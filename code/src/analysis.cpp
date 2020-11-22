//
// Created by Shiroha on 20/11/22.
//
#include "syntax.h"
#include "parser.tab.h"
#include "symbol_table.h"
#include "type.h"
#include "ast.h"

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <optional>

using std::string, std::to_string, std::move, std::vector, std::nullopt;
using symbol_table::SymbolFlag, symbol_table::fParam, symbol_table::fFunc, symbol_table::fTemp, symbol_table::fVar;

extern SymbolTable symbolTable;
extern vector<int> scopeStack;

string newAlias() {
    static int id = 1;
    return "v" + to_string(id ++);
}

string newLabel() {
    static int id = 1;
    return "l" + to_string(id ++);
}

string newTemp() {
    static int id = 1;
    return "t" + to_string(id ++);
}

shared_ptr<CodeNode> genCodeNode(int kind, Operation $1, Operation $2, Operation res) {
    shared_ptr<CodeNode> node(new CodeNode());
    node->kind = kind, node->op1 = move($1), node->op2 = move($2), node->res = move(res);
    return node->prev = node->next = node;
}

shared_ptr<CodeNode> gen_label(int kind, const string &label) {
    shared_ptr<CodeNode> node(new CodeNode());
    node->kind = kind, node->res.data = label;
    return node->prev = node->next = node;
}

shared_ptr<CodeNode> genGoto(const string &label) {
    return gen_label(GOTO, label);
}

shared_ptr<CodeNode> genLabel(const string &label) {
    return gen_label(LABEL, label);
}

shared_ptr<CodeNode> mergeCodeNode(const vector<shared_ptr<CodeNode>> &list) {
    shared_ptr<CodeNode> h1 = nullptr, h2 = nullptr;
    for (auto &ii : list)
        if (h1 == nullptr) h1 = ii;
        else if (ii) {
            shared_ptr<CodeNode> t1 = h1->prev;
            shared_ptr<CodeNode> t2 = h2->prev;
            t1->next = h2, t2->next = h1;
            h1->prev = t2, h2->prev = t1;
        }
    return h1;
}

void throwSemanticError(int line, const string &msg1, const string &msg2 = "") {
    const string err_msg("Line " + to_string(line) + ", Message: " + msg1 + " " + msg2);
    throw std::runtime_error(err_msg);
}

int fillTempVar(const string &name, int level, int type, SymbolFlag flag) {
    Symbol sym{};

    sym.name = "";
    sym.alias = name;
    sym.level = level;
    sym.type = type;
    sym.flag = flag;
    sym.idx = symbolTable.size();

#ifdef IS_HASH_TABLE
    symbolTable[sym.alias] = sym;
#else
    symbolTable.emplace_back(sym);
#endif
    // Return ID of the temporary variable
    // TODO: Not adapt for hash map
    return symbolTable.size() - 1;
}

int level = 0;

void extVarList(ASTNode *node) {
    switch (node->kind) {
        case EXT_DEC_LIST:
            node->children[0]->type = node->type;
            node->children[1]->type = node->type;
            extVarList(node->children[0]);
            extVarList(node->children[1]);
            node->num = node->children[1]->num + 1;
            break;
        case ID: {
            auto fill_result = symbol_table::fill(get<String>(node->value), newAlias(), level, node->type, fVar);
            if (fill_result == nullopt)
                throwSemanticError(node->pos, get<String>(node->value), "Re-declare Variable");
            else node->idx = fill_result.value();
            node->num = 1;
            break;
        }
    }
}

bool matchParam(const Symbol &symbol, ASTNode *node) {
    int num = symbol.paramNum;
    const int pos = node->pos;
    node = node->children[0];
    if (num == 0 && node == nullptr) {
        return true;
    }

    for (int j = 1; j <= num; j++) {
        if (!node) {
            throwSemanticError(pos, "", "Too few parameters to call function!");
            return false;
        }
        int type1 = symbolTable[symbol.idx + j].type;
        int type2 = node->children[0]->type;
        if (type1 != type2) {
            throwSemanticError(pos, "", "Function Type doesn't match.");
            return false;
        }
        node = node->children[1];
    }
    if (node) {
        throwSemanticError(pos, "", "Too much parameters to call function.");
        return false;
    }
    return true;
}

