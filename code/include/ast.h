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
    };

    struct Code {
        int kind;
        Opt $1, $2, res;
        shared_ptr<Code> prev, next;
    };

    struct Node {
        int kind;
        var value;
        vector<Node *> children;
        string eTrue, eFalse, sNext;
        shared_ptr<Code> code;
        int type, pos, num;
    };

    // Methods

    Node *newNode(
        int kind,
        int pos,
        const vector<Node *>& nodes = vector<Node *>()
    );

    void entryPoint(Node *node);

    void boolExpression(Node *node);

    void expression(Node *node);

    void toObjectCode(shared_ptr<Node> head);
}

using Operation = ast::Opt;
using CodeNode = ast::Code;
using ASTNode = ast::Node;

#endif //TOY_COMPILER_AST_H
