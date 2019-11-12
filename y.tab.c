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
#include <list>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct Variable{

	string tipo;
	string nome;
	string valor;
//std::list<char> caracteres;
} variable;


typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita;
	string nomeVar;
	string varConvertida;
} structAux;

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
int mapAtual = 0;
//unordered_map <string, variable> tabSym;
vector <string> tempVector;
stack <int> stackLoops;
vector <unordered_map<string, variable>> contextoVariaveis;

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
void addMapToStack();
variable searchForVariable(string nome);
void checkForVariable(string nome);
//string concatenacao();

#line 134 "y.tab.c" /* yacc.c:337  */
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
    TK_ELSE = 261,
    TK_THEN = 262,
    TK_END_LOOP = 263,
    TK_WHILE = 264,
    TK_DO = 265,
    TK_FOR = 266,
    TK_ENTRADA = 267,
    TK_SAIDA = 268,
    TK_DEC_VAR = 269,
    TK_TIPO_INT = 270,
    TK_TIPO_FLOAT = 271,
    TK_TIPO_BOOL = 272,
    TK_TIPO_CHAR = 273,
    TK_TIPO_STRING = 274,
    TK_UN_POS = 275,
    TK_CONV_FLOAT = 276,
    TK_CONV_INT = 277,
    TK_LE = 278,
    TK_HE = 279,
    TK_EQ = 280,
    TK_DIFF = 281,
    TK_CHAR = 282,
    TK_FLOAT = 283,
    TK_BOOL = 284,
    TK_NUM = 285,
    TK_STRING = 286,
    TK_FIM = 287,
    TK_ERROR = 288
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_ID 259
#define TK_IF 260
#define TK_ELSE 261
#define TK_THEN 262
#define TK_END_LOOP 263
#define TK_WHILE 264
#define TK_DO 265
#define TK_FOR 266
#define TK_ENTRADA 267
#define TK_SAIDA 268
#define TK_DEC_VAR 269
#define TK_TIPO_INT 270
#define TK_TIPO_FLOAT 271
#define TK_TIPO_BOOL 272
#define TK_TIPO_CHAR 273
#define TK_TIPO_STRING 274
#define TK_UN_POS 275
#define TK_CONV_FLOAT 276
#define TK_CONV_INT 277
#define TK_LE 278
#define TK_HE 279
#define TK_EQ 280
#define TK_DIFF 281
#define TK_CHAR 282
#define TK_FLOAT 283
#define TK_BOOL 284
#define TK_NUM 285
#define TK_STRING 286
#define TK_FIM 287
#define TK_ERROR 288

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
       2,     2,     2,    35,     2,     2,     2,     2,    37,     2,
      44,    45,    42,    40,     2,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
      38,    34,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    36,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    92,    99,   104,   110,   115,   120,   125,
     130,   135,   140,   145,   150,   155,   160,   166,   175,   182,
     190,   198,   221,   241,   254,   280,   304,   320,   326,   332,
     338,   344,   351,   351,   371,   371,   383,   383,   403,   403,
     422,   422,   446,   472,   488,   504,   520,   530,   558,   578,
     597,   616,   624,   632,   641,   667,   693,   698,   706,   714,
     722,   730,   738
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_ID", "TK_IF", "TK_ELSE",
  "TK_THEN", "TK_END_LOOP", "TK_WHILE", "TK_DO", "TK_FOR", "TK_ENTRADA",
  "TK_SAIDA", "TK_DEC_VAR", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL",
  "TK_TIPO_CHAR", "TK_TIPO_STRING", "TK_UN_POS", "TK_CONV_FLOAT",
  "TK_CONV_INT", "TK_LE", "TK_HE", "TK_EQ", "TK_DIFF", "TK_CHAR",
  "TK_FLOAT", "TK_BOOL", "TK_NUM", "TK_STRING", "TK_FIM", "TK_ERROR",
  "'='", "'!'", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "'{'", "'}'", "';'", "$accept", "S", "BLOCO",
  "BLOCOCONTEXTO", "COMANDOS", "COMANDO", "ENTRADA", "SAIDA", "ATRIBUICAO",
  "DECLARACAO", "IF", "$@1", "ELSE", "$@2", "WHILE", "$@3", "DOWHILE",
  "$@4", "FOR", "$@5", "E", YY_NULLPTR
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
     285,   286,   287,   288,    61,    33,   124,    38,    60,    62,
      43,    45,    42,    47,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -70

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -70,     8,    -4,   -70,    22,     6,     7,     5,    88,   -70,
     -10,    19,    52,   -70,   -70,   -70,   -70,   -70,   120,   120,
       4,    16,    41,    17,    18,    25,    26,   -20,   -70,    99,
      60,    43,    47,   265,   196,   -70,   -70,   -70,   -70,    69,
     -70,   -70,    34,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   -70,   -70,   120,   120,   265,   -70,    50,    55,
      56,    59,    62,   -70,   120,    42,     5,    90,    91,   -70,
     -11,   -11,   186,   186,   272,   293,   -11,   -11,   -16,   -16,
     -70,   -70,   265,   265,   120,   120,   120,   120,   120,   145,
     120,    89,    58,    93,   265,   265,   265,   265,   265,   132,
     219,    64,   120,   132,    96,     5,   120,   154,   101,    65,
     -70,   242,   120,    66,   -70,   -70,   175,   -70,    76,    88,
      63,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     4,     2,
      62,     0,     0,    59,    58,    60,    57,    61,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    62,    53,     0,    32,    36,    38,    40,    12,
      13,    14,     0,    16,     3,     5,    10,    11,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    17,     0,     0,    24,    18,    29,    30,
      31,    27,    28,    56,     0,     0,     0,     0,     0,    15,
      49,    50,    54,    55,    51,    52,    47,    48,    42,    43,
      44,    45,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    22,    23,    19,    20,     4,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    33,    39,     0,    35,     0,     4,
       0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -69,   112,   -22,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    20,    21,    22,    23,    24,    25,    26,
      39,    74,    40,    78,    41,    75,    42,    76,    43,    77,
      27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    33,    34,    50,    51,    52,    53,   101,     3,    35,
      28,     4,    66,    36,    37,    38,    54,    55,    56,    57,
      58,    59,    60,    61,    29,     5,    60,    61,    62,    58,
      59,    60,    61,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    10,   120,    92,    93,    -6,
       6,     8,     7,    30,    11,    12,    31,    99,    68,    69,
      70,    71,    72,    44,    67,    46,    47,    28,    13,    14,
      15,    16,    17,    48,    49,   -34,    18,   104,   105,   106,
     107,   108,    79,   110,    94,    19,   100,   114,    -6,    95,
      96,   118,    10,    97,   102,   117,    98,   103,   111,   121,
     113,    11,    12,    32,   119,   126,   112,   130,   116,   123,
     131,    63,     2,   124,   127,    13,    14,    15,    16,    17,
      64,    65,   129,    18,    32,     0,    13,    14,    15,    16,
      17,     0,    19,     0,    18,    -6,    10,     0,     0,     0,
      -6,     0,     0,    19,     0,    11,    12,    13,    14,    15,
      16,    17,   109,     0,     0,    18,     0,     0,     0,    13,
      14,    15,    16,    17,    19,     0,     0,    18,    50,    51,
      52,    53,     0,     0,     0,     0,    19,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    50,    51,
      52,    53,   122,     0,     0,     0,     0,     0,     0,    50,
      51,    54,    55,    56,    57,    58,    59,    60,    61,    50,
      51,    52,    53,   128,    56,    57,    58,    59,    60,    61,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    73,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,     0,   115,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,   125,    50,    51,
      52,    53,     0,     0,     0,    50,    51,    52,    53,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    55,
      56,    57,    58,    59,    60,    61,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61
};

