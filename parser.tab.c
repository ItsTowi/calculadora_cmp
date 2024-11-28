/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXLEN 100
#define SENTENCE_MAX_LENGTH 50

extern FILE *yyout;
extern int yylineno;
extern int yylex();
char *sentenciasC3A[MAXLEN];
int num_temportales = 1;
int sig_linea=1;
char* nou_temporal();
void addToMatrix(int args_count, ...);
void print_sentences();
/*extern void yyerror(char*);*/


#line 93 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_ONELINECMNT = 4,                /* ONELINECMNT  */
  YYSYMBOL_MULTILINECMNT = 5,              /* MULTILINECMNT  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_EOL = 7,                        /* EOL  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_A_ID = 9,                       /* A_ID  */
  YYSYMBOL_B_ID = 10,                      /* B_ID  */
  YYSYMBOL_INTEGER = 11,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_BOOLEAN = 14,                   /* BOOLEAN  */
  YYSYMBOL_PI = 15,                        /* PI  */
  YYSYMBOL_E = 16,                         /* E  */
  YYSYMBOL_ADD = 17,                       /* ADD  */
  YYSYMBOL_SUB = 18,                       /* SUB  */
  YYSYMBOL_MULT = 19,                      /* MULT  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_MOD = 21,                       /* MOD  */
  YYSYMBOL_POW = 22,                       /* POW  */
  YYSYMBOL_SIN = 23,                       /* SIN  */
  YYSYMBOL_COS = 24,                       /* COS  */
  YYSYMBOL_TAN = 25,                       /* TAN  */
  YYSYMBOL_LEN = 26,                       /* LEN  */
  YYSYMBOL_SUBSTR = 27,                    /* SUBSTR  */
  YYSYMBOL_BIN = 28,                       /* BIN  */
  YYSYMBOL_HEX = 29,                       /* HEX  */
  YYSYMBOL_OCT = 30,                       /* OCT  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_OPRELACIONAL = 34,              /* OPRELACIONAL  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_lista_declaraciones = 39,       /* lista_declaraciones  */
  YYSYMBOL_declaracion = 40,               /* declaracion  */
  YYSYMBOL_exp = 41,                       /* exp  */
  YYSYMBOL_aritmetica = 42,                /* aritmetica  */
  YYSYMBOL_termino = 43,                   /* termino  */
  YYSYMBOL_factor = 44,                    /* factor  */
  YYSYMBOL_primario = 45,                  /* primario  */
  YYSYMBOL_op_trig = 46,                   /* op_trig  */
  YYSYMBOL_representacioNum = 47,          /* representacioNum  */
  YYSYMBOL_booleana = 48,                  /* booleana  */
  YYSYMBOL_bool1 = 49,                     /* bool1  */
  YYSYMBOL_bool2 = 50,                     /* bool2  */
  YYSYMBOL_bool3 = 51,                     /* bool3  */
  YYSYMBOL_bool_aritmetic = 52             /* bool_aritmetic  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 34 "parser.y"

 void sumaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);

#line 184 "parser.tab.c"


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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    50,    50,    52,    67,    78,    82,    86,
      86,    88,    88,    93,    97,    98,   100,   100,   103,   106,
     110,   111,   115,   119,   122,   126,   129,   132,   143,   154,
     157,   158,   159,   160,   162,   162,   162,   164,   164,   164,
     166,   167,   171,   172,   176,   177,   181,   182,   185,   188,
     200
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN",
  "ONELINECMNT", "MULTILINECMNT", "COMMA", "EOL", "ID", "A_ID", "B_ID",
  "INTEGER", "FLOAT", "STRING", "BOOLEAN", "PI", "E", "ADD", "SUB", "MULT",
  "DIV", "MOD", "POW", "SIN", "COS", "TAN", "LEN", "SUBSTR", "BIN", "HEX",
  "OCT", "AND", "OR", "NOT", "OPRELACIONAL", "LPAREN", "RPAREN", "$accept",
  "programa", "lista_declaraciones", "declaracion", "exp", "aritmetica",
  "termino", "factor", "primario", "op_trig", "representacioNum",
  "booleana", "bool1", "bool2", "bool3", "bool_aritmetic", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,   -34,   -34,    15,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   126,   126,   -34,   -34,   -34,   -33,     4,   -34,
     -34,   -34,    73,    73,    21,    45,   -34,    23,    -9,    46,
      10,   -34,    12,    29,    -6,     3,   -34,   -34,   -34,    73,
     -34,   101,    46,    46,   101,   101,    -9,   -34,   -14,   -13,
     -34,   -34,   -34,   126,   126,   101,   126,   126,   126,   126,
     101,   101,    73,    73,    69,    -7,    -5,    34,   -34,   -34,
      46,    46,    19,    10,    10,    10,   -34,    -3,    -1,     3,
     -34,   -34,   -34,    66,   -34,   -34,    89,    68,    71,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     8,    27,    28,    49,    22,    23,    24,    48,
      25,    26,     0,     0,    34,    35,    36,     0,     0,    37,
      38,    39,     0,     0,     0,     2,     4,     0,     9,    11,
      16,    20,     0,     0,    10,    40,    42,    44,    46,     0,
      27,     0,    15,    14,     0,     0,     0,    45,     0,     0,
       1,     3,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    47,
      12,    13,    50,    17,    18,    19,    21,     0,     0,    41,
      43,     5,    31,     0,    30,    33,     0,     0,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,    79,    72,   -17,   -12,    36,    56,   -34,
     -34,    82,    58,   -15,   -34,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    43,    44,    53,    54,    46,    48,    47,    53,    54,
      53,    54,    53,    54,    53,    54,    53,    54,    39,    62,
      55,    50,    68,    69,    65,    55,    62,    66,    67,    68,
      52,    82,    59,    84,    63,    85,    53,    54,    72,    45,
      83,    70,    71,    77,    78,    46,    46,    60,    80,     1,
       2,    53,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    61,    56,    57,    58,    14,    15,
      16,    17,    18,    19,    20,    21,    81,    86,    22,    88,
      23,    40,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    73,    74,    75,    87,    14,    15,    16,    17,
      18,    19,    20,    21,    51,    49,    22,    89,    23,    40,
       4,    64,     6,     7,     8,    76,    10,    11,    12,    13,
      79,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,    40,     4,    41,     6,     7,     8,
       0,    10,    11,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,    41
};

static const yytype_int8 yycheck[] =
{
      12,    13,    35,    17,    18,    22,    23,    22,    17,    18,
      17,    18,    17,    18,    17,    18,    17,    18,     3,    32,
      34,     0,    36,    36,    41,    34,    32,    44,    45,    36,
       7,    36,    22,    36,    31,    36,    17,    18,    55,    35,
       6,    53,    54,    60,    61,    62,    63,    35,    63,     4,
       5,    17,    18,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    35,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,     7,    11,    33,    11,
      35,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    56,    57,    58,     6,    23,    24,    25,    26,
      27,    28,    29,    30,    25,    23,    33,    36,    35,     8,
       9,    39,    11,    12,    13,    59,    15,    16,    17,    18,
      62,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,     8,     9,    35,    11,    12,    13,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    23,    24,    25,    26,    27,    28,
      29,    30,    33,    35,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     3,
       8,    35,    43,    43,    35,    35,    42,    50,    42,    48,
       0,    40,     7,    17,    18,    34,    19,    20,    21,    22,
      35,    35,    32,    31,    41,    42,    42,    42,    36,    36,
      43,    43,    42,    44,    44,    44,    45,    42,    42,    49,
      50,     7,    36,     6,    36,    36,    11,     6,    11,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    42,    42,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    46,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     2,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     1,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     8,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     1,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_declaraciones  */
