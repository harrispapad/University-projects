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
#line 3 "src/llvm/parser.y"

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "ast.hpp"
#include "lexer.hpp"

extern int linenum;
extern FILE *yyin;
SymbolTable st;
LoopStack lp;

// Global AST pointer and command-line flags
FuncDef *program_ast = nullptr;
bool flag_i = false;
bool flag_f = false;
bool flag_O = false;
std::string output_file = "a.out";
std::string input_file = "";

#line 96 "src/llvm/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_and = 3,                      /* "and"  */
  YYSYMBOL_T_as = 4,                       /* "as"  */
  YYSYMBOL_T_break = 5,                    /* "break"  */
  YYSYMBOL_T_byte = 6,                     /* "byte"  */
  YYSYMBOL_T_continue = 7,                 /* "continue"  */
  YYSYMBOL_T_decl = 8,                     /* "decl"  */
  YYSYMBOL_T_def = 9,                      /* "def"  */
  YYSYMBOL_T_elif = 10,                    /* "elif"  */
  YYSYMBOL_T_else = 11,                    /* "else"  */
  YYSYMBOL_T_exit = 12,                    /* "exit"  */
  YYSYMBOL_T_false = 13,                   /* "false"  */
  YYSYMBOL_T_if = 14,                      /* "if"  */
  YYSYMBOL_T_is = 15,                      /* "is"  */
  YYSYMBOL_T_int = 16,                     /* "int"  */
  YYSYMBOL_T_loop = 17,                    /* "loop"  */
  YYSYMBOL_T_not = 18,                     /* "not"  */
  YYSYMBOL_T_or = 19,                      /* "or"  */
  YYSYMBOL_T_ref = 20,                     /* "ref"  */
  YYSYMBOL_T_return = 21,                  /* "return"  */
  YYSYMBOL_T_skip = 22,                    /* "skip"  */
  YYSYMBOL_T_true = 23,                    /* "true"  */
  YYSYMBOL_T_var = 24,                     /* "var"  */
  YYSYMBOL_T_assign = 25,                  /* ":="  */
  YYSYMBOL_T_eq = 26,                      /* "="  */
  YYSYMBOL_T_neq = 27,                     /* "<>"  */
  YYSYMBOL_T_lt = 28,                      /* "<"  */
  YYSYMBOL_T_gt = 29,                      /* ">"  */
  YYSYMBOL_T_le = 30,                      /* "<="  */
  YYSYMBOL_T_ge = 31,                      /* ">="  */
  YYSYMBOL_T_plus = 32,                    /* "+"  */
  YYSYMBOL_T_minus = 33,                   /* "-"  */
  YYSYMBOL_T_times = 34,                   /* "*"  */
  YYSYMBOL_T_div = 35,                     /* "/"  */
  YYSYMBOL_T_mod = 36,                     /* "%"  */
  YYSYMBOL_T_INDENT = 37,                  /* "INDENT"  */
  YYSYMBOL_T_DEDENT = 38,                  /* "DEDENT"  */
  YYSYMBOL_T_id = 39,                      /* T_id  */
  YYSYMBOL_T_string = 40,                  /* T_string  */
  YYSYMBOL_T_intconst = 41,                /* T_intconst  */
  YYSYMBOL_T_charconst = 42,               /* T_charconst  */
  YYSYMBOL_43_ = 43,                       /* '|'  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 47,                     /* UPLUS  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_func_def = 56,                  /* func_def  */
  YYSYMBOL_indented_local_def_and_block = 57, /* indented_local_def_and_block  */
  YYSYMBOL_local_def_and_stmts = 58,       /* local_def_and_stmts  */
  YYSYMBOL_header = 59,                    /* header  */
  YYSYMBOL_header_aux = 60,                /* header_aux  */
  YYSYMBOL_fpar_def = 61,                  /* fpar_def  */
  YYSYMBOL_data_type = 62,                 /* data_type  */
  YYSYMBOL_type = 63,                      /* type  */
  YYSYMBOL_fpar_type = 64,                 /* fpar_type  */
  YYSYMBOL_array_type = 65,                /* array_type  */
  YYSYMBOL_local_def = 66,                 /* local_def  */
  YYSYMBOL_func_decl = 67,                 /* func_decl  */
  YYSYMBOL_var_def = 68,                   /* var_def  */
  YYSYMBOL_id_aux = 69,                    /* id_aux  */
  YYSYMBOL_stmt_list = 70,                 /* stmt_list  */
  YYSYMBOL_simple_stmt_no_colon = 71,      /* simple_stmt_no_colon  */
  YYSYMBOL_simple_stmt = 72,               /* simple_stmt  */
  YYSYMBOL_else_part = 73,                 /* else_part  */
  YYSYMBOL_if_aux = 74,                    /* if_aux  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_indented_stmt_list = 76,        /* indented_stmt_list  */
  YYSYMBOL_proc_call = 77,                 /* proc_call  */
  YYSYMBOL_expr_aux = 78,                  /* expr_aux  */
  YYSYMBOL_func_call = 79,                 /* func_call  */
  YYSYMBOL_l_value = 80,                   /* l_value  */
  YYSYMBOL_expr = 81,                      /* expr  */
  YYSYMBOL_cond = 82,                      /* cond  */
  YYSYMBOL_cond_aux = 83                   /* cond_aux  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
       2,     2,     2,    45,     2,     2,     2,     2,    44,     2,
      52,    53,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   147,   151,   155,   159,   160,   161,   162,
     166,   167,   171,   175,   176,   180,   181,   185,   186,   187,
     191,   192,   196,   197,   198,   199,   203,   207,   211,   212,
     216,   217,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   235,   236,   237,   238,   239,   240,   247,
     248,   249,   250,   251,   252,   256,   257,   261,   262,   266,
     267,   271,   275,   276,   280,   281,   285,   286,   290,   291,
     292,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   316,   317,
     318,   322,   323,   324,   325,   326,   327,   328,   329,   330
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"and\"", "\"as\"",
  "\"break\"", "\"byte\"", "\"continue\"", "\"decl\"", "\"def\"",
  "\"elif\"", "\"else\"", "\"exit\"", "\"false\"", "\"if\"", "\"is\"",
  "\"int\"", "\"loop\"", "\"not\"", "\"or\"", "\"ref\"", "\"return\"",
  "\"skip\"", "\"true\"", "\"var\"", "\":=\"", "\"=\"", "\"<>\"", "\"<\"",
  "\">\"", "\"<=\"", "\">=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\"INDENT\"", "\"DEDENT\"", "T_id", "T_string", "T_intconst",
  "T_charconst", "'|'", "'&'", "'!'", "UMINUS", "UPLUS", "':'", "','",
  "'['", "']'", "'('", "')'", "$accept", "program", "func_def",
  "indented_local_def_and_block", "local_def_and_stmts", "header",
  "header_aux", "fpar_def", "data_type", "type", "fpar_type", "array_type",
  "local_def", "func_decl", "var_def", "id_aux", "stmt_list",
  "simple_stmt_no_colon", "simple_stmt", "else_part", "if_aux", "block",
  "indented_stmt_list", "proc_call", "expr_aux", "func_call", "l_value",
  "expr", "cond", "cond_aux", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    -6,    18,   -87,    -4,    -1,   -87,    29,    41,   -87,
     -87,   -87,   -87,     9,   -87,   -87,     4,    47,    65,    41,
      39,   102,   -87,   -87,    -6,    41,   -87,   -87,   -87,   164,
     -87,    41,    29,    40,    53,   -87,    63,   -87,     7,    45,
      61,   -87,    84,    66,    72,   -87,   -16,   -87,   -87,   -87,
     -13,    39,   -87,   -87,    83,    94,    98,    29,   101,   103,
     -87,    84,   -87,   114,   114,    91,   -87,   -87,   114,    84,
     -87,    95,   223,     0,   -87,    96,   177,   114,   114,   114,
     114,   -87,    97,    99,   -87,    53,   -87,   -87,   -87,   114,
     -87,   -87,    59,   -87,   192,     2,   104,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
      84,    84,   177,   177,   113,   115,   -87,    93,   116,   -87,
     -87,   -87,   -87,   -87,   -87,     6,   228,   228,   228,   197,
     -87,   -87,    43,   -87,   228,   -87,   -87,   228,   228,   228,
     228,   228,   228,   -21,   -21,   -87,   -87,   -87,   -21,   -87,
     -87,   146,   -87,   -87,   123,   129,   124,   177,   114,   153,
     114,   128,   -87,    57,    44,   -87,   -87,   177,   -87,   228,
     -87,   228,   114,   -87,    84,   125,   -87,   -87,   228,     1,
     177,   177,   -87,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     6,     0,     1,     0,     0,    22,
       3,    14,    13,     7,    28,    10,     0,     0,    30,     0,
       9,     0,    29,     4,     0,     0,    23,    24,    25,     5,
      10,     0,     0,    15,    17,    12,    19,    26,     0,    51,
      53,    46,     0,     0,     0,    43,    62,    69,    31,    45,
       0,     8,    11,    18,     0,     0,     0,     0,     0,     0,
      84,     0,    83,     0,     0,    68,    71,    72,     0,     0,
      75,    73,    88,     0,    90,     0,     0,     0,     0,     0,
       0,    20,     0,     0,    15,    27,    52,    54,    91,     0,
      77,    76,     0,    85,    88,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    41,    35,     0,     0,    32,
      30,    60,    49,    59,    34,     0,    47,    64,    44,     0,
      16,    21,     0,    66,    64,    74,    89,    94,    95,    96,
      97,    98,    99,    78,    79,    80,    81,    82,    87,    86,
      92,    93,    57,    50,     0,     0,     0,     0,     0,     0,
       0,    63,    70,     0,    55,    40,    42,     0,    37,    36,
      61,    33,     0,    67,     0,     0,    48,    38,    65,     0,
       0,     0,    56,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   161,   -87,   -87,   156,   157,    -3,   -15,   126,
     -87,   -87,   -87,   -87,   -87,   163,    70,   -87,   -87,   -87,
     -87,   -86,   -87,   -28,    62,   -87,   -29,   -39,   -59,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    10,    17,     5,    20,    15,    13,    34,
      35,    36,    18,    27,    28,    16,    29,   121,    48,   176,
     164,   122,   123,   124,   161,    70,    71,    72,    73,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    49,    88,   110,   110,   110,    33,     1,    21,   -68,
      95,     7,    79,   105,   106,   107,    30,    53,     6,   111,
     111,   111,    57,   109,    90,    91,   152,   153,    52,    93,
      94,   160,    78,     4,   -68,    11,     9,    80,   126,   127,
     128,   129,    84,    22,     8,    12,    22,   125,   112,   181,
     132,   150,   151,   134,   174,   175,    80,    19,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   168,    60,    24,     1,   103,   104,   105,   106,   107,
      14,   177,    62,   125,   125,    23,   108,   109,    31,    25,
      54,    63,    64,    58,   182,   183,   135,    60,    65,    47,
      66,    67,    61,    55,    68,    75,   172,    62,    11,    59,
     173,    89,   133,    56,    76,   179,    63,    64,    12,   169,
      77,   171,    32,    65,    47,    66,    67,    60,   125,    68,
      50,    49,   156,   178,    81,    82,    69,    62,   125,    83,
      86,   157,    87,    92,   113,    80,    63,    64,   130,   110,
     131,   125,   125,    65,    47,    66,    67,   136,    39,    68,
      40,   154,   165,   155,   158,    41,    89,    42,   166,    39,
      43,    40,   167,   180,    44,    45,    41,   172,    42,    26,
      37,    43,   114,    85,   115,    44,    45,    51,    38,   116,
     159,   170,    46,    47,   117,     0,   163,     0,   118,   119,
      96,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,    46,    47,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
     108,   109,     0,     0,     0,   135,     0,     0,   162,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,   108,   109
};

static const yytype_int16 yycheck[] =
{
      29,    29,    61,     3,     3,     3,    21,     9,     4,    25,
      69,    15,    25,    34,    35,    36,    19,    32,     0,    19,
      19,    19,    15,    44,    63,    64,   112,   113,    31,    68,
      69,    25,    48,    39,    50,     6,    37,    50,    77,    78,
      79,    80,    57,    39,    48,    16,    39,    76,    48,    48,
      89,   110,   111,    92,    10,    11,    50,    48,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   157,    13,     8,     9,    32,    33,    34,    35,    36,
      39,   167,    23,   112,   113,    38,    43,    44,    49,    24,
      50,    32,    33,    48,   180,   181,    53,    13,    39,    40,
      41,    42,    18,    50,    45,    39,    49,    23,     6,    48,
      53,    52,    53,    50,    48,   174,    32,    33,    16,   158,
      48,   160,    20,    39,    40,    41,    42,    13,   157,    45,
     159,   159,    39,   172,    51,    41,    52,    23,   167,    41,
      39,    48,    39,    52,    48,    50,    32,    33,    51,     3,
      51,   180,   181,    39,    40,    41,    42,    53,     5,    45,
       7,    48,    39,    48,    48,    12,    52,    14,    39,     5,
      17,     7,    48,    48,    21,    22,    12,    49,    14,    18,
      24,    17,     5,    57,     7,    21,    22,    30,    25,    12,
     120,    38,    39,    40,    17,    -1,   134,    -1,    21,    22,
      69,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    32,
      33,    34,    35,    36,    -1,    43,    44,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    53,    -1,    -1,    51,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      32,    33,    34,    35,    36,    -1,    43,    44,    -1,    -1,
      -1,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    55,    56,    39,    59,     0,    15,    48,    37,
      57,     6,    16,    62,    39,    61,    69,    58,    66,    48,
      60,     4,    39,    38,     8,    24,    56,    67,    68,    70,
      61,    49,    20,    62,    63,    64,    65,    59,    69,     5,
       7,    12,    14,    17,    21,    22,    39,    40,    72,    77,
      80,    60,    61,    62,    50,    50,    50,    15,    48,    48,
      13,    18,    23,    32,    33,    39,    41,    42,    45,    52,
      79,    80,    81,    82,    83,    39,    48,    48,    48,    25,
      50,    51,    41,    41,    62,    63,    39,    39,    82,    52,
      81,    81,    52,    81,    81,    82,    83,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    43,    44,
       3,    19,    48,    48,     5,     7,    12,    17,    21,    22,
      37,    71,    75,    76,    77,    80,    81,    81,    81,    81,
      51,    51,    81,    53,    81,    53,    53,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    75,    75,    48,    48,    39,    48,    48,    70,
      25,    78,    51,    78,    74,    39,    39,    48,    75,    81,
      38,    81,    49,    53,    10,    11,    73,    75,    81,    82,
      48,    48,    75,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    57,    58,    59,    59,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     1,     3,     6,     4,
       0,     3,     3,     1,     1,     1,     4,     1,     2,     1,
       3,     4,     0,     2,     2,     2,     2,     4,     1,     2,
       0,     2,     1,     3,     1,     1,     3,     3,     4,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     6,     3,
       4,     1,     3,     1,     3,     0,     3,     0,     5,     1,
       1,     3,     1,     4,     0,     3,     3,     5,     1,     1,
       4,     1,     1,     1,     3,     1,     2,     2,     3,     3,
       3,     3,     3,     1,     1,     2,     3,     3,     1,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: func_def  */
