//
// Created by Shiroha on 20/11/21.
//

#include "symbol_table.h"
#include "parser.tab.h"

#include <vector>

using std::vector, std::nullopt;
using symbol_table::SymbolFlag, symbol_table::fNull;

SymbolTable symbolTable;
vector<int> scopeStack;

optional<Symbol> symbol_table::searchByName(const string &name) {
    iterate_symbol_table($symbol) {
        if (name == $symbol.name) return $symbol;
    } return nullopt;
}

optional<Symbol> symbol_table::searchByFlag(const string &name, SymbolFlag flag) {
    iterate_symbol_table($symbol) {
        if (flag == $symbol.flag && name == $symbol.name) return $symbol;
    } return nullopt;
}

optional<Symbol> symbol_table::searchByAlias(const string &alias) {
#ifdef IS_HASH_TABLE
    if (symbolTable.count(alias)) return symbolTable[alias];
    else return nullopt;
#else
    iterate_symbol_table($symbol) {
        if (alias == $symbol.alias) return $symbol;
    } return nullopt;
#endif
}

optional<int> symbol_table::fill(
        const string &name,
        const string &alias,
        int level,
        int type,
        SymbolFlag flag) {
#ifdef IS_HASH_TABLE
    iterate_symbol_table($symbol) {
        if ($symbol.level && $symbol.level != level) continue;
        if (!level && $symbol.level == 1) continue;
        if ($symbol.name == name) return nullopt;
    }
#else
    for (int i = symbolTable.size() - 1; i >= 0 && (symbolTable[i].level == level || !level); i--) {
        if (level == 0 && symbolTable[i].level == 1) continue;
        if (symbolTable[i].name == name) return nullopt;
    }
#endif

    Symbol sym{};
    sym.name = name;
    sym.alias = alias;
    sym.level = level;
    sym.type = type;
    sym.flag = flag;
    sym.idx = symbolTable.size();
#ifdef IS_HASH_TABLE
    symbolTable[alias] = sym;
#else
    symbolTable.emplace_back(sym);
#endif
    // Return ID of the temporary variable
    // TODO: Not adapt for hash map
    return symbolTable.size() - 1;
}

void symbol_table::print() {

    if constexpr (!PRINT_SYMBOL_TABLE) return;
    printf("%9s %9s %9s %9s %9s\n", "Name", "Alias", "Level", "Type", "Flag");
    iterate_symbol_table(symbol)
        printf("%9s %9s %9d %9s %9c\n", symbol.name.c_str(),
               symbol.alias.c_str(), symbol.level,
               symbol.type == INT ? "int" : "float", symbol.flag);
    printf("\n\n");
}

symbol_table::Symbol::Symbol() : level(0), type(0), paramNum(0), flag(fNull), idx(0) {}
