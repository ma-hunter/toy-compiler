#include <cstdio>
#include <cmath>
#include <cstring>

#include "parser.tab.h"
#include "def.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void print_ast_node(ASTNode *,int);
int yylex();

int main(int argc, char *argv[]) {
    string file_path;
    if (argc >= 2) {
        file_path = string(argv[1]);
    } else {
        fprintf(stderr, "Fatal error: No input file.");
        exit(EXIT_FAILURE);
    }

    printf("File path = %s\n", file_path.c_str());
    yyin = fopen(file_path.c_str(), "r");
    if (!yyin) exit(0);
    yylineno = 1;
    yyparse();
    exit(EXIT_SUCCESS);
}

#include<stdarg.h>
void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