#line 143 "src/llvm/parser.y"
                                                  {program_ast = (yyvsp[0].func_def);}
#line 1578 "src/llvm/parser.cpp"
    break;

  case 3: /* func_def: "def" header indented_local_def_and_block  */
#line 147 "src/llvm/parser.y"
                                                  {(yyval.func_def) = new FuncDef((yyvsp[-1].header), (yyvsp[0].local_def_and_stmts_pair)->first, new Block(new Stmt((yyvsp[0].local_def_and_stmts_pair)->second)));}
#line 1584 "src/llvm/parser.cpp"
    break;

  case 4: /* indented_local_def_and_block: "INDENT" local_def_and_stmts "DEDENT"  */
#line 151 "src/llvm/parser.y"
                                                  {(yyval.local_def_and_stmts_pair) = (yyvsp[-1].local_def_and_stmts_pair);}
#line 1590 "src/llvm/parser.cpp"
    break;

  case 5: /* local_def_and_stmts: local_def stmt_list  */
#line 155 "src/llvm/parser.y"
                                                  {(yyval.local_def_and_stmts_pair) = new std::pair<LocalDef*, StmtList*>((yyvsp[-1].local_def), (yyvsp[0].stmt_list));}
#line 1596 "src/llvm/parser.cpp"
    break;

  case 6: /* header: T_id  */
