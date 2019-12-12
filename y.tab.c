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
} variable;

typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita; //tradução após conversão
	string nomeVar; //nome da variável
	string varConvertida; //nome da variável que foi convertida
} structAux; //struct auxiliar utilizada para conversões

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
int valorAuxiliar = 0;
int mapAtual = 0; //indica qual contexto está
int tamanho_vetor = 0; //indica o tamanho do vetor atual
int tamanho_linhas = 0;
int tamanho_colunas = 0;
int elementos_matriz;

stack <string> label_vet; //stack para armazenar o nome dos elementos sendo adicionados no vetor
stack <string> tipo_vet; //stack para armazenar o tipo do elemento armazenado no vetor
stack <string> trad_vet; //stack para armazenar a traducao do elemento armazenado no vetor

unordered_map <string, variable> globalTabSym; //tabela de símbolos global
vector <string> tempVector; //vetor de impressão de variáveis em cód. interm.
vector <string> globalTempVector; //vetor de impressão global
stack <int> stackLoops; //pilha de variáveis de controle de loop
stack <string> stackCommands; //pilha que auxilia qual o tipo de loop existem
stack <string> stackVectors;

unordered_map <string, int> map_vetor;
unordered_map <string, int> map_linhas;
unordered_map <string, int> map_colunas;
unordered_map <string, int> pointer_vector;

unordered_map <string, variable> arrayPointerNames;

vector <unordered_map<string, variable>> contextoVariaveis; //pilha de contextos

//funções yacc
int yylex(void);
void yyerror(string);

//função geradora de label
string genLabel();

//funções de conversão
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);

//funções para checar tipos específicos
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);

//funções para acessar o vetor de variáveis
void addVarToTempVector(string nomeVar);
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void freeVectors();
void printGlobalVector();

//funções de array e matrix
string addElementsToArray(int tamanhoArray, string nomeArray);

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
variable searchForGlobalVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();

#line 173 "y.tab.c" /* yacc.c:337  */
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
    TK_IF = 259,
    TK_ELSE = 260,
    TK_TERN = 261,
    TK_THEN = 262,
    TK_END_LOOP = 263,
    TK_WHILE = 264,
    TK_DO = 265,
    TK_FOR = 266,
    TK_BREAK = 267,
    TK_CONTINUE = 268,
    TK_ENTRADA = 269,
    TK_SAIDA = 270,
    TK_ID = 271,
    TK_DEC_VAR = 272,
    TK_GLOBAL = 273,
    TK_TIPO_INT = 274,
    TK_TIPO_FLOAT = 275,
    TK_TIPO_BOOL = 276,
    TK_TIPO_CHAR = 277,
    TK_TIPO_STRING = 278,
    TK_CONV_FLOAT = 279,
    TK_CONV_INT = 280,
    TK_LE = 281,
    TK_HE = 282,
    TK_EQ = 283,
    TK_DIFF = 284,
    TK_UN_SUM = 285,
    TK_UN_SUB = 286,
    TK_NUN_SUM = 287,
    TK_NUN_SUB = 288,
    TK_NUN_MUL = 289,
    TK_NUN_DIV = 290,
    TK_CHAR = 291,
    TK_FLOAT = 292,
    TK_BOOL = 293,
    TK_NUM = 294,
    TK_STRING = 295,
    TK_FIM = 296,
    TK_ERROR = 297
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_IF 259
#define TK_ELSE 260
#define TK_TERN 261
#define TK_THEN 262
#define TK_END_LOOP 263
#define TK_WHILE 264
#define TK_DO 265
#define TK_FOR 266
#define TK_BREAK 267
#define TK_CONTINUE 268
#define TK_ENTRADA 269
#define TK_SAIDA 270
#define TK_ID 271
#define TK_DEC_VAR 272
#define TK_GLOBAL 273
#define TK_TIPO_INT 274
#define TK_TIPO_FLOAT 275
#define TK_TIPO_BOOL 276
#define TK_TIPO_CHAR 277
#define TK_TIPO_STRING 278
#define TK_CONV_FLOAT 279
#define TK_CONV_INT 280
#define TK_LE 281
#define TK_HE 282
#define TK_EQ 283
#define TK_DIFF 284
#define TK_UN_SUM 285
#define TK_UN_SUB 286
#define TK_NUN_SUM 287
#define TK_NUN_SUB 288
#define TK_NUN_MUL 289
#define TK_NUN_DIV 290
#define TK_CHAR 291
#define TK_FLOAT 292
#define TK_BOOL 293
#define TK_NUM 294
#define TK_STRING 295
#define TK_FIM 296
#define TK_ERROR 297

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
#define YYLAST   836

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  317

