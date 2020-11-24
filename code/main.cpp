#include <cstdio>
#include <cmath>
#include <cstdarg>

#include "parser.tab.h"
#include "def.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void print_ast_node(ASTNode *,int);
int yylex();

FILE *astOut, *sybOut, *irOut;

int main(int argc, char *argv[]) {
    string file_path;
    if (argc >= 2) {
        file_path = string(argv[1]);
    } else {
        fprintf(stderr, "Fatal error: No input file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "Input file path: %s\n", file_path.c_str());
    if constexpr (PRINT_AST) astOut = fopen("ast.txt", "w");
    if constexpr (PRINT_SYMBOL_TABLE) sybOut = fopen("syb.txt", "w");
    // if constexpr (PRINT_LLVM_IR) irOut = fopen("ir.ll", "w");

    yyin = fopen(file_path.c_str(), "r");
    if (!yyin) exit(0);
    yylineno = 1;
    yyparse();
    exit(EXIT_SUCCESS);
}

void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