#line 159 "src/llvm/parser.y"
                                                  {(yyval.header) = new Header(new Id((yyvsp[0].var)), TYPE_void, nullptr);}
#line 1602 "src/llvm/parser.cpp"
    break;

  case 7: /* header: T_id "is" data_type  */
#line 160 "src/llvm/parser.y"
                                                  {(yyval.header) = new Header(new Id((yyvsp[-2].var)), (yyvsp[0].data_type), nullptr);}
#line 1608 "src/llvm/parser.cpp"
    break;

  case 8: /* header: T_id "is" data_type ':' fpar_def header_aux  */
#line 161 "src/llvm/parser.y"
                                                  {(yyvsp[0].header_aux)->insert_front((yyvsp[-1].fpar_def)); (yyval.header) = new Header(new Id((yyvsp[-5].var)), (yyvsp[-3].data_type), (yyvsp[0].header_aux));}
#line 1614 "src/llvm/parser.cpp"
    break;

  case 9: /* header: T_id ':' fpar_def header_aux  */
#line 162 "src/llvm/parser.y"
                                                  {(yyvsp[0].header_aux)->insert_front((yyvsp[-1].fpar_def)); (yyval.header) = new Header(new Id((yyvsp[-3].var)), TYPE_void, (yyvsp[0].header_aux));}