#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
       2,     2,     2,    44,     2,     2,     2,     2,    46,     2,
      53,    54,    51,    49,    58,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    57,
      47,    43,    48,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    45,    56,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   139,   146,   152,   156,   162,   167,   172,
     177,   182,   187,   192,   197,   202,   207,   212,   217,   222,
     227,   232,   238,   250,   262,   271,   281,   290,   297,   314,
     345,   367,   382,   400,   417,   436,   453,   478,   500,   516,
     533,   551,   570,   596,   615,   634,   653,   672,   696,   711,
     742,   764,   784,   804,   825,   845,   850,   875,   901,   920,
     939,   958,   977,  1001,  1016,  1047,  1069,  1089,  1109,  1129,
    1149,  1164,  1172,  1181,  1193,  1220,  1247,  1275,  1300,  1325,
    1352,  1378,  1405,  1432,  1446,  1454,  1462,  1473,  1497,  1523,
    1549,  1576,  1603,  1631,  1655,  1679,  1704,  1724,  1743,  1789,
    1834,  1834,  1854,  1854,  1867,  1867,  1885,  1885,  1905,  1905,
    1925,  1925,  1930,  1930,  1935,  1963,  1991,  2006,  2021,  2047,
    2063,  2079,  2095,  2104,  2113,  2138,  2158,  2177,  2196,  2204,
    2212,  2221,  2240,  2266,  2271,  2280,  2289,  2298,  2307,  2315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_IF", "TK_ELSE", "TK_TERN",
  "TK_THEN", "TK_END_LOOP", "TK_WHILE", "TK_DO", "TK_FOR", "TK_BREAK",
  "TK_CONTINUE", "TK_ENTRADA", "TK_SAIDA", "TK_ID", "TK_DEC_VAR",
  "TK_GLOBAL", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL",
  "TK_TIPO_CHAR", "TK_TIPO_STRING", "TK_CONV_FLOAT", "TK_CONV_INT",
  "TK_LE", "TK_HE", "TK_EQ", "TK_DIFF", "TK_UN_SUM", "TK_UN_SUB",
  "TK_NUN_SUM", "TK_NUN_SUB", "TK_NUN_MUL", "TK_NUN_DIV", "TK_CHAR",
  "TK_FLOAT", "TK_BOOL", "TK_NUM", "TK_STRING", "TK_FIM", "TK_ERROR",
  "'='", "'!'", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "'{'", "'}'", "';'", "','", "'['", "']'", "'?'", "':'",
  "$accept", "S", "BLOCO", "BLOCOGLOBAL", "BLOCOCONTEXTO", "COMANDOS",
  "COMANDO", "VETOR", "MATRIZ", "ENTRADA", "SAIDA", "ATRIBUICAO", "TRYING",
  "ATTGLOBAL", "DECLARACAO", "ARRAYDECLARATION", "GADECLARATION",
  "MATRIXDECLARATION", "GMDECLARATION", "IF", "$@1", "ELSE", "$@2",
  "TERNARIO", "$@3", "WHILE", "$@4", "DOWHILE", "$@5", "FOR", "$@6", "$@7",
  "FORMODES", "BREAK", "CONTINUE", "E", YY_NULLPTR
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
     295,   296,   297,    61,    33,   124,    38,    60,    62,    43,
      45,    42,    47,    40,    41,   123,   125,    59,    44,    91,
      93,    63,    58
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -176,    12,  -176,  -176,   -13,    60,   -33,    26,    66,   222,
    -176,  -176,  -176,  -176,    57,   369,    43,    99,  -176,  -176,
    -176,  -176,  -176,   342,   342,   121,    89,   111,   100,   104,
     108,   352,   109,    92,   117,   159,   171,  -176,   127,   128,
     662,   342,   130,  -176,  -176,   342,   342,   342,   342,     5,
    -176,    -5,   158,   220,   371,   129,    17,   784,   716,  -176,
    -176,  -176,   139,   193,  -176,  -176,   142,  -176,  -176,  -176,
    -176,  -176,  -176,    -3,   446,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,  -176,   419,  -176,   784,   784,   784,   784,  -176,
      63,   342,   342,   146,   342,   381,   784,   163,   168,   170,
     173,   207,   342,    31,   342,   342,   342,   342,   317,     2,
     473,  -176,  -176,   342,   154,    66,    39,   167,   219,  -176,
     188,   189,   120,   120,   488,   488,   461,   434,   120,   120,
      45,    45,  -176,  -176,   307,   784,   784,   342,   -45,    21,
     784,     6,   500,   342,   342,   342,   342,   190,   198,   201,
     527,   203,   213,   214,   224,   223,   342,   784,   784,   784,
     784,   249,   342,   342,   146,   342,   400,   784,   230,   239,
     243,   342,   227,   305,   102,   245,  -176,    39,   280,   342,
     342,   247,    75,  -176,   251,   342,  -176,  -176,  -176,   784,
     784,   784,   784,   146,   146,   146,   252,   342,   342,   342,
     342,   271,   272,   273,   554,  -176,   784,   784,    96,    98,
      56,   581,   342,   342,   268,   745,   264,   164,   342,    87,
     302,   342,   275,   268,   784,   784,   307,  -176,   342,   784,
     269,   269,   269,   342,   784,   784,   784,   784,   146,   146,
     146,   267,  -176,  -176,  -176,  -176,   784,   784,   322,    66,
     342,   675,   163,   168,   170,   173,   229,   277,   689,  -176,
     323,   279,   115,   608,   269,   269,   269,   342,   292,  -176,
     755,   342,   190,   198,   201,   203,   213,   214,   224,   281,
     342,   293,  -176,  -176,  -176,   635,  -176,  -176,   702,   271,
     272,   273,   702,  -176,  -176,  -176,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,     0,     0,     0,     0,     0,     5,
       2,   104,   116,   117,     0,   139,     0,     0,   136,   135,
     137,   134,   138,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,   122,   123,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,   139,   130,     0,   100,
     106,   108,   110,    14,    15,    16,     0,    18,     3,     6,
      11,    12,     9,   139,     0,    10,    76,    75,    74,    90,
      91,    92,    77,    78,    79,    93,    94,    95,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,    27,    43,    44,    45,    46,    26,
     139,     0,     0,     0,     0,     0,    42,    71,    72,    73,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   139,
       0,    21,   133,     0,     0,     0,     0,     0,     0,    17,
       0,     0,   126,   127,   131,   132,   128,   129,   124,   125,
     118,   119,   120,   121,     5,    47,    48,     0,     0,     0,
      22,   139,     0,     0,     0,     0,     0,    80,    81,    82,
       0,    84,    85,    86,    83,     0,     0,    58,    59,    60,
      61,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    49,    53,    54,    29,
      30,    31,    28,     0,     0,     0,    96,     0,     0,     0,
       0,    87,    88,    89,     0,    57,    62,    63,     0,     0,
     139,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     5,    51,    52,     5,    24,     0,    23,
      32,    33,    34,     0,    36,    37,    38,    35,     0,     0,
       0,    97,    65,    64,    68,    69,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,    39,    40,    41,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,    25,    98,     0,   101,   109,     0,     0,
       0,     0,     0,   103,    99,   114,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -125,  -176,   330,   -22,  -151,  -150,  -175,  -176,
    -176,  -132,   -15,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,   137,  -176,  -176,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,     2,    25,    26,    27,   159,   158,    28,
      29,    30,    31,    55,    32,    33,    34,    35,    36,    63,
     133,    64,   138,    37,    41,    65,   134,    66,   135,    67,
     136,   137,   196,    38,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    58,    54,   201,   195,    69,     5,   202,    74,   228,
     192,   203,     3,   204,   117,   118,   119,   120,   103,   109,
       7,   110,   105,   106,   107,   108,   116,    43,    44,   111,
     112,   130,    43,    44,   115,   229,    43,    44,   250,   251,
     252,    18,    19,    20,    21,    22,   121,    43,    44,    23,
     171,   172,   173,   174,   122,   193,   194,   140,    24,    51,
     113,    52,   188,     6,   114,   195,   207,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   205,
       8,   206,   175,   284,   285,   286,    43,    44,   155,   156,
     176,   160,   162,    43,    44,   281,   100,   101,   282,   170,
      42,   177,   178,   179,   180,   187,   272,   273,   274,   275,
     190,    76,    77,   186,    78,    53,   264,    11,   239,    -7,
     240,     9,    50,    12,    13,    59,    14,    15,    16,    17,
      60,    61,    62,   205,   160,   247,    79,    80,   276,    81,
     209,   210,   211,   212,   289,    68,   104,    18,    19,    20,
      21,    22,   262,   224,   204,    23,   205,    70,   263,   226,
     227,    71,   160,   231,    24,    72,    75,    -7,   235,    98,
      99,   100,   101,   205,   123,   303,   244,   245,    82,    83,
     110,    84,   249,   315,    88,    89,   131,   316,   111,   112,
      85,    86,  -112,    87,   254,   255,   256,   257,  -102,   139,
      18,    19,    20,    21,    22,   157,   163,   191,    23,   266,
     267,   164,   268,   165,   116,   271,   166,    24,   278,   113,
     197,   280,   115,   114,   198,   160,   167,   168,    11,   169,
     283,   199,   200,   213,    12,    13,   236,    14,    15,    16,
      17,   214,   221,   222,   215,   223,   217,   290,   292,   293,
     234,   294,   124,   125,   126,   127,   218,   219,    18,    19,
      20,    21,    22,   128,   305,   225,    23,   220,   308,    90,
      91,    92,    93,   232,    11,    24,    -7,   312,    -7,    50,
      12,    13,   233,    14,    15,    16,    17,   243,    94,    95,
      96,    97,    98,    99,   100,   101,   295,   296,   297,   298,
     309,   310,   241,   311,    18,    19,    20,    21,    22,   246,
     248,   253,    23,    11,   258,   259,   260,   270,   277,    12,
      13,    24,    14,    15,    16,    17,   287,   204,   299,   279,
     288,   301,     4,   110,   242,   181,   302,    45,    46,    47,
      48,   182,   183,    18,    19,    20,    21,    22,   237,   306,
     313,    23,     0,    18,    19,    20,    21,    22,    56,     0,
      24,    23,   238,     0,    50,     0,     0,     0,    73,     0,
      24,     0,   184,     0,     0,     0,   185,     0,    18,    19,
      20,    21,    22,     0,     0,     0,    23,   129,    18,    19,
      20,    21,    22,     0,     0,    24,    23,   161,     0,    43,
      44,    45,    46,    47,    48,    24,     0,    18,    19,    20,
      21,    22,    49,     0,     0,    23,   230,    18,    19,    20,
      21,    22,     0,     0,    24,    23,     0,     0,    50,     0,
       0,     0,     0,     0,    24,     0,    18,    19,    20,    21,
      22,     0,     0,     0,    23,    90,    91,    92,    93,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    90,    91,    92,    93,     0,     0,     0,     0,
     154,    96,    97,    98,    99,   100,   101,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    90,
      91,    92,    93,     0,     0,     0,   141,    95,    96,    97,
      98,    99,   100,   101,    90,    91,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,    90,    91,    92,    93,
       0,     0,     0,   189,     0,    96,    97,    98,    99,   100,
     101,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,    90,    91,    92,    93,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
      90,    91,    92,    93,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,    90,    91,    92,
      93,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,    90,    91,    92,    93,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,    90,    91,    92,    93,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,    90,    91,
      92,    93,     0,     0,     0,   314,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,    90,    91,    92,    93,   102,
      94,    95,    96,    97,    98,    99,   100,   101,    90,    91,
      92,    93,   291,     0,    94,    95,    96,    97,    98,    99,
     100,   101,    90,    91,    92,    93,   300,    94,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     9,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     132,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,     0,   269,
      94,    95,    96,    97,    98,    99,   100,   101,     0,   307,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
      23,    24,    17,   154,   136,    27,    19,   157,    31,   184,
     135,    56,     0,    58,    19,    20,    21,    22,    41,    14,
      53,    16,    45,    46,    47,    48,    49,    30,    31,    24,
      25,    54,    30,    31,    49,   185,    30,    31,   213,   214,
     215,    36,    37,    38,    39,    40,    51,    30,    31,    44,
      19,    20,    21,    22,    59,    16,    17,    60,    53,    16,
      55,    18,    60,     3,    59,   197,    60,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    58,
      54,    60,    51,   258,   259,   260,    30,    31,   111,   112,
      59,   114,   115,    30,    31,   246,    51,    52,   248,   122,
      43,   124,   125,   126,   127,   128,    19,    20,    21,    22,
     133,    19,    20,   128,    22,    16,    60,     6,    16,     8,
      18,    55,    59,    12,    13,     4,    15,    16,    17,    18,
       9,    10,    11,    58,   157,    60,    19,    20,    51,    22,
     163,   164,   165,   166,   269,    56,    16,    36,    37,    38,
      39,    40,    56,   176,    58,    44,    58,    57,    60,   182,
     183,    57,   185,   186,    53,    57,    57,    56,   191,    49,
      50,    51,    52,    58,    16,    60,   199,   200,    19,    20,
      16,    22,   205,   308,    57,    57,    57,   312,    24,    25,
      19,    20,    53,    22,   217,   218,   219,   220,     5,    57,
      36,    37,    38,    39,    40,    59,    43,    53,    44,   232,
     233,    43,   234,    43,   237,   238,    43,    53,   241,    55,
      53,   243,   237,    59,     5,   248,    19,    20,     6,    22,
     253,    43,    43,    43,    12,    13,     9,    15,    16,    17,
      18,    43,    19,    20,    43,    22,    43,   270,    19,    20,
       7,    22,    32,    33,    34,    35,    43,    43,    36,    37,
      38,    39,    40,    43,   287,    16,    44,    43,   291,    26,
      27,    28,    29,    43,     6,    53,     8,   300,    56,    59,
      12,    13,    43,    15,    16,    17,    18,     7,    45,    46,
      47,    48,    49,    50,    51,    52,    19,    20,    21,    22,
      19,    20,    57,    22,    36,    37,    38,    39,    40,    62,
      59,    59,    44,     6,    43,    43,    43,    53,    16,    12,
      13,    53,    15,    16,    17,    18,    59,    58,    51,    54,
       8,     8,     2,    16,   197,    18,    57,    32,    33,    34,
      35,    24,    25,    36,    37,    38,    39,    40,    43,    57,
      57,    44,    -1,    36,    37,    38,    39,    40,    16,    -1,
      53,    44,    57,    -1,    59,    -1,    -1,    -1,    16,    -1,
      53,    -1,    55,    -1,    -1,    -1,    59,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    16,    36,    37,
      38,    39,    40,    -1,    -1,    53,    44,    16,    -1,    30,
      31,    32,    33,    34,    35,    53,    -1,    36,    37,    38,
      39,    40,    43,    -1,    -1,    44,    16,    36,    37,    38,
      39,    40,    -1,    -1,    53,    44,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    45,    46,    47,    48,    49,    50,
      51,    52,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      61,    47,    48,    49,    50,    51,    52,    26,    27,    28,
      29,    45,    46,    47,    48,    49,    50,    51,    52,    26,
      27,    28,    29,    -1,    -1,    -1,    60,    46,    47,    48,
      49,    50,    51,    52,    26,    27,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    26,    27,    28,    29,
      -1,    -1,    -1,    60,    -1,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    26,    27,    28,    29,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      26,    27,    28,    29,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    26,    27,    28,
      29,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    26,    27,    28,    29,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    26,    27,    28,    29,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    26,    27,
      28,    29,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    26,    27,    28,    29,    57,
      45,    46,    47,    48,    49,    50,    51,    52,    26,    27,
      28,    29,    57,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    26,    27,    28,    29,    57,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    66,     0,    67,    19,     3,    53,    54,    55,
      65,     6,    12,    13,    15,    16,    17,    18,    36,    37,
      38,    39,    40,    44,    53,    67,    68,    69,    72,    73,
      74,    75,    77,    78,    79,    80,    81,    86,    96,    97,
      98,    87,    43,    30,    31,    32,    33,    34,    35,    43,
      59,    16,    18,    16,    75,    76,    16,    98,    98,     4,
       9,    10,    11,    82,    84,    88,    90,    92,    56,    68,
      57,    57,    57,    16,    98,    57,    19,    20,    22,    19,
      20,    22,    19,    20,    22,    19,    20,    22,    57,    57,
      26,    27,    28,    29,    45,    46,    47,    48,    49,    50,
      51,    52,    57,    98,    16,    98,    98,    98,    98,    14,
      16,    24,    25,    55,    59,    75,    98,    19,    20,    21,
      22,    51,    59,    16,    32,    33,    34,    35,    43,    16,
      98,    57,    54,    83,    89,    91,    93,    94,    85,    57,
      60,    60,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    61,    98,    98,    59,    71,    70,
      98,    16,    98,    43,    43,    43,    43,    19,    20,    22,
      98,    19,    20,    21,    22,    51,    59,    98,    98,    98,
      98,    18,    24,    25,    55,    59,    75,    98,    60,    60,
      98,    53,    65,    16,    17,    74,    95,    53,     5,    43,
      43,    69,    70,    56,    58,    58,    60,    60,    60,    98,
      98,    98,    98,    43,    43,    43,    60,    43,    43,    43,
      43,    19,    20,    22,    98,    16,    98,    98,    71,    70,
      16,    98,    43,    43,     7,    98,     9,    43,    57,    16,
      18,    57,    95,     7,    98,    98,    62,    60,    59,    98,
      71,    71,    71,    59,    98,    98,    98,    98,    43,    43,
      43,    60,    56,    60,    60,    60,    98,    98,    68,    54,
      53,    98,    19,    20,    21,    22,    51,    16,    98,    54,
      68,    69,    70,    98,    71,    71,    71,    59,     8,    65,
      98,    57,    19,    20,    22,    19,    20,    21,    22,    51,
      57,     8,    57,    60,    60,    98,    57,    54,    98,    19,
      20,    22,    98,    57,    60,    65,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    79,    80,    81,
      83,    82,    85,    84,    87,    86,    89,    88,    91,    90,
      93,    92,    94,    92,    95,    95,    96,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     0,     0,     2,     0,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     3,     2,     2,
       2,     3,     1,     3,     3,     5,     3,     3,     5,     5,
       5,     5,     6,     6,     6,     6,     6,     6,     6,     7,
       7,     7,     3,     3,     3,     3,     3,     4,     4,     5,
       5,     5,     5,     5,     5,     2,     3,     4,     3,     3,
       3,     3,     4,     4,     5,     5,     5,     5,     5,     5,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       2,     2,     2,     2,     2,     2,     5,     6,     8,     9,
       0,     7,     0,     7,     0,     8,     0,     6,     0,     7,
       0,     3,     0,     5,     6,     6,     1,     1,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1
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
#line 129 "sintatica.y" /* yacc.c:1652  */
    {
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << yyvsp[0].traducao << endl;
				freeVectors();
				cout << "\treturn 0;\n}" << endl;
			}