#line 48 "parser.y"
                              {print_sentences();}
#line 1208 "parser.tab.c"
    break;

  case 5: /* declaracion: ID ASSIGN exp EOL  */
#line 52 "parser.y"
                               {
                                  //fprintf("Una expresión de tipo: %s\n", type_to_str($3.val_type));
                                  if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror((yyvsp[-1].expr_val).value.val_string);
                                  } 
                                  else 
                                  {
                                    (yyvsp[-3].expr_val).val_type = (yyvsp[-1].expr_val).val_type;
                                    if (!((yyvsp[-3].expr_val).name == NULL)) {
                                      sym_enter((yyvsp[-3].expr_val).name, &(yyvsp[-1].expr_val));
                                    }
                                    fprintf(yyout, "ID: %s pren amb tipus %s per valor: %s\n", (yyvsp[-3].expr_val).name, type_to_str((yyvsp[-3].expr_val).val_type) ,valueToString((yyvsp[-1].expr_val)));
                                  }
                                }
#line 1228 "parser.tab.c"
    break;

  case 6: /* declaracion: exp EOL  */
#line 67 "parser.y"
                                {
                                  if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE)
                                  {
                                    yyerror((yyvsp[-1].expr_val).value.val_string);
                                  }
                                  else
                                  {
                                    if ((yyvsp[-1].expr_val).name == NULL) fprintf(yyout, "Line %d, unsaved EXPRESSION with value %s and type %s\n", yylineno, valueToString((yyvsp[-1].expr_val)), type_to_str((yyvsp[-1].expr_val).val_type));
										                else fprintf(yyout, "Line %d, EXPRESSION %s with value %s and type %s\n", yylineno, (yyvsp[-1].expr_val).name, valueToString((yyvsp[-1].expr_val)), type_to_str((yyvsp[-1].expr_val).val_type));
                                  }
                                }