#line 1620 "src/llvm/parser.cpp"
    break;

  case 10: /* header_aux: %empty  */
#line 166 "src/llvm/parser.y"
                                                  {(yyval.header_aux) = new HeaderAux();}
#line 1626 "src/llvm/parser.cpp"
    break;

  case 11: /* header_aux: header_aux ',' fpar_def  */
#line 167 "src/llvm/parser.y"
                                                  {(yyvsp[-2].header_aux)->append((yyvsp[0].fpar_def)); (yyval.header_aux) = (yyvsp[-2].header_aux);}
#line 1632 "src/llvm/parser.cpp"
    break;

  case 12: /* fpar_def: id_aux "as" fpar_type  */
#line 171 "src/llvm/parser.y"
                                                  {(yyval.fpar_def) = new FparDef((yyvsp[-2].id_aux), (yyvsp[0].fpar_type));}
#line 1638 "src/llvm/parser.cpp"
    break;

  case 13: /* data_type: "int"  */
#line 175 "src/llvm/parser.y"
                                                  {(yyval.data_type) = TYPE_int;}
#line 1644 "src/llvm/parser.cpp"
    break;

  case 14: /* data_type: "byte"  */
#line 176 "src/llvm/parser.y"
                                                  {(yyval.data_type) = TYPE_byte;}
#line 1650 "src/llvm/parser.cpp"
    break;

  case 15: /* type: data_type  */
#line 180 "src/llvm/parser.y"
                                                  {(yyval.type) = new Type_((yyvsp[0].data_type));}
#line 1656 "src/llvm/parser.cpp"
    break;

  case 16: /* type: type '[' T_intconst ']'  */
#line 181 "src/llvm/parser.y"
                                                  {(yyvsp[-3].type)->append(new Int((yyvsp[-1].num))); (yyval.type) = (yyvsp[-3].type);}
#line 1662 "src/llvm/parser.cpp"
    break;

  case 17: /* fpar_type: type  */
#line 185 "src/llvm/parser.y"
                                                  {(yyval.fpar_type) = new FparType((yyvsp[0].type));}
#line 1668 "src/llvm/parser.cpp"
    break;

  case 18: /* fpar_type: "ref" data_type  */
#line 186 "src/llvm/parser.y"
                                                  {(yyval.fpar_type) = new FparType(nullptr, (yyvsp[0].data_type));}
#line 1674 "src/llvm/parser.cpp"
    break;

  case 19: /* fpar_type: array_type  */
#line 187 "src/llvm/parser.y"
                                                  {(yyval.fpar_type) = new FparType(nullptr, UNDEFINED, (yyvsp[0].array_type));}
#line 1680 "src/llvm/parser.cpp"
    break;

  case 20: /* array_type: data_type '[' ']'  */
#line 191 "src/llvm/parser.y"
                                                  {(yyval.array_type) = new ArrayType_((yyvsp[-2].data_type));}
#line 1686 "src/llvm/parser.cpp"
    break;

  case 21: /* array_type: array_type '[' T_intconst ']'  */
#line 192 "src/llvm/parser.y"
                                                  {(yyvsp[-3].array_type)->append(new Int((yyvsp[-1].num))); (yyval.array_type) = (yyvsp[-3].array_type);}
#line 1692 "src/llvm/parser.cpp"
    break;

  case 22: /* local_def: %empty  */