#line 1709 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 140 "sintatica.y" /* yacc.c:1652  */
    {
					yyval.traducao = yyvsp[-1].traducao;
				}
#line 1717 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 146 "sintatica.y" /* yacc.c:1652  */
    {
								contextoVariaveis.push_back(globalTabSym);
								cout << "Adicionado o contexto global!" << endl;
							}
#line 1726 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 152 "sintatica.y" /* yacc.c:1652  */
    {
								addMapToStack();
							}
#line 1734 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 157 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
					}
#line 1742 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 162 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
					}
#line 1750 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 168 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1758 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 173 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1766 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 178 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1774 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 183 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1782 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 188 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1790 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 193 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[0];
						}
#line 1798 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 198 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[0];
						}
#line 1806 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 203 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[0];
						}
#line 1814 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 208 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[0];
						}
#line 1822 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 213 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1830 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 218 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[0];
						}
#line 1838 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 223 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1846 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 228 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1854 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 233 "sintatica.y" /* yacc.c:1652  */
    {
							yyval = yyvsp[-1];
						}
#line 1862 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 239 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.traducao = yyvsp[0].traducao;
				tamanho_vetor++;
				//tamanho_linhas++;
				label_vet.push(yyvsp[0].label);
				tipo_vet.push(yyvsp[0].tipo);
				trad_vet.push(yyvsp[0].traducao);
				yyval.tipo = yyvsp[0].tipo;
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}
#line 1877 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 251 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
				tamanho_vetor++;
				yyval.tipo = yyvsp[-2].tipo;
				label_vet.push(yyvsp[0].label);
				tipo_vet.push(yyvsp[0].tipo);
				trad_vet.push(yyvsp[0].traducao);
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}
#line 1891 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 263 "sintatica.y" /* yacc.c:1652  */
    {
					yyval.traducao = yyvsp[-1].traducao;
					yyval.tipo = yyvsp[-1].tipo;
          tamanho_linhas++;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
				}
