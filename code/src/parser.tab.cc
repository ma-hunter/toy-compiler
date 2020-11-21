/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:337  */

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

#line 86 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_HOME_SHIROHA_WORKSPACE_TOY_COMPILER_CODE_SCRIPT_INCLUDE_PARSER_TAB_H_INCLUDED
# define YY_YY_HOME_SHIROHA_WORKSPACE_TOY_COMPILER_CODE_SCRIPT_INCLUDE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    RELOP = 260,
    TYPE = 261,
    FLOAT = 262,
    DPLUS = 263,
    LP = 264,
    RP = 265,
    LC = 266,
    RC = 267,
    SEMI = 268,
    COMMA = 269,
    PLUS = 270,
    MINUS = 271,
    STAR = 272,
    DIV = 273,
    MOD = 274,
    ASSIGNOP = 275,
    AND = 276,
    OR = 277,
    NOT = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    RETURN = 282,
    FOR = 283,
    SWITCH = 284,
    CASE = 285,
    COLON = 286,
    DEFAULT = 287,
    CONTINUE = 288,
    BREAK = 289,
    EXT_DEF_LIST = 290,
    EXT_VAR_DEF = 291,
    FUNC_DEF = 292,
    FUNC_DEC = 293,
    EXT_DEC_LIST = 294,
    PARAM_LIST = 295,
    PARAM_DEC = 296,
    VAR_DEF = 297,
    DEC_LIST = 298,
    DEF_LIST = 299,
    COMP_STM = 300,
    STM_LIST = 301,
    EXP_STMT = 302,
    IF_THEN = 303,
    IF_THEN_ELSE = 304,
    FUNC_CALL = 305,
    ARGS = 306,
    FUNCTION = 307,
    PARAM = 308,
    ARG = 309,
    CALL = 310,
    LABEL = 311,
    GOTO = 312,
    JLT = 313,
    JLE = 314,
    JGT = 315,
    JGE = 316,
    EQ = 317,
    NEQ = 318,
    UMINUS = 319,
    LOWER_THEN_ELSE = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:352  */

	Integer type_int;
	Float   type_float;
	char    type_id[32];
	ASTNode *ptr;

#line 202 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_HOME_SHIROHA_WORKSPACE_TOY_COMPILER_CODE_SCRIPT_INCLUDE_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

