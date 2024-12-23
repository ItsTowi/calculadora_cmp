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

#define MAXLEN 150
#define SENTENCE_MAX_LENGTH 150

extern FILE *yyout;
extern int yylineno;
extern int yylex();
char *sentenciasC3A[MAXLEN];
int num_temportales = 1;
int sig_linea=1;
char* temp_sq;
char* nou_temporal();
void addToMatrix(int args_count, ...);
void print_sentences();
/*extern void yyerror(char*);*/


#line 94 "parser.tab.c"

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
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_LT = 10,                        /* LT  */
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_A_ID = 15,                      /* A_ID  */
  YYSYMBOL_B_ID = 16,                      /* B_ID  */
  YYSYMBOL_INTEGER = 17,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 18,                     /* FLOAT  */
  YYSYMBOL_BOOLEAN = 19,                   /* BOOLEAN  */
  YYSYMBOL_DOTS = 20,                      /* DOTS  */
  YYSYMBOL_ADD = 21,                       /* ADD  */
  YYSYMBOL_SUB = 22,                       /* SUB  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_POW = 26,                       /* POW  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_OPRELACIONAL = 29,              /* OPRELACIONAL  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_THEN = 34,                      /* THEN  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_FI = 36,                        /* FI  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_UNTIL = 38,                     /* UNTIL  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_IN = 40,                        /* IN  */
  YYSYMBOL_RANG = 41,                      /* RANG  */
  YYSYMBOL_REPEAT = 42,                    /* REPEAT  */
  YYSYMBOL_DONE = 43,                      /* DONE  */
  YYSYMBOL_DO = 44,                        /* DO  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programa = 46,                  /* programa  */
  YYSYMBOL_lista_declaraciones = 47,       /* lista_declaraciones  */
  YYSYMBOL_declaracion = 48,               /* declaracion  */
  YYSYMBOL_declaracion_simple = 49,        /* declaracion_simple  */
  YYSYMBOL_exp = 50,                       /* exp  */
  YYSYMBOL_aritmetica = 51,                /* aritmetica  */
  YYSYMBOL_termino = 52,                   /* termino  */
  YYSYMBOL_factor = 53,                    /* factor  */
  YYSYMBOL_primario = 54,                  /* primario  */
  YYSYMBOL_booleana = 55,                  /* booleana  */
  YYSYMBOL_bool1 = 56,                     /* bool1  */
  YYSYMBOL_bool2 = 57,                     /* bool2  */
  YYSYMBOL_bool3 = 58,                     /* bool3  */
  YYSYMBOL_bool_aritmetic = 59,            /* bool_aritmetic  */
  YYSYMBOL_operador_relacional = 60,       /* operador_relacional  */
  YYSYMBOL_declaracion_condicional = 61,   /* declaracion_condicional  */
  YYSYMBOL_declaracion_iterativa = 62,     /* declaracion_iterativa  */
  YYSYMBOL_declaracion_iterativa_incondicional = 63, /* declaracion_iterativa_incondicional  */
  YYSYMBOL_declaracion_iterativa_condicional = 64, /* declaracion_iterativa_condicional  */
  YYSYMBOL_bucle_do_until = 65,            /* bucle_do_until  */
  YYSYMBOL_bucle_while = 66,               /* bucle_while  */
  YYSYMBOL_declaracion_iterativa_indexada = 67, /* declaracion_iterativa_indexada  */
  YYSYMBOL_M = 68,                         /* M  */
  YYSYMBOL_LIN = 69,                       /* LIN  */
  YYSYMBOL_NEXTLIST = 70                   /* NEXTLIST  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 38 "parser.y"

 void completa(list lista, int num);
 list crea_lista(int num);
 list fusiona(list l1, list l2);
 value_info contador;
 char* getVariableValue(value_info v);
 void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void addToMatrixSaltoCondicional(value_info v1, char *operador, value_info v2, char * jump_line);
 void addToMatrixSalotIncond(value_info v1, const char* operador, value_info v2, char* jump_line);

#line 214 "parser.tab.c"


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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    79,    83,    85,    85,    85,    87,   107,
     122,   125,   127,   128,   148,   148,   150,   150,   154,   158,
     162,   164,   164,   168,   172,   177,   178,   183,   187,   191,
     205,   217,   222,   223,   235,   236,   248,   249,   255,   256,
     259,   262,   278,   289,   289,   289,   289,   289,   289,   291,
     298,   308,   308,   308,   310,   316,   316,   318,   325,   335,
     342,   353,   358
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
  "ONELINECMNT", "MULTILINECMNT", "COMMA", "EOL", "GT", "GE", "LT", "LE",
  "EQ", "NE", "ID", "A_ID", "B_ID", "INTEGER", "FLOAT", "BOOLEAN", "DOTS",
  "ADD", "SUB", "MULT", "DIV", "MOD", "POW", "LPAREN", "RPAREN",
  "OPRELACIONAL", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "FI", "WHILE",
  "UNTIL", "FOR", "IN", "RANG", "REPEAT", "DONE", "DO", "$accept",
  "programa", "lista_declaraciones", "declaracion", "declaracion_simple",
  "exp", "aritmetica", "termino", "factor", "primario", "booleana",
  "bool1", "bool2", "bool3", "bool_aritmetic", "operador_relacional",
  "declaracion_condicional", "declaracion_iterativa",
  "declaracion_iterativa_incondicional",
  "declaracion_iterativa_condicional", "bucle_do_until", "bucle_while",
  "declaracion_iterativa_indexada", "M", "LIN", "NEXTLIST", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      11,   -48,   -48,   -48,    14,    18,   -48,   -48,   -48,   -48,
     125,   125,    87,    87,    87,   -48,     4,   114,   -48,    34,
      47,   -48,   -48,    45,   112,    16,    30,   -48,    41,    57,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
      87,    87,   -48,   -48,   114,    16,    16,    67,    23,   112,
     -48,    31,    87,    21,   -13,    89,   -48,    11,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   125,   125,   114,   125,   125,
     125,   125,   -48,   -48,   100,   105,    -8,   -48,   -48,   -48,
      -9,   114,   -48,    11,   -48,    16,    16,    62,    30,    30,
      30,   -48,    87,    87,   -48,   -48,    11,   -48,    48,   106,
      77,    57,   -48,    58,   109,   114,    11,    87,   -48,   -48,
      11,     2,    74,    41,   -48,    75,   119,   -48,    11,   -48,
      11,    91,    94,   -48,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,    12,    29,    30,    41,    27,    28,    40,
       0,     0,     0,     0,     0,    61,     0,     0,    61,     0,
      61,     4,     5,     0,    14,    16,    21,    25,    15,    32,
      34,    36,    38,     6,     7,    51,    52,    55,    56,    53,
       0,     0,    29,    30,     0,    20,    19,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     1,     0,     9,    43,
      45,    44,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,    61,    61,     0,     0,     0,    31,    39,    61,
       0,     0,    60,     0,     3,    17,    18,    42,    22,    23,
      24,    26,     0,     0,     8,    13,     0,    61,     0,     0,
      61,    33,    35,    61,     0,     0,     0,     0,    62,    49,
       0,     0,    61,    57,    61,    61,     0,    54,     0,    58,
       0,    61,    61,    50,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -47,    73,   -48,    70,    -7,     1,    22,    76,
     -10,    46,   -12,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -15,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    67,    33,    34,    35,    36,
      37,    38,    39,    99,    57,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      52,    50,    48,    55,    51,    47,    49,    49,    65,    66,
      54,    45,    46,    65,    66,     1,     2,    40,     3,    53,
      77,    41,    72,    65,    66,     4,     5,     6,     7,     8,
       9,    82,    10,    11,    56,    97,   100,    76,    12,    68,
      69,    70,    80,    13,    14,    49,   116,    -2,    15,   103,
      16,    78,    58,    17,    72,    18,    71,    92,    93,   112,
      87,    81,    72,   115,    96,    79,    85,    86,   105,    65,
      66,   121,    72,   122,    98,    59,    60,    61,    62,    63,
      64,   102,   104,    65,    66,    49,    49,    73,    65,    66,
      88,    89,    90,   108,   109,    77,    83,   113,   111,   118,
      49,    42,    43,     6,     7,     8,     9,    94,    10,    11,
      74,    75,    95,   106,    12,   107,   110,   117,   119,    13,
      59,    60,    61,    62,    63,    64,   120,   123,    42,    43,
      84,     7,     8,    65,    66,    10,    11,   124,   101,    42,
      43,    44,     7,     8,     0,     0,     0,    91,     0,     0,
       0,     0,    44
};

static const yytype_int8 yycheck[] =
{
      15,    13,    12,    18,    14,    12,    13,    14,    21,    22,
      17,    10,    11,    21,    22,     4,     5,     3,     7,    15,
      28,     3,    31,    21,    22,    14,    15,    16,    17,    18,
      19,    44,    21,    22,     0,    44,    83,    44,    27,    23,
      24,    25,    52,    32,    33,    52,    44,     0,    37,    96,
      39,    28,     7,    42,    31,    44,    26,    72,    73,   106,
      67,    40,    31,   110,    79,    34,    65,    66,    20,    21,
      22,   118,    31,   120,    81,     8,     9,    10,    11,    12,
      13,    93,    97,    21,    22,    92,    93,    30,    21,    22,
      68,    69,    70,    35,    36,    28,     7,   107,   105,   114,
     107,    14,    15,    16,    17,    18,    19,     7,    21,    22,
      40,    41,     7,     7,    27,    38,     7,    43,    43,    32,
       8,     9,    10,    11,    12,    13,     7,    36,    14,    15,
      57,    17,    18,    21,    22,    21,    22,    43,    92,    14,
      15,    27,    17,    18,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    14,    15,    16,    17,    18,    19,
      21,    22,    27,    32,    33,    37,    39,    42,    44,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
       3,     3,    14,    15,    27,    52,    52,    51,    55,    51,
      57,    55,    69,    15,    51,    69,     0,    69,     7,     8,
       9,    10,    11,    12,    13,    21,    22,    60,    23,    24,
      25,    26,    31,    30,    50,    50,    51,    28,    28,    34,
      55,    40,    44,     7,    48,    52,    52,    51,    53,    53,
      53,    54,    69,    69,     7,     7,    69,    44,    51,    68,
      47,    56,    57,    47,    69,    20,     7,    38,    35,    36,
       7,    51,    47,    55,    70,    47,    44,    43,    69,    43,
       7,    47,    47,    36,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    63,    64,    64,    65,    66,    67,
      68,    69,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     4,     2,
       1,     1,     1,     4,     1,     1,     1,     3,     3,     2,
       2,     1,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     4,     1,     4,     1,     2,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     6,
      10,     1,     1,     1,     7,     1,     1,     6,     8,    10,
       0,     0,     0
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
#line 77 "parser.y"
                              {print_sentences();}
#line 1258 "parser.tab.c"
    break;

  case 3: /* lista_declaraciones: lista_declaraciones LIN declaracion  */