#line 196 "src/llvm/parser.y"
                                                  {(yyval.local_def) = new LocalDef();}
#line 1698 "src/llvm/parser.cpp"
    break;

  case 23: /* local_def: local_def func_def  */
#line 197 "src/llvm/parser.y"
                                                  {(yyvsp[-1].local_def)->append((yyvsp[0].func_def)); (yyval.local_def) = (yyvsp[-1].local_def);}
#line 1704 "src/llvm/parser.cpp"
    break;

  case 24: /* local_def: local_def func_decl  */
#line 198 "src/llvm/parser.y"
                                                  {(yyvsp[-1].local_def)->append((yyvsp[0].func_decl)); (yyval.local_def) = (yyvsp[-1].local_def);}
#line 1710 "src/llvm/parser.cpp"
    break;

  case 25: /* local_def: local_def var_def  */
#line 199 "src/llvm/parser.y"
                                                  {(yyvsp[-1].local_def)->append((yyvsp[0].var_def)); (yyval.local_def) = (yyvsp[-1].local_def);}
#line 1716 "src/llvm/parser.cpp"
    break;

  case 26: /* func_decl: "decl" header  */
#line 203 "src/llvm/parser.y"
                                                 {(yyval.func_decl) = new FuncDecl((yyvsp[0].header));}
#line 1722 "src/llvm/parser.cpp"
    break;

  case 27: /* var_def: "var" id_aux "is" type  */
#line 207 "src/llvm/parser.y"
                                                 {(yyval.var_def) = new VarDef((yyvsp[-2].id_aux), (yyvsp[0].type));}
#line 1728 "src/llvm/parser.cpp"
    break;

  case 28: /* id_aux: T_id  */
#line 211 "src/llvm/parser.y"
                                                 {(yyval.id_aux) = new IdAux(new Id((yyvsp[0].var)));}
#line 1734 "src/llvm/parser.cpp"
    break;

  case 29: /* id_aux: id_aux T_id  */
#line 212 "src/llvm/parser.y"
                                                 {(yyvsp[-1].id_aux)->append(new Id((yyvsp[0].var))); (yyval.id_aux) = (yyvsp[-1].id_aux);}
#line 1740 "src/llvm/parser.cpp"
    break;

  case 30: /* stmt_list: %empty  */
#line 216 "src/llvm/parser.y"
                                                 {(yyval.stmt_list) = new StmtList();}
#line 1746 "src/llvm/parser.cpp"
    break;

  case 31: /* stmt_list: stmt_list simple_stmt  */
#line 217 "src/llvm/parser.y"
                                                 {(yyvsp[-1].stmt_list)->append((yyvsp[0].simple_stmt)); (yyval.stmt_list) = (yyvsp[-1].stmt_list);}
#line 1752 "src/llvm/parser.cpp"
    break;

  case 32: /* simple_stmt_no_colon: "skip"  */
#line 221 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Skip();}
#line 1758 "src/llvm/parser.cpp"
    break;

  case 33: /* simple_stmt_no_colon: l_value ":=" expr  */
#line 222 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Assign((yyvsp[-2].l_val), (yyvsp[0].expr));}
#line 1764 "src/llvm/parser.cpp"
    break;

  case 34: /* simple_stmt_no_colon: proc_call  */
#line 223 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = (yyvsp[0].proc_call);}
#line 1770 "src/llvm/parser.cpp"
    break;

  case 35: /* simple_stmt_no_colon: "exit"  */
#line 224 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Exit();}
#line 1776 "src/llvm/parser.cpp"
    break;

  case 36: /* simple_stmt_no_colon: "return" ':' expr  */
#line 225 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Return((yyvsp[0].expr));}
#line 1782 "src/llvm/parser.cpp"
    break;

  case 37: /* simple_stmt_no_colon: "loop" ':' block  */
#line 226 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Loop((yyvsp[0].block));}
#line 1788 "src/llvm/parser.cpp"
    break;

  case 38: /* simple_stmt_no_colon: "loop" T_id ':' block  */
#line 227 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Loop((yyvsp[0].block), new Id((yyvsp[-2].var)));}
#line 1794 "src/llvm/parser.cpp"
    break;

  case 39: /* simple_stmt_no_colon: "break"  */
#line 228 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Break();}
#line 1800 "src/llvm/parser.cpp"
    break;

  case 40: /* simple_stmt_no_colon: "break" ':' T_id  */
#line 229 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Break(new Id((yyvsp[0].var)));}
#line 1806 "src/llvm/parser.cpp"
    break;

  case 41: /* simple_stmt_no_colon: "continue"  */
#line 230 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Continue();}
#line 1812 "src/llvm/parser.cpp"
    break;

  case 42: /* simple_stmt_no_colon: "continue" ':' T_id  */
#line 231 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Continue(new Id((yyvsp[0].var)));}
#line 1818 "src/llvm/parser.cpp"
    break;

  case 43: /* simple_stmt: "skip"  */
#line 235 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Skip();}
#line 1824 "src/llvm/parser.cpp"
    break;

  case 44: /* simple_stmt: l_value ":=" expr  */
#line 236 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Assign((yyvsp[-2].l_val), (yyvsp[0].expr));}
#line 1830 "src/llvm/parser.cpp"
    break;

  case 45: /* simple_stmt: proc_call  */
