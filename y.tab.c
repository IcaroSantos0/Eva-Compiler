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
#line 1 "sintatica.y" /* yacc.c:337  */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct{

	string tipo;
	string nome;
	string valor;
} variable;

struct atributos
{
	string tipo;
	string label;
	string traducao;
};

typedef struct{

	string implicita;
	string nomeVar;
	string varConvertida;
} structAux;

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
unordered_map <string, variable> tabSym;
vector <string> tempVector;
stack <int> stackLoops;

int yylex(void);
void yyerror(string);
string genLabel();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);
void addVarToTempVector(string nomeVar);
void printVector();

#line 125 "y.tab.c" /* yacc.c:337  */
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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TK_MAIN = 258,
    TK_ID = 259,
    TK_IF = 260,
    TK_THEN = 261,
    TK_END_LOOP = 262,
    TK_DEC_VAR = 263,
    TK_TIPO_INT = 264,
    TK_TIPO_FLOAT = 265,
    TK_TIPO_BOOL = 266,
    TK_TIPO_CHAR = 267,
    TK_CONV_FLOAT = 268,
    TK_CONV_INT = 269,
    TK_LE = 270,
    TK_HE = 271,
    TK_EQ = 272,
    TK_DIFF = 273,
    TK_CHAR = 274,
    TK_FLOAT = 275,
    TK_BOOL = 276,
    TK_NUM = 277,
    TK_FIM = 278,
    TK_ERROR = 279
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_ID 259
#define TK_IF 260
#define TK_THEN 261
#define TK_END_LOOP 262
#define TK_DEC_VAR 263
#define TK_TIPO_INT 264
#define TK_TIPO_FLOAT 265
#define TK_TIPO_BOOL 266
#define TK_TIPO_CHAR 267
#define TK_CONV_FLOAT 268
#define TK_CONV_INT 269
#define TK_LE 270
#define TK_HE 271
#define TK_EQ 272
#define TK_DIFF 273
#define TK_CHAR 274
#define TK_FLOAT 275
#define TK_BOOL 276
#define TK_NUM 277
#define TK_FIM 278
#define TK_ERROR 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

#define YYUNDEFTOK  2
#define YYMAXUTOK   279

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
       2,     2,     2,    26,     2,     2,     2,     2,    28,     2,
      35,    36,    33,    31,     2,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      29,    25,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    27,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    83,    89,    95,   100,   105,   110,   114,
     117,   125,   134,   142,   150,   173,   194,   208,   214,   220,
     226,   233,   233,   250,   250,   267,   283,   299,   315,   331,
     350,   370,   389,   408,   416,   424,   433,   459,   485,   490,
     498,   506,   514,   522
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_ID", "TK_IF", "TK_THEN",
  "TK_END_LOOP", "TK_DEC_VAR", "TK_TIPO_INT", "TK_TIPO_FLOAT",
  "TK_TIPO_BOOL", "TK_TIPO_CHAR", "TK_CONV_FLOAT", "TK_CONV_INT", "TK_LE",
  "TK_HE", "TK_EQ", "TK_DIFF", "TK_CHAR", "TK_FLOAT", "TK_BOOL", "TK_NUM",
  "TK_FIM", "TK_ERROR", "'='", "'!'", "'|'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "$accept", "S",
  "BLOCO", "COMANDOS", "COMANDO", "ATRIBUICAO", "DECLARACAO", "IF", "$@1",
  "$@2", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    33,   124,    38,    60,
      62,    43,    45,    42,    47,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -26

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     6,    17,    -4,   -26,     0,   -19,    42,   -26,     9,
       2,    34,   -26,   -26,   -26,   -26,    61,    61,     1,    42,
       3,     4,   -26,    91,    53,     5,    61,    -6,   -26,   155,
     111,   -26,   -26,   -26,   -26,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,   -26,    61,    61,
     155,    61,    83,    16,    19,    20,    23,   -26,   -20,   -20,
     188,   188,   162,   182,   -20,   -20,   -18,   -18,   -26,   -26,
     155,   155,   133,    42,    61,    61,    61,    30,   -19,    44,
     155,   155,   155,   -26,   -26,    13,   -26
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,    43,
      23,     0,    41,    40,    42,    39,     0,     0,     0,     5,
       0,     0,     9,     0,     0,     0,     0,     0,    43,    35,
       0,     3,     4,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
      14,     0,     0,    18,    19,    20,    17,    38,    31,    32,
      36,    37,    33,    34,    29,    30,    25,    26,    27,    28,
      15,    16,     0,     5,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    10,    22,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -25,   -17,   -26,   -26,   -26,   -26,   -26,   -26,
     -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    18,    19,    20,    21,    22,    25,    26,
      23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    30,    32,    53,    54,    55,    56,     1,    50,     3,
      52,    43,    44,    45,    46,    45,    46,     4,     7,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     5,    70,    71,    24,    72,     6,   -21,    27,    31,
      51,    74,    33,    34,    75,    76,     9,    10,    77,    83,
      11,    85,    86,    84,     0,     0,    79,    28,    80,    81,
      82,    12,    13,    14,    15,    28,    48,    49,    16,     0,
       0,     0,    12,    13,    14,    15,     0,    17,     0,    16,
      12,    13,    14,    15,     0,     0,     0,    16,    17,    73,
       0,     0,     0,     0,     0,     0,    17,     0,    35,    36,
      37,    38,     0,     0,     0,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    39,    40,
      41,    42,    43,    44,    45,    46,    35,    36,    37,    38,
      47,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    57,    35,    36,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    78,
      35,    36,    37,    38,     0,     0,     0,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      40,    41,    42,    43,    44,    45,    46,    35,    36,    37,
      38,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,    41,    42,    43,
      44,    45,    46
};