static const yytype_int16 yycheck[] =
{
      22,    18,    19,    23,    24,    25,    26,    76,     0,     5,
      20,    15,    29,     9,    10,    11,    36,    37,    38,    39,
      40,    41,    42,    43,    34,     3,    42,    43,    48,    40,
      41,    42,    43,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     4,   115,    64,    65,     8,
      44,    46,    45,    34,    13,    14,     4,    74,    15,    16,
      17,    18,    19,    47,     4,    48,    48,    20,    27,    28,
      29,    30,    31,    48,    48,     6,    35,    94,    95,    96,
      97,    98,    48,   100,    34,    44,    44,   109,    47,    34,
      34,   113,     4,    34,     4,   112,    34,     6,     9,   116,
       7,    13,    14,     4,     8,   122,    48,   129,    44,     8,
      47,    12,     0,    48,    48,    27,    28,    29,    30,    31,
      21,    22,    46,    35,     4,    -1,    27,    28,    29,    30,
      31,    -1,    44,    -1,    35,    47,     4,    -1,    -1,    -1,
       8,    -1,    -1,    44,    -1,    13,    14,    27,    28,    29,
      30,    31,     7,    -1,    -1,    35,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    44,    -1,    -1,    35,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    44,    23,    24,    25,
      26,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    23,    24,
      25,    26,    48,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    36,    37,    38,    39,    40,    41,    42,    43,    23,
      24,    25,    26,    48,    38,    39,    40,    41,    42,    43,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    23,    24,
      25,    26,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    37,
      38,    39,    40,    41,    42,    43,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,     0,    15,     3,    44,    45,    46,    51,
       4,    13,    14,    27,    28,    29,    30,    31,    35,    44,
      52,    53,    54,    55,    56,    57,    58,    69,    20,    34,
      34,     4,     4,    69,    69,     5,     9,    10,    11,    59,
      61,    63,    65,    67,    47,    53,    48,    48,    48,    48,
      23,    24,    25,    26,    36,    37,    38,    39,    40,    41,
      42,    43,    48,    12,    21,    22,    69,     4,    15,    16,
      17,    18,    19,    45,    60,    64,    66,    68,    62,    48,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    34,    34,    34,    34,    34,    69,
      44,    51,     4,     6,    69,    69,    69,    69,    69,     7,
      69,     9,    48,     7,    53,    45,    44,    69,    53,     8,
      51,    69,    48,     8,    48,    45,    69,    48,    48,    46,
      53,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    60,    59,    62,    61,    64,    63,    66,    65,
      68,    67,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     0,     2,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     2,     3,     3,     5,
       5,     5,     5,     5,     3,     4,     4,     3,     3,     3,
       3,     3,     0,     7,     0,     7,     0,     6,     0,     7,
       0,    11,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1
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
#line 85 "sintatica.y" /* yacc.c:1652  */
    {
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << yyvsp[0].traducao << "\treturn 0;\n}" << endl;
			}
#line 1464 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 93 "sintatica.y" /* yacc.c:1652  */
    {
					yyval.traducao = yyvsp[-1].traducao;
				}
#line 1472 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 99 "sintatica.y" /* yacc.c:1652  */
    {
								addMapToStack();
								yyval.traducao = "";
							}
#line 1481 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 105 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
					}
