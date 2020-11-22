//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_CONFIG_H
#define TOY_COMPILER_CONFIG_H

#include <unordered_map>
#include <vector>

// Use policy based data structures in external C++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using std::string, std::unordered_map;
using __gnu_pbds::cc_hash_table, __gnu_pbds::gp_hash_table;

// Configure if print methods work.
constexpr bool PRINT_AST = false;
constexpr bool PRINT_SYMBOL_TABLE = false;
constexpr bool PRINT_LLVM_IR = false;

// Configure data structure use in symbol table.
// In hash map: pair [<string>alias, symbol_t]
#define SYMBOL_TABLE_T(TYPE) SYMBOL_TABLE_##TYPE
#define IS_HASH_TABLE
#define SYMBOL_TABLE_T_VECTOR

template <typename symbol_t>
#if defined SYMBOL_TABLE_T_STD_HASH_TABLE
using symbol_table_t = unordered_map<string, symbol_t>;
#elif defined SYMBOL_TABLE_T_CC_HASH_TABLE
using symbol_table_t = cc_hash_table<string, symbol_t>;
#elif defined SYMBOL_TABLE_T_GP_HASH_TABLE
using symbol_table_t = gp_hash_table<string, symbol_t>;
#elif defined SYMBOL_TABLE_T_VECTOR
using symbol_table_t = vector<symbol_t>;
#undef IS_HASH_TABLE
#endif

#endif //TOY_COMPILER_CONFIG_H
