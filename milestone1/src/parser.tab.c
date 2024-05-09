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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<bits/stdc++.h>
    using namespace std;
    #include "ast1.h"
    extern int yylex();
    #define YYERROR_VERBOSE 1
    // extern int yyparse();
    extern FILE *yyin;
     extern int yylineno;
     extern int yydebug;
    
    extern FILE *yyout;

    FILE *program;
    string input_file = "../tests/test1.py";
    string output_file = "graph.dot"; 
    void yyerror(const char *s) {
 
    fprintf(stderr, "Error at line %d: %s\n",yylineno, s);}
    Node *root = NULL;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *temp = new Node();
    temp->value = value;
    temp->children = children;
    temp->label = label;
    
    return temp;
}
   

#line 104 "parser.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_DELIMITER = 4,                  /* DELIMITER  */
  YYSYMBOL_FLOATING_POINT = 5,             /* FLOATING_POINT  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_STR_LIT = 10,                   /* STR_LIT  */
  YYSYMBOL_BYT_LIT = 11,                   /* BYT_LIT  */
  YYSYMBOL_STR = 12,                       /* STR  */
  YYSYMBOL_LIST = 13,                      /* LIST  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_BOOL = 15,                      /* BOOL  */
  YYSYMBOL_EQUALS = 16,                    /* EQUALS  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_TIMES = 19,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 20,                 /* DIVIDEDBY  */
  YYSYMBOL_NEWLINE = 21,                   /* NEWLINE  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_MODULO = 23,                    /* MODULO  */
  YYSYMBOL_AUGPLUS = 24,                   /* AUGPLUS  */
  YYSYMBOL_AUGMINUS = 25,                  /* AUGMINUS  */
  YYSYMBOL_AUGTIMES = 26,                  /* AUGTIMES  */
  YYSYMBOL_AUGDIVIDEDBY = 27,              /* AUGDIVIDEDBY  */
  YYSYMBOL_AUGMOD = 28,                    /* AUGMOD  */
  YYSYMBOL_AUGMODULO = 29,                 /* AUGMODULO  */
  YYSYMBOL_POW = 30,                       /* POW  */
  YYSYMBOL_AUGPOW = 31,                    /* AUGPOW  */
  YYSYMBOL_BIT_AND = 32,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 33,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 34,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 35,                   /* BIT_NOT  */
  YYSYMBOL_BIT_RSHIFT = 36,                /* BIT_RSHIFT  */
  YYSYMBOL_BIT_LSHIFT = 37,                /* BIT_LSHIFT  */
  YYSYMBOL_AUGBIT_AND = 38,                /* AUGBIT_AND  */
  YYSYMBOL_AUGBIT_OR = 39,                 /* AUGBIT_OR  */
  YYSYMBOL_AUGBIT_XOR = 40,                /* AUGBIT_XOR  */
  YYSYMBOL_AUGBIT_NOT = 41,                /* AUGBIT_NOT  */
  YYSYMBOL_AUGBIT_RSHIFT = 42,             /* AUGBIT_RSHIFT  */
  YYSYMBOL_AUGBIT_LSHIFT = 43,             /* AUGBIT_LSHIFT  */
  YYSYMBOL_LPAREN = 44,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 45,                    /* RPAREN  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 49,                 /* SEMICOLON  */
  YYSYMBOL_LLIST = 50,                     /* LLIST  */
  YYSYMBOL_RLIST = 51,                     /* RLIST  */
  YYSYMBOL_R_ARR = 52,                     /* R_ARR  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_NEQ = 54,                       /* NEQ  */
  YYSYMBOL_GT = 55,                        /* GT  */
  YYSYMBOL_GTE = 56,                       /* GTE  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_LTE = 58,                       /* LTE  */
  YYSYMBOL_HEX = 59,                       /* HEX  */
  YYSYMBOL_INT = 60,                       /* INT  */
  YYSYMBOL_AWAIT = 61,                     /* AWAIT  */
  YYSYMBOL_LEN = 62,                       /* LEN  */
  YYSYMBOL_AND = 63,                       /* AND  */
  YYSYMBOL_BREAK = 64,                     /* BREAK  */
  YYSYMBOL_DEF = 65,                       /* DEF  */
  YYSYMBOL_ELIF = 66,                      /* ELIF  */
  YYSYMBOL_ELSE = 67,                      /* ELSE  */
  YYSYMBOL_FOR = 68,                       /* FOR  */
  YYSYMBOL_IF = 69,                        /* IF  */
  YYSYMBOL_ENDMARKER = 70,                 /* ENDMARKER  */
  YYSYMBOL_RANGE = 71,                     /* RANGE  */
  YYSYMBOL_NOT = 72,                       /* NOT  */
  YYSYMBOL_OR = 73,                        /* OR  */
  YYSYMBOL_RETURN = 74,                    /* RETURN  */
  YYSYMBOL_WHILE = 75,                     /* WHILE  */
  YYSYMBOL_INDENT = 76,                    /* INDENT  */
  YYSYMBOL_DEDENT = 77,                    /* DEDENT  */
  YYSYMBOL_NONE = 78,                      /* NONE  */
  YYSYMBOL_IS = 79,                        /* IS  */
  YYSYMBOL_IN = 80,                        /* IN  */
  YYSYMBOL_CONTINUE = 81,                  /* CONTINUE  */
  YYSYMBOL_ASSERT = 82,                    /* ASSERT  */
  YYSYMBOL_NONLOCAL = 83,                  /* NONLOCAL  */
  YYSYMBOL_GLOBAL = 84,                    /* GLOBAL  */
  YYSYMBOL_CLASS = 85,                     /* CLASS  */
  YYSYMBOL_ASYNC = 86,                     /* ASYNC  */
  YYSYMBOL_IMPORT = 87,                    /* IMPORT  */
  YYSYMBOL_PASS = 88,                      /* PASS  */
  YYSYMBOL_EXCEPT = 89,                    /* EXCEPT  */
  YYSYMBOL_RAISE = 90,                     /* RAISE  */
  YYSYMBOL_FINALLY = 91,                   /* FINALLY  */
  YYSYMBOL_LAMBDA = 92,                    /* LAMBDA  */
  YYSYMBOL_TRY = 93,                       /* TRY  */
  YYSYMBOL_AS = 94,                        /* AS  */
  YYSYMBOL_FROM = 95,                      /* FROM  */
  YYSYMBOL_DEL = 96,                       /* DEL  */
  YYSYMBOL_WITH = 97,                      /* WITH  */
  YYSYMBOL_YIELD = 98,                     /* YIELD  */
  YYSYMBOL_YYACCEPT = 99,                  /* $accept  */
  YYSYMBOL_file = 100,                     /* file  */
  YYSYMBOL_single_inputs = 101,            /* single_inputs  */
  YYSYMBOL_single_input = 102,             /* single_input  */
  YYSYMBOL_funcdef = 103,                  /* funcdef  */
  YYSYMBOL_rarr_test_maybe = 104,          /* rarr_test_maybe  */
  YYSYMBOL_parameters = 105,               /* parameters  */
  YYSYMBOL_arguments = 106,                /* arguments  */
  YYSYMBOL_argument_a = 107,               /* argument_a  */
  YYSYMBOL_comm_arg_a = 108,               /* comm_arg_a  */
  YYSYMBOL_equals_test_maybe = 109,        /* equals_test_maybe  */
  YYSYMBOL_kwargs = 110,                   /* kwargs  */
  YYSYMBOL_comma_maybe = 111,              /* comma_maybe  */
  YYSYMBOL_args = 112,                     /* args  */
  YYSYMBOL_kwonly_kwargs = 113,            /* kwonly_kwargs  */
  YYSYMBOL_comma_kwargs_maybe = 114,       /* comma_kwargs_maybe  */
  YYSYMBOL_args_kwonly_kwargs = 115,       /* args_kwonly_kwargs  */
  YYSYMBOL_poskeyword_args_kwonly_kwargs = 116, /* poskeyword_args_kwonly_kwargs  */
  YYSYMBOL_comma_argskwonlykwargs = 117,   /* comma_argskwonlykwargs  */
  YYSYMBOL_typedargslist_no_posonly = 118, /* typedargslist_no_posonly  */
  YYSYMBOL_typedargslist = 119,            /* typedargslist  */
  YYSYMBOL_comma_typedargs_maybe = 120,    /* comma_typedargs_maybe  */
  YYSYMBOL_tfpdef = 121,                   /* tfpdef  */
  YYSYMBOL_colon_test_maybe = 122,         /* colon_test_maybe  */
  YYSYMBOL_stmt = 123,                     /* stmt  */
  YYSYMBOL_simple_stmt = 124,              /* simple_stmt  */
  YYSYMBOL_small_stmt1 = 125,              /* small_stmt1  */
  YYSYMBOL_small_stmt = 126,               /* small_stmt  */
  YYSYMBOL_type1 = 127,                    /* type1  */
  YYSYMBOL_type = 128,                     /* type  */
  YYSYMBOL_expr_stmt = 129,                /* expr_stmt  */
  YYSYMBOL_expr_list = 130,                /* expr_list  */
  YYSYMBOL_eq_test = 131,                  /* eq_test  */
  YYSYMBOL_annassign = 132,                /* annassign  */
  YYSYMBOL_annassign_a = 133,              /* annassign_a  */
  YYSYMBOL_testlist_star_expr = 134,       /* testlist_star_expr  */
  YYSYMBOL_test_star = 135,                /* test_star  */
  YYSYMBOL_comm_test_star = 136,           /* comm_test_star  */
  YYSYMBOL_augassign = 137,                /* augassign  */
  YYSYMBOL_flow_stmt = 138,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 139,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 140,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 141,              /* return_stmt  */
  YYSYMBOL_global_stmt = 142,              /* global_stmt  */
  YYSYMBOL_comm_name = 143,                /* comm_name  */
  YYSYMBOL_nonlocal_stmt = 144,            /* nonlocal_stmt  */
  YYSYMBOL_assert_stmt = 145,              /* assert_stmt  */
  YYSYMBOL_comma_test_maybe = 146,         /* comma_test_maybe  */
  YYSYMBOL_compound_stmt = 147,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 148,               /* async_stmt  */
  YYSYMBOL_if_stmt = 149,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 150,               /* while_stmt  */
  YYSYMBOL_for_stmt = 151,                 /* for_stmt  */
  YYSYMBOL_else_colon_suite_maybe = 152,   /* else_colon_suite_maybe  */
  YYSYMBOL_elif_namedexprtest_colon_suite = 153, /* elif_namedexprtest_colon_suite  */
  YYSYMBOL_suite = 154,                    /* suite  */
  YYSYMBOL_stmt_morethanone = 155,         /* stmt_morethanone  */
  YYSYMBOL_test = 156,                     /* test  */
  YYSYMBOL_if_ortest_else_test_maybe = 157, /* if_ortest_else_test_maybe  */
  YYSYMBOL_or_test = 158,                  /* or_test  */
  YYSYMBOL_or_andtest = 159,               /* or_andtest  */
  YYSYMBOL_and_test = 160,                 /* and_test  */
  YYSYMBOL_and_nottest = 161,              /* and_nottest  */
  YYSYMBOL_not_test = 162,                 /* not_test  */
  YYSYMBOL_comparison = 163,               /* comparison  */
  YYSYMBOL_comp_op_expr = 164,             /* comp_op_expr  */
  YYSYMBOL_comp_op = 165,                  /* comp_op  */
  YYSYMBOL_star_expr = 166,                /* star_expr  */
  YYSYMBOL_expr = 167,                     /* expr  */
  YYSYMBOL_bitor_xorexpr = 168,            /* bitor_xorexpr  */
  YYSYMBOL_xor_expr = 169,                 /* xor_expr  */
  YYSYMBOL_bitxor_andexpr = 170,           /* bitxor_andexpr  */
  YYSYMBOL_and_expr = 171,                 /* and_expr  */
  YYSYMBOL_bitand_shiftexpr = 172,         /* bitand_shiftexpr  */
  YYSYMBOL_shift_expr = 173,               /* shift_expr  */
  YYSYMBOL_lorrshift_arithexpr = 174,      /* lorrshift_arithexpr  */
  YYSYMBOL_lshift_or_rshift = 175,         /* lshift_or_rshift  */
  YYSYMBOL_arith_expr = 176,               /* arith_expr  */
  YYSYMBOL_plusorminus_term = 177,         /* plusorminus_term  */
  YYSYMBOL_plus_or_minus = 178,            /* plus_or_minus  */
  YYSYMBOL_term = 179,                     /* term  */
  YYSYMBOL_timedivmod_factor = 180,        /* timedivmod_factor  */
  YYSYMBOL_timedivmod = 181,               /* timedivmod  */
  YYSYMBOL_factor = 182,                   /* factor  */
  YYSYMBOL_plusminusnot = 183,             /* plusminusnot  */
  YYSYMBOL_power = 184,                    /* power  */
  YYSYMBOL_pow_factor_maybe = 185,         /* pow_factor_maybe  */
  YYSYMBOL_atom_expr = 186,                /* atom_expr  */
  YYSYMBOL_trailer_ = 187,                 /* trailer_  */
  YYSYMBOL_atom = 188,                     /* atom  */
  YYSYMBOL_string_pl = 189,                /* string_pl  */
  YYSYMBOL_testlist_comp = 190,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_a = 191,          /* testlist_comp_a  */
  YYSYMBOL_comma_testorstar = 192,         /* comma_testorstar  */
  YYSYMBOL_test_or_starexpr = 193,         /* test_or_starexpr  */
  YYSYMBOL_trailer = 194,                  /* trailer  */
  YYSYMBOL_subscriptlist = 195,            /* subscriptlist  */
  YYSYMBOL_comma_subscript = 196,          /* comma_subscript  */
  YYSYMBOL_subscript = 197,                /* subscript  */
  YYSYMBOL_sliceop_maybe = 198,            /* sliceop_maybe  */
  YYSYMBOL_sliceop = 199,                  /* sliceop  */
  YYSYMBOL_exprlist = 200,                 /* exprlist  */
  YYSYMBOL_expr_str = 201,                 /* expr_str  */
  YYSYMBOL_comm_exstr = 202,               /* comm_exstr  */
  YYSYMBOL_testlist = 203,                 /* testlist  */
  YYSYMBOL_comm_test = 204,                /* comm_test  */
  YYSYMBOL_classdef = 205,                 /* classdef  */
  YYSYMBOL_l_arglist_r_maybe = 206,        /* l_arglist_r_maybe  */
  YYSYMBOL_arglist = 207,                  /* arglist  */
  YYSYMBOL_comm_arg = 208,                 /* comm_arg  */
  YYSYMBOL_argument = 209,                 /* argument  */
  YYSYMBOL_comp_iter = 210,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 211,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 212,                 /* comp_for  */
  YYSYMBOL_comp_if = 213,                  /* comp_if  */
  YYSYMBOL_func_body_suite = 214,          /* func_body_suite  */
  YYSYMBOL_func_type_input = 215,          /* func_type_input  */
  YYSYMBOL_nls = 216,                      /* nls  */
  YYSYMBOL_func_type = 217,                /* func_type  */
  YYSYMBOL_typelist = 218,                 /* typelist  */
  YYSYMBOL_comma_typel_maybe = 219,        /* comma_typel_maybe  */
  YYSYMBOL_type_l = 220,                   /* type_l  */
  YYSYMBOL_comma_pow_test_maybe = 221      /* comma_pow_test_maybe  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  100
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  123
/* YYNRULES -- Number of rules.  */
#define YYNRULES  278
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  402

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   353


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    78,    80,    83,    84,    85,    86,    87,
      90,    91,    91,    92,    94,    95,    96,    96,    98,    98,
      99,   100,   100,   101,   103,   106,   107,   110,   111,   112,
     113,   114,   115,   116,   119,   121,   122,   123,   124,   125,
     126,   127,   130,   131,   133,   135,   138,   139,   140,   141,
     142,   143,   145,   146,   148,   150,   152,   153,   154,   157,
     158,   159,   160,   161,   162,   163,   164,   169,   170,   171,
     172,   172,   173,   174,   175,   176,   176,   177,   178,   179,
     180,   181,   182,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   198,   198,   198,   199,   200,
     201,   202,   204,   205,   206,   207,   208,   209,   209,   211,
     211,   211,   211,   211,   211,   212,   213,   214,   215,   216,
     221,   221,   223,   224,   227,   228,   233,   233,   235,   236,
     239,   241,   242,   244,   246,   247,   249,   251,   251,   252,
     254,   255,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   270,   271,   272,   274,   275,   276,   277,   278,
     279,   280,   281,   283,   283,   284,   284,   285,   286,   286,
     287,   287,   288,   289,   289,   290,   290,   290,   290,   291,
     291,   292,   292,   292,   293,   294,   294,   295,   295,   296,
     296,   297,   298,   300,   301,   301,   301,   301,   303,   303,
     303,   306,   306,   307,   307,   307,   308,   308,   308,   309,
     313,   314,   314,   315,   318,   321,   324,   327,   329,   330,
     331,   332,   332,   334,   336,   338,   340,   340,   341,   341,
     342,   342,   343,   343,   344,   344,   345,   345,   346,   346,
     353,   357,   359,   361,   361,   362,   362,   363,   364,   365,
     366,   367,   369,   369,   370,   373,   376,   378,   379,   381,
     387,   387,   392,   395,   395,   396,   400,   405,   406,   407,
     408,   409,   410,   410,   411,   412,   413,   414,   414
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "DELIMITER", "FLOATING_POINT", "NUMBER", "TRUE", "FALSE", "TYPE",
  "STR_LIT", "BYT_LIT", "STR", "LIST", "FLOAT", "BOOL", "EQUALS", "PLUS",
  "MINUS", "TIMES", "DIVIDEDBY", "NEWLINE", "MOD", "MODULO", "AUGPLUS",
  "AUGMINUS", "AUGTIMES", "AUGDIVIDEDBY", "AUGMOD", "AUGMODULO", "POW",
  "AUGPOW", "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NOT", "BIT_RSHIFT",
  "BIT_LSHIFT", "AUGBIT_AND", "AUGBIT_OR", "AUGBIT_XOR", "AUGBIT_NOT",
  "AUGBIT_RSHIFT", "AUGBIT_LSHIFT", "LPAREN", "RPAREN", "COMMA", "DOT",
  "COLON", "SEMICOLON", "LLIST", "RLIST", "R_ARR", "EQ", "NEQ", "GT",
  "GTE", "LT", "LTE", "HEX", "INT", "AWAIT", "LEN", "AND", "BREAK", "DEF",
  "ELIF", "ELSE", "FOR", "IF", "ENDMARKER", "RANGE", "NOT", "OR", "RETURN",
  "WHILE", "INDENT", "DEDENT", "NONE", "IS", "IN", "CONTINUE", "ASSERT",
  "NONLOCAL", "GLOBAL", "CLASS", "ASYNC", "IMPORT", "PASS", "EXCEPT",
  "RAISE", "FINALLY", "LAMBDA", "TRY", "AS", "FROM", "DEL", "WITH",
  "YIELD", "$accept", "file", "single_inputs", "single_input", "funcdef",
  "rarr_test_maybe", "parameters", "arguments", "argument_a", "comm_arg_a",
  "equals_test_maybe", "kwargs", "comma_maybe", "args", "kwonly_kwargs",
  "comma_kwargs_maybe", "args_kwonly_kwargs",
  "poskeyword_args_kwonly_kwargs", "comma_argskwonlykwargs",
  "typedargslist_no_posonly", "typedargslist", "comma_typedargs_maybe",
  "tfpdef", "colon_test_maybe", "stmt", "simple_stmt", "small_stmt1",
  "small_stmt", "type1", "type", "expr_stmt", "expr_list", "eq_test",
  "annassign", "annassign_a", "testlist_star_expr", "test_star",
  "comm_test_star", "augassign", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "global_stmt", "comm_name",
  "nonlocal_stmt", "assert_stmt", "comma_test_maybe", "compound_stmt",
  "async_stmt", "if_stmt", "while_stmt", "for_stmt",
  "else_colon_suite_maybe", "elif_namedexprtest_colon_suite", "suite",
  "stmt_morethanone", "test", "if_ortest_else_test_maybe", "or_test",
  "or_andtest", "and_test", "and_nottest", "not_test", "comparison",
  "comp_op_expr", "comp_op", "star_expr", "expr", "bitor_xorexpr",
  "xor_expr", "bitxor_andexpr", "and_expr", "bitand_shiftexpr",
  "shift_expr", "lorrshift_arithexpr", "lshift_or_rshift", "arith_expr",
  "plusorminus_term", "plus_or_minus", "term", "timedivmod_factor",
  "timedivmod", "factor", "plusminusnot", "power", "pow_factor_maybe",
  "atom_expr", "trailer_", "atom", "string_pl", "testlist_comp",
  "testlist_comp_a", "comma_testorstar", "test_or_starexpr", "trailer",
  "subscriptlist", "comma_subscript", "subscript", "sliceop_maybe",
  "sliceop", "exprlist", "expr_str", "comm_exstr", "testlist", "comm_test",
  "classdef", "l_arglist_r_maybe", "arglist", "comm_arg", "argument",
  "comp_iter", "sync_comp_for", "comp_for", "comp_if", "func_body_suite",
  "func_type_input", "nls", "func_type", "typelist", "comma_typel_maybe",
  "type_l", "comma_pow_test_maybe", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-153)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     320,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  1086,
    -329,  -329,   109,    85,   369,     7,  -329,    52,  1036,  1067,
    1067,    85,  1067,  -329,  -329,  1067,    55,    63,    83,    -8,
     105,   404,  -329,  -329,  -329,  -329,  -329,   486,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,    89,  -329,  -329,  -329,
    -329,  -329,    38,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  1086,  -329,    88,  -329,   103,  -329,
    -329,  -329,    85,  -329,  1067,  1067,    69,   -34,   -34,    93,
      98,   -34,    80,  -329,    85,   101,  -329,  -329,    68,  -329,
     102,  -329,  -329,   112,   115,  -329,  -329,   111,  -329,  -329,
    -329,  -329,    19,    85,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,    23,  -329,  -329,  1067,
     116,  -329,  1067,  -329,    91,   104,   379,   133,   134,   140,
      86,   107,    27,  -329,  1086,  -329,    37,  -329,     1,  -329,
      11,   127,  -329,  1067,  1036,   106,  -329,   129,   131,  -329,
    -329,  -329,  -329,   126,  -329,    37,   135,    50,   130,   108,
     137,   740,   740,  1067,  -329,   138,   138,   860,   141,  -329,
     775,  -329,  -329,  -329,   136,  -329,  -329,  -329,  -329,  -329,
     169,  -329,  -329,    85,   121,  1067,  1067,  -329,  -329,  -329,
    -329,  -329,  -329,   110,   119,  -329,  1086,  1086,  1086,  1086,
    -329,  -329,  1086,  -329,  -329,  1086,  -329,  -329,  -329,  -329,
    1086,  -329,   215,   189,   940,  -329,  -329,  -329,   127,   959,
    -329,  -329,   113,  -329,    85,   909,  -329,  1067,  -329,   147,
     193,   193,   151,  -329,  -329,  -329,  -329,  -329,  -329,   153,
     183,    23,   152,   158,  1036,   139,  -329,  -329,   142,  -329,
     202,  1067,  1067,     8,   161,  -329,   740,  -329,  -329,   191,
      18,    85,  -329,   164,  -329,  1067,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,   166,  -329,
     990,   176,   175,  -329,  -329,  1067,  -329,  1067,  -329,  -329,
    -329,  1067,  1067,  -329,  -329,    23,  -329,  -329,   171,    24,
    -329,   181,   182,  -329,  -329,  1067,  -329,  -329,   825,  1067,
    -329,   656,    67,   187,  -329,  -329,  -329,  -329,  1067,  -329,
    -329,   184,  -329,    85,   180,  -329,  1067,  -329,  -329,  1067,
     188,  -329,  -329,   990,  -329,   198,  -329,   -27,  -329,   127,
    -329,  -329,  -329,  -329,   200,  -329,   193,    45,  -329,  -329,
     172,  -329,  -329,   167,  -329,  -329,  -329,   488,  1067,  -329,
     740,  -329,   860,  -329,  -329,  -329,  -329,   188,  -329,   940,
    1067,  -329,  -329,  -329,   127,  -329,    50,  -329,  -329,  -329,
     656,   199,  -329,  -329,   203,  -329,  -329,  -329,  -329,   -27,
    -329,   207,  -329,   572,   740,   740,  -329,    26,  -329,   142,
    -329,  -329
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   194,   197,   195,   199,   200,   202,   181,   182,     0,
       6,   183,     0,   203,     0,     0,    98,     0,     0,     0,
       0,   101,     0,   198,    99,     0,     0,     0,     0,     0,
       0,     2,     5,   112,     7,    53,    54,    71,    82,    55,
      95,    96,    97,    56,    57,    58,     8,   114,   109,   110,
     111,    79,   130,   133,   136,   138,    80,   141,   155,   158,
     161,   164,   169,   174,     0,   180,   186,   190,   196,   113,
       3,   264,   203,   152,   239,     0,     0,   210,   210,     0,
       0,   210,     0,   190,   203,     0,   233,   232,     0,   235,
       0,   137,   100,     0,   108,   104,   104,   242,   115,   116,
       1,     4,    51,     0,    83,    84,    85,    86,    94,    87,
      93,    88,    89,    90,    91,    92,     0,    67,    68,     0,
      78,     9,     0,   128,   131,   134,   139,   153,   156,   159,
     162,   167,   172,   179,     0,   184,   188,   201,     0,   239,
     141,   278,   270,     0,     0,     0,   204,   208,   273,   257,
     206,   205,   191,     0,   193,   187,     0,    37,    12,     0,
     231,     0,     0,     0,   106,   105,   102,     0,     0,    49,
      50,    73,    64,    61,     0,    60,    62,    59,    63,    65,
      76,   239,    69,    77,     0,     0,     0,   144,   147,   143,
     145,   142,   146,     0,   150,   148,     0,     0,     0,     0,
     166,   165,     0,   170,   171,     0,   175,   176,   178,   177,
       0,   185,     0,     0,     0,   189,   263,   262,   278,     0,
     269,   266,     0,   256,   207,   272,   267,     0,   192,    45,
      24,     0,    32,    17,    30,    17,    36,    35,    39,     0,
      19,     0,     0,     0,   230,     0,   124,   123,   121,   107,
       0,     0,     0,   248,     0,   246,     0,    48,    52,    70,
       0,     0,    74,   237,    81,     0,   132,   135,   149,   151,
     140,   154,   157,   160,   163,   168,   173,   214,     0,   216,
     227,   221,     0,   220,   268,     0,   238,     0,   211,   212,
     209,   239,     0,   271,   265,     0,    43,    23,    22,    34,
      31,    14,    28,    29,    13,     0,    15,    11,     0,     0,
     234,     0,   121,     0,   118,   103,   251,   250,     0,   247,
     241,   244,   240,     0,     0,    75,   236,   129,   213,   229,
     227,   225,   226,   227,   215,   218,   277,   255,   239,   278,
     276,    44,    21,    20,    40,    33,     0,    27,    25,    18,
       0,   260,    10,     0,   127,    46,    47,     0,     0,   117,
       0,   249,   243,    72,    66,   228,   224,   227,   223,   217,
       0,   254,   252,   253,   278,   275,    42,    38,    16,    26,
       0,     0,   125,   126,     0,   120,   245,   222,   219,   259,
     274,    32,    41,     0,     0,     0,   258,    34,   261,   121,
     122,   119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,  -329,   206,   226,  -329,  -329,  -120,  -210,    22,
    -329,   -89,  -329,  -329,  -329,  -329,  -286,  -329,  -329,  -115,
    -329,  -329,   -90,  -329,  -328,     0,  -329,    92,     3,  -221,
    -329,  -329,  -329,  -329,  -329,   -18,    81,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,   174,  -329,  -329,  -329,    39,  -329,
    -329,  -329,   238,  -293,  -329,  -156,  -112,   -11,  -329,  -118,
    -329,    87,  -329,   -10,  -329,  -329,  -329,     5,    -2,  -329,
      74,  -329,    75,  -329,    76,  -329,  -329,    77,  -329,  -329,
      73,  -329,  -329,   -52,  -329,  -329,  -329,  -329,   201,   268,
    -329,    14,   205,  -329,  -329,  -329,  -329,  -329,   -84,  -305,
    -329,   144,    42,  -329,   -20,   -72,  -329,  -329,    78,  -329,
     -71,   -97,   150,  -238,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -209
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    30,    31,    32,    33,   242,   158,   232,   233,   301,
     306,   234,   343,   235,   303,   348,   236,   237,   300,   238,
     239,   377,   240,   296,   354,   246,   102,    35,   179,   180,
      36,   117,   259,   118,   262,    37,    38,   120,   119,    39,
      40,    41,    42,    43,   165,    44,    45,   164,   356,    47,
      48,    49,    50,   314,   312,   247,   357,    51,   123,    52,
     124,    53,   125,    54,    55,   126,   196,    56,    57,   127,
      58,   128,    59,   129,    60,   130,   202,    61,   131,   205,
      62,   132,   210,    63,    64,    65,   135,    66,   136,    67,
      68,    79,   146,   147,   290,   215,   282,   335,   283,   331,
     332,    88,    89,   160,   182,   141,    69,   168,   254,   321,
     255,   371,   149,   150,   373,   352,    70,   138,    71,    80,
     226,   293,   220
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    77,    81,    92,   184,   148,   248,    73,    90,   284,
      91,    93,   133,   345,    94,   319,    87,    78,    78,   359,
     307,   172,   216,    86,   318,   366,   172,    82,   368,   383,
     173,    34,   175,   176,   144,   173,   174,   175,   176,    46,
     169,   144,   370,   230,   344,   230,   206,   207,   229,   208,
     209,    84,   145,   229,   231,    85,   231,    17,    95,   145,
      18,    81,   387,   139,   142,   383,    96,   218,   170,   230,
      46,   217,   140,    81,   341,   231,   144,    78,   177,  -152,
     231,   212,   211,   177,   213,   171,    97,   214,     1,    78,
       2,     3,     4,     5,   145,     6,   178,  -152,   156,   372,
     322,   178,     7,     8,     9,   100,   401,   122,   181,   263,
     121,   345,     1,   137,     2,     3,     4,     5,   134,     6,
      11,   143,   200,   201,   203,   204,     7,     8,    74,    72,
     375,   154,   221,   358,   313,    13,   378,   378,   152,    75,
     297,   298,    87,   153,    11,   157,    14,    15,   159,    86,
     161,   372,   249,    72,    76,   167,   253,    20,   276,    13,
     162,   163,   183,    23,   185,   390,   197,   186,   198,   337,
      14,    15,   199,   219,   144,   224,   267,   225,   227,   243,
     228,    20,   241,   244,   250,   261,   260,    23,   265,   256,
     268,   269,   279,   287,   270,   295,   229,   299,   304,   305,
     308,   253,   309,   281,   385,   315,   320,   323,   286,   313,
     326,   328,   381,   288,   286,   311,   294,   342,     1,   339,
       2,     3,     4,     5,   333,     6,   334,   346,   347,   289,
     362,   364,     7,     8,   251,   360,   329,   101,   399,   400,
     316,   317,    87,   325,   369,   252,   376,   394,   380,    86,
      11,   395,   389,   397,   327,    98,   391,   302,   379,    72,
     277,   392,   258,   324,   264,    13,   374,    99,   393,   330,
     166,   271,   266,   272,   336,   273,    14,    15,   275,   274,
     338,   340,    83,   151,   155,   388,   310,    20,   222,   353,
     278,   386,   396,    23,   349,   223,     0,     0,   181,     0,
       0,     0,     0,     0,     0,   363,     0,   361,   351,     0,
       0,   355,     0,     0,     0,   286,     0,     0,   365,     0,
       0,     0,   367,     1,     0,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,    10,     0,     0,     0,     0,     0,   384,     0,     0,
       0,   253,     0,     0,     0,    11,     0,   355,   281,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
      13,     0,     1,     0,     2,     3,     4,     5,     0,     6,
     355,    14,    15,     0,    16,    17,     0,     0,    18,    19,
       0,     0,    20,   355,    21,    22,     0,     0,    23,     0,
       0,    24,    25,    26,    27,    28,    29,     1,     0,     2,
       3,     4,     5,    72,     6,     0,     0,     0,     0,    13,
       0,     7,     8,     9,     0,    10,     0,     0,     0,     0,
       0,    15,   187,   188,   189,   190,   191,   192,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    23,    72,     0,
       0,   193,     0,     0,    13,     0,     0,     0,   194,   195,
       0,     0,     0,     0,     0,    14,    15,     0,    16,    17,
       0,     0,    18,    19,     0,     0,    20,     0,    21,    22,
       0,     0,    23,     0,     0,    24,    25,    26,    27,    28,
      29,     1,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,   103,     0,     0,     7,     8,     9,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   110,     0,     0,
       0,     0,     0,    11,   111,   112,   113,     0,   114,   115,
       0,     0,    72,     0,   116,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,    16,    17,     0,     0,    18,    19,     0,     0,
      20,     0,    21,    22,     0,   382,    23,     0,     0,    24,
      25,    26,    27,    28,    29,     1,     0,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,    16,    17,     0,     0,
      18,    19,     0,     0,    20,     0,    21,    22,     0,   398,
      23,     0,     0,    24,    25,    26,    27,    28,    29,     1,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
      16,    17,     0,     0,    18,    19,     0,     0,    20,     0,
      21,    22,     0,     0,    23,     0,     0,    24,    25,    26,
      27,    28,    29,     1,     0,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     1,     0,
       2,     3,     4,     5,    72,     6,     0,     0,     0,     0,
      13,     0,     7,     8,     9,     0,   257,     0,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,     0,     0,
      11,     0,    20,     0,    21,     0,     0,     0,    23,    72,
       0,    24,    25,    26,    27,    13,     0,     0,     1,     0,
       2,     3,     4,     5,     0,     6,    14,    15,     0,    16,
       0,     0,     7,     8,     9,     0,   350,    20,     0,    21,
       0,     0,     0,    23,     0,     0,    24,    25,    26,    27,
      11,     0,     0,     1,     0,     2,     3,     4,     5,    72,
       6,     0,     0,     0,     0,    13,     0,     7,     8,   251,
       0,     0,     0,     0,     0,     0,    14,    15,     0,    16,
     252,     0,     0,     0,     0,    11,     0,    20,     0,    21,
       0,     0,     0,    23,    72,     0,    24,    25,    26,    27,
      13,     0,     1,     0,     2,     3,     4,     5,     0,     6,
       0,    14,    15,     0,     0,     0,     7,     8,   291,     0,
       0,     0,    20,     0,     0,     0,     0,     0,    23,   292,
       0,     0,     0,     1,    11,     2,     3,     4,     5,     0,
       6,     0,     0,    72,     0,     0,     0,     7,     8,    13,
       0,     0,     1,     0,     2,     3,     4,     5,     0,     6,
      14,    15,     0,     0,     0,    11,     7,     8,     0,     0,
       0,    20,     0,     0,    72,     0,     0,    23,   280,   285,
      13,     0,     0,     1,    11,     2,     3,     4,     5,     0,
       6,    14,    15,    72,     0,     0,     0,     7,     8,    13,
       0,     0,    20,     0,     0,     0,     0,     0,    23,     0,
      14,    15,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    20,     0,     0,    72,     0,     0,    23,   329,     1,
      13,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,    14,    15,     7,     8,     9,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,    23,     0,
       1,    11,     2,     3,     4,     5,     0,     6,     0,     0,
      72,     0,     0,     0,     7,     8,    13,     0,     0,     1,
       0,     2,     3,     4,     5,     0,     6,    14,    15,     0,
       0,     0,    11,     7,     8,     0,     0,     0,     0,     0,
       0,    72,     0,     0,    23,     0,     0,    13,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    14,    15,
      72,     0,     0,     0,     0,     0,    13,     0,     0,    20,
       0,     0,     0,     0,     0,    23,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       0,    12,    13,    21,   122,    77,   162,     9,    19,   218,
      20,    22,    64,   299,    25,   253,    18,    12,    13,   312,
     241,     3,    21,    18,    16,   330,     3,    13,   333,   357,
      12,    31,    14,    15,    68,    12,    13,    14,    15,     0,
      21,    68,    69,    19,    20,    19,    19,    20,     3,    22,
      23,    44,    86,     3,    30,     3,    30,    65,     3,    86,
      68,    72,   367,    74,    75,   393,     3,   139,    49,    19,
      31,    70,    74,    84,   295,    30,    68,    72,    60,    68,
      30,    44,   134,    60,    47,   103,     3,    50,     3,    84,
       5,     6,     7,     8,    86,    10,    78,    86,    84,   337,
     256,    78,    17,    18,    19,     0,   399,    69,   119,   181,
      21,   397,     3,    10,     5,     6,     7,     8,    30,    10,
      35,    52,    36,    37,    17,    18,    17,    18,    19,    44,
     339,    51,   143,    66,    67,    50,   346,   347,    45,    30,
     230,   231,   144,    45,    35,    44,    61,    62,    80,   144,
      48,   389,   163,    44,    45,    44,   167,    72,   210,    50,
      48,    46,    46,    78,    73,   374,    33,    63,    34,   287,
      61,    62,    32,    46,    68,    46,   186,    46,    52,    71,
      45,    72,    52,    46,    46,    16,    50,    78,    67,    48,
      80,    72,     3,    80,   196,    48,     3,    46,    45,    16,
      48,   212,    44,   214,   360,     3,    45,    16,   219,    67,
      46,    45,    45,   224,   225,    76,   227,    46,     3,   291,
       5,     6,     7,     8,    48,    10,    51,    46,    46,   224,
      46,    51,    17,    18,    19,    48,    48,    31,   394,   395,
     251,   252,   244,   261,    46,    30,    46,    48,    76,   244,
      35,    48,   370,    46,   265,    29,   376,   235,   347,    44,
      45,   376,   170,   260,   183,    50,   338,    29,   380,   280,
      96,   197,   185,   198,   285,   199,    61,    62,   205,   202,
     291,   292,    14,    78,    83,   369,   244,    72,   144,   309,
     212,   362,   389,    78,   305,   145,    -1,    -1,   309,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,   318,   308,    -1,
      -1,   311,    -1,    -1,    -1,   326,    -1,    -1,   329,    -1,
      -1,    -1,   333,     3,    -1,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
      -1,   362,    -1,    -1,    -1,    35,    -1,   357,   369,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,     3,    -1,     5,     6,     7,     8,    -1,    10,
     380,    61,    62,    -1,    64,    65,    -1,    -1,    68,    69,
      -1,    -1,    72,   393,    74,    75,    -1,    -1,    78,    -1,
      -1,    81,    82,    83,    84,    85,    86,     3,    -1,     5,
       6,     7,     8,    44,    10,    -1,    -1,    -1,    -1,    50,
      -1,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    62,    53,    54,    55,    56,    57,    58,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    44,    -1,
      -1,    72,    -1,    -1,    50,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,    65,
      -1,    -1,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      -1,    -1,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,     3,    -1,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    16,    -1,    -1,    17,    18,    19,    -1,    -1,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    35,    38,    39,    40,    -1,    42,    43,
      -1,    -1,    44,    -1,    48,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    64,    65,    -1,    -1,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,     3,    -1,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    -1,    -1,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    86,     3,
      -1,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    -1,    -1,    78,    -1,    -1,    81,    82,    83,
      84,    85,    86,     3,    -1,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,     3,    -1,
       5,     6,     7,     8,    44,    10,    -1,    -1,    -1,    -1,
      50,    -1,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    72,    -1,    74,    -1,    -1,    -1,    78,    44,
      -1,    81,    82,    83,    84,    50,    -1,    -1,     3,    -1,
       5,     6,     7,     8,    -1,    10,    61,    62,    -1,    64,
      -1,    -1,    17,    18,    19,    -1,    21,    72,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    82,    83,    84,
      35,    -1,    -1,     3,    -1,     5,     6,     7,     8,    44,
      10,    -1,    -1,    -1,    -1,    50,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      30,    -1,    -1,    -1,    -1,    35,    -1,    72,    -1,    74,
      -1,    -1,    -1,    78,    44,    -1,    81,    82,    83,    84,
      50,    -1,     3,    -1,     5,     6,     7,     8,    -1,    10,
      -1,    61,    62,    -1,    -1,    -1,    17,    18,    19,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    30,
      -1,    -1,    -1,     3,    35,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    44,    -1,    -1,    -1,    17,    18,    50,
      -1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    10,
      61,    62,    -1,    -1,    -1,    35,    17,    18,    -1,    -1,
      -1,    72,    -1,    -1,    44,    -1,    -1,    78,    48,    30,
      50,    -1,    -1,     3,    35,     5,     6,     7,     8,    -1,
      10,    61,    62,    44,    -1,    -1,    -1,    17,    18,    50,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      61,    62,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    44,    -1,    -1,    78,    48,     3,
      50,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    61,    62,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
       3,    35,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      44,    -1,    -1,    -1,    17,    18,    50,    -1,    -1,     3,
      -1,     5,     6,     7,     8,    -1,    10,    61,    62,    -1,
      -1,    -1,    35,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    78,    -1,    -1,    50,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    10,    17,    18,    19,
      21,    35,    44,    50,    61,    62,    64,    65,    68,    69,
      72,    74,    75,    78,    81,    82,    83,    84,    85,    86,
     100,   101,   102,   103,   124,   126,   129,   134,   135,   138,
     139,   140,   141,   142,   144,   145,   147,   148,   149,   150,
     151,   156,   158,   160,   162,   163,   166,   167,   169,   171,
     173,   176,   179,   182,   183,   184,   186,   188,   189,   205,
     215,   217,    44,   167,    19,    30,    45,   156,   166,   190,
     218,   156,   190,   188,    44,     3,   166,   167,   200,   201,
     156,   162,   134,   156,   156,     3,     3,     3,   103,   151,
       0,   102,   125,    16,    24,    25,    26,    27,    28,    29,
      31,    38,    39,    40,    42,    43,    48,   130,   132,   137,
     136,    21,    69,   157,   159,   161,   164,   168,   170,   172,
     174,   177,   180,   182,    30,   185,   187,    10,   216,   156,
     167,   204,   156,    52,    68,    86,   191,   192,   204,   211,
     212,   191,    45,    45,    51,   187,   190,    44,   105,    80,
     202,    48,    48,    46,   146,   143,   143,    44,   206,    21,
      49,   134,     3,    12,    13,    14,    15,    60,    78,   127,
     128,   156,   203,    46,   158,    73,    63,    53,    54,    55,
      56,    57,    58,    72,    79,    80,   165,    33,    34,    32,
      36,    37,   175,    17,    18,   178,    19,    20,    22,    23,
     181,   182,    44,    47,    50,   194,    21,    70,   204,    46,
     221,   156,   200,   211,    46,    46,   219,    52,    45,     3,
      19,    30,   106,   107,   110,   112,   115,   116,   118,   119,
     121,    52,   104,    71,    46,    21,   124,   154,   154,   156,
      46,    19,    30,   156,   207,   209,    48,    21,   126,   131,
      50,    16,   133,   204,   135,    67,   160,   162,    80,    72,
     167,   169,   171,   173,   176,   179,   182,    45,   207,     3,
      48,   156,   195,   197,   221,    30,   156,    80,   156,   166,
     193,    19,    30,   220,   156,    48,   122,   121,   121,    46,
     117,   108,   108,   113,    45,    16,   109,   128,    48,    44,
     201,    76,   153,    67,   152,     3,   156,   156,    16,   212,
      45,   208,   154,    16,   127,   134,    46,   156,    45,    48,
     156,   198,   199,    48,    51,   196,   156,   158,   156,   204,
     156,   128,    46,   111,    20,   115,    46,    46,   114,   156,
      21,   124,   214,   203,   123,   124,   147,   155,    66,   152,
      48,   156,    46,   134,    51,   156,   198,   156,   198,    46,
      69,   210,   212,   213,   204,   221,    46,   120,   107,   110,
      76,    45,    77,   123,   156,   154,   209,   198,   197,   158,
     221,   106,   118,   155,    48,    48,   210,    46,    77,   154,
     154,   152
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   104,   104,   105,   106,   107,   108,   108,   109,   109,
     110,   111,   111,   112,   112,   113,   114,   114,   114,   115,
     115,   116,   117,   117,   117,   118,   118,   119,   119,   119,
     120,   120,   120,   121,   122,   122,   123,   123,   124,   124,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   130,   130,
     130,   130,   131,   131,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   138,   139,   140,
     141,   141,   142,   143,   143,   144,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   148,   148,   149,   150,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   157,
     157,   158,   159,   159,   160,   161,   161,   162,   162,   163,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   167,   168,   168,   169,   170,   170,   171,
     172,   172,   173,   174,   174,   175,   175,   176,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   181,   181,   182,
     182,   183,   183,   183,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   189,   190,   190,   190,   191,   191,   191,   192,
     192,   193,   193,   194,   194,   194,   194,   195,   195,   196,
     196,   197,   197,   197,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   203,   204,   204,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   209,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   215,   216,   216,   217,   217,   218,   218,   218,
     218,   219,   219,   219,   220,   220,   220,   221,   221
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       6,     2,     0,     3,     2,     2,     3,     0,     2,     0,
       3,     1,     0,     2,     1,     2,     2,     1,     0,     2,
       1,     2,     0,     2,     1,     1,     1,     0,     4,     1,
       0,     2,     1,     2,     2,     0,     1,     1,     4,     3,
       3,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     1,     2,
       3,     0,     3,     0,     3,     2,     0,     3,     2,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     3,     0,     3,     3,     2,     0,     1,
       1,     1,     1,     1,     1,     2,     2,     6,     5,    10,
       3,     0,     5,     0,     1,     4,     2,     1,     2,     4,
       0,     2,     3,     0,     2,     3,     0,     2,     1,     2,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     2,     3,     0,     2,     3,     0,     2,
       3,     0,     2,     3,     0,     1,     1,     2,     3,     0,
       1,     1,     2,     3,     0,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     2,     2,     0,     3,     2,     2,
       0,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     2,     2,     1,     2,     1,     3,
       0,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       0,     1,     4,     3,     3,     2,     1,     0,     2,     1,
       3,     2,     1,     1,     3,     0,     3,     2,     3,     0,
       5,     3,     0,     3,     2,     3,     0,     2,     1,     3,
       2,     2,     1,     1,     5,     4,     2,     1,     3,     2,
       1,     4,     3,     2,     0,     5,     4,     3,     4,     3,
       2,     2,     1,     0,     4,     3,     2,     3,     0
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
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };


/* Context of a parse error.  */
typedef struct
{
  yypstate* yyps;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypstate_expected_tokens (yypstate *yyps,
                          yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyps->yyssp];
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


/* Similar to the previous function.  */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
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





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yystacksize yyps->yystacksize

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

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

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

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
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
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
  case 2: /* file: single_inputs  */
#line 77 "parser.y"
                   {Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{(yyvsp[0].node),temp});}
#line 2155 "parser.tab.c"
    break;

  case 3: /* file: func_type_input  */
#line 78 "parser.y"
                      {Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{(yyvsp[0].node),temp});}
#line 2161 "parser.tab.c"
    break;

  case 4: /* single_inputs: single_inputs single_input  */
#line 80 "parser.y"
                                           { (yyval.node)=(yyvsp[-1].node);
(yyval.node)->children.push_back((yyvsp[0].node));
}
#line 2169 "parser.tab.c"
    break;

  case 5: /* single_inputs: single_input  */
#line 83 "parser.y"
                             {(yyval.node)=createNode("single_inputs","",{(yyvsp[0].node)});}
#line 2175 "parser.tab.c"
    break;

  case 6: /* single_input: NEWLINE  */
#line 84 "parser.y"
                      {(yyval.node)=createNode("Newline","nl",{});}
#line 2181 "parser.tab.c"
    break;

  case 7: /* single_input: simple_stmt  */