void boolExpression(ASTNode *node) {
    if (node) {
        switch (node->kind) {
            case INT:
            case ID:
            case FLOAT:
                break;
            case RELOP: {
                Operation opn1, opn2, result;
                int kind = 0;
                expression(node->children[0]);
                expression(node->children[1]);
                opn1.kind = ID;
                opn1.data = symbolTable[node->children[0]->idx].alias;
                opn2.kind = ID;
                opn2.data = symbolTable[node->children[1]->idx].alias;
                result.kind = ID;
                result.data = node->eTrue;
                if (get<String>(node->value) == "<")
                    kind = JLT;
                else if (get<String>(node->value) == "<=")
                    kind = JLE;
                else if (get<String>(node->value) == ">")
                    kind = JGT;
                else if (get<String>(node->value) == ">=")
                    kind = JGE;
                else if (get<String>(node->value) == "==")
                    kind = EQ;
                else if (get<String>(node->value) == "!=")
                    kind = NEQ;
                node->code = genCodeNode(kind, opn1, opn2, result);
                node->code->data.push_back(genGoto(node->eFalse));
                node->code = mergeCodeNode({node->children[0]->code,
                                              node->children[1]->code,
                                              node->code});
                break;
            }
            case AND:
            case OR:
                if (node->kind == AND) {
                    node->children[0]->eTrue = newLabel();
                    node->children[0]->eFalse = node->eFalse;
                } else {
                    node->children[0]->eTrue = node->eTrue;
                    node->children[0]->eFalse = newLabel();
                }
                node->children[1]->eTrue = node->eTrue;
                node->children[1]->eFalse = node->eFalse;
                boolExpression(node->children[0]);
                boolExpression(node->children[1]);
                if (node->kind == AND) {
                    node->code = mergeCodeNode({node->children[0]->code,
                                                  genLabel(node->children[0]->eTrue),
                                                  node->children[1]->code});
                } else {
                    node->code = mergeCodeNode({node->children[0]->code,
                                                  genLabel(node->children[0]->eFalse),
                                                  node->children[1]->code});
                }
                break;
            case NOT:
                node->children[0]->eTrue = node->eFalse;
                node->children[0]->eFalse = node->eTrue;
                boolExpression(node->children[0]);
                node->code = node->children[0]->code;
                break;
        }
    }
}

