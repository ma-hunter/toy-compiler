//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_AST_H
#define TOY_COMPILER_AST_H

#include <iostream>
#include <vector>
#include <variant>
#include <memory>

#include "type.h"

using std::variant, std::get;
using std::shared_ptr;
using std::vector, std::string;

using var = variant<Integer, Float, String>;

namespace ast {

    struct Opt {
        int kind, type;
        var data;
        int level;

        Opt();
    };

    struct Code {
        int kind;
        vector<shared_ptr<Code>> data;
        Opt op1, op2, res;
        shared_ptr<Code> prev, next;

        Code();
    };

    struct Node {
        int kind;
        var value;
        vector<Node *> children;
        int idx;
        string eTrue, eFalse, sNext;
        shared_ptr<Code> code;
        int type, pos, num;

        Node();
    };

    // Methods

    Node *newNode(
        int kind,
        int pos,
        const vector<Node *>& nodes = vector<Node *>()
    );

    void printNode(Node *node, int indent);

}

using Operation = ast::Opt;
using CodeNode = ast::Code;
using ASTNode = ast::Node;

#endif //TOY_COMPILER_AST_H