#line 237 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = (yyvsp[0].proc_call);}
#line 1836 "src/llvm/parser.cpp"
    break;

  case 46: /* simple_stmt: "exit"  */
#line 238 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Exit();}
#line 1842 "src/llvm/parser.cpp"
    break;

  case 47: /* simple_stmt: "return" ':' expr  */
#line 239 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Return((yyvsp[0].expr));}
#line 1848 "src/llvm/parser.cpp"
    break;

  case 48: /* simple_stmt: "if" cond ':' block if_aux else_part  */
#line 240 "src/llvm/parser.y"
                                                 {
        if ((yyvsp[0].block) != nullptr) {
            (yyval.simple_stmt) = new If((yyvsp[-4].cond), (yyvsp[-2].block), (yyvsp[0].block), (yyvsp[-1].if_aux));
        } else {
            (yyval.simple_stmt) = new If((yyvsp[-4].cond), (yyvsp[-2].block), nullptr, (yyvsp[-1].if_aux));
        }
    }
#line 1860 "src/llvm/parser.cpp"
    break;

  case 49: /* simple_stmt: "loop" ':' block  */
#line 247 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Loop((yyvsp[0].block));}
#line 1866 "src/llvm/parser.cpp"
    break;

  case 50: /* simple_stmt: "loop" T_id ':' block  */
#line 248 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Loop((yyvsp[0].block), new Id((yyvsp[-2].var)));}
#line 1872 "src/llvm/parser.cpp"
    break;

  case 51: /* simple_stmt: "break"  */
#line 249 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Break();}
#line 1878 "src/llvm/parser.cpp"
    break;

  case 52: /* simple_stmt: "break" ':' T_id  */
#line 250 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Break(new Id((yyvsp[0].var)));}
#line 1884 "src/llvm/parser.cpp"
    break;

  case 53: /* simple_stmt: "continue"  */
#line 251 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Continue();}
#line 1890 "src/llvm/parser.cpp"
    break;

  case 54: /* simple_stmt: "continue" ':' T_id  */
#line 252 "src/llvm/parser.y"
                                                 {(yyval.simple_stmt) = new Continue(new Id((yyvsp[0].var)));}
#line 1896 "src/llvm/parser.cpp"
    break;

  case 55: /* else_part: %empty  */
#line 256 "src/llvm/parser.y"
                                                 {(yyval.block) = nullptr;}
#line 1902 "src/llvm/parser.cpp"
    break;

  case 56: /* else_part: "else" ':' block  */
#line 257 "src/llvm/parser.y"
                                                 {(yyval.block) = (yyvsp[0].block);}
#line 1908 "src/llvm/parser.cpp"
    break;

  case 57: /* if_aux: %empty  */
#line 261 "src/llvm/parser.y"
                                                 {(yyval.if_aux) = new IfAux();}
#line 1914 "src/llvm/parser.cpp"
    break;

  case 58: /* if_aux: if_aux "elif" cond ':' block  */
#line 262 "src/llvm/parser.y"
                                                 {(yyvsp[-4].if_aux)->append(new Elif((yyvsp[-2].cond), (yyvsp[0].block))); (yyval.if_aux) = (yyvsp[-4].if_aux);}
#line 1920 "src/llvm/parser.cpp"
    break;

  case 59: /* block: indented_stmt_list  */
#line 266 "src/llvm/parser.y"
                                                 {(yyval.block) = new Block(new Stmt((yyvsp[0].stmt_list)));}
#line 1926 "src/llvm/parser.cpp"
    break;

  case 60: /* block: simple_stmt_no_colon  */
#line 267 "src/llvm/parser.y"
                                                 {StmtList *sl = new StmtList(); sl->append((yyvsp[0].simple_stmt)); (yyval.block) = new Block(new Stmt(sl));}
#line 1932 "src/llvm/parser.cpp"
    break;

  case 61: /* indented_stmt_list: "INDENT" stmt_list "DEDENT"  */
#line 271 "src/llvm/parser.y"
                                                 {(yyval.stmt_list) = (yyvsp[-1].stmt_list);}
#line 1938 "src/llvm/parser.cpp"
    break;

  case 62: /* proc_call: T_id  */
#line 275 "src/llvm/parser.y"
                                {(yyval.proc_call) = new ProcCall(new Id((yyvsp[0].var)));}
#line 1944 "src/llvm/parser.cpp"
    break;

  case 63: /* proc_call: T_id ':' expr expr_aux  */
#line 276 "src/llvm/parser.y"
                                {(yyvsp[0].expr_aux)->insert_front((yyvsp[-1].expr)); (yyval.proc_call) = new ProcCall(new Id((yyvsp[-3].var)), (yyvsp[0].expr_aux));}
#line 1950 "src/llvm/parser.cpp"
    break;

  case 64: /* expr_aux: %empty  */
#line 280 "src/llvm/parser.y"
                                {(yyval.expr_aux) = new ExprAux();}
#line 1956 "src/llvm/parser.cpp"
    break;

  case 65: /* expr_aux: expr_aux ',' expr  */
#line 281 "src/llvm/parser.y"
                                {(yyvsp[-2].expr_aux)->append((yyvsp[0].expr)); (yyval.expr_aux) = (yyvsp[-2].expr_aux);}
#line 1962 "src/llvm/parser.cpp"
    break;

  case 66: /* func_call: T_id '(' ')'  */