void expression(ASTNode *node) {
    if (node) {
        switch (node->kind) {
            case INT: {
                Operation opn1, opn2, result;
                node->idx = fillTempVar(newTemp(), level, node->type, fTemp);
                node->type = INT;
                opn1.kind = INT;
                opn1.data = get<Integer>(node->value);
                result.kind = ID;
                result.data = symbolTable[node->idx].alias;
                node->code = genCodeNode(ASSIGNOP, opn1, opn2, result);
                break;
            }
            case ID: {
                auto fill_result = symbol_table::searchByName(get<String>(node->value));
                if (fill_result == nullopt)
                    throwSemanticError(node->pos, get<String>(node->value), "Variable is not declared.");
                if (fill_result.value().flag == symbol_table::fFunc)
                    throwSemanticError(node->pos, get<String>(node->value), "Type doesn't match.");
                else {
                    node->idx = fill_result.value().idx;
                    node->code = nullptr;
                    node->type = fill_result.value().type;
                }
                break;
            }
            case FLOAT: {
                Operation opn1, opn2, result;
                node->idx = fillTempVar(newTemp(), level, node->type, fTemp);
                node->type = FLOAT;
                opn1.kind = FLOAT;
                opn1.data = get<Float>(node->value);
                result.kind = ID;
                result.data = symbolTable[node->idx].alias;
                node->code = genCodeNode(ASSIGNOP, opn1, opn2, result);
                break;
            }
            case ASSIGNOP: {
                Operation opn1, opn2, result;

                if (node->children[0]->kind != ID) {
                    throwSemanticError(node->pos, "", "Assign Expression needs to be left value.");
                } else {
                    expression(node->children[0]);
                    expression(node->children[1]);
                    node->type = node->children[0]->type;
                    node->code = mergeCodeNode({node->children[0]->code, node->children[1]->code});
                    opn1.kind = ID;
                    opn1.data = symbolTable[node->children[1]->idx].alias;
                    result.kind = ID;
                    result.data = symbolTable[node->children[0]->idx].alias;
                    node->code = mergeCodeNode({node->code, genCodeNode(ASSIGNOP, opn1, opn2, result)});
                }
                break;
            }
            case RELOP: // todo
                node->type = INT;
                expression(node->children[0]);
                expression(node->children[1]);
                break;
            case PLUS:
            case MINUS:
            case STAR:
            case DIV:
            case MOD: {
                Operation opn1, opn2, result;

                expression(node->children[0]);
                expression(node->children[1]);
                // todo: err handle
                if (node->children[0]->type == FLOAT || node->children[1]->type == FLOAT)
                    node->type = FLOAT;
                else
                    node->type = INT;
                node->idx = fillTempVar(newTemp(), level, node->type, fTemp);
                opn1.kind = ID;
                opn1.data = symbolTable[node->children[0]->idx].alias;
                opn1.type = node->children[0]->type;
                opn2.kind = ID;
                opn2.data = symbolTable[node->children[1]->idx].alias;
                opn2.type = node->children[1]->type;
                result.kind = ID;
                result.data = symbolTable[node->idx].alias;
                result.type = node->type;
                node->code = mergeCodeNode({node->children[0]->code,
                                              node->children[1]->code,
                                              genCodeNode(node->kind, opn1, opn2, result)});
                break;
            }
            case NOT:
                // TODO: not operator
                break;
            case UMINUS:
                // TODO: unary minus operator
                break;
            case FUNC_CALL: {
                vector<shared_ptr<CodeNode>> call_args;
                Operation opn1, opn2, result;

                auto fill_result = symbol_table::searchByName(get<String>(node->value));
                if (fill_result == nullopt) {
                    throwSemanticError(node->pos, get<String>(node->value), "Function not declared.");
                    break;
                }
                if (fill_result.value().flag != symbol_table::fFunc) {
                    throwSemanticError(node->pos, get<String>(node->value), "Not a function!");
                    break;
                }
                node->type = fill_result.value().type;
                const int width = node->type == INT ? 4 : 8;
                if (node->children[0]) {
                    expression(node->children[0]);
                    node->code = node->children[0]->code;
                } else {
                    node->code = nullptr;
                }
                matchParam(fill_result.value(), node);
                ASTNode *ptr = node->children[0];
                while (ptr) {
                    result.kind = ID;
                    result.data = symbolTable[ptr->children[0]->idx].alias;
                    call_args.push_back(genCodeNode(ARG, opn1, opn2, result));
                    ptr = ptr->children[1];
                }
                node->idx = fillTempVar(newTemp(), level, node->type, fTemp);
                opn1.kind = ID;
                opn1.data = node->value;
                result.kind = ID;
                result.data = symbolTable[node->idx].alias;

                auto call_code_node = genCodeNode(CALL, opn1, opn2, result);
                call_code_node->data = call_args;

                node->code = mergeCodeNode({node->code,
                                              call_code_node});
                break;
            }
            case ARGS:
                expression(node->children[0]);
                node->code = node->children[0]->code;
                if (node->children[1]) {
                    expression(node->children[1]);
                    node->code = mergeCodeNode({node->code,
                                                  node->children[1]->code});
                }
                break;
        }
    }
}

vector<ASTNode *> semanticStack;

optional<ASTNode *> findLastLoopStatement() {
    for (int i = semanticStack.size() - 1; i >= 0; i--) {
        if (semanticStack[i]->kind == WHILE)
            return semanticStack[i];
    }
    return nullopt;
}