#line 79 "parser.y"
                                                         {
		                completa((yyvsp[-2].sent), (yyvsp[-1].entero));
		                (yyval.sent) = (yyvsp[0].sent);
                    }
#line 1267 "parser.tab.c"
    break;

  case 8: /* declaracion_simple: ID ASSIGN exp EOL  */
#line 87 "parser.y"
                                      {
                                  if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE) 
                                  {
                                    printf("ERror tipo\n");
                                    yyerror((yyvsp[-1].expr_val).value.val_string);
                                  } 
                                  else 
                                  {
                                    (yyvsp[-3].expr_val).val_type = (yyvsp[-1].expr_val).val_type;
                                    (yyvsp[-1].expr_val).name = (yyvsp[-3].expr_val).name;
                                    printf("Se asigna a la variable %s el valor %s\n", (yyvsp[-3].expr_val).name, valueToString((yyvsp[-1].expr_val)));
                                    if (!((yyvsp[-3].expr_val).name == NULL)) {
                                      sym_enter((yyvsp[-3].expr_val).name, &(yyvsp[-1].expr_val));
                                      if ((yyvsp[-1].expr_val).place != NULL)
                                        addToMatrix(3, (yyvsp[-3].expr_val).name, ":=", (yyvsp[-1].expr_val).place);
                                      else
                                        addToMatrix(3, (yyvsp[-3].expr_val).name, ":=", valueToString((yyvsp[-1].expr_val)));
                                    }
                                  }
                                }
