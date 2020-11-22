%define parse.error verbose
%locations
%code top {
#include <cstdio>
#include <cmath>
#include <cstring>

#include "parser.tab.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void print_ast_node(ASTNode *,int);
int yylex();
}

%code requires {
    #include "def.h"
}

%union {
	Integer   type_int;
	Float     type_float;
	char      type_id[32];
	ASTNode   *ptr;
}

%type  <ptr> program ExtDefList ExtDef  Specifier ExtDecList FuncDec CompSt VarList VarDec ParamDec Stmt StmList DefList Def DecList Dec Exp Args

%token <type_int> INT
%token <type_id> ID  RELOP TYPE
%token <type_float> FLOAT

%token DPLUS LP RP LC RC SEMI COMMA
%token PLUS MINUS STAR DIV MOD ASSIGNOP AND OR NOT IF ELSE WHILE RETURN FOR SWITCH CASE COLON DEFAULT CONTINUE BREAK
%token EXT_DEF_LIST EXT_VAR_DEF FUNC_DEF FUNC_DEC EXT_DEC_LIST PARAM_LIST PARAM_DEC VAR_DEF DEC_LIST DEF_LIST COMP_STM STM_LIST EXP_STMT IF_THEN IF_THEN_ELSE
%token FUNC_CALL ARGS FUNCTION PARAM ARG CALL LABEL GOTO JLT JLE JGT JGE EQ NEQ


%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%left MOD
%right UMINUS NOT DPLUS

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%

program: ExtDefList    { print_ast_node($1,0); entrypoint($1);}
    ;
ExtDefList: {$$=nullptr;}
    | ExtDef ExtDefList {$$=ast::newNode(EXT_DEF_LIST,yylineno,{$1,$2});}
    ;
ExtDef:   Specifier ExtDecList SEMI   {$$=ast::newNode(EXT_VAR_DEF,yylineno,{$1,$2});}
    |Specifier FuncDec CompSt    {$$=ast::newNode(FUNC_DEF,yylineno,{$1,$2,$3});}
    | error SEMI   {$$=nullptr;}
    ;
Specifier:  TYPE    {$$=ast::newNode(TYPE,yylineno);$$->value = string($1);$$->type=(string($1) == "float")?FLOAT:INT;}   
    ;
ExtDecList:  VarDec      {$$=$1;}
    | VarDec COMMA ExtDecList {$$=ast::newNode(EXT_DEC_LIST,yylineno,{$1,$3});}
    ;  
VarDec:  ID          {$$=ast::newNode(ID,yylineno);$$->value = $1;}
    ;
FuncDec: ID LP VarList RP   {$$=ast::newNode(FUNC_DEC,yylineno,{$3});$$->value = $1;}
	|ID LP  RP   {$$=ast::newNode(FUNC_DEC,yylineno);$$->value = $1;$$->children[0]=nullptr;}
    ;
VarList: ParamDec  {$$=ast::newNode(PARAM_LIST,yylineno,{$1});}
    | ParamDec COMMA  VarList  {$$=ast::newNode(PARAM_LIST,yylineno,{$1,$3});}
    ;
ParamDec: Specifier VarDec         {$$=ast::newNode(PARAM_DEC,yylineno,{$1,$2});}
    ;

CompSt: LC DefList StmList RC    {$$=ast::newNode(COMP_STM,yylineno,{$2,$3});}
    ;

StmList: {$$=nullptr; }  
    | Stmt StmList  {$$=ast::newNode(STM_LIST,yylineno,{$1,$2});}
    ;
Stmt:   Exp SEMI    {$$=ast::newNode(EXP_STMT,yylineno,{$1});}
    | CompSt      {$$=$1;}
    | RETURN Exp SEMI   {$$=ast::newNode(RETURN,yylineno,{$2});}
    | IF LP Exp RP Stmt %prec LOWER_THEN_ELSE   {$$=ast::newNode(IF_THEN,yylineno,{$3,$5});}
    | IF LP Exp RP Stmt ELSE Stmt   {$$=ast::newNode(IF_THEN_ELSE,yylineno,{$3,$5,$7});}
    | WHILE LP Exp RP Stmt {$$=ast::newNode(WHILE,yylineno,{$3,$5});}
    | CONTINUE SEMI {$$=ast::newNode(CONTINUE,yylineno);}
    | BREAK SEMI {$$=ast::newNode(BREAK,yylineno);}
    ;
DefList: {$$=nullptr; }
    | Def DefList {$$=ast::newNode(DEF_LIST,yylineno,{$1,$2});}
    | error SEMI   {$$=nullptr;}
    ;
Def:    Specifier DecList SEMI {$$=ast::newNode(VAR_DEF,yylineno,{$1,$2});}
    ;
DecList: Dec  {$$=ast::newNode(DEC_LIST,yylineno,{$1});}
    | Dec COMMA DecList  {$$=ast::newNode(DEC_LIST,yylineno,{$1,$3});}
	;
Dec:     VarDec  {$$=$1;}
    | VarDec ASSIGNOP Exp  {$$=ast::newNode(ASSIGNOP,yylineno,{$1,$3});}
    ;
Exp:    Exp ASSIGNOP Exp {$$=ast::newNode(ASSIGNOP,yylineno,{$1,$3});}
    | Exp AND Exp   {$$=ast::newNode(AND,yylineno,{$1,$3});}
    | Exp OR Exp    {$$=ast::newNode(OR,yylineno,{$1,$3});}
    | Exp RELOP Exp {$$=ast::newNode(RELOP,yylineno,{$1,$3});$$->value = $2;}
    | Exp PLUS Exp  {$$=ast::newNode(PLUS,yylineno,{$1,$3});}
    | Exp MINUS Exp {$$=ast::newNode(MINUS,yylineno,{$1,$3});}
    | Exp STAR Exp  {$$=ast::newNode(STAR,yylineno,{$1,$3});}
    | Exp MOD Exp  {$$=ast::newNode(MOD,yylineno,{$1,$3});}
    | Exp DIV Exp   {$$=ast::newNode(DIV,yylineno,{$1,$3});}
    | LP Exp RP     {$$=$2;}
    | MINUS Exp %prec UMINUS   {$$=ast::newNode(UMINUS,yylineno,{$2});}
    | NOT Exp       {$$=ast::newNode(NOT,yylineno,{$2});}
    | DPLUS  Exp      {$$=ast::newNode(DPLUS,yylineno,{$2});}
    | Exp DPLUS      {$$=ast::newNode(DPLUS,yylineno,{$1});}
    | ID LP Args RP {$$=ast::newNode(FUNC_CALL,yylineno,{$3});$$->value = $1;}
    | ID LP RP      {$$=ast::newNode(FUNC_CALL,yylineno);$$->value = $1;}
    | ID            {$$=ast::newNode(ID,yylineno);$$->value = $1;}
    | INT           {$$=ast::newNode(INT,yylineno);$$->value=$1;$$->type=INT;}
    | FLOAT         {$$=ast::newNode(FLOAT,yylineno);$$->value=$1;$$->type=FLOAT;}
    ;
Args:    Exp COMMA Args    {$$=ast::newNode(ARGS,yylineno,{$1,$3});}
    | Exp               {$$=ast::newNode(ARGS,yylineno,{$1});}
    ;

%%


