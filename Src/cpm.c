/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cpm.y"


	#include <malloc.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <ctype.h>
	#include "symcpm.h"
	#include "strsplit.h"

	#define NHASH 9997
	#define MAX_FILE_NAME 50
	#define YYERROR_VERBOSE 1
	
	typedef struct symTbls
	{
		symcpm symTblScope[NHASH];
		struct symTbls* nextSymTbl;
	} symTbl;

	typedef enum
	{
		redef_e,
		typesmismtch_e,
		undec_e,
		argsmismtch_e,
		zero_e,
		opermismtch_e,
		constasgn_e,
		swexpr_e
	} ERRORS;

	typedef enum
	{
		if_e,
		while_e,
		for_e,
		dowhile_e
	} BMODE;

	void yyerror(const char* str);
	void mError(const int typeOfError, const symcpm* var, const char* str);
	void emit(FILE* file, const char* str);
	void emitDec(const symcpm* tempVar);
	void freeSymbolTable();

	extern int yylex (void);
	extern int yylineno, column;
	extern char* yytext;
	symTbl* listOfSymTbl;
	static int currLevelNum = 1;
	FILE* errorsLog, *mipsOut, *tempOutBody, *tempOutHeader;
	char* variablsTemp[NHASH];
	char* fileName1, *saveStmt;
	BMODE mode;
	/* The global variables below responsible for different labels
		in the code, in situations where there are multiple "if" statments,
		while loops etc.. and if there are inner statements.
		(like if inside if etc..) */
	int numOfVar = 0, numOfSent = 1, numOfLoops = 1, iRegs = 0, fRegs = 0;
	int numOfIf = 0, numOfJ = 0, numOfCond = 2, numOfTemps = 0, numOfW = 0;
	int numOfFor = 0, numOfDW = 0, numOfSw = 0;
	static bool gProg = true;


/* Line 371 of yacc.c  */
#line 135 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     num = 258,
     relop = 259,
     addop = 260,
     mulop = 261,
     assignop = 262,
     orop = 263,
     andop = 264,
     sentence = 265,
     id = 266,
     BREAK = 267,
     CASE = 268,
     CONST = 269,
     DEFAULT = 270,
     DO = 271,
     ELSE = 272,
     END = 273,
     FOR = 274,
     IF = 275,
     INT = 276,
     MAIN = 277,
     PRINT = 278,
     REAL = 279,
     READ = 280,
     START = 281,
     STRING = 282,
     SWITCH = 283,
     TILL = 284,
     THEN = 285,
     VAR = 286,
     WHILE = 287
   };
#endif
/* Tokens.  */
#define num 258
#define relop 259
#define addop 260
#define mulop 261
#define assignop 262
#define orop 263
#define andop 264
#define sentence 265
#define id 266
#define BREAK 267
#define CASE 268
#define CONST 269
#define DEFAULT 270
#define DO 271
#define ELSE 272
#define END 273
#define FOR 274
#define IF 275
#define INT 276
#define MAIN 277
#define PRINT 278
#define REAL 279
#define READ 280
#define START 281
#define STRING 282
#define SWITCH 283
#define TILL 284
#define THEN 285
#define VAR 286
#define WHILE 287



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 69 "cpm.y"

	struct 
	{
		enum
		{
			I,
			F,
			S
		} type;
		union
		{
			float fval;
			int   ival;
		};
	} nval;
   char* sval;
   enum {PLUS, MINUS, MUL, DIV, EQUAL, NOT_EQUAL, LESS, MORE, GREATER_EQUAL, LESS_EQUAL, ASSIGN, OR, AND} op;