#line 1292 "parser.tab.c"
    break;

  case 9: /* declaracion_simple: exp EOL  */
#line 107 "parser.y"
                                {
                                  if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE)
                                  {
                                    yyerror((yyvsp[-1].expr_val).value.val_string);
                                  }
                                  else 
                                  {
                                    addToMatrix(2, "PARAM", (yyvsp[-1].expr_val).name);
                                    char* oper = malloc(sizeof(char)*5);
                                    strcpy(oper, "PUT");
                                    if ((yyvsp[-1].expr_val).val_type == INT_TYPE) strcat(oper, "I,");
                                    else if ((yyvsp[-1].expr_val).val_type == FLOAT_TYPE) strcat(oper, "F,");
                                    addToMatrix(3, "CALL", oper, "1");
                                  }
                                }
#line 1312 "parser.tab.c"
    break;

  case 10: /* declaracion_simple: ONELINECMNT  */
#line 122 "parser.y"
                                {

                                }
#line 1320 "parser.tab.c"
    break;

  case 11: /* declaracion_simple: MULTILINECMNT  */
#line 125 "parser.y"
                                {
                                }
#line 1327 "parser.tab.c"
    break;

  case 12: /* declaracion_simple: EOL  */
#line 127 "parser.y"
                                {}
#line 1333 "parser.tab.c"
    break;

  case 13: /* declaracion_simple: A_ID ASSIGN exp EOL  */
