//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_TYPE_H
#define TOY_COMPILER_TYPE_H

#include <string>

#define __INT_32

using Boolean = bool;
using Char = char;
#ifdef __INT_32
using Integer  = int;
using Long = long long;
using Float = float;
using Double = double;
#elif defined __INT_64  // TODO: should adapt IR translator
using Integer = long long;
using Long = __int128;
using Float = double;
using Double = long double;
#endif
using String = std::string;

#endif //TOY_COMPILER_TYPE_H