#line 85 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2187 "parser.tab.c"
    break;

  case 8: /* single_input: compound_stmt  */
#line 86 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2193 "parser.tab.c"
    break;

  case 9: /* single_input: compound_stmt NEWLINE  */
#line 87 "parser.y"
                                   {Node *n1=createNode("Newline","nl",{}); (yyval.node)=createNode("single_input","",{(yyvsp[-1].node),n1});}
#line 2199 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF IDENTIFIER parameters rarr_test_maybe COLON func_body_suite  */
#line 90 "parser.y"
                                                                        {Node* n2= createNode("Keyword","def",{});Node* n3= createNode("Identifier",*(yyvsp[-4].str),{});Node* n4= createNode("Delimiter",":",{});(yyval.node)=createNode("Func","",{n2,n3,(yyvsp[-3].node),(yyvsp[-2].node),n4,(yyvsp[0].node)});}
#line 2205 "parser.tab.c"
    break;

  case 11: /* rarr_test_maybe: R_ARR type  */
#line 91 "parser.y"
                           {Node * n5= createNode("Delimiter","->",{});(yyval.node)=createNode("rarr_maybe","",{n5,(yyvsp[0].node)});}
#line 2211 "parser.tab.c"
    break;

  case 12: /* rarr_test_maybe: %empty  */