#line 128 "parser.y"
                                    {
                                  if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror((yyvsp[-1].expr_val).value.val_string);
                                  } 
                                  else 
                                  {
                                    (yyvsp[-3].expr_val).val_type = (yyvsp[-1].expr_val).val_type;
                                    (yyvsp[-1].expr_val).name = (yyvsp[-3].expr_val).name;
                                    printf("Se asigna a la variable %s el valor %s\n", (yyvsp[-3].expr_val).name, valueToString((yyvsp[-1].expr_val)));
                                    if (!((yyvsp[-3].expr_val).name == NULL)) {
                                      sym_enter((yyvsp[-3].expr_val).name, &(yyvsp[-1].expr_val));
                                      if ((yyvsp[-1].expr_val).place != NULL)
                                        addToMatrix(3, (yyvsp[-3].expr_val).name, ":=", (yyvsp[-1].expr_val).place);
                                      else
                                        addToMatrix(3, (yyvsp[-3].expr_val).name, ":=", valueToString((yyvsp[-1].expr_val)));
                                    }
                                  }
                                }
#line 1357 "parser.tab.c"
    break;

  case 17: /* aritmetica: aritmetica ADD termino  */
#line 150 "parser.y"
                                              {
                                                (yyval.expr_val) = sumaAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                                sumaAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "+", (yyvsp[0].expr_val));
                                              }
#line 1366 "parser.tab.c"
    break;

  case 18: /* aritmetica: aritmetica SUB termino  */
#line 154 "parser.y"
                                              {
                                                (yyval.expr_val) = restaAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                                restaAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "-", (yyvsp[0].expr_val));
                                              }
#line 1375 "parser.tab.c"
    break;

  case 19: /* aritmetica: SUB termino  */
#line 158 "parser.y"
                                              { 
                                                (yyval.expr_val) = cambioAritmetica((yyvsp[0].expr_val)); 
                                                //addToMatrix(4, $$.place, ":=", "CHSI", getVariableValue($2));
                                              }
#line 1384 "parser.tab.c"
    break;

  case 20: /* aritmetica: ADD termino  */
#line 162 "parser.y"
                                              { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1390 "parser.tab.c"
    break;

  case 22: /* termino: termino MULT factor  */
#line 164 "parser.y"
                                      {
                                        (yyval.expr_val) = multAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                        multiplicacionAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "*", (yyvsp[0].expr_val));
                                      }
#line 1399 "parser.tab.c"
    break;

  case 23: /* termino: termino DIV factor  */
#line 168 "parser.y"
                                      {
                                        (yyval.expr_val) = divAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                        divisionAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "/", (yyvsp[0].expr_val));
                                      }
#line 1408 "parser.tab.c"
    break;

  case 24: /* termino: termino MOD factor  */
#line 172 "parser.y"
                                      {
                                        (yyval.expr_val) = modAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                        moduloAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "%", (yyvsp[0].expr_val));
                                      }
#line 1417 "parser.tab.c"
    break;

  case 26: /* factor: factor POW primario  */
#line 178 "parser.y"
                                       {
                                          (yyval.expr_val) = potAritmetica((yyvsp[-2].expr_val), (yyvsp[0].expr_val));
                                          potenciaAritmetica3AC(&(yyval.expr_val),(yyvsp[-2].expr_val), "**", (yyvsp[0].expr_val));
                                       }
#line 1426 "parser.tab.c"
    break;

  case 27: /* primario: INTEGER  */