static const yytype_int8 yycheck[] =
{
      16,    17,    19,     9,    10,    11,    12,     9,    24,     3,
      26,    31,    32,    33,    34,    33,    34,     0,    37,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    35,    48,    49,    25,    51,    36,    35,     4,    38,
      35,    25,    39,    39,    25,    25,     4,     5,    25,    19,
       8,     7,    39,    78,    -1,    -1,    73,     4,    74,    75,
      76,    19,    20,    21,    22,     4,    13,    14,    26,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    35,    -1,    26,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    35,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      27,    28,    29,    30,    31,    32,    33,    34,    27,    28,
      29,    30,    31,    32,    33,    34,    15,    16,    17,    18,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      15,    16,    17,    18,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      28,    29,    30,    31,    32,    33,    34,    15,    16,    17,
      18,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    29,    30,    31,
      32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    41,     3,     0,    35,    36,    37,    42,     4,
       5,     8,    19,    20,    21,    22,    26,    35,    43,    44,
      45,    46,    47,    50,    25,    48,    49,     4,     4,    50,
      50,    38,    43,    39,    39,    15,    16,    17,    18,    27,
      28,    29,    30,    31,    32,    33,    34,    39,    13,    14,
      50,    35,    50,     9,    10,    11,    12,    36,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,     6,    25,    25,    25,    25,    36,    43,
      50,    50,    50,    19,    42,     7,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    46,
      46,    48,    47,    49,    47,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     2,     2,     1,
       5,     5,     5,     5,     3,     4,     4,     3,     3,     3,
       3,     0,     6,     0,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 76 "sintatica.y" /* yacc.c:1652  */
    {
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << yyvsp[0].traducao << "\treturn 0;\n}" << endl;
			}
#line 1387 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 84 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1395 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 90 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1403 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 95 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.traducao = "";
			}
#line 1411 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 101 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1419 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 106 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1427 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 111 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1435 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 118 "sintatica.y" /* yacc.c:1652  */
    {
				erroTipo("char", yyvsp[0].tipo);
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "char");
				yyval.traducao = "\t" + nomeAuxID + " = " + yyvsp[0].traducao + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}
#line 1446 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 126 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.tipo = "int";
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "int");
				cout << "SOU DO TIPO " << yyvsp[0].tipo << endl;
				yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + nomeAuxID +  ";\n");
			}
#line 1458 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 135 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.tipo = "float";
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "float");
				yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
			}
#line 1469 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 143 "sintatica.y" /* yacc.c:1652  */
    {
				//erroTipo("bool", $5.tipo);
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "bool");
				yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
