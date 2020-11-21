//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_SYMBOL_TABLE_H
#define TOY_COMPILER_SYMBOL_TABLE_H

#include <string>

#include "type.h"
#include "config.h"

using std::string;

namespace symbol_table {

    enum SymbolFlag {
        FUNCTION = 'F',
        VARIABLE = 'V',
        PARAMETER = 'P',
        TEMPORARY = 'T'
    };

    struct Symbol {
        string name;
        int level, type;
        int paramNum;
        string alias;
        SymbolFlag flag;
        int idx;
    };
}

using Symbol = symbol_table::Symbol;
using SymbolTable = symbol_table_t<Symbol>;

// TODO: if use macro `is_hash_table`, it will appear contrarily.
#if SYMBOL_TABLE_T == VECTOR
#define iterate_symbol_table(symbol) for (const auto& [key, symbol] : symbolTable)
#else
#define iterate_symbol_table(symbol) for (const auto& symbol : symbolTable)
#endif

#endif //TOY_COMPILER_SYMBOL_TABLE_H