#line 1489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 110 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
					}
#line 1497 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 116 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1505 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 121 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1513 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 126 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1521 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 131 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1529 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 136 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1537 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 141 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
			}
#line 1545 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 146 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
			}
#line 1553 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 151 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
			}
#line 1561 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 156 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 1569 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 161 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
			}
#line 1577 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 167 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = yyvsp[-2].tipo;
				variable Var = searchForVariable(yyvsp[-2].label);
				cout << "$3.label = " << yyvsp[0].label << endl;
				yyval.traducao = "\tstd::cin" + yyval.traducao + yyvsp[-2].traducao + ";\n";
			}
#line 1589 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 176 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				variable Var = searchForVariable(yyvsp[0].label);
				yyval.traducao = "\tstd::cout " + yyvsp[0].traducao + ";\n";
			}
#line 1599 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 183 "sintatica.y" /* yacc.c:1652  */
    {
				erroTipo("char", yyvsp[0].tipo);
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "char");
				yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}
#line 1610 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 191 "sintatica.y" /* yacc.c:1652  */
    {
				erroTipo("string", yyvsp[0].tipo);
				string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "string");
				yyval.traducao =  yyvsp[0].traducao +  "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tstring " + nomeAuxID + ";\n");
			}
#line 1621 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 199 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.tipo = "int";
				if(yyval.tipo != yyvsp[0].tipo){

					if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
						yyerror("Declaração de char/string em int não permitido!");
					}

					else{
						string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "int");
						yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (int) " + yyvsp[0].label  + ";\n";
						addVarToTempVector("\tint " + nomeAuxID +  ";\n");
					}
				}

				else{
					string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "int");
					yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}
#line 1647 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 222 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.tipo = "float";
				if(yyval.tipo != yyvsp[0].tipo){
					if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
						yyerror("Declaração de char/string em float não permitido!");
					}
					else{
						string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "float");
						yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (float) " + yyvsp[0].label  + ";\n";
						addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
					}
				}
				else{
					string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "float");
					yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}
#line 1670 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 242 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.tipo = "bool";
				if(yyval.tipo != yyvsp[0].tipo){
					yyerror("Tipo booleano somente aceita boleano!");
				}
				else{
					string nomeAuxID = addVarToTabSym(yyvsp[-3].label, yyvsp[0].traducao, "int");
					yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + yyvsp[0].label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}