#line 1903 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 272 "sintatica.y" /* yacc.c:1652  */
    {
          yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
          tamanho_linhas++;
					tamanho_colunas = tamanho_vetor;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
        }
#line 1915 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 282 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = yyvsp[-2].tipo;
				variable Var = searchForVariable(yyvsp[-2].label);
				cout << "$3.label = " << yyvsp[0].label << endl;
				yyval.traducao = "\tstd::cin" + yyval.traducao + yyvsp[-2].traducao + ";\n";
			}
#line 1927 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 291 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				variable Var = searchForVariable(yyvsp[0].label);
				yyval.traducao = "\tstd::cout " + yyvsp[0].traducao + ";\n";
			}
#line 1937 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 298 "sintatica.y" /* yacc.c:1652  */
    {
							erroTipo("char", yyvsp[0].tipo);
							string nomeAuxID = genLabel();
							yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
							addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "char");
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 1949 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 315 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "int";
							if(yyval.tipo != yyvsp[0].tipo){

								if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{

									string nomeAuxID = genLabel();
									yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (int) " + yyvsp[0].label  + ";\n";

									addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "int");
									addVarToTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{

								string nomeAuxID = genLabel();
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";

								addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "int");
								variable Var = searchForVariable(yyvsp[-3].label);
								cout << "WHATS IN THE BOX? " << Var.valor << endl;
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 1983 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 346 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "float";
							if(yyval.tipo != yyvsp[0].tipo){
								if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = genLabel();
									yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (float) " + yyvsp[0].label  + ";\n";
									addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "float");
									addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
								addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "float");
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2008 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 368 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "bool";
							if(yyval.tipo != yyvsp[0].tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = genLabel();
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
								addVarToTabSym(nomeAuxID, yyvsp[-3].label, yyval.traducao, "int");
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2025 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 383 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "int";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								addVarToTabSym(nomeAuxID, yyvsp[-4].label, yyval.traducao, "int*");
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2046 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 401 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "float";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								addVarToTabSym(nomeAuxID, yyvsp[-4].label, yyval.traducao, "float*");
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2066 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 418 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "char";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								addVarToTabSym(nomeAuxID, yyvsp[-4].label, yyval.traducao, "char*");
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2086 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 437 "sintatica.y" /* yacc.c:1652  */
    {
							erroTipo("char", yyvsp[0].tipo);
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "char");
							yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label + ";\n";
							addVarToGlobalTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 2098 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 454 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "int";
							if(yyval.tipo != yyvsp[0].tipo){

								if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{
									string nomeAuxID = genLabel();
									addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "int");
									yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (int) " + yyvsp[0].label  + ";\n";
									addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "int");
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2126 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 479 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "float";
							if(yyval.tipo != yyvsp[0].tipo){
								if(yyvsp[0].tipo == "char" || yyvsp[0].tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = genLabel();
									addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "float");
									yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (float) " + yyvsp[0].label  + ";\n";
									addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "float");
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
								addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
							}
						}