#line 183 "parser.y"
                                      {
                                        (yyvsp[0].expr_val).name = NULL;
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1435 "parser.tab.c"
    break;

  case 28: /* primario: FLOAT  */
#line 187 "parser.y"
                                      {
                                        (yyvsp[0].expr_val).name = NULL;
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1444 "parser.tab.c"
    break;

  case 29: /* primario: ID  */
#line 191 "parser.y"
                                      {
                                          if(sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND) 
                                          {	
                                            printf("AQUIIII\n");
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
											else 
                                          { 
                                            (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                            (yyval.expr_val).name = (yyvsp[0].expr_val).name;
                                            (yyval.expr_val).value =(yyvsp[0].expr_val).value;
                                            (yyval.expr_val).place = valueToString((yyvsp[0].expr_val));
                                          }
                                      }
#line 1463 "parser.tab.c"
    break;

  case 30: /* primario: A_ID  */
#line 205 "parser.y"
                                      {
                                          if(sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND)
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
										    else 
                                          {
                                            (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                            (yyval.expr_val).value =(yyvsp[0].expr_val).value;
                                            (yyval.expr_val).place = (yyvsp[0].expr_val).name;
                                          }
                                      }
#line 1480 "parser.tab.c"
    break;

  case 31: /* primario: LPAREN aritmetica RPAREN  */
#line 217 "parser.y"
                                      {
                                          (yyval.expr_val) = (yyvsp[-1].expr_val);
                                      }
#line 1488 "parser.tab.c"
    break;

  case 33: /* booleana: booleana OR LIN bool1  */
#line 223 "parser.y"
                                  {
                                if ((yyvsp[-3].expr_val).val_type == BOOLEAN_TYPE && (yyvsp[-3].expr_val).value.val_boolean) {
                                    printf("Corto de or\n");
                                    (yyval.expr_val) = (yyvsp[-3].expr_val);
                                } else {
                                    (yyval.expr_val) = orBooleana((yyvsp[-3].expr_val), (yyvsp[0].expr_val));
                                }
                                completa((yyvsp[-3].expr_val).falselist, (yyvsp[-1].entero));
		                        (yyval.expr_val).truelist = fusiona((yyvsp[-3].expr_val).truelist, (yyvsp[0].expr_val).truelist);
		                        (yyval.expr_val).falselist = (yyvsp[0].expr_val).falselist;
                              }
#line 1504 "parser.tab.c"
    break;

  case 35: /* bool1: bool1 AND LIN bool2  */
#line 236 "parser.y"
                            {
                          if ((yyvsp[-3].expr_val).val_type == BOOLEAN_TYPE && !(yyvsp[-3].expr_val).value.val_boolean) {
                              printf("Corto de and\n");
                              (yyval.expr_val) = (yyvsp[-3].expr_val);
                          } else {
                              (yyval.expr_val) = andBooleana((yyvsp[-3].expr_val), (yyvsp[0].expr_val));
                          }
                          completa((yyvsp[-3].expr_val).truelist, (yyvsp[-1].entero));
                          (yyval.expr_val).truelist = (yyvsp[0].expr_val).truelist;
                          (yyval.expr_val).falselist = fusiona((yyvsp[-3].expr_val).falselist, (yyvsp[0].expr_val).falselist);
                        }
#line 1520 "parser.tab.c"
    break;

  case 37: /* bool2: NOT bool2  */
#line 249 "parser.y"
                                      {
                                        (yyval.expr_val).truelist = (yyvsp[0].expr_val).falselist;
                                        (yyval.expr_val).falselist = (yyvsp[0].expr_val).truelist;
                                        //$$ = notBooleana($2);
                                      }
#line 1530 "parser.tab.c"
    break;

  case 39: /* bool3: LPAREN booleana RPAREN  */
#line 256 "parser.y"
                                      {
                                        (yyval.expr_val) = (yyvsp[-1].expr_val);
                                      }
#line 1538 "parser.tab.c"
    break;

  case 40: /* bool3: BOOLEAN  */
#line 259 "parser.y"
                                      {
                                        (yyval.expr_val) = (yyvsp[0].expr_val);
                                      }
#line 1546 "parser.tab.c"
    break;

  case 41: /* bool3: B_ID  */
#line 262 "parser.y"
                                      {
                                        if (sym_lookup((yyvsp[0].expr_val).name, &(yyvsp[0].expr_val)) == SYMTAB_NOT_FOUND)
                                        {
                                          yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n");
                                        }
                                        else
                                        {
                                          (yyval.expr_val).truelist = crea_lista(sig_linea);
                                          addToMatrix(5,"IF",(yyvsp[0].expr_val).name,"EQ","1","GOTO");
                                          (yyval.expr_val).falselist = crea_lista(sig_linea);
                                          addToMatrix(1, "GOTO");
                                          (yyval.expr_val).val_type = (yyvsp[0].expr_val).val_type;
                                          (yyval.expr_val).value = (yyvsp[0].expr_val).value;
                                        }
                                      }
#line 1566 "parser.tab.c"
    break;

  case 42: /* bool_aritmetic: aritmetica operador_relacional aritmetica  */
#line 278 "parser.y"
                                                           {
                                                      //$$ = opRelacional($1,$2,$3);
                                                      (yyval.expr_val).truelist = crea_lista(sig_linea);
                                                      printf("item true list %d\n", (yyval.expr_val).truelist.lista[0]);
                                                      addToMatrixSaltoCondicional((yyvsp[-2].expr_val), (yyvsp[-1].cadena), (yyvsp[0].expr_val), "");
                                                      (yyval.expr_val).falselist = crea_lista(sig_linea);
                                                      printf("item false list %d\n", (yyval.expr_val).falselist.lista[0]);
                                                      addToMatrix(1, "GOTO");
                                                    }
#line 1580 "parser.tab.c"
    break;

  case 43: /* operador_relacional: GT  */
#line 289 "parser.y"
                        {(yyval.cadena)="GT";}
#line 1586 "parser.tab.c"
    break;

  case 44: /* operador_relacional: LT  */
#line 289 "parser.y"
                                        {(yyval.cadena)="LT";}
#line 1592 "parser.tab.c"
    break;

  case 45: /* operador_relacional: GE  */
#line 289 "parser.y"
                                                        {(yyval.cadena)="GE";}
#line 1598 "parser.tab.c"
    break;

  case 46: /* operador_relacional: LE  */
#line 289 "parser.y"
                                                                        {(yyval.cadena)="LE";}
#line 1604 "parser.tab.c"
    break;

  case 47: /* operador_relacional: EQ  */
#line 289 "parser.y"
                                                                                        {(yyval.cadena)="EQ";}
#line 1610 "parser.tab.c"
    break;

  case 48: /* operador_relacional: NE  */
#line 289 "parser.y"
                                                                                                        {(yyval.cadena)="NE";}
#line 1616 "parser.tab.c"
    break;

  case 49: /* declaracion_condicional: IF booleana THEN LIN lista_declaraciones FI  */
#line 292 "parser.y"
                        {
                            printf("LLEGO AL IF\n");
                            completa((yyvsp[-4].expr_val).truelist, (yyvsp[-2].entero));
	                        (yyval.sent)=fusiona((yyvsp[-4].expr_val).falselist, (yyvsp[-1].sent));
                        }
#line 1626 "parser.tab.c"
    break;

  case 50: /* declaracion_condicional: IF booleana THEN LIN lista_declaraciones ELSE NEXTLIST LIN lista_declaraciones FI  */
#line 299 "parser.y"
                        {
                            completa((yyvsp[-8].expr_val).truelist, (yyvsp[-6].entero));
	                        completa((yyvsp[-8].expr_val).falselist, (yyvsp[-2].entero));
	                        (yyval.sent)=fusiona((yyvsp[-5].sent), fusiona((yyvsp[-3].sent), (yyvsp[-1].sent)));
                            printf("SE HA ENCONTRADO UN IF/ELSE \n");
                        }
#line 1637 "parser.tab.c"
    break;

  case 54: /* declaracion_iterativa_incondicional: REPEAT aritmetica DO M EOL lista_declaraciones DONE  */
#line 310 "parser.y"
                                                                                         {
	addToMatrix(5, contador.place, ":=", contador.place, "ADDI", "1");
    printf("valor de aritmetica %s\n", (yyvsp[-5].expr_val).place);
	addToMatrixSalotIncond(contador, "LT", (yyvsp[-5].expr_val), temp_sq);
}
#line 1647 "parser.tab.c"
    break;

  case 57: /* bucle_do_until: DO LIN EOL lista_declaraciones UNTIL booleana  */
#line 319 "parser.y"
            {
                printf("BUCLE DO\n");
                completa((yyvsp[0].expr_val).truelist, (yyvsp[-4].entero));
                (yyval.sent) = (yyvsp[0].expr_val).falselist;
            }
#line 1657 "parser.tab.c"
    break;

  case 58: /* bucle_while: WHILE LIN booleana DO LIN EOL lista_declaraciones DONE  */
#line 326 "parser.y"
            {
                completa((yyvsp[-5].expr_val).truelist, (yyvsp[-3].entero));
                completa((yyvsp[-1].sent), (yyvsp[-6].entero));
                (yyval.sent) = (yyvsp[-5].expr_val).falselist;
                char *m_buffer = malloc(sizeof(char)*5);
                sprintf(m_buffer, "%d", (yyvsp[-6].entero)); 
                addToMatrix(2, "GOTO", m_buffer);
            }
#line 1670 "parser.tab.c"
    break;

  case 59: /* declaracion_iterativa_indexada: FOR A_ID IN aritmetica DOTS aritmetica DO EOL lista_declaraciones DONE  */
#line 336 "parser.y"
            {
                printf("BUCLE FOR DETECTADO\n");
            }
#line 1678 "parser.tab.c"
    break;

  case 60: /* M: %empty  */
#line 342 "parser.y"
    {(yyval.expr_val).place = malloc(sizeof(char)*5);
     (yyval.expr_val).val_type = INT_TYPE; /*Un contador siempre es un entero*/
     strcpy((yyval.expr_val).place, nou_temporal());
     addToMatrix(3, (yyval.expr_val).place, ":=", "0");
     contador.val_type = INT_TYPE;
     contador.place = (yyval.expr_val).place;
     temp_sq = malloc(sizeof(char)*5);
     sprintf(temp_sq, "%d", sig_linea);  
}
#line 1692 "parser.tab.c"
    break;

  case 61: /* LIN: %empty  */
#line 353 "parser.y"
     {
	(yyval.entero)=sig_linea;
}
#line 1700 "parser.tab.c"
    break;

  case 62: /* NEXTLIST: %empty  */
#line 358 "parser.y"
          {
    (yyval.sent)=crea_lista(sig_linea);
	addToMatrix(1, "GOTO");
}
#line 1709 "parser.tab.c"
    break;


#line 1713 "parser.tab.c"

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

#line 363 "parser.y"



char* nou_temporal(){
  char* buffer = (char *) malloc(sizeof(char)*3+sizeof(int));
  sprintf(buffer, "$t0%d", num_temportales);
  num_temportales++;
  return buffer;
}

list crea_lista(int num){
	list temp;
	temp.lista = malloc(MAXLEN*sizeof(int));
	temp.lista[0]=num;
	temp.size = 1;
	return temp;
}

void completa(list lista, int num){
	int i;
	char* num_buffer = malloc(sizeof(char)*5);
	sprintf(num_buffer, "%d", num);
	for (i=0; i < lista.size; i++){
	strcat(sentenciasC3A[lista.lista[i]],num_buffer);
	}
}

list fusiona(list l1, list l2){
	list temp;
	temp.lista = malloc(MAXLEN*sizeof(int));
	int i;
	for (i=0; i < l1.size; i++){
	temp.lista[i]=l1.lista[i];
	}
	int j;
	for (j=0; j < l2.size; j++){
	temp.lista[i]=l2.lista[j];
	i++;
	}

	temp.size = l1.size + l2.size;
	return temp;
}


void addToMatrix(int args_count, ...) {
    va_list args;
    va_start(args, args_count);
    char* buffer = malloc(sizeof(char) * (SENTENCE_MAX_LENGTH + 1));
    buffer[0] = '\0';

    for (int i = 0; i < args_count; i++) {
        char* arg = va_arg(args, char*);  // Intento de leer argumento
        printf("%s\n", arg);
        strcat(buffer, arg);
        strcat(buffer, " ");
    }

    sentenciasC3A[sig_linea] = buffer;
    printf("Guardado en sentenciasC3A[%d]: %s\n", sig_linea, buffer);
    sig_linea++;

    va_end(args);
}

void addToMatrixSalotIncond(value_info v1, const char* operador, value_info v2, char* jump_line){
	if (v1.val_type==v2.val_type) {
		char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
		strcpy(op, operador);
		if (v1.val_type==INT_TYPE) strcat(op, "I");
	 	else strcat(op, "F");
		addToMatrix(6, "IF", v1.place, op, v2.place, "GOTO", jump_line);
		free(op);
	}
	else yyerror("Tienen que tener el mismo tipo!");
}


void addToMatrixSaltoCondicional(value_info v1, char *operador, value_info v2, char * jump_line) {
	
    char* valor_v1 = getVariableValue(v1);
    char* valor_v2 = getVariableValue(v2);
    
    if (strcmp(operador, "=")==0 || strcmp(operador, "<>")==0){
		if (v1.val_type==v2.val_type) {
			char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
			strcpy(op, operador);
			if (v1.val_type==INT_TYPE) strcat(op, "I");
		 	else strcat(op, "F");
			addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			free(op);
		}
		else yyerror("Las dos variables tienen que tener el mismo tipo para realizar esta operación!");
	} else {
		char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
		strcpy(op, operador);
		if (v1.val_type==v2.val_type) {
			if (v1.val_type==INT_TYPE){
				 strcat(op, "I");
			} else {
				 strcat(op, "F");
			}
			addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);

		} else if (v1.val_type==FLOAT_TYPE || v2.val_type==FLOAT_TYPE){
			strcat(op, "F");
			if (v1.val_type==FLOAT_TYPE) {
				char *castedValue;
				if (v2.name != NULL) {
					castedValue = nou_temporal();
					addToMatrix(4, castedValue, ":=", "I2F", v2.place);
				} else {
					castedValue = (char *) malloc(sizeof(char)*5);
					sprintf(castedValue, "%.1f", atof(v2.place));
				}
				addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			}
			else if (v2.val_type==FLOAT_TYPE){
				char *castedValue;
				if (v1.name != NULL) {
					castedValue = nou_temporal();
					addToMatrix(4, castedValue, ":=", "I2F", v1.place);
				} else {
					castedValue = (char *) malloc(sizeof(char)*5);
					sprintf(castedValue, "%.1f", atof(v1.place));
				}
				addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			} else yyerror("OPERACION NO PERMITIDA");
		} else yyerror("OPERACION NO PERMITIDA");
		free(op);
	}
}

char* getVariableValue(value_info v) {
    if (v.place != NULL && strlen(v.place) > 0) {
        return v.place;
    } else {
        return valueToString(v);
    }
}

void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();

        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        char* v1_str = getVariableValue(v1);
        char* v2_str = getVariableValue(v2);

        if (strcmp(op, "+") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1_str, "ADDF", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1_str, "ADDI", v2_str);
            }
        }

        if (v1.place == NULL) free(v1_str);
        if (v2.place == NULL) free(v2_str);
    } else {
        printf("Error: Los operandos deben ser numéricos.\n");
    }
}