#line 285 "src/llvm/parser.y"
                                {(yyval.func_call) = new FuncCall(new Id((yyvsp[-2].var)));}
#line 1968 "src/llvm/parser.cpp"
    break;

  case 67: /* func_call: T_id '(' expr expr_aux ')'  */
#line 286 "src/llvm/parser.y"
                                {(yyvsp[-1].expr_aux)->insert_front((yyvsp[-2].expr)); (yyval.func_call) = new FuncCall(new Id((yyvsp[-4].var)), (yyvsp[-1].expr_aux));}
#line 1974 "src/llvm/parser.cpp"
    break;

  case 68: /* l_value: T_id  */
#line 290 "src/llvm/parser.y"
                                {(yyval.l_val) = new L_val(new Id((yyvsp[0].var)));}
#line 1980 "src/llvm/parser.cpp"
    break;

  case 69: /* l_value: T_string  */
#line 291 "src/llvm/parser.y"
                                {(yyval.l_val) = new L_val(nullptr, std::string((yyvsp[0].string)));}
#line 1986 "src/llvm/parser.cpp"
    break;

  case 70: /* l_value: l_value '[' expr ']'  */
#line 292 "src/llvm/parser.y"
                                {(yyvsp[-3].l_val)->append((yyvsp[-1].expr)); (yyval.l_val) = (yyvsp[-3].l_val);}
#line 1992 "src/llvm/parser.cpp"
    break;

  case 71: /* expr: T_intconst  */
#line 296 "src/llvm/parser.y"
                                {(yyval.expr) = new Int((yyvsp[0].num));}
#line 1998 "src/llvm/parser.cpp"
    break;

  case 72: /* expr: T_charconst  */
#line 297 "src/llvm/parser.y"
                                {(yyval.expr) = new Char((yyvsp[0].character));}
#line 2004 "src/llvm/parser.cpp"
    break;

  case 73: /* expr: l_value  */
#line 298 "src/llvm/parser.y"
                                {(yyvsp[0].l_val)->fromExpr(true); (yyval.expr) = (yyvsp[0].l_val);}
#line 2010 "src/llvm/parser.cpp"
    break;

  case 74: /* expr: '(' expr ')'  */
#line 299 "src/llvm/parser.y"
                                {(yyval.expr) = (yyvsp[-1].expr);}
#line 2016 "src/llvm/parser.cpp"
    break;

  case 75: /* expr: func_call  */
#line 300 "src/llvm/parser.y"
                                {(yyval.expr) = (yyvsp[0].func_call);}
#line 2022 "src/llvm/parser.cpp"
    break;

  case 76: /* expr: "-" expr  */
#line 301 "src/llvm/parser.y"
                                {(yyval.expr) = new UnOp((yyvsp[-1].op), (yyvsp[0].expr));}
#line 2028 "src/llvm/parser.cpp"
    break;

  case 77: /* expr: "+" expr  */
#line 302 "src/llvm/parser.y"
                                {(yyval.expr) = new UnOp((yyvsp[-1].op), (yyvsp[0].expr));}
#line 2034 "src/llvm/parser.cpp"
    break;

  case 78: /* expr: expr "+" expr  */
#line 303 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2040 "src/llvm/parser.cpp"
    break;

  case 79: /* expr: expr "-" expr  */
#line 304 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2046 "src/llvm/parser.cpp"
    break;

  case 80: /* expr: expr "*" expr  */
#line 305 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2052 "src/llvm/parser.cpp"
    break;

  case 81: /* expr: expr "/" expr  */
#line 306 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2058 "src/llvm/parser.cpp"
    break;

  case 82: /* expr: expr "%" expr  */
#line 307 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2064 "src/llvm/parser.cpp"
    break;

  case 83: /* expr: "true"  */
#line 308 "src/llvm/parser.y"
                                {(yyval.expr) = new Bool(true);}
#line 2070 "src/llvm/parser.cpp"
    break;

  case 84: /* expr: "false"  */
#line 309 "src/llvm/parser.y"
                                {(yyval.expr) = new Bool(false);}
#line 2076 "src/llvm/parser.cpp"
    break;

  case 85: /* expr: '!' expr  */
#line 310 "src/llvm/parser.y"
                                {(yyval.expr) = new UnOp((yyvsp[-1].op), (yyvsp[0].expr));}
#line 2082 "src/llvm/parser.cpp"
    break;

  case 86: /* expr: expr '&' expr  */
#line 311 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2088 "src/llvm/parser.cpp"
    break;

  case 87: /* expr: expr '|' expr  */
