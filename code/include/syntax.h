//
// Created by Shiroha on 20/11/22.
//

#ifndef TOY_COMPILER_SYNTAX_H
#define TOY_COMPILER_SYNTAX_H

#include "ast.h"
#include "symbol_table.h"
#include "use_llvm.h"

#include <tuple>

using ast::Node, symbol_table::SymbolFlag;
using std::tuple;
using llvm::Function, llvm::FunctionType, llvm::LLVMContext, llvm::IRBuilder, llvm::Module;

void entryPoint(Node *node);

void boolExpression(Node *node);

void expression(Node *node);

tuple<
    Function *,
    FunctionType *,
    Function *,
    FunctionType *
> injectPrintFunction(LLVMContext &ctx, IRBuilder<> &builder, Module &_module);

void toObjectCode(shared_ptr<CodeNode> head);


#endif //TOY_COMPILER_SYNTAX_H
