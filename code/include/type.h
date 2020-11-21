//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_TYPE_H
#define TOY_COMPILER_TYPE_H

#include <string>

using String = std::string;
using Boolean = bool;
#if 0
using Integer  = int;
using Long = long long;
using Float = float;
using Double = double;
#else
using Integer = long long;
using Long = __int128;
using Float = double;
using Double = long double;
#endif

#endif //TOY_COMPILER_TYPE_H