void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Crear un nuevo temporal
        s0->place = nou_temporal();

        // Determinar tipo del resultado
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        // Obtener cadenas para v1 y v2
        char* v1_str = getVariableValue(v1);
        char* v2_str = getVariableValue(v2);

        // Generar instrucción basada en el operador
        if (strcmp(op, "-") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1_str, "SUBF", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1_str, "SUBI", v2_str);
            }
        }

        // Liberar memoria de las cadenas generadas dinámicamente
        if (v1.place == NULL) free(v1_str);
        if (v2.place == NULL) free(v2_str);
    } else {
        printf("Error: Los operandos deben ser numéricos.\n");
    }
}

void generarValorCadena(value_info v, char **v_str) {
    if (v.name == NULL) {
        // Si el nombre es NULL, usamos el valor directamente
        if (v.val_type == INT_TYPE) {
            asprintf(v_str, "%d", v.value.val_int);
        } else {
            asprintf(v_str, "%f", v.value.val_float);
        }
    } else {
        *v_str = v.name;
    }
}

void liberarValorCadena(value_info v, char *v_str) {
    if (v.name == NULL) {
        free(v_str);
    }
}

void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char *v1_str, *v2_str;

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {
        
        s0->place = nou_temporal();
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        generarValorCadena(v1, &v1_str);
        generarValorCadena(v2, &v2_str);

        if (strcmp(op, "*") == 0) {
            addToMatrix(5, s0->place, ":=", 
                        v1.place ? v1.place : v1_str, 
                        s0->val_type == FLOAT_TYPE ? "MULF" : "MULI", 
                        v2_str);
        }

        liberarValorCadena(v1, v1_str);
        liberarValorCadena(v2, v2_str);
    }
}

