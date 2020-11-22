//
// Created by Shiroha on 20/11/21.
//

#ifndef TOY_COMPILER_SYMBOL_TABLE_H
#define TOY_COMPILER_SYMBOL_TABLE_H

#include <string>
#include <optional>
#include <vector>

#include "type.h"
#include "config.h"

using std::string, std::optional;

namespace symbol_table {

    enum SymbolFlag {
        fFunc = 'F',
        fVar = 'V',
        fParam = 'P',
        fTemp = 'T'
    };

    struct Symbol {
        string name;
        int level, type;
        int paramNum;
        string alias;
        SymbolFlag flag;
        int idx;
    };

    optional<Symbol> searchByName(const string &name);

    optional<Symbol> searchByFlag(const string &name, SymbolFlag flag);

    optional<Symbol> searchByAlias(const string &alias);

    void print();

    optional<int> fill(
        const string &name,
        const string &alias,
        int level,
        int type,
        SymbolFlag flag
    );
}

using Symbol = symbol_table::Symbol;
using SymbolTable = symbol_table_t<Symbol>;

#ifdef IS_HASH_TABLE
#define iterate_symbol_table(symbol) for (const auto& [$alias, symbol] : symbolTable)
#else
#define iterate_symbol_table(symbol) for (const auto& symbol : symbolTable)
#endif

#endif //TOY_COMPILER_SYMBOL_TABLE_H