#line 1480 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 151 "sintatica.y" /* yacc.c:1652  */
    {

				if((yyvsp[0].tipo != tabSym[yyvsp[-2].label].tipo)){

					if((yyvsp[0].tipo == "char" && tabSym[yyvsp[-2].label].tipo != "char") || (yyvsp[0].tipo == "bool" && tabSym[yyvsp[-2].label].tipo != "bool")){
						string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + tabSym[yyvsp[-2].label].tipo  + " é inválida!\n";
						yyerror(msgError);
					}

					else{
						yyval.tipo = tabSym[yyvsp[-2].label].tipo;
						yyval.traducao = yyvsp[0].traducao + "\t" + tabSym[yyvsp[-2].label].nome + " = " + "("+ tabSym[yyvsp[-2].label].tipo + ") " + yyvsp[0].label + ";\n";

					}
				}

				else{
					yyval.tipo = yyvsp[0].tipo;
					yyval.traducao = yyvsp[0].traducao + "\t" + tabSym[yyvsp[-2].label].nome + " = " + yyvsp[0].label + ";\n";
				}
			}
#line 1506 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 174 "sintatica.y" /* yacc.c:1652  */
    {

				if((yyvsp[0].tipo == "char" && tabSym[yyvsp[-3].label].tipo != "char") || (yyvsp[0].tipo == "bool" && tabSym[yyvsp[-3].label].tipo != "bool")){
					string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + tabSym[yyvsp[-3].label].tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					if((tabSym[yyvsp[-3].label].tipo == "int") && yyvsp[0].tipo == "float"){

						cout << "Conversão para float em "<< tabSym[yyvsp[-3].label].nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
							yyval.traducao = yyvsp[0].traducao + "\t" + tabSym[yyvsp[-3].label].nome + " = " + yyvsp[0].label + ";\n";
					}
					else{
							yyval.traducao = yyvsp[0].traducao + "\t" + tabSym[yyvsp[-3].label].nome + " = (float) " + yyvsp[0].label + ";\n";
					}
				}
			}
#line 1530 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 195 "sintatica.y" /* yacc.c:1652  */
    {
				if((yyvsp[0].tipo == "char" && tabSym[yyvsp[-3].label].tipo != "char") || (yyvsp[0].tipo == "bool" && tabSym[yyvsp[-3].label].tipo != "bool")){
					string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + tabSym[yyvsp[-3].label].tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					yyval.traducao = yyvsp[0].traducao + "\t" + tabSym[yyvsp[-3].label].nome + " = (int) " + yyvsp[0].label + ";\n";
				}
			}
#line 1546 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 209 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "none", "char");
				addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
			}
#line 1555 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 215 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "0", "int");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
#line 1564 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 221 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "0.0", "float");
				addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
			}
#line 1573 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 227 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "TRUE", "bool");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
#line 1582 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 233 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1588 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 234 "sintatica.y" /* yacc.c:1652  */
    {
					 		if(yyvsp[-2].tipo != "bool"){
								yyerror("Condicional sem declaração do tipo booleano!\n");
							}

							else{
								string auxVar = "temp" + to_string(valorVar++);
								addVarToTempVector("\tint " + auxVar + ";\n");
								string auxVar2 = "!" + yyvsp[-2].label;
								yyval.traducao = "\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-2].traducao + "\n\t" + auxVar + " = " +
								auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[0].traducao + "\tfinal" +
								to_string(stackLoops.top()) + ":\n";
								stackLoops.pop();
							}
						}
#line 1608 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 250 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1614 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 251 "sintatica.y" /* yacc.c:1652  */
    {
							if(yyvsp[-4].tipo != "bool"){
								yyerror("Condicional sem declaração do tipo booleano!\n");
							}

							else{
								string auxVar = "temp" + to_string(valorVar++);
								addVarToTempVector("\tint " + auxVar + ";\n");
								string auxVar2 = "!" + yyvsp[-4].label;
								yyval.traducao = "\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-4].traducao + "\n\t" + auxVar + " = " +
								auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[-2].traducao + "\tfinal" +
								to_string(stackLoops.top()) + ":\n";
								stackLoops.pop();
							}
						}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 268 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){ //se primeira variável for int, muda pra float e entra nesse if
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " + " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){ //se segunda variável for int, muda pra float e entra nesse else
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label  + ";\n");
			}