#line 2151 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 501 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "bool";
							if(yyval.tipo != yyvsp[0].tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-4].label, yyvsp[0].traducao, "int");
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = " + yyvsp[0].label  + ";\n";
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2168 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 517 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "int";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-5].label, yyvsp[0].traducao, "int*");
								//variable Var = searchForVariable(nomeAuxID);
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2188 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 534 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "float";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-5].label, yyvsp[0].traducao, "float*");
								//variable Var = searchForVariable(nomeAuxID);

								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2209 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 552 "sintatica.y" /* yacc.c:1652  */
    {
							yyval.tipo = "char";
							if(yyvsp[0].tipo != yyval.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, yyvsp[-5].label, yyvsp[0].traducao, "char*");
								//variable Var = searchForVariable(nomeAuxID);
								yyval.traducao = yyvsp[0].traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2229 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 571 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-2].label);

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
#line 2257 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 597 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-2].label);
							variable Var2 = searchForVariable(yyvsp[0].label);
							if((yyvsp[0].tipo != Var.tipo)){

								if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								yyval.tipo = Var.tipo;
								yyval.label = Var.nome;
								yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + yyvsp[0].label + ";\n";
							}
						}
#line 2279 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 616 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-2].label);
							variable Var2 = searchForVariable(yyvsp[0].label);
							if((yyvsp[0].tipo != Var.tipo)){

								if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								yyval.tipo = Var.tipo;
								yyval.label = Var.nome;
								yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + yyvsp[0].label + ";\n";
							}
						}
#line 2301 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 635 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-2].label);
							variable Var2 = searchForVariable(yyvsp[0].label);
							if((yyvsp[0].tipo != Var.tipo)){

								if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								yyval.tipo = Var.tipo;
								yyval.label = Var.nome;
								yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + yyvsp[0].label + ";\n";
							}
						}
#line 2323 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 654 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-2].label);
							variable Var2 = searchForVariable(yyvsp[0].label);
							if((yyvsp[0].tipo != Var.tipo)){

								if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								yyval.tipo = Var.tipo;
								yyval.label = Var.nome;
								yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + yyvsp[0].label + ";\n";
							}
						}
#line 2345 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 673 "sintatica.y" /* yacc.c:1652  */
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
#line 2372 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 697 "sintatica.y" /* yacc.c:1652  */
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
#line 2390 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 712 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);
							map_vetor[Var.nome] = tamanho_vetor;
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;

							if(Var.tipo != yyvsp[-1].tipo + '*'){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

									yyval.traducao = yyvsp[-1].traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
									cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
									map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
									cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
									tamanho_vetor = 0;
									map_vetor[Var.nome] = 0;
								}

								else{
									yyerror("Vetor atribuido maior que suportado na variável!");
								}
							}
						}
#line 2424 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 743 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							if(Var.tipo != yyvsp[-1].tipo + '*'){
								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}
							else{
							if(tamanho_vetor > elementos_matriz){
									yyerror("Vetor atribuido maior que variável suporta!");
								}
								else{
									variable Var = searchForVariable(yyvsp[-4].label);
									yyval.traducao = yyvsp[-1].traducao + addElementsToArray(elementos_matriz, Var.nome);
									//tamanho_vetor -= tamanho_linhas;
									tamanho_vetor = 0;
								}
							}
						}
#line 2449 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 765 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);

							if(Var.tipo != yyvsp[0].tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									variable kmpls = searchForVariable(yyvsp[-3].label);
									yyval.traducao = yyvsp[0].traducao + "\t" + pointer.nome + " = " + kmpls.nome +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + yyvsp[0].label + ";\n";
								}
							}
						}
#line 2472 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 785 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);

							if(Var.tipo != yyvsp[0].tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									//variable kmpls = searchForVariable($3.label);
									yyval.traducao = yyvsp[-3].traducao + yyvsp[0].traducao + "\t" + pointer.nome + " = " + yyvsp[-3].label +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + yyvsp[0].label + ";\n";
								}
							}
						}
#line 2495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 805 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);
							variable Vector = searchForVariable(yyvsp[-2].label);
							variable Index = searchForVariable(yyvsp[-1].label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								yyval.traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}

						}
#line 2518 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 826 "sintatica.y" /* yacc.c:1652  */
    {
							variable Var = searchForVariable(yyvsp[-4].label);
							variable Vector = searchForVariable(yyvsp[-2].label);
							variable Index = searchForVariable(yyvsp[-1].label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								yyval.traducao = yyvsp[-1].traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}
						}
#line 2540 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 846 "sintatica.y" /* yacc.c:1652  */
    {
					yyval = yyvsp[-1];
				}
#line 2548 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 851 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-2].label);

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
#line 2576 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 876 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-3].label);
						variable Var2 = searchForGlobalVariable(yyvsp[0].label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								yyval.tipo = Var.tipo;
								yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + Var2.nome + ";\n";
							}
						}

						else{

							yyval.tipo = Var2.tipo;
							yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
						}
					}
#line 2604 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 902 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-2].label);
						variable Var2 = searchForVariable(yyvsp[0].label);
						if((yyvsp[0].tipo != Var.tipo)){

							if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							yyval.tipo = Var.tipo;
							yyval.label = Var.nome;
							yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + yyvsp[0].label + ";\n";
						}
					}
#line 2626 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 921 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-2].label);
						variable Var2 = searchForVariable(yyvsp[0].label);
						if((yyvsp[0].tipo != Var.tipo)){

							if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							yyval.tipo = Var.tipo;
							yyval.label = Var.nome;
							yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + yyvsp[0].label + ";\n";
						}
					}
#line 2648 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 940 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-2].label);
						variable Var2 = searchForVariable(yyvsp[0].label);
						if((yyvsp[0].tipo != Var.tipo)){

							if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							yyval.tipo = Var.tipo;
							yyval.label = Var.nome;
							yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + yyvsp[0].label + ";\n";
						}
					}
#line 2670 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 959 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-2].label);
						variable Var2 = searchForVariable(yyvsp[0].label);
						if((yyvsp[0].tipo != Var.tipo)){

							if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool") || (yyvsp[0].tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							yyval.tipo = Var.tipo;
							yyval.label = Var.nome;
							yyval.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + yyvsp[0].label + ";\n";
						}
					}