void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char *v1_str, *v2_str;

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        if ((v2.val_type == INT_TYPE && v2.value.val_int == 0) ||
            (v2.val_type == FLOAT_TYPE && v2.value.val_float == 0.0)) {
            printf("Error: División por cero\n");
            return;
        }

        s0->place = nou_temporal();
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        generarValorCadena(v1, &v1_str);
        generarValorCadena(v2, &v2_str);

        if (strcmp(op, "/") == 0) {
            addToMatrix(5, s0->place, ":=", 
                        v1.place ? v1.place : v1_str, 
                        s0->val_type == FLOAT_TYPE ? "DIVF" : "DIVI", 
                        v2_str);
        }

        liberarValorCadena(v1, v1_str);
        liberarValorCadena(v2, v2_str);
    }
}


void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos que ambos operandos sean enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {

        // Comprobamos si el divisor (v2) es 0 para evitar un error de módulo por cero
        if (v2.value.val_int == 0) {
            // Imprimir un error de módulo por cero o manejarlo adecuadamente
            printf("Error: Módulo por cero\n");
            return;
        }

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado
        s0->val_type = INT_TYPE;     // El resultado del módulo siempre es un entero

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            asprintf(&v1_str, "%d", v1.value.val_int);
        } else {
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            asprintf(&v2_str, "%d", v2.value.val_int);
        } else {
            v2_str = v2.name;
        }

        // Generar la instrucción de módulo
        if (strcmp(op, "%") == 0) {
            if (v1.place == NULL) {
                addToMatrix(5, s0->place, ":=", v1_str, "MODI", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1.place, "MODI", v2_str);
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);

    } else {
        // Si uno o ambos operandos no son enteros, se genera un error
        printf("Error: Operación de módulo solo soportada entre enteros\n");
    }
}


void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos que los operandos sean numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Comprobar si el exponente es negativo y la base es un entero
        if (v2.val_type == INT_TYPE && v2.value.val_int < 0 && v1.val_type == INT_TYPE) {
            printf("Error: Potencia con exponente negativo requiere un valor flotante\n");
            return;
        }

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);
            }
        } else {
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);
            }
        } else {
            v2_str = v2.name;
        }

        // Generar la instrucción de potencia
        if (strcmp(op, "**") == 0) {
            if (v1.place == NULL) {
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "POWF", v2_str);
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "POWI", v2_str);
                }
            } else {
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "POWF", v2_str);
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "POWI", v2_str);
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);

    } else {
        // Error si alguno de los operandos no es numérico
        printf("Error: Operación de potencia solo soportada entre enteros o flotantes\n");
    }
}

void print_sentences(){
  int i;
  for (i=1; i < sig_linea; i++)
	fprintf(yyout, "%d:  %s\n", i, sentenciasC3A[i]);
  fprintf(yyout, "%d:  HALT\n", sig_linea);
}
