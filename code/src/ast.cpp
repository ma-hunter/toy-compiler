//
// Created by Shiroha on 20/11/21.
//

#include "ast.h"
#include "config.h"
#include "symbol_table.h"

#include "parser.tab.h"

extern SymbolTable symbolTable;

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

    if (node) {
        switch (node->kind) {
            case INT:
                printf("%*cINT: %d\n", indent, ' ', get<Integer>(node->value));
                break;
            case ID:
                printf("%*cID: %s\n", indent, ' ', get<String>(node->value).c_str());
                break;
            case TYPE:
                printf("%*cType: %s\n", indent, ' ', get<String>(node->value).c_str());
                break;
            case FLOAT:
                printf("%*cFLOAT: %f\n", indent, ' ', get<Float>(node->value));
                break;
            case WHILE:
                printf("%*cLoop Statement: (%d)\n", indent, ' ', node->pos);
                printf("%*cLoop Condition: \n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                printf("%*cLoop Body: (%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                break;
            case RETURN:
                printf("%*cReturn Expression:(%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                break;
            case CONTINUE:
                printf("%*cContinue Statement\n", indent, ' ');
                break;
            case BREAK:
                printf("%*cBreak Statement\n", indent, ' ');
                break;
            case EXT_DEF_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case EXT_VAR_DEF:
                printf("%*cVariable Declaration: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                printf("%*cVariable Name: \n", indent + 2, ' ');
                printNode(node->children[1], indent + 4);
                break;
            case FUNC_DEF:
                printf("%*cFunction Declaration: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                printNode(node->children[2], indent + 2);
                break;
            case FUNC_DEC:
                printf("%*cFunction Name: %s\n", indent, ' ', get<String>(node->value).c_str());
                if (node->children[0]) {
                    printf("%*cFunction Parameters: \n", indent, ' ');
                    printNode(node->children[0], indent + 2);
                } else {
                    printf("%*cFunction without Parameters: \n", indent + 2, ' ');
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
                printf("%*cType: %s, Parameter Name: %s\n", indent, ' ', node->children[0]->type == INT ? "int" : "float",
                       get<String>(node->children[1]->value).c_str());
                break;
            case VAR_DEF:
                printf("%*cVariable Decl: (%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                break;
            case DEC_LIST: {
                printf("%*cVariable Name Decl:\n", indent, ' ');
                ASTNode *ptr = node;
                while (ptr) {
                    if (ptr->children[0]->kind == ID)
                        printf("%*c %s\n", indent + 4, ' ', get<String>(ptr->children[0]->value).c_str());
                    else if (ptr->children[0]->kind == ASSIGNOP) {
                        printf("%*c %s ASSIGNOP\n ", indent + 4, ' ', get<String>(ptr->children[0]->children[0]->value).c_str());
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
                printf("%*cComposite Expression: (%d)\n", indent, ' ', node->pos);
                printf("%*cVariable Declaration (Composite Expression) :\n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                printf("%*cExpression (Composite Expression) :\n", indent + 2, ' ');
                printNode(node->children[1], indent + 4);
                break;
            case STM_LIST:
                printNode(node->children[0], indent);
                printNode(node->children[1], indent);
                break;
            case EXP_STMT:
                printf("%*cExpression:(%d)\n", indent, ' ', node->pos);
                printNode(node->children[0], indent + 2);
                break;
            case IF_THEN:
                printf("%*cIF Expression: (%d)\n", indent, ' ', node->pos);
                printf("%*cIF Conds:\n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                printf("%*cIF Body:(%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                break;
            case IF_THEN_ELSE:
                printf("%*cIF Expression - Else: (%d)\n", indent, ' ', node->pos);
                printf("%*cIF Conds: \n", indent + 2, ' ');
                printNode(node->children[0], indent + 4);
                printf("%*cIF Body: (%d)\n", indent + 2, ' ', node->pos);
                printNode(node->children[1], indent + 4);
                printf("%*cELSE Body: (%d)\n", indent + 4, ' ', node->pos);
                printNode(node->children[2], indent + 4);
                break;
            case FUNC_CALL:
                printf("%*cFunction Call: (%d)\n", indent, ' ', node->pos);
                printf("%*cFunction Name: %s\n", indent + 2, ' ', get<String>(node->value).c_str());
                printNode(node->children[0], indent + 2);
                break;
            case ARGS: {
                int i = 1;
                while (node) {
                    ASTNode *ptr = node->children[0];
                    printf("%*cParameter #%d Parameter Expression: \n", indent, ' ', i++);
                    printNode(ptr, indent + 2);
                    node = node->children[1];
                }
                printf("\n");
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
                    printf("%*c%s\n", indent, ' ', get<String>(node->value).c_str());
                }
                printNode(node->children[0], indent + 2);
                printNode(node->children[1], indent + 2);
                break;
            }
            case NOT:
            case UMINUS:
                printf("%*c%s\n", indent, ' ', get<String>(node->value).c_str());
                printNode(node->children[0], indent + 2);
                break;
        }
    }
}

ast::Code::Code() : kind(0), next(nullptr), prev(nullptr) {}

ast::Node::Node() : kind(0), children(4, nullptr), idx(0), type(0), pos(0), num(0), code(nullptr) {}

ast::Opt::Opt() : kind(0), data(0), type(0), level(0) {}