#line 2692 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 978 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-3].label);
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
#line 2719 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 1002 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-3].label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if((yyvsp[0].tipo == "char" && Var.tipo != "char") || (yyvsp[0].tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + yyvsp[0].tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							yyval.traducao = yyvsp[0].traducao + "\t" + Var.nome + " = (int) " + yyvsp[0].label + ";\n";
						}
					}
#line 2737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 1017 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);
						map_vetor[Var.nome] = tamanho_vetor;
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;

						if(Var.tipo != yyvsp[-1].tipo + '*'){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{

							if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

								yyval.traducao = yyvsp[-1].traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
								cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
								map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
								cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
								tamanho_vetor = 0;
								map_vetor[Var.nome] = 0;
							}

							else{
								yyerror("Vetor atribuido maior que suportado na variável!");
							}
						}
					}
#line 2771 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 1048 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;
						if(Var.tipo != yyvsp[-1].tipo + '*'){
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}
						else{
						if(tamanho_vetor > elementos_matriz){
								yyerror("Vetor atribuido maior que variável suporta!");
							}
							else{
								variable Var = searchForVariable(yyvsp[-4].label);
								yyval.traducao = yyvsp[-1].traducao + addElementsToArray(elementos_matriz, Var.nome);
								//tamanho_vetor -= tamanho_linhas;
								tamanho_vetor = 0;
							}
						}
					}
#line 2796 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 1070 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);

						if(Var.tipo != yyvsp[0].tipo + "*"){
							cout << "TIPO E: " << Var.tipo << endl;
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								variable kmpls = searchForVariable(yyvsp[-3].label);
								yyval.traducao = yyvsp[0].traducao + "\t" + pointer.nome + " = " + kmpls.nome +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + yyvsp[0].label + ";\n";
							}
						}
					}
#line 2819 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 1090 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);

						if(Var.tipo != yyvsp[0].tipo + "*"){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								//variable kmpls = searchForVariable($3.label);
								yyval.traducao = yyvsp[-3].traducao + yyvsp[0].traducao + "\t" + pointer.nome + " = " + yyvsp[-3].label +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + yyvsp[0].label + ";\n";
							}
						}
					}
#line 2842 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 1110 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);
						variable Vector = searchForVariable(yyvsp[-2].label);
						variable Index = searchForVariable(yyvsp[-1].label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							yyval.traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 2864 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 1130 "sintatica.y" /* yacc.c:1652  */
    {
						variable Var = searchForGlobalVariable(yyvsp[-4].label);
						variable Vector = searchForVariable(yyvsp[-2].label);
						variable Index = searchForVariable(yyvsp[-1].label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							yyval.traducao = yyvsp[-1].traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 2886 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 1150 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							yyval.traducao = "";
							addVarToTabSym(nomeAuxID, yyvsp[-1].label, "none", "char");
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 2897 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 1165 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							yyval.traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToTabSym(nomeAuxID, yyvsp[-1].label, "0", "int");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2908 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 1173 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();

							yyval.traducao = "\t" + nomeAuxID + " = 0.0;\n";;
							addVarToTabSym(nomeAuxID, yyvsp[-1].label, "0.0", "float");
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 2920 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 1182 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							yyval.traducao = "\t" + nomeAuxID + " = TRUE;\n";;
							addVarToTabSym(nomeAuxID, yyvsp[-1].label, "TRUE", "bool");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2931 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 1194 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, yyval.label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 2961 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 1221 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, yyvsp[0].label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 2991 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 1248 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToTabSym(nomeAuxID, yyvsp[0].label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3021 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 1276 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, yyvsp[0].label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3049 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 1301 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, yyvsp[0].label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 3077 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 1326 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, yyvsp[0].label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 3105 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 1353 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, yyvsp[-2].label, "empty", "int*");
							//tamanho_vetor = 50;
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3134 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 1379 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, yyvsp[-2].label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 3164 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 1406 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, yyvsp[-2].label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 3192 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 1433 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							addVarToTabSym(nomeAuxID, yyvsp[-2].label, "none", "char");
							yyval.traducao = "";
							addVarToGlobalTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 3203 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 1447 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							yyval.traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-1].label, "0", "int");
							//addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3214 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 1455 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-2].label, "0.0", "float");
							yyval.traducao = "\t" + nomeAuxID + " = 0.-;\n";
							addVarToGlobalTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 3225 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 1463 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-2].label, "TRUE", "bool");
							yyval.traducao = "\t" + nomeAuxID + " = TRUE;\n";
							addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3236 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 1474 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-2].label, "empty", "int*");
						}
#line 3263 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 1498 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-2].label, "empty", "float*");
						}
#line 3292 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 1524 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							yyval.traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[-2].label, "empty", "char*");
						}
#line 3319 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 1550 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "int*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3349 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 1577 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
 							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "float*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3379 "y.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 1604 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable(yyvsp[-1].label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
 							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "char*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3409 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 1632 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "int*");
						}
#line 3436 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 1656 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "float*");
						}
#line 3463 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 1680 "sintatica.y" /* yacc.c:1652  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							yyval.traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, yyvsp[0].label, "empty", "char*");
						}
#line 3490 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 1705 "sintatica.y" /* yacc.c:1652  */
    {
									 yyval = yyvsp[-1];
									 stringstream tamanho;

									 tamanho << yyvsp[-1].traducao;
									 string temp;
									 int found;

									 while(!tamanho.eof()){
										 tamanho >> temp;

										 if(stringstream(temp) >> found){
											 cout << "______________ " << found << endl;
											 tamanho_linhas = found;
										 }
									 }
								 }
#line 3512 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1725 "sintatica.y" /* yacc.c:1652  */
    {
									yyval = yyvsp[-1];
									stringstream tamanho;

									tamanho << yyvsp[-1].traducao;
									string temp;
									int found;

									while(!tamanho.eof()){
										tamanho >> temp;

										if(stringstream(temp) >> found){
											cout << "______________ " << found << endl;
											tamanho_linhas = found;
										}
									}
								}
#line 3534 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1744 "sintatica.y" /* yacc.c:1652  */
    {
									 yyval = yyvsp[-4];

									 //cout << $4.traducao << $7.traducao << endl;

									 stringstream v0;
									 stringstream v1;

									 v0 << yyvsp[-4].traducao;
									 v1 << yyvsp[-1].traducao;

									 string temp;

									 int found0;
									 int found1;

									 while(!v0.eof()){

										 //extraindo palavra por palavra
										 v0 >> temp;

										 //checando se a palavra é um inteiro ou não
										 if(stringstream(temp) >> found0){
											 //cout << found0 << " ";
										 }
									 }

									 while(!v1.eof()){

										 v1 >> temp;

										 if(stringstream(temp) >> found1){
											 //cout << found1 << " ";
										 }
									 }

									 cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									 tamanho_linhas = found0;
									 tamanho_colunas = found1;
									 elementos_matriz = tamanho_linhas * tamanho_colunas;
									 cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									 //tamanho_vetor =  found0 * found1;
								 }
