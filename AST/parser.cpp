/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

    #include "ast.h"
    #include "define.h"
    #include <memory>
    #include<stdarg.h>
    using namespace std;
    unique_ptr<CompUnitAST> root; /* the top level root node of our final AST */

    extern int yylineno;
    extern int yylex();
    extern void yyerror(const char *s);

#line 83 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    FLOAT = 259,
    ID = 260,
    GTE = 261,
    LTE = 262,
    GT = 263,
    LT = 264,
    EQ = 265,
    NEQ = 266,
    INTTYPE = 267,
    FLOATTYPE = 268,
    VOID = 269,
    CONST = 270,
    RETURN = 271,
    IF = 272,
    ELSE = 273,
    WHILE = 274,
    BREAK = 275,
    CONTINUE = 276,
    LP = 277,
    RP = 278,
    LB = 279,
    RB = 280,
    LC = 281,
    RC = 282,
    COMMA = 283,
    SEMICOLON = 284,
    NOT = 285,
    POS = 286,
    NEG = 287,
    ASSIGN = 288,
    MINUS = 289,
    ADD = 290,
    MUL = 291,
    DIV = 292,
    MOD = 293,
    AND = 294,
    OR = 295,
    LOWER_THEN_ELSE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    CompUnitAST* compUnit;
    DeclDefAST* declDef;
    DeclAST* decl;
    DefListAST* defList;
    DefAST* def;
    ArraysAST* arrays;
    InitValListAST* initValList;
    InitValAST* initVal;
    FuncDefAST* funcDef;
    FuncFParamListAST* FuncFParamList;
    FuncFParamAST* funcFParam;
    BlockAST* block;
    BlockItemListAST* blockItemList;
    BlockItemAST* blockItem;
    StmtAST* stmt;
    ReturnStmtAST* returnStmt;
    SelectStmtAST* selectStmt;
    IterationStmtAST* iterationStmt;
    LValAST* lVal;
    PrimaryExpAST* primaryExp;
    NumberAST* number;
    UnaryExpAST* unaryExp;
    CallAST* call;
    FuncCParamListAST* funcCParamList;
    MulExpAST* mulExp;
    AddExpAST* addExp;
    RelExpAST* relExp;
    EqExpAST* eqExp;
    LAndExpAST* lAndExp;
    LOrExpAST* lOrExp;

    TYPE ty;
    UOP op;
	string* token;
	int int_val;
	float float_val;

