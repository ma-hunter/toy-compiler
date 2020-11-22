//
// Created by Shiroha on 20/11/23.
//

#include "syntax.h"
#include "parser.tab.h"

#include <iostream>
#include <memory>
#include <list>
#include <unordered_set>

using std::pair, std::tuple, std::list, std::make_unique, std::unordered_set;
using symbol_table::fParam, symbol_table::fFunc, symbol_table::fTemp, symbol_table::fVar;
using namespace llvm;

extern SymbolTable symbolTable;

pair<Value *, int> parseOperand(
        LLVMContext &TheContext,
        unordered_map<string,
        pair<Value *, int>> &val_table,
        const Operation &operation) {

    switch (operation.kind) {
        case INT: return {
            ConstantInt::get(
                    Type::getInt32Ty(TheContext),
                    get<Integer>(operation.data)
            ), INT};
        case FLOAT: return {
            ConstantFP::get(
                    Type::getFloatTy(TheContext),
                    get<Float>(operation.data)
            ), FLOAT};
        case ID:
            if (val_table.count(get<string>(operation.data)))
                return val_table[get<string>(operation.data)];
        default: return {nullptr, 0};
    }
}

void toObjectCode(const shared_ptr<CodeNode>& head) {

    LLVMContext TheContext;
    Module TheModule("code", TheContext);

    vector<BasicBlock *> blockStack;
    vector<IRBuilder<>> builderStack;
    vector<Function *> functionStack;

    unordered_map<string, pair<Function *, FunctionType *>> functionTable;
    unordered_map<string, pair<Value *, int>> valTable;
    unordered_map<string, BasicBlock *> labelTable;
    unordered_set<BasicBlock *> finishedBlock;

    typedef tuple<Instruction *, Value *, string, string> DeferredBrStatementType;

    unordered_map<string, vector<Instruction *>> deferredGotoStatement;
    list<DeferredBrStatementType> deferredBrStatement;

    builderStack.emplace_back(IRBuilder<>(TheContext));
    auto[printf_func, 
         printf_func_type, 
         print_int_func, 
         print_int_func_type] = injectPrintFunction(TheContext,
                                                    builderStack.back(),
                                                    TheModule);
    functionTable["printf"] = {printf_func, printf_func_type};
    functionTable["print_int"] = {print_int_func, print_int_func_type};

    auto create_goto = [&](const string &label) -> void {
        auto *current_basic_block = blockStack.back();
        if (finishedBlock.count(current_basic_block))
            return;
        finishedBlock.insert(current_basic_block);

        if (labelTable.count(label)) {
            builderStack.back().CreateBr(labelTable[label]);
        } else {
            Instruction *fake_node = builderStack.back().CreateRetVoid();
            deferredGotoStatement[label].emplace_back(fake_node);
        }
    };

    shared_ptr<CodeNode> cur = head;
    do {
        auto[l, l_type] = parseOperand(TheContext, valTable, cur->op1);
        auto[r, r_type] = parseOperand(TheContext, valTable, cur->op2);
        switch (cur->kind) {
            case ASSIGNOP: {
                string var_name(get<string>(cur->res.data));

                Value *alloc = nullptr;
                if (valTable.count(var_name)) {
                    alloc = valTable[var_name].first;
                } else {
                    auto type = l_type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(TheContext);

                    alloc = builderStack.back().CreateAlloca(type, nullptr, var_name);
                    valTable[var_name] = {alloc, l_type};
                }

                if (l->getType()->isPointerTy()) {
                    l = builderStack.back().CreateLoad(
                        l_type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(TheContext),
                        l, "");
                }
                builderStack.back().CreateStore(l, alloc);
                break;
            }

            case PLUS:
            case MINUS:
            case STAR:
            case DIV:
            case MOD: {
                bool have_float_type = false;
                if (l->getType()->isFloatTy() || r->getType()->isFloatTy() || l_type == FLOAT || r_type == FLOAT) {
                    have_float_type = true;
                }

                if (l->getType()->isPointerTy()) {
                    auto type = l_type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(TheContext);
                    l = builderStack.back().CreateLoad(type, l, "");
                }
                if (r->getType()->isPointerTy()) {
                    auto type = r_type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(TheContext);
                    r = builderStack.back().CreateLoad(type, r, "");
                }
                Value *res = nullptr;

                if (cur->kind == PLUS) {
                    if (have_float_type) {
                        res = builderStack.back().CreateFAdd(l, r, get<string>(cur->res.data));
                    } else {
                        res = builderStack.back().CreateAdd(l, r, get<string>(cur->res.data));
                    }
                } else if (cur->kind == MINUS) {
                    if (have_float_type) {
                        res = builderStack.back().CreateFSub(l, r, get<string>(cur->res.data));
                    } else {
                        res = builderStack.back().CreateSub(l, r, get<string>(cur->res.data));
                    }
                } else if (cur->kind == STAR) {
                    if (have_float_type) {
                        res = builderStack.back().CreateFMul(l, r, get<string>(cur->res.data));
                    } else {
                        res = builderStack.back().CreateMul(l, r, get<string>(cur->res.data));
                    }
                } else if (cur->kind == DIV) {
                    if (have_float_type) {
                        res = builderStack.back().CreateFDiv(l, r, get<string>(cur->res.data));
                    } else {
                        res = builderStack.back().CreateSDiv(l, r, get<string>(cur->res.data));
                    }
                } else if (cur->kind == MOD) {
                    if (have_float_type) {
                        throw std::runtime_error("cannot mod float value.");
                    } else {
                        res = builderStack.back().CreateSRem(l, r, get<string>(cur->res.data));
                    }
                }

                valTable[get<string>(cur->res.data)] = {res, have_float_type ? FLOAT : INT};
                break;
            }
            case RETURN: {
                if (cur->res.kind) {
                    auto[return_val, return_type] = valTable[get<string>(cur->res.data)];
                    if (return_val->getType()->isPointerTy()) {
                        return_val = builderStack.back().CreateLoad(Type::getInt32Ty(TheContext), return_val, "");
                    }
                    builderStack.back().CreateRet(return_val);
                } else {
                    builderStack.back().CreateRetVoid();
                }

                break;
            }
            case CONTINUE:
            case BREAK: {
                const string &label = get<string>(cur->res.data);
                create_goto(label);
                break;
            }
            case FUNCTION: {
                const string &function_name = get<string>(cur->res.data);
                const auto fill_result = symbol_table::searchByFlag(function_name, fFunc);

                vector<Type *> parameters;
                for (int i = 0; i < fill_result.value().paramNum; i++) {
                    const int offset = i + fill_result.value().idx + 1;
                    parameters.push_back(
                            symbolTable[offset].type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(
                                    TheContext));
                }
                Type *return_type = Type::getInt32Ty(TheContext);
                FunctionType *function_type = FunctionType::get(return_type, parameters, false);
                Function *function_value = Function::Create(function_type, Function::ExternalLinkage, function_name,
                                                            &TheModule);
                BasicBlock *next_block = BasicBlock::Create(TheContext, "entry", function_value);
                functionTable[function_name] = {function_value, function_type};
                int ptr = fill_result.value().idx + 1;
                for (auto &arg : function_value->args()) {
                    valTable[symbolTable[ptr].alias] = {&arg, symbolTable[ptr].type};
                    arg.setName(symbolTable[ptr].alias);
                    ptr++;
                }
                IRBuilder<> next_builder(next_block);
                builderStack.push_back(next_builder);
                blockStack.push_back(next_block);
                functionStack.push_back(function_value);
                break;
            }
            case CALL: {
                auto[fn, fn_type] = functionTable[get<string>(cur->op1.data)];
                vector<Value *> parameters;
                for (const auto& arg : cur->data) {
                    auto[val, val_type] = valTable[get<string>(arg->res.data)];
                    if (val->getType()->isPointerTy()) {
                        auto type = val_type == FLOAT ? Type::getFloatTy(TheContext) : Type::getInt32Ty(TheContext);
                        val = builderStack.back().CreateLoad(type, val, "");
                    }

                    parameters.push_back(val);
                }

                valTable[get<string>(cur->res.data)] = {
                        builderStack.back().CreateCall(fn_type, fn, parameters, get<string>(cur->res.data)),
                        fn_type->getReturnType()->isFloatTy() ? FLOAT : INT};
                break;
            }

            case LABEL: {
                const string &label = get<string>(cur->res.data);
                BasicBlock *next_block = BasicBlock::Create(TheContext, label, functionStack.back());
                labelTable[label] = next_block;

                if (deferredGotoStatement.count(label)) {
                    for (auto val : deferredGotoStatement[label]) {
                        BranchInst::Create(next_block, val);
                        val->eraseFromParent();
                    }
                    deferredGotoStatement.erase(label);
                }

                for (auto it = deferredBrStatement.begin(); it != deferredBrStatement.end();) {
                    auto[val, icmp_val, true_label, false_label] = *it;
                    if (labelTable.count(true_label) && labelTable.count(false_label)) {
                        BranchInst::Create(labelTable[true_label], labelTable[false_label], icmp_val, val);
                        val->eraseFromParent();

                        it = deferredBrStatement.erase(it);
                    } else {
                        it++;
                    }
                }

                // builderStack.back().CreateBr(next_block);
                blockStack.push_back(next_block);
                builderStack.emplace_back(next_block);
                break;
            }

            case GOTO: {
                const string &label = get<string>(cur->res.data);
                create_goto(label);
                break;
            }

            case JGE:
            case JGT:
            case JLE:
            case JLT:
            case NEQ:
            case EQ: {
                Value *val = nullptr;

                if (l_type != r_type) {
                    throw std::runtime_error("inconsistency float and int type.");
                }

                bool cmp_float = l_type == FLOAT || r_type == FLOAT;
                if (cmp_float) {
                    if (l && l->getType()->isPointerTy())
                        l = builderStack.back().CreateLoad(Type::getFloatTy(TheContext), l, "");
                    if (r && r->getType()->isPointerTy())
                        r = builderStack.back().CreateLoad(Type::getFloatTy(TheContext), r, "");

                    if (cur->kind == EQ)
                        val = builderStack.back().CreateFCmpOEQ(l, r, "cmpres");
                    else if (cur->kind == NEQ)
                        val = builderStack.back().CreateFCmpONE(l, r, "cmpres");
                    else if (cur->kind == JGE)
                        val = builderStack.back().CreateFCmpOGE(l, r, "cmpres");
                    else if (cur->kind == JGT)
                        val = builderStack.back().CreateFCmpOGT(l, r, "cmpres");
                    else if (cur->kind == JLE)
                        val = builderStack.back().CreateFCmpOLE(l, r, "cmpres");
                    else if (cur->kind == JLT)
                        val = builderStack.back().CreateFCmpOLT(l, r, "cmpres");
                } else { // int
                    if (l && l->getType()->isPointerTy())
                        l = builderStack.back().CreateLoad(Type::getInt32Ty(TheContext), l, "");
                    if (r && r->getType()->isPointerTy())
                        r = builderStack.back().CreateLoad(Type::getInt32Ty(TheContext), r, "");

                    if (cur->kind == EQ)
                        val = builderStack.back().CreateICmpEQ(l, r, "cmpres");
                    else if (cur->kind == NEQ)
                        val = builderStack.back().CreateICmpNE(l, r, "cmpres");
                    else if (cur->kind == JGE)
                        val = builderStack.back().CreateICmpSGE(l, r, "cmpres");
                    else if (cur->kind == JGT)
                        val = builderStack.back().CreateICmpSGT(l, r, "cmpres");
                    else if (cur->kind == JLE)
                        val = builderStack.back().CreateICmpSLE(l, r, "cmpres");
                    else if (cur->kind == JLT)
                        val = builderStack.back().CreateICmpSLT(l, r, "cmpres");
                }

                const string &true_label = get<string>(cur->res.data), &false_label = get<string>(
                        cur->data[0]->res.data);
                if (labelTable.count(true_label) && labelTable.count(false_label)) {
                    builderStack.back().CreateCondBr(val, labelTable[true_label], labelTable[false_label]);
                } else {
                    Instruction *fake_node = builderStack.back().CreateRetVoid();
                    deferredBrStatement.emplace_back(fake_node, val, true_label, false_label);
                }
            }
        }

        cur = cur->next;
    } while (cur != head);

    if constexpr (PRINT_LLVM_IR) {
        TheModule.print(errs(), nullptr);
    }
    verifyModule(TheModule, &(errs()));

    std::unique_ptr<Module> ptr(&TheModule);
    ExecutionEngine *engine = EngineBuilder(std::move(ptr)).create();
    engine->finalizeObject();
    engine->runFunction(functionTable["main"].first, {});
}