void semantic_analysis(ASTNode *node, const string &function_name = "") {
    if (node) {
        semanticStack.push_back(node);
        switch (node->kind) {
            case CONTINUE:
            case BREAK: {
                auto last_loop_statement = findLastLoopStatement();
                if (last_loop_statement == nullopt) {
                    throwSemanticError(node->pos, "Break or continue statement invalid");
                    break;
                }
                Operation opn1, opn2, result;
                result.kind = ID;
                result.data = last_loop_statement.value()->sNext;

                node->sNext = last_loop_statement.value()->sNext;
                node->code = genCodeNode(node->kind, opn1, opn2, result);
                break;
            }
            case RETURN: {
                Operation opn1, opn2, result;
                if (node->children[0]) {
                    expression(node->children[0]);

                    result.kind = ID;
                    result.data = symbolTable[node->children[0]->idx].alias;
                    node->code = mergeCodeNode({node->children[0]->code, genCodeNode(RETURN, opn1, opn2, result)});

                    auto function_symbol = symbol_table::searchByFlag(function_name, symbol_table::fFunc);
                    auto return_var_name = get<String>(result.data);
                    auto return_var_symbol = symbol_table::searchByAlias(get<String>(result.data));
                    const int return_type = function_symbol.value().type;
                    if (return_var_symbol.value().type != return_type) {
                        throwSemanticError(node->children[0]->pos, "Return type doesn't match.");
                    }
                } else {
                    result.kind = 0;
                    node->code = genCodeNode(RETURN, opn1, opn2, result);
                }
                break;
            }
            case EXT_DEF_LIST:
                if (!node->children[0]) {
                    break;
                }
                semantic_analysis(node->children[0], function_name);
                node->code = node->children[0]->code;
                if (node->children[1]) {
                    semantic_analysis(node->children[1], function_name);
                    node->code = mergeCodeNode({node->code,
                                                  node->children[1]->code});
                }
                break;
            case EXT_VAR_DEF:
                node->type = node->children[1]->type = get<String>(node->children[0]->value) == "int" ? INT : FLOAT;
                extVarList(node->children[1]);
                node->code = nullptr;
                break;
            case FUNC_DEF:
                node->children[1]->type = get<String>(node->children[0]->value) == "int" ? INT : FLOAT;
                semantic_analysis(node->children[1], get<String>(node->children[1]->value));
                // T->children[2]->sNext = newLabel();
                semantic_analysis(node->children[2], get<String>(node->children[1]->value));
                node->code = mergeCodeNode({node->children[1]->code, node->children[2]->code});
                break;
            case FUNC_DEC: {
                Operation opn1, opn2, result;
                const auto fill_result = symbol_table::fill(get<String>(node->value), newAlias(), level, node->type,
                                                            symbol_table::fFunc);
                if (fill_result == nullopt) {
                    throwSemanticError(node->pos, get<String>(node->value), "Function Redeclaration.");
                    break;
                } else {
                    node->idx = fill_result.value();
                }
                result.kind = ID;
                result.data = node->value;
                node->code = genCodeNode(FUNCTION, opn1, opn2, result);
                if (node->children[0]) {
                    semantic_analysis(node->children[0], function_name);
                    symbolTable[fill_result.value()].paramNum = node->children[0]->num;
                    node->code = mergeCodeNode({node->code, node->children[0]->code});
                } else {
                    symbolTable[fill_result.value()].paramNum = 0;
                }
                break;
            }
            case PARAM_LIST:
                semantic_analysis(node->children[0], function_name);
                if (node->children[1]) {
                    semantic_analysis(node->children[1], function_name);
                    node->num = node->children[0]->num + node->children[1]->num;
                    node->code = mergeCodeNode({node->children[0]->code, node->children[1]->code});
                } else {
                    node->num = node->children[0]->num;
                    node->code = node->children[0]->code;
                }
                break;
            case PARAM_DEC: {
                Operation opn1, opn2, result;
                auto fill_result = symbol_table::fill(get<String>(node->children[1]->value), newAlias(), 1,
                                                      node->children[0]->type, fParam);
                if (fill_result == nullopt) {
                    throwSemanticError(node->children[1]->pos, get<String>(node->children[1]->value),
                                       "Function Parameter name re-declaration.");
                } else {
                    node->children[1]->idx = fill_result.value();
                }
                node->num = 1;
                result.kind = ID;
                result.data = symbolTable[fill_result.value()].alias;
                // T->code = genCodeNode(PARAM, opn1, opn2, result);
                break;
            }
            case VAR_DEF: {
                Operation opn1, opn2, result;
                node->code = nullptr;
                node->children[1]->type = get<String>(node->children[0]->value) == "int" ? INT : FLOAT;
                ASTNode *ptr = node->children[1];
                int num = 0;
                while (ptr) {
                    num++;
                    ptr->children[0]->type = ptr->type;
                    if (ptr->children[1]) {
                        ptr->children[1]->type = ptr->type;
                    }

                    if (ptr->children[0]->kind == ID) {
                        auto fill_result = symbol_table::fill(get<String>(ptr->children[0]->value), newAlias(), level,
                                                              ptr->children[0]->type, fVar);
                        if (fill_result == nullopt) {
                            throwSemanticError(ptr->children[0]->pos, get<String>(ptr->children[0]->value),
                                               "Variable re-declared.");
                        } else {
                            ptr->children[0]->idx = fill_result.value();
                        }
                    } else if (ptr->children[0]->kind == ASSIGNOP) {
                        auto fill_result = symbol_table::fill(get<String>(ptr->children[0]->children[0]->value), newAlias(),
                                                              level,
                                                              ptr->children[0]->type, fVar);
                        if (fill_result == nullopt)
                            throwSemanticError(ptr->children[0]->children[0]->pos, get<String>(ptr->children[0]->children[0]->value),
                                               "Variable re-declared.");
                        else {
                            ptr->children[0]->idx = fill_result.value();
                            expression(ptr->children[0]->children[1]);
                            opn1.kind = ID;
                            opn1.data = symbolTable[ptr->children[0]->children[1]->idx].alias;
                            result.kind = ID;
                            result.data = symbolTable[ptr->children[0]->idx].alias;
                            node->code = mergeCodeNode({node->code,
                                                          ptr->children[0]->children[1]->code,
                                                          genCodeNode(ASSIGNOP, opn1, opn2, result)});
                        }
                    }
                    ptr = ptr->children[1];
                }
                break;
            }
            case DEF_LIST:
                node->code = nullptr;
                if (node->children[0]) {
                    semantic_analysis(node->children[0], function_name);
                    node->code = node->children[0]->code;
                }
                if (node->children[1]) {
                    semantic_analysis(node->children[1], function_name);
                    node->code = mergeCodeNode({node->code,
                                                  node->children[1]->code});
                }
                break;
            case COMP_STM:
                level++;
                scopeStack.push_back(symbolTable.size());
                node->code = nullptr;
                if (node->children[0]) {
                    semantic_analysis(node->children[0], function_name);
                    node->code = node->children[0]->code;
                }
                if (node->children[1]) {
                    node->children[1]->sNext = node->sNext;
                    semantic_analysis(node->children[1], function_name);
                    node->code = mergeCodeNode({node->code,
                                                  node->children[1]->code});
                }
                symbol_table::print();
                level--;
                symbolTable.resize(scopeStack.back());
                scopeStack.pop_back();
                break;
            case STM_LIST:
                if (!node->children[0]) {
                    node->code = nullptr;
                    break;
                }
                if (node->children[1])
                    node->children[0]->sNext = newLabel();
                else
                    node->children[0]->sNext = node->sNext;
                semantic_analysis(node->children[0], function_name);
                node->code = node->children[0]->code;
                if (node->children[1]) {
                    node->children[1]->sNext = node->sNext;
                    semantic_analysis(node->children[1], function_name);
                    if (node->children[0]->kind == RETURN || node->children[0]->kind == EXP_STMT ||
                        node->children[0]->kind == COMP_STM) {
                        node->code = mergeCodeNode({node->code,
                                                      node->children[1]->code});
                    } else {
                        node->code = mergeCodeNode({node->code,
                                                      genLabel(node->children[0]->sNext),
                                                      node->children[1]->code});
                    }
                }
                break;
            case EXP_STMT:
                semantic_analysis(node->children[0], function_name);
                node->code = node->children[0]->code;
                break;
            case IF_THEN:
                node->children[0]->eTrue = newLabel();
                node->children[0]->eFalse = node->sNext;
                boolExpression(node->children[0]);
                node->children[1]->sNext = node->sNext;
                semantic_analysis(node->children[1], function_name);
                node->code = mergeCodeNode({node->children[0]->code,
                                              genLabel(node->children[0]->eTrue),
                                              node->children[1]->code,
                                              genGoto(node->children[1]->sNext)});
                break;
            case IF_THEN_ELSE:
                node->children[0]->eTrue = newLabel();
                node->children[0]->eFalse = newLabel();
                boolExpression(node->children[0]);
                node->children[1]->sNext = node->sNext;
                semantic_analysis(node->children[1], function_name);
                node->children[2]->sNext = node->sNext;
                semantic_analysis(node->children[2], function_name);
                node->code = mergeCodeNode({node->children[0]->code,
                                              genLabel(node->children[0]->eTrue),
                                              node->children[1]->code,
                                              genGoto(node->sNext),
                                              genLabel(node->children[0]->eFalse),
                                              node->children[2]->code,
                                              genGoto(node->sNext)});
                break;
            case WHILE:
                node->children[0]->eTrue = newLabel();
                node->children[0]->eFalse = node->sNext;
                boolExpression(node->children[0]);
                node->children[1]->sNext = newLabel();
                semantic_analysis(node->children[1], function_name);
                node->code = mergeCodeNode({genGoto(node->children[1]->sNext),
                                              genLabel(node->children[1]->sNext),
                                              node->children[0]->code,
                                              genLabel(node->children[0]->eTrue),
                                              node->children[1]->code,
                                              genGoto(node->children[1]->sNext)});
                break;
            case ID:
            case INT:
            case FLOAT:
            case ASSIGNOP:
            case AND:
            case OR:
            case RELOP:
            case PLUS:
            case MINUS:
            case STAR:
            case DIV:
            case NOT:
            case UMINUS:
            case FUNC_CALL:
                expression(node);
                break;
        }
        semanticStack.pop_back();
    }
}