#line 216 "parser.cpp"

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

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   121,   125,   132,   136,   143,   149,   158,
     161,   167,   171,   178,   184,   189,   194,   201,   205,   213,
     217,   220,   227,   231,   238,   245,   251,   258,   266,   272,
     276,   283,   289,   295,   305,   308,   315,   319,   326,   330,
     337,   341,   347,   352,   356,   360,   366,   372,   377,   385,
     390,   399,   406,   410,   415,   421,   427,   431,   439,   444,
     449,   457,   463,   472,   477,   482,   490,   495,   504,   507,
     510,   516,   520,   527,   532,   539,   546,   556,   561,   568,
     578,   583,   590,   597,   604,   614,   619,   626,   636,   641,
     649,   654
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "GTE", "LTE", "GT",
  "LT", "EQ", "NEQ", "INTTYPE", "FLOATTYPE", "VOID", "CONST", "RETURN",
  "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "LP", "RP", "LB", "RB", "LC",
  "RC", "COMMA", "SEMICOLON", "NOT", "POS", "NEG", "ASSIGN", "MINUS",
  "ADD", "MUL", "DIV", "MOD", "AND", "OR", "LOWER_THEN_ELSE", "$accept",
  "Program", "CompUnit", "DeclDef", "Decl", "BType", "DefList", "Def",
  "Arrays", "InitVal", "InitValList", "FuncDef", "VoidType",
  "FuncFParamList", "FuncFParam", "Block", "BlockItemList", "BlockItem",
  "Stmt", "SelectStmt", "IterationStmt", "ReturnStmt", "Exp", "Cond",
  "LVal", "PrimaryExp", "Number", "UnaryExp", "Call", "UnaryOp",
  "FuncCParamList", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     191,  -113,  -113,  -113,    66,    15,   191,  -113,  -113,    24,
    -113,    28,    31,  -113,  -113,    40,    58,  -113,    22,    -8,
      96,     5,   156,    19,    32,    31,  -113,   141,  -113,    26,
      43,    71,  -113,  -113,  -113,   122,   156,  -113,  -113,  -113,
      38,  -113,  -113,  -113,  -113,  -113,   156,   -25,   106,    16,
    -113,  -113,   156,    19,  -113,    26,    79,    55,  -113,    45,
      26,    66,   133,    77,    57,  -113,  -113,   156,   156,   156,
     156,   156,  -113,  -113,   130,    70,  -113,  -113,    26,   147,
      89,   109,   120,   146,  -113,  -113,  -113,    31,  -113,    93,
    -113,  -113,  -113,  -113,  -113,   158,   112,   145,  -113,  -113,
    -113,  -113,    98,  -113,  -113,  -113,  -113,   -25,   -25,  -113,
      19,  -113,  -113,  -113,   159,   156,   156,  -113,  -113,  -113,
    -113,  -113,   156,   165,  -113,   156,  -113,  -113,   169,   106,
     201,   155,   154,   171,   189,   184,    77,  -113,   113,   156,
     156,   156,   156,   156,   156,   156,   156,   113,  -113,   176,
     106,   106,   106,   106,   201,   201,   155,   154,  -113,   113,
    -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    28,     0,     0,     2,     4,     5,     0,
       6,     0,     0,     1,     3,    16,     0,    11,     0,    16,
       0,     0,     0,     0,    15,     0,     8,     0,     7,     0,
       0,     0,    29,    61,    62,    56,     0,    70,    69,    68,
       0,    59,    63,    60,    73,    64,     0,    77,    54,     0,
      14,    19,     0,     0,    12,     0,     0,     0,    25,    31,
       0,     0,     0,    57,     0,    17,    65,     0,     0,     0,
       0,     0,    20,    23,     0,     0,    13,    27,     0,     0,
       0,     0,     0,     0,    34,    40,    38,     0,    45,     0,
      36,    39,    47,    48,    46,     0,    59,     0,    24,    30,
      66,    71,     0,    58,    74,    75,    76,    79,    78,    21,
       0,    18,    26,    53,     0,     0,     0,    44,    43,    35,
      37,    42,     0,    32,    67,     0,    22,    52,     0,    80,
      85,    88,    90,    55,     0,     0,    33,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    49,
      81,    82,    83,    84,    86,    87,    89,    91,    51,     0,
      50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,   208,   -50,     4,   203,   192,   -32,   -44,
    -113,  -113,  -113,   193,   157,   -23,  -113,   127,  -112,  -113,
    -113,  -113,   -22,   105,   -55,  -113,  -113,   116,  -113,  -113,
    -113,   103,    56,    36,    74,    76,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    30,    16,    17,    24,    50,
      74,    10,    11,    31,    32,    88,    89,    90,    91,    92,
      93,    94,    95,   128,    41,    42,    43,    44,    45,    46,
     102,    47,    48,   130,   131,   132,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    51,    96,    63,     9,    73,    58,    86,    12,    76,
       9,    67,    68,    69,    64,    13,    22,     1,     2,    33,
      34,    35,    33,    34,    35,    23,   149,    51,    29,    15,
      75,    51,    77,    18,    96,   158,    19,    98,    36,    86,
     101,    36,    49,    72,    27,    49,    37,   160,    59,    37,
      38,    39,    57,    38,    39,   112,    52,   114,    33,    34,
      35,    87,    21,    65,    22,    53,   126,     1,     2,    97,
       4,    79,    80,    23,    81,    82,    83,    36,     1,     2,
     103,    57,    84,    96,    85,    37,    25,    26,    51,    38,
      39,   136,    96,    87,    60,   111,    33,    34,    35,    61,
     135,    52,    78,   137,    96,     1,     2,    61,     4,    79,
      80,   115,    81,    82,    83,    36,    33,    34,    35,    57,
     119,   124,    85,    37,    25,    28,   125,    38,    39,    79,
      80,   116,    81,    82,    83,    36,    33,    34,    35,    57,
      70,    71,    85,    37,    62,   122,    22,    38,    39,   117,
      33,    34,    35,     1,     2,    36,   100,   109,   110,    33,
      34,    35,    66,    37,    55,   143,   144,    38,    39,    36,
     123,   129,   129,   107,   108,   118,   113,    37,    36,   154,
     155,    38,    39,   104,   105,   106,    37,   121,   127,    22,
      38,    39,   138,   145,   159,   150,   151,   152,   153,   129,
     129,   129,   129,     1,     2,     3,     4,   139,   140,   141,
     142,   146,   147,   148,    14,    20,   120,    54,    99,   156,
      56,   134,   157
};