/* Line 387 of yacc.c  */
#line 262 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 290 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      36,    37,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    16,    20,    21,    22,
      26,    27,    30,    34,    38,    39,    44,    47,    51,    53,
      55,    57,    65,    66,    69,    70,    72,    77,    82,    84,
      86,    88,    90,    96,   102,   108,   113,   119,   122,   127,
     132,   137,   138,   139,   140,   152,   153,   154,   162,   163,
     164,   175,   176,   184,   186,   189,   192,   196,   204,   206,
     208,   209,   210,   220,   224,   229,   233,   239,   245,   251,
     257,   261,   263,   266,   270,   272,   277,   278,   283,   287,
     289,   292,   296,   298,   302,   306,   308
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    -1,    22,    11,    26,    44,    46,
      45,    55,    18,    -1,     1,    -1,    31,    47,    54,    -1,
      -1,    -1,    47,    48,    50,    -1,    -1,    49,    50,    -1,
      53,    33,    51,    -1,    53,     1,    51,    -1,    -1,    11,
      52,    34,    51,    -1,    11,    35,    -1,    11,     1,    51,
      -1,    21,    -1,    24,    -1,    27,    -1,    14,    53,    11,
       7,     3,    35,    54,    -1,    -1,    55,    56,    -1,    -1,
      59,    -1,    11,     7,    10,    35,    -1,    11,     1,    10,
      35,    -1,    60,    -1,    58,    -1,    57,    -1,    69,    -1,
      23,    36,    80,    37,    35,    -1,    23,    36,    10,    37,
      35,    -1,    23,    36,     1,    37,    35,    -1,    23,    36,
       1,    35,    -1,    25,    36,    11,    37,    35,    -1,     1,
      35,    -1,    11,     7,    80,    35,    -1,    11,     1,    80,
      35,    -1,    11,     7,     1,    35,    -1,    -1,    -1,    -1,
      20,    36,    76,    37,    61,    30,    56,    62,    17,    63,
      56,    -1,    -1,    -1,    32,    64,    36,    76,    37,    65,
      69,    -1,    -1,    -1,    19,    36,    59,    66,    76,    35,
      67,    75,    37,    56,    -1,    -1,    16,    68,    69,    29,
      36,    76,    37,    -1,    70,    -1,     1,    38,    -1,     1,
      30,    -1,    39,    55,    40,    -1,    28,    36,    71,    37,
      39,    72,    40,    -1,    11,    -1,     3,    -1,    -1,    -1,
      13,     3,    33,    73,    55,    12,    35,    74,    72,    -1,
      15,    33,    55,    -1,    13,     3,     1,    38,    -1,    15,
       1,    55,    -1,    11,     7,    11,     5,     3,    -1,    11,
       7,    11,     6,     3,    -1,    11,     1,    11,     5,     3,
      -1,    11,     7,    11,     1,     3,    -1,    76,     8,    77,
      -1,    77,    -1,     1,    38,    -1,    77,     9,    78,    -1,
      78,    -1,    41,    36,    78,    37,    -1,    -1,    80,    79,
       4,    80,    -1,    80,     5,    81,    -1,    81,    -1,     1,
      38,    -1,    81,     6,    82,    -1,    82,    -1,     1,     6,
      81,    -1,    36,    80,    37,    -1,    11,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   104,   104,   105,   107,   108,   110,   110,
     111,   111,   113,   126,   129,   128,   144,   156,   158,   159,
     160,   162,   186,   188,   189,   191,   192,   217,   218,   219,
     220,   221,   223,   235,   245,   246,   248,   269,   271,   328,
     329,   331,   331,   331,   331,   332,   332,   332,   338,   338,
     338,   344,   344,   348,   349,   350,   352,   354,   356,   375,
     394,   407,   393,   414,   415,   416,   418,   456,   491,   492,
     494,   499,   500,   502,   507,   509,   511,   510,   766,   815,
     816,   818,   872,   873,   875,   876,   908
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "relop", "addop", "mulop",
  "assignop", "orop", "andop", "sentence", "id", "BREAK", "CASE", "CONST",
  "DEFAULT", "DO", "ELSE", "END", "FOR", "IF", "INT", "MAIN", "PRINT",
  "REAL", "READ", "START", "STRING", "SWITCH", "TILL", "THEN", "VAR",
  "WHILE", "':'", "','", "';'", "'('", "')'", "'\\n'", "'{'", "'}'", "'!'",
  "$accept", "program", "$@1", "$@2", "declarations", "declarlist", "$@3",
  "$@4", "decl", "list", "$@5", "type", "cdecl", "stmtlist", "stmt",
  "write_stmt", "read_stmt", "assignment_stmt", "control_stmt", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "stmt_block",
  "switch", "choice", "cases", "$@14", "$@15", "step", "boolexpr",
  "boolterm", "boolfactor", "$@16", "expression", "term", "factor", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    58,    44,    59,    40,    41,    10,   123,
     125,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    45,    43,    43,    46,    46,    48,    47,
      49,    47,    50,    50,    52,    51,    51,    51,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    61,    62,    63,    60,    64,    65,    60,    66,    67,
      60,    68,    60,    60,    60,    60,    69,    70,    71,    71,
      73,    74,    72,    72,    72,    72,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    79,    78,    80,    80,
      80,    81,    81,    81,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     1,     3,     0,     0,     3,
       0,     2,     3,     3,     0,     4,     2,     3,     1,     1,
       1,     7,     0,     2,     0,     1,     4,     4,     1,     1,
       1,     1,     5,     5,     5,     4,     5,     2,     4,     4,
       4,     0,     0,     0,    11,     0,     0,     7,     0,     0,
      10,     0,     7,     1,     2,     2,     3,     7,     1,     1,
       0,     0,     9,     3,     4,     3,     5,     5,     5,     5,
       3,     1,     2,     3,     1,     4,     0,     4,     3,     1,
       2,     3,     1,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     1,     2,     7,    10,     3,
      22,     0,    24,     0,     0,     6,    18,    19,    20,    11,
       0,     0,     0,     9,     0,     0,     0,     0,    51,     4,
       0,     0,     0,     0,     0,    45,    24,    23,    30,    29,
      25,    28,    31,    53,     0,     0,    13,    12,    55,    37,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    86,     0,    85,     0,
       0,    79,    82,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    71,    74,    76,     0,     0,     0,     0,    59,
      58,     0,     0,    56,     0,    17,     0,     0,    80,    27,
       0,     0,    39,     0,    40,    26,    38,     0,     0,     0,
       0,    72,     0,     0,    41,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    22,    15,     0,    83,    84,    78,
      81,     0,     0,     0,    70,     0,    73,     0,    34,    33,
      32,    36,     0,    46,    21,     0,    49,    75,     0,    77,
       0,     0,     0,     0,    52,     0,    42,     0,    24,    24,
      57,    47,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,    43,    64,    24,     0,     0,    50,     0,     0,
       0,     0,     0,     0,    44,     0,    68,    69,    66,    67,
      61,     0,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     7,    12,     9,    10,    14,    11,    19,    46,
      64,    20,    15,    21,    37,    38,    39,    40,    41,   135,
     164,   178,    59,   153,   110,   155,    53,    42,    43,    91,
     152,   174,   191,   163,    81,    82,    83,   116,    84,    71,
      72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
      54,   -87,    68,    27,    80,   -87,   -87,    89,   -87,   -87,
     171,   175,   -87,   175,   175,   -87,   -87,   -87,   -87,   -87,
      31,    96,   120,   -87,   123,   123,   153,   173,   -87,   -87,
     107,   110,   119,   127,   145,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   179,    16,   -87,   -87,   -87,   -87,
     -87,    25,   129,   167,   197,     7,   157,   198,    11,   174,
      14,   204,   123,   -87,   177,    75,   -87,   178,   -87,    20,
      35,   206,   -87,    57,   180,   137,   185,   183,   -87,    87,
     181,    21,   207,   -87,   213,    67,   182,    47,   184,   -87,
     -87,   186,     7,   -87,   187,   -87,   123,    97,   -87,   -87,
      72,    97,   -87,     2,   -87,   -87,   -87,   188,    20,   151,
       7,    63,     8,     8,   -87,     8,   216,   -87,   190,   191,
     192,   193,   194,    81,   215,   -87,   224,   -87,   -87,   206,
     -87,     7,   121,   195,   207,   201,   -87,    20,   -87,   -87,
     -87,   -87,   164,   -87,   -87,   139,   -87,   -87,   150,   213,
     231,   116,   200,   167,   -87,   225,   -87,   126,   -87,   -87,
     -87,   -87,   196,   202,   218,   203,   -87,    46,    71,   226,
     227,   150,   -87,   -87,   -87,   237,   199,   -87,   150,   125,
     240,   241,   242,   243,   -87,   212,   -87,   -87,   -87,   -87,
     -87,   164,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   234,   -21,
     -87,   236,   128,   -36,    23,   -87,   -87,   205,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -52,   -87,   -87,
      59,   -87,   -87,   -87,   -86,   138,   -32,   -87,   -49,   -85,
     152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -81
