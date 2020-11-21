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

// Define data structures use for symbol table.
constexpr int VECTOR = 0;
constexpr int STD_HASH_TABLE = 1;
constexpr int CC_HASH_TABLE = 2;
constexpr int GP_HASH_TABLE = 3;

// Configure data structure use in symbol table.
constexpr int SYMBOL_TABLE_T = STD_HASH_TABLE;

template <typename symbol_t>
#if SYMBOL_TABLE_T == STD_HASH_TABLE
using symbol_table_t = unordered_map<string, symbol_t>;
#elif SYMBOL_TABLE_T == CC_HASH_TABLE
using symbol_table_t = cc_hash_table<string, symbol_t>;
#elif SYMBOL_TABLE_T == GP_HASH_TABLE
using symbol_table_t = gp_hash_table<string, symbol_t>;
#elif SYMBOL_TABLE_T == VECTOR
using symbol_table_t = vector<symbol_t>;
#endif

#endif //TOY_COMPILER_CONFIG_H
