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

namespace ast {

    struct node {
        variant<Integer, Float, String> value;
    };
}


#endif //TOY_COMPILER_AST_H