#line 1244 "parser.tab.c"
    break;

  case 7: /* declaracion: ONELINECMNT  */
#line 78 "parser.y"
                            {
                              fprintf(yyout, "COMENTARIO DE UNA LINEA EN LA LINEA %d\n", yylineno - 1);
                              //yylineno++;
                            }
#line 1253 "parser.tab.c"
    break;

  case 8: /* declaracion: MULTILINECMNT  */
#line 82 "parser.y"
                              {
                                fprintf(yyout, "COMENTARIO DE MULTIPLES LINEAS %d\n", yylineno - 1);
                              }
#line 1261 "parser.tab.c"
    break;

  case 12: /* aritmetica: aritmetica ADD termino  */
#line 88 "parser.y"
                                              {
                                                (yyval.expr_val) = sumaAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                                sumaArtimetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "+", (yyvsp[0].expr_val));

                                              }
#line 1271 "parser.tab.c"
    break;

  case 13: /* aritmetica: aritmetica SUB termino  */
#line 93 "parser.y"
                                              {
                                                (yyval.expr_val) = restaAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                                restaArtimetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "-", (yyvsp[0].expr_val));
                                              }
#line 1280 "parser.tab.c"
    break;

  case 14: /* aritmetica: SUB termino  */
#line 97 "parser.y"
                                              { (yyval.expr_val) = cambioAritmetica((yyvsp[0].expr_val)); }
#line 1286 "parser.tab.c"
    break;

  case 15: /* aritmetica: ADD termino  */