#line 1686 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 255 "sintatica.y" /* yacc.c:1652  */
    {
				variable Var = searchForVariable(yyvsp[-2].label);
				cout << "\n\nNome expressão: " << yyvsp[0].label << "\nTipo expressão: " << yyvsp[0].tipo << endl;

				if((yyvsp[0].tipo != Var.tipo)){

					if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
						string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
						yyerror(msgError);
					}

					else{

						yyval.tipo = Var.tipo;
						yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + yyvsp[0].label + ";\n";
					}
				}

				else{

					yyval.tipo = yyvsp[0].tipo;
					yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = " + yyvsp[0].label + ";\n";
				}
			}
#line 1715 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 281 "sintatica.y" /* yacc.c:1652  */
    {
				variable Var = searchForVariable(yyvsp[-3].label);
				//unordered_map<string, variable> tabSym = contextoVariaveis.back();
				if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool")){
					string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					if((Var.tipo == "int") && yyvsp[0].tipo == "float"){

						cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
						yyval.tipo = "int";
						yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = " + yyvsp[0].label + ";\n";
					}
					else{
							yyval.tipo = "float";
							yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = (float) " + yyvsp[0].label + ";\n";
					}
				}
			}
#line 1742 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 305 "sintatica.y" /* yacc.c:1652  */
    {
				variable Var = searchForVariable(yyvsp[-3].label);
				//unordered_map<string, variable> tabSym = contextoVariaveis.back();
				if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool")){
					string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = (int) " + yyvsp[0].label + ";\n";
				}
			}
#line 1760 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 321 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "none", "char");
				addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
			}
#line 1769 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 327 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "none", "string");
				addVarToTempVector("\tstring " + nomeAuxID +  ";\n");
			}
#line 1778 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 333 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "0", "int");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
#line 1787 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 339 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "0.0", "float");
				addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
			}