#define YYUNDEFTOK  2
#define YYMAXUTOK   320

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    54,    55,    57,    58,    59,    61,    63,
      64,    66,    68,    69,    71,    72,    74,    77,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    92,    93,
      94,    96,    98,    99,   101,   102,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   124,   125
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "RELOP", "TYPE", "FLOAT",
  "DPLUS", "LP", "RP", "LC", "RC", "SEMI", "COMMA", "PLUS", "MINUS",
  "STAR", "DIV", "MOD", "ASSIGNOP", "AND", "OR", "NOT", "IF", "ELSE",
  "WHILE", "RETURN", "FOR", "SWITCH", "CASE", "COLON", "DEFAULT",
  "CONTINUE", "BREAK", "EXT_DEF_LIST", "EXT_VAR_DEF", "FUNC_DEF",
  "FUNC_DEC", "EXT_DEC_LIST", "PARAM_LIST", "PARAM_DEC", "VAR_DEF",
  "DEC_LIST", "DEF_LIST", "COMP_STM", "STM_LIST", "EXP_STMT", "IF_THEN",
  "IF_THEN_ELSE", "FUNC_CALL", "ARGS", "FUNCTION", "PARAM", "ARG", "CALL",
  "LABEL", "GOTO", "JLT", "JLE", "JGT", "JGE", "EQ", "NEQ", "UMINUS",
  "LOWER_THEN_ELSE", "$accept", "program", "ExtDefList", "ExtDef",
  "Specifier", "ExtDecList", "VarDec", "FuncDec", "VarList", "ParamDec",
  "CompSt", "StmList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp",
  "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,    -9,   -40,     7,   -40,    54,     6,   -40,   -40,   -40,
      10,     4,    37,    11,    52,   -40,    57,    41,   -40,   -40,
      57,    46,    49,   -40,   -40,    53,    57,    69,    41,   -40,
     -40,    63,   -40,    50,    58,    67,   -40,    73,   -40,     5,
       5,     5,     5,    74,    75,     5,    78,    81,   -40,    85,
      69,   106,   -40,   -40,     5,   -40,    57,    97,    90,   124,
      90,    90,     5,     5,   142,   -40,   -40,   -40,   -40,     5,
     -40,   -40,     5,     5,     5,     5,     5,     5,     5,     5,
     214,   -40,   -40,   160,    89,   -40,   178,   196,   -40,    71,
       8,     8,    12,    12,    90,   232,   262,   247,     5,   -40,
      69,    69,   -40,    83,   -40,    69,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     2,     0,     0,     7,     1,     4,
      11,     0,     9,     0,     0,     5,     0,     0,     6,    13,
       0,     0,    14,    11,    10,     0,     0,    18,     0,    16,
      12,     0,    30,    34,     0,    32,    53,    52,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      18,     0,    29,    15,     0,    31,     0,     0,    48,     0,
      46,    47,     0,     0,     0,    26,    27,    17,    19,     0,
      49,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    33,    51,    56,     0,    45,     0,     0,    22,    39,
      40,    41,    42,    44,    43,    36,    37,    38,     0,    50,
       0,     0,    55,    23,    25,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   104,   -40,    15,    94,   -15,   -40,    84,   -40,
      99,    66,    30,   105,   -40,    61,   -40,   -39,    20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    11,    12,    13,    21,    22,
      48,    49,    50,    27,    28,    34,    35,    51,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      58,    59,    60,    61,     7,    29,    64,     8,    36,    37,
      10,    33,    38,    39,    40,    80,    70,    15,    83,    14,
      70,    41,    17,    86,    87,    74,    75,    76,    42,    20,
      89,    76,    26,    90,    91,    92,    93,    94,    95,    96,
      97,    33,    25,    26,   -28,   -28,    20,     2,   -28,   -28,
     -28,    16,   -28,   -28,    -3,     1,    30,   -28,     2,    83,
       2,    23,    19,    31,   -28,   -28,    32,   -28,   -28,     2,
      54,    55,    36,    37,   -28,   -28,    38,    39,    40,    70,
      17,    56,    57,    62,    63,    41,    72,    73,    74,    75,
      76,    65,    42,    43,    66,    44,    45,    67,    70,    99,
      36,    37,    46,    47,    38,    39,    40,    82,   105,     9,
      24,    69,    18,    41,    70,    53,    68,    81,   102,    71,
      42,    72,    73,    74,    75,    76,    77,    78,    79,    69,
     103,   104,    70,    52,    85,   106,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    69,     0,     0,
      70,     0,     0,     0,     0,    88,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    69,     0,     0,    70,     0,
       0,     0,     0,     0,    98,    72,    73,    74,    75,    76,
      77,    78,    79,    69,     0,     0,    70,     0,   100,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    69,     0,     0,    70,     0,   101,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    69,
       0,     0,    70,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    69,     0,     0,
      70,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    69,    78,    79,    70,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    69,    78,     0,
      70,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76
};