static const yytype_int16 yytable[] =
{
      60,    76,    70,    75,    47,    66,   123,    87,    79,    65,
      66,    66,   127,    68,    89,    26,   129,    62,    68,    68,
     100,    65,    90,    66,   132,    27,    65,     5,    66,   113,
      28,    68,    24,    30,    31,    67,    68,    32,    69,    33,
     101,    95,    34,    69,    69,   145,    35,    26,    80,    80,
     -14,    63,   101,    36,    93,     1,    69,    27,   114,    70,
      75,    69,    28,    97,    25,    30,    31,   -80,   -80,    32,
     102,    33,    26,    97,    34,   125,     2,   101,    35,     4,
     133,    97,    27,   136,   120,    36,   -65,    28,   149,   113,
      30,    31,   104,    97,    32,    98,    33,    26,   126,    34,
      66,   161,   117,    35,   118,    98,     6,    27,    68,   128,
      36,   -63,    28,    98,    29,    30,    31,   158,   143,    32,
       8,    33,   167,   168,    34,   111,    26,   165,    35,   113,
      73,    44,    66,    69,    45,    36,    27,   185,   179,    74,
      68,    28,   101,    54,    30,    31,    55,   113,    32,   159,
      33,    26,    73,    34,    66,    56,   146,    35,    85,   166,
      66,    27,    68,    57,    36,    69,    28,    86,    68,    30,
      31,   156,   106,    32,    51,    33,   154,   150,    34,   151,
      52,    58,    35,    48,   108,    13,    61,    69,    49,    36,
     109,    50,    -8,    69,   177,    -8,    16,   169,    -8,    17,
     181,   184,    18,   170,   182,   183,    36,    94,    77,    88,
      92,    96,   103,    99,   107,   105,   115,   112,   101,   119,
     137,   121,   124,   122,   131,   138,   139,   140,   141,    13,
      97,   148,   147,   142,   157,   172,   162,   175,   176,   171,
     160,   173,   180,   186,   187,   188,   189,   190,    23,    22,
     192,   134,   144,     0,     0,   130,     0,     0,     0,    78
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      36,    53,    51,    52,    25,     3,    92,    56,     1,     1,
       3,     3,    97,    11,     3,     1,   101,     1,    11,    11,
      69,     1,    11,     3,   110,    11,     1,     0,     3,     8,
      16,    11,     1,    19,    20,    10,    11,    23,    36,    25,
       5,    62,    28,    36,    36,   131,    32,     1,    41,    41,
      34,    35,     5,    39,    40,     1,    36,    11,    37,   108,
     109,    36,    16,     6,    33,    19,    20,     4,     5,    23,
      35,    25,     1,     6,    28,    96,    22,     5,    32,    11,
     112,     6,    11,   115,    37,    39,    40,    16,   137,     8,
      19,    20,    35,     6,    23,    38,    25,     1,     1,    28,
       3,   153,    35,    32,    37,    38,    26,    11,    11,    37,
      39,    40,    16,    38,    18,    19,    20,     1,    37,    23,
      31,    25,   158,   159,    28,    38,     1,     1,    32,     8,
       1,    11,     3,    36,    11,    39,    11,    12,   174,    10,
      11,    16,     5,    36,    19,    20,    36,     8,    23,    33,
      25,     1,     1,    28,     3,    36,    35,    32,     1,    33,
       3,    11,    11,    36,    39,    36,    16,    10,    11,    19,
      20,   148,    35,    23,     1,    25,    37,    13,    28,    15,
       7,    36,    32,    30,     1,    14,     7,    36,    35,    39,
       7,    38,    21,    36,   171,    24,    21,     1,    27,    24,
       1,   178,    27,     7,     5,     6,    39,     3,    11,    11,
      36,    34,     6,    35,    29,    35,     9,    36,     5,    37,
       4,    37,    35,    37,    36,    35,    35,    35,    35,    14,
       6,    30,    37,    39,     3,    17,    11,    11,    11,    37,
      40,    38,     5,     3,     3,     3,     3,    35,    14,    13,
     191,   113,   124,    -1,    -1,   103,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    22,    43,    11,     0,    26,    44,    31,    46,
      47,    49,    45,    14,    48,    54,    21,    24,    27,    50,
      53,    55,    53,    50,     1,    33,     1,    11,    16,    18,
      19,    20,    23,    25,    28,    32,    39,    56,    57,    58,
      59,    60,    69,    70,    11,    11,    51,    51,    30,    35,
      38,     1,     7,    68,    36,    36,    36,    36,    36,    64,
      55,     7,     1,    35,    52,     1,     3,    10,    11,    36,
      80,    81,    82,     1,    10,    80,    69,    11,    59,     1,
      41,    76,    77,    78,    80,     1,    10,    80,    11,     3,
      11,    71,    36,    40,     3,    51,    34,     6,    38,    35,
      80,     5,    35,     6,    35,    35,    35,    29,     1,     7,
      66,    38,    36,     8,    37,     9,    79,    35,    37,    37,
      37,    37,    37,    76,    35,    51,     1,    81,    37,    81,
      82,    36,    76,    78,    77,    61,    78,     4,    35,    35,
      35,    35,    39,    37,    54,    76,    35,    37,    30,    80,
      13,    15,    72,    65,    37,    67,    56,     3,     1,    33,
      40,    69,    11,    75,    62,     1,    33,    55,    55,     1,
       7,    37,    17,    38,    73,    11,    11,    56,    63,    55,
       5,     1,     5,     6,    56,    12,     3,     3,     3,     3,
      35,    74,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

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
      yychar = YYLEX;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 104 "cpm.y"
    { emit(tempOutHeader, "#Noam Hadad & Ofer Montano\n.data"); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 104 "cpm.y"
    { emit(tempOutBody, "\n.text"); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 105 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 110 "cpm.y"
    { numOfVar = 0; }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 111 "cpm.y"
    { numOfVar = 0; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 114 "cpm.y"
    {
							/* Iterate on the array and assign the type
								to the variables */
							symcpm* tempVar;
							while(numOfVar != -1)
							{
								tempVar = lookup(variablsTemp[numOfVar]);
								tempVar->type = (yyvsp[(1) - (3)].sval);
								emitDec(tempVar);
								free(variablsTemp[numOfVar--]);
							}
						}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 126 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 129 "cpm.y"
    {
							symcpm* tempVar = lookup((yyvsp[(1) - (1)].sval));
							if(tempVar->isDecleared)
							{
								gProg = false;
								mError(redef_e, tempVar, NULL);
							}
							tempVar->isDecleared = true;
							tempVar->isConst = false;
							
							/* Add variable name to an array to assign
								type to them later on */
							variablsTemp[numOfVar++] = strdup((yyvsp[(1) - (1)].sval));
						}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 145 "cpm.y"
    {
								symcpm* tempVar = lookup((yyvsp[(1) - (2)].sval));
								if(tempVar->isDecleared)
								{
									gProg = false;
									mError(redef_e, tempVar, NULL);
								}
								tempVar->isDecleared = true;
								tempVar->isConst = false;
								variablsTemp[numOfVar] = strdup((yyvsp[(1) - (2)].sval));
						  }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 156 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 158 "cpm.y"
    { (yyval.sval) = "int"; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 159 "cpm.y"
    { (yyval.sval) = "real"; }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 160 "cpm.y"
    { (yyval.sval) = "string"; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 163 "cpm.y"
    {
							symcpm* tempVar = lookup((yyvsp[(3) - (7)].sval));
							if(tempVar->isDecleared)
							{
								gProg = false;
								mError(redef_e, tempVar, NULL);
							}
							tempVar->isDecleared = true;
							tempVar->type = (yyvsp[(2) - (7)].sval);
							tempVar->isConst = true;

							/* If the variable has a type of string or he is int
								but the num is float- raise an error */
							if(!strcmp(tempVar->type, "string") || (!strcmp(tempVar->type, "int") && (yyvsp[(5) - (7)].nval).type == F))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar, "real");
							}
							if((yyvsp[(5) - (7)].nval).type == F)
								tempVar->value.rval = (yyvsp[(5) - (7)].nval).fval;
							else
								tempVar->value.ival = (yyvsp[(5) - (7)].nval).ival;
							emitDec(tempVar);
						}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 193 "cpm.y"
    {
								symcpm* tempVar = lookup((yyvsp[(1) - (4)].sval));
								if(!tempVar->isDecleared)
								{
									gProg = false;
									mError(undec_e, tempVar, NULL);
								}
								else if(strcmp(tempVar->type, "string"))
								{
									gProg = false;
									mError(typesmismtch_e, tempVar, "string");
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									sprintf(s, "sentc%d: .asciiz %s", numOfSent, (yyvsp[(3) - (4)].sval));
									emit(tempOutHeader, s);
									sprintf(s, "li $t0, 0\nlb $t1, sentc%d($t0)\nloop%d:\n\tsb $t1, %s($t0)\n\taddi $t0, $t0, 1\n\tlb $t1, sentc%d($t0)\n\tbne $t1, \'\\0\', loop%d", numOfSent, numOfLoops, tempVar->name, numOfSent, numOfLoops);
									numOfSent++;
									numOfLoops++;
									emit(tempOutBody, s);
									free(s);
								}
						  }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 217 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 224 "cpm.y"
    {
							char* s = (char *) malloc(sizeof(char) * 256);
							if((yyvsp[(3) - (5)].nval).type == I)
									sprintf(s, "li $v0, 1\nmove $a0, $t%d\nsyscall", iRegs - 1);
							else if((yyvsp[(3) - (5)].nval).type == F)
								sprintf(s, "li $v0, 2\nmov.s $f12, $f%d\nsyscall", fRegs - 1);
							else
								sprintf(s, "li $v0, 4\nsyscall");
							emit(tempOutBody, s);
							free(s);
						}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 236 "cpm.y"
    {
								char* s = (char *) malloc(sizeof(char) * 256);
								sprintf(s, "sentc%d: .asciiz %s", numOfSent, (yyvsp[(3) - (5)].sval));
								emit(tempOutHeader, s);
								sprintf(s, "li $v0, 4\nla $a0, sentc%d\nsyscall", numOfSent);
								numOfSent++;
								emit(tempOutBody, s);
								free(s);
						  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 245 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 246 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 249 "cpm.y"
    {
							symcpm* tempVar = lookup((yyvsp[(3) - (5)].sval));
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}
							else
							{
								char* s = (char*) malloc(sizeof(char)* 256);
								if(!strcmp(tempVar->type, "int"))
									sprintf(s, "li $v0, 5\nsyscall\nsw $v0, %s", tempVar->name);
								else if(!strcmp(tempVar->type, "real"))
									sprintf(s, "li $v0, 6\nsyscall\ns.s $f0, %s", tempVar->name);
								else
									sprintf(s, "li $v0, 8\nla $a0, %s\nli $a1, 256\nsyscall", tempVar->name);
								emit(tempOutBody, s);
								free(s);
							}
						}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 269 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 272 "cpm.y"
    {
							symcpm* tempVar = lookup((yyvsp[(1) - (4)].sval));
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}

							/* If the variable or the expression is string and the other
								one is not, raise an error */
							else if((!strcmp(tempVar->type, "string") && (yyvsp[(3) - (4)].nval).type != S) || (strcmp(tempVar->type, "string") && (yyvsp[(3) - (4)].nval).type == S))
							{
									gProg = false;
									mError(typesmismtch_e, tempVar, "string");
							}
							else if(!strcmp(tempVar->type, "int") && (yyvsp[(3) - (4)].nval).type == F)
							{
								gProg = false;
								mError(typesmismtch_e, tempVar, "real");
							}

							// If it is a const variable, raise an error
							else if(tempVar->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar, NULL);
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if(!strcmp(tempVar->type, "int") && (yyvsp[(3) - (4)].nval).type == I)
								{
									sprintf(s, "sw $t%d, %s", iRegs - 1, tempVar->name);
									iRegs--;
								}
								else if(!strcmp(tempVar->type, "real") && (yyvsp[(3) - (4)].nval).type == F)
								{
									sprintf(s, "s.s $f%d, %s", fRegs - 1, tempVar->name);
									fRegs--;
								}
								else if(!strcmp(tempVar->type, "real") && (yyvsp[(3) - (4)].nval).type == I)
								{
									sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\ns.s $f%d, %s", iRegs - 1, fRegs - 1, fRegs - 1, fRegs - 1, fRegs - 1, tempVar->name);
									iRegs--;
									fRegs--;
								}
								else
								{
									sprintf(s, "la $t%d, %s\nloop%d:\nlb $t%d, 0($a0)\nsb $t%d, 0($t%d)\naddi $a0, $a0, 1\naddi $t%d, $t%d, 1\nbne $t%d, \'\\0\', loop%d",
									iRegs, tempVar->name, numOfLoops, iRegs + 1, iRegs + 1, iRegs, iRegs, iRegs, iRegs + 1, numOfLoops);
									numOfLoops++;
								}
								emit(tempOutBody, s);
								free(s);
							}
						}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 328 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 329 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 331 "cpm.y"
    { fprintf(tempOutBody, "beq $t%d, $0, ELSE%d\n", iRegs - 1, numOfIf++); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 331 "cpm.y"
    { fprintf(tempOutBody, "j L%d\n", numOfJ); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 331 "cpm.y"
    { fprintf(tempOutBody, "ELSE%d:\n", --numOfIf); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 331 "cpm.y"
    { fprintf(tempOutBody, "L%d:\n", numOfJ++); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 332 "cpm.y"
    { fprintf(tempOutBody, "wLoop%d:\n", numOfW); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 332 "cpm.y"
    { fprintf(tempOutBody, "beq $t%d, $0, ewLoop%d\n", iRegs - 1, numOfW++); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 334 "cpm.y"
    { 
								numOfW--;
								fprintf(tempOutBody, "j wLoop%d\newLoop%d:\n", numOfW, numOfW);
						  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 338 "cpm.y"
    { fprintf(tempOutBody, "fLoop%d:\n", numOfFor); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 338 "cpm.y"
    { fprintf(tempOutBody, "beq $t%d, $0, efLoop%d\n", iRegs - 1, numOfFor++); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 339 "cpm.y"
    { 
								emit(tempOutBody, (yyvsp[(8) - (10)].sval));
								numOfFor--;
								fprintf(tempOutBody, "j fLoop%d\nefLoop%d:\n", numOfFor, numOfFor);
						  }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 344 "cpm.y"
    { fprintf(tempOutBody, "dLoop%d:\n", numOfDW++); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 345 "cpm.y"
    {
								fprintf(tempOutBody, "bne $t%d, $0, dLoop%d\n", iRegs - 1, --numOfDW);
						  }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 349 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 350 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 357 "cpm.y"
    {
							symcpm* tempVar = lookup((yyvsp[(1) - (1)].sval));
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}
							if(!strcmp(tempVar->type, "string") || !strcmp(tempVar->type, "real"))
							{
								gProg = false;
								mError(swexpr_e, NULL, "float/string");
							}
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "lw $t%d, %s", iRegs, (yyvsp[(1) - (1)].sval));
							iRegs++;
							emit(tempOutBody, s);
							free(s);
						}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 376 "cpm.y"
    {
								// The choice cant be from type float
								if((yyvsp[(1) - (1)].nval).type == F)
								{
									gProg = false;
									mError(swexpr_e, NULL, "float");
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									snprintf(s, 256, "li $t%d, %d", iRegs, (yyvsp[(1) - (1)].nval).ival);
									iRegs++;
									emit(tempOutBody, s);
									free(s);
								}
						  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 394 "cpm.y"
    {
							if((yyvsp[(2) - (3)].nval).type == F)
							{
								gProg = false;
								mError(swexpr_e, NULL, "float");
							}
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "li $t%d, %d\nbne $t%d, $t%d, C%d_COND", iRegs, (yyvsp[(2) - (3)].nval).ival, iRegs - 1, iRegs, numOfCond);
							iRegs--;
							emit(tempOutBody, s);
							free(s);
						}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 407 "cpm.y"
    {
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "j eSwtch%d\nC%d_COND:", numOfSw, numOfCond++);
							emit(tempOutBody, s);
							free(s);
						}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 414 "cpm.y"
    { fprintf(tempOutBody, "eSwtch%d:\n", numOfSw++); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 415 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 416 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 419 "cpm.y"
    {
							symcpm* tempVar1 = lookup((yyvsp[(1) - (5)].sval));
							symcpm* tempVar2 = lookup((yyvsp[(3) - (5)].sval));

							/* If one of the variables is not declared or is a string
								or left side is const, raise an error */
							if(!tempVar1->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar1, NULL);
							}
							if(!tempVar2->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar2, NULL);
							}
							if(!strcmp(tempVar1->type, "string") || (!strcmp(tempVar1->type, "int") && strcmp(tempVar2->type, "int")))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar1, tempVar2->type);
							}
							if(tempVar1->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar1, NULL);
							}
							(yyval.sval) = (char *) malloc(sizeof(char) * 256);
							char* s = (char *) malloc(sizeof(char) * 256);
							sprintf((yyval.sval), "li $t%d, %d\nlw $t%d, %s\n", iRegs, (yyvsp[(5) - (5)].nval).ival, iRegs + 1, tempVar2->name);
							if((yyvsp[(4) - (5)].op) == PLUS)
								sprintf(s, "add $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, (yyvsp[(1) - (5)].sval));
							else
								sprintf(s, "sub $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, (yyvsp[(1) - (5)].sval));
							iRegs--;
							strcat((yyval.sval), s);
							free(s);
					   }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 457 "cpm.y"
    {
							symcpm* tempVar1 = lookup((yyvsp[(1) - (5)].sval));
							symcpm* tempVar2 = lookup((yyvsp[(3) - (5)].sval));
							if(!tempVar1->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar1, NULL);
							}
							if(!tempVar2->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar2, NULL);
							}
							if(!strcmp(tempVar1->type, "string") || (!strcmp(tempVar1->type, "int") && strcmp(tempVar2->type, "int")))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar1, tempVar2->type);
							}
							if(tempVar1->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar1, NULL);
							}
							(yyval.sval) = (char *) malloc(sizeof(char) * 256);
							char* s = (char *) malloc(sizeof(char) * 256);
							sprintf((yyval.sval), "li $t%d, %d\nlw $t%d, %s\n", iRegs, (yyvsp[(5) - (5)].nval).ival, iRegs + 1, tempVar2->name);
							if((yyvsp[(4) - (5)].op) == MUL)
								sprintf(s, "mul $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, (yyvsp[(1) - (5)].sval));
							else
								sprintf(s, "div $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, (yyvsp[(1) - (5)].sval));
							iRegs--;
							strcat((yyval.sval), s);
							free(s);
						  }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 491 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 492 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 495 "cpm.y"
    {
							fprintf(tempOutBody, "or $t%d, $t%d, $t%d\n", iRegs - 2, iRegs - 2, iRegs - 1);
							iRegs--;
						}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 500 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 503 "cpm.y"
    {	
							fprintf(tempOutBody, "and $t%d, $t%d, $t%d\n", iRegs - 2, iRegs - 2, iRegs - 1);
							iRegs--;
						}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 509 "cpm.y"
    { fprintf(tempOutBody, "xori $t%d, $t%d, 1\n", iRegs - 1, iRegs - 1); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 511 "cpm.y"
    {
								/* If the expression is a string, in this point it means
									that its in $a0. Because we relop between two expressions
									if the other expression is also a string, 
									we need to move that value to another register. */
								if((yyvsp[(1) - (1)].nval).type == S)
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									sprintf(s, "move $t%d, $a0", iRegs);
									iRegs++;
									emit(tempOutBody, s);
									free(s);
								}
						  }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 526 "cpm.y"
    {
								char* s = (char *) malloc(sizeof(char) * 256);
								switch((yyvsp[(3) - (4)].op))
								{
									case EQUAL:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{

											/* We divided the sprintf to a couple of statements only
												because it is more readable and easy to track the arguments */
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "seq $t%d, $t%d, $t%d\nbeq $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nseq $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);											
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "==");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "seq $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
											{
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nseq $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											}
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nseq $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case NOT_EQUAL:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sne $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);		
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "!=");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "sne $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsne $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsne $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}		
									break;
									case LESS:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "slt $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nslt $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nslt $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case GREATER_EQUAL:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs + 1, numOfLoops, iRegs + 2, iRegs, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<=");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "sge $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsge $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsge $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case MORE:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs + 1, numOfLoops, iRegs + 2, iRegs, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, ">");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "sgt $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsgt $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsgt $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case LESS_EQUAL:
										if((yyvsp[(1) - (4)].nval).type == S && (yyvsp[(4) - (4)].nval).type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "slt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if((yyvsp[(1) - (4)].nval).type == S || (yyvsp[(4) - (4)].nval).type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<=");
										}
										else
										{
											if((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == I)
											{
												sprintf(s, "sle $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(((yyvsp[(1) - (4)].nval).type == I && (yyvsp[(4) - (4)].nval).type == F) || ((yyvsp[(1) - (4)].nval).type == F && (yyvsp[(4) - (4)].nval).type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsle $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsle $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
								}
						  }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 767 "cpm.y"
    {
							(yyval.nval).type = F;
							if((yyvsp[(1) - (3)].nval).type == S || (yyvsp[(3) - (3)].nval).type == S)
							{
									gProg = false;
									mError(opermismtch_e, NULL, "+/-");
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if((yyvsp[(2) - (3)].op) == PLUS)
								{
									if((yyvsp[(1) - (3)].nval).type == F && (yyvsp[(3) - (3)].nval).type == F)
									{
										sprintf(s, "add.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if((yyvsp[(1) - (3)].nval).type == F || (yyvsp[(3) - (3)].nval).type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nadd.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										(yyval.nval).type = I;
										sprintf(s, "add $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}
								else
								{
									if((yyvsp[(1) - (3)].nval).type == F && (yyvsp[(3) - (3)].nval).type == F)
									{
										sprintf(s, "sub.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if((yyvsp[(1) - (3)].nval).type == F || (yyvsp[(3) - (3)].nval).type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										(yyval.nval).type = I;
										sprintf(s, "sub $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}
							}
						}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 815 "cpm.y"
    { (yyval.nval).type = (yyvsp[(1) - (1)].nval).type; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 816 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 819 "cpm.y"
    {
							(yyval.nval).type = F;
							if((yyvsp[(1) - (3)].nval).type == S || (yyvsp[(3) - (3)].nval).type == S)
							{
									gProg = false;
									mError(opermismtch_e, NULL, "*//");
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if((yyvsp[(2) - (3)].op) == MUL)
								{
									if((yyvsp[(1) - (3)].nval).type == F && (yyvsp[(3) - (3)].nval).type == F)
									{
										sprintf(s, "mul.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if((yyvsp[(1) - (3)].nval).type == F || (yyvsp[(3) - (3)].nval).type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nmul.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										(yyval.nval).type = I;
										sprintf(s, "mul $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}	
								else if(((yyvsp[(3) - (3)].nval).type == F && !(yyvsp[(3) - (3)].nval).fval) || ((yyvsp[(3) - (3)].nval).type == I && !(yyvsp[(3) - (3)].nval).ival))
								{
										gProg = false;
										mError(zero_e, NULL, NULL);
								}
								else
								{
									if((yyvsp[(1) - (3)].nval).type == F && (yyvsp[(3) - (3)].nval).type == F)
									{
										sprintf(s, "div.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if((yyvsp[(1) - (3)].nval).type == F || (yyvsp[(3) - (3)].nval).type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\ndiv.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										sprintf(s, "div $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
										(yyval.nval).type = I;
									}
									emit(tempOutBody, s);
									free(s);
								}
							}	
						}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 872 "cpm.y"
    { (yyval.nval).type = (yyvsp[(1) - (1)].nval).type; }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 873 "cpm.y"
    {gProg=false; yyerrok;}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 875 "cpm.y"
    { (yyval.nval).type = (yyvsp[(2) - (3)].nval).type; }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 877 "cpm.y"
    {
								symcpm* tempVar = lookup((yyvsp[(1) - (1)].sval));
								if(!tempVar->isDecleared)
								{
									gProg = false;
									mError(undec_e, tempVar, NULL);
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									if(!strcmp(tempVar->type, "real"))
									{
										sprintf(s, "l.s $f%d, %s", fRegs, (yyvsp[(1) - (1)].sval));
										fRegs++;
										(yyval.nval).type = F;
									}
									else if(!strcmp(tempVar->type, "int"))
									{
										sprintf(s, "lw $t%d, %s", iRegs, (yyvsp[(1) - (1)].sval));
										iRegs++;
										(yyval.nval).type = I;
									}
									else
									{
										sprintf(s, "la $a0, %s", (yyvsp[(1) - (1)].sval));
										(yyval.nval).type = S;
									}
									emit(tempOutBody, s);
									free(s);
								}
						  }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 909 "cpm.y"
    {
								char* s = (char *) malloc(sizeof(char) * 256);
								if((yyvsp[(1) - (1)].nval).type == F)
								{
									//sprintf(s, "tempF%d: .float %.2f", numOfTemps, $1.fval);
									//emit(tempOutHeader, s);
									sprintf(s, "tempF%d: .float %.2f\nl.s $f%d, tempF%d", numOfTemps, (yyvsp[(1) - (1)].nval).fval, fRegs, numOfTemps);
									numOfTemps++;
									fRegs++;
								}
								else
								{
									sprintf(s, "li $t%d, %d", iRegs, (yyvsp[(1) - (1)].nval).ival);
									iRegs++;
								}
								(yyval.nval).type = (yyvsp[(1) - (1)].nval).type;
								emit(tempOutBody, s);
								free(s);
						  }
    break;


/* Line 1792 of yacc.c  */
#line 2750 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 929 "cpm.y"


int main(int argc, char* argv[])
{

	// Check if user entered enough parameters
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "Please provide an input file!");
		return 1;
	}
	char** inputFile = strsplit(argv[1], ".");

	// Check if the input file is of type cpl or CPL
	if(!inputFile || strcmp(strlwr(inputFile[1]), "cpl"))
	{
		free(inputFile);
		fprintf(stderr, "%s\n", "Please provide a .cpl or .CPL file!");
		return 1;
	}
	extern FILE* yyin, *yyout;
	errorsLog = fopen("errorsLog.txt", "w+");
	yyin = fopen(argv[1], "r");
	char* fileName = strtok(argv[1], ".");
	strcat(fileName, ".lst");
	yyout = fopen(fileName, "w");

	/* Open one file for mips .text instructions
		and one file for .data instructions */
	tempOutBody = fopen("tempOutBody.txt", "w+");
	tempOutHeader = fopen("tempOutHeader.txt", "w+");
	
	// Check if one of the files didnt opened correctly
	if(!errorsLog || !yyin || !yyout || !tempOutBody || !tempOutHeader)
	{
		free(fileName);
		free(inputFile);
		fclose(yyin);
		fclose(yyout);
		fclose(errorsLog);
		fclose(tempOutBody);
		remove("errorsLog.txt");
		remove("tempOutBody.txt");
		fprintf(stderr, "%s\n", "Unexpected open file error!");
		return 1;
	}

	fprintf(yyout, "Noam Hadad & Ofer Montano\n%d: ", 1);

	// Initialize a list of symbol tables
	listOfSymTbl = (symTbl*) malloc(sizeof(symTbl));
	listOfSymTbl->nextSymTbl = NULL;

	yyparse();

	// Copy errors occurred during parsing
	rewind(errorsLog);
	char ch = fgetc(errorsLog);
	while (ch != EOF)
   {
		fputc(ch, yyout);
      ch = fgetc(errorsLog);
   }
	
	/* open a final mips file, copy the data and text instructions 
		to that file and delete the other files */
	strcpy(fileName, inputFile[0]);
	strcat(fileName, ".s");
	mipsOut = fopen(fileName, "w");
	if(!mipsOut)
	{
		free(fileName);
		free(inputFile);
		fclose(yyin);
		fclose(yyout);
		fclose(errorsLog);
		fclose(tempOutBody);
		fclose(tempOutHeader);
		remove("errorsLog.txt");
		remove("tempOutBody.txt");
		remove("tempOutHeader.txt");
		fprintf(stderr, "%s\n", "Unexpected open file error!");
		return 1;
	}
	rewind(tempOutHeader);
	rewind(tempOutBody);
	ch = fgetc(tempOutHeader);
	while (ch != EOF)
   {
		fputc(ch, mipsOut);
      ch = fgetc(tempOutHeader);
   }
	ch = fgetc(tempOutBody);
	while (ch != EOF)
   {
		fputc(ch, mipsOut);
      ch = fgetc(tempOutBody);
   }

	fprintf(stderr, "Noam Hadad & Ofer Montano");

	// Cleanup
	freeSymbolTable();
	fclose(errorsLog);
	fclose(tempOutBody);
	fclose(tempOutHeader);
	fclose(yyin);
	fclose(yyout);
	fclose(mipsOut);
	if(!gProg)
		remove(fileName);
	free(fileName);
	free(inputFile);
   remove("errorsLog.txt");
	remove("tempOutBody.txt");
	remove("tempOutHeader.txt");
	return 0;
}

/* This function responsible for printing the instructions to the
	different files, according to the "file" argument */
void emit(FILE* file, const char* str)
{
	fprintf(file,"%s\n", str);
}

void freeSymbolTable()
{
	int scount;
	symcpm* sp;
	while(listOfSymTbl)
	{
		scount = NHASH;
		sp = listOfSymTbl->symTblScope;
		while(--scount >= 0)
		{
			if(sp->name)
				free(sp->name);
		}
		listOfSymTbl = listOfSymTbl->nextSymTbl;
	}
}

/* This function responsible for printing instructions to .data
	file, specifically variables declarations */
void emitDec(const symcpm* tempVar)
{
	char* s = (char*) malloc(sizeof(char)* 256);
	if(!strcmp(tempVar->type, "int"))
		sprintf(s, "%s: .word %d", tempVar->name, tempVar->value.ival);
	else if(!strcmp(tempVar->type, "real"))
		sprintf(s, "%s: .float %.2f", tempVar->name, tempVar->value.rval);
	else
		sprintf(s, "%s: .space %d", tempVar->name, 256);
	emit(tempOutHeader, s);
	free(s);
}

/* This function responsible for printing lexical and parsing errors */
void yyerror(const char* str)
{
	char** errorMsg = strsplit(str, " ");
	if(!errorMsg)
		return;
	fprintf(errorsLog,"\nERROR line %d, column %d: Expected %s, found %s instead.", yylineno, column, errorMsg[5], strsplit(errorMsg[3], ",")[0]);
	free(errorMsg);
}

/* This function responsible for printing runtime errors */
void mError(const int typeOfError, const symcpm* var, const char* str)
{
	switch(typeOfError)
	{
		case redef_e:
			fprintf(errorsLog,"\nERROR \'%s %s\': redefinition. (line %d)", var->type, var->name, yylineno);
		break;
		case typesmismtch_e:
			fprintf(errorsLog,"\nERROR \':=\': types mismatch from %s to %s. (line %d)", str, var->type, yylineno);
		break;
		case undec_e:
			fprintf(errorsLog,"\nERROR \'%s\': undeclared identifier. (line %d)", var->name, yylineno);
		break;
		case argsmismtch_e:
			fprintf(errorsLog,"\nERROR \'%s\':  cannot convert argument from \'string\' to \'%s\'. (line %d)", str, var->type, yylineno);
		break;
		case zero_e:
			fprintf(errorsLog,"\nERROR: devide or mod by zero. (line %d)", yylineno);
		break;
		case opermismtch_e:
			fprintf(errorsLog,"\nERROR \'%s\': operator not defined for type \'string\'. (line %d)", str, yylineno);
		break;
		case constasgn_e:
			fprintf(errorsLog,"\nERROR \'%s\': you cannot assign to a variable that is const. (line %d)", var->name, yylineno);
		break;
		case swexpr_e:
			fprintf(errorsLog,"\nERROR : a switch expression of type \'%s\' is not valid. (line %d)", str, yylineno);
		break;
	}
}

/* This function responsible for assigning a unique index for
	variables in the symbol tables */
static unsigned symhash(char* sym)
{
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++)
		hash = hash * 9 ^ c;
	return hash;
}

/* This function responsible for searching variables in the
	list of symbol tables, if the variable does not exists
	it enters it to the symbol table */
symcpm* lookup(char* sym)
{
	symTbl* tempList = listOfSymTbl;
	symcpm* sp;
	int scount;
	while(tempList)
	{
		sp = &tempList->symTblScope[symhash(sym) % NHASH];
		scount = NHASH;
		while(--scount >= 0)
		{
			if(sp->name && !strcmp(sp->name, sym))
				return sp;
			if(!sp->name)
			{
				sp->name = strdup(sym);
				sp->isDecleared = false;
				return sp;
			}
			if(++sp >= tempList->symTblScope + NHASH)
				sp = tempList->symTblScope;
		}
		tempList = tempList->nextSymTbl;
	}
	fprintf(stderr, "%s\n", "symbol table overflow");
	abort();
}

/* This function responsible for splitting strings */
static char** _strsplit(const char* s, const char* delim, size_t* nb)
{
	void* data;
	char* _s = (char*)s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while((_s = strstr(_s, delim)))
	{
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = (nbWords + 1) * sizeof(char*);
	ptrs = data = malloc(ptrsSize + sLen + 1);
	if(data)
	{
		*ptrs = _s = strcpy(((char*)data) + ptrsSize, s);
		if(nbWords > 1)
		{
			while((_s = strstr(_s, delim)))
			{
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	if(nb)
	{
		*nb = data ? nbWords : 0;
	}
	return data;
}

/* This function responsible for splitting strings */
char** strsplit(const char* s, const char* delim)
{
	return _strsplit(s, delim, NULL);
}