#line 3582 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 1790 "sintatica.y" /* yacc.c:1652  */
    {
									yyval = yyvsp[-4];

									//cout << $4.traducao << $7.traducao << endl;

									stringstream v0;
									stringstream v1;

									v0 << yyvsp[-4].traducao;
									v1 << yyvsp[-1].traducao;

									string temp;

									int found0;
									int found1;

									while(!v0.eof()){

										//extraindo palavra por palavra
										v0 >> temp;

										//checando se a palavra é um inteiro ou não
										if(stringstream(temp) >> found0){
											//cout << found0 << " ";
										}
									}

									while(!v1.eof()){

										v1 >> temp;

										if(stringstream(temp) >> found1){
											//cout << found1 << " ";
										}
									}

									cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									tamanho_linhas = found0;
									tamanho_colunas = found1;
									elementos_matriz = tamanho_linhas * tamanho_colunas;
									cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									//tamanho_vetor =  found0 * found1;
								}
#line 3630 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1834 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 3636 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 1835 "sintatica.y" /* yacc.c:1652  */
    {
						if(yyvsp[-4].tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + yyvsp[-4].label;
							yyval.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-4].traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[-2].traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 3658 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1854 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 3664 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1855 "sintatica.y" /* yacc.c:1652  */
    {
					int posiAlteracao = yyvsp[-6].traducao.rfind("final");
					string auxRetorno = yyvsp[-6].traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					yyval.traducao = auxRetorno + yyvsp[-2].traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 3678 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 1867 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 3684 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 1869 "sintatica.y" /* yacc.c:1652  */
    {
				if(yyvsp[-5].tipo != "bool"){
				yyerror("Condicional sem declaração do tipo booleano!\n");
			}

			else{
				string auxVar = "temp" + to_string(valorVar++);
				addVarToTempVector("\tint " + auxVar + ";\n");
				string auxVar2 = "!" + yyvsp[-5].label;
				yyval.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-5].traducao + "\n\t" + auxVar + " = " +
				auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[-3].traducao + ";\tgoto final" + to_string(stackLoops.top() + 1) + ";\n" + "\n\tfinal" + to_string(stackLoops.top()) + ":\n" + yyvsp[-3].traducao + "\tfinal" + to_string(stackLoops.top() + 1) + ":\n";
				stackLoops.pop();
			}
			}
#line 3703 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 1885 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 3709 "y.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 1886 "sintatica.y" /* yacc.c:1652  */
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
#line 3731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 1905 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 3737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 1906 "sintatica.y" /* yacc.c:1652  */
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
#line 3759 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 1925 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 3765 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 1926 "sintatica.y" /* yacc.c:1652  */
    {
				  	yyval = yyvsp[0];
				  }
#line 3773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 1930 "sintatica.y" /* yacc.c:1652  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 3779 "y.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 1931 "sintatica.y" /* yacc.c:1652  */
    {
						yyval = yyvsp[-1];
					}
#line 3787 "y.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 1936 "sintatica.y" /* yacc.c:1652  */
    {

							variable Var = searchForVariable(yyvsp[-3].label);

				  		if(yyvsp[-3].tipo != "bool"){
				  			string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + yyvsp[-3].tipo + " inválida!\n";
				  			yyerror(msgError);
				  		}

				  		string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

				  		string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + yyvsp[-3].label;

							yyval.traducao = "\n//for\n" + yyvsp[-5].traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-3].traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[0].traducao + "\t" + nomeVar + " = " + Var.nome + " + 1;\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							addVarToTabSym(nomeVar, yyvsp[-1].label, yyvsp[-1].traducao, yyvsp[-1].tipo);
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
#line 3818 "y.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 1964 "sintatica.y" /* yacc.c:1652  */
    {

							variable Var = searchForVariable(yyvsp[-3].label);

					  	if(yyvsp[-3].tipo != "bool"){
					  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + yyvsp[-3].tipo + " inválida!\n";
					  		yyerror(msgError);
					  	}

						  string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

						  string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + yyvsp[-3].label;

							yyval.traducao = "\n//for\n" + yyvsp[-5].traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + yyvsp[-3].traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + yyvsp[0].traducao + yyvsp[-1].traducao + "\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
#line 3848 "y.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 1992 "sintatica.y" /* yacc.c:1652  */
    {
						if(stackLoops.empty()){
							yyval.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Break fora de um laço. Erro!");
						}

						else{
							yyval.traducao = "\tgoto final" + to_string(stackLoops.top()) + ";// isso é um break\n";
						}
					}
#line 3866 "y.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 2007 "sintatica.y" /* yacc.c:1652  */
    {
						if(stackLoops.empty()){
							yyval.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Continue fora de um laço. Erro!");
						}

						else{
							yyval.traducao = "\tgoto comeco" + to_string(stackLoops.top()) + ";// isso é um continue\n";
						}
					}
#line 3884 "y.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 2022 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();

				if(yyval.tipo != "string" && yyvsp[-2].tipo != "string" && yyvsp[0].tipo != "string")
				{
					cout << yyval.tipo << endl;
					structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
					if(aux.varConvertida == yyvsp[-2].label){
						yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " + " + yyvsp[0].label + ";\n";
					}
					else if(aux.varConvertida == yyvsp[0].label){
						yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + aux.nomeVar + ";\n";
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
#line 3913 "y.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 2048 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao =  yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " - " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 3932 "y.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 2064 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao =  yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " * " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 3951 "y.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 2080 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " / " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
				}
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
			}
#line 3970 "y.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 2096 "sintatica.y" /* yacc.c:1652  */
    {

				variable Var = searchForVariable(yyvsp[-1].label);
				yyval.tipo = Var.tipo;
				yyval.label = Var.nome;
				yyval.traducao = "\t" + Var.nome + " = " + Var.nome + " + 1;\n";
			}
#line 3982 "y.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 2105 "sintatica.y" /* yacc.c:1652  */
    {

				variable Var = searchForVariable(yyvsp[-1].label);
				yyval.tipo = Var.tipo;
				yyval.label = Var.nome;
				yyval.traducao = "\t" + Var.nome + " = " + Var.nome + " - 1;\n";
			}
#line 3994 "y.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 2114 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "carai " << $1.traducao << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);

				if(aux.varConvertida == yyvsp[-2].label){

					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " < " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";


				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4022 "y.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 2139 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);

				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " > " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4045 "y.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 2159 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " <= " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4067 "y.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 2178 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " >= " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4089 "y.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 2197 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4100 "y.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 2205 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = isBoolean(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4111 "y.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 2213 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[0];
				yyval.tipo = isBoolean("bool", yyvsp[0].tipo);
				yyval.label = genLabel();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = !" + yyvsp[0].label + ";\n";
				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4123 "y.tab.c" /* yacc.c:1652  */
    break;

  case 131:
#line 2222 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
				if(aux.varConvertida == yyvsp[-2].label){
					yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " == " + yyvsp[0].label + ";\n";
				}
				else if(aux.varConvertida == yyvsp[0].label){
					yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
				}

				addVarToTempVector("\tint " + yyval.label + ";\n");
			}
#line 4145 "y.tab.c" /* yacc.c:1652  */
    break;

  case 132:
#line 2241 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = genLabel();
				yyval.tipo = "bool";

				if((yyvsp[-2].tipo == "bool" && yyvsp[0].tipo == "bool") || (yyvsp[-2].tipo == "char" && yyvsp[0].tipo == "char")){

					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
				}

				else{

					structAux aux = implicitConversion(yyvsp[-2].tipo, yyvsp[0].tipo, yyvsp[-2].label, yyvsp[0].label);
					if(aux.varConvertida == yyvsp[-2].label){
						yyval.traducao = yyvsp[0].traducao + aux.implicita + "\t" + yyval.label + " = " + aux.nomeVar + " != " + yyvsp[0].label + ";\n";
					}
					else if(aux.varConvertida == yyvsp[0].label){
						yyval.traducao = yyvsp[-2].traducao + aux.implicita + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
					}
					addVarToTempVector("\tint " + yyval.label + ";\n");
				}
			}
#line 4174 "y.tab.c" /* yacc.c:1652  */
    break;

  case 133:
#line 2267 "sintatica.y" /* yacc.c:1652  */
    {
				yyval = yyvsp[-1];
			}
#line 4182 "y.tab.c" /* yacc.c:1652  */
    break;

  case 134:
#line 2272 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioInt" + to_string(valorTemp++);
				yyval.tipo = "int";
				addVarToTempVector("\t" + yyval.tipo + " " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
				addVarToTabSym(yyval.label, yyval.label, yyvsp[0].traducao, "int");
			}
#line 4194 "y.tab.c" /* yacc.c:1652  */
    break;

  case 135:
#line 2281 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				yyval.tipo = "float";
				addVarToTempVector("\tfloat " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
				addVarToTabSym(yyval.label, yyval.label, yyval.traducao, "float");
		 	}
#line 4206 "y.tab.c" /* yacc.c:1652  */
    break;

  case 136:
#line 2290 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioChar" + to_string(valorTemp++);
				yyval.tipo = "char";
				addVarToTempVector("\tchar "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
				addVarToTabSym(yyval.label, yyval.label, yyval.traducao, "char");
			}
#line 4218 "y.tab.c" /* yacc.c:1652  */
    break;

  case 137:
#line 2299 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioBool" + to_string(valorTemp++);
				yyval.tipo = "bool";
				addVarToTempVector("\tint " + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
				addVarToTabSym(yyval.label, yyval.label, yyval.traducao, "int");
			}
#line 4230 "y.tab.c" /* yacc.c:1652  */
    break;

  case 138:
#line 2308 "sintatica.y" /* yacc.c:1652  */
    {
				yyval.label = "nomeTemporarioString" + to_string(valorTemp++);
				yyval.tipo = "string";
				addVarToTempVector("\tstring "  + yyval.label + ";\n");
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
			}
#line 4241 "y.tab.c" /* yacc.c:1652  */
    break;

  case 139:
#line 2316 "sintatica.y" /* yacc.c:1652  */
    {
				variable auxVar = searchForVariable(yyvsp[0].label);
				yyval.label = auxVar.nome;
				yyval.tipo = auxVar.tipo;
				yyval.traducao = auxVar.valor;
			}
#line 4252 "y.tab.c" /* yacc.c:1652  */
    break;


#line 4256 "y.tab.c" /* yacc.c:1652  */
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
#line 2323 "sintatica.y" /* yacc.c:1918  */


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
	cout << "==== Valor atual: " << valorVar << endl;
}

string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "\nconteudo da variavel: " << conteudoVar << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);

	if(got == tabSym.end()){

		variable Var2;

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

	else {

		return tabSym[nomeDado].nome;
	}

	return "";
}