static const yytype_int8 yycheck[] =
{
      39,    40,    41,    42,    13,    20,    45,     0,     3,     4,
       4,    26,     7,     8,     9,    54,     8,    13,    57,     9,
       8,    16,    11,    62,    63,    17,    18,    19,    23,    14,
      69,    19,    17,    72,    73,    74,    75,    76,    77,    78,
      79,    56,     1,    28,     3,     4,    31,     6,     7,     8,
       9,    14,    11,    12,     0,     1,    10,    16,     6,    98,
       6,     4,    10,    14,    23,    24,    13,    26,    27,     6,
      20,    13,     3,     4,    33,    34,     7,     8,     9,     8,
      11,    14,     9,     9,     9,    16,    15,    16,    17,    18,
      19,    13,    23,    24,    13,    26,    27,    12,     8,    10,
       3,     4,    33,    34,     7,     8,     9,    10,    25,     5,
      16,     5,    13,    16,     8,    31,    50,    56,    98,    13,
      23,    15,    16,    17,    18,    19,    20,    21,    22,     5,
     100,   101,     8,    28,    10,   105,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,     5,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,     5,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     5,    -1,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,     5,    -1,    -1,     8,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,     5,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,     5,    21,    22,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,     5,    21,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,    67,    68,    69,    70,    13,     0,    68,
       4,    71,    72,    73,     9,    13,    14,    11,    76,    10,
      70,    74,    75,     4,    71,     1,    70,    79,    80,    72,
      10,    14,    13,    72,    81,    82,     3,     4,     7,     8,
       9,    16,    23,    24,    26,    27,    33,    34,    76,    77,
      78,    83,    79,    74,    20,    13,    14,     9,    83,    83,
      83,    83,     9,     9,    83,    13,    13,    12,    77,     5,
       8,    13,    15,    16,    17,    18,    19,    20,    21,    22,
      83,    81,    10,    83,    84,    10,    83,    83,    13,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    14,    10,
      10,    10,    84,    78,    78,    25,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     1,     1,
       3,     1,     4,     3,     1,     3,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     2,     2,     0,     2,
       2,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       4,     3,     1,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    { print_ast_node((yyvsp[0].ptr),0); entrypoint((yyvsp[0].ptr));}
#line 1519 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 3:
#line 54 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=nullptr;}
#line 1525 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 4:
#line 55 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(EXT_DEF_LIST,yylineno,{(yyvsp[-1].ptr),(yyvsp[0].ptr)});}
#line 1531 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 5:
#line 57 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(EXT_VAR_DEF,yylineno,{(yyvsp[-2].ptr),(yyvsp[-1].ptr)});}
#line 1537 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 6:
#line 58 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FUNC_DEF,yylineno,{(yyvsp[-2].ptr),(yyvsp[-1].ptr),(yyvsp[0].ptr)});}
#line 1543 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 7:
#line 59 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=nullptr;}
#line 1549 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 8:
#line 61 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(TYPE,yylineno);(yyval.ptr)->data = string((yyvsp[0].type_id));(yyval.ptr)->type=(string((yyvsp[0].type_id)) == "float")?FLOAT:INT;}
#line 1555 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 9:
#line 63 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1561 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 10:
#line 64 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(EXT_DEC_LIST,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1567 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 11:
#line 66 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ID,yylineno);(yyval.ptr)->data = (yyvsp[0].type_id);}
#line 1573 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 12:
#line 68 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FUNC_DEC,yylineno,{(yyvsp[-1].ptr)});(yyval.ptr)->data = (yyvsp[-3].type_id);}
#line 1579 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 13:
#line 69 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FUNC_DEC,yylineno);(yyval.ptr)->data = (yyvsp[-2].type_id);(yyval.ptr)->ptr[0]=nullptr;}
#line 1585 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 14:
#line 71 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(PARAM_LIST,yylineno,{(yyvsp[0].ptr)});}
#line 1591 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 15:
#line 72 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(PARAM_LIST,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1597 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 16:
#line 74 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(PARAM_DEC,yylineno,{(yyvsp[-1].ptr),(yyvsp[0].ptr)});}
#line 1603 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 17:
#line 77 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(COMP_STM,yylineno,{(yyvsp[-2].ptr),(yyvsp[-1].ptr)});}
#line 1609 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 18:
#line 80 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=nullptr; }
#line 1615 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 19:
#line 81 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(STM_LIST,yylineno,{(yyvsp[-1].ptr),(yyvsp[0].ptr)});}
#line 1621 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 20:
#line 83 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(EXP_STMT,yylineno,{(yyvsp[-1].ptr)});}
#line 1627 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 21:
#line 84 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1633 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 22:
#line 85 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(RETURN,yylineno,{(yyvsp[-1].ptr)});}
#line 1639 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 23:
#line 86 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(IF_THEN,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1645 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 24:
#line 87 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(IF_THEN_ELSE,yylineno,{(yyvsp[-4].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1651 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 25:
#line 88 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(WHILE,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1657 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 26:
#line 89 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(CONTINUE,yylineno);}
#line 1663 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 27:
#line 90 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(BREAK,yylineno);}
#line 1669 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 28:
#line 92 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=nullptr; }
#line 1675 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 29:
#line 93 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DEF_LIST,yylineno,{(yyvsp[-1].ptr),(yyvsp[0].ptr)});}
#line 1681 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 30:
#line 94 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=nullptr;}
#line 1687 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 31:
#line 96 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(VAR_DEF,yylineno,{(yyvsp[-2].ptr),(yyvsp[-1].ptr)});}
#line 1693 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 32:
#line 98 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DEC_LIST,yylineno,{(yyvsp[0].ptr)});}
#line 1699 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 33:
#line 99 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DEC_LIST,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1705 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 34:
#line 101 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1711 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 35:
#line 102 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ASSIGNOP,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1717 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 36:
#line 104 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ASSIGNOP,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1723 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 37:
#line 105 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(AND,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1729 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 38:
#line 106 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(OR,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1735 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 39:
#line 107 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(RELOP,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});(yyval.ptr)->data = (yyvsp[-1].type_id);}
#line 1741 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 40:
#line 108 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(PLUS,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1747 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 41:
#line 109 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(MINUS,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1753 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 42:
#line 110 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(STAR,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1759 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 43:
#line 111 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(MOD,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1765 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 44:
#line 112 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DIV,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1771 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 45:
#line 113 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 1777 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 46:
#line 114 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(UMINUS,yylineno,{(yyvsp[0].ptr)});}
#line 1783 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 47:
#line 115 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(NOT,yylineno,{(yyvsp[0].ptr)});}
#line 1789 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 48:
#line 116 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DPLUS,yylineno,{(yyvsp[0].ptr)});}
#line 1795 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 49:
#line 117 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(DPLUS,yylineno,{(yyvsp[-1].ptr)});}
#line 1801 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 50:
#line 118 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FUNC_CALL,yylineno,{(yyvsp[-1].ptr)});(yyval.ptr)->data = (yyvsp[-3].type_id);}
#line 1807 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 51:
#line 119 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FUNC_CALL,yylineno);(yyval.ptr)->data = (yyvsp[-2].type_id);}
#line 1813 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 52:
#line 120 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ID,yylineno);(yyval.ptr)->data = (yyvsp[0].type_id);}
#line 1819 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 53:
#line 121 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(INT,yylineno);(yyval.ptr)->data=(yyvsp[0].type_int);(yyval.ptr)->type=INT;}
#line 1825 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 54:
#line 122 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(FLOAT,yylineno);(yyval.ptr)->data=(yyvsp[0].type_float);(yyval.ptr)->type=FLOAT;}
#line 1831 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 55:
#line 124 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ARGS,yylineno,{(yyvsp[-2].ptr),(yyvsp[0].ptr)});}
#line 1837 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;

  case 56:
#line 125 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1652  */
    {(yyval.ptr)=make_node(ARGS,yylineno,{(yyvsp[0].ptr)});}
#line 1843 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
    break;


#line 1847 "/home/shiroha/workspace/toy-compiler/code/script/../src/parser.tab.cc" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 128 "/home/shiroha/workspace/toy-compiler/code/script/../config/parser.y" /* yacc.c:1918  */


int main(int argc, char *argv[]) {
    string file_path;
    if (argc >= 2) {
        file_path = string(argv[1]);
    } else {
        file_path = "./test.txt";
    }

    printf("File path = %s\n", file_path.c_str());
    yyin = fopen(file_path.c_str(), "r");
    if (!yyin) exit(0);
    yylineno = 1;
    yyparse();
    return 0;
}

#include<stdarg.h>
void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