#line 312 "src/llvm/parser.y"
                                {(yyval.expr) = new BinOp((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2094 "src/llvm/parser.cpp"
    break;

  case 88: /* cond: expr  */
#line 316 "src/llvm/parser.y"
                                {(yyval.cond) = new ExprCond((yyvsp[0].expr));}
#line 2100 "src/llvm/parser.cpp"
    break;

  case 89: /* cond: '(' cond_aux ')'  */
#line 317 "src/llvm/parser.y"
                                {(yyval.cond) = (yyvsp[-1].cond);}
#line 2106 "src/llvm/parser.cpp"
    break;

  case 90: /* cond: cond_aux  */
#line 318 "src/llvm/parser.y"
                                {(yyval.cond) = (yyvsp[0].cond);}
#line 2112 "src/llvm/parser.cpp"
    break;

  case 91: /* cond_aux: "not" cond  */
#line 322 "src/llvm/parser.y"
                                {(yyval.cond) = new UnOpCond((yyvsp[-1].op), (yyvsp[0].cond));}
#line 2118 "src/llvm/parser.cpp"
    break;

  case 92: /* cond_aux: cond "and" cond  */
#line 323 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].cond), (yyvsp[-1].op), (yyvsp[0].cond));}
#line 2124 "src/llvm/parser.cpp"
    break;

  case 93: /* cond_aux: cond "or" cond  */
#line 324 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].cond), (yyvsp[-1].op), (yyvsp[0].cond));}
#line 2130 "src/llvm/parser.cpp"
    break;

  case 94: /* cond_aux: expr "=" expr  */
#line 325 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2136 "src/llvm/parser.cpp"
    break;

  case 95: /* cond_aux: expr "<>" expr  */
#line 326 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2142 "src/llvm/parser.cpp"
    break;

  case 96: /* cond_aux: expr "<" expr  */
#line 327 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2148 "src/llvm/parser.cpp"
    break;

  case 97: /* cond_aux: expr ">" expr  */
#line 328 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2154 "src/llvm/parser.cpp"
    break;

  case 98: /* cond_aux: expr "<=" expr  */
#line 329 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2160 "src/llvm/parser.cpp"
    break;

  case 99: /* cond_aux: expr ">=" expr  */
#line 330 "src/llvm/parser.y"
                                {(yyval.cond) = new BinOpCond((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr));}
#line 2166 "src/llvm/parser.cpp"
    break;


#line 2170 "src/llvm/parser.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 332 "src/llvm/parser.y"


void yyerror (const std::string msg) {
    std::cerr << "Error: " << msg << " in line " << linenum << "\n";
    exit(1);
}

void print_usage(const char* program_name) {
    std::cerr << "Usage: " << program_name << " [options] [input_file]\n";
    std::cerr << "Options:\n";
    std::cerr << "  -i              Output intermediate code (LLVM IR) to stdout\n";
    std::cerr << "  -f              Output final code (Assembly) to stdout\n";
    std::cerr << "  -O              Enable optimizations\n";
    std::cerr << "  -o <file>       Output executable to <file> (default: a.out)\n";
    std::cerr << "\n";
    std::cerr << "If no -i or -f flags are given:\n";
    std::cerr << "  - Intermediate code (.imm) and assembly (.asm) files are created\n";
    std::cerr << "  - Files are placed in the same directory as the input file\n";
    std::cerr << "\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << program_name << " program.dana           # Creates program.imm, program.asm, a.out\n";
    std::cerr << "  " << program_name << " -O program.dana       # Same with optimizations\n";
    std::cerr << "  " << program_name << " -o myapp program.dana # Creates myapp executable\n";
    std::cerr << "  " << program_name << " -i < program.dana     # Output LLVM IR to stdout\n";
    std::cerr << "  " << program_name << " -f < program.dana     # Output assembly to stdout\n";
}

int main(int argc, char** argv) {
    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-i") {
            flag_i = true;
        } else if (arg == "-f") {
            flag_f = true;
        } else if (arg == "-O") {
            flag_O = true;
        } else if (arg == "-o") {
            if (i + 1 < argc) {
                output_file = argv[++i];
            } else {
                std::cerr << "Error: -o requires an argument\n";
                print_usage(argv[0]);
                return 1;
            }
        } else if (arg == "-h" || arg == "--help") {
            print_usage(argv[0]);
            return 0;
        } else if (arg[0] == '-') {
            std::cerr << "Error: Unknown option '" << arg << "'\n";
            print_usage(argv[0]);
            return 1;
        } else {
            // This is the input file
            input_file = arg;
        }
    }
    
    // Validate options
    if (flag_i && flag_f) {
        std::cerr << "Error: Cannot specify both -i and -f\n";
        return 1;
    }
    
    // If reading from stdin (-i or -f), input_file should be empty
    // If reading from file, input_file should be set
    if (!flag_i && !flag_f && input_file.empty()) {
        std::cerr << "Error: No input file specified\n";
        print_usage(argv[0]);
        return 1;
    }
    
    // Open input file if specified
    FILE* input = stdin;
    if (!input_file.empty()) {
        input = fopen(input_file.c_str(), "r");
        if (!input) {
            std::cerr << "Error: Cannot open input file '" << input_file << "'\n";
            return 1;
        }
        yyin = input;
    }
    
    // Redirect logging
    std::ofstream logfile("mylog.txt");
    auto* oldbuf = std::clog.rdbuf(logfile.rdbuf());
    
    // Parse the input
    int parse_result = yyparse();
    
    if (parse_result != 0) {
        std::clog.rdbuf(oldbuf);
        if (input != stdin) fclose(input);
        return 1;
    }
    
    // Now compile the program
    if (program_ast) {
        try {
            program_ast->compile(input_file, flag_i, flag_f, flag_O, output_file);
        } catch (const std::exception& e) {
            std::cerr << "Compilation error: " << e.what() << "\n";
            std::clog.rdbuf(oldbuf);
            if (input != stdin) fclose(input);
            return 1;
        }
    } else {
        std::cerr << "Error: No program to compile\n";
        std::clog.rdbuf(oldbuf);
        if (input != stdin) fclose(input);
        return 1;
    }
    
    std::clog.rdbuf(oldbuf);
    if (input != stdin) fclose(input);
    
    return 0;
}