string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeGerado);
	cout << "\nglobalTabSym antes " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nomeDado);

	if(got == globalTabSym.end()){

		variable Var;

		Var =	{
						.tipo = tipoVar,
				   	.nome = nomeGerado,
						.valor = conteudoVar
		  		};

		globalTabSym[nomeDado] = Var;
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo <<" na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	else {

		return globalTabSym[nomeDado].nome;
	}

	return "";
}

void printGlobalVariables(){

	unordered_map<string, variable> auxMap = globalTabSym;

	for (auto& it: globalTabSym){

		addVarToGlobalTempVector("\t" + it.second.tipo + " " + it.second.nome + ";\n");
	}

	printGlobalVector();
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){ //se a primeira variável for float e segunda for int

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

	else if(tipo0 == "int" && tipo1 == "float") //se a primeira variável for int e a segunda for float
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

  else if(tipo0 == "float" && tipo1 == "float") //se as duas são float
  {

	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
   }

  else if(tipo0 == "int" && tipo1 == "int") //se as duas são int
  {

	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
  }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }
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

void addVarToGlobalTempVector(string nomeVar)
{
	globalTempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

void printGlobalVector()
{
	cout << "\n" << endl;
	for(auto i: globalTempVector)
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
	cout << "global " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo <<"\nContexto: " << i << endl;
			cout << "Conteudo: " << auxMap[nome].valor << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
}

void checkForVariable(string nome){

	unordered_map<string, variable>::const_iterator got = (contextoVariaveis.back()).find(nome); //procuro a variável pelo nome no map mais interno

	if(got != (contextoVariaveis.back()).end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		string errorMessage = "\n\nEncontrada variável 2!\nNome: " + nome + "\nTipo: " + (contextoVariaveis.back())[nome].tipo + "\n";
		yyerror(errorMessage);
	}
}

variable searchForGlobalVariable(string nome){

	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nome); //procuro a variável pelo nome no map mais interno

	if(got != globalTabSym.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << globalTabSym[nome].tipo << endl;
		cout << "Conteudo: " << globalTabSym[nome].valor << endl;
		variable auxVar = globalTabSym[nome];
		return auxVar; //se for, retorno essa variável
	}
}

string addElementsToArray(int tamanhoArray, string nomeArray){

	string trad = "";
	stack <string> auxStack;

	for(int i = 0; i < tamanhoArray; i++){ //uma das gambiarras mais criminosas que eu fiz
		auxStack.push(label_vet.top());
		label_vet.pop();
		tipo_vet.pop();
		trad_vet.pop();
	}

	variable Var1 = arrayPointerNames[nomeArray];
	variable Var2 = arrayPointerNames[nomeArray + "Acrescimo"];

	for(int i = 0; i < tamanhoArray; i++){
		trad = trad + "\t" + nomeArray + "[" + Var1.nome + "] = " + auxStack.top() +
		";\n\t" + Var1.nome + " = " + Var1.nome + " + " + Var2.nome + ";\n"; //olha que coisa feia
		auxStack.pop();
	}

	return trad;
}

void freeVectors(){

	string aux;
	while (!stackVectors.empty()){
		aux = stackVectors.top();
		stackVectors.pop();
		cout << aux << endl;
	}
	cout << "\n\n" << endl;
}