#line 1796 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 345 "sintatica.y" /* yacc.c:1652  */
    {
				string nomeAuxID = addVarToTabSym(yyvsp[-1].label, "TRUE", "bool");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
#line 1805 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 351 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1811 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 352 "sintatica.y" /* yacc.c:1652  */
    {
						if(yyvsp[-4].tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + yyvsp[-4].label;
							yyval.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-4].traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[-2].traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 371 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1839 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 372 "sintatica.y" /* yacc.c:1652  */
    {
					int posiAlteracao = yyvsp[-6].traducao.rfind("final");
					string auxRetorno = yyvsp[-6].traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					yyval.traducao = auxRetorno + yyvsp[-2].traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 1853 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 383 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1859 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 384 "sintatica.y" /* yacc.c:1652  */
    {
						if(yyvsp[-2].tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + yyvsp[-2].label;
							yyval.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-2].traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[0].traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 1881 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 403 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1887 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 404 "sintatica.y" /* yacc.c:1652  */
    {
				if(yyvsp[-1].tipo != "bool"){
					yyerror("Condicional sem declaração do tipo booleano!\n");
				}

				else{
					string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");
					string auxVar2 = "!" + yyvsp[-1].label;
					yyval.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-4].traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + yyvsp[-1].traducao +
					"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
					";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
			}
#line 1909 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 422 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 1915 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 423 "sintatica.y" /* yacc.c:1652  */
    {

				  	if(yyvsp[-6].tipo != "bool"){
				  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + yyvsp[-6].tipo + " inválida!\n";
				  		yyerror(msgError);
				  	}

			  	string nomeVar = addVarToTabSym(yyvsp[-7].label, yyvsp[-4].traducao, "int");

			  	string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");

					string auxVar2 = genLabel();
					string auxVar3 = "!" + auxVar2;

					yyval.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-6].traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\t" + nomeVar + " = " + nomeVar + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				  }
#line 1942 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 447 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();

				if(yyval.tipo != "string" && yyvsp[-2].tipo != "string" && yyvsp[0].tipo != "string")
				{
					cout << yyval.tipo << endl;
					structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
					if(aux.varConvertida == yyvsp[-2].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " + " + yyvsp[0].label + ";\n";
					}
					else if(aux.varConvertida == yyvsp[0].label){
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
				}				}

				else
				{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
					cout << "aqui" << endl;
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label  + ";\n");
			}
#line 1971 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 473 "sintatica.y" /* yacc.c:1652  */
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
#line 1990 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 489 "sintatica.y" /* yacc.c:1652  */
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
#line 2009 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 505 "sintatica.y" /* yacc.c:1652  */
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
#line 2028 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 521 "sintatica.y" /* yacc.c:1652  */
    {

				variable Var = searchForVariable(yyvsp[-1].label);
				yyval.tipo = Var.tipo;

				yyval.traducao = "\t" + yyvsp[-1].label + " = " + yyvsp[-1].label + " + 1;\n";

			}
#line 2041 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 531 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $1.tipo << endl;

				if((yyvsp[-2].tipo).empty()){ //se a variavel 1 for TK_ID (n vem com tipo)
						cout << "pantomima " << yyvsp[-2].label << endl;
						variable auxVar1 = searchForVariable(yyvsp[-2].label);
						yyvsp[-2].tipo = auxVar1.tipo;
						cout << "brita " << yyvsp[-2].tipo << endl;
				}

				if((yyvsp[0].tipo).empty()){ //se a variavel 3 for TK_ID (n vem com tipo)

						cout << "tireoide " << endl;
						variable auxVar2 = searchForVariable(yyvsp[0].label);
						yyvsp[0].tipo = auxVar2.tipo;
				}

				if(yyvsp[-2].tipo == yyvsp[0].tipo){ //se elas são do mesmo tipo, não é necessário conversão

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\n\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2072 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 559 "sintatica.y" /* yacc.c:1652  */
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

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2095 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 579 "sintatica.y" /* yacc.c:1652  */
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

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2117 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 598 "sintatica.y" /* yacc.c:1652  */
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

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2139 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 617 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2150 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 625 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2161 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 633 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
				yyval.tipo = isBoolean("bool", yyvsp[0].tipo);
				yyval.label = genLabel();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = !" + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 2173 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 642 "sintatica.y" /* yacc.c:1652  */
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
#line 2202 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 668 "sintatica.y" /* yacc.c:1652  */
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
#line 2231 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 694 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 2239 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 699 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioInt" + to_string(valorTemp++);
				yyval.tipo = "int";
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 2250 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 707 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				yyval.tipo = "float";
				addVarToTempVector("\tfloat " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
		 	}
#line 2261 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 715 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioChar" + to_string(valorTemp++);
				yyval.tipo = "char";
				addVarToTempVector("\tchar "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 2272 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 723 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioBool" + to_string(valorTemp++);
				yyval.tipo = "bool";
				addVarToTempVector("\tint " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 2283 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 731 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioString" + to_string(valorTemp++);
				yyval.tipo = "string";
				addVarToTempVector("\tstring "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 2294 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 739 "sintatica.y" /* yacc.c:1652  */
    {
				cout << "trombeta " << yyvsp[0].label << endl;
				variable auxVar = searchForVariable(yyvsp[0].label);
				yyval.label = auxVar.nome;
				cout << "carambolas filho " << yyval.label << endl;
				yyval.tipo = auxVar.tipo;
				yyval.traducao;
			}
#line 2307 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2311 "y.tab.c" /* yacc.c:1652  */
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
#line 748 "sintatica.y" /* yacc.c:1918  */


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

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var2;
		nomeGerado = genLabel();

		Var2 =	{
					.tipo = tipoVar,
				   	.nome = nomeGerado,
					.valor = conteudoVar
		  		};

		tabSym[nomeDado] = Var2;
		contextoVariaveis.pop_back();
		contextoVariaveis.push_back(tabSym);
		cout << "tabSym depois " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << tabSym[nomeDado].nome << " de tipo "<< tabSym[nomeDado].tipo <<" na tabela de simbolos " << mapAtual << "!\n" << endl;
		return tabSym[nomeDado].nome;
	}

	/*else {

		return tabSym[nomeDado].nome;
	}*/

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

void addMapToStack(void){

	unordered_map<string, variable> auxMap;
	contextoVariaveis.push_back(auxMap);
	mapAtual++;
	cout << "adicionei o map de numero " << mapAtual << " na tabela de mapas!\n" << endl;
}

variable searchForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo << "\n" << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
	//se não encontrei, a variável não existe e está tentando ser acessada. Erro!
	yyerror("Variável não declarada tentando ser usada!\n");
}

void checkForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap check iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			string errorMessage = "\n\nEncontrada variável!\nNome: " + nome + "\nTipo: " + auxMap[nome].tipo + "\n";
			yyerror(errorMessage);
		}
	}
	//se não encontrei, a variável não existe e poderá ser adicionada.
}