void entryPoint(ASTNode *node) {
    semanticStack.clear();

    symbol_table::fill("print_int", "", 0, INT, fFunc);
    symbolTable[0].paramNum = 1;
    symbol_table::fill("0", "", 1, INT, fParam);

    semantic_analysis(node);
    toObjectCode(node->code);
}

tuple<
    Function *,
    FunctionType *,
    Function *,
    FunctionType *
> injectPrintFunction(LLVMContext &ctx, IRBuilder<> &builder, Module &_module) {

    using namespace llvm;

    vector<Type *> printfArgsTypes({Type::getInt8PtrTy(ctx)});

    Function *printf_func = _module.getFunction("printf");
    FunctionType *printf_func_type = FunctionType::get(
            Type::getInt32Ty(_module.getContext()),
            {Type::getInt8PtrTy(_module.getContext())},
            true);
    if (printf_func == nullptr)
    {
        printf_func = Function::Create(printf_func_type, GlobalValue::ExternalLinkage, "printf", &_module);
        printf_func->setCallingConv(llvm::CallingConv::C);
    }

    FunctionType *print_int_func_type = FunctionType::get(
            Type::getInt32Ty(ctx),
            {Type::getInt32Ty(_module.getContext())},
            false);
    Function *print_int_func = Function::Create(print_int_func_type, GlobalValue::ExternalLinkage, "print_int",& _module);
    BasicBlock *block = BasicBlock::Create(ctx, "", print_int_func);
    IRBuilder<> block_builder(block);

    vector<Value *> parameters = {
            block_builder.CreateGlobalStringPtr("%d\n"),
            print_int_func->getArg(0)};
    auto ret = block_builder.CreateCall(printf_func, parameters, "");
    block_builder.CreateRet(ret);

    return {printf_func, printf_func_type, print_int_func, print_int_func_type};
}