#line 98 "parser.y"
                                              { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1292 "parser.tab.c"
    break;

  case 17: /* termino: termino MULT factor  */
#line 100 "parser.y"
                                      {
                                        (yyval.expr_val) = multAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                      }
#line 1300 "parser.tab.c"
    break;

  case 18: /* termino: termino DIV factor  */
#line 103 "parser.y"
                                      {
                                        (yyval.expr_val) = divAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                      }
#line 1308 "parser.tab.c"
    break;

  case 19: /* termino: termino MOD factor  */
#line 106 "parser.y"
                                      {
                                        (yyval.expr_val) = modAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                      }
#line 1316 "parser.tab.c"
    break;

  case 21: /* factor: factor POW primario  */
#line 111 "parser.y"
                                       {
                                          (yyval.expr_val) = potAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                       }
#line 1324 "parser.tab.c"
    break;

  case 22: /* primario: INTEGER  */
#line 115 "parser.y"
                                      {
                                        (yyvsp[0].expr_val).name = NULL;
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1333 "parser.tab.c"
    break;

  case 23: /* primario: FLOAT  */
#line 119 "parser.y"
                                      {
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1341 "parser.tab.c"
    break;

  case 24: /* primario: STRING  */
#line 122 "parser.y"
                                      {
                                        printf("%s\n", type_to_str((yyvsp[0].expr_val).val_type));
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1350 "parser.tab.c"
    break;

  case 25: /* primario: PI  */
#line 126 "parser.y"
                                      {
                                        (yyval.expr_val) = constantePI();
                                      }
#line 1358 "parser.tab.c"
    break;

  case 26: /* primario: E  */
#line 129 "parser.y"
                                      {
                                        (yyval.expr_val) = constanteE();
                                      }
#line 1366 "parser.tab.c"
    break;

  case 27: /* primario: ID  */
#line 132 "parser.y"
                                      {
                                          if(sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND) 
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
												                  else 
                                          { 
                                            (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                            (yyval.expr_val).value =(yyvsp[0].expr_val).value;
                                          }
                                      }
#line 1382 "parser.tab.c"
    break;

  case 28: /* primario: A_ID  */
#line 143 "parser.y"
                                        {
                                          if(sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND) 
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
												                  else 
                                          {
                                            (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                            (yyval.expr_val).value =(yyvsp[0].expr_val).value;
                                          }
                                      }
#line 1398 "parser.tab.c"
    break;

  case 29: /* primario: LPAREN aritmetica RPAREN  */
#line 154 "parser.y"
                                      {
                                          (yyval.expr_val) = (yyvsp[-1].expr_val);
                                      }
#line 1406 "parser.tab.c"
    break;

  case 30: /* primario: op_trig LPAREN aritmetica RPAREN  */
#line 157 "parser.y"
                                             { (yyval.expr_val) = opTrigonometrica((yyvsp[-3].expr_val), (yyvsp[-1].expr_val)); }
#line 1412 "parser.tab.c"
    break;

  case 31: /* primario: LEN LPAREN aritmetica RPAREN  */
#line 158 "parser.y"
                                         { (yyval.expr_val) = calcularLen((yyvsp[-1].expr_val)); }
#line 1418 "parser.tab.c"
    break;

  case 32: /* primario: SUBSTR LPAREN aritmetica COMMA INTEGER COMMA INTEGER RPAREN  */
#line 159 "parser.y"
                                                                        { (yyval.expr_val) = substring((yyvsp[-5].expr_val), (yyvsp[-3].expr_val).value.val_int, (yyvsp[-1].expr_val).value.val_int); }
#line 1424 "parser.tab.c"
    break;

  case 33: /* primario: representacioNum LPAREN aritmetica RPAREN  */
#line 160 "parser.y"
                                                      { (yyval.expr_val) = representacioNum((yyvsp[-3].expr_val) ,(yyvsp[-1].expr_val)); }
#line 1430 "parser.tab.c"
    break;

  case 41: /* booleana: booleana OR bool1  */
#line 167 "parser.y"
                                      {
                                        (yyval.expr_val) = orBooleana((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                      }
#line 1438 "parser.tab.c"
    break;

  case 43: /* bool1: bool1 AND bool2  */
#line 172 "parser.y"
                                      {
                                        (yyval.expr_val) = andBooleana((yyvsp[-2].expr_val),(yyvsp[0].expr_val));
                                      }
#line 1446 "parser.tab.c"
    break;

  case 45: /* bool2: NOT bool2  */
#line 177 "parser.y"
                                      {
                                        (yyval.expr_val) = notBooleana((yyvsp[0].expr_val));
                                      }
#line 1454 "parser.tab.c"
    break;

  case 47: /* bool3: LPAREN booleana RPAREN  */
#line 182 "parser.y"
                                      {
                                        (yyval.expr_val) = (yyvsp[-1].expr_val);
                                      }
#line 1462 "parser.tab.c"
    break;

  case 48: /* bool3: BOOLEAN  */
#line 185 "parser.y"
                                      {
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1470 "parser.tab.c"
    break;

  case 49: /* bool3: B_ID  */
#line 188 "parser.y"
                                      {
                                        if (sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND)
                                        {
                                          yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n");
                                        }
                                        else
                                        {
                                          (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                          (yyval.expr_val).value = (yyvsp[0].expr_val).value;
                                        }
                                      }
#line 1486 "parser.tab.c"
    break;

  case 50: /* bool_aritmetic: aritmetica OPRELACIONAL aritmetica  */
#line 200 "parser.y"
                                                    {
                                                      //printf("%s\n", valueToString($1));
                                                      //printf("%d\n", $3.value.val_int);
                                                      (yyval.expr_val) = opRelacional((yyvsp[-2].expr_val),(yyvsp[-1].expr_val),(yyvsp[0].expr_val));
                                                    }
#line 1496 "parser.tab.c"
    break;


#line 1500 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 206 "parser.y"



char* nou_temporal(){
  char* buffer = (char *) malloc(sizeof(char)*3+sizeof(int));
  sprintf(buffer, "$t0%d", num_temportales);
  num_temportales++;
  return buffer;
}

void sumaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "+") == 0) {
            // Operación de suma
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "ADDF", v2_str);  // Suma flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "ADDI", v2_str);  // Suma entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "ADDF", v2_str);  // Suma flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "ADDI", v2_str);  // Suma entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}


void restaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "-") == 0) {
            // Operación de resta
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "SUBF", v2_str);  // Resta flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "SUBI", v2_str);  // Resta entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "SUBF", v2_str);  // Resta flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "SUBI", v2_str);  // Resta entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}

void addToMatrix(int args_count, ...) {
    va_list args;
    va_start(args, args_count);
    char* buffer = malloc(sizeof(char) * SENTENCE_MAX_LENGTH + 1);
    for (int i = 0; i < args_count; i++) {
        char* arg = va_arg(args, char*);
        strcat(buffer, arg);
        strcat(buffer, " ");  // Agregar espacio entre los argumentos
    }

    sentenciasC3A[sig_linea] = buffer;
    sig_linea++;

    printf("Matriz construida: %s\n", sentenciasC3A[sig_linea-1]);

    va_end(args);
}


void print_sentences(){
  int i;
  for (i=1; i < sig_linea; i++)
	fprintf(yyout, "%d:  %s\n", i, sentenciasC3A[i]);
  fprintf(yyout, "%d:  HALT\n", sig_linea);
}