#line 91 "parser.y"
                                                                                                                  {(yyval.node)=createNode("rarr_test_maybe","",{});}
#line 2217 "parser.tab.c"
    break;

  case 13: /* parameters: LPAREN typedargslist RPAREN  */
#line 92 "parser.y"
                                        {Node *n6= createNode("Delimiter","(",{});Node *n7= createNode("Delimiter",")",{});(yyval.node)=createNode("params","",{n6,(yyvsp[-1].node),n7});}
#line 2223 "parser.tab.c"
    break;

  case 14: /* arguments: argument_a comm_arg_a  */
#line 94 "parser.y"
                                 {(yyval.node)=createNode("args","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2229 "parser.tab.c"
    break;

  case 15: /* argument_a: tfpdef equals_test_maybe  */
#line 95 "parser.y"
                                    {(yyval.node)=createNode("arg","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2235 "parser.tab.c"
    break;

  case 16: /* comm_arg_a: comm_arg_a COMMA argument_a  */
#line 96 "parser.y"
                                        {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 2241 "parser.tab.c"
    break;

  case 17: /* comm_arg_a: %empty  */
#line 96 "parser.y"
                                                                                                                                                     {(yyval.node)=createNode("comm_arg_a", "", {});}
#line 2247 "parser.tab.c"
    break;

  case 18: /* equals_test_maybe: EQUALS test  */
#line 98 "parser.y"
                               {Node *n8=createNode("Assign","=",{});(yyval.node)=createNode("args","",{n8,(yyvsp[0].node)});}
#line 2253 "parser.tab.c"
    break;

  case 19: /* equals_test_maybe: %empty  */
#line 98 "parser.y"
                                                                                                          {(yyval.node)=createNode("equals_test_maybe","",{});}
#line 2259 "parser.tab.c"
    break;

  case 20: /* kwargs: POW tfpdef comma_maybe  */
#line 99 "parser.y"
                               {Node *n9=createNode("Operator","Power(**)",{});  (yyval.node)=createNode("args","",{n9,(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2265 "parser.tab.c"
    break;

  case 21: /* comma_maybe: COMMA  */
#line 100 "parser.y"
                   {Node *n10=createNode("COMMA",",",{});}
#line 2271 "parser.tab.c"
    break;

  case 22: /* comma_maybe: %empty  */
#line 100 "parser.y"
                                                             {(yyval.node)=createNode("comma_maybe","",{});}
#line 2277 "parser.tab.c"
    break;

  case 23: /* args: TIMES tfpdef  */
#line 101 "parser.y"
                  {   Node *n11 = createNode("Operator","Times(*)",{});
                        (yyval.node)=createNode("args","",{n11,(yyvsp[0].node)});}
#line 2284 "parser.tab.c"
    break;

  case 24: /* args: TIMES  */
#line 103 "parser.y"
            {Node *n11 = createNode("Operator","Times(*)",{});
            (yyval.node) = createNode("args","",{n11});
                    }
#line 2292 "parser.tab.c"
    break;

  case 25: /* kwonly_kwargs: comm_arg_a comma_kwargs_maybe  */
#line 106 "parser.y"
                                            { (yyval.node)=createNode("kwarg","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2298 "parser.tab.c"
    break;

  case 26: /* comma_kwargs_maybe: COMMA kwargs  */
#line 107 "parser.y"
                                {   Node *n12 = createNode("Delimiter",",",{});
                                        (yyval.node) = createNode("kwargs","",{n12,(yyvsp[0].node)});
                                    }
#line 2306 "parser.tab.c"
    break;

  case 27: /* comma_kwargs_maybe: COMMA  */
#line 110 "parser.y"
                           {(yyval.node) = createNode("Delimiter",",",{});}
#line 2312 "parser.tab.c"
    break;

  case 28: /* comma_kwargs_maybe: %empty  */
#line 111 "parser.y"
                      {(yyval.node)=createNode("comma_kwargs_maybe","",{});}
#line 2318 "parser.tab.c"
    break;

  case 29: /* args_kwonly_kwargs: args kwonly_kwargs  */
#line 112 "parser.y"
                                       { (yyval.node)=createNode("args_kw","nkw",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2324 "parser.tab.c"
    break;

  case 30: /* args_kwonly_kwargs: kwargs  */
#line 113 "parser.y"
                            { (yyval.node)=(yyvsp[0].node);}
#line 2330 "parser.tab.c"
    break;

  case 31: /* poskeyword_args_kwonly_kwargs: arguments comma_argskwonlykwargs  */
#line 114 "parser.y"
                                                                { (yyval.node)=createNode("poskeyword_args_kwonly_kwargs","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2336 "parser.tab.c"
    break;

  case 32: /* comma_argskwonlykwargs: %empty  */
#line 115 "parser.y"
                         {(yyval.node)=createNode("comma_argskwonlykwargs","",{});}
#line 2342 "parser.tab.c"
    break;

  case 33: /* comma_argskwonlykwargs: COMMA args_kwonly_kwargs  */
#line 116 "parser.y"
                                                 {   Node *n11 = createNode("Delimiter",",",{});
                                                         (yyval.node)=createNode("comma_argskwonlykwargs","",{n11,(yyvsp[0].node)});
                                                        }
#line 2350 "parser.tab.c"
    break;

  case 34: /* comma_argskwonlykwargs: COMMA  */
#line 119 "parser.y"
                              {(yyval.node) = createNode("Delimiter",",",{});}
#line 2356 "parser.tab.c"
    break;

  case 35: /* typedargslist_no_posonly: poskeyword_args_kwonly_kwargs  */
#line 121 "parser.y"
                                                         { (yyval.node)=(yyvsp[0].node);}
#line 2362 "parser.tab.c"
    break;

  case 36: /* typedargslist_no_posonly: args_kwonly_kwargs  */
#line 122 "parser.y"
                                             { (yyval.node)=(yyvsp[0].node);}
#line 2368 "parser.tab.c"
    break;

  case 37: /* typedargslist: %empty  */
#line 123 "parser.y"
               {(yyval.node)=createNode("typedargslist","",{});}
#line 2374 "parser.tab.c"
    break;

  case 38: /* typedargslist: arguments COMMA DIVIDEDBY comma_typedargs_maybe  */
#line 124 "parser.y"
                                                              {Node* n3= createNode("div_by","/",{}); Node* n2= createNode("Delimiter",",",{});(yyval.node)=createNode("typedargslist","",{(yyvsp[-3].node),n2,n3,(yyvsp[0].node)});}
#line 2380 "parser.tab.c"
    break;

  case 39: /* typedargslist: typedargslist_no_posonly  */
#line 125 "parser.y"
                                         {  (yyval.node)=(yyvsp[0].node);}
#line 2386 "parser.tab.c"
    break;

  case 40: /* comma_typedargs_maybe: %empty  */
#line 126 "parser.y"
                      {(yyval.node)=createNode("comma_typedargs_maybe","",{});}
#line 2392 "parser.tab.c"
    break;

  case 41: /* comma_typedargs_maybe: COMMA typedargslist_no_posonly  */
#line 127 "parser.y"
                                                       {   Node *n11 = createNode("COMMA",",",{});
                                                         (yyval.node)=createNode("comma_typedargs_yes","",{n11,(yyvsp[0].node)});
                                                        }
#line 2400 "parser.tab.c"
    break;

  case 42: /* comma_typedargs_maybe: COMMA  */
#line 130 "parser.y"
                              {(yyval.node) = createNode("COMMA",",",{});}
#line 2406 "parser.tab.c"
    break;

  case 43: /* tfpdef: IDENTIFIER colon_test_maybe  */
#line 131 "parser.y"
                                    {Node *n11 = createNode("IDENTIFIER",*(yyvsp[-1].str),{});
                                                         (yyval.node)=createNode("tfpdef","",{n11,(yyvsp[0].node)});}
#line 2413 "parser.tab.c"
    break;

  case 44: /* colon_test_maybe: COLON type  */
#line 133 "parser.y"
                              {Node *n11 = createNode("Delimiter",":",{});
                                                         (yyval.node)=createNode("colon_test_yes","",{n11,(yyvsp[0].node)});}
#line 2420 "parser.tab.c"
    break;

  case 45: /* colon_test_maybe: %empty  */
#line 135 "parser.y"
                  {(yyval.node)=createNode("colon_test_maybe","",{});}
#line 2426 "parser.tab.c"
    break;

  case 46: /* stmt: simple_stmt  */
#line 138 "parser.y"
                 { (yyval.node) = (yyvsp[0].node);}
#line 2432 "parser.tab.c"
    break;

  case 47: /* stmt: compound_stmt  */
#line 139 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2438 "parser.tab.c"
    break;

  case 48: /* simple_stmt: small_stmt small_stmt1 SEMICOLON NEWLINE  */
#line 140 "parser.y"
                                                       { Node* n3= createNode("Delimiter",";",{}); Node* n4= createNode("newline","nl",{});(yyval.node)=createNode("simple_stmt","",{(yyvsp[-3].node),(yyvsp[-2].node),n3,n4});}
#line 2444 "parser.tab.c"
    break;

  case 49: /* simple_stmt: small_stmt small_stmt1 NEWLINE  */
#line 141 "parser.y"
                                            {  Node* n3= createNode("newline","nl",{});(yyval.node)=createNode("simple_stmt","",{(yyvsp[-2].node),(yyvsp[-1].node),n3});}
#line 2450 "parser.tab.c"
    break;

  case 50: /* simple_stmt: small_stmt small_stmt1 SEMICOLON  */
#line 142 "parser.y"
                                              { { Node* n3= createNode("Delimiter",";",{}); (yyval.node)=createNode("simple_stmt","",{(yyvsp[-2].node),(yyvsp[-1].node),n3});} }
#line 2456 "parser.tab.c"
    break;

  case 51: /* simple_stmt: small_stmt small_stmt1  */
#line 143 "parser.y"
                                    { (yyval.node)=createNode("simple_stmt","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2462 "parser.tab.c"
    break;

  case 52: /* small_stmt1: small_stmt1 SEMICOLON small_stmt  */
#line 145 "parser.y"
                                              { (yyval.node)=(yyvsp[-2].node); Node* n1= createNode("Delimiter",";",{}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 2468 "parser.tab.c"
    break;

  case 53: /* small_stmt1: %empty  */
#line 146 "parser.y"
  {(yyval.node)=createNode("small_stmt1", "", {});}
#line 2474 "parser.tab.c"
    break;

  case 54: /* small_stmt: expr_stmt  */
#line 148 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2480 "parser.tab.c"
    break;

  case 55: /* small_stmt: flow_stmt  */
#line 150 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2486 "parser.tab.c"
    break;

  case 56: /* small_stmt: global_stmt  */
#line 152 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2492 "parser.tab.c"
    break;

  case 57: /* small_stmt: nonlocal_stmt  */
#line 153 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2498 "parser.tab.c"
    break;

  case 58: /* small_stmt: assert_stmt  */
#line 154 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2504 "parser.tab.c"
    break;

  case 59: /* type1: INT  */
#line 157 "parser.y"
           {(yyval.node)=createNode("Keyword","int",{});}
#line 2510 "parser.tab.c"
    break;

  case 60: /* type1: FLOAT  */
#line 158 "parser.y"
            {(yyval.node)=createNode("Keyword","float",{});}
#line 2516 "parser.tab.c"
    break;

  case 61: /* type1: STR  */
#line 159 "parser.y"
          {(yyval.node)=createNode("Keyword","str",{});}
#line 2522 "parser.tab.c"
    break;

  case 62: /* type1: BOOL  */
#line 160 "parser.y"
           {(yyval.node)=createNode("Keyword","bool",{});}
#line 2528 "parser.tab.c"
    break;

  case 63: /* type1: NONE  */
#line 161 "parser.y"
           {(yyval.node)=createNode("Keyword","None",{});}
#line 2534 "parser.tab.c"
    break;

  case 64: /* type1: IDENTIFIER  */
#line 162 "parser.y"
                 {(yyval.node)=createNode("Identifier",*(yyvsp[0].str),{});}
#line 2540 "parser.tab.c"
    break;

  case 65: /* type: type1  */
#line 163 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 2546 "parser.tab.c"
    break;

  case 66: /* type: LIST LLIST type1 RLIST  */
#line 164 "parser.y"
                             {
        Node *lst=createNode("Keyword","list",{});
        Node * ll=createNode("Delimiter","[",{});
        Node* rl=createNode("Delimiter","]",{});
        (yyval.node)=createNode("type","t",{lst,ll,(yyvsp[-1].node),rl});}
#line 2556 "parser.tab.c"
    break;

  case 67: /* expr_stmt: testlist_star_expr expr_list  */
#line 169 "parser.y"
                                        {(yyval.node)=createNode("expr_stmt","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2562 "parser.tab.c"
    break;

  case 68: /* expr_list: annassign  */
#line 170 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2568 "parser.tab.c"
    break;

  case 69: /* expr_list: augassign testlist  */
#line 171 "parser.y"
                         {(yyval.node)=createNode("expr_list","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2574 "parser.tab.c"
    break;

  case 70: /* expr_list: EQUALS testlist_star_expr eq_test  */
#line 172 "parser.y"
                                       {Node * eq=createNode("Equals","=",{});(yyval.node)=createNode("expr_list","",{eq,(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2580 "parser.tab.c"
    break;

  case 71: /* expr_list: %empty  */
#line 172 "parser.y"
                                                                                                                           {(yyval.node)=createNode("expr_list","",{});}
#line 2586 "parser.tab.c"
    break;

  case 72: /* eq_test: eq_test EQUALS testlist_star_expr  */
#line 173 "parser.y"
                                           {(yyval.node)=(yyvsp[-2].node); Node * eq=createNode("Equals","=",{});(yyval.node)->children.push_back(eq);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2592 "parser.tab.c"
    break;

  case 73: /* eq_test: %empty  */
#line 174 "parser.y"
          {(yyval.node)=createNode("eq_test", "", {});}
#line 2598 "parser.tab.c"
    break;

  case 74: /* annassign: COLON type annassign_a  */
#line 175 "parser.y"
                                  {Node * cl=createNode("colon",":",{});(yyval.node)=createNode("Annassign","",{cl,(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2604 "parser.tab.c"
    break;

  case 75: /* annassign_a: EQUALS testlist_star_expr  */
#line 176 "parser.y"
                                        {Node * eq=createNode("Equals","=",{});(yyval.node)=createNode("Annassign_a","",{eq,(yyvsp[0].node)});}
#line 2610 "parser.tab.c"
    break;

  case 76: /* annassign_a: %empty  */
#line 176 "parser.y"
                                                                                                                          {(yyval.node)=createNode("Annassign_a","",{});}
#line 2616 "parser.tab.c"
    break;

  case 77: /* testlist_star_expr: test_star comm_test_star COMMA  */
#line 177 "parser.y"
                                                   {Node * cmma=createNode("comma",",",{});(yyval.node)=createNode("testlist_star","",{(yyvsp[-2].node),(yyvsp[-1].node),cmma});}
#line 2622 "parser.tab.c"
    break;

  case 78: /* testlist_star_expr: test_star comm_test_star  */
#line 178 "parser.y"
                               {(yyval.node)=createNode("Testlist_star","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2628 "parser.tab.c"
    break;

  case 79: /* test_star: test  */
#line 179 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2634 "parser.tab.c"
    break;

  case 80: /* test_star: star_expr  */
#line 180 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2640 "parser.tab.c"
    break;

  case 81: /* comm_test_star: comm_test_star COMMA test_star  */
#line 181 "parser.y"
                                               {(yyval.node)=(yyvsp[-2].node);Node * cmma=createNode("comma",",",{});(yyval.node)->children.push_back(cmma);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2646 "parser.tab.c"
    break;

  case 82: /* comm_test_star: %empty  */
#line 182 "parser.y"
                {(yyval.node)=createNode("comm_test_star", "", {});}
#line 2652 "parser.tab.c"
    break;

  case 83: /* augassign: AUGPLUS  */
#line 185 "parser.y"
             {(yyval.node)=createNode("AugAssign","+=",{});}
#line 2658 "parser.tab.c"
    break;

  case 84: /* augassign: AUGMINUS  */
#line 186 "parser.y"
               {(yyval.node)=createNode("AugAssign","-=",{});}
#line 2664 "parser.tab.c"
    break;

  case 85: /* augassign: AUGTIMES  */
#line 187 "parser.y"
               {(yyval.node)=createNode("AugAssign","*=",{});}
#line 2670 "parser.tab.c"
    break;

  case 86: /* augassign: AUGDIVIDEDBY  */
#line 188 "parser.y"
                   {(yyval.node)=createNode("AugAssign","/=",{});}
#line 2676 "parser.tab.c"
    break;

  case 87: /* augassign: AUGMODULO  */
#line 189 "parser.y"
                {(yyval.node)=createNode("AugAssign","%=",{});}
#line 2682 "parser.tab.c"
    break;

  case 88: /* augassign: AUGBIT_AND  */
#line 190 "parser.y"
                 {(yyval.node)=createNode("AugAssign","&=",{});}
#line 2688 "parser.tab.c"
    break;

  case 89: /* augassign: AUGBIT_OR  */
#line 191 "parser.y"
                {(yyval.node)=createNode("AugAssign","|=",{});}
#line 2694 "parser.tab.c"
    break;

  case 90: /* augassign: AUGBIT_XOR  */
#line 192 "parser.y"
                 {(yyval.node)=createNode("AugAssign","^=",{});}
#line 2700 "parser.tab.c"
    break;

  case 91: /* augassign: AUGBIT_RSHIFT  */
#line 193 "parser.y"
                    {(yyval.node)=createNode("AugAssign","<<=",{});}
#line 2706 "parser.tab.c"
    break;

  case 92: /* augassign: AUGBIT_LSHIFT  */
#line 194 "parser.y"
                    {(yyval.node)=createNode("AugAssign",">>=",{});}
#line 2712 "parser.tab.c"
    break;

  case 93: /* augassign: AUGPOW  */
#line 195 "parser.y"
             {(yyval.node)=createNode("AugAssign","**=",{});}
#line 2718 "parser.tab.c"
    break;

  case 94: /* augassign: AUGMOD  */
#line 196 "parser.y"
             {(yyval.node)=createNode("AugAssign","//=",{});}
#line 2724 "parser.tab.c"
    break;

  case 95: /* flow_stmt: break_stmt  */
#line 198 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2730 "parser.tab.c"
    break;

  case 96: /* flow_stmt: continue_stmt  */
#line 198 "parser.y"
                                               {(yyval.node) = (yyvsp[0].node);}
#line 2736 "parser.tab.c"
    break;

  case 97: /* flow_stmt: return_stmt  */
#line 198 "parser.y"
                                                                       {(yyval.node) = (yyvsp[0].node);}
#line 2742 "parser.tab.c"
    break;

  case 98: /* break_stmt: BREAK  */
#line 199 "parser.y"
                  {(yyval.node)=createNode("Keyword","BREAK",{});}
#line 2748 "parser.tab.c"
    break;

  case 99: /* continue_stmt: CONTINUE  */
#line 200 "parser.y"
                        {(yyval.node)=createNode("Keyword","CONTINUE",{});}
#line 2754 "parser.tab.c"
    break;

  case 100: /* return_stmt: RETURN testlist_star_expr  */
#line 201 "parser.y"
                                       {Node *n11 = createNode("Keyword","return",{}); (yyval.node)=createNode("return_stmt","",{n11, (yyvsp[0].node)});}
#line 2760 "parser.tab.c"
    break;

  case 101: /* return_stmt: RETURN  */
#line 202 "parser.y"
                    {(yyval.node)=createNode("Keyword","return",{});}
#line 2766 "parser.tab.c"
    break;

  case 102: /* global_stmt: GLOBAL IDENTIFIER comm_name  */
#line 204 "parser.y"
                                         {Node *n1 = createNode("Keyword","Global",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[-1].str),{}); (yyval.node)=createNode("global_stmt","",{n1, n2, (yyvsp[0].node)});}
#line 2772 "parser.tab.c"
    break;

  case 103: /* comm_name: comm_name COMMA IDENTIFIER  */
#line 205 "parser.y"
                                     {(yyval.node)=(yyvsp[-2].node);Node *n1 = createNode("Delimiter",",",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[0].str),{}); (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back(n2);}
#line 2778 "parser.tab.c"
    break;

  case 104: /* comm_name: %empty  */
#line 206 "parser.y"
          {(yyval.node)=createNode("comm_name", "", {});}
#line 2784 "parser.tab.c"
    break;

  case 105: /* nonlocal_stmt: NONLOCAL IDENTIFIER comm_name  */
#line 207 "parser.y"
                                             {Node *n1 = createNode("Nonlocal","nonlocal",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[-1].str),{}); (yyval.node)=createNode("nonlocal_stmt","",{n1, n2, (yyvsp[0].node)});}
#line 2790 "parser.tab.c"
    break;

  case 106: /* assert_stmt: ASSERT test comma_test_maybe  */
#line 208 "parser.y"
                                          {Node *n1 = createNode("Keyword","Assert",{});  (yyval.node)=createNode("Assert_stmt","",{n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 2796 "parser.tab.c"
    break;

  case 107: /* comma_test_maybe: COMMA test  */
#line 209 "parser.y"
                             {Node *n1=createNode("Delimiter",",",{}); (yyval.node)=createNode("comma_testmaybe","",{n1,(yyvsp[0].node)});}
#line 2802 "parser.tab.c"
    break;

  case 108: /* comma_test_maybe: %empty  */
#line 209 "parser.y"
                                                                                                                      {(yyval.node) = createNode("comma_test_maybe",",",{});}
#line 2808 "parser.tab.c"
    break;

  case 109: /* compound_stmt: if_stmt  */
#line 211 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2814 "parser.tab.c"
    break;

  case 110: /* compound_stmt: while_stmt  */
#line 211 "parser.y"
                                           {(yyval.node)=(yyvsp[0].node);}
#line 2820 "parser.tab.c"
    break;

  case 111: /* compound_stmt: for_stmt  */
#line 211 "parser.y"
                                                              {(yyval.node)=(yyvsp[0].node);}
#line 2826 "parser.tab.c"
    break;

  case 112: /* compound_stmt: funcdef  */
#line 211 "parser.y"
                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2832 "parser.tab.c"
    break;

  case 113: /* compound_stmt: classdef  */
#line 211 "parser.y"
                                                                                                   {(yyval.node)=(yyvsp[0].node);}
#line 2838 "parser.tab.c"
    break;

  case 114: /* compound_stmt: async_stmt  */
#line 211 "parser.y"
                                                                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 2844 "parser.tab.c"
    break;

  case 115: /* async_stmt: ASYNC funcdef  */
#line 212 "parser.y"
                          {Node *n1=createNode("Keyword","Async",{}); (yyval.node)=createNode("async_stmt","",{n1,(yyvsp[0].node)});}
#line 2850 "parser.tab.c"
    break;

  case 116: /* async_stmt: ASYNC for_stmt  */
#line 213 "parser.y"
                     {Node *n1=createNode("Keyword","Async",{}); (yyval.node)=createNode("async_stmt","",{n1,(yyvsp[0].node)});}
#line 2856 "parser.tab.c"
    break;

  case 117: /* if_stmt: IF test COLON suite elif_namedexprtest_colon_suite else_colon_suite_maybe  */
#line 214 "parser.y"
                                                                                   {Node *n1=createNode("KEYWORD","if",{}); Node *n2=createNode("Delimiter",":",{}); (yyval.node)=createNode("If_stmt","",{n1,(yyvsp[-4].node),n2,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2862 "parser.tab.c"
    break;

  case 118: /* while_stmt: WHILE test COLON suite else_colon_suite_maybe  */
#line 215 "parser.y"
                                                          {Node *n1=createNode("Keyword","while",{});Node *n2=createNode("Delimiter",":",{});(yyval.node)=createNode("while","",{n1,(yyvsp[-3].node),n2,(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2868 "parser.tab.c"
    break;

  case 119: /* for_stmt: FOR exprlist IN RANGE LPAREN testlist RPAREN COLON suite else_colon_suite_maybe  */
#line 216 "parser.y"
                                                                                             {
    Node* n1=createNode("Keyword","For",{});Node* n2=createNode("Keyword","In",{});
    Node* n3=createNode("Keyword","Range",{});Node* n4=createNode("Lparen","(",{});
    Node* n5=createNode("rparen",")",{});Node* n6=createNode("Delimiter",":",{});
    (yyval.node)=createNode("for","",{n1,(yyvsp[-8].node),n2,n3,n4,(yyvsp[-4].node),n5,n6,(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2878 "parser.tab.c"
    break;

  case 120: /* else_colon_suite_maybe: ELSE COLON suite  */
#line 221 "parser.y"
                                         {Node* n1=createNode("Keyword","Else",{});Node* n2=createNode("Delimiter",":",{});(yyval.node)=createNode("else","",{n1,n2,(yyvsp[0].node)});}
#line 2884 "parser.tab.c"
    break;

  case 121: /* else_colon_suite_maybe: %empty  */
#line 221 "parser.y"
                                                                                                                                                                  {(yyval.node)=createNode("else_colon_suite_maybe","",{});}
#line 2890 "parser.tab.c"
    break;

  case 122: /* elif_namedexprtest_colon_suite: elif_namedexprtest_colon_suite ELIF test COLON suite  */
#line 223 "parser.y"
                                                                                    {(yyval.node)=(yyvsp[-4].node);Node* n1=createNode("Keyword","Elif",{});Node* n2=createNode("Delimiter",":",{});(yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[-2].node));(yyval.node)->children.push_back(n2);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2896 "parser.tab.c"
    break;

  case 123: /* elif_namedexprtest_colon_suite: %empty  */
#line 224 "parser.y"
                              {(yyval.node)=createNode("elif_namedexprtest_colon_suite", "", {});}
#line 2902 "parser.tab.c"
    break;

  case 124: /* suite: simple_stmt  */
#line 227 "parser.y"
                   {(yyval.node)=(yyvsp[0].node);}
#line 2908 "parser.tab.c"
    break;

  case 125: /* suite: NEWLINE INDENT stmt_morethanone DEDENT  */
#line 228 "parser.y"
                                              {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    (yyval.node)=createNode("suite","",{n1,n2,(yyvsp[-1].node),n3});
}
#line 2917 "parser.tab.c"
    break;

  case 126: /* stmt_morethanone: stmt_morethanone stmt  */
#line 233 "parser.y"
                                        {(yyval.node)=(yyvsp[-1].node);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2923 "parser.tab.c"
    break;

  case 127: /* stmt_morethanone: stmt  */
#line 233 "parser.y"
                                                                                  {(yyval.node)=createNode("stmt_more","",{(yyvsp[0].node)});}
#line 2929 "parser.tab.c"
    break;

  case 128: /* test: or_test if_ortest_else_test_maybe  */
#line 235 "parser.y"
                                        {(yyval.node)=createNode("test","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2935 "parser.tab.c"
    break;

  case 129: /* if_ortest_else_test_maybe: IF or_test ELSE test  */
#line 236 "parser.y"
                                                {
    Node * n1=createNode("Keyword","if",{});Node * n2=createNode("Keyword","else",{});
    (yyval.node)=createNode("if_or_else","",{n1,(yyvsp[-2].node),n2,(yyvsp[0].node)});
}
#line 2944 "parser.tab.c"
    break;

  case 130: /* if_ortest_else_test_maybe: %empty  */
#line 239 "parser.y"
   {(yyval.node) = createNode("if_ortest_else_test_maybe","",{});}
#line 2950 "parser.tab.c"
    break;

  case 131: /* or_test: and_test or_andtest  */
#line 241 "parser.y"
                             {(yyval.node)=createNode("or_test","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2956 "parser.tab.c"
    break;

  case 132: /* or_andtest: or_andtest OR and_test  */
#line 242 "parser.y"
                                   {(yyval.node)=(yyvsp[-2].node);Node * n1=createNode("Keyword","or",{});
    (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2963 "parser.tab.c"
    break;

  case 133: /* or_andtest: %empty  */
#line 244 "parser.y"
      {(yyval.node)=createNode("or_andtest", "", {});}
#line 2969 "parser.tab.c"
    break;

  case 134: /* and_test: not_test and_nottest  */
#line 246 "parser.y"
                               {(yyval.node)=createNode("and_test","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2975 "parser.tab.c"
    break;

  case 135: /* and_nottest: and_nottest AND not_test  */
#line 247 "parser.y"
                                      {(yyval.node)=(yyvsp[-2].node);Node * n1=createNode("Keyword","And",{});
    (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 2982 "parser.tab.c"
    break;

  case 136: /* and_nottest: %empty  */
#line 249 "parser.y"
      {(yyval.node)=createNode("and_nottest", "", {});}
#line 2988 "parser.tab.c"
    break;

  case 137: /* not_test: NOT not_test  */
#line 251 "parser.y"
                      {(yyval.node)=createNode("Keyword","not",{}); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 2994 "parser.tab.c"
    break;

  case 138: /* not_test: comparison  */
#line 251 "parser.y"
                                                                                                    {(yyval.node)=(yyvsp[0].node);}
#line 3000 "parser.tab.c"
    break;

  case 139: /* comparison: expr comp_op_expr  */
#line 252 "parser.y"
                              {(yyval.node)=createNode("comp","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3006 "parser.tab.c"
    break;

  case 140: /* comp_op_expr: comp_op_expr comp_op expr  */
#line 254 "parser.y"
                                        {(yyval.node)=(yyvsp[-2].node);(yyval.node)->children.push_back((yyvsp[-1].node));(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3012 "parser.tab.c"
    break;

  case 141: /* comp_op_expr: %empty  */
#line 255 "parser.y"
              {(yyval.node)=createNode("comp_op_expr", "", {});}
#line 3018 "parser.tab.c"
    break;

  case 142: /* comp_op: LT  */
#line 259 "parser.y"
  {(yyval.node)=createNode("Operator","<",{});}
#line 3024 "parser.tab.c"
    break;

  case 143: /* comp_op: GT  */
#line 260 "parser.y"
    {(yyval.node)=createNode("Operator",">",{});}
#line 3030 "parser.tab.c"
    break;

  case 144: /* comp_op: EQ  */
#line 261 "parser.y"
    {(yyval.node)=createNode("Operator","==",{});}
#line 3036 "parser.tab.c"
    break;

  case 145: /* comp_op: GTE  */
#line 262 "parser.y"
     {(yyval.node)=createNode("Operator",">=",{});}
#line 3042 "parser.tab.c"
    break;

  case 146: /* comp_op: LTE  */
#line 263 "parser.y"
     {(yyval.node)=createNode("Operator","<=",{});}
#line 3048 "parser.tab.c"
    break;

  case 147: /* comp_op: NEQ  */
#line 264 "parser.y"
     {(yyval.node)=createNode("Operator","!=",{});}
#line 3054 "parser.tab.c"
    break;

  case 148: /* comp_op: IN  */
#line 265 "parser.y"
    {(yyval.node)=createNode("Keyword","in",{});}
#line 3060 "parser.tab.c"
    break;

  case 149: /* comp_op: NOT IN  */
#line 266 "parser.y"
        {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","in",{});(yyval.node)=createNode("not in","",{n1,n2});}
#line 3066 "parser.tab.c"
    break;

  case 150: /* comp_op: IS  */
#line 267 "parser.y"
    {(yyval.node)=createNode("Keyword","is",{});}
#line 3072 "parser.tab.c"
    break;

  case 151: /* comp_op: IS NOT  */
#line 268 "parser.y"
        {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","is",{});(yyval.node)=createNode("is not","",{n2,n1});}
#line 3078 "parser.tab.c"
    break;

  case 152: /* star_expr: TIMES expr  */
#line 270 "parser.y"
                      {Node *n1=createNode("Operator","*",{});(yyval.node)=createNode("star_expr","",{n1,(yyvsp[0].node)});}
#line 3084 "parser.tab.c"
    break;

  case 153: /* expr: xor_expr bitor_xorexpr  */
#line 271 "parser.y"
                             {(yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3090 "parser.tab.c"
    break;

  case 154: /* bitor_xorexpr: bitor_xorexpr BIT_OR xor_expr  */
#line 272 "parser.y"
                                             {(yyval.node)=(yyvsp[-2].node);Node * n1=createNode("Bit_op","|",{});
    (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3097 "parser.tab.c"
    break;

  case 155: /* bitor_xorexpr: %empty  */
#line 274 "parser.y"
      {(yyval.node)=createNode("bitor_xorexpr", "", {});}
#line 3103 "parser.tab.c"
    break;

  case 156: /* xor_expr: and_expr bitxor_andexpr  */
#line 275 "parser.y"
                                  {(yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3109 "parser.tab.c"
    break;

  case 157: /* bitxor_andexpr: bitxor_andexpr BIT_XOR and_expr  */
#line 276 "parser.y"
                                                {(yyval.node)=(yyvsp[-2].node);Node * n1=createNode("Bit_op","^",{});
    (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3116 "parser.tab.c"
    break;

  case 158: /* bitxor_andexpr: %empty  */
#line 277 "parser.y"
                                                              {(yyval.node)=createNode("bitxor_andexpr", "", {});}
#line 3122 "parser.tab.c"
    break;

  case 159: /* and_expr: shift_expr bitand_shiftexpr  */
#line 278 "parser.y"
                                      {(yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3128 "parser.tab.c"
    break;

  case 160: /* bitand_shiftexpr: bitand_shiftexpr BIT_AND shift_expr  */
#line 279 "parser.y"
                                                      {(yyval.node)=(yyvsp[-2].node);Node * n1=createNode("Bit_op","&",{});
    (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3135 "parser.tab.c"
    break;

  case 161: /* bitand_shiftexpr: %empty  */
#line 280 "parser.y"
                                                             {(yyval.node)=createNode("bitand_shiftexpr", "", {});}
#line 3141 "parser.tab.c"
    break;

  case 162: /* shift_expr: arith_expr lorrshift_arithexpr  */
#line 281 "parser.y"
                                           {(yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3147 "parser.tab.c"
    break;

  case 163: /* lorrshift_arithexpr: lorrshift_arithexpr lshift_or_rshift arith_expr  */
#line 283 "parser.y"
                                                                     {(yyval.node)=(yyvsp[-2].node);(yyval.node)->children.push_back((yyvsp[-1].node));(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3153 "parser.tab.c"
    break;

  case 164: /* lorrshift_arithexpr: %empty  */
#line 283 "parser.y"
                                                                                                                                      {(yyval.node)=createNode("lorrshift_arithexpr", "", {});}
#line 3159 "parser.tab.c"
    break;

  case 165: /* lshift_or_rshift: BIT_LSHIFT  */
#line 284 "parser.y"
                             {(yyval.node)=createNode("Bit_left_shift","<<",{});}
#line 3165 "parser.tab.c"
    break;

  case 166: /* lshift_or_rshift: BIT_RSHIFT  */
#line 284 "parser.y"
                                                                                     {(yyval.node)=createNode("Bit_right_shift",">>",{});}
#line 3171 "parser.tab.c"
    break;

  case 167: /* arith_expr: term plusorminus_term  */
#line 285 "parser.y"
                                  {(yyval.node)=createNode("arith_expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3177 "parser.tab.c"
    break;

  case 168: /* plusorminus_term: plusorminus_term plus_or_minus term  */
#line 286 "parser.y"
                                                       {(yyval.node)=(yyvsp[-2].node);(yyval.node)->children.push_back((yyvsp[-1].node));(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3183 "parser.tab.c"
    break;

  case 169: /* plusorminus_term: %empty  */
#line 286 "parser.y"
                                                                                                                        {(yyval.node)=createNode("plusorminus_term", "", {});}
#line 3189 "parser.tab.c"
    break;

  case 170: /* plus_or_minus: PLUS  */
#line 287 "parser.y"
                    {(yyval.node)=createNode("Operator","+",{});}
#line 3195 "parser.tab.c"
    break;

  case 171: /* plus_or_minus: MINUS  */
#line 287 "parser.y"
                                                               {(yyval.node)=createNode("Operator","-",{});}
#line 3201 "parser.tab.c"
    break;

  case 172: /* term: factor timedivmod_factor  */
#line 288 "parser.y"
                               {(yyval.node)=createNode("term","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3207 "parser.tab.c"
    break;

  case 173: /* timedivmod_factor: timedivmod_factor timedivmod factor  */
#line 289 "parser.y"
                                                       {(yyval.node)=(yyvsp[-2].node);(yyval.node)->children.push_back((yyvsp[-1].node));(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3213 "parser.tab.c"
    break;

  case 174: /* timedivmod_factor: %empty  */
#line 289 "parser.y"
                                                                                                                       {(yyval.node)=createNode("timedivmod_factor", "", {});}
#line 3219 "parser.tab.c"
    break;

  case 175: /* timedivmod: TIMES  */
#line 290 "parser.y"
                 {(yyval.node)=createNode("Operator","*",{});}
#line 3225 "parser.tab.c"
    break;

  case 176: /* timedivmod: DIVIDEDBY  */
#line 290 "parser.y"
                                                              {(yyval.node)=createNode("Operator","/",{});}
#line 3231 "parser.tab.c"
    break;

  case 177: /* timedivmod: MODULO  */
#line 290 "parser.y"
                                                                                                        {(yyval.node)=createNode("Operator","%",{});}
#line 3237 "parser.tab.c"
    break;

  case 178: /* timedivmod: MOD  */
#line 290 "parser.y"
                                                                                                                                                {(yyval.node)=createNode("Operator","//",{});}
#line 3243 "parser.tab.c"
    break;

  case 179: /* factor: plusminusnot factor  */
#line 291 "parser.y"
                            {(yyval.node)=(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 3249 "parser.tab.c"
    break;

  case 180: /* factor: power  */
#line 291 "parser.y"
                                                                         {(yyval.node)=(yyvsp[0].node);}
#line 3255 "parser.tab.c"
    break;

  case 181: /* plusminusnot: PLUS  */
#line 292 "parser.y"
                   {(yyval.node)=createNode("Operator","+",{});}
#line 3261 "parser.tab.c"
    break;

  case 182: /* plusminusnot: MINUS  */
#line 292 "parser.y"
                                                              {(yyval.node)=createNode("Operator","-",{});}
#line 3267 "parser.tab.c"
    break;

  case 183: /* plusminusnot: BIT_NOT  */
#line 292 "parser.y"
                                                                                                          {(yyval.node)=createNode("Operator","~",{});}
#line 3273 "parser.tab.c"
    break;

  case 184: /* power: atom_expr pow_factor_maybe  */
#line 293 "parser.y"
                                  {(yyval.node)=createNode("power","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3279 "parser.tab.c"
    break;

  case 185: /* pow_factor_maybe: POW factor  */
#line 294 "parser.y"
                             {Node *n1=createNode("Operator","**",{});(yyval.node)=createNode("pow_maybe","",{n1,(yyvsp[0].node)});}
#line 3285 "parser.tab.c"
    break;

  case 186: /* pow_factor_maybe: %empty  */
#line 294 "parser.y"
                                                                                                                {(yyval.node)=createNode("pow_maybe","",{});}
#line 3291 "parser.tab.c"
    break;

  case 187: /* atom_expr: AWAIT atom trailer_  */
#line 295 "parser.y"
                               {Node *n1=createNode("KEYWORD","AWAIT",{});(yyval.node)=createNode("atom_expr","",{n1,(yyvsp[-1].node)});}
#line 3297 "parser.tab.c"
    break;

  case 188: /* atom_expr: atom trailer_  */
#line 295 "parser.y"
                                                                                                                                  {(yyval.node)=createNode("atom_expr","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3303 "parser.tab.c"
    break;

  case 189: /* trailer_: trailer_ trailer  */
#line 296 "parser.y"
                           {(yyval.node)=(yyvsp[-1].node);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3309 "parser.tab.c"
    break;

  case 190: /* trailer_: %empty  */
#line 296 "parser.y"
                                                                {(yyval.node)=createNode("trailer_", "", {});}
#line 3315 "parser.tab.c"
    break;

  case 191: /* atom: LPAREN testlist_comp RPAREN  */
#line 297 "parser.y"
                                  {Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});(yyval.node)=createNode("atom","",{n1,(yyvsp[-1].node),n2});}
#line 3321 "parser.tab.c"
    break;

  case 192: /* atom: LEN LPAREN testlist_comp RPAREN  */
#line 298 "parser.y"
                                        {Node *n3=createNode("KEYWORD","len",{});Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});(yyval.node)=createNode("atom","",{n3,n1,(yyvsp[-1].node),n2});}
#line 3327 "parser.tab.c"
    break;

  case 193: /* atom: LLIST testlist_comp RLIST  */
#line 300 "parser.y"
                                   {Node *n1=createNode("Delimiter","[",{});Node *n2=createNode("Delimiter","]",{});(yyval.node)=createNode("atom","",{n1,(yyvsp[-1].node),n2});}
#line 3333 "parser.tab.c"
    break;

  case 194: /* atom: IDENTIFIER  */
#line 301 "parser.y"
                  {(yyval.node)=createNode("Identifer",*(yyvsp[0].str),{});}
#line 3339 "parser.tab.c"
    break;

  case 195: /* atom: NUMBER  */
#line 301 "parser.y"
                                                                {(yyval.node)=createNode("Number",*(yyvsp[0].str),{});}
#line 3345 "parser.tab.c"
    break;

  case 196: /* atom: string_pl  */
#line 301 "parser.y"
                                                                                                            {(yyval.node)=(yyvsp[0].node);}
#line 3351 "parser.tab.c"
    break;

  case 197: /* atom: FLOATING_POINT  */
#line 301 "parser.y"
                                                                                                                                     {(yyval.node)=createNode("FLoating_point",*(yyvsp[0].str),{});}
#line 3357 "parser.tab.c"
    break;

  case 198: /* atom: NONE  */
#line 303 "parser.y"
              {(yyval.node)=createNode("KEYWORD","None",{});}
#line 3363 "parser.tab.c"
    break;

  case 199: /* atom: TRUE  */
#line 303 "parser.y"
                                                           {(yyval.node)=createNode("KEYWORD","True",{});}
#line 3369 "parser.tab.c"
    break;

  case 200: /* atom: FALSE  */
#line 303 "parser.y"
                                                                                                         {(yyval.node)=createNode("KEYWORD","False",{});}
#line 3375 "parser.tab.c"
    break;

  case 201: /* string_pl: string_pl STR_LIT  */
#line 306 "parser.y"
                             {(yyval.node)=(yyvsp[-1].node);Node * n1= createNode("Str",*(yyvsp[0].str),{});(yyval.node)->children.push_back(n1);}
#line 3381 "parser.tab.c"
    break;

  case 202: /* string_pl: STR_LIT  */
#line 306 "parser.y"
                                                                                                               {(yyval.node)= createNode("Str",*(yyvsp[0].str),{});}
#line 3387 "parser.tab.c"
    break;

  case 203: /* testlist_comp: %empty  */
#line 307 "parser.y"
               {(yyval.node)=createNode("testlist_comp","",{});}
#line 3393 "parser.tab.c"
    break;

  case 204: /* testlist_comp: test testlist_comp_a  */
#line 307 "parser.y"
                                                                             {(yyval.node)=createNode("testlist_comp","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3399 "parser.tab.c"
    break;

  case 205: /* testlist_comp: star_expr testlist_comp_a  */
#line 307 "parser.y"
                                                                                                                                                     {(yyval.node)=createNode("testlist_comp","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 3405 "parser.tab.c"
    break;

  case 206: /* testlist_comp_a: comp_for  */
#line 308 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3411 "parser.tab.c"
    break;

  case 207: /* testlist_comp_a: comma_testorstar COMMA  */
#line 308 "parser.y"
                                                           {Node *n1=createNode("Delimiter",",",{});(yyval.node)=createNode("testlist_comp_a","",{(yyvsp[-1].node),n1});}
#line 3417 "parser.tab.c"
    break;

  case 208: /* testlist_comp_a: comma_testorstar  */
#line 308 "parser.y"
                                                                                                                                                                     {(yyval.node)=(yyvsp[0].node);}
#line 3423 "parser.tab.c"
    break;

  case 209: /* comma_testorstar: comma_testorstar COMMA test_or_starexpr  */
#line 309 "parser.y"
                                                          {
    (yyval.node)=(yyvsp[-2].node);
    Node *n1=createNode("Delimiter",",",{});
    (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 3433 "parser.tab.c"
    break;

  case 210: /* comma_testorstar: %empty  */
#line 313 "parser.y"
    {(yyval.node)=createNode("comma_testorstar", "", {});}
#line 3439 "parser.tab.c"
    break;

  case 211: /* test_or_starexpr: test  */
#line 314 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 3445 "parser.tab.c"
    break;

  case 212: /* test_or_starexpr: star_expr  */
#line 314 "parser.y"
                                          {(yyval.node)=(yyvsp[0].node);}
#line 3451 "parser.tab.c"
    break;

  case 213: /* trailer: LPAREN arglist RPAREN  */
#line 315 "parser.y"
                               { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer", "", {n1, (yyvsp[-1].node), n2});}
#line 3459 "parser.tab.c"
    break;

  case 214: /* trailer: LPAREN RPAREN  */
#line 318 "parser.y"
                                                { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer", "", {n1, n2});}
#line 3467 "parser.tab.c"
    break;

  case 215: /* trailer: LLIST subscriptlist RLIST  */
#line 321 "parser.y"
                                                            { Node *n1=createNode("Delimiter", "[", {}); 
                                Node *n2=createNode("Delimiter", "]", {});
                                (yyval.node)=createNode("trailer", "", {n1, (yyvsp[-1].node), n2});}
#line 3475 "parser.tab.c"
    break;

  case 216: /* trailer: DOT IDENTIFIER  */
#line 324 "parser.y"
                                                 { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifer", *(yyvsp[0].str), {});
                                (yyval.node)=createNode("trailer", "", {n1, n2});}
#line 3483 "parser.tab.c"
    break;

  case 217: /* subscriptlist: subscript comma_subscript COMMA  */
#line 327 "parser.y"
                                               { Node *n1=createNode("Delimiter", ",", {});
                                (yyval.node)=createNode("subscriptlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});}
#line 3490 "parser.tab.c"
    break;

  case 218: /* subscriptlist: subscript comma_subscript  */
#line 329 "parser.y"
                                                            { (yyval.node)=createNode("subscriptlist", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 3496 "parser.tab.c"
    break;

  case 219: /* comma_subscript: comma_subscript COMMA subscript  */
#line 330 "parser.y"
                                                 { (yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {});
                                (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 3503 "parser.tab.c"
    break;

  case 220: /* comma_subscript: %empty  */
#line 331 "parser.y"
                                                                                          {(yyval.node)=createNode("comma_subscript", "", {});}
#line 3509 "parser.tab.c"
    break;

  case 221: /* subscript: test  */
#line 332 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 3515 "parser.tab.c"
    break;

  case 222: /* subscript: test COLON test sliceop_maybe  */
#line 332 "parser.y"
                                                        { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {(yyvsp[-3].node), n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3522 "parser.tab.c"
    break;

  case 223: /* subscript: test COLON sliceop_maybe  */
#line 334 "parser.y"
                                                           { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {(yyvsp[-2].node), n1, (yyvsp[0].node)});}
#line 3529 "parser.tab.c"
    break;

  case 224: /* subscript: COLON test sliceop_maybe  */
#line 336 "parser.y"
                                                           { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3536 "parser.tab.c"
    break;

  case 225: /* subscript: COLON sliceop_maybe  */
#line 338 "parser.y"
                                                      { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {n1, (yyvsp[0].node)});}
#line 3543 "parser.tab.c"
    break;

  case 226: /* sliceop_maybe: sliceop  */
#line 340 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 3549 "parser.tab.c"
    break;

  case 227: /* sliceop_maybe: %empty  */
#line 340 "parser.y"
                                 {(yyval.node)=createNode("sliceop_maybe","",{});}
#line 3555 "parser.tab.c"
    break;

  case 228: /* sliceop: COLON test  */
#line 341 "parser.y"
                    { Node *n1=createNode("Delimiter", ":", {}); (yyval.node)=createNode("sliceop", "", {n1, (yyvsp[0].node)});}
#line 3561 "parser.tab.c"
    break;

  case 229: /* sliceop: COLON  */
#line 341 "parser.y"
                                                                                                                 {(yyval.node)=createNode("Delimiter", ":", {});}
#line 3567 "parser.tab.c"
    break;

  case 230: /* exprlist: expr_str comm_exstr COMMA  */
#line 342 "parser.y"
                                    { Node *n1=createNode("Delimiter", ",", {}); (yyval.node)=createNode("exprlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});}
#line 3573 "parser.tab.c"
    break;

  case 231: /* exprlist: expr_str comm_exstr  */
#line 342 "parser.y"
                                                                                                                                                    {(yyval.node)=createNode("exprlist", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 3579 "parser.tab.c"
    break;

  case 232: /* expr_str: expr  */
#line 343 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3585 "parser.tab.c"
    break;

  case 233: /* expr_str: star_expr  */
#line 343 "parser.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 3591 "parser.tab.c"
    break;

  case 234: /* comm_exstr: comm_exstr COMMA expr_str  */
#line 344 "parser.y"
                                      {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 3597 "parser.tab.c"
    break;

  case 235: /* comm_exstr: %empty  */
#line 344 "parser.y"
                                                                                                                                                    {(yyval.node)=createNode("comm_exstr", "", {});}
#line 3603 "parser.tab.c"
    break;

  case 236: /* testlist: test comm_test COMMA  */
#line 345 "parser.y"
                               { Node *n1=createNode("Delimiter", ",", {}); (yyval.node)=createNode("testlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});}
#line 3609 "parser.tab.c"
    break;

  case 237: /* testlist: test comm_test  */
#line 345 "parser.y"
                                                                                                                                           {(yyval.node)=createNode("testlist", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 3615 "parser.tab.c"
    break;

  case 238: /* comm_test: comm_test COMMA test  */
#line 346 "parser.y"
                                {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 3621 "parser.tab.c"
    break;

  case 239: /* comm_test: %empty  */
#line 346 "parser.y"
                                                                                                                                              {(yyval.node)=createNode("comm_test", "", {});}
#line 3627 "parser.tab.c"
    break;

  case 240: /* classdef: CLASS IDENTIFIER l_arglist_r_maybe COLON suite  */
#line 353 "parser.y"
                                                          { Node *n1=createNode("KEYWORD", "CLASS", {}); 
                                                            Node *n2=createNode("Identifier", *(yyvsp[-3].str), {});
                                                            Node *n3=createNode("Delimiter", ":", {});
                                                            (yyval.node)=createNode("classdef", "", {n1, n2, (yyvsp[-2].node), n3, (yyvsp[0].node)});}
#line 3636 "parser.tab.c"
    break;

  case 241: /* l_arglist_r_maybe: LPAREN arglist RPAREN  */
#line 357 "parser.y"
                                         { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("l_arglist_r_maybe", "", {n1, (yyvsp[-1].node), n2});}
#line 3644 "parser.tab.c"
    break;

  case 242: /* l_arglist_r_maybe: %empty  */
#line 359 "parser.y"
                                                                                         {(yyval.node)=createNode("l_arglist_r_maybe", "", {});}
#line 3650 "parser.tab.c"
    break;

  case 243: /* arglist: argument comm_arg COMMA  */
#line 361 "parser.y"
                                 { Node *n1=createNode("Delimiter", ",", {}); (yyval.node)=createNode("arglist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});}
#line 3656 "parser.tab.c"
    break;

  case 244: /* arglist: argument comm_arg  */
#line 361 "parser.y"
                                                                                                                                               {(yyval.node)=createNode("arglist", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 3662 "parser.tab.c"
    break;

  case 245: /* comm_arg: comm_arg COMMA argument  */
#line 362 "parser.y"
                                  {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 3668 "parser.tab.c"
    break;

  case 246: /* comm_arg: %empty  */
#line 362 "parser.y"
                                                                                                                                               {(yyval.node)=createNode("comm_arg", "", {});}
#line 3674 "parser.tab.c"
    break;

  case 247: /* argument: test comp_for  */
#line 363 "parser.y"
                         {(yyval.node)=createNode("argument", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 3680 "parser.tab.c"
    break;

  case 248: /* argument: test  */
#line 364 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 3686 "parser.tab.c"
    break;

  case 249: /* argument: test EQUALS test  */
#line 365 "parser.y"
                             { Node *n1=createNode("Equals", "=", {}); (yyval.node)=createNode("argument", "", {(yyvsp[-2].node), n1, (yyvsp[0].node)});}
#line 3692 "parser.tab.c"
    break;

  case 250: /* argument: POW test  */
#line 366 "parser.y"
                     { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("argument", "", {n1, (yyvsp[0].node)});}
#line 3698 "parser.tab.c"
    break;

  case 251: /* argument: TIMES test  */
#line 367 "parser.y"
                       { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("argument", "", {n1, (yyvsp[0].node)});}
#line 3704 "parser.tab.c"
    break;

  case 252: /* comp_iter: comp_for  */
#line 369 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 3710 "parser.tab.c"
    break;

  case 253: /* comp_iter: comp_if  */
#line 369 "parser.y"
                                     {(yyval.node)=(yyvsp[0].node);}
#line 3716 "parser.tab.c"
    break;

  case 254: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 370 "parser.y"
                                                 { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    (yyval.node)=createNode("sync_comp_for", "", {n1, (yyvsp[-3].node), n2, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3724 "parser.tab.c"
    break;

  case 255: /* sync_comp_for: FOR exprlist IN or_test  */
#line 373 "parser.y"
                          { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    (yyval.node)=createNode("sync_comp_for", "", {n1, (yyvsp[-2].node), n2, (yyvsp[0].node)});}
#line 3732 "parser.tab.c"
    break;

  case 256: /* comp_for: ASYNC sync_comp_for  */
#line 376 "parser.y"
                              { Node *n1=createNode("KEYWORD", "ASYNC", {}); 
                                (yyval.node)=createNode("comp_for", "", {n1, (yyvsp[0].node)});}
#line 3739 "parser.tab.c"
    break;

  case 257: /* comp_for: sync_comp_for  */
#line 378 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3745 "parser.tab.c"
    break;

  case 258: /* comp_if: IF or_test comp_iter  */
#line 379 "parser.y"
                              { Node *n1=createNode("KEYWORD", "IF", {}); 
                                (yyval.node)=createNode("comp_if", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3752 "parser.tab.c"
    break;

  case 259: /* comp_if: IF or_test  */
#line 381 "parser.y"
                                              { Node *n1=createNode("KEYWORD", "IF", {}); 
                                (yyval.node)=createNode("comp_if", "", {n1, (yyvsp[0].node)});}
#line 3759 "parser.tab.c"
    break;

  case 260: /* func_body_suite: simple_stmt  */
#line 387 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 3765 "parser.tab.c"
    break;

  case 261: /* func_body_suite: NEWLINE INDENT stmt_morethanone DEDENT  */
#line 387 "parser.y"
                                                                              {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    (yyval.node)=createNode("func_body_suite","",{n1,n2,(yyvsp[-1].node),n3});
}
#line 3774 "parser.tab.c"
    break;

  case 262: /* func_type_input: func_type nls ENDMARKER  */
#line 392 "parser.y"
                                         {
    Node * n1=createNode("Endmarker","<<EOF>>",{}); (yyval.node)=createNode("func_type_input","",{(yyvsp[-2].node),(yyvsp[-1].node),n1});
}
#line 3782 "parser.tab.c"
    break;

  case 263: /* nls: nls NEWLINE  */
#line 395 "parser.y"
                 {(yyval.node)=(yyvsp[-1].node); Node *n1 = createNode("Newline","nl",{}); (yyval.node)->children.push_back(n1);}
#line 3788 "parser.tab.c"
    break;

  case 264: /* nls: %empty  */
#line 395 "parser.y"
                                                                                                 {(yyval.node)=createNode("nls", "", {});}
#line 3794 "parser.tab.c"
    break;

  case 265: /* func_type: LPAREN typelist RPAREN R_ARR test  */
#line 396 "parser.y"
                                             { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-3].node), n2, n3, (yyvsp[0].node)});}
#line 3803 "parser.tab.c"
    break;

  case 266: /* func_type: LPAREN RPAREN R_ARR test  */
#line 400 "parser.y"
                                   { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                (yyval.node)=createNode("func_type", "", {n1, n2, n3, (yyvsp[0].node)});}
#line 3812 "parser.tab.c"
    break;

  case 267: /* typelist: test comm_test comma_typel_maybe  */
#line 405 "parser.y"
                                           {(yyval.node)=createNode("typelist", "", {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3818 "parser.tab.c"
    break;

  case 268: /* typelist: TIMES test comm_test comma_pow_test_maybe  */
#line 406 "parser.y"
                                                  { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3824 "parser.tab.c"
    break;

  case 269: /* typelist: TIMES comm_test comma_pow_test_maybe  */
#line 407 "parser.y"
                                            { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3830 "parser.tab.c"
    break;

  case 270: /* typelist: POW test  */
#line 408 "parser.y"
                { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[0].node)});}
#line 3836 "parser.tab.c"
    break;

  case 271: /* comma_typel_maybe: COMMA type_l  */
#line 409 "parser.y"
                                { Node *n1=createNode("Delimiter", ",", {}); (yyval.node)=createNode("comma_typel_maybe", "", {n1, (yyvsp[0].node)});}
#line 3842 "parser.tab.c"
    break;

  case 272: /* comma_typel_maybe: COMMA  */
#line 410 "parser.y"
                        { (yyval.node)=createNode("Delimiter", ",", {});}
#line 3848 "parser.tab.c"
    break;

  case 273: /* comma_typel_maybe: %empty  */
#line 410 "parser.y"
                                                                 {(yyval.node)=createNode("comma_typel_maybe", "", {});}
#line 3854 "parser.tab.c"
    break;

  case 274: /* type_l: TIMES test comm_test comma_pow_test_maybe  */
#line 411 "parser.y"
                                                  { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3860 "parser.tab.c"
    break;

  case 275: /* type_l: TIMES comm_test comma_pow_test_maybe  */
#line 412 "parser.y"
                                               { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3866 "parser.tab.c"
    break;

  case 276: /* type_l: POW test  */
#line 413 "parser.y"
                   { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[0].node)});}
#line 3872 "parser.tab.c"
    break;

  case 277: /* comma_pow_test_maybe: COMMA POW test  */
#line 414 "parser.y"
                                     {Node *n1=createNode("Delimiter",",",{});Node *n2=createNode("Operator","*",{});(yyval.node)=createNode("comma_pow_test_maybe","",{n1,n2,(yyvsp[0].node)});}
#line 3878 "parser.tab.c"
    break;

  case 278: /* comma_pow_test_maybe: %empty  */
#line 414 "parser.y"
                                                                                                                                                                            {(yyval.node)=createNode("comma_pow_test_maybe","",{});}
#line 3884 "parser.tab.c"
    break;


#line 3888 "parser.tab.c"

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
          = {yyps, yytoken};
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
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yystacksize
#line 415 "parser.y"





int node_counter = 0;
string dfs(Node* node,ofstream &out) {
    // Generate the label for the current node
    
    if(node->children.size()==1) return dfs(node->children[0], out);
        if(node->children.size()==2){
            if(node->children[1]->children.empty() && node->children[1]->value.empty()) return dfs(node->children[0],out);
            if(node->children[0]->children.empty() && node->children[0]->value.empty()) return dfs(node->children[1],out);
        }
        // if(parent!=NULL and parent->children.size()==2){
        //     if (node==parent->children[0]){
        //         if(parent->children[1]->children.size()==1 and parent->children[1]->value.empty()){

        //         }
        //     }
        // }
        string node_name = "node_" + to_string(node_counter++);
        
        
        string temp;
        if ((node->value)[0] == '"') {
            temp = "\\" + node->value.substr(0, node->value.size() - 1) + "\\\"";
        } else {
            temp = node->value;
        }
        string node_label = node->value.empty() ? node->label : node->label + "(" + temp+")";
        if(!node->children.empty() or !node->value.empty())
            out << node_name << " [label=\"" << node_label << "\"]" << endl;

        for (auto child : node->children) {
            if(child->value.empty() && child->children.empty()) continue;
            string child_name = dfs(child,out);
            out << node_name << " -> " << child_name << endl;
        }
        
        return node_name;
    }


void print_path(Node *node,int t){
    if (node== nullptr){
        return;
    }
    for(int i=0; i<t; i++){
        cout<<'\t';
    }
    cout<<(node->label+"("+node->value+")")<<" -> ";
    for(auto i: node->children){
        cout<<(node->label+"("+node->value+")")<<" ";
    }
    cout<<endl;
    t++;
    for(auto child:node->children){
        print_path(child,t);
    }


}

void generateDotFile(string outp) {
    if (root == nullptr) {
        return;
    }
    ofstream out(outp);
    // out.open()
    out << "digraph G {" << endl;
    out << "  node [shape=ellipse, style=filled, fillcolor=white]" << endl;
    
   

    dfs(root,out);

    out << "}" << endl;
    out.close();
}


void print_help() {
    cout << "Usage options     \n\n";
    cout << "Commands:\n-h, --help \t\t\t\t\t help and options\n";
    cout << "-i, --input <input_file_name> \t\t\t Give input file\n";
    cout << "-o, --output <output_file_name>\t\t\t Redirect dot file to output file\n";
    cout << "-v, --verbose \t\t\t\t\t Outputs the entire derivation in command line\n";
    return;
}


int main (int argc, char *argv[]) {
    bool verbose=false;
    for(int i = 1; i < argc; i++){        
        if(std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h") {
            print_help();
            return -1;
        }
        else if(std::string(argv[i]) == "--input" || std::string(argv[i]) == "-i") {
            if((i + 1) < argc) input_file = argv[i+1];
            else {cout << "Error: No input filename given";return -1;}
            i++;
        }
        else if(std::string(argv[i]) == "--output" || std::string(argv[i]) == "-o") {
            if((i + 1) < argc) output_file = argv[i+1];
            else {cout << "Error: No output filename given";return -1;}
            i++;
        }
        else if(std::string(argv[i]) == "--verbose" || std::string(argv[i]) == "-v") {
            verbose = true;
        }
        else {
            cout << "Error: Invalid parameter\n";
            print_help();
            return -1;
        }
    }
    program = fopen(input_file.c_str(), "r");
    if(!program) {
        cout << "Error: Program file could not be opened" << endl;
        return -1;
    }

    yyin = program;
    yyout = stderr;
    yylex();
    if(verbose){
        print_path(root,0);
    }
    //cout<<"done\n";
    generateDotFile(output_file);
    fclose(program);
    return 1;
}