#line 1653 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 284 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " - " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1672 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 300 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " * " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1691 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 316 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " / " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1710 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 332 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " < " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1732 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 351 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);

				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " > " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 371 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " <= " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1777 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 390 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " >= " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 1799 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 409 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 1810 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 417 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 425 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
				yyval.tipo = isBoolean("bool", yyvsp[0].tipo);
				yyval.label = genLabel();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = !" + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 434 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";

				if((yyvsp[-2].tipo == "bool" && yyvsp[0].tipo == "bool") || (yyvsp[-2].tipo == "char" && yyvsp[0].tipo == "char")){

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
				}

				else{
					structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
					if(aux.varConvertida == yyvsp[-2].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " == " + yyvsp[0].label + ";\n";
					}
					else if(aux.varConvertida == yyvsp[0].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
					}
					addVarToTempVector("\tint " + yyval.label + ";\n");

				}
			}
#line 1862 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 460 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";

				if((yyvsp[-2].tipo == "bool" && yyvsp[0].tipo == "bool") || (yyvsp[-2].tipo == "char" && yyvsp[0].tipo == "char")){

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
				}

				else{

					structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
					if(aux.varConvertida == yyvsp[-2].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " != " + yyvsp[0].label + ";\n";
					}
					else if(aux.varConvertida == yyvsp[0].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
					}
					addVarToTempVector("\tint " + yyval.label + ";\n");
				}
			}
#line 1891 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 486 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1899 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 491 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioInt" + to_string(valorTemp++);
				yyval.tipo = "int";
				addVarToTempVector("\tint "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 1910 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 499 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				yyval.tipo = "float";
				addVarToTempVector("\tfloat " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
		 	}
#line 1921 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 507 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioChar" + to_string(valorTemp++);
				yyval.tipo = "char";
				addVarToTempVector("\tchar "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 1932 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 515 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioBool" + to_string(valorTemp++);
				yyval.tipo = "bool";
				addVarToTempVector("\tint " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 1943 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 523 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = tabSym[yyvsp[0].label].nome;
				yyval.tipo = tabSym[yyvsp[0].label].tipo;
				yyval.traducao = tabSym[yyvsp[0].label].valor;
			}
#line 1953 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1957 "y.tab.c" /* yacc.c:1652  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 529 "sintatica.y" /* yacc.c:1918  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	//yydebug = 1;
	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string genLabel(){

	return "temp" + to_string(valorVar++);
}

string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar){

	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var;
		nomeGerado = genLabel();

		Var = {
					.tipo = tipoVar,
			   		.nome = nomeGerado,
					.valor = conteudoVar
			  };

		tabSym[nomeDado] = Var;
		return tabSym[nomeDado].nome;
	}

	else {

		if(tipoVar != tabSym[nomeDado].tipo){

			cout << "Variável " << nomeDado << " de tipo " << tabSym[nomeDado].tipo << " e variável de mesmo nome de tipo " << tipoVar << " tentando ser criada!\n" << endl;
			yyerror("Variáveis de mesmo nome com tipos diferentes!\n");
		}

		return tabSym[nomeDado].nome;
	}

	return "";
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){

		string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome1 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome1
						};

		return aux;
	}

	else if(tipo0 == "int" && tipo1 == "float")
  {

  	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome0 + ";\n";

		structAux aux = {

											.implicita = stringRetorno,
											.nomeVar = nomeAuxID,
											.varConvertida = nome0
										};

		return aux;

  }

  else if(tipo0 == "float" && tipo1 == "float")
  {

    	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);

    }

  else if(tipo0 == "int" && tipo1 == "int")
  {

    	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
    	//return "int";
    }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }

    //return "";
}

string explicitConversion(string tipo0, string tipo1){

	if (tipo0 == "char" || tipo0 == "bool")
	{
		yyerror("não é possivel converter em char ou booleano!\n");
	}

	else
	{
		string nomeAuxID = "nomeTemporario" + tipo1 + to_string(valorTemp);
    	addVarToTempVector("\t" + tipo1 + " " + nomeAuxID + ";\n");
    	return tipo1;
	}

	return "";
}

void addVarToTempVector(string nomeVar)
{
	tempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}

	cout << "\n\n" << endl;
}

string isBoolean(string tipo0, string tipo1)
{
	if (tipo1 != "bool" || tipo0 != "bool")
	{
		yyerror("Operacao logica sem tipo booleano!\n");
	}

	else{

		return "bool";
	}

	return "";
}

int erroTipo(string tipo0, string tipo1)
{
	if (tipo1 != tipo0)
	{
		yyerror("tipo de variaveis incompativeis\n");

	}
			return 0;
}