static const yytype_uint8 yycheck[] =
{
      22,    23,    57,    35,     0,    49,    29,    57,     4,    53,
       6,    36,    37,    38,    36,     0,    24,    12,    13,     3,
       4,     5,     3,     4,     5,    33,   138,    49,    23,     5,
      52,    53,    55,     5,    89,   147,     5,    60,    22,    89,
      62,    22,    26,    27,    22,    26,    30,   159,     5,    30,
      34,    35,    26,    34,    35,    78,    24,    79,     3,     4,
       5,    57,    22,    25,    24,    33,   110,    12,    13,    24,
      15,    16,    17,    33,    19,    20,    21,    22,    12,    13,
      23,    26,    27,   138,    29,    30,    28,    29,   110,    34,
      35,   123,   147,    89,    23,    25,     3,     4,     5,    28,
     122,    24,    23,   125,   159,    12,    13,    28,    15,    16,
      17,    22,    19,    20,    21,    22,     3,     4,     5,    26,
      27,    23,    29,    30,    28,    29,    28,    34,    35,    16,
      17,    22,    19,    20,    21,    22,     3,     4,     5,    26,
      34,    35,    29,    30,    22,    33,    24,    34,    35,    29,
       3,     4,     5,    12,    13,    22,    23,    27,    28,     3,
       4,     5,    46,    30,    23,    10,    11,    34,    35,    22,
      25,   115,   116,    70,    71,    29,    29,    30,    22,   143,
     144,    34,    35,    67,    68,    69,    30,    29,    29,    24,
      34,    35,    23,    39,    18,   139,   140,   141,   142,   143,
     144,   145,   146,    12,    13,    14,    15,     6,     7,     8,
       9,    40,    23,    29,     6,    12,    89,    25,    61,   145,
      27,   116,   146
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    14,    15,    43,    44,    45,    46,    47,
      53,    54,    47,     0,    45,     5,    48,    49,     5,     5,
      48,    22,    24,    33,    50,    28,    29,    22,    29,    23,
      47,    55,    56,     3,     4,     5,    22,    30,    34,    35,
      64,    66,    67,    68,    69,    70,    71,    73,    74,    26,
      51,    64,    24,    33,    49,    23,    55,    26,    57,     5,
      23,    28,    22,    50,    64,    25,    69,    36,    37,    38,
      34,    35,    27,    51,    52,    64,    51,    57,    23,    16,
      17,    19,    20,    21,    27,    29,    46,    47,    57,    58,
      59,    60,    61,    62,    63,    64,    66,    24,    57,    56,
      23,    64,    72,    23,    69,    69,    69,    73,    73,    27,
      28,    25,    57,    29,    64,    22,    22,    29,    29,    27,
      59,    29,    33,    25,    23,    28,    51,    29,    65,    74,
      75,    76,    77,    78,    65,    64,    50,    64,    23,     6,
       7,     8,     9,    10,    11,    39,    40,    23,    29,    60,
      74,    74,    74,    74,    75,    75,    76,    77,    60,    18,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      51,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    63,    63,    64,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     3,     4,     3,     2,     1,     3,     4,     1,
       2,     3,     3,     1,     6,     5,     6,     5,     1,     1,
       3,     2,     4,     5,     2,     3,     1,     2,     1,     1,
       1,     4,     2,     2,     2,     1,     1,     1,     1,     5,
       7,     5,     3,     2,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 115 "parser.y"
                 {
          root = unique_ptr<CompUnitAST>((yyvsp[0].compUnit));
		}
#line 1635 "parser.cpp"
    break;

  case 3:
#line 121 "parser.y"
                          {
            (yyval.compUnit) = (yyvsp[-1].compUnit);
            (yyval.compUnit)->declDefList.push_back(unique_ptr<DeclDefAST>((yyvsp[0].declDef)));
		}
#line 1644 "parser.cpp"
    break;

  case 4:
#line 125 "parser.y"
                         {
            (yyval.compUnit) = new CompUnitAST();
		    (yyval.compUnit)->declDefList.push_back(unique_ptr<DeclDefAST>((yyvsp[0].declDef)));
		}
#line 1653 "parser.cpp"
    break;

  case 5:
#line 132 "parser.y"
              {
			(yyval.declDef) = new DeclDefAST();
			(yyval.declDef)->Decl = unique_ptr<DeclAST>((yyvsp[0].decl));
		}
#line 1662 "parser.cpp"
    break;

  case 6:
#line 136 "parser.y"
                         {
            (yyval.declDef) =  new DeclDefAST();
			(yyval.declDef)->funcDef = unique_ptr<FuncDefAST>((yyvsp[0].funcDef));
		}
#line 1671 "parser.cpp"
    break;

  case 7:
#line 143 "parser.y"
                                      {
            (yyval.decl) = new DeclAST();
            (yyval.decl)->isConst = true;
			(yyval.decl)->bType = (yyvsp[-2].ty);
			(yyval.decl)->defList.swap((yyvsp[-1].defList)->list);
		}
#line 1682 "parser.cpp"
    break;

  case 8:
#line 149 "parser.y"
                                 {
            (yyval.decl) = new DeclAST();
            (yyval.decl)->isConst = false;
			(yyval.decl)->bType = (yyvsp[-2].ty);
			(yyval.decl)->defList.swap((yyvsp[-1].defList)->list);
        }
#line 1693 "parser.cpp"
    break;

  case 9:
#line 158 "parser.y"
                {
			(yyval.ty) = TYPE_INT;
		}
#line 1701 "parser.cpp"
    break;

  case 10:
#line 161 "parser.y"
                           {
            (yyval.ty) = TYPE_FLOAT;
        }
#line 1709 "parser.cpp"
    break;

  case 11:
#line 167 "parser.y"
            {
			(yyval.defList) = new DefListAST();
            (yyval.defList)->list.push_back(unique_ptr<DefAST>((yyvsp[0].def)));
		}
#line 1718 "parser.cpp"
    break;

  case 12:
#line 171 "parser.y"
                                   {
			(yyval.defList) = (yyvsp[-2].defList);
            (yyval.defList)->list.push_back(unique_ptr<DefAST>((yyvsp[0].def)));
		}
#line 1727 "parser.cpp"
    break;

  case 13:
#line 178 "parser.y"
                                 {
			(yyval.def) = new DefAST();
			(yyval.def)->id = unique_ptr<string>((yyvsp[-3].token));
			(yyval.def)->arrays.swap((yyvsp[-2].arrays)->list);
			(yyval.def)->initVal = unique_ptr<InitValAST>((yyvsp[0].initVal));
		}
#line 1738 "parser.cpp"
    break;

  case 14:
#line 184 "parser.y"
                           {
			(yyval.def) = new DefAST();
			(yyval.def)->id = unique_ptr<string>((yyvsp[-2].token));
			(yyval.def)->initVal = unique_ptr<InitValAST>((yyvsp[0].initVal));
        }
#line 1748 "parser.cpp"
    break;

  case 15:
#line 189 "parser.y"
                   {
            (yyval.def) = new DefAST();
            (yyval.def)->id = unique_ptr<string>((yyvsp[-1].token));
            (yyval.def)->arrays.swap((yyvsp[0].arrays)->list);
        }
#line 1758 "parser.cpp"
    break;

  case 16:
#line 194 "parser.y"
            {
            (yyval.def) = new DefAST();
            (yyval.def)->id = unique_ptr<string>((yyvsp[0].token));
        }
#line 1767 "parser.cpp"
    break;

  case 17:
#line 201 "parser.y"
                  {
			(yyval.arrays) = new ArraysAST();
			(yyval.arrays)->list.push_back(unique_ptr<AddExpAST>((yyvsp[-1].addExp)));
		}
#line 1776 "parser.cpp"
    break;

  case 18:
#line 205 "parser.y"
                          {
			(yyval.arrays) = (yyvsp[-3].arrays);
			(yyval.arrays)->list.push_back(unique_ptr<AddExpAST>((yyvsp[-1].addExp)));
		}
#line 1785 "parser.cpp"
    break;

  case 19:
#line 213 "parser.y"
             {
			(yyval.initVal) = new InitValAST();
			(yyval.initVal)->exp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
		}
#line 1794 "parser.cpp"
    break;

  case 20:
#line 217 "parser.y"
                        {
			(yyval.initVal) = new InitValAST();
		}
#line 1802 "parser.cpp"
    break;

  case 21:
#line 220 "parser.y"
                                   {
			(yyval.initVal) = new InitValAST();
			(yyval.initVal)->initValList.swap((yyvsp[-1].initValList)->list);
		}
#line 1811 "parser.cpp"
    break;

  case 22:
#line 227 "parser.y"
                                      {
			(yyval.initValList) = (yyvsp[-2].initValList);
			(yyval.initValList)->list.push_back(unique_ptr<InitValAST>((yyvsp[0].initVal)));
		}
#line 1820 "parser.cpp"
    break;

  case 23:
#line 231 "parser.y"
                         {
			(yyval.initValList)  = new InitValListAST();
			(yyval.initValList)->list.push_back(unique_ptr<InitValAST>((yyvsp[0].initVal)));
		}
#line 1829 "parser.cpp"
    break;

  case 24:
#line 238 "parser.y"
                                             {
			(yyval.funcDef) = new FuncDefAST();
			(yyval.funcDef)->funcType = (yyvsp[-5].ty);
			(yyval.funcDef)->id = unique_ptr<string>((yyvsp[-4].token));
			(yyval.funcDef)->funcFParamList.swap((yyvsp[-2].FuncFParamList)->list);
			(yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
		}
#line 1841 "parser.cpp"
    break;

  case 25:
#line 245 "parser.y"
                              {
			(yyval.funcDef) = new FuncDefAST();
			(yyval.funcDef)->funcType = (yyvsp[-4].ty);
			(yyval.funcDef)->id = unique_ptr<string>((yyvsp[-3].token));
			(yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
		}
#line 1852 "parser.cpp"
    break;

  case 26:
#line 251 "parser.y"
                                                {
			(yyval.funcDef) = new FuncDefAST();
			(yyval.funcDef)->funcType = (yyvsp[-5].ty);
			(yyval.funcDef)->id = unique_ptr<string>((yyvsp[-4].token));
			(yyval.funcDef)->funcFParamList.swap((yyvsp[-2].FuncFParamList)->list);
			(yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
		}
#line 1864 "parser.cpp"
    break;

  case 27:
#line 258 "parser.y"
                                 {
			(yyval.funcDef) = new FuncDefAST();
			(yyval.funcDef)->funcType = (yyvsp[-4].ty);
			(yyval.funcDef)->id = unique_ptr<string>((yyvsp[-3].token));
			(yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
		}
#line 1875 "parser.cpp"
    break;

  case 28:
#line 266 "parser.y"
               {
			(yyval.ty) = TYPE_VOID;
		}
#line 1883 "parser.cpp"
    break;

  case 29:
#line 272 "parser.y"
                           {
				(yyval.FuncFParamList) = new FuncFParamListAST();
				(yyval.FuncFParamList)->list.push_back(unique_ptr<FuncFParamAST>((yyvsp[0].funcFParam)));
			}
#line 1892 "parser.cpp"
    break;

  case 30:
#line 276 "parser.y"
                                                         {
				(yyval.FuncFParamList) = (yyvsp[-2].FuncFParamList);
				(yyval.FuncFParamList)->list.push_back(unique_ptr<FuncFParamAST>((yyvsp[0].funcFParam)));
			}
#line 1901 "parser.cpp"
    break;

  case 31:
#line 283 "parser.y"
                          {
				(yyval.funcFParam) = new FuncFParamAST();
				(yyval.funcFParam)->bType = (yyvsp[-1].ty);
				(yyval.funcFParam)->id = unique_ptr<string>((yyvsp[0].token));
				(yyval.funcFParam)->isArray = false;
			}
#line 1912 "parser.cpp"
    break;

  case 32:
#line 289 "parser.y"
                                        {
				(yyval.funcFParam) = new FuncFParamAST();
				(yyval.funcFParam)->bType = (yyvsp[-3].ty);
				(yyval.funcFParam)->id = unique_ptr<string>((yyvsp[-2].token));
				(yyval.funcFParam)->isArray = true;
			}
#line 1923 "parser.cpp"
    break;

  case 33:
#line 295 "parser.y"
                                               {
				(yyval.funcFParam) = new FuncFParamAST();
				(yyval.funcFParam)->bType = (yyvsp[-4].ty);
				(yyval.funcFParam)->id = unique_ptr<string>((yyvsp[-3].token));
				(yyval.funcFParam)->isArray = true;
				(yyval.funcFParam)->arrays.swap((yyvsp[0].arrays)->list);
			}
#line 1935 "parser.cpp"
    break;

  case 34:
#line 305 "parser.y"
               {
			(yyval.block) = new BlockAST();
		}
#line 1943 "parser.cpp"
    break;

  case 35:
#line 308 "parser.y"
                                     {
			(yyval.block) = new BlockAST();
			(yyval.block)->blockItemList.swap((yyvsp[-1].blockItemList)->list);
		}
#line 1952 "parser.cpp"
    break;

  case 36:
#line 315 "parser.y"
                        {
				(yyval.blockItemList) = new BlockItemListAST();
				(yyval.blockItemList)->list.push_back(unique_ptr<BlockItemAST>((yyvsp[0].blockItem)));
			}
#line 1961 "parser.cpp"
    break;

  case 37:
#line 319 "parser.y"
                                                 {
				(yyval.blockItemList) = (yyvsp[-1].blockItemList);
				(yyval.blockItemList)->list.push_back(unique_ptr<BlockItemAST>((yyvsp[0].blockItem)));
			}
#line 1970 "parser.cpp"
    break;

  case 38:
#line 326 "parser.y"
                      {
				(yyval.blockItem) = new BlockItemAST();
				(yyval.blockItem)->decl = unique_ptr<DeclAST>((yyvsp[0].decl));
			}
#line 1979 "parser.cpp"
    break;

  case 39:
#line 330 "parser.y"
                              {
				(yyval.blockItem) = new BlockItemAST();
				(yyval.blockItem)->stmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
			}
#line 1988 "parser.cpp"
    break;

  case 40:
#line 337 "parser.y"
                        {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = SEMI;
		}
#line 1997 "parser.cpp"
    break;

  case 41:
#line 341 "parser.y"
                                           {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = ASS;
			(yyval.stmt)->lVal = unique_ptr<LValAST>((yyvsp[-3].lVal));
			(yyval.stmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
		}
#line 2008 "parser.cpp"
    break;

  case 42:
#line 347 "parser.y"
                               {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = EXP;
			(yyval.stmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
		}
#line 2018 "parser.cpp"
    break;

  case 43:
#line 352 "parser.y"
                                {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = CONT;
		}
#line 2027 "parser.cpp"
    break;

  case 44:
#line 356 "parser.y"
                         {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = BRE;
		}
#line 2036 "parser.cpp"
    break;

  case 45:
#line 360 "parser.y"
               {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = BLK;
			(yyval.stmt)->block = unique_ptr<BlockAST>((yyvsp[0].block));

		}
#line 2047 "parser.cpp"
    break;

  case 46:
#line 366 "parser.y"
                    {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = RET;
			(yyval.stmt)->returnStmt = unique_ptr<ReturnStmtAST>((yyvsp[0].returnStmt));

		}
#line 2058 "parser.cpp"
    break;

  case 47:
#line 372 "parser.y"
                    {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = SEL;
			(yyval.stmt)->selectStmt = unique_ptr<SelectStmtAST>((yyvsp[0].selectStmt));
		}
#line 2068 "parser.cpp"
    break;

  case 48:
#line 377 "parser.y"
                       {
			(yyval.stmt) = new StmtAST();
			(yyval.stmt)->sType = ITER;
			(yyval.stmt)->iterationStmt = unique_ptr<IterationStmtAST>((yyvsp[0].iterationStmt));
		}
#line 2078 "parser.cpp"
    break;

  case 49:
#line 385 "parser.y"
                                                         {
				(yyval.selectStmt) = new SelectStmtAST();
				(yyval.selectStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
				(yyval.selectStmt)->ifStmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
			}
#line 2088 "parser.cpp"
    break;

  case 50:
#line 390 "parser.y"
                                                      {
				(yyval.selectStmt) = new SelectStmtAST();
				(yyval.selectStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-4].lOrExp));
				(yyval.selectStmt)->ifStmt = unique_ptr<StmtAST>((yyvsp[-2].stmt));
				(yyval.selectStmt)->elseStmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
			}
#line 2099 "parser.cpp"
    break;

  case 51:
#line 399 "parser.y"
                                      {
					(yyval.iterationStmt) = new IterationStmtAST();
					(yyval.iterationStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
					(yyval.iterationStmt)->stmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
				}
#line 2109 "parser.cpp"
    break;

  case 52:
#line 406 "parser.y"
                                     {
				(yyval.returnStmt) = new ReturnStmtAST();
				(yyval.returnStmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
			}
#line 2118 "parser.cpp"
    break;

  case 53:
#line 410 "parser.y"
                              {
				(yyval.returnStmt) = new ReturnStmtAST();
			}
#line 2126 "parser.cpp"
    break;

  case 54:
#line 415 "parser.y"
               {
			(yyval.addExp) = (yyvsp[0].addExp);
		}
#line 2134 "parser.cpp"
    break;

  case 55:
#line 421 "parser.y"
               {
			(yyval.lOrExp) = (yyvsp[0].lOrExp);
		}
#line 2142 "parser.cpp"
    break;

  case 56:
#line 427 "parser.y"
           {
			(yyval.lVal) = new LValAST();
			(yyval.lVal)->id = unique_ptr<string>((yyvsp[0].token));
		}
#line 2151 "parser.cpp"
    break;

  case 57:
#line 431 "parser.y"
                           {
			(yyval.lVal) = new LValAST();
			(yyval.lVal)->id = unique_ptr<string>((yyvsp[-1].token));
			(yyval.lVal)->arrays.swap((yyvsp[0].arrays)->list);
		}
#line 2161 "parser.cpp"
    break;

  case 58:
#line 439 "parser.y"
                           {
				(yyval.primaryExp) = new PrimaryExpAST();
				(yyval.primaryExp)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
				
			}
#line 2171 "parser.cpp"
    break;

  case 59:
#line 444 "parser.y"
                              {
				(yyval.primaryExp) = new PrimaryExpAST();
				(yyval.primaryExp)->lval = unique_ptr<LValAST>((yyvsp[0].lVal));
				
			}
#line 2181 "parser.cpp"
    break;

  case 60:
#line 449 "parser.y"
                                {
				(yyval.primaryExp) = new PrimaryExpAST();
				(yyval.primaryExp)->number = unique_ptr<NumberAST>((yyvsp[0].number));
				
			}
#line 2191 "parser.cpp"
    break;

  case 61:
#line 457 "parser.y"
             {
			(yyval.number) = new NumberAST();
			(yyval.number)->isInt = true;
			(yyval.number)->intval = (yyvsp[0].int_val);
			
		}
#line 2202 "parser.cpp"
    break;

  case 62:
#line 463 "parser.y"
                       {
			(yyval.number) = new NumberAST();
			(yyval.number)->isInt = false;
			(yyval.number)->floatval = (yyvsp[0].float_val);
			
		}
#line 2213 "parser.cpp"
    break;

  case 63:
#line 472 "parser.y"
                                {
				(yyval.unaryExp) = new UnaryExpAST();
				(yyval.unaryExp)->primaryExp = unique_ptr<PrimaryExpAST>((yyvsp[0].primaryExp));
				
			}
#line 2223 "parser.cpp"
    break;

  case 64:
#line 477 "parser.y"
                              {
				(yyval.unaryExp) = new UnaryExpAST();
				(yyval.unaryExp)->call = unique_ptr<CallAST>((yyvsp[0].call));
				
			}
#line 2233 "parser.cpp"
    break;

  case 65:
#line 482 "parser.y"
                                          {
				(yyval.unaryExp) = new UnaryExpAST();
				(yyval.unaryExp)->op = (yyvsp[-1].op);
				(yyval.unaryExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
			}
#line 2243 "parser.cpp"
    break;

  case 66:
#line 490 "parser.y"
              {
		(yyval.call) = new CallAST();
		(yyval.call)->id = unique_ptr<string>((yyvsp[-2].token));
		
	}
#line 2253 "parser.cpp"
    break;

  case 67:
#line 495 "parser.y"
                                  {
		(yyval.call) = new CallAST();
		(yyval.call)->id = unique_ptr<string>((yyvsp[-3].token));
		(yyval.call)->funcCParamList.swap((yyvsp[-1].funcCParamList)->list);
		
	 }
#line 2264 "parser.cpp"
    break;

  case 68:
#line 504 "parser.y"
             {
            (yyval.op) = UOP_ADD;
		}
#line 2272 "parser.cpp"
    break;

  case 69:
#line 507 "parser.y"
               {
            (yyval.op) = UOP_MINUS;
		}
#line 2280 "parser.cpp"
    break;

  case 70:
#line 510 "parser.y"
             {
            (yyval.op) = UOP_NOT;
		}
#line 2288 "parser.cpp"
    break;

  case 71:
#line 516 "parser.y"
                    {
				(yyval.funcCParamList) = new FuncCParamListAST();
				(yyval.funcCParamList)->list.push_back(unique_ptr<AddExpAST>((yyvsp[0].addExp)));
			}
#line 2297 "parser.cpp"
    break;

  case 72:
#line 520 "parser.y"
                                                  {
				(yyval.funcCParamList) = (FuncCParamListAST*) (yyvsp[-2].funcCParamList);
				(yyval.funcCParamList)->list.push_back(unique_ptr<AddExpAST>((yyvsp[0].addExp)));
			}
#line 2306 "parser.cpp"
    break;

  case 73:
#line 527 "parser.y"
                  {
			(yyval.mulExp) = new MulExpAST();
			(yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
			
		}
#line 2316 "parser.cpp"
    break;

  case 74:
#line 532 "parser.y"
                                     {
			(yyval.mulExp) = new MulExpAST();
			(yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
			(yyval.mulExp)->op = MOP_MUL;
			(yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
			
		}
#line 2328 "parser.cpp"
    break;

  case 75:
#line 539 "parser.y"
                                     {
			(yyval.mulExp) = new MulExpAST();
			(yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
			(yyval.mulExp)->op = MOP_DIV;
			(yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
			
		}
#line 2340 "parser.cpp"
    break;

  case 76:
#line 546 "parser.y"
                                     {
			(yyval.mulExp) = new MulExpAST();
			(yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
			(yyval.mulExp)->op = MOP_MOD;
			(yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
			
		}
#line 2352 "parser.cpp"
    break;

  case 77:
#line 556 "parser.y"
                {
			(yyval.addExp) = new AddExpAST();
			(yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
			
		}
#line 2362 "parser.cpp"
    break;

  case 78:
#line 561 "parser.y"
                                   {
			(yyval.addExp) = new AddExpAST();
			(yyval.addExp)->addExp = unique_ptr<AddExpAST>((yyvsp[-2].addExp));
			(yyval.addExp)->op = AOP_ADD;
			(yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
			
		}
#line 2374 "parser.cpp"
    break;

  case 79:
#line 568 "parser.y"
                                     {
			(yyval.addExp) = new AddExpAST();
			(yyval.addExp)->addExp = unique_ptr<AddExpAST>((yyvsp[-2].addExp));
			(yyval.addExp)->op = AOP_MINUS;
			(yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
			
		}
#line 2386 "parser.cpp"
    break;

  case 80:
#line 578 "parser.y"
                {
			(yyval.relExp) = new RelExpAST();
			(yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
			
		}
#line 2396 "parser.cpp"
    break;

  case 81:
#line 583 "parser.y"
                                  {
			(yyval.relExp) = new RelExpAST();
			(yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
			(yyval.relExp)->op = ROP_GTE;
			(yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
			
		}
#line 2408 "parser.cpp"
    break;

  case 82:
#line 590 "parser.y"
                                  {
			(yyval.relExp) = new RelExpAST();
			(yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
			(yyval.relExp)->op = ROP_LTE;
			(yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
			
		}
#line 2420 "parser.cpp"
    break;

  case 83:
#line 597 "parser.y"
                                  {
			(yyval.relExp) = new RelExpAST();
			(yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
			(yyval.relExp)->op = ROP_GT;
			(yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
			
		}
#line 2432 "parser.cpp"
    break;

  case 84:
#line 604 "parser.y"
                                  {
			(yyval.relExp) = new RelExpAST();
			(yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
			(yyval.relExp)->op = ROP_LT;
			(yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
			
		}
#line 2444 "parser.cpp"
    break;

  case 85:
#line 614 "parser.y"
                {
			(yyval.eqExp) = new EqExpAST();
			(yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
			
		}
#line 2454 "parser.cpp"
    break;

  case 86:
#line 619 "parser.y"
                                {
			(yyval.eqExp) = new EqExpAST();
			(yyval.eqExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[-2].eqExp));
			(yyval.eqExp)->op = EOP_EQ;
			(yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
			
		}
#line 2466 "parser.cpp"
    break;

  case 87:
#line 626 "parser.y"
                                 {
			(yyval.eqExp) = new EqExpAST();
			(yyval.eqExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[-2].eqExp));
			(yyval.eqExp)->op = EOP_NEQ;
			(yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
			
		}
#line 2478 "parser.cpp"
    break;

  case 88:
#line 636 "parser.y"
               {
			(yyval.lAndExp) = new LAndExpAST();
			(yyval.lAndExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[0].eqExp));
			
		}
#line 2488 "parser.cpp"
    break;

  case 89:
#line 641 "parser.y"
                                   {
			(yyval.lAndExp) = new LAndExpAST();
			(yyval.lAndExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[-2].lAndExp));
			(yyval.lAndExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[0].eqExp));
		}
#line 2498 "parser.cpp"
    break;

  case 90:
#line 649 "parser.y"
                 {
			(yyval.lOrExp) = new LOrExpAST();
			(yyval.lOrExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[0].lAndExp));
			
		}
#line 2508 "parser.cpp"
    break;

  case 91:
#line 654 "parser.y"
                                   {
			(yyval.lOrExp) = new LOrExpAST();
			(yyval.lOrExp)->lOrExp = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
			(yyval.lOrExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[0].lAndExp));
			
		}
#line 2519 "parser.cpp"
    break;


#line 2523 "parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 661 "parser.y"


void yyerror(const char* fmt) {
    printf("line:%d\tcolumn:%d\n", yylloc.first_line,yylloc.first_column);
    printf("ERROR: %s\n", fmt);
}

