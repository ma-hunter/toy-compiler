//
// Created by Shiroha on 20/11/21.
//

#include "ast.h"
#include "config.h"
#include "symbol_table.h"

#include "parser.tab.h"

extern SymbolTable symbolTable;
extern FILE *astOut;

ast::Node *ast::newNode(int kind, int pos, const vector<Node *>& nodes) {

    auto node = new ast::Node();
    node->kind = kind, node->pos = pos;

    int i = 0;
    for (auto &ii : nodes) node->children[i ++] = ii;
    while (i < 4) node->children[i ++] = nullptr;

    return node;
}

void ast::printNode(ast::Node *node, int indent) {

    if constexpr (!PRINT_AST) return;
    if (!astOut) {
        fprintf(stderr, "Can\'t print AST node: FILE open failed.\n");
        return;
    }

    if (node) {
        switch (node->kind) {
            case INT:
                fprintf(astOut, "%*cINT: %d\n", indent, ' ', get<Integer>(node->value));
                break;
            case ID:
                fprintf(astOut, "%*cID: %s\n", indent, ' ', get<String>(node->value).c_str());
                break;
            case TYPE:
                fprintf(astOut, "%*cType: %s\n", indent, ' ', get<String>(node->value).c_str());
                break;
            case FLOAT:
                fprintf(astOut, "%*cFLOAT: %f\n", indent, ' ', get<Float>(node->value));
                break;
            case WHILE:
                fprintf(astOut, "%*cLoop Statement: (%d)\n", indent, ' ', node->pos);
                fprintf(astOut, "%*cLoop Condition: \n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                fprintf(astOut, "%*cLoop Body: (%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                break;
            case RETURN:
                fprintf(astOut, "%*cReturn Expression:(%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                break;
            case CONTINUE:
                fprintf(astOut, "%*cContinue Statement\n", indent, ' ');
                break;
            case BREAK:
                fprintf(astOut, "%*cBreak Statement\n", indent, ' ');
                break;
            case EXT_DEF_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case EXT_VAR_DEF:
                fprintf(astOut, "%*cVariable Declaration: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                fprintf(astOut, "%*cVariable Name: \n", indent + 2, ' ');
                printNode(node->children[1], indent + 4);
                break;
            case FUNC_DEF:
                fprintf(astOut, "%*cFunction Declaration: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                printNode(node->children[2], indent + 2);
                break;
            case FUNC_DEC:
                fprintf(astOut, "%*cFunction Name: %s\n", indent, ' ', get<String>(node->value).c_str());
                if (node->children[0]) {
                    fprintf(astOut, "%*cFunction Parameters: \n", indent, ' ');
                    printNode(node->children[0], indent + 2);
                } else {
                    fprintf(astOut, "%*cFunction without Parameters: \n", indent + 2, ' ');
                }
                break;
            case EXT_DEC_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case PARAM_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case PARAM_DEC:
                fprintf(astOut, "%*cType: %s, Parameter Name: %s\n", indent, ' ', node->children[0]->type == INT ? "int" : "float",
                       get<String>(node->children[1]->value).c_str());
                break;
            case VAR_DEF:
                fprintf(astOut, "%*cVariable Decl: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                break;
            case DEC_LIST: {
                fprintf(astOut, "%*cVariable Name Decl:\n", indent, ' ');
                ASTNode *ptr = node;
                while (ptr) {
                    if (ptr->children[0]->kind == ID)
                        fprintf(astOut, "%*c %s\n", indent + 4, ' ', get<String>(ptr->children[0]->value).c_str());
                    else if (ptr->children[0]->kind == ASSIGNOP) {
                        fprintf(astOut, "%*c %s ASSIGNOP\n ", indent + 4, ' ', get<String>(ptr->children[0]->children[0]->value).c_str());
                        printNode(ptr->children[0]->children[1], indent + get<String>(ptr->children[0]->children[0]->value).size() + 8);
                    }
                    ptr = ptr->children[1];
                }
                break;
            }
            case DEF_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case COMP_STM:
                fprintf(astOut, "%*cComposite Expression: (%d)\n", indent, ' ', node->pos);
                fprintf(astOut, "%*cVariable Declaration (Composite Expression) :\n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                fprintf(astOut, "%*cExpression (Composite Expression) :\n", indent + 2, ' ');
                printNode(node->children[1], indent + 4);
                break;
            case STM_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case EXP_STMT:
                fprintf(astOut, "%*cExpression:(%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                break;
            case IF_THEN:
                fprintf(astOut, "%*cIF Expression: (%d)\n", indent, ' ', node->pos);
                fprintf(astOut, "%*cIF Conds:\n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                fprintf(astOut, "%*cIF Body:(%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                break;
            case IF_THEN_ELSE:
                fprintf(astOut, "%*cIF Expression - Else: (%d)\n", indent, ' ', node->pos);
                fprintf(astOut, "%*cIF Conds: \n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                fprintf(astOut, "%*cIF Body: (%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                fprintf(astOut, "%*cELSE Body: (%d)\n", indent + 4, ' ', node->pos);
                printNode(node->children[2], indent + 4);
                break;
            case FUNC_CALL:
                fprintf(astOut, "%*cFunction Call: (%d)\n", indent, ' ', node->pos);
                fprintf(astOut, "%*cFunction Name: %s\n", indent + 2, ' ', get<String>(node->value).c_str());
                printNode(node->children[0], indent + 2);
                break;
            case ARGS: {
                int i = 1;
                while (node) {
                    ASTNode *ptr = node->children[0];
                    fprintf(astOut, "%*cParameter #%d Parameter Expression: \n", indent, ' ', i++);
                    printNode(ptr, indent + 2);
                    node = node->children[1];
                }
                fprintf(astOut, "\n");
                break;
            }
            case ASSIGNOP:
            case AND:
            case OR:
            case RELOP:
            case PLUS:
            case MINUS:
            case STAR:
            case DIV:
            case MOD: {
                if (node->value.index() == 2) {
                    fprintf(astOut, "%*c%s\n", indent, ' ', get<String>(node->value).c_str());
                }
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                break;
            }
            case NOT:
            case UMINUS:
                fprintf(astOut, "%*c%s\n", indent, ' ', get<String>(node->value).c_str());
                printNode(node->children[0], indent + 2);
                break;
        }
    }
}

ast::Code::Code() : kind(0), next(nullptr), prev(nullptr) {}

ast::Node::Node() : kind(0), children(4, nullptr), idx(0), type(0), pos(0), num(0), code(nullptr) {}

ast::Opt::Opt() : kind(0), data(0), type(0), level(0) {}
