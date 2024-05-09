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
    // #include "ast1.h"
    #include "x86.h"
    extern int yylex();
    #define YYERROR_VERBOSE 1
    // extern int yyparse();
    extern FILE *yyin;
    extern int yylineno;
    extern int yydebug;
    extern symbol_table_global * main_st;
    extern symbol_table_global* ogroot;
    extern symbol_table* orig;
    extern symbol_table *curr;
    extern FILE *yyout;
    vector<quad*> ircode;
    int tac_line=0;
    FILE *program;
    string input_file = "../tests/testcase1.py";
    string output_file = "asm.s";
    string asm_file="asm.s"; 
    codegen* gen= new codegen();
    int temp_cnt=0;
    int is_funccall=0;
    int is_ctorcall=0;
    int is_print_string=0;
    string trailer_attr="";


    void yyerror(const char *s) {
 
    fprintf(stderr, "Error at line %d: %s\n",yylineno, s);}
    extern Node *root;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *temp = new Node();
    temp->value = value;
    temp->children = children;
    temp->label = label;
    temp->line_no=yylineno;

    return temp;
}

#line 118 "parser.tab.c"

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
  YYSYMBOL_NONE = 16,                      /* NONE  */
  YYSYMBOL_EQUALS = 17,                    /* EQUALS  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 21,                 /* DIVIDEDBY  */
  YYSYMBOL_NEWLINE = 22,                   /* NEWLINE  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_MODULO = 24,                    /* MODULO  */
  YYSYMBOL_AUGPLUS = 25,                   /* AUGPLUS  */
  YYSYMBOL_AUGMINUS = 26,                  /* AUGMINUS  */
  YYSYMBOL_AUGTIMES = 27,                  /* AUGTIMES  */
  YYSYMBOL_AUGDIVIDEDBY = 28,              /* AUGDIVIDEDBY  */
  YYSYMBOL_AUGMOD = 29,                    /* AUGMOD  */
  YYSYMBOL_AUGMODULO = 30,                 /* AUGMODULO  */
  YYSYMBOL_POW = 31,                       /* POW  */
  YYSYMBOL_AUGPOW = 32,                    /* AUGPOW  */
  YYSYMBOL_BIT_AND = 33,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 34,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 35,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 36,                   /* BIT_NOT  */
  YYSYMBOL_BIT_RSHIFT = 37,                /* BIT_RSHIFT  */
  YYSYMBOL_BIT_LSHIFT = 38,                /* BIT_LSHIFT  */
  YYSYMBOL_AUGBIT_AND = 39,                /* AUGBIT_AND  */
  YYSYMBOL_AUGBIT_OR = 40,                 /* AUGBIT_OR  */
  YYSYMBOL_AUGBIT_XOR = 41,                /* AUGBIT_XOR  */
  YYSYMBOL_AUGBIT_NOT = 42,                /* AUGBIT_NOT  */
  YYSYMBOL_AUGBIT_RSHIFT = 43,             /* AUGBIT_RSHIFT  */
  YYSYMBOL_AUGBIT_LSHIFT = 44,             /* AUGBIT_LSHIFT  */
  YYSYMBOL_LPAREN = 45,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 46,                    /* RPAREN  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 50,                 /* SEMICOLON  */
  YYSYMBOL_LLIST = 51,                     /* LLIST  */
  YYSYMBOL_RLIST = 52,                     /* RLIST  */
  YYSYMBOL_R_ARR = 53,                     /* R_ARR  */
  YYSYMBOL_EQ = 54,                        /* EQ  */
  YYSYMBOL_NEQ = 55,                       /* NEQ  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_GTE = 57,                       /* GTE  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_LTE = 59,                       /* LTE  */
  YYSYMBOL_HEX = 60,                       /* HEX  */
  YYSYMBOL_INT = 61,                       /* INT  */
  YYSYMBOL_AWAIT = 62,                     /* AWAIT  */
  YYSYMBOL_LEN = 63,                       /* LEN  */
  YYSYMBOL_AND = 64,                       /* AND  */
  YYSYMBOL_BREAK = 65,                     /* BREAK  */
  YYSYMBOL_DEF = 66,                       /* DEF  */
  YYSYMBOL_ELIF = 67,                      /* ELIF  */
  YYSYMBOL_ELSE = 68,                      /* ELSE  */
  YYSYMBOL_FOR = 69,                       /* FOR  */
  YYSYMBOL_IF = 70,                        /* IF  */
  YYSYMBOL_ENDMARKER = 71,                 /* ENDMARKER  */
  YYSYMBOL_RANGE = 72,                     /* RANGE  */
  YYSYMBOL_NOT = 73,                       /* NOT  */
  YYSYMBOL_OR = 74,                        /* OR  */
  YYSYMBOL_RETURN = 75,                    /* RETURN  */
  YYSYMBOL_WHILE = 76,                     /* WHILE  */
  YYSYMBOL_INDENT = 77,                    /* INDENT  */
  YYSYMBOL_DEDENT = 78,                    /* DEDENT  */
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
  YYSYMBOL_104_1 = 104,                    /* $@1  */
  YYSYMBOL_rarr_test_maybe = 105,          /* rarr_test_maybe  */
  YYSYMBOL_parameters = 106,               /* parameters  */
  YYSYMBOL_arguments = 107,                /* arguments  */
  YYSYMBOL_argument_a = 108,               /* argument_a  */
  YYSYMBOL_comm_arg_a = 109,               /* comm_arg_a  */
  YYSYMBOL_equals_test_maybe = 110,        /* equals_test_maybe  */
  YYSYMBOL_kwargs = 111,                   /* kwargs  */
  YYSYMBOL_comma_maybe = 112,              /* comma_maybe  */
  YYSYMBOL_args = 113,                     /* args  */
  YYSYMBOL_kwonly_kwargs = 114,            /* kwonly_kwargs  */
  YYSYMBOL_comma_kwargs_maybe = 115,       /* comma_kwargs_maybe  */
  YYSYMBOL_args_kwonly_kwargs = 116,       /* args_kwonly_kwargs  */
  YYSYMBOL_poskeyword_args_kwonly_kwargs = 117, /* poskeyword_args_kwonly_kwargs  */
  YYSYMBOL_comma_argskwonlykwargs = 118,   /* comma_argskwonlykwargs  */
  YYSYMBOL_typedargslist_no_posonly = 119, /* typedargslist_no_posonly  */
  YYSYMBOL_typedargslist = 120,            /* typedargslist  */
  YYSYMBOL_comma_typedargs_maybe = 121,    /* comma_typedargs_maybe  */
  YYSYMBOL_tfpdef = 122,                   /* tfpdef  */
  YYSYMBOL_colon_test_maybe = 123,         /* colon_test_maybe  */
  YYSYMBOL_stmt = 124,                     /* stmt  */
  YYSYMBOL_simple_stmt = 125,              /* simple_stmt  */
  YYSYMBOL_small_stmt1 = 126,              /* small_stmt1  */
  YYSYMBOL_small_stmt = 127,               /* small_stmt  */
  YYSYMBOL_type1 = 128,                    /* type1  */
  YYSYMBOL_type = 129,                     /* type  */
  YYSYMBOL_expr_stmt = 130,                /* expr_stmt  */
  YYSYMBOL_expr_list = 131,                /* expr_list  */
  YYSYMBOL_eq_test = 132,                  /* eq_test  */
  YYSYMBOL_annassign = 133,                /* annassign  */
  YYSYMBOL_annassign_a = 134,              /* annassign_a  */
  YYSYMBOL_testlist_star_expr = 135,       /* testlist_star_expr  */
  YYSYMBOL_test_star = 136,                /* test_star  */
  YYSYMBOL_comm_test_star = 137,           /* comm_test_star  */
  YYSYMBOL_augassign = 138,                /* augassign  */
  YYSYMBOL_flow_stmt = 139,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 140,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 141,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 142,              /* return_stmt  */
  YYSYMBOL_global_stmt = 143,              /* global_stmt  */
  YYSYMBOL_comm_name = 144,                /* comm_name  */
  YYSYMBOL_nonlocal_stmt = 145,            /* nonlocal_stmt  */
  YYSYMBOL_assert_stmt = 146,              /* assert_stmt  */
  YYSYMBOL_comma_test_maybe = 147,         /* comma_test_maybe  */
  YYSYMBOL_compound_stmt = 148,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 149,               /* async_stmt  */
  YYSYMBOL_if_stmt = 150,                  /* if_stmt  */
  YYSYMBOL_151_2 = 151,                    /* $@2  */
  YYSYMBOL_152_3 = 152,                    /* $@3  */
  YYSYMBOL_while_stmt = 153,               /* while_stmt  */
  YYSYMBOL_154_4 = 154,                    /* $@4  */
  YYSYMBOL_for_stmt = 155,                 /* for_stmt  */
  YYSYMBOL_156_5 = 156,                    /* $@5  */
  YYSYMBOL_else_colon_suite_maybe = 157,   /* else_colon_suite_maybe  */
  YYSYMBOL_elif_namedexprtest_colon_suite = 158, /* elif_namedexprtest_colon_suite  */
  YYSYMBOL_suite = 159,                    /* suite  */
  YYSYMBOL_stmt_morethanone = 160,         /* stmt_morethanone  */
  YYSYMBOL_test = 161,                     /* test  */
  YYSYMBOL_if_ortest_else_test_maybe = 162, /* if_ortest_else_test_maybe  */
  YYSYMBOL_or_test = 163,                  /* or_test  */
  YYSYMBOL_or_andtest = 164,               /* or_andtest  */
  YYSYMBOL_and_test = 165,                 /* and_test  */
  YYSYMBOL_and_nottest = 166,              /* and_nottest  */
  YYSYMBOL_not_test = 167,                 /* not_test  */
  YYSYMBOL_comparison = 168,               /* comparison  */
  YYSYMBOL_comp_op_expr = 169,             /* comp_op_expr  */
  YYSYMBOL_comp_op = 170,                  /* comp_op  */
  YYSYMBOL_star_expr = 171,                /* star_expr  */
  YYSYMBOL_expr = 172,                     /* expr  */
  YYSYMBOL_bitor_xorexpr = 173,            /* bitor_xorexpr  */
  YYSYMBOL_xor_expr = 174,                 /* xor_expr  */
  YYSYMBOL_bitxor_andexpr = 175,           /* bitxor_andexpr  */
  YYSYMBOL_and_expr = 176,                 /* and_expr  */
  YYSYMBOL_bitand_shiftexpr = 177,         /* bitand_shiftexpr  */
  YYSYMBOL_shift_expr = 178,               /* shift_expr  */
  YYSYMBOL_lorrshift_arithexpr = 179,      /* lorrshift_arithexpr  */
  YYSYMBOL_lshift_or_rshift = 180,         /* lshift_or_rshift  */
  YYSYMBOL_arith_expr = 181,               /* arith_expr  */
  YYSYMBOL_plusorminus_term = 182,         /* plusorminus_term  */
  YYSYMBOL_plus_or_minus = 183,            /* plus_or_minus  */
  YYSYMBOL_term = 184,                     /* term  */
  YYSYMBOL_timedivmod_factor = 185,        /* timedivmod_factor  */
  YYSYMBOL_timedivmod = 186,               /* timedivmod  */
  YYSYMBOL_factor = 187,                   /* factor  */
  YYSYMBOL_plusminusnot = 188,             /* plusminusnot  */
  YYSYMBOL_power = 189,                    /* power  */
  YYSYMBOL_pow_factor_maybe = 190,         /* pow_factor_maybe  */
  YYSYMBOL_atom_expr = 191,                /* atom_expr  */
  YYSYMBOL_atom = 192,                     /* atom  */
  YYSYMBOL_string_pl = 193,                /* string_pl  */
  YYSYMBOL_testlist_comp = 194,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_a = 195,          /* testlist_comp_a  */
  YYSYMBOL_comma_testorstar = 196,         /* comma_testorstar  */
  YYSYMBOL_test_or_starexpr = 197,         /* test_or_starexpr  */
  YYSYMBOL_trailer = 198,                  /* trailer  */
  YYSYMBOL_subscriptlist = 199,            /* subscriptlist  */
  YYSYMBOL_comma_subscript = 200,          /* comma_subscript  */
  YYSYMBOL_subscript = 201,                /* subscript  */
  YYSYMBOL_sliceop_maybe = 202,            /* sliceop_maybe  */
  YYSYMBOL_sliceop = 203,                  /* sliceop  */
  YYSYMBOL_exprlist = 204,                 /* exprlist  */
  YYSYMBOL_expr_str = 205,                 /* expr_str  */
  YYSYMBOL_comm_exstr = 206,               /* comm_exstr  */
  YYSYMBOL_testlist = 207,                 /* testlist  */
  YYSYMBOL_comm_test = 208,                /* comm_test  */
  YYSYMBOL_classdef = 209,                 /* classdef  */
  YYSYMBOL_210_6 = 210,                    /* $@6  */
  YYSYMBOL_211_7 = 211,                    /* $@7  */
  YYSYMBOL_l_arglist_r_maybe = 212,        /* l_arglist_r_maybe  */
  YYSYMBOL_arglist = 213,                  /* arglist  */
  YYSYMBOL_comm_arg = 214,                 /* comm_arg  */
  YYSYMBOL_argument = 215,                 /* argument  */
  YYSYMBOL_comp_iter = 216,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 217,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 218,                 /* comp_for  */
  YYSYMBOL_comp_if = 219,                  /* comp_if  */
  YYSYMBOL_func_body_suite = 220,          /* func_body_suite  */
  YYSYMBOL_func_type_input = 221,          /* func_type_input  */
  YYSYMBOL_nls = 222,                      /* nls  */
  YYSYMBOL_func_type = 223,                /* func_type  */
  YYSYMBOL_typelist = 224,                 /* typelist  */
  YYSYMBOL_comma_typel_maybe = 225,        /* comma_typel_maybe  */
  YYSYMBOL_type_l = 226,                   /* type_l  */
  YYSYMBOL_comma_pow_test_maybe = 227      /* comma_pow_test_maybe  */
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
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  286
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  412

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
       0,    91,    91,   138,   140,   141,   142,   143,   144,   145,
     148,   148,   445,   445,   446,   447,   455,   456,   456,   458,
     458,   459,   460,   460,   461,   463,   466,   467,   470,   471,
     472,   473,   474,   475,   476,   479,   481,   482,   483,   484,
     485,   486,   487,   490,   491,   503,   505,   508,   509,   510,
     511,   512,   513,   515,   516,   518,   520,   522,   523,   524,
     527,   528,   529,   530,   531,   532,   541,   542,   548,   802,
     803,   811,   821,   822,   823,   824,   842,   858,   859,   860,
     861,   862,   863,   864,   867,   868,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,   880,   880,   880,   881,
     882,   883,   899,   901,   902,   903,   904,   905,   906,   906,
     908,   908,   908,   908,   908,   908,   909,   910,   913,   913,
     913,   971,   971,   994,   994,  1084,  1084,  1086,  1087,  1090,
    1091,  1096,  1100,  1102,  1130,  1133,  1135,  1163,  1196,  1198,
    1229,  1262,  1265,  1265,  1266,  1295,  1331,  1335,  1336,  1337,
    1338,  1339,  1340,  1341,  1342,  1343,  1344,  1346,  1347,  1374,
    1408,  1409,  1436,  1470,  1471,  1500,  1534,  1535,  1565,  1604,
    1605,  1605,  1606,  1637,  1672,  1673,  1673,  1674,  1714,  1750,
    1751,  1751,  1751,  1751,  1752,  1753,  1758,  1758,  1758,  1759,
    1760,  1760,  1763,  1764,  2011,  2012,  2014,  2015,  2028,  2034,
    2035,  2042,  2044,  2046,  2050,  2051,  2058,  2059,  2066,  2067,
    2067,  2067,  2068,  2076,  2077,  2077,  2078,  2086,  2089,  2096,
    2103,  2113,  2121,  2122,  2124,  2125,  2127,  2128,  2128,  2130,
    2132,  2134,  2136,  2136,  2137,  2137,  2138,  2146,  2151,  2151,
    2152,  2159,  2160,  2168,  2169,  2174,  2182,  2187,  2182,  2287,
    2293,  2295,  2304,  2311,  2321,  2322,  2323,  2353,  2354,  2355,
    2357,  2357,  2358,  2361,  2364,  2366,  2367,  2369,  2375,  2375,
    2381,  2384,  2384,  2385,  2389,  2394,  2395,  2396,  2397,  2398,
    2399,  2399,  2400,  2401,  2402,  2403,  2403
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
  "STR_LIT", "BYT_LIT", "STR", "LIST", "FLOAT", "BOOL", "NONE", "EQUALS",
  "PLUS", "MINUS", "TIMES", "DIVIDEDBY", "NEWLINE", "MOD", "MODULO",
  "AUGPLUS", "AUGMINUS", "AUGTIMES", "AUGDIVIDEDBY", "AUGMOD", "AUGMODULO",
  "POW", "AUGPOW", "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NOT", "BIT_RSHIFT",
  "BIT_LSHIFT", "AUGBIT_AND", "AUGBIT_OR", "AUGBIT_XOR", "AUGBIT_NOT",
  "AUGBIT_RSHIFT", "AUGBIT_LSHIFT", "LPAREN", "RPAREN", "COMMA", "DOT",
  "COLON", "SEMICOLON", "LLIST", "RLIST", "R_ARR", "EQ", "NEQ", "GT",
  "GTE", "LT", "LTE", "HEX", "INT", "AWAIT", "LEN", "AND", "BREAK", "DEF",
  "ELIF", "ELSE", "FOR", "IF", "ENDMARKER", "RANGE", "NOT", "OR", "RETURN",
  "WHILE", "INDENT", "DEDENT", "IS", "IN", "CONTINUE", "ASSERT",
  "NONLOCAL", "GLOBAL", "CLASS", "ASYNC", "IMPORT", "PASS", "EXCEPT",
  "RAISE", "FINALLY", "LAMBDA", "TRY", "AS", "FROM", "DEL", "WITH",
  "YIELD", "$accept", "file", "single_inputs", "single_input", "funcdef",
  "$@1", "rarr_test_maybe", "parameters", "arguments", "argument_a",
  "comm_arg_a", "equals_test_maybe", "kwargs", "comma_maybe", "args",
  "kwonly_kwargs", "comma_kwargs_maybe", "args_kwonly_kwargs",
  "poskeyword_args_kwonly_kwargs", "comma_argskwonlykwargs",
  "typedargslist_no_posonly", "typedargslist", "comma_typedargs_maybe",
  "tfpdef", "colon_test_maybe", "stmt", "simple_stmt", "small_stmt1",
  "small_stmt", "type1", "type", "expr_stmt", "expr_list", "eq_test",
  "annassign", "annassign_a", "testlist_star_expr", "test_star",
  "comm_test_star", "augassign", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "global_stmt", "comm_name",
  "nonlocal_stmt", "assert_stmt", "comma_test_maybe", "compound_stmt",
  "async_stmt", "if_stmt", "$@2", "$@3", "while_stmt", "$@4", "for_stmt",
  "$@5", "else_colon_suite_maybe", "elif_namedexprtest_colon_suite",
  "suite", "stmt_morethanone", "test", "if_ortest_else_test_maybe",
  "or_test", "or_andtest", "and_test", "and_nottest", "not_test",
  "comparison", "comp_op_expr", "comp_op", "star_expr", "expr",
  "bitor_xorexpr", "xor_expr", "bitxor_andexpr", "and_expr",
  "bitand_shiftexpr", "shift_expr", "lorrshift_arithexpr",
  "lshift_or_rshift", "arith_expr", "plusorminus_term", "plus_or_minus",
  "term", "timedivmod_factor", "timedivmod", "factor", "plusminusnot",
  "power", "pow_factor_maybe", "atom_expr", "atom", "string_pl",
  "testlist_comp", "testlist_comp_a", "comma_testorstar",
  "test_or_starexpr", "trailer", "subscriptlist", "comma_subscript",
  "subscript", "sliceop_maybe", "sliceop", "exprlist", "expr_str",
  "comm_exstr", "testlist", "comm_test", "classdef", "$@6", "$@7",
  "l_arglist_r_maybe", "arglist", "comm_arg", "argument", "comp_iter",
  "sync_comp_for", "comp_for", "comp_if", "func_body_suite",
  "func_type_input", "nls", "func_type", "typelist", "comma_typel_maybe",
  "type_l", "comma_pow_test_maybe", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-158)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     287,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    1218,  -371,  -371,   873,  1011,    39,    -9,  -371,    38,  -371,
    -371,  1149,  1011,  -371,  -371,  1149,    40,    61,    97,     8,
      70,   371,  -371,  -371,  -371,  -371,  -371,   209,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,    86,  -371,  -371,  -371,
    -371,  -371,    43,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  1218,  -371,    89,    79,   118,  -371,
    -371,  -371,  1011,  -371,  1149,  1149,    85,   -46,   -46,    90,
      99,   -46,    80,    79,  1011,   104,  1168,  1149,  -371,  -371,
    1149,   113,  -371,  -371,  -371,  -371,  -371,  -371,  -371,     7,
    1011,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,    12,  -371,  -371,  1149,   117,  -371,  1149,
    -371,    92,   101,    37,   134,   135,   138,    81,   107,   127,
    -371,  1218,  -371,   892,   166,  1030,  -371,  -371,    -2,  -371,
      20,   126,  -371,  1149,  1168,   106,  -371,   129,   130,  -371,
    -371,  -371,  -371,   125,  -371,  -371,   133,    34,   131,  -371,
    -371,   100,  -371,  -371,   137,  1149,  -371,   141,   141,   140,
    -371,   707,  -371,  -371,  -371,   142,  -371,  -371,  -371,  -371,
    -371,   172,  -371,  -371,  1011,   123,  1149,  1149,  -371,  -371,
    -371,  -371,  -371,  -371,   112,   121,  -371,  1218,  1218,  1218,
    1218,  -371,  -371,  1218,  -371,  -371,  1218,  -371,  -371,  -371,
    -371,  1218,  -371,  1149,  1149,  -371,     2,   149,  -371,   151,
    1080,   148,   152,  -371,  -371,  -371,   126,  1099,  -371,  -371,
     120,  -371,  1011,   136,  -371,  1149,  -371,   154,   202,   202,
     159,  -371,  -371,  -371,  -371,  -371,  -371,   161,   193,    12,
    -371,   139,   165,   164,   741,  -371,   211,   961,  -371,  -371,
    -371,   199,    36,  1011,  -371,   170,  -371,  1149,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  1149,  -371,  -371,   171,   942,  1149,   173,  -371,  -371,
    1080,  -371,   177,  -371,  1149,  -371,  1149,  -371,  -371,  -371,
    1149,  1149,  -371,  -371,    12,  -371,  -371,   178,    91,  -371,
     182,   183,  -371,  -371,  1149,  -371,  -371,   184,   174,  1168,
     741,   155,  -371,   163,  -371,   194,   195,  1011,   190,  -371,
    1149,  -371,  -371,   961,  -371,   197,  -371,  -371,   173,  -371,
    1030,  -371,    29,  -371,   126,  -371,  -371,  -371,  -371,   200,
    -371,   202,    27,  -371,  -371,   791,  1149,  -371,  -371,   623,
     205,  -371,  -371,   741,  -371,  -371,  -371,  -371,  -371,  -371,
    1149,  -371,  -371,  -371,   126,  -371,    34,  -371,  -371,  -371,
     179,  -371,  -371,   213,    67,  -371,  -371,  -371,   455,   741,
    -371,    29,  -371,   204,  -371,   623,   212,  1149,  -371,  -371,
    -371,  -371,  -371,    83,   539,   741,   214,  -371,   163,   741,
    -371,  -371
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   197,   200,   198,   202,   203,   205,   201,   186,   187,
       0,     6,   188,     0,   206,     0,     0,    99,     0,   123,
     118,     0,   102,   121,   100,     0,     0,     0,     0,     0,
       0,     2,     5,   113,     7,    54,    55,    72,    83,    56,
      96,    97,    98,    57,    58,    59,     8,   115,   110,   111,
     112,    80,   135,   138,   141,   143,    81,   146,   160,   163,
     166,   169,   174,   179,     0,   185,   191,   222,   199,   114,
       3,   272,   206,   157,   245,     0,     0,   213,   213,     0,
       0,   213,     0,   222,   206,     0,     0,     0,   142,   101,
       0,   109,   105,   105,   246,   116,   117,     1,     4,    52,
       0,    84,    85,    86,    87,    95,    88,    94,    89,    90,
      91,    92,    93,     0,    68,    69,     0,    79,     9,     0,
     133,   136,   139,   144,   158,   161,   164,   167,   172,   177,
     184,     0,   189,     0,     0,     0,   193,   204,     0,   245,
     146,   286,   278,     0,     0,     0,   207,   211,   281,   265,
     209,   208,   194,     0,   196,   192,     0,    38,    13,   239,
     238,     0,   241,   119,     0,     0,   107,   106,   103,   250,
      50,    51,    74,    65,    62,     0,    61,    63,    64,    60,
      66,    77,   245,    70,    78,     0,     0,     0,   149,   152,
     148,   150,   147,   151,     0,   155,   153,     0,     0,     0,
       0,   171,   170,     0,   175,   176,     0,   180,   181,   183,
     182,     0,   190,     0,     0,   217,   256,     0,   254,   219,
     233,   227,     0,   226,   271,   270,   286,     0,   277,   274,
       0,   264,   210,   280,   275,     0,   195,    46,    25,     0,
      33,    18,    31,    18,    37,    36,    40,     0,    20,     0,
      10,     0,   237,     0,     0,   108,     0,     0,   247,    49,
      53,    71,     0,     0,    75,   243,    82,     0,   137,   140,
     154,   156,   145,   159,   162,   165,   168,   173,   178,   259,
     258,     0,   255,   216,   252,     0,   235,   233,   231,   232,
     233,   218,   224,   276,     0,   244,     0,   214,   215,   212,
     245,     0,   279,   273,     0,    44,    24,    23,    35,    32,
      15,    29,    30,    14,     0,    16,    12,     0,     0,   236,
       0,     0,   129,   126,   104,     0,     0,     0,     0,    76,
     242,   134,   257,   251,   221,     0,   234,   230,   233,   229,
     223,   285,   263,   245,   286,   284,    45,    22,    21,    41,
      34,     0,    28,    26,    19,     0,     0,   240,   128,     0,
       0,   122,   249,     0,    73,    67,   253,   220,   228,   225,
       0,   262,   260,   261,   286,   283,    43,    39,    17,    27,
       0,   268,    11,     0,   126,   132,    47,    48,     0,     0,
     248,   267,   282,    33,    42,     0,     0,     0,   120,   130,
     131,   125,   266,    35,     0,     0,     0,   269,   126,     0,
     124,   127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,  -371,   229,   233,  -371,  -371,  -371,  -112,  -194,
      23,  -371,   -87,  -371,  -371,  -371,  -371,  -296,  -371,  -371,
    -109,  -371,  -371,   -76,  -371,  -370,     0,  -371,   105,     6,
    -228,  -371,  -371,  -371,  -371,  -371,   -17,    87,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,   186,  -371,  -371,  -371,    22,
    -371,  -371,  -371,  -371,  -371,  -371,   243,  -371,  -352,  -371,
    -304,  -120,   -12,  -371,  -113,  -371,    94,  -371,   -13,  -371,
    -371,  -371,    -4,    -7,  -371,    88,  -371,    78,  -371,    84,
    -371,  -371,    82,  -371,  -371,    75,  -371,  -371,   -50,  -371,
    -371,  -371,  -371,   268,  -371,     3,   218,  -371,  -371,   208,
    -371,  -371,   -53,  -252,  -371,   156,   -21,  -371,   -57,   -73,
    -371,  -371,  -371,  -371,  -224,  -371,   -32,   -83,   168,  -209,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -215
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    30,    31,    32,    33,   317,   250,   158,   240,   241,
     310,   315,   242,   348,   243,   312,   353,   244,   245,   309,
     246,   247,   377,   248,   305,   385,   322,    99,    35,   180,
     181,    36,   114,   261,   115,   264,    37,    38,   117,   116,
      39,    40,    41,    42,    43,   167,    44,    45,   166,   387,
      47,    48,    87,   253,    49,    90,    50,    86,   361,   384,
     323,   388,    51,   120,    52,   121,    53,   122,    54,    55,
     123,   197,    56,    57,   124,    58,   125,    59,   126,    60,
     127,   203,    61,   128,   206,    62,   129,   211,    63,    64,
      65,   132,    66,    67,    68,    79,   146,   147,   299,   136,
     222,   292,   223,   288,   289,   161,   162,   252,   183,   141,
      69,   169,   326,   258,   217,   284,   218,   371,   149,   150,
     373,   382,    70,   138,    71,    80,   234,   302,   228
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    77,    81,    73,   148,    89,   185,   282,    88,    78,
      78,   293,   350,    91,   130,   173,   358,    82,   400,   281,
     224,   316,    46,   144,   174,   175,   176,   177,   178,   170,
     237,    34,   398,   325,   400,   337,    84,   237,   339,   173,
     145,    85,     1,    92,     2,     3,     4,     5,   174,     6,
     176,   177,   178,    46,   238,     7,   410,   171,   239,   390,
      81,   335,   139,   142,    93,   239,   226,   140,    78,   225,
      97,   144,    81,   179,    18,   163,   346,    19,   164,   160,
      78,   212,   159,   172,    72,   401,   368,   156,   145,  -157,
      14,   188,   189,   190,   191,   192,   193,   179,   144,   370,
      94,   408,    16,   238,   182,   411,  -157,   350,   118,   265,
     194,   238,   349,   119,   239,   145,   195,   196,   201,   202,
     131,   216,   239,   221,   133,   204,   205,   134,   137,   375,
     135,   229,   154,   372,   397,   360,   152,   160,   143,     1,
     159,     2,     3,     4,     5,   153,     6,   207,   208,   157,
     209,   210,     7,   255,     8,     9,   300,   378,   378,   392,
     165,   278,   306,   307,   184,   187,   186,   301,   198,   219,
     199,   200,    12,   227,   269,   144,   232,   233,   235,   236,
     251,    72,   372,   342,   249,   257,   254,    14,   256,   263,
     272,   267,   270,   262,   271,   283,   285,   290,    15,    16,
     296,   279,   280,   304,   291,   237,   308,   313,   287,    21,
     314,   318,   319,   320,   324,   295,   327,   330,   333,   356,
     297,   295,   286,   303,   340,   347,   100,   344,   298,   351,
     352,   360,   359,   355,   101,   102,   103,   104,   105,   106,
     362,   107,   365,   367,   363,   216,   329,   376,   108,   109,
     110,   403,   111,   112,   389,   331,   395,   391,   113,   396,
      98,   405,    95,   409,   393,   379,   311,   394,   328,   332,
     374,   266,    96,   216,   336,   404,   260,   274,   338,   168,
     268,   277,   341,    83,   275,   276,   273,   369,   343,   345,
       1,   155,     2,     3,     4,     5,   151,     6,   357,   383,
     230,   366,   354,     7,     0,     8,     9,    10,   402,    11,
     364,     0,   160,   231,     0,   159,     0,     0,   295,     0,
       0,   216,     0,    12,     0,     0,     0,     0,   221,     0,
       0,     0,    13,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,   182,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,   381,    19,    20,     0,   386,
      21,     0,    22,    23,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     1,     0,     2,     3,     4,     5,
       0,     6,     0,     0,     0,   406,     0,     7,   386,     8,
       9,    10,     0,    11,     0,   386,     0,     0,     0,     0,
       0,     0,     0,     0,   386,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,    18,     0,     0,
      19,    20,     0,     0,    21,     0,    22,    23,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,     1,     0,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     7,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      17,    18,     0,     0,    19,    20,     0,     0,    21,     0,
      22,    23,     0,   399,     0,     0,    24,    25,    26,    27,
      28,    29,     1,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     7,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,     0,    19,    20,
       0,     0,    21,     0,    22,    23,     0,   407,     0,     0,
      24,    25,    26,    27,    28,    29,     1,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     7,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,    17,    18,
       0,     0,    19,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
       1,     0,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     7,     0,     8,     9,    10,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     1,     0,     2,     3,     4,     5,
       0,     6,    72,     0,     0,     0,     0,     7,    14,     8,
       9,    10,     0,   321,     0,     0,     0,     0,     0,    15,
      16,     0,    17,     0,     0,     0,     0,    12,     0,     0,
      21,     0,    22,     0,     0,     0,    72,     0,    24,    25,
      26,    27,    14,     0,     1,     0,     2,     3,     4,     5,
       0,     6,     0,    15,    16,     0,    17,     7,     0,     8,
       9,    10,     0,   380,    21,     0,    22,     0,     0,     0,
       0,     0,    24,    25,    26,    27,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    22,     0,     0,     0,
       0,     0,    24,    25,    26,    27,     1,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     7,
       0,     8,     9,    74,     0,     1,     0,     2,     3,     4,
       5,     0,     6,     0,    75,     0,     0,     0,     7,    12,
       8,     9,   213,     0,     0,     0,     0,     0,    72,    76,
       0,     0,     0,   214,    14,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,    15,    16,    72,   215,     0,
       0,     0,     0,    14,     0,     1,    21,     2,     3,     4,
       5,     0,     6,     0,    15,    16,     0,     0,     7,     0,
       8,     9,   213,     0,     1,    21,     2,     3,     4,     5,
       0,     6,     0,   214,     0,     0,     0,     7,    12,     8,
       9,   213,     0,     0,     0,     0,     0,    72,   334,     0,
       0,     0,   214,    14,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,    15,    16,    72,     0,     0,     0,
       0,     0,    14,     0,     1,    21,     2,     3,     4,     5,
       0,     6,     0,    15,    16,     0,     0,     7,     0,     8,
       9,    10,     0,     1,    21,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     7,    12,     8,     9,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,    14,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,    15,    16,    72,     0,     0,     0,   220,
       0,    14,     0,     1,    21,     2,     3,     4,     5,     0,
       6,     0,    15,    16,     0,     0,     7,     0,     8,     9,
       0,     0,     1,    21,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     7,    12,     8,     9,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,   286,
     294,    14,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,    15,    16,    72,     0,     0,     0,     0,     0,
      14,     0,     1,    21,     2,     3,     4,     5,     0,     6,
       0,    15,    16,     0,     0,     7,     0,     8,     9,     0,
       0,     1,    21,     2,     3,     4,     5,     0,     6,     0,
       0,     0,     0,     0,     7,    12,     8,     9,    10,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
      14,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,    15,    16,    72,     0,     0,     0,     0,     0,    14,
       0,     1,    21,     2,     3,     4,     5,     0,     6,     0,
      15,    16,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16
};

static const yytype_int16 yycheck[] =
{
       0,    13,    14,    10,    77,    22,   119,   216,    21,    13,
      14,   226,   308,    25,    64,     3,   320,    14,   388,    17,
      22,   249,     0,    69,    12,    13,    14,    15,    16,    22,
       3,    31,   384,   257,   404,   287,    45,     3,   290,     3,
      86,     3,     3,     3,     5,     6,     7,     8,    12,    10,
      14,    15,    16,    31,    20,    16,   408,    50,    31,   363,
      72,   285,    74,    75,     3,    31,   139,    74,    72,    71,
       0,    69,    84,    61,    66,    87,   304,    69,    90,    86,
      84,   131,    86,   100,    45,   389,   338,    84,    86,    69,
      51,    54,    55,    56,    57,    58,    59,    61,    69,    70,
       3,   405,    63,    20,   116,   409,    86,   403,    22,   182,
      73,    20,    21,    70,    31,    86,    79,    80,    37,    38,
      31,   133,    31,   135,    45,    18,    19,    48,    10,   344,
      51,   143,    52,   342,    67,    68,    46,   144,    53,     3,
     144,     5,     6,     7,     8,    46,    10,    20,    21,    45,
      23,    24,    16,   165,    18,    19,    20,   351,   352,   374,
      47,   211,   238,   239,    47,    64,    74,    31,    34,     3,
      35,    33,    36,    47,   187,    69,    47,    47,    53,    46,
      80,    45,   391,   296,    53,    45,    49,    51,    47,    17,
     197,    68,    80,    51,    73,    46,    45,    49,    62,    63,
      80,   213,   214,    49,    52,     3,    47,    46,   220,    73,
      17,    72,    47,    49,     3,   227,    17,    47,    47,    45,
     232,   233,    49,   235,    47,    47,    17,   300,   232,    47,
      47,    68,    77,    49,    25,    26,    27,    28,    29,    30,
      46,    32,    52,    46,    49,   257,   263,    47,    39,    40,
      41,    47,    43,    44,    49,   267,    77,   370,    49,    46,
      31,    49,    29,    49,   376,   352,   243,   376,   262,   281,
     343,   184,    29,   285,   286,   395,   171,   199,   290,    93,
     186,   206,   294,    15,   200,   203,   198,   340,   300,   301,
       3,    83,     5,     6,     7,     8,    78,    10,   319,   356,
     144,   333,   314,    16,    -1,    18,    19,    20,   391,    22,
     327,    -1,   319,   145,    -1,   319,    -1,    -1,   330,    -1,
      -1,   333,    -1,    36,    -1,    -1,    -1,    -1,   340,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,   356,    -1,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,    -1,   355,    69,    70,    -1,   359,
      73,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,     3,    -1,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,   397,    -1,    16,   388,    18,
      19,    20,    -1,    22,    -1,   395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   404,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      69,    70,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,     3,    -1,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    -1,    69,    70,    -1,    -1,    73,    -1,
      75,    76,    -1,    78,    -1,    -1,    81,    82,    83,    84,
      85,    86,     3,    -1,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    73,    -1,    75,    76,    -1,    78,    -1,    -1,
      81,    82,    83,    84,    85,    86,     3,    -1,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    70,    -1,    -1,    73,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
       3,    -1,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,     3,    -1,     5,     6,     7,     8,
      -1,    10,    45,    -1,    -1,    -1,    -1,    16,    51,    18,
      19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      73,    -1,    75,    -1,    -1,    -1,    45,    -1,    81,    82,
      83,    84,    51,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    10,    -1,    62,    63,    -1,    65,    16,    -1,    18,
      19,    20,    -1,    22,    73,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,     3,    -1,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    -1,     3,    -1,     5,     6,     7,
       8,    -1,    10,    -1,    31,    -1,    -1,    -1,    16,    36,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    31,    51,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    45,    46,    -1,
      -1,    -1,    -1,    51,    -1,     3,    73,     5,     6,     7,
       8,    -1,    10,    -1,    62,    63,    -1,    -1,    16,    -1,
      18,    19,    20,    -1,     3,    73,     5,     6,     7,     8,
      -1,    10,    -1,    31,    -1,    -1,    -1,    16,    36,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    31,    51,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,     3,    73,     5,     6,     7,     8,
      -1,    10,    -1,    62,    63,    -1,    -1,    16,    -1,    18,
      19,    20,    -1,     3,    73,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    16,    36,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    45,    -1,    -1,    -1,    49,
      -1,    51,    -1,     3,    73,     5,     6,     7,     8,    -1,
      10,    -1,    62,    63,    -1,    -1,    16,    -1,    18,    19,
      -1,    -1,     3,    73,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    16,    36,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      31,    51,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,     3,    73,     5,     6,     7,     8,    -1,    10,
      -1,    62,    63,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,     3,    73,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    16,    36,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,     3,    73,     5,     6,     7,     8,    -1,    10,    -1,
      62,    63,    -1,    -1,    16,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    10,    16,    18,    19,
      20,    22,    36,    45,    51,    62,    63,    65,    66,    69,
      70,    73,    75,    76,    81,    82,    83,    84,    85,    86,
     100,   101,   102,   103,   125,   127,   130,   135,   136,   139,
     140,   141,   142,   143,   145,   146,   148,   149,   150,   153,
     155,   161,   163,   165,   167,   168,   171,   172,   174,   176,
     178,   181,   184,   187,   188,   189,   191,   192,   193,   209,
     221,   223,    45,   172,    20,    31,    46,   161,   171,   194,
     224,   161,   194,   192,    45,     3,   156,   151,   167,   135,
     154,   161,     3,     3,     3,   103,   155,     0,   102,   126,
      17,    25,    26,    27,    28,    29,    30,    32,    39,    40,
      41,    43,    44,    49,   131,   133,   138,   137,    22,    70,
     162,   164,   166,   169,   173,   175,   177,   179,   182,   185,
     187,    31,   190,    45,    48,    51,   198,    10,   222,   161,
     172,   208,   161,    53,    69,    86,   195,   196,   208,   217,
     218,   195,    46,    46,    52,   198,   194,    45,   106,   171,
     172,   204,   205,   161,   161,    47,   147,   144,   144,   210,
      22,    50,   135,     3,    12,    13,    14,    15,    16,    61,
     128,   129,   161,   207,    47,   163,    74,    64,    54,    55,
      56,    57,    58,    59,    73,    79,    80,   170,    34,    35,
      33,    37,    38,   180,    18,    19,   183,    20,    21,    23,
      24,   186,   187,    20,    31,    46,   161,   213,   215,     3,
      49,   161,   199,   201,    22,    71,   208,    47,   227,   161,
     204,   217,    47,    47,   225,    53,    46,     3,    20,    31,
     107,   108,   111,   113,   116,   117,   119,   120,   122,    53,
     105,    80,   206,   152,    49,   161,    47,    45,   212,    22,
     127,   132,    51,    17,   134,   208,   136,    68,   165,   167,
      80,    73,   172,   174,   176,   178,   181,   184,   187,   161,
     161,    17,   218,    46,   214,    45,    49,   161,   202,   203,
      49,    52,   200,   227,    31,   161,    80,   161,   171,   197,
      20,    31,   226,   161,    49,   123,   122,   122,    47,   118,
     109,   109,   114,    46,    17,   110,   129,   104,    72,    47,
      49,    22,   125,   159,     3,   213,   211,    17,   128,   135,
      47,   161,   161,    47,    46,   213,   161,   202,   161,   202,
      47,   161,   163,   161,   208,   161,   129,    47,   112,    21,
     116,    47,    47,   115,   161,    49,    45,   205,   159,    77,
      68,   157,    46,    49,   135,    52,   215,    46,   202,   201,
      70,   216,   218,   219,   208,   227,    47,   121,   108,   111,
      22,   125,   220,   207,   158,   124,   125,   148,   160,    49,
     159,   163,   227,   107,   119,    77,    46,    67,   157,    78,
     124,   159,   216,    47,   160,    49,   161,    78,   159,    49,
     157,   159
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     104,   103,   105,   105,   106,   107,   108,   109,   109,   110,
     110,   111,   112,   112,   113,   113,   114,   115,   115,   115,
     116,   116,   117,   118,   118,   118,   119,   119,   120,   120,
     120,   121,   121,   121,   122,   123,   123,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   128,   128,   129,   129,   130,   131,
     131,   131,   131,   132,   132,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   140,
     141,   142,   142,   143,   144,   144,   145,   146,   147,   147,
     148,   148,   148,   148,   148,   148,   149,   149,   151,   152,
     150,   154,   153,   156,   155,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   162,   162,   163,   164,   164,   165,
     166,   166,   167,   167,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   172,   173,
     173,   174,   175,   175,   176,   177,   177,   178,   179,   179,
     180,   180,   181,   182,   182,   183,   183,   184,   185,   185,
     186,   186,   186,   186,   187,   187,   188,   188,   188,   189,
     190,   190,   191,   191,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   193,   193,   194,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   200,   200,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   210,   211,   209,   212,
     212,   213,   213,   214,   214,   215,   215,   215,   215,   215,
     216,   216,   217,   217,   218,   218,   219,   219,   220,   220,
     221,   222,   222,   223,   223,   224,   224,   224,   224,   225,
     225,   225,   226,   226,   226,   227,   227
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       0,     7,     2,     0,     3,     2,     2,     3,     0,     2,
       0,     3,     1,     0,     2,     1,     2,     2,     1,     0,
       2,     1,     2,     0,     2,     1,     1,     1,     0,     4,
       1,     0,     2,     1,     2,     2,     0,     1,     1,     4,
       3,     3,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     1,
       2,     3,     0,     3,     0,     3,     2,     0,     3,     2,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     3,     0,     3,     3,     2,     0,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     0,
       8,     0,     6,     0,    11,     3,     0,     5,     0,     1,
       4,     2,     1,     2,     4,     0,     2,     3,     0,     2,
       3,     0,     2,     1,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     2,     3,
       0,     2,     3,     0,     2,     3,     0,     2,     3,     0,
       1,     1,     2,     3,     0,     1,     1,     2,     3,     0,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     0,     3,     2,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     2,     2,     1,
       2,     1,     3,     0,     1,     1,     3,     2,     3,     2,
       5,     4,     0,     3,     2,     3,     0,     1,     4,     3,
       3,     2,     1,     0,     2,     1,     3,     2,     1,     1,
       3,     0,     3,     2,     3,     0,     0,     0,     7,     3,
       0,     3,     2,     3,     0,     2,     1,     3,     2,     2,
       1,     1,     5,     4,     2,     1,     3,     2,     1,     4,
       3,     2,     0,     5,     4,     3,     4,     3,     2,     2,
       1,     0,     4,     3,     2,     3,     0
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
#line 91 "parser.y"
                   {Node * temp=createNode("EOF","<EOF>",{}); 
                    root =createNode("file","",{(yyvsp[0].node),temp});
                    orig->make_csv_wrapper();(yyval.node)=root;
                    // for(auto qq:ircode) cout<<"done done "<<qq->code; 
                    (yyval.node)->code = (yyvsp[0].node)->code;
                    ofstream tac_file("tac3.txt");
                    int linenum=1;
                    set<int> targets;
                    for(auto tx: (yyval.node)->code){
                        size_t found=tx->code.find("goto");
                        tx-> ins_line = linenum;
                        string final;
                        if(found!=string::npos){
                            final=tx->code.substr(0,(int)found+4);
                            int fin=linenum;
                            string n="";
                            int ch=1;
                            for(int i=found+5;i<tx->code.size();i++){
                                if(tx->code[i]=='-') ch=-1;
                                if(tx->code[i]>='0' and tx->code[i]<='9') n+=tx->code[i];
                            }
                            fin+=ch*stoi(n);
                            final+=(" "+to_string(fin)+"\n");
                            // tx->code=final;
                            // op="goto";
                            // arg1="j+"+to_string();
                            // quad* q1=new quad("",arg1,op,"");
                            // q1->make_code_from_goto();
                            tx->abs_jump = fin;
                            targets.insert(fin);

                        }
                        else
                         final=tx->code;
                        tac_file<<linenum<<":"<<final;
                        linenum++;
                    }
                    int linum=1;
                    for(auto tx: (yyval.node)->code){
                        if(targets.find(linum)!= targets.end()) tx->is_target = true;
                        linum++;
                    }
                    tac_file.close();
                    gen->gen_global();
                    gen->gen_text();
                    gen->print_code(output_file);
                    }
#line 2252 "parser.tab.c"
    break;

  case 3: /* file: func_type_input  */
#line 138 "parser.y"
                      {Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{(yyvsp[0].node),temp});}
#line 2258 "parser.tab.c"
    break;

  case 4: /* single_inputs: single_inputs single_input  */
#line 140 "parser.y"
                                           { (yyval.node)=(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); (yyval.node)->code = (yyvsp[-1].node)->code; (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());}
#line 2264 "parser.tab.c"
    break;

  case 5: /* single_inputs: single_input  */
#line 141 "parser.y"
                             {(yyval.node)=createNode("single_inputs","",{(yyvsp[0].node)}); (yyval.node)->code = (yyvsp[0].node)->code;}
#line 2270 "parser.tab.c"
    break;

  case 6: /* single_input: NEWLINE  */
#line 142 "parser.y"
                      {(yyval.node)=createNode("Newline","nl",{});}
#line 2276 "parser.tab.c"
    break;

  case 7: /* single_input: simple_stmt  */
#line 143 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2282 "parser.tab.c"
    break;

  case 8: /* single_input: compound_stmt  */
#line 144 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2288 "parser.tab.c"
    break;

  case 9: /* single_input: compound_stmt NEWLINE  */
#line 145 "parser.y"
                                   {Node *n1=createNode("Newline","nl",{}); (yyval.node)=createNode("single_input","",{(yyvsp[-1].node),n1});}
#line 2294 "parser.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 148 "parser.y"
                                                   {
    // cout<<"def\n";
    symbol_table_func* funcd=new symbol_table_func(*(yyvsp[-2].str),(yyvsp[-1].node)->Sym_list,(yyvsp[0].node)->type);
    if(curr->st_category!='C') ogroot->add_entry(funcd);
    else {
        symbol_table_class* cls=(symbol_table_class *)curr;
        cls->add_func(funcd);
    }                                                                                                                                                                                                      
    curr->add_scope(funcd);
    Symbol* fn=new Symbol(*(yyvsp[-2].str),(yyvsp[0].node)->type,yylineno); 
    fn->is_func=true;curr->add_entry(fn);curr=funcd;
    }
#line 2311 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF IDENTIFIER parameters rarr_test_maybe $@1 COLON func_body_suite  */
#line 159 "parser.y"
                            {
        // cout<<"abort0\n";
        // symbol_table_func* funcf=(symbol_table_func *)curr;
        Node* n2= createNode("Keyword","def",{});
        Node* n3= createNode("Identifier",*(yyvsp[-5].str),{});
        Node* n4= createNode("Delimiter",":",{});
        (yyval.node)=createNode("Func","",{n2,n3,(yyvsp[-4].node),(yyvsp[-3].node),n4,(yyvsp[0].node)});
        curr=curr->parent;
        
        string arg1=*(yyvsp[-5].str);
        string argg1 = arg1;
        if (curr->st_category=='C'){
            argg1=curr->name+"."+arg1;
        }
        quad* q = new quad("", argg1, "", "");
        q->make_code_begin_func();
        (yyval.node)->code.push_back(q);
        // funcf->codes.push_back(q);
        // cout<<"abort\n";
        if(curr->st_category == 'C' && arg1!="__init__"){
            // cout<<"notinit"<<endl;
            quad* q2 = new quad("self", "", "", "");
            q2->make_code_pop_param();
            (yyval.node)->code.push_back(q2);
            // funcf->codes.push_back(q2);
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q3 = new quad(tar, "self", "", "");
            q3->make_code_from_assignment();
            (yyval.node)->code.push_back(q3);
            // funcf->codes.push_back(q3);
            vector<quad*> temp;
            int ctr=0;
            for(auto cd:(yyvsp[0].node)->code){
                if(cd->made_from==quad::ASSIGNMENT){
                    if(cd->self_res == true && cd->self_arg1 == false){
                        string tar1=tar;
                        if(ctr==0){
                            // tar1=tar;
                        }
                        // string tar=cd->result
                        else{
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                            q5->make_code_from_binary();
                            // temp.push_back(q5);
                            // tar1=tar2;
                        }
                        // cout<<"done"<<endl;
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->result){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        if(found){
                        // cout<<"done2"<<endl;
                            if(offset) arg2=to_string(8*offset);
                            // cout<<arg2<<endl;
                            quad* qn=new quad(tar1,a1,"",arg2);
                            qn->make_code_from_store();
                            temp.push_back(qn);
                            // cout<<qn->code<<endl;
                            ctr++;
                        }
                    // cout<<"done3"<<endl;
                    }
                    else if(cd->self_arg1 == true && cd->self_res == false){
                        string tar1=tar;
                        // if(ctr==0){
                        //     // tar1=tar;
                        // }
                        // // string tar=cd->result
                        // else{
                        //     string tar2=string("_t")+to_string(temp_cnt);
                        //     // temp_cnt++;
                        //     quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                        //     q5->make_code_from_binary();
                        //     // temp.push_back(q5);
                        //     // tar1=tar2;
                        // }
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->arg1){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        // cout<<cd->arg1<<" "<<cd->arg2<<" "<<cd->result<<endl;
                        if(found){
                            if(offset) arg2=to_string(8*offset);
                            // cout<<arg2<<endl;
                            quad* qn=new quad(cd->result,tar1,"",arg2);
                            qn->make_code_from_load();
                            // cout<<qn->code<<endl;
                            temp.push_back(qn);
                            ctr++;
                        }
                    }
                    else if(cd->self_arg1 == true && cd->self_res == true){
                        string tar1;
                        if(ctr==0){
                            tar1=tar;
                        }
                        // string tar=cd->result
                        else{
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                            q5->make_code_from_binary();
                            temp.push_back(q5);
                            tar1=tar2;
                        }
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset1=0;
                        bool found1=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->result){
                                found1=true;
                                break;
                            }
                            offset1++;
                        }
                        int offset2=0;
                        bool found2=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->arg1){
                                found2=true;
                                break;
                            }
                            offset2++;
                        }
                        // cout<<offset1<<" "<<offset2<<endl;
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        string argg2="";
                        // cout<<cd->arg1<<" "<<cd->arg2<<" "<<cd->result<<endl;
                        if(found1 && found2){
                            if(offset1) arg2=to_string(8*offset1);
                            if(offset2) argg2=to_string(8*offset2);
                            // cout<<arg2<<endl;
                            string tarx=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* qn=new quad(tarx,tar1,"",argg2);
                            qn->make_code_from_load();
                            temp.push_back(qn);
                            quad* qnn=new quad(tar1,tarx,"",arg2);
                            qnn->make_code_from_store();
                            temp.push_back(qnn);
                            ctr++;
                        }
                    }
                    else{
                        temp.push_back(cd);
                    }
                }
                else if (cd->made_from==quad::RETURN){
                    if(cd->self_arg1 == true){
                        string argu1=cd->arg1;
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==argu1){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        if(found){
                            string arg2="";
                            if(offset) arg2=to_string(8*offset);
                            string res=tar;
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* ql = new quad(tar2, res, "", arg2);
                            ql->make_code_from_load();
                            temp.push_back(ql);
                            string op="return";
                            quad* qr = new quad("", tar2, op, "");
                            qr->make_code_from_return();
                            temp.push_back(qr);
                        }
                    }
                    else{
                    temp.push_back(cd);
                    }
                }
                else{
                    temp.push_back(cd);
                }
            }
            (yyvsp[0].node)->code=temp;
        }
        // cout<<"abort1\n";
        bool fl=0;
        if(arg1 == "__init__") {
            if(curr->st_category!='C') yyerror("__init__ defined outside class");
            else argg1 = curr->name + '.' + arg1;

            // cout<<"polle\n";
            fl=1;
        }
        // cout<<"abort2\n";
        if(fl) {
            // cout<<curr->st_category<<"inside init\n";
            symbol_table_func * funcd=curr->look_upfunc("__init__");
            symbol_table_class *clss=(symbol_table_class *)curr;
            for(auto it:funcd->entries) {
                // cout<<"funcd\n";
                clss->attrs.push_back(it);
            }
            quad* q2 = new quad("self", "", "", "");
            q2->make_code_pop_param();
            (yyval.node)->code.push_back(q2);
            // funcf->codes.push_back(q2);
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q3 = new quad(tar, "self", "", "");
            q3->make_code_from_assignment();
            (yyval.node)->code.push_back(q3);
            // funcf->codes.push_back(q3);
            vector<quad*> temp;
            int ctr=0;
            for(auto cd:(yyvsp[0].node)->code){
                // cout<<cd->code<<endl;
                // cout<<self_res<<" "<<self_arg1<<" "<<self_arg2<<endl;
                if(cd->made_from==quad::ASSIGNMENT){
                    string tar1;
                    if(ctr==0){
                        tar1=tar;
                    }
                    // string tar=cd->result
                    else{
                        string tar2=string("_t")+to_string(temp_cnt);
                        temp_cnt++;
                        quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                        q5->make_code_from_binary();
                        temp.push_back(q5);
                        tar1=tar2;
                    }
                    string a1=cd->arg1;
                    quad* qn=new quad(tar1,a1,"","");
                    qn->make_code_from_store();
                    temp.push_back(qn);
                    ctr++;
                }
            }
            (yyvsp[0].node)->code=temp;
        }
        // cout<<"abort3\n";
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-4].node)->code.begin(), (yyvsp[-4].node)->code.end());
        // funcf->codes.insert(funcf->codes.end(), $3->code.begin(), $3->code.end());
        ircode.push_back(q);
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        // funcf->codes.insert(funcf->codes.end(), $7->code.begin(), $7->code.end());
        quad* q1 = new quad("", "", "", "");
        q1->make_code_end_func(); 
        (yyval.node)->code.push_back(q1);
        // for(auto cd: $$->code){
        //     cout<<cd->code<<endl;
        // }
        // funcf->codes.push_back(q1);
        
        // for(auto cd:$$->code) cout<<"func "<<cd->code<<endl;
    }
#line 2602 "parser.tab.c"
    break;

  case 12: /* rarr_test_maybe: R_ARR type  */
#line 445 "parser.y"
                           {Node * n5= createNode("Delimiter","->",{});(yyval.node)=createNode("rarr_maybe","",{n5,(yyvsp[0].node)});(yyval.node)->type=(yyvsp[0].node)->type;}
#line 2608 "parser.tab.c"
    break;

  case 13: /* rarr_test_maybe: %empty  */
#line 445 "parser.y"
                                                                                                                                    {(yyval.node)=createNode("rarr_test_maybe","",{});}
#line 2614 "parser.tab.c"
    break;

  case 14: /* parameters: LPAREN typedargslist RPAREN  */
#line 446 "parser.y"
                                        {Node *n6= createNode("Delimiter","(",{});Node *n7= createNode("Delimiter",")",{});(yyval.node)=createNode("params","",{n6,(yyvsp[-1].node),n7});(yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list; (yyval.node)->code=(yyvsp[-1].node)->code;}
#line 2620 "parser.tab.c"
    break;

  case 15: /* arguments: argument_a comm_arg_a  */
#line 447 "parser.y"
                                 {
    (yyval.node)=createNode("args","",{(yyvsp[-1].node),(yyvsp[0].node)});
    (yyval.node)->Sym_list.push_back((yyvsp[-1].node)->sym);
    for(auto &sy:(yyvsp[0].node)->Sym_list) (yyval.node)->Sym_list.push_back(sy);
    
    (yyval.node)->code = (yyvsp[-1].node)->code;
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
    }
#line 2633 "parser.tab.c"
    break;

  case 16: /* argument_a: tfpdef equals_test_maybe  */
#line 455 "parser.y"
                                    {(yyval.node)=createNode("arg","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->code=(yyvsp[-1].node)->code;}
#line 2639 "parser.tab.c"
    break;

  case 17: /* comm_arg_a: comm_arg_a COMMA argument_a  */
#line 456 "parser.y"
                                        {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node)); (yyval.node)->Sym_list.push_back((yyvsp[0].node)->sym); (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());}
#line 2645 "parser.tab.c"
    break;

  case 18: /* comm_arg_a: %empty  */
#line 456 "parser.y"
                                                                                                                                                                                                                                                         {(yyval.node)=createNode("comm_arg_a", "", {});}
#line 2651 "parser.tab.c"
    break;

  case 19: /* equals_test_maybe: EQUALS test  */
#line 458 "parser.y"
                               {Node *n8=createNode("Assign","=",{});(yyval.node)=createNode("args","",{n8,(yyvsp[0].node)});}
#line 2657 "parser.tab.c"
    break;

  case 20: /* equals_test_maybe: %empty  */
#line 458 "parser.y"
                                                                                                          {(yyval.node)=createNode("equals_test_maybe","",{});}
#line 2663 "parser.tab.c"
    break;

  case 21: /* kwargs: POW tfpdef comma_maybe  */
#line 459 "parser.y"
                               {Node *n9=createNode("Operator","Power(**)",{});  (yyval.node)=createNode("args","",{n9,(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym;}
#line 2669 "parser.tab.c"
    break;

  case 22: /* comma_maybe: COMMA  */
#line 460 "parser.y"
                   {Node *n10=createNode("COMMA",",",{});}
#line 2675 "parser.tab.c"
    break;

  case 23: /* comma_maybe: %empty  */
#line 460 "parser.y"
                                                             {(yyval.node)=createNode("comma_maybe","",{});}
#line 2681 "parser.tab.c"
    break;

  case 24: /* args: TIMES tfpdef  */
#line 461 "parser.y"
                  {   Node *n11 = createNode("Operator","Times(*)",{});
                        (yyval.node)=createNode("args","",{n11,(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[0].node)->sym;}
#line 2688 "parser.tab.c"
    break;

  case 25: /* args: TIMES  */
#line 463 "parser.y"
            {Node *n11 = createNode("Operator","Times(*)",{});
            (yyval.node) = createNode("args","",{n11});
                    }
#line 2696 "parser.tab.c"
    break;

  case 26: /* kwonly_kwargs: comm_arg_a comma_kwargs_maybe  */
#line 466 "parser.y"
                                            { (yyval.node)=createNode("kwarg","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2702 "parser.tab.c"
    break;

  case 27: /* comma_kwargs_maybe: COMMA kwargs  */
#line 467 "parser.y"
                                {   Node *n12 = createNode("Delimiter",",",{});
                                        (yyval.node) = createNode("kwargs","",{n12,(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[0].node)->sym;
                                    }
#line 2710 "parser.tab.c"
    break;

  case 28: /* comma_kwargs_maybe: COMMA  */
#line 470 "parser.y"
                           {(yyval.node) = createNode("Delimiter",",",{});}
#line 2716 "parser.tab.c"
    break;

  case 29: /* comma_kwargs_maybe: %empty  */
#line 471 "parser.y"
                      {(yyval.node)=createNode("comma_kwargs_maybe","",{});}
#line 2722 "parser.tab.c"
    break;

  case 30: /* args_kwonly_kwargs: args kwonly_kwargs  */
#line 472 "parser.y"
                                       { (yyval.node)=createNode("args_kw","nkw",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 2728 "parser.tab.c"
    break;

  case 31: /* args_kwonly_kwargs: kwargs  */
#line 473 "parser.y"
                            { (yyval.node)=(yyvsp[0].node);}
#line 2734 "parser.tab.c"
    break;

  case 32: /* poskeyword_args_kwonly_kwargs: arguments comma_argskwonlykwargs  */
#line 474 "parser.y"
                                                                { (yyval.node)=createNode("poskeyword_args_kwonly_kwargs","",{(yyvsp[-1].node),(yyvsp[0].node)});(yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list; (yyval.node)->code = (yyvsp[-1].node)->code;}
#line 2740 "parser.tab.c"
    break;

  case 33: /* comma_argskwonlykwargs: %empty  */
#line 475 "parser.y"
                         {(yyval.node)=createNode("comma_argskwonlykwargs","",{});}
#line 2746 "parser.tab.c"
    break;

  case 34: /* comma_argskwonlykwargs: COMMA args_kwonly_kwargs  */
#line 476 "parser.y"
                                                 {   Node *n11 = createNode("Delimiter",",",{});
                                                         (yyval.node)=createNode("comma_argskwonlykwargs","",{n11,(yyvsp[0].node)});
                                                        }
#line 2754 "parser.tab.c"
    break;

  case 35: /* comma_argskwonlykwargs: COMMA  */
#line 479 "parser.y"
                              {(yyval.node) = createNode("Delimiter",",",{});}
#line 2760 "parser.tab.c"
    break;

  case 36: /* typedargslist_no_posonly: poskeyword_args_kwonly_kwargs  */
#line 481 "parser.y"
                                                         { (yyval.node)=(yyvsp[0].node);}
#line 2766 "parser.tab.c"
    break;

  case 37: /* typedargslist_no_posonly: args_kwonly_kwargs  */
#line 482 "parser.y"
                                             { (yyval.node)=(yyvsp[0].node);}
#line 2772 "parser.tab.c"
    break;

  case 38: /* typedargslist: %empty  */
#line 483 "parser.y"
               {(yyval.node)=createNode("typedargslist","",{});}
#line 2778 "parser.tab.c"
    break;

  case 39: /* typedargslist: arguments COMMA DIVIDEDBY comma_typedargs_maybe  */
#line 484 "parser.y"
                                                              {Node* n3= createNode("div_by","/",{}); Node* n2= createNode("Delimiter",",",{});(yyval.node)=createNode("typedargslist","",{(yyvsp[-3].node),n2,n3,(yyvsp[0].node)});}
#line 2784 "parser.tab.c"
    break;

  case 40: /* typedargslist: typedargslist_no_posonly  */
#line 485 "parser.y"
                                         {  (yyval.node)=(yyvsp[0].node);}
#line 2790 "parser.tab.c"
    break;

  case 41: /* comma_typedargs_maybe: %empty  */
#line 486 "parser.y"
                      {(yyval.node)=createNode("comma_typedargs_maybe","",{});}
#line 2796 "parser.tab.c"
    break;

  case 42: /* comma_typedargs_maybe: COMMA typedargslist_no_posonly  */
#line 487 "parser.y"
                                                       {   Node *n11 = createNode("COMMA",",",{});
                                                         (yyval.node)=createNode("comma_typedargs_yes","",{n11,(yyvsp[0].node)});
                                                        }
#line 2804 "parser.tab.c"
    break;

  case 43: /* comma_typedargs_maybe: COMMA  */
#line 490 "parser.y"
                              {(yyval.node) = createNode("COMMA",",",{});}
#line 2810 "parser.tab.c"
    break;

  case 44: /* tfpdef: IDENTIFIER colon_test_maybe  */
#line 491 "parser.y"
                                    {Node *n11 = createNode("IDENTIFIER",*(yyvsp[-1].str),{});
                                    (yyval.node)=createNode("tfpdef","",{n11,(yyvsp[0].node)});
                                    Symbol * sym=new Symbol(*(yyvsp[-1].str),(yyvsp[0].node)->type,yylineno);
                                    (yyval.node)->sym=sym;
                                    string result=*(yyvsp[-1].str);
                                    if(result!="self"){
                                    quad* q = new quad(result, "", "", "");
                                    q->make_code_pop_param();
                                    (yyval.node)->code.push_back(q);
                                    }
                                    // ircode.push_back(q);
                                    }
#line 2827 "parser.tab.c"
    break;

  case 45: /* colon_test_maybe: COLON type  */
#line 503 "parser.y"
                             {Node *n11 = createNode("Delimiter",":",{});
                                                         (yyval.node)=createNode("colon_test_yes","",{n11,(yyvsp[0].node)});(yyval.node)->type=(yyvsp[0].node)->type;}
#line 2834 "parser.tab.c"
    break;

  case 46: /* colon_test_maybe: %empty  */
#line 505 "parser.y"
                  {(yyval.node)=createNode("colon_test_maybe","",{});}
#line 2840 "parser.tab.c"
    break;

  case 47: /* stmt: simple_stmt  */
#line 508 "parser.y"
                 { (yyval.node) = (yyvsp[0].node);}
#line 2846 "parser.tab.c"
    break;

  case 48: /* stmt: compound_stmt  */
#line 509 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2852 "parser.tab.c"
    break;

  case 49: /* simple_stmt: small_stmt small_stmt1 SEMICOLON NEWLINE  */
#line 510 "parser.y"
                                                       { Node* n3= createNode("Delimiter",";",{}); Node* n4= createNode("newline","nl",{});(yyval.node)=createNode("simple_stmt","",{(yyvsp[-3].node),(yyvsp[-2].node),n3,n4});}
#line 2858 "parser.tab.c"
    break;

  case 50: /* simple_stmt: small_stmt small_stmt1 NEWLINE  */
#line 511 "parser.y"
                                            { Node* n3= createNode("newline","nl",{});(yyval.node)=createNode("simple_stmt","",{(yyvsp[-2].node),(yyvsp[-1].node),n3}); (yyval.node)->code=(yyvsp[-2].node)->code; (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());}
#line 2864 "parser.tab.c"
    break;

  case 51: /* simple_stmt: small_stmt small_stmt1 SEMICOLON  */
#line 512 "parser.y"
                                              { { Node* n3= createNode("Delimiter",";",{}); (yyval.node)=createNode("simple_stmt","",{(yyvsp[-2].node),(yyvsp[-1].node),n3});} }
#line 2870 "parser.tab.c"
    break;

  case 52: /* simple_stmt: small_stmt small_stmt1  */
#line 513 "parser.y"
                                    {(yyval.node)=createNode("simple_stmt","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->code=(yyvsp[-1].node)->code; (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());}
#line 2876 "parser.tab.c"
    break;

  case 53: /* small_stmt1: small_stmt1 SEMICOLON small_stmt  */
#line 515 "parser.y"
                                              { (yyval.node)=(yyvsp[-2].node); Node* n1= createNode("Delimiter",";",{}); (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 2882 "parser.tab.c"
    break;

  case 54: /* small_stmt1: %empty  */
#line 516 "parser.y"
  {(yyval.node)=createNode("small_stmt1", "", {});}
#line 2888 "parser.tab.c"
    break;

  case 55: /* small_stmt: expr_stmt  */
#line 518 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2894 "parser.tab.c"
    break;

  case 56: /* small_stmt: flow_stmt  */
#line 520 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2900 "parser.tab.c"
    break;

  case 57: /* small_stmt: global_stmt  */
#line 522 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2906 "parser.tab.c"
    break;

  case 58: /* small_stmt: nonlocal_stmt  */
#line 523 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2912 "parser.tab.c"
    break;

  case 59: /* small_stmt: assert_stmt  */
#line 524 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2918 "parser.tab.c"
    break;

  case 60: /* type1: INT  */
#line 527 "parser.y"
           {(yyval.node)=createNode("Keyword","int",{});(yyval.node)->type="int";}
#line 2924 "parser.tab.c"
    break;

  case 61: /* type1: FLOAT  */
#line 528 "parser.y"
            {(yyval.node)=createNode("Keyword","float",{}); (yyval.node)->type="float";}
#line 2930 "parser.tab.c"
    break;

  case 62: /* type1: STR  */
#line 529 "parser.y"
          {(yyval.node)=createNode("Keyword","str",{}); (yyval.node)->type="string";}
#line 2936 "parser.tab.c"
    break;

  case 63: /* type1: BOOL  */
#line 530 "parser.y"
           {(yyval.node)=createNode("Keyword","bool",{}); (yyval.node)->type="boolean";}
#line 2942 "parser.tab.c"
    break;

  case 64: /* type1: NONE  */
#line 531 "parser.y"
           {(yyval.node)=createNode("Keyword","None",{}); (yyval.node)->type="none";}
#line 2948 "parser.tab.c"
    break;

  case 65: /* type1: IDENTIFIER  */
#line 532 "parser.y"
                 {(yyval.node)=createNode("Identifier",*(yyvsp[0].str),{}); 
        if(curr->look_up(*(yyvsp[0].str))==NULL){
            yyerror("Class not declared");
        }
        
        
        
        (yyval.node)->type="class_"+*(yyvsp[0].str);
        }
#line 2962 "parser.tab.c"
    break;

  case 66: /* type: type1  */
#line 541 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 2968 "parser.tab.c"
    break;

  case 67: /* type: LIST LLIST type1 RLIST  */
#line 542 "parser.y"
                             {
        Node *lst=createNode("Keyword","list",{});
        Node * ll=createNode("Delimiter","[",{});
        Node* rl=createNode("Delimiter","]",{});
        (yyval.node)=createNode("type","t",{lst,ll,(yyvsp[-1].node),rl});
        (yyval.node)->type="list["+(yyvsp[-1].node)->type+"]";}
#line 2979 "parser.tab.c"
    break;

  case 68: /* expr_stmt: testlist_star_expr expr_list  */
#line 548 "parser.y"
                                        {
    (yyval.node)=createNode("expr_stmt","",{(yyvsp[-1].node),(yyvsp[0].node)}); 
    if((yyvsp[0].node)->label == "Annassign") (yyvsp[-1].node)->sym->update_type((yyvsp[0].node)->type);
    // $1->sym->printSym();
    // cout<<"hello\n";

    // cout<<$1->sym->type<<" re\n";
    // cout<<$2->type<<" re\n";
    string type=(yyvsp[-1].node)->sym->type;
    if((yyvsp[0].node)->label!="Annassign"){
        if (curr->look_up((yyvsp[-1].node)->sym->lexeme)==NULL and (yyvsp[-1].node)->sym->lexeme!="print") {cout<<(yyvsp[-1].node)->sym->lexeme<<" "<<curr->st_category<<endl; yyerror("type_annotations not given");}
        else if ((yyvsp[-1].node)->sym->lexeme!="print") 
        { Symbol * sym=curr->look_up((yyvsp[-1].node)->sym->lexeme);
        type=sym->type;
        (yyvsp[-1].node)->sym->update_type(type);
        }// cout<<"type:"<<type<<endl;
    }
    // $1->sym->printSym();
    // cout<<"byebye\n";
    // cout<<"after notann\n";
    if((yyvsp[-1].node)->sym->type.substr(0,4)=="list"){
        size_t f=(yyvsp[-1].node)->sym->type.find("]");
        if(f!=string::npos){
            type=(yyvsp[-1].node)->sym->type.substr(5,f-5);
        }
    }
    // cout<<"after notlist"<<endl;
    for(auto &i:(yyvsp[0].node)->Sym_list){
        //cout<<"ss";
        if (i==NULL) continue; 

        
        // cout<<"\nlll"<<i->lexeme<<" "<<i->type<<"er"<<endl;
        if (i->type=="id" && curr->look_up(i->lexeme)==NULL){
            yyerror("Not declared");
        }
        // cout<<i->type<<"  r\n";

        // cout<<$1->sym->type<<"  r\n";
        if(i->type!=type and i->type.substr(0,4)!="list" ) yyerror("Type Mismatch");
    }
    
    // cout<<"out\n";
    if((yyvsp[0].node)->label == "Annassign") {
        (yyvsp[-1].node)->sym->is_decl=true;(yyvsp[-1].node)->sym->type=(yyvsp[0].node)->type;
        // cout<<$1->sym->lexeme<<endl;
        // cout<<$2->type.substr(0,4)<<"leep\n"; 
        if((yyvsp[0].node)->type.substr(0, 4) == "list" ){
            if(is_funccall){
                is_funccall=0;
                string a2="return_value";
                quad *q=new quad((yyvsp[-1].node)->sym->lexeme,"","","");
                q->make_code_from_return_val();
                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                (yyval.node)->code.push_back(q);
            }
            else{
                string op = "push_param";
                string sz=to_string(8*((yyvsp[0].node)->Sym_list.size()));
                quad* q6 = new quad("", sz, op, "");
                q6->make_code_push_param();
                // $$->code.push_back(q6);

                string arg1 = "allocmem";
                op="call_func";
                quad* q3 = new quad("", arg1, op, "");
                q3->make_code_from_func_call();
                // $$->code.push_back(q3);

                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                quad* q4 = new quad(tar, "", "", "");
                q4->make_code_from_return_val();
                // $$->code.push_back(q4);
            string ar1=(yyvsp[-1].node)->sym->lexeme;
            // cout<<"attribute "<<trailer_attr<<endl;
            if(trailer_attr!=""){
                
                ar1=trailer_attr;
                trailer_attr="";
            }
            // cout<<"leep "<<q->code<<endl;
            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
            (yyval.node)->code.push_back(q6);
            (yyval.node)->code.push_back(q3);
            (yyval.node)->code.push_back(q4);
            string ar2= string("_t")+to_string(temp_cnt-1);
            quad *q1=new quad(ar2,(yyvsp[0].node)->Sym_list[0]->lexeme,"=","");
            q1->make_code_from_store();
            (yyval.node)->code.push_back(q1);
            
            for(int i=1;i<(yyvsp[0].node)->Sym_list.size();i++){
                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                
                quad* q2 = new quad(tar, ar2, "+", to_string(i*8));
                q2->make_code_from_binary();
                (yyval.node)->code.push_back(q2);
                
                quad* q3=new quad(tar,(yyvsp[0].node)->Sym_list[i]->lexeme,"=","");
                q3->make_code_from_store();
                (yyval.node)->code.push_back(q3);

                

            }
            quad *qw=new quad(ar1,ar2,"=","");
            qw->make_code_from_assignment();
            (yyval.node)->code.push_back(qw);

            }
        }
        if(curr->st_category!='C' and curr->st_category!='M')
        curr->add_entry((yyvsp[-1].node)->sym);
        else if (curr->st_category=='M'){
            symbol_table_func* fs=(symbol_table_func *)curr;
            // cout<<$1->sym->lexeme<<" method\n";
            fs->add_entry((yyvsp[-1].node)->sym);
        }
        else{
            symbol_table_class* cls=(symbol_table_class *)curr;
            cls->attrs.push_back((yyvsp[-1].node)->sym);
        }
        }
    // else if (curr->st_category=='C')
    // else if (curr->st_category=='C'){cout<<$1->suym->lexeme<<end;l;}
    
    else if(curr->look_up((yyvsp[-1].node)->sym->lexeme)==NULL and (yyvsp[-1].node)->sym->lexeme!="print") {
        if(curr->st_category=='C'){
            symbol_table_class *cls=(symbol_table_class*)curr;
            // for(auto it:cls->attrs) cout<<it->lexeme<<"dddd\n";
        }
        yyerror("Type annotations not given");}
    
    if((yyvsp[0].node)->label != "expr_list_empty" and (yyvsp[-1].node)->listchk != "list_ind" && (yyvsp[0].node)->label != "Augassign" and (yyvsp[0].node)->listchk != "list_ind"){
        if((yyvsp[0].node)->type.substr(0,4)!="list"){
            string a2=(yyvsp[0].node)->res;
            if(is_funccall){
                is_funccall=0;
                a2="return_value";
                quad *q=new quad((yyvsp[-1].node)->sym->lexeme,"","","");
                q->make_code_from_return_val();
                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                (yyval.node)->code.push_back(q);
            }
            else if(is_ctorcall){
                is_ctorcall=0;
                a2="return_value";
                string arg1 = string("_t")+to_string(temp_cnt-1);
                quad *q=new quad((yyvsp[-1].node)->sym->lexeme,arg1,"","");
                q->make_code_from_assignment();
                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                (yyval.node)->code.push_back(q);
                // $1->sym->self = arg1;
            }
            else{
            string ar1=(yyvsp[-1].node)->sym->lexeme;
            // cout<<$1->sym->lexeme<<" "<<$1->sym->is_attr<<endl;
            // cout<<$2->res<<" "<<$2->is_attr<<endl;
            if(trailer_attr!=""){
                ar1=trailer_attr;
                trailer_attr="";
            }
            // if(curr->st_category=='M'){
            //     symbol_table_func* fs=(symbol_table_func *)curr;
            //     // cout<<$1->sym->lexeme<<" method\n";
            //     if(fs->look_up($1->sym->lexeme)==NULL) fs->add_entry($1->sym);
            // }
            quad *q=new quad((yyvsp[-1].node)->sym->lexeme,(yyvsp[0].node)->res,"=","");
            if((yyvsp[-1].node)->sym->is_attr == true) q->self_res = true;
            if((yyvsp[0].node)->is_attr == true) q->self_arg1 = true;
            q->make_code_from_assignment();
            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
            (yyval.node)->code.push_back(q);
            }
        }
        // for(auto cd:$$->code) cout<<"final "<<cd->code<<endl;
    }
    // cout<<"islist"<<$1->listchk<<" he"<<$2->listchk<<endl;
    if((yyvsp[0].node)->listchk == "list_ind"){
        // cout<<"listchk1\n";
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        string arg1 = (yyvsp[-1].node)->res;
        quad *q1=new quad(arg1,tar,"=","");
        q1->make_code_from_load();
        (yyval.node)->code.insert((yyval.node)->code.begin(),(yyvsp[-1].node)->code.begin(),(yyvsp[-1].node)->code.end());
        (yyval.node)->code.insert((yyval.node)->code.begin(),(yyvsp[0].node)->code.begin(),(yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q1);
    }
    if((yyvsp[-1].node)->listchk == "list_ind"){
        // cout<<"listchk1\n";
        string tar=string("_t")+to_string(temp_cnt);
        // temp_cnt++;
        // string tar=$2->res;
        string arg1 = (yyvsp[0].node)->res;
        quad *q1=new quad(tar,arg1,"=","");
        q1->make_code_from_store();
        (yyval.node)->code.insert((yyval.node)->code.begin(),(yyvsp[-1].node)->code.begin(),(yyvsp[-1].node)->code.end());
        (yyval.node)->code.insert((yyval.node)->code.begin(),(yyvsp[0].node)->code.begin(),(yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q1);
    }   
    // if($2->listchk == "list_ind"){
    //     cout<<"listchk11\n";
    //     string tar='*'+string("_t")+to_string(temp_cnt);
    //     temp_cnt++;
    //     string arg1 = $2->res;
    //     quad *q1=new quad(tar,arg1,"=","");
    //     q1->make_code_from_assignment();
    //     // $$->code=$1->code;
    //     $$->code.push_back(q1);
    // } 
    
    if((yyvsp[0].node)->label == "Augassign"){
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        string arg1=(yyvsp[-1].node)->res;
        string op=(yyvsp[0].node)->op;
        string arg2=(yyvsp[0].node)->res;
        // cout<<$1->sym->lexeme<<" "<<$1->sym->is_attr<<endl;
        // cout<<$2->res<<" "<<$2->is_attr<<endl;
        quad* q = new quad(tar, arg1, op, arg2);
        if((yyvsp[-1].node)->sym->is_attr) q->self_arg1 = true;
        if((yyvsp[0].node)->is_attr) q->self_arg2 = true;
        q->make_code_from_binary();
        (yyval.node)->code.push_back(q);
        // cout<<q->code<<endl;
        string res=(yyvsp[-1].node)->res;
        arg1=tar;
        quad* q1 = new quad(res, arg1, "", "");
        if((yyvsp[-1].node)->sym->is_attr) q1->self_res = true;
        q1->make_code_from_assignment();
        (yyval.node)->code.push_back(q1);
        // cout<<q1->code<<endl;

    }
    if((yyvsp[0].node)->label=="expr_list_empty") {
        (yyval.node)->code=(yyvsp[-1].node)->code;
        if(is_funccall){
                is_funccall=0;
                
                // a2="return_value";
                quad *q=new quad("","","","");
                q->make_code_from_return_val();
                // $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        // if($1->Sym_list[0]->lexeme!="print") 
        (yyval.node)->code.push_back(q);
            }
    }
    // $1->sym->printSym();
    // cout<<"byebye1\n";
    (yyval.node)->sym=(yyvsp[-1].node)->sym;
    }
#line 3238 "parser.tab.c"
    break;

  case 69: /* expr_list: annassign  */
#line 802 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 3244 "parser.tab.c"
    break;

  case 70: /* expr_list: augassign testlist  */
#line 803 "parser.y"
                         {(yyval.node)=createNode("Augassign","",{(yyvsp[-1].node),(yyvsp[0].node)}); 
                            (yyval.node)->code = (yyvsp[0].node)->code;
                            (yyval.node)->res = (yyvsp[0].node)->resset[0];
                            (yyval.node)->op = (yyvsp[-1].node)->value[0];
                            (yyval.node)->is_attr = (yyvsp[0].node)->is_attr;
                            (yyval.node)->listchk = (yyvsp[0].node)->listchk;

                        }
#line 3257 "parser.tab.c"
    break;

  case 71: /* expr_list: EQUALS testlist_star_expr eq_test  */
#line 811 "parser.y"
                                       {
        Node * eq=createNode("Equals","=",{});(yyval.node)=createNode("expr_list","",{eq,(yyvsp[-1].node),(yyvsp[0].node)});
        (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
        (yyval.node)->op="=";
        (yyval.node)->code=(yyvsp[-1].node)->code;
        (yyval.node)->is_attr = (yyvsp[-1].node)->sym->is_attr;
        (yyval.node)->res=(yyvsp[-1].node)->res;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->listchk = (yyvsp[0].node)->listchk;
        }
#line 3272 "parser.tab.c"
    break;

  case 72: /* expr_list: %empty  */
#line 821 "parser.y"
      {(yyval.node)=createNode("expr_list_empty","",{});}
#line 3278 "parser.tab.c"
    break;

  case 73: /* eq_test: eq_test EQUALS testlist_star_expr  */
#line 822 "parser.y"
                                           {(yyval.node)=(yyvsp[-2].node); Node * eq=createNode("Equals","=",{});(yyval.node)->children.push_back(eq);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3284 "parser.tab.c"
    break;

  case 74: /* eq_test: %empty  */
#line 823 "parser.y"
          {(yyval.node)=createNode("eq_test", "", {});}
#line 3290 "parser.tab.c"
    break;

  case 75: /* annassign: COLON type annassign_a  */
#line 824 "parser.y"
                                  {
    Node * cl=createNode("colon",":",{});(yyval.node)=createNode("Annassign","",{cl,(yyvsp[-1].node),(yyvsp[0].node)});
    (yyval.node)->type=(yyvsp[-1].node)->type;
    (yyval.node)->Sym_list=(yyvsp[0].node)->Sym_list;
    (yyval.node)->op="=";
    // cout<<"a"<<endl;
    (yyval.node)->is_attr = (yyvsp[0].node)->is_attr;
    // cout<<"b"<<endl;
    (yyval.node)->res=(yyvsp[0].node)->res;
    (yyval.node)->code=(yyvsp[0].node)->code;
    (yyval.node)->listchk = (yyvsp[0].node)->listchk;
    // cout<<$$->listchk<<"listck\n";
    //cout<<$2->type<<" tt"<<$3->type<<endl;
    //if($2->type!=$3->type) yyerror("type mismatch");

    //  for(auto cd:$$->code) cout<<"codeq10 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
#line 3313 "parser.tab.c"
    break;

  case 76: /* annassign_a: EQUALS testlist_star_expr  */
#line 842 "parser.y"
                                       {Node * eq=createNode("Equals","=",{});(yyval.node)=createNode("Annassign_a","",{eq,(yyvsp[0].node)});(yyval.node)->Sym_list=(yyvsp[0].node)->Sym_list;
    (yyval.node)->op="=";
    (yyval.node)->res=(yyvsp[0].node)->res;
    // cout<<"c"<<endl;
    // cout<<$2->listchk<<endl;
    if((yyvsp[0].node)->sym) (yyval.node)->is_attr = (yyvsp[0].node)->sym->is_attr;
    else (yyval.node)->is_attr = false;
    // cout<<"d"<<endl;
    (yyval.node)->code=(yyvsp[0].node)->code;
    (yyval.node)->type=(yyvsp[0].node)->type;
    (yyval.node)->listchk = (yyvsp[0].node)->listchk;
    // cout<<$$->listchk<<"listck\n";

    //  for(auto cd:$$->code) cout<<"codeq9 "<<cd->code<<endl;
    // cout<<"done1 "<< $$->res<<"kk\n";

}
#line 3335 "parser.tab.c"
    break;

  case 77: /* annassign_a: %empty  */
#line 858 "parser.y"
   {(yyval.node)=createNode("Annassign_a","",{});}
#line 3341 "parser.tab.c"
    break;

  case 78: /* testlist_star_expr: test_star comm_test_star COMMA  */
#line 859 "parser.y"
                                                   {Node * cmma=createNode("comma",",",{});(yyval.node)=createNode("testlist_star","",{(yyvsp[-2].node),(yyvsp[-1].node),cmma}); (yyval.node)->sym = (yyvsp[-2].node)->sym; (yyval.node)->Sym_list = (yyvsp[-2].node)->Sym_list;}
#line 3347 "parser.tab.c"
    break;

  case 79: /* testlist_star_expr: test_star comm_test_star  */
#line 860 "parser.y"
                               {(yyval.node)=createNode("Testlist_star","",{(yyvsp[-1].node),(yyvsp[0].node)});(yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;(yyval.node)->code=(yyvsp[-1].node)->code;(yyval.node)->res=(yyvsp[-1].node)->res;(yyval.node)->type=(yyvsp[-1].node)->type;(yyval.node)->listchk = (yyvsp[-1].node)->listchk;}
#line 3353 "parser.tab.c"
    break;

  case 80: /* test_star: test  */
#line 861 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 3359 "parser.tab.c"
    break;

  case 81: /* test_star: star_expr  */
#line 862 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 3365 "parser.tab.c"
    break;

  case 82: /* comm_test_star: comm_test_star COMMA test_star  */
#line 863 "parser.y"
                                               {(yyval.node)=(yyvsp[-2].node);Node * cmma=createNode("comma",",",{});(yyval.node)->children.push_back(cmma);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3371 "parser.tab.c"
    break;

  case 83: /* comm_test_star: %empty  */
#line 864 "parser.y"
                {(yyval.node)=createNode("comm_test_star", "", {});}
#line 3377 "parser.tab.c"
    break;

  case 84: /* augassign: AUGPLUS  */
#line 867 "parser.y"
             {(yyval.node)=createNode("AugAssign","+=",{});}
#line 3383 "parser.tab.c"
    break;

  case 85: /* augassign: AUGMINUS  */
#line 868 "parser.y"
               {(yyval.node)=createNode("AugAssign","-=",{});}
#line 3389 "parser.tab.c"
    break;

  case 86: /* augassign: AUGTIMES  */
#line 869 "parser.y"
               {(yyval.node)=createNode("AugAssign","*=",{});}
#line 3395 "parser.tab.c"
    break;

  case 87: /* augassign: AUGDIVIDEDBY  */
#line 870 "parser.y"
                   {(yyval.node)=createNode("AugAssign","/=",{});}
#line 3401 "parser.tab.c"
    break;

  case 88: /* augassign: AUGMODULO  */
#line 871 "parser.y"
                {(yyval.node)=createNode("AugAssign","%=",{});}
#line 3407 "parser.tab.c"
    break;

  case 89: /* augassign: AUGBIT_AND  */
#line 872 "parser.y"
                 {(yyval.node)=createNode("AugAssign","&=",{});}
#line 3413 "parser.tab.c"
    break;

  case 90: /* augassign: AUGBIT_OR  */
#line 873 "parser.y"
                {(yyval.node)=createNode("AugAssign","|=",{});}
#line 3419 "parser.tab.c"
    break;

  case 91: /* augassign: AUGBIT_XOR  */
#line 874 "parser.y"
                 {(yyval.node)=createNode("AugAssign","^=",{});}
#line 3425 "parser.tab.c"
    break;

  case 92: /* augassign: AUGBIT_RSHIFT  */
#line 875 "parser.y"
                    {(yyval.node)=createNode("AugAssign","<<=",{});}
#line 3431 "parser.tab.c"
    break;

  case 93: /* augassign: AUGBIT_LSHIFT  */
#line 876 "parser.y"
                    {(yyval.node)=createNode("AugAssign",">>=",{});}
#line 3437 "parser.tab.c"
    break;

  case 94: /* augassign: AUGPOW  */
#line 877 "parser.y"
             {(yyval.node)=createNode("AugAssign","**=",{});}
#line 3443 "parser.tab.c"
    break;

  case 95: /* augassign: AUGMOD  */
#line 878 "parser.y"
             {(yyval.node)=createNode("AugAssign","//=",{});}
#line 3449 "parser.tab.c"
    break;

  case 96: /* flow_stmt: break_stmt  */
#line 880 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 3455 "parser.tab.c"
    break;

  case 97: /* flow_stmt: continue_stmt  */
#line 880 "parser.y"
                                               {(yyval.node) = (yyvsp[0].node);}
#line 3461 "parser.tab.c"
    break;

  case 98: /* flow_stmt: return_stmt  */
#line 880 "parser.y"
                                                                       {(yyval.node) = (yyvsp[0].node);}
#line 3467 "parser.tab.c"
    break;

  case 99: /* break_stmt: BREAK  */
#line 881 "parser.y"
                  {(yyval.node)=createNode("Keyword","BREAK",{});}
#line 3473 "parser.tab.c"
    break;

  case 100: /* continue_stmt: CONTINUE  */
#line 882 "parser.y"
                        {(yyval.node)=createNode("Keyword","CONTINUE",{});}
#line 3479 "parser.tab.c"
    break;

  case 101: /* return_stmt: RETURN testlist_star_expr  */
#line 883 "parser.y"
                                       {
                                        Node *n11 = createNode("Keyword","return",{});
                                        (yyval.node)=createNode("return_stmt","",{n11, (yyvsp[0].node)});
                                        (yyval.node)->code = (yyvsp[0].node)->code;
                                        string arg1 = (yyvsp[0].node)->res;
                                        // string op1="push_param";
                                        // quad* q1 = new quad("", arg1, op1, ""); 
                                        // q1->make_code_push_param();
                                        // $$->code.push_back(q1); 
                                        string op="return";
                                        quad* q = new quad("", arg1, op, "");
                                        q->self_arg1 = (yyvsp[0].node)->sym->is_attr;
                                        q->make_code_from_return();
                                        (yyval.node)->code.push_back(q);
                                        // cout<<"return_stmt"<<q->code<<endl;
                                        }
#line 3500 "parser.tab.c"
    break;

  case 102: /* return_stmt: RETURN  */
#line 899 "parser.y"
                    {(yyval.node)=createNode("Keyword","return",{}); string op="return"; quad* q = new quad("", "", op, ""); q->make_code_from_return(); (yyval.node)->code.push_back(q);}
#line 3506 "parser.tab.c"
    break;

  case 103: /* global_stmt: GLOBAL IDENTIFIER comm_name  */
#line 901 "parser.y"
                                         {Node *n1 = createNode("Keyword","Global",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[-1].str),{}); (yyval.node)=createNode("global_stmt","",{n1, n2, (yyvsp[0].node)});}
#line 3512 "parser.tab.c"
    break;

  case 104: /* comm_name: comm_name COMMA IDENTIFIER  */
#line 902 "parser.y"
                                     {(yyval.node)=(yyvsp[-2].node);Node *n1 = createNode("Delimiter",",",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[0].str),{}); (yyval.node)->children.push_back(n1);(yyval.node)->children.push_back(n2);}
#line 3518 "parser.tab.c"
    break;

  case 105: /* comm_name: %empty  */
#line 903 "parser.y"
          {(yyval.node)=createNode("comm_name", "", {});}
#line 3524 "parser.tab.c"
    break;

  case 106: /* nonlocal_stmt: NONLOCAL IDENTIFIER comm_name  */
#line 904 "parser.y"
                                             {Node *n1 = createNode("Nonlocal","nonlocal",{}); Node *n2 = createNode("IDENTIFIER",*(yyvsp[-1].str),{}); (yyval.node)=createNode("nonlocal_stmt","",{n1, n2, (yyvsp[0].node)});}
#line 3530 "parser.tab.c"
    break;

  case 107: /* assert_stmt: ASSERT test comma_test_maybe  */
#line 905 "parser.y"
                                          {Node *n1 = createNode("Keyword","Assert",{});  (yyval.node)=createNode("Assert_stmt","",{n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 3536 "parser.tab.c"
    break;

  case 108: /* comma_test_maybe: COMMA test  */
#line 906 "parser.y"
                             {Node *n1=createNode("Delimiter",",",{}); (yyval.node)=createNode("comma_testmaybe","",{n1,(yyvsp[0].node)});}
#line 3542 "parser.tab.c"
    break;

  case 109: /* comma_test_maybe: %empty  */
#line 906 "parser.y"
                                                                                                                      {(yyval.node) = createNode("comma_test_maybe",",",{});}
#line 3548 "parser.tab.c"
    break;

  case 110: /* compound_stmt: if_stmt  */
#line 908 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 3554 "parser.tab.c"
    break;

  case 111: /* compound_stmt: while_stmt  */
#line 908 "parser.y"
                                           {(yyval.node)=(yyvsp[0].node);}
#line 3560 "parser.tab.c"
    break;

  case 112: /* compound_stmt: for_stmt  */
#line 908 "parser.y"
                                                              {(yyval.node)=(yyvsp[0].node);}
#line 3566 "parser.tab.c"
    break;

  case 113: /* compound_stmt: funcdef  */
#line 908 "parser.y"
                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 3572 "parser.tab.c"
    break;

  case 114: /* compound_stmt: classdef  */
#line 908 "parser.y"
                                                                                                   {(yyval.node)=(yyvsp[0].node);}
#line 3578 "parser.tab.c"
    break;

  case 115: /* compound_stmt: async_stmt  */
#line 908 "parser.y"
                                                                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 3584 "parser.tab.c"
    break;

  case 116: /* async_stmt: ASYNC funcdef  */
#line 909 "parser.y"
                          {Node *n1=createNode("Keyword","Async",{}); (yyval.node)=createNode("async_stmt","",{n1,(yyvsp[0].node)});}
#line 3590 "parser.tab.c"
    break;

  case 117: /* async_stmt: ASYNC for_stmt  */
#line 910 "parser.y"
                     {Node *n1=createNode("Keyword","Async",{}); (yyval.node)=createNode("async_stmt","",{n1,(yyvsp[0].node)});}
#line 3596 "parser.tab.c"
    break;

  case 118: /* $@2: %empty  */
#line 913 "parser.y"
            {symbol_table * if_block=new symbol_table("if_cond");curr->add_scope(if_block);curr=if_block;}
#line 3602 "parser.tab.c"
    break;

  case 119: /* $@3: %empty  */
#line 913 "parser.y"
                                                                                                                {
    // cout<<$3->op<<"operator\n";
    if ((yyvsp[0].node)->op!=""){
        if((yyvsp[0].node)->Sym_list[0]->lexeme=="__name__"){
            // cout<<"mainnn"<<$3->Sym_list[1]->lexeme<<endl;
            if ((yyvsp[0].node)->Sym_list[1]->lexeme!="\"__main__\"")
             yyerror("Only main allowed");
         }
        else{string type=(yyvsp[0].node)->Sym_list[0]->type;
        for(auto x:(yyvsp[0].node)->Sym_list){
            if (type!=x->type)
                yyerror("Type does not match between operands");
        }}
    }
    // for(auto &x:$3->Sym_list){
    //     // x->printSym();
    //     // cout<<x->type<<"if\n";
    // }
}
#line 3626 "parser.tab.c"
    break;

  case 120: /* if_stmt: IF $@2 test $@3 COLON suite elif_namedexprtest_colon_suite else_colon_suite_maybe  */
#line 931 "parser.y"
                                                                   {
    Node *n1=createNode("KEYWORD","if",{});
    Node *n2=createNode("Delimiter",":",{});
    (yyval.node)=createNode("If_stmt","",{n1,(yyvsp[-5].node),n2,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
    //symbol_table * if_block= new symbol_table("if_cond");
    
    curr=curr->parent;
    (yyval.node)->code=(yyvsp[-5].node)->code;
    string op="if_false";
    string arg1=(yyvsp[-5].node)->res;
    string arg2="j+"+to_string((yyvsp[-2].node)->code.size()+2);
    quad* q = new quad("",arg1,op,arg2);
    q->make_code_from_conditional();
    (yyval.node)->code.push_back(q);
    ircode.push_back(q);
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-2].node)->code.begin(), (yyvsp[-2].node)->code.end());

    op="goto";
    arg1="j+"+to_string((yyvsp[0].node)->code.size()+1);
    quad* q1=new quad("",arg1,op,"");
    q1->make_code_from_goto();
    (yyval.node)->code.push_back(q1);
    ircode.push_back(q1);
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());


    //int cnt=0;
    //for(auto line:$3->code) cnt++;
    //for(auto line:$5->code) cnt++;
    
    //q->op="if_false";
    //q->arg1=$3->res;
    //q->rel_jump = cnt;
    
    // cout<<"qcode "<<q->code<<endl;
    // cout<<"q1code "<<q1->code<<endl;
    //$$->code.push_back(q); 
    // for(auto qq:$$->code) cout<<"cond "<<qq->code<<endl;
    
    }
#line 3671 "parser.tab.c"
    break;

  case 121: /* $@4: %empty  */
#line 971 "parser.y"
                  {symbol_table * while_block=new symbol_table("while");curr->add_scope(while_block);curr=while_block;}
#line 3677 "parser.tab.c"
    break;

  case 122: /* while_stmt: WHILE $@4 test COLON suite else_colon_suite_maybe  */
#line 971 "parser.y"
                                                                                                                                                                {
    Node *n1=createNode("Keyword","while",{});
    Node *n2=createNode("Delimiter",":",{});
    (yyval.node)=createNode("while","",{n1,(yyvsp[-3].node),n2,(yyvsp[-1].node),(yyvsp[0].node)}); 
    curr=curr->parent;
    (yyval.node)->code=(yyvsp[-3].node)->code;
    string op="if_false";
    string arg1=(yyvsp[-3].node)->res;
    string arg2="j+"+to_string((yyvsp[-1].node)->code.size()+2);
    quad* q = new quad("",arg1,op,arg2);
    q->make_code_from_conditional();
    (yyval.node)->code.push_back(q);
    ircode.push_back(q);
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());

    op="goto";
    arg1="j-"+to_string((yyvsp[-1].node)->code.size()+2);
    quad* q1=new quad("",arg1,op,"");
    q1->make_code_from_goto();
    (yyval.node)->code.push_back(q1);
    ircode.push_back(q1);
    // for(auto qq:$$->code) cout<<"cond while"<<qq->code<<endl;
    }
#line 3705 "parser.tab.c"
    break;

  case 123: /* $@5: %empty  */
#line 994 "parser.y"
              {symbol_table * for_block=new symbol_table("for");curr->add_scope(for_block);curr=for_block;}
#line 3711 "parser.tab.c"
    break;

  case 124: /* for_stmt: FOR $@5 exprlist IN RANGE LPAREN testlist RPAREN COLON suite else_colon_suite_maybe  */
#line 994 "parser.y"
                                                                                                                                                                                        {
    Node* n1=createNode("Keyword","For",{});Node* n2=createNode("Keyword","In",{});
    Node* n3=createNode("Keyword","Range",{});Node* n4=createNode("Lparen","(",{});
    Node* n5=createNode("rparen",")",{});Node* n6=createNode("Delimiter",":",{});
    (yyval.node)=createNode("for","",{n1,(yyvsp[-8].node),n2,n3,n4,(yyvsp[-4].node),n5,n6,(yyvsp[-1].node),(yyvsp[0].node)});
    curr=curr->parent;
    (yyval.node)->code = (yyvsp[-8].node)->code;
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-4].node)->code.begin(), (yyvsp[-4].node)->code.end());
    for(auto it: (yyvsp[-8].node)->resset){
        // cout<<"ressetsize "<<$7->resset.size()<<" "<<$7->resset[0]<<" "<<$7->resset[1]<<" "<<$7->resset[2]<<" "<<$7->resset[3]<<endl;
        string arg1 = it;
        string op = "<";
        string argj = "j+"+to_string((yyvsp[-1].node)->code.size()+4);
        if((yyvsp[-4].node)->resset.size() == 1){
            string arg2 = (yyvsp[-4].node)->resset[0];
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q = new quad(tar, arg1, op, arg2);
            q->make_code_from_binary();
            (yyval.node)->code.push_back(q);
            ircode.push_back(q);
            string op1="if_false";
            quad* q1 = new quad("", tar, op1, argj);
            q1->make_code_from_conditional();
            (yyval.node)->code.push_back(q1);
            ircode.push_back(q1);
        }
        else if((yyvsp[-4].node)->resset.size() == 2 || (yyvsp[-4].node)->resset.size() == 3 || (yyvsp[-4].node)->resset.size() == 4){
            string arg10 = (yyvsp[-4].node)->resset[0];
            quad* q10 = new quad(it, arg10, "", "");
            q10->make_code_from_assignment();
            (yyval.node)->code.push_back(q10);
            ircode.push_back(q10);
            string arg2 = (yyvsp[-4].node)->resset[1];
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q = new quad(tar, arg1, op, arg2);
            q->make_code_from_binary();
            (yyval.node)->code.push_back(q);
            ircode.push_back(q);
            string op1="if_false";
            quad* q1 = new quad("", tar, op1, argj);
            q1->make_code_from_conditional();
            (yyval.node)->code.push_back(q1);
            ircode.push_back(q1);
        }
            // string arg2="j+"+to_string($10->code.size()+2);
    // quad* q = new quad("",arg1,op,arg2);
    // q->make_code_from_conditional();
    }
    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());
    if((yyvsp[-4].node)->resset.size() == 1 || (yyvsp[-4].node)->resset.size() == 2){
        for(auto itr: (yyvsp[-8].node)->resset){
            string ar1 = itr;
            string opr = "+";
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q2 = new quad(tar, ar1, opr, "1");
            q2->make_code_from_binary();
            (yyval.node)->code.push_back(q2);
            ircode.push_back(q2);
            quad* q3 = new quad(itr, tar, "", "");
            q3->make_code_from_assignment();
            (yyval.node)->code.push_back(q3);
            ircode.push_back(q3);
        }
    }
    else if((yyvsp[-4].node)->resset.size() == 3 || (yyvsp[-4].node)->resset.size() == 4){
        for(auto itr: (yyvsp[-8].node)->resset){
            string ar20 = (yyvsp[-4].node)->resset[3];
            string ar1 = itr;
            string opr = "+";
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q2 = new quad(tar, ar1, opr, ar20);
            q2->make_code_from_binary();
            (yyval.node)->code.push_back(q2);
            ircode.push_back(q2);
            quad* q3 = new quad(itr, tar, "", "");
            q3->make_code_from_assignment();
            (yyval.node)->code.push_back(q3);
            ircode.push_back(q3);
        }
    }
    string opb="goto";
    string arg1b="j-"+to_string((yyvsp[-1].node)->code.size()+4);
    quad* qb=new quad("",arg1b,opb,"");
    qb->make_code_from_goto();
    (yyval.node)->code.push_back(qb);
    }
#line 3806 "parser.tab.c"
    break;

  case 125: /* else_colon_suite_maybe: ELSE COLON suite  */
#line 1084 "parser.y"
                                         {Node* n1=createNode("Keyword","Else",{});Node* n2=createNode("Delimiter",":",{});(yyval.node)=createNode("else","",{n1,n2,(yyvsp[0].node)});(yyval.node)->code=(yyvsp[0].node)->code;}
#line 3812 "parser.tab.c"
    break;

  case 126: /* else_colon_suite_maybe: %empty  */
#line 1084 "parser.y"
                                                                                                                                                                                    {(yyval.node)=createNode("else_colon_suite_maybe","",{});}
#line 3818 "parser.tab.c"
    break;

  case 127: /* elif_namedexprtest_colon_suite: elif_namedexprtest_colon_suite ELIF test COLON suite  */
#line 1086 "parser.y"
                                                                                    {(yyval.node)=(yyvsp[-4].node);Node* n1=createNode("Keyword","Elif",{});Node* n2=createNode("Delimiter",":",{});(yyval.node)->children.push_back(n1);(yyval.node)->children.push_back((yyvsp[-2].node));(yyval.node)->children.push_back(n2);(yyval.node)->children.push_back((yyvsp[0].node));}
#line 3824 "parser.tab.c"
    break;

  case 128: /* elif_namedexprtest_colon_suite: %empty  */
#line 1087 "parser.y"
                              {(yyval.node)=createNode("elif_namedexprtest_colon_suite", "", {});}
#line 3830 "parser.tab.c"
    break;

  case 129: /* suite: simple_stmt  */
#line 1090 "parser.y"
                   {(yyval.node)=(yyvsp[0].node);}
#line 3836 "parser.tab.c"
    break;

  case 130: /* suite: NEWLINE INDENT stmt_morethanone DEDENT  */
#line 1091 "parser.y"
                                              {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    (yyval.node)=createNode("suite","",{n1,n2,(yyvsp[-1].node),n3});(yyval.node)->code=(yyvsp[-1].node)->code;
}
#line 3845 "parser.tab.c"
    break;

  case 131: /* stmt_morethanone: stmt_morethanone stmt  */
#line 1096 "parser.y"
                                        {
    // $$=$1;
    // cout<<"abort-2\n";
(yyval.node)=createNode("stmt_more","",{(yyvsp[-1].node)}); (yyval.node)->code = (yyvsp[-1].node)->code;for(auto ch:(yyvsp[-1].node)->children) (yyval.node)->children.push_back(ch);
(yyval.node)->children.push_back((yyvsp[0].node));(yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());}
#line 3855 "parser.tab.c"
    break;

  case 132: /* stmt_morethanone: stmt  */
#line 1100 "parser.y"
                                                                                                     {(yyval.node)=createNode("stmt_more","",{(yyvsp[0].node)}); (yyval.node)->code = (yyvsp[0].node)->code;}
#line 3861 "parser.tab.c"
    break;

  case 133: /* test: or_test if_ortest_else_test_maybe  */
#line 1102 "parser.y"
                                        {(yyval.node)=createNode("test","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                (yyval.node)->res=(yyvsp[-1].node)->res;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                (yyval.node)->last=(yyvsp[-1].node)->last;
                                if((yyvsp[0].node)->is_empty) (yyval.node)->op=(yyvsp[-1].node)->op;
                                // cout<<$1->op<<"oper1\n";
                                string op=(yyvsp[0].node)->op;
                                string rhs=(yyvsp[0].node)->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                (yyval.node)->type=(yyvsp[-1].node)->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    (yyval.node)->code.push_back(q);
                                    ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                    (yyval.node)->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq8 "<<cd->code<<endl;
    // cout<<"done2 "<< $$->res<<"kk\n";
}
#line 3894 "parser.tab.c"
    break;

  case 134: /* if_ortest_else_test_maybe: IF or_test ELSE test  */
#line 1130 "parser.y"
                                                {
    Node * n1=createNode("Keyword","if",{});Node * n2=createNode("Keyword","else",{});
    (yyval.node)=createNode("if_or_else","",{n1,(yyvsp[-2].node),n2,(yyvsp[0].node)});
}
#line 3903 "parser.tab.c"
    break;

  case 135: /* if_ortest_else_test_maybe: %empty  */
#line 1133 "parser.y"
   {(yyval.node) = createNode("if_ortest_else_test_maybe","",{});(yyval.node)->is_empty=true;}
#line 3909 "parser.tab.c"
    break;

  case 136: /* or_test: and_test or_andtest  */
#line 1135 "parser.y"
                             {(yyval.node)=createNode("or_test","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                (yyval.node)->res=(yyvsp[-1].node)->res;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                (yyval.node)->last=(yyvsp[-1].node)->last;
                                if((yyvsp[0].node)->is_empty) (yyval.node)->op=(yyvsp[-1].node)->op;
                                // cout<<$2->is_empty<<" "<<$1->op<<"oper2\n";
                                string op=(yyvsp[0].node)->op;
                                string rhs=(yyvsp[0].node)->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                (yyval.node)->type=(yyvsp[-1].node)->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    (yyval.node)->code.push_back(q);
                                    ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                    (yyval.node)->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq7 "<<cd->code<<endl;
    // cout<<"done kk\n";
}
#line 3942 "parser.tab.c"
    break;

  case 137: /* or_andtest: or_andtest OR and_test  */
#line 1163 "parser.y"
                                   {(yyval.node)=createNode("or_andtest", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;Node * n1=createNode("Keyword","and",{});
                                                        (yyval.node)->children.push_back(n1);
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op="or";
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, "or", (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = "or";
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }}
#line 3980 "parser.tab.c"
    break;

  case 138: /* or_andtest: %empty  */
#line 1196 "parser.y"
      {(yyval.node)=createNode("or_andtest", "", {});(yyval.node)->is_empty=true;}
#line 3986 "parser.tab.c"
    break;

  case 139: /* and_test: not_test and_nottest  */
#line 1198 "parser.y"
                               {
                                (yyval.node)=createNode("and_test","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym;
                                (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                (yyval.node)->res=(yyvsp[-1].node)->res;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                (yyval.node)->last=(yyvsp[-1].node)->last;
                                if((yyvsp[0].node)->is_empty) (yyval.node)->op=(yyvsp[-1].node)->op;
                                // cout<<$1->op<<"oper3\n";
                                string op=(yyvsp[0].node)->op;
                                string rhs=(yyvsp[0].node)->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                (yyval.node)->type=(yyvsp[-1].node)->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    (yyval.node)->code.push_back(q);
                                    ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                    (yyval.node)->res=tar;
                                }

                                //  for(auto cd:$$->code) cout<<"codeq6 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                }
#line 4022 "parser.tab.c"
    break;

  case 140: /* and_nottest: and_nottest AND not_test  */
#line 1229 "parser.y"
                                      {(yyval.node)=createNode("and_nottest", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;Node * n1=createNode("Keyword","and",{});
                                                        (yyval.node)->children.push_back(n1);
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op="and";
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, "and", (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = "and";
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }}
#line 4060 "parser.tab.c"
    break;

  case 141: /* and_nottest: %empty  */
#line 1262 "parser.y"
      {(yyval.node)=createNode("and_nottest", "", {});
     (yyval.node)->is_empty=true;}
#line 4067 "parser.tab.c"
    break;

  case 142: /* not_test: NOT not_test  */
#line 1265 "parser.y"
                      {(yyval.node)=createNode("Keyword","not",{}); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4073 "parser.tab.c"
    break;

  case 143: /* not_test: comparison  */
#line 1265 "parser.y"
                                                                                                    {(yyval.node)=(yyvsp[0].node);}
#line 4079 "parser.tab.c"
    break;

  case 144: /* comparison: expr comp_op_expr  */
#line 1266 "parser.y"
                              {
                                (yyval.node)=createNode("comp","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                (yyval.node)->res=(yyvsp[-1].node)->res;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                (yyval.node)->last=(yyvsp[-1].node)->last;
                                (yyval.node)->op=(yyvsp[0].node)->op;
                                string op=(yyvsp[0].node)->op;
                                string rhs=(yyvsp[0].node)->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                (yyval.node)->type=(yyvsp[-1].node)->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    (yyval.node)->code.push_back(q);
                                    ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                    (yyval.node)->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq5 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                }
#line 4112 "parser.tab.c"
    break;

  case 145: /* comp_op_expr: comp_op_expr comp_op expr  */
#line 1295 "parser.y"
                                        {
                                                        //Node * temp=$1;$$=$1;
                                                        (yyval.node)=createNode("comp_op_expr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list=(yyvsp[-2].node)->Sym_list;
                                                        // $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        (yyval.node)->is_empty=false;(yyval.node)->children.push_back((yyvsp[-1].node));
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$2->value<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op=(yyvsp[-1].node)->value;
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, (yyvsp[-1].node)->value, (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<$1->is_empty<<"empty\n";
                                                            (yyval.node)->op = (yyvsp[-1].node)->value;
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4153 "parser.tab.c"
    break;

  case 146: /* comp_op_expr: %empty  */
#line 1331 "parser.y"
              {(yyval.node)=createNode("comp_op_expr", "", {}); (yyval.node)->is_empty=true;}
#line 4159 "parser.tab.c"
    break;

  case 147: /* comp_op: LT  */
#line 1335 "parser.y"
  {(yyval.node)=createNode("Operator","<",{});}
#line 4165 "parser.tab.c"
    break;

  case 148: /* comp_op: GT  */
#line 1336 "parser.y"
    {(yyval.node)=createNode("Operator",">",{});}
#line 4171 "parser.tab.c"
    break;

  case 149: /* comp_op: EQ  */
#line 1337 "parser.y"
    {(yyval.node)=createNode("Operator","==",{});}
#line 4177 "parser.tab.c"
    break;

  case 150: /* comp_op: GTE  */
#line 1338 "parser.y"
     {(yyval.node)=createNode("Operator",">=",{});}
#line 4183 "parser.tab.c"
    break;

  case 151: /* comp_op: LTE  */
#line 1339 "parser.y"
     {(yyval.node)=createNode("Operator","<=",{});}
#line 4189 "parser.tab.c"
    break;

  case 152: /* comp_op: NEQ  */
#line 1340 "parser.y"
     {(yyval.node)=createNode("Operator","!=",{});}
#line 4195 "parser.tab.c"
    break;

  case 153: /* comp_op: IN  */
#line 1341 "parser.y"
    {(yyval.node)=createNode("Keyword","in",{});}
#line 4201 "parser.tab.c"
    break;

  case 154: /* comp_op: NOT IN  */
#line 1342 "parser.y"
        {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","in",{});(yyval.node)=createNode("not in","",{n1,n2});}
#line 4207 "parser.tab.c"
    break;

  case 155: /* comp_op: IS  */
#line 1343 "parser.y"
    {(yyval.node)=createNode("Keyword","is",{});}
#line 4213 "parser.tab.c"
    break;

  case 156: /* comp_op: IS NOT  */
#line 1344 "parser.y"
        {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","is",{});(yyval.node)=createNode("is not","",{n2,n1});}
#line 4219 "parser.tab.c"
    break;

  case 157: /* star_expr: TIMES expr  */
#line 1346 "parser.y"
                      {Node *n1=createNode("Operator","*",{});(yyval.node)=createNode("star_expr","",{n1,(yyvsp[0].node)}); (yyval.node)->Sym_list = (yyvsp[0].node)->Sym_list;}
#line 4225 "parser.tab.c"
    break;

  case 158: /* expr: xor_expr bitor_xorexpr  */
#line 1347 "parser.y"
                             {
                                (yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                (yyval.node)->res=(yyvsp[-1].node)->res;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                (yyval.node)->last=(yyvsp[-1].node)->last;
                                string op=(yyvsp[0].node)->op;
                                string rhs=(yyvsp[0].node)->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                (yyval.node)->type=(yyvsp[-1].node)->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    (yyval.node)->code.push_back(q);
                                    ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                    (yyval.node)->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq4 "<<cd->code<<endl;
    // cout<<"done3 "<< $$->res<<"kk\n";
                                }
#line 4257 "parser.tab.c"
    break;

  case 159: /* bitor_xorexpr: bitor_xorexpr BIT_OR xor_expr  */
#line 1374 "parser.y"
                                             {(yyval.node)=createNode("bitxor_andexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;Node * n1=createNode("Bit_op","|",{});
                                                        (yyval.node)->children.push_back(n1);
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op="|";
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, "|", (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = "|";
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4296 "parser.tab.c"
    break;

  case 160: /* bitor_xorexpr: %empty  */
#line 1408 "parser.y"
      {(yyval.node)=createNode("bitor_xorexpr", "", {}); (yyval.node)->is_empty=true;}
#line 4302 "parser.tab.c"
    break;

  case 161: /* xor_expr: and_expr bitxor_andexpr  */
#line 1409 "parser.y"
                                  {(yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; 
                                    (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
                                    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                    (yyval.node)->res=(yyvsp[-1].node)->res;
                                    (yyval.node)->code=(yyvsp[-1].node)->code;
                                    (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
                                    (yyval.node)->last=(yyvsp[-1].node)->last;
                                    string op=(yyvsp[0].node)->op;
                                    string rhs=(yyvsp[0].node)->res;
                                    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                    (yyval.node)->type=(yyvsp[-1].node)->type;
                                    if (op!=""){
                                        string tar=string("_t")+to_string(temp_cnt);
                                        temp_cnt++;
                                        // cout<<"tar "<<tar<<endl;
                                        quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
                                        q->make_code_from_binary();
                                        // cout<<"qqqq "<<q->code<<endl;
                                        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                        (yyval.node)->code.push_back(q);
                                        ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                        (yyval.node)->res=tar;
                                    }
                                    //  for(auto cd:$$->code) cout<<"codeq3 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                    }
#line 4334 "parser.tab.c"
    break;

  case 162: /* bitxor_andexpr: bitxor_andexpr BIT_XOR and_expr  */
#line 1436 "parser.y"
                                                {(yyval.node)=createNode("bitxor_andexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;Node * n1=createNode("Bit_op","^",{});
                                                        (yyval.node)->children.push_back(n1);
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op="^";
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, "^", (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = "^";
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4373 "parser.tab.c"
    break;

  case 163: /* bitxor_andexpr: %empty  */
#line 1470 "parser.y"
      {(yyval.node)=createNode("bitxor_andexpr", "", {}); (yyval.node)->is_empty=true;}
#line 4379 "parser.tab.c"
    break;

  case 164: /* and_expr: shift_expr bitand_shiftexpr  */
#line 1471 "parser.y"
                                      {
    (yyval.node)=createNode("expr","",{(yyvsp[-1].node),(yyvsp[0].node)}); (yyval.node)->sym = (yyvsp[-1].node)->sym; 
    (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list;
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
    (yyval.node)->res=(yyvsp[-1].node)->res;
    (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
    (yyval.node)->code=(yyvsp[-1].node)->code;
    (yyval.node)->last=(yyvsp[-1].node)->last;

    string op=(yyvsp[0].node)->op;
    string rhs=(yyvsp[0].node)->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    (yyval.node)->type=(yyvsp[-1].node)->type;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q);
        ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
        (yyval.node)->res=tar;
    } 
    //  for(auto cd:$$->code) cout<<"codeq2 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
#line 4413 "parser.tab.c"
    break;

  case 165: /* bitand_shiftexpr: bitand_shiftexpr BIT_AND shift_expr  */
#line 1500 "parser.y"
                                                      {(yyval.node)=createNode("bitand_shiftexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;Node * n1=createNode("Bit_op","&",{});
                                                        (yyval.node)->children.push_back(n1);
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op="&";
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, "&", (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = "&";
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4452 "parser.tab.c"
    break;

  case 166: /* bitand_shiftexpr: %empty  */
#line 1534 "parser.y"
      {(yyval.node)=createNode("bitand_shiftexpr", "", {}); (yyval.node)->is_empty=true;}
#line 4458 "parser.tab.c"
    break;

  case 167: /* shift_expr: arith_expr lorrshift_arithexpr  */
#line 1535 "parser.y"
                                           {
    (yyval.node)=createNode("shift_expr","",{(yyvsp[-1].node),(yyvsp[0].node)}); 
    (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list; 
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
    (yyval.node)->res=(yyvsp[-1].node)->res;
    (yyval.node)->code=(yyvsp[-1].node)->code;
    (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
    (yyval.node)->type=(yyvsp[-1].node)->type;
    (yyval.node)->last=(yyvsp[-1].node)->last;

    string op=(yyvsp[0].node)->op;
    string rhs=(yyvsp[0].node)->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q);
        ircode.push_back(q);
        (yyval.node)->last=ircode.size()-1;
        (yyval.node)->res=tar;
    }
    //  for(auto cd:$$->code) cout<<"codeq1 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
#line 4492 "parser.tab.c"
    break;

  case 168: /* lorrshift_arithexpr: lorrshift_arithexpr lshift_or_rshift arith_expr  */
#line 1565 "parser.y"
                                                                     {
                                                        (yyval.node)=createNode("lorrshift_arithexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;(yyval.node)->children.push_back((yyvsp[-1].node));
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op=(yyvsp[-1].node)->value;
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, (yyvsp[-1].node)->value, (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = (yyvsp[-1].node)->value;
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4531 "parser.tab.c"
    break;

  case 169: /* lorrshift_arithexpr: %empty  */
#line 1604 "parser.y"
      {(yyval.node)=createNode("lorrshift_arithexpr", "", {});(yyval.node)->is_empty=true;}
#line 4537 "parser.tab.c"
    break;

  case 170: /* lshift_or_rshift: BIT_LSHIFT  */
#line 1605 "parser.y"
                             {(yyval.node)=createNode("Bit_left_shift","<<",{});}
#line 4543 "parser.tab.c"
    break;

  case 171: /* lshift_or_rshift: BIT_RSHIFT  */
#line 1605 "parser.y"
                                                                                     {(yyval.node)=createNode("Bit_right_shift",">>",{});}
#line 4549 "parser.tab.c"
    break;

  case 172: /* arith_expr: term plusorminus_term  */
#line 1606 "parser.y"
                                  {
    (yyval.node)=createNode("arith_expr","",{(yyvsp[-1].node),(yyvsp[0].node)}); 
    (yyval.node)->sym = (yyvsp[-1].node)->sym; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list; 
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
    (yyval.node)->res=(yyvsp[-1].node)->res;
    (yyval.node)->code=(yyvsp[-1].node)->code;
    (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
    (yyval.node)->type=(yyvsp[-1].node)->type;
    (yyval.node)->last=(yyvsp[-1].node)->last;
    string op=(yyvsp[0].node)->op;
    string rhs=(yyvsp[0].node)->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q);
        ircode.push_back(q);
        (yyval.node)->last=ircode.size()-1;
        (yyval.node)->res=tar;
    }
    
    //cout<<"code of "<<($$->code)<<"\n";
    // for(auto cd:$$->code) cout<<"codeq "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
#line 4584 "parser.tab.c"
    break;

  case 173: /* plusorminus_term: plusorminus_term plus_or_minus term  */
#line 1637 "parser.y"
                                                       {
                                                        //Node * temp=$1;$$=$1;
                                                        (yyval.node)=createNode("plusorminus_term", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;(yyval.node)->children.push_back((yyvsp[-1].node));
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op=(yyvsp[-1].node)->value;
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, (yyvsp[-1].node)->value, (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = (yyvsp[-1].node)->value;
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4624 "parser.tab.c"
    break;

  case 174: /* plusorminus_term: %empty  */
#line 1672 "parser.y"
                  {(yyval.node)=createNode("plusorminus_term", "", {});(yyval.node)->is_empty=true;}
#line 4630 "parser.tab.c"
    break;

  case 175: /* plus_or_minus: PLUS  */
#line 1673 "parser.y"
                    {(yyval.node)=createNode("Operator","+",{});}
#line 4636 "parser.tab.c"
    break;

  case 176: /* plus_or_minus: MINUS  */
#line 1673 "parser.y"
                                                               {(yyval.node)=createNode("Operator","-",{});}
#line 4642 "parser.tab.c"
    break;

  case 177: /* term: factor timedivmod_factor  */
#line 1674 "parser.y"
                               {
    (yyval.node)=createNode("term","",{(yyvsp[-1].node),(yyvsp[0].node)});
    (yyval.node)->sym=(yyvsp[-1].node)->sym; 
    (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list; 
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end()); 
    if((yyval.node)->sym) 
    {string ar1=(yyval.node)->sym->lexeme;
            // cout<<"attribute "<<trailer_attr<<endl;
            if(trailer_attr!=""){
                
                ar1=trailer_attr;
                trailer_attr="";
            }
            (yyval.node)->res=ar1;
    }
    (yyval.node)->type=(yyvsp[-1].node)->type;
    (yyval.node)->code=(yyvsp[-1].node)->code;
    (yyval.node)->listchk = (yyvsp[-1].node)->listchk;
    (yyval.node)->last=(yyvsp[-1].node)->last;
    string op=(yyvsp[0].node)->op;
    string rhs=(yyvsp[0].node)->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,(yyvsp[-1].node)->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
        (yyval.node)->code.push_back(q);
        ircode.push_back(q);
        (yyval.node)->last=ircode.size()-1;
        (yyval.node)->res=tar;
    }
    
    //cout<<"code of "<<($$->code)<<"\n";
    // for(auto cd:$$->code) cout<<"codeqmul "<<cd->code<<endl;
    // cout<<"donea kk\n";
    }
#line 4687 "parser.tab.c"
    break;

  case 178: /* timedivmod_factor: timedivmod_factor timedivmod factor  */
#line 1714 "parser.y"
                                                       {
                                                        (yyval.node)=createNode("timedivmod_factor", "", {});
                                                        //$$->children.push_back($1);
                                                        // cout<<"donerr1\n";
                                                        for(auto ch:(yyvsp[-2].node)->children) (yyval.node)->children.push_back(ch);
                                                        (yyval.node)->last=(yyvsp[-2].node)->last;
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[-2].node)->Sym_list.begin(), (yyvsp[-2].node)->Sym_list.end());
                                                        (yyval.node)->is_empty=false;(yyval.node)->children.push_back((yyvsp[-1].node));
                                                        (yyval.node)->children.push_back((yyvsp[0].node)); 
                                                        (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(), (yyvsp[0].node)->Sym_list.begin(), (yyvsp[0].node)->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        (yyval.node)->type=(yyvsp[0].node)->type;
                                                        // $$->listchk = $3->listchk;
                                                        if(!((yyvsp[-2].node)->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            (yyval.node)->code=(yyvsp[-2].node)->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            (yyval.node)->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            (yyval.node)->op=(yyvsp[-1].node)->value;
                                                            quad* q = new quad(res, (yyvsp[-2].node)->res, (yyvsp[-1].node)->value, (yyvsp[0].node)->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            (yyval.node)->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            (yyval.node)->last=ircode.size()-1;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        else{
                                                            // cout<<"empty\n";
                                                            (yyval.node)->op = (yyvsp[-1].node)->value;
                                                            (yyval.node)->res = (yyvsp[0].node)->res;
                                                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                                        }
                                                        }
#line 4728 "parser.tab.c"
    break;

  case 179: /* timedivmod_factor: %empty  */
#line 1750 "parser.y"
                      {(yyval.node)=createNode("timedivmod_factor", "", {});(yyval.node)->is_empty=true;}
#line 4734 "parser.tab.c"
    break;

  case 180: /* timedivmod: TIMES  */
#line 1751 "parser.y"
                 {(yyval.node)=createNode("Operator","*",{});}
#line 4740 "parser.tab.c"
    break;

  case 181: /* timedivmod: DIVIDEDBY  */
#line 1751 "parser.y"
                                                              {(yyval.node)=createNode("Operator","/",{});}
#line 4746 "parser.tab.c"
    break;

  case 182: /* timedivmod: MODULO  */
#line 1751 "parser.y"
                                                                                                        {(yyval.node)=createNode("Operator","%",{});}
#line 4752 "parser.tab.c"
    break;

  case 183: /* timedivmod: MOD  */
#line 1751 "parser.y"
                                                                                                                                                {(yyval.node)=createNode("Operator","//",{});}
#line 4758 "parser.tab.c"
    break;

  case 184: /* factor: plusminusnot factor  */
#line 1752 "parser.y"
                            {(yyval.node)=(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); (yyval.node)->Sym_list = (yyvsp[0].node)->Sym_list;}
#line 4764 "parser.tab.c"
    break;

  case 185: /* factor: power  */
#line 1753 "parser.y"
                {(yyval.node)=(yyvsp[0].node);
        // cout<<"llpppoo\n";
        // for(auto it:$$->code)
        // cout<<it->code<<endl;
        }
#line 4774 "parser.tab.c"
    break;

  case 186: /* plusminusnot: PLUS  */
#line 1758 "parser.y"
                   {(yyval.node)=createNode("Operator","+",{});}
#line 4780 "parser.tab.c"
    break;

  case 187: /* plusminusnot: MINUS  */
#line 1758 "parser.y"
                                                              {(yyval.node)=createNode("Operator","-",{});}
#line 4786 "parser.tab.c"
    break;

  case 188: /* plusminusnot: BIT_NOT  */
#line 1758 "parser.y"
                                                                                                          {(yyval.node)=createNode("Operator","~",{});}
#line 4792 "parser.tab.c"
    break;

  case 189: /* power: atom_expr pow_factor_maybe  */
#line 1759 "parser.y"
                                  {(yyval.node)=createNode("power","",{(yyvsp[-1].node),(yyvsp[0].node)});(yyval.node)->sym=(yyvsp[-1].node)->sym;if((yyval.node)->sym) (yyval.node)->res=(yyval.node)->sym->lexeme;(yyval.node)->type=(yyvsp[-1].node)->type; (yyval.node)->Sym_list = (yyvsp[-1].node)->Sym_list; if((yyvsp[-1].node)->sym) (yyval.node)->Sym_list.push_back((yyvsp[-1].node)->sym); (yyval.node)->code = (yyvsp[-1].node)->code;(yyval.node)->listchk = (yyvsp[-1].node)->listchk;}
#line 4798 "parser.tab.c"
    break;

  case 190: /* pow_factor_maybe: POW factor  */
#line 1760 "parser.y"
                             {Node *n1=createNode("Operator","**",{});(yyval.node)=createNode("pow_maybe","",{n1,(yyvsp[0].node)}); (yyval.node)->Sym_list.push_back((yyvsp[0].node)->sym);}
#line 4804 "parser.tab.c"
    break;

  case 191: /* pow_factor_maybe: %empty  */
#line 1760 "parser.y"
                                                                                                                                                 {(yyval.node)=createNode("pow_maybe","",{});}
#line 4810 "parser.tab.c"
    break;

  case 192: /* atom_expr: AWAIT atom trailer  */
#line 1763 "parser.y"
                              {Node *n1=createNode("KEYWORD","AWAIT",{});(yyval.node)=createNode("atom_expr","",{n1,(yyvsp[-1].node)});}
#line 4816 "parser.tab.c"
    break;

  case 193: /* atom_expr: atom trailer  */
#line 1764 "parser.y"
               {
    // cout<<"atom_expr "<<$1->sym->lexeme<<endl;
    (yyval.node)=createNode("atom_expr","",{(yyvsp[-1].node),(yyvsp[0].node)});
    (yyval.node)->type=(yyvsp[-1].node)->type;
    if((yyvsp[-1].node)->value == "self") {(yyval.node)->sym=(yyvsp[0].node)->sym;(yyval.node)->sym->is_attr=true;}
    
    else{
        // cout<<"else atom trailer\n";
        (yyval.node)->sym=(yyvsp[-1].node)->sym;
        (yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;

        if((yyvsp[0].node)->label=="trailer_arglist"){
            // cout<<"Called args\n";
            if(curr->look_up((yyvsp[-1].node)->sym->lexeme)==NULL and (yyvsp[-1].node)->sym->lexeme!="print") yyerror("Class/Func not defined");
            else if((yyvsp[-1].node)->sym->lexeme=="print"){
                (yyval.node)->code=(yyvsp[0].node)->code;
                is_funccall=1;
                bool is_string=false;
                if((yyvsp[0].node)->Sym_list.size()==1 and (yyvsp[0].node)->Sym_list[0]->type=="string"){
                    string arg1=(yyvsp[0].node)->Sym_list[0]->lexeme;
                    quad *qs= new quad("",arg1,"","");
                    qs->make_code_print_string();
                    (yyval.node)->code.push_back(qs);
                    is_print_string=0;
                }
                
                else{
                string arg1 = "print";
                string op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                (yyval.node)->code.push_back(q);}
                
                // ircode.push_back(q);
            }
            else{
                // cout<<"Called func\n";
                
                string ag1 = "";
                if((yyvsp[-1].node)->sym->is_func){
                    symbol_table_func * funcst=ogroot->look_up_func((yyvsp[-1].node)->sym->lexeme);
                    if(funcst->params.size()!=(yyvsp[0].node)->Sym_list.size()) yyerror("Incorrect no of params");
                    for(int i=0;i<funcst->params.size();i++){
                        if(funcst->params[i]->type!=(yyvsp[0].node)->Sym_list[i]->type) yyerror("Type mismatch of params");
                    }
                is_funccall=1;
                (yyval.node)->code=(yyvsp[0].node)->code;
                ag1='+'+to_string(8*funcst->params.size());
                quad* q1 = new quad("", ag1, "", "");
                q1->make_code_stack_pointer();
                // cout<<q1->code<<"\n";
                // $$->code.push_back(q1);

                string arg1 = (yyvsp[-1].node)->sym->lexeme;
                string op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                (yyval.node)->code.push_back(q);
                ircode.push_back(q);

                ag1='-'+to_string(8*funcst->params.size());
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // cout<<q2->code<<"\n";
                // $$->code.push_back(q2);
                }

                else if((yyvsp[-1].node)->sym->is_class) {
                    symbol_table_class * clst=ogroot->look_up_class((yyvsp[-1].node)->sym->lexeme);
                    if(clst->params.size()!=((yyvsp[0].node)->Sym_list.size())) yyerror("Incorrect no of params");
                    for(int i=0;i<clst->params.size();i++){
                        if(clst->params[i]->type!=(yyvsp[0].node)->Sym_list[i]->type) yyerror("Type mismatch of params");
                    }
                    is_ctorcall = 1;
                    (yyval.node)->code=(yyvsp[0].node)->code;
                    ag1='+' + to_string(8*clst->params.size());
                quad* q1 = new quad("", ag1, "", "");
                // q1->make_code_stack_pointer();
                // $$->code.push_back(q1);

                string op = "push_param";
                string sz=to_string(8*(clst->attrs.size()));
                quad* q6 = new quad("", sz, op, "");
                q6->make_code_push_param();
                (yyval.node)->code.push_back(q6);

                string arg1 = "allocmem";
                op="call_func";
                quad* q3 = new quad("", arg1, op, "");
                q3->make_code_from_func_call();
                (yyval.node)->code.push_back(q3);

                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                quad* q4 = new quad(tar, "", "", "");
                q4->make_code_from_return_val();
                (yyval.node)->code.push_back(q4);

                op = "push_param";
                quad* q5 = new quad("", tar, op, "");
                q5->make_code_push_param();
                (yyval.node)->code.push_back(q5);
                // $$->sym->lexeme = tar;

                arg1 = (yyvsp[-1].node)->sym->lexeme + '.' + "__init__";
                op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                (yyval.node)->code.push_back(q);
                ircode.push_back(q);
                ag1='-'+to_string(8*clst->params.size());
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // $$->code.push_back(q2);
                }
            }
            // quad* q1 = new quad("", ag1, "", "");
            // q1->make_code_stack_pointer();
            // $$->code.push_back(q1);
        }
        else if((yyvsp[0].node)->label=="trailer_method"){
            // cout<<"problem"<<endl;
            string class_name=(yyvsp[-1].node)->type.substr(6,(yyvsp[-1].node)->type.size()-1);
            // cout<<class_name<<"taraa";
            if(ogroot->look_up_class(class_name)==NULL){
                yyerror("class not declared");
            }
            symbol_table_class * cls=ogroot->look_up_class(class_name);
            if(cls->look_upfunc((yyvsp[0].node)->sym->lexeme)==NULL) yyerror("Member Function not defined");
            symbol_table_func *fun=cls->look_upfunc((yyvsp[0].node)->sym->lexeme);

            symbol_table_class * cls2=cls;

            if(cls2->parent_name != "global") cls2=ogroot->look_up_class(cls2->parent_name);
            // for(auto x1:fun->params) cout<<"ddfff "<<x1->lexeme<<" pp "<<x1->type<<endl;
            if((yyvsp[0].node)->Sym_list.size()!=(fun->params.size()-1)) yyerror("Params size mismatch");
            else{
            for(int i=0;i<fun->params.size()-1;i++){
                    // cout<<"SSDDDD "<<fun->params[i+1]->type<<" tt"<<$2->Sym_list[i]->type<<endl;
                    if(fun->params[i+1]->type!=(yyvsp[0].node)->Sym_list[i]->type) yyerror("Type mismatch of params");
            }
            is_funccall=1;
            // cout<<"funcclass\n";
                (yyval.node)->code=(yyvsp[0].node)->code;
                // symbol_table_func funcst;
                // for(auto it:cls->member_funcs){

                // }
                
                string op = "push_param";
                quad* q5 = new quad("", (yyvsp[-1].node)->sym->lexeme, op, "");
                q5->make_code_push_param();
                (yyval.node)->code.push_back(q5);
                
                string ag1='+'+to_string(8*(fun->params.size()-1));
                quad* q1 = new quad("", ag1, "", "");
                // q1->make_code_stack_pointer();
                // cout<<q1->code<<"\n";
                // $$->code.push_back(q1);

                // string arg1 = cls2->name+'.'+$2->sym->lexeme;
                string arg1 = cls2->name+'.'+(yyvsp[0].node)->sym->lexeme;
                op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                (yyval.node)->code.push_back(q);

                ag1='-'+to_string(8*(fun->params.size()-1));
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // cout<<q2->code<<"\n";
                // $$->code.push_back(q2);
            }
            
        }
        else if((yyvsp[0].node)->label=="attribute"){
            // cout<<$1->type<<" taraa\n";
            string class_name=(yyvsp[-1].node)->type.substr(6,(yyvsp[-1].node)->type.size()-1);
            
            if(ogroot->look_up_class(class_name)==NULL){
                yyerror("class not declared");
            }
            symbol_table_class * cls=ogroot->look_up_class(class_name);
            bool found=false;
            int offset=0;
            for(auto it:cls->attrs){
                if(it->lexeme==(yyvsp[0].node)->sym->lexeme){
                    found=true;
                    break;
                }
                offset++;
            }
            if(!found) yyerror("Attribute not defined");
            else{
                string tar=string("_t")+to_string(temp_cnt);
                string arg1 = (yyvsp[-1].node)->sym->lexeme;
                string arg2 = "";
                if(offset) arg2 = to_string(8*offset);
                temp_cnt++;
                // cout<<"argpr"<<arg2<<offset<<endl;
                quad* q1 = new quad(tar, arg1, "", arg2);
                q1->make_code_from_load();
                (yyval.node)->code.push_back(q1);
                // $$->sym->lexeme = tar;
                trailer_attr=tar;
                // cout<<"atrr2 "<<trailer_attr<<endl;
            }
        }
        else if((yyvsp[0].node)->label == "trailer_list"){
            (yyval.node)->sym->is_attr = false;
            // cout<<"yay"<<endl;
            string arg1 = (yyvsp[-1].node)->sym->lexeme;
            string op = "+";
            string ind=(yyvsp[0].node)->sym->lexeme;
            string arg2;
            if (ind[0]>='0' and ind[0]<='9')
            ind = to_string(stoi((yyvsp[0].node)->sym->lexeme)*8);
            else {
                if (curr->look_up(ind)==NULL) yyerror("Index not found");
                else{
                    string tar=string("_t")+to_string(temp_cnt);
                    temp_cnt++;
                    // $$->listchk = "list_ind";
                    string op1="*";
                    arg2="8";
                    quad* q1 = new quad(tar, ind, op1, arg2);
                    q1->make_code_from_binary();
                    (yyval.node)->code.push_back(q1);
                    ind=tar;
                }
             }
            string tar=string("_t")+to_string(temp_cnt);
            // temp_cnt++;
            (yyval.node)->listchk = "list_ind";
            quad* q = new quad(tar, arg1, op, ind);
            q->make_code_from_binary();
            // cout<<"lst"<<q->code<<endl;
            (yyval.node)->code.push_back(q);
        }
    }
    
    }
#line 5066 "parser.tab.c"
    break;

  case 194: /* atom: LPAREN testlist_comp RPAREN  */
#line 2011 "parser.y"
                                  {Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});(yyval.node)=createNode("atom","",{n1,(yyvsp[-1].node),n2});}
#line 5072 "parser.tab.c"
    break;

  case 195: /* atom: LEN LPAREN testlist_comp RPAREN  */
#line 2012 "parser.y"
                                        {Node *n3=createNode("KEYWORD","len",{});Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});(yyval.node)=createNode("atom","",{n3,n1,(yyvsp[-1].node),n2});}
#line 5078 "parser.tab.c"
    break;

  case 196: /* atom: LLIST testlist_comp RLIST  */
#line 2014 "parser.y"
                                 {Node *n1=createNode("Delimiter","[",{});Node *n2=createNode("Delimiter","]",{});(yyval.node)=createNode("atom","",{n1,(yyvsp[-1].node),n2});(yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;(yyval.node)->type="list";}
#line 5084 "parser.tab.c"
    break;

  case 197: /* atom: IDENTIFIER  */
#line 2015 "parser.y"
                  {
            // cout<<"p"<<endl;
            (yyval.node)=createNode("Identifier",*(yyvsp[0].str),{});
            if(curr->look_up(*(yyvsp[0].str))==NULL){
                // cout<<*$1<<"not found\n";
            Symbol * temp = new Symbol(*(yyvsp[0].str),"id",yylineno);
            if(*(yyvsp[0].str)=="print") is_print_string=1;
            (yyval.node)->sym=temp;
            (yyval.node)->type="identifier";
            temp->token = "IDENTIFIER";
            }
            else {(yyval.node)->sym=curr->look_up(*(yyvsp[0].str));(yyval.node)->type=(yyval.node)->sym->type;}
        }
#line 5102 "parser.tab.c"
    break;

  case 198: /* atom: NUMBER  */
#line 2028 "parser.y"
                {(yyval.node)=createNode("int",*(yyvsp[0].str),{});
            Symbol * temp = new Symbol(*(yyvsp[0].str),"int",yylineno);
            (yyval.node)->sym=temp;
            (yyval.node)->type="int";
            temp->token = "INT";
           }
#line 5113 "parser.tab.c"
    break;

  case 199: /* atom: string_pl  */
#line 2034 "parser.y"
                  {(yyval.node)=(yyvsp[0].node);}
#line 5119 "parser.tab.c"
    break;

  case 200: /* atom: FLOATING_POINT  */
#line 2035 "parser.y"
                        {(yyval.node)=createNode("float",*(yyvsp[0].str),{});
            Symbol * temp = new Symbol(*(yyvsp[0].str),"float",yylineno);
            (yyval.node)->sym=temp;
            (yyval.node)->type="float";
            temp->token = "FLOAT";
            }
#line 5130 "parser.tab.c"
    break;

  case 201: /* atom: NONE  */
#line 2042 "parser.y"
              {(yyval.node)=createNode("KEYWORD","None",{});
            }
#line 5137 "parser.tab.c"
    break;

  case 202: /* atom: TRUE  */
#line 2044 "parser.y"
              {(yyval.node)=createNode("KEYWORD","True",{});
            }
#line 5144 "parser.tab.c"
    break;

  case 203: /* atom: FALSE  */
#line 2046 "parser.y"
               {(yyval.node)=createNode("KEYWORD","False",{});
            }
#line 5151 "parser.tab.c"
    break;

  case 204: /* string_pl: string_pl STR_LIT  */
#line 2050 "parser.y"
                             {(yyval.node)=(yyvsp[-1].node);Node * n1= createNode("string",*(yyvsp[0].str),{});(yyval.node)->children.push_back(n1);}
#line 5157 "parser.tab.c"
    break;

  case 205: /* string_pl: STR_LIT  */
#line 2051 "parser.y"
          {(yyval.node)= createNode("string",*(yyvsp[0].str),{});
    // cout<<*$1<<" wert"<<endl;
    Symbol * temp = new Symbol(*(yyvsp[0].str),"string",yylineno);
            (yyval.node)->sym=temp;
            (yyval.node)->type="str";
            temp->token = "STR";    
    }
#line 5169 "parser.tab.c"
    break;

  case 206: /* testlist_comp: %empty  */
#line 2058 "parser.y"
               {(yyval.node)=createNode("testlist_comp","",{});}
#line 5175 "parser.tab.c"
    break;

  case 207: /* testlist_comp: test testlist_comp_a  */
#line 2059 "parser.y"
                           {
    (yyval.node)=createNode("testlist_comp","",{(yyvsp[-1].node),(yyvsp[0].node)});
    (yyval.node)->sym=(yyvsp[-1].node)->sym;
    (yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;
    // cout<<"don1\n";
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(),(yyvsp[0].node)->Sym_list.begin(),(yyvsp[0].node)->Sym_list.end());
    // cout<<"don0\n";
    }
#line 5188 "parser.tab.c"
    break;

  case 208: /* testlist_comp: star_expr testlist_comp_a  */
#line 2066 "parser.y"
                                 {(yyval.node)=createNode("testlist_comp","",{(yyvsp[-1].node),(yyvsp[0].node)});}
#line 5194 "parser.tab.c"
    break;

  case 209: /* testlist_comp_a: comp_for  */
#line 2067 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 5200 "parser.tab.c"
    break;

  case 210: /* testlist_comp_a: comma_testorstar COMMA  */
#line 2067 "parser.y"
                                                           {Node *n1=createNode("Delimiter",",",{});(yyval.node)=createNode("testlist_comp_a","",{(yyvsp[-1].node),n1});}
#line 5206 "parser.tab.c"
    break;

  case 211: /* testlist_comp_a: comma_testorstar  */
#line 2067 "parser.y"
                                                                                                                                                                     {(yyval.node)=(yyvsp[0].node);}
#line 5212 "parser.tab.c"
    break;

  case 212: /* comma_testorstar: comma_testorstar COMMA test_or_starexpr  */
#line 2068 "parser.y"
                                                          {
    // $$=$1;
    (yyval.node)=createNode("comma_testorstar", "", {});
    (yyval.node)->Sym_list=(yyvsp[-2].node)->Sym_list;
    (yyval.node)->sym=(yyvsp[-2].node)->sym;
    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(),(yyvsp[0].node)->Sym_list.begin(),(yyvsp[0].node)->Sym_list.end());
    Node *n1=createNode("Delimiter",",",{});
    (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 5226 "parser.tab.c"
    break;

  case 213: /* comma_testorstar: %empty  */
#line 2076 "parser.y"
    {(yyval.node)=createNode("comma_testorstar", "", {});}
#line 5232 "parser.tab.c"
    break;

  case 214: /* test_or_starexpr: test  */
#line 2077 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 5238 "parser.tab.c"
    break;

  case 215: /* test_or_starexpr: star_expr  */
#line 2077 "parser.y"
                                          {(yyval.node)=(yyvsp[0].node);}
#line 5244 "parser.tab.c"
    break;

  case 216: /* trailer: LPAREN arglist RPAREN  */
#line 2078 "parser.y"
                               { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer_arglist", "", {n1, (yyvsp[-1].node), n2});
                                
                                (yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;
                                reverse((yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                            }
#line 5257 "parser.tab.c"
    break;

  case 217: /* trailer: LPAREN RPAREN  */
#line 2086 "parser.y"
                                                { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer_arglist", "", {n1, n2});}
#line 5265 "parser.tab.c"
    break;

  case 218: /* trailer: LLIST subscriptlist RLIST  */
#line 2089 "parser.y"
                                                            { Node *n1=createNode("Delimiter", "[", {}); 
                                Node *n2=createNode("Delimiter", "]", {});
                                (yyval.node)=createNode("trailer_list", "", {n1, (yyvsp[-1].node), n2});
                                (yyval.node)->sym=(yyvsp[-1].node)->sym;
                                if((yyval.node)->sym->type!="int") yyerror("List index can be int only");
                                // cout<<"list index\n";
                                }
#line 5277 "parser.tab.c"
    break;

  case 219: /* trailer: DOT IDENTIFIER  */
#line 2096 "parser.y"
                                                 { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *(yyvsp[0].str), {});
                                (yyval.node)=createNode("attribute", "", {n1, n2});
                                Symbol * temp = new Symbol(*(yyvsp[0].str),"identifier",yylineno);
                                (yyval.node)->sym = temp;
                                // cout<<"atrribute "<<*$2<<endl;
                                }
#line 5289 "parser.tab.c"
    break;

  case 220: /* trailer: DOT IDENTIFIER LPAREN arglist RPAREN  */
#line 2103 "parser.y"
                                                                      { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *(yyvsp[-3].str), {});
                                Node *n3=createNode("Delimiter", "(", {}); 
                                Node *n4=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer_method", "", {n1, n2, n3, (yyvsp[-1].node), n4});
                                Symbol * temp = new Symbol(*(yyvsp[-3].str),"identifier",yylineno);
                                (yyval.node)->sym = temp;
                                (yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                }
#line 5304 "parser.tab.c"
    break;

  case 221: /* trailer: DOT IDENTIFIER LPAREN RPAREN  */
#line 2113 "parser.y"
                                                              { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *(yyvsp[-2].str), {});
                                Node *n3=createNode("Delimiter", "(", {}); 
                                Node *n4=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("trailer_method", "", {n1, n2, n3, n4});
                                Symbol * temp = new Symbol(*(yyvsp[-2].str),"identifier",yylineno);
                                (yyval.node)->sym = temp;
                                }
#line 5317 "parser.tab.c"
    break;

  case 222: /* trailer: %empty  */
#line 2121 "parser.y"
                                  {(yyval.node)=createNode("Null","",{});}
#line 5323 "parser.tab.c"
    break;

  case 223: /* subscriptlist: subscript comma_subscript COMMA  */
#line 2122 "parser.y"
                                               { Node *n1=createNode("Delimiter", ",", {});
                                (yyval.node)=createNode("subscriptlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1}); (yyval.node)->code = (yyvsp[-2].node)->code;}
#line 5330 "parser.tab.c"
    break;

  case 224: /* subscriptlist: subscript comma_subscript  */
#line 2124 "parser.y"
                                                            { (yyval.node)=createNode("subscriptlist", "", {(yyvsp[-1].node), (yyvsp[0].node)});(yyval.node)->sym=(yyvsp[-1].node)->sym;(yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list; (yyval.node)->code = (yyvsp[-1].node)->code;}
#line 5336 "parser.tab.c"
    break;

  case 225: /* comma_subscript: comma_subscript COMMA subscript  */
#line 2125 "parser.y"
                                                 { (yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {});
                                (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5343 "parser.tab.c"
    break;

  case 226: /* comma_subscript: %empty  */
#line 2127 "parser.y"
                                  {(yyval.node)=createNode("comma_subscript", "", {});}
#line 5349 "parser.tab.c"
    break;

  case 227: /* subscript: test  */
#line 2128 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 5355 "parser.tab.c"
    break;

  case 228: /* subscript: test COLON test sliceop_maybe  */
#line 2128 "parser.y"
                                                        { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {(yyvsp[-3].node), n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5362 "parser.tab.c"
    break;

  case 229: /* subscript: test COLON sliceop_maybe  */
#line 2130 "parser.y"
                                                           { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {(yyvsp[-2].node), n1, (yyvsp[0].node)});}
#line 5369 "parser.tab.c"
    break;

  case 230: /* subscript: COLON test sliceop_maybe  */
#line 2132 "parser.y"
                                                           { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5376 "parser.tab.c"
    break;

  case 231: /* subscript: COLON sliceop_maybe  */
#line 2134 "parser.y"
                                                      { Node *n1=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("subscript", "", {n1, (yyvsp[0].node)});}
#line 5383 "parser.tab.c"
    break;

  case 232: /* sliceop_maybe: sliceop  */
#line 2136 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 5389 "parser.tab.c"
    break;

  case 233: /* sliceop_maybe: %empty  */
#line 2136 "parser.y"
                                 {(yyval.node)=createNode("sliceop_maybe","",{});}
#line 5395 "parser.tab.c"
    break;

  case 234: /* sliceop: COLON test  */
#line 2137 "parser.y"
                    { Node *n1=createNode("Delimiter", ":", {}); (yyval.node)=createNode("sliceop", "", {n1, (yyvsp[0].node)});}
#line 5401 "parser.tab.c"
    break;

  case 235: /* sliceop: COLON  */
#line 2137 "parser.y"
                                                                                                                 {(yyval.node)=createNode("Delimiter", ":", {});}
#line 5407 "parser.tab.c"
    break;

  case 236: /* exprlist: expr_str comm_exstr COMMA  */
#line 2138 "parser.y"
                                    { 
                                    Node *n1=createNode("Delimiter", ",", {});
                                    (yyval.node)=createNode("exprlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});
                                    (yyval.node)->code = (yyvsp[-2].node)->code;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());
                                    (yyval.node)->resset.push_back((yyvsp[-2].node)->res);
                                    (yyval.node)->resset.insert((yyval.node)->resset.end(), (yyvsp[-1].node)->resset.begin(), (yyvsp[-1].node)->resset.end());
                                    }
#line 5420 "parser.tab.c"
    break;

  case 237: /* exprlist: expr_str comm_exstr  */
#line 2146 "parser.y"
                                  {
                                    (yyval.node)=createNode("exprlist", "", {(yyvsp[-1].node), (yyvsp[0].node)});
                                    (yyval.node)->resset.push_back((yyvsp[-1].node)->res);
                                    (yyval.node)->resset.insert((yyval.node)->resset.end(), (yyvsp[0].node)->resset.begin(), (yyvsp[0].node)->resset.end());
                                    }
#line 5430 "parser.tab.c"
    break;

  case 238: /* expr_str: expr  */
#line 2151 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 5436 "parser.tab.c"
    break;

  case 239: /* expr_str: star_expr  */
#line 2151 "parser.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 5442 "parser.tab.c"
    break;

  case 240: /* comm_exstr: comm_exstr COMMA expr_str  */
#line 2152 "parser.y"
                                      {
                                        (yyval.node)=(yyvsp[-2].node);
                                        Node *n1=createNode("Delimiter", ",", {});
                                        (yyval.node)->children.push_back(n1); (yyval.node)->children.push_back((yyvsp[0].node));
                                        (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                        (yyval.node)->resset.push_back((yyvsp[0].node)->res);
                                        }
#line 5454 "parser.tab.c"
    break;

  case 241: /* comm_exstr: %empty  */
#line 2159 "parser.y"
              {(yyval.node)=createNode("comm_exstr", "", {});}
#line 5460 "parser.tab.c"
    break;

  case 242: /* testlist: test comm_test COMMA  */
#line 2160 "parser.y"
                               { 
                                Node *n1=createNode("Delimiter", ",", {});
                                (yyval.node)=createNode("testlist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1});
                                (yyval.node)->code=(yyvsp[-2].node)->code;
                                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());
                                if((yyvsp[-2].node)->res != "") (yyval.node)->resset.push_back((yyvsp[-2].node)->res);
                                if(!(yyvsp[-1].node)->resset.empty()) (yyval.node)->resset.insert((yyval.node)->resset.end(), (yyvsp[-1].node)->resset.begin(), (yyvsp[-1].node)->resset.end());
                                }
#line 5473 "parser.tab.c"
    break;

  case 243: /* testlist: test comm_test  */
#line 2168 "parser.y"
                         {(yyval.node)=createNode("testlist", "", {(yyvsp[-1].node), (yyvsp[0].node)}); (yyval.node)->code=(yyvsp[-1].node)->code; (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end()); if((yyvsp[-1].node)->res != "") (yyval.node)->resset.push_back((yyvsp[-1].node)->res); if(!(yyvsp[0].node)->resset.empty()) (yyval.node)->resset.insert((yyval.node)->resset.end(), (yyvsp[0].node)->resset.begin(), (yyvsp[0].node)->resset.end()); (yyval.node)->is_attr = (yyvsp[-1].node)->sym->is_attr;}
#line 5479 "parser.tab.c"
    break;

  case 244: /* comm_test: comm_test COMMA test  */
#line 2169 "parser.y"
                                {(yyval.node)=(yyvsp[-2].node); Node *n1=createNode("Delimiter", ",", {}); 
                        (yyval.node)->children.push_back(n1); 
                        (yyval.node)->children.push_back((yyvsp[0].node)); (yyval.node)->code.insert((yyval.node)->code.end(),  (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                        if(!(yyvsp[-2].node)->resset.empty()) (yyval.node)->resset.insert((yyval.node)->resset.end(), (yyvsp[-2].node)->resset.begin(), (yyvsp[-2].node)->resset.end());
                        if((yyvsp[0].node)->res != "") (yyval.node)->resset.push_back((yyvsp[0].node)->res);}
#line 5489 "parser.tab.c"
    break;

  case 245: /* comm_test: %empty  */
#line 2174 "parser.y"
                          {(yyval.node)=createNode("comm_test", "", {});}
#line 5495 "parser.tab.c"
    break;

  case 246: /* $@6: %empty  */
#line 2182 "parser.y"
                           {symbol_table_class * stclass = new symbol_table_class(*(yyvsp[0].str));
                            ogroot->add_entry(stclass);curr->add_scope(stclass);
                            Symbol * temp = new Symbol(*(yyvsp[0].str), "class_"+*(yyvsp[0].str), yylineno);
                            temp->is_class=true;curr->add_entry(temp);
                            curr=stclass;
                            }
#line 5506 "parser.tab.c"
    break;

  case 247: /* $@7: %empty  */
#line 2187 "parser.y"
                                                {
                                    vector<symbol_table_func *> member_funcs_new;
                                symbol_table_class *cls=(symbol_table_class *)curr;
                                symbol_table_class *bs;
                                for(auto base:(yyvsp[0].node)->Sym_list){
                                    if(ogroot->look_up_class(base->lexeme)==NULL) yyerror("Undeclared class used as base");
                                    else{
                                        bs=ogroot->look_up_class(base->lexeme);
                                        cls->parent_name = bs->name;
                                        // cout<<"parent "<<bs->name<<endl;
                                        // for(auto at:cls->attrs){
                                        //     cout<<"1 "<<at->lexeme<<endl;
                                        // }
                                        for(auto it:bs->attrs){
                                            cls->attrs.push_back(it);
                                            // cout<<it->lexeme<<endl;
                                        }
                                        // for(auto at:cls->attrs){
                                        //     cout<<at->lexeme<<endl;
                                        // }
                                        for(auto f:bs->member_funcs){
                                            if(f->name!="__init__"){
                                                cls->member_funcs.push_back(f);
                                                member_funcs_new.push_back(f);
                                            }
                                        }

                                        // for(auto it:cls->attrs) cout<<"atrrib base"<<it->lexeme<<endl;
                                        // for(auto it:cls->member_funcs) cout<<"memberfunc base"<<it->name<<endl;
                                    }
                                }
                                }
#line 5543 "parser.tab.c"
    break;

  case 248: /* classdef: CLASS IDENTIFIER $@6 l_arglist_r_maybe $@7 COLON suite  */
#line 2219 "parser.y"
                                            { 
                                
                                Node *n1=createNode("KEYWORD", "CLASS", {}); 
                                Node *n2=createNode("Identifier", *(yyvsp[-5].str), {});
                                Node *n3=createNode("Delimiter", ":", {});
                                (yyval.node)=createNode("classdef", "", {n1, n2, (yyvsp[-3].node), n3, (yyvsp[0].node)});
                                // for(auto base:$4->Sym_list){
                                //     if(ogroot->look_up_class(base->lexeme)==NULL) yyerror("Undeclared class used as base");
                                //     else{
                                //         symbol_table_class *bs=ogroot->look_up_class(base->lexeme);
                                //         for(auto it:bs->attrs) cls->attrs.push_back(it);
                                //         for(auto f:bs->member_funcs){
                                //             if(f->name!="__init__"){
                                //                 cls->member_funcs.push_back(f);
                                //             }
                                //         }

                                //         for(auto it:cls->attrs) cout<<"atrrib base"<<it->lexeme<<endl;
                                        
                                //     }
                                // }

                                symbol_table_func* init=curr->look_upfunc("__init__");
                                // cout<<"looks\n";
                                if(init==NULL) yyerror("init func not defined");
                                else{
                                    symbol_table_class *cls=(symbol_table_class *)curr;
                                    for(auto pr:init->params){
                                        if(pr->lexeme!="self") cls->params.push_back(pr);
                                    }
                                    // for(auto it:init->entries){
                                    //     cls->attrs.push_back(it);
                                    // }
                                    // for(auto it:cls->attrs) cout<<"atrrib "<<it->lexeme<<endl;
                                }
                                symbol_table_class* cls = (symbol_table_class*)curr;
                                curr=curr->parent;
                                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-3].node)->code.begin(), (yyvsp[-3].node)->code.end());
                                string arg1=*(yyvsp[-5].str);
                                quad* q = new quad("", arg1, "", "");
                                q->make_code_begin_class();
                                // $$->code.push_back(q);
                                ircode.push_back(q);
                                (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                // for(auto it:cls->attrs){
                                //     cout<<cls->name<<" "<<it->lexeme<<endl;
                                // }
                                // vector<quad*> funcs_code;
                                // for(auto fnc:member_funcs_new){
                                //     string argfun = curr2->name + '.' + fnc->name;
                                //     quad* qb = new quad("", argfun, "", "");
                                //     qb->make_code_begin_func();
                                //     funcs_code.push_back(qb);
                                //     for(auto cd:fnc->codes){
                                //         string str1 = "*(";
                                //         // size_t found = str.find(str1);
                                //         // if (found != string::npos){
                                            
                                //         // }
                                //     }
                                // }
                                // $$->code.insert($$->code.end(), funcs_code.begin(), funcs_code.end());
                                quad* q1 = new quad("", "", "", "");
                                q1->make_code_end_class(); 
                                // $$->code.push_back(q1);
                                ircode.push_back(q1);
                                // for(auto cd:$$->code) cout<<"class "<<cd->code<<endl;
                                }
#line 5616 "parser.tab.c"
    break;

  case 249: /* l_arglist_r_maybe: LPAREN arglist RPAREN  */
#line 2287 "parser.y"
                                         { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                (yyval.node)=createNode("l_arglist_r_maybe", "", {n1, (yyvsp[-1].node), n2});
                                (yyval.node)->Sym_list=(yyvsp[-1].node)->Sym_list;
                                (yyval.node)->code=(yyvsp[-1].node)->code;
                                
                                }
#line 5628 "parser.tab.c"
    break;

  case 250: /* l_arglist_r_maybe: %empty  */
#line 2293 "parser.y"
                                    {(yyval.node)=createNode("l_arglist_r_maybe", "", {});}
#line 5634 "parser.tab.c"
    break;

  case 251: /* arglist: argument comm_arg COMMA  */
#line 2295 "parser.y"
                                 {
                                    Node *n1=createNode("Delimiter", ",", {});
                                    (yyval.node)=createNode("arglist", "", {(yyvsp[-2].node), (yyvsp[-1].node), n1}); 
                                    (yyval.node)->Sym_list.push_back((yyvsp[-2].node)->sym);
                                    // $$->Sym_list=$2->Sym_list; 
                                    for(auto &it:(yyvsp[-1].node)->Sym_list) (yyval.node)->Sym_list.push_back(it);
                                    (yyval.node)->code=(yyvsp[-2].node)->code;
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[-1].node)->code.begin(), (yyvsp[-1].node)->code.end());
                                    }
#line 5648 "parser.tab.c"
    break;

  case 252: /* arglist: argument comm_arg  */
#line 2304 "parser.y"
                            {(yyval.node)=createNode("arglist", "", {(yyvsp[-1].node), (yyvsp[0].node)});
                            (yyval.node)->Sym_list.push_back((yyvsp[-1].node)->sym);
                                    // $$->Sym_list=$2->Sym_list; 
                                    for(auto &it:(yyvsp[0].node)->Sym_list) (yyval.node)->Sym_list.push_back(it);
                            (yyval.node)->code=(yyvsp[-1].node)->code;
                            (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                            }
#line 5660 "parser.tab.c"
    break;

  case 253: /* comm_arg: comm_arg COMMA argument  */
#line 2311 "parser.y"
                                  {
                                    (yyval.node)=createNode("comm_arg", "", {});
                                    (yyval.node)->Sym_list.insert((yyval.node)->Sym_list.end(),(yyvsp[-2].node)->Sym_list.begin(),(yyvsp[-2].node)->Sym_list.end());
                                    Node *n1=createNode("Delimiter", ",", {});
                                    (yyval.node)->code=(yyvsp[-2].node)->code;
                                    (yyval.node)->children.push_back(n1);
                                    (yyval.node)->children.push_back((yyvsp[0].node));
                                    (yyval.node)->Sym_list.push_back((yyvsp[0].node)->sym);
                                    (yyval.node)->code.insert((yyval.node)->code.end(), (yyvsp[0].node)->code.begin(), (yyvsp[0].node)->code.end());
                                    }
#line 5675 "parser.tab.c"
    break;

  case 254: /* comm_arg: %empty  */
#line 2321 "parser.y"
          {(yyval.node)=createNode("comm_arg", "", {});}
#line 5681 "parser.tab.c"
    break;

  case 255: /* argument: test comp_for  */
#line 2322 "parser.y"
                         {(yyval.node)=createNode("argument", "", {(yyvsp[-1].node), (yyvsp[0].node)});}
#line 5687 "parser.tab.c"
    break;

  case 256: /* argument: test  */
#line 2323 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); 
            // cout<<"argument\n";
                int flag=0; 
                string type; 
                for(auto &i:(yyvsp[0].node)->Sym_list){
                    if (i==NULL) continue;
                    if(flag==0){
                        type = i->type;
                        flag=1;
                    }
                    if(i->type != type) yyerror("Type mismatch");
                    if (i->type=="id" && curr->look_up(i->lexeme)==NULL){
                        yyerror("Not declared");
                    }
                }

                string op="push_param";
                quad* q = new quad("", (yyvsp[0].node)->res, op, ""); 
                q->make_code_push_param();
                // cout<<"is_print_string"<<is_print_string<<" "<<type<<endl;
                if(is_print_string && type!="string"){
                (yyval.node)->code.push_back(q); reverse((yyval.node)->code.begin(),(yyval.node)->code.end());}
                else if(!is_print_string){
                    (yyval.node)->code.push_back(q);
                    reverse((yyval.node)->code.begin(),(yyval.node)->code.end());
                     
                }
                ircode.push_back(q);
                // cout<<"arg done\n"<<q->code<<endl;
                }
#line 5722 "parser.tab.c"
    break;

  case 257: /* argument: test EQUALS test  */
#line 2353 "parser.y"
                           { Node *n1=createNode("Equals", "=", {}); (yyval.node)=createNode("argument", "", {(yyvsp[-2].node), n1, (yyvsp[0].node)});}
#line 5728 "parser.tab.c"
    break;

  case 258: /* argument: POW test  */
#line 2354 "parser.y"
                   { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("argument", "", {n1, (yyvsp[0].node)});}
#line 5734 "parser.tab.c"
    break;

  case 259: /* argument: TIMES test  */
#line 2355 "parser.y"
                     { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("argument", "", {n1, (yyvsp[0].node)});}
#line 5740 "parser.tab.c"
    break;

  case 260: /* comp_iter: comp_for  */
#line 2357 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 5746 "parser.tab.c"
    break;

  case 261: /* comp_iter: comp_if  */
#line 2357 "parser.y"
                                     {(yyval.node)=(yyvsp[0].node);}
#line 5752 "parser.tab.c"
    break;

  case 262: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 2358 "parser.y"
                                                 { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    (yyval.node)=createNode("sync_comp_for", "", {n1, (yyvsp[-3].node), n2, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5760 "parser.tab.c"
    break;

  case 263: /* sync_comp_for: FOR exprlist IN or_test  */
#line 2361 "parser.y"
                          { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    (yyval.node)=createNode("sync_comp_for", "", {n1, (yyvsp[-2].node), n2, (yyvsp[0].node)});}
#line 5768 "parser.tab.c"
    break;

  case 264: /* comp_for: ASYNC sync_comp_for  */
#line 2364 "parser.y"
                              { Node *n1=createNode("KEYWORD", "ASYNC", {}); 
                                (yyval.node)=createNode("comp_for", "", {n1, (yyvsp[0].node)});}
#line 5775 "parser.tab.c"
    break;

  case 265: /* comp_for: sync_comp_for  */
#line 2366 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 5781 "parser.tab.c"
    break;

  case 266: /* comp_if: IF or_test comp_iter  */
#line 2367 "parser.y"
                              { Node *n1=createNode("KEYWORD", "IF", {}); 
                                (yyval.node)=createNode("comp_if", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5788 "parser.tab.c"
    break;

  case 267: /* comp_if: IF or_test  */
#line 2369 "parser.y"
                                              { Node *n1=createNode("KEYWORD", "IF", {}); 
                                (yyval.node)=createNode("comp_if", "", {n1, (yyvsp[0].node)});}
#line 5795 "parser.tab.c"
    break;

  case 268: /* func_body_suite: simple_stmt  */
#line 2375 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 5801 "parser.tab.c"
    break;

  case 269: /* func_body_suite: NEWLINE INDENT stmt_morethanone DEDENT  */
#line 2375 "parser.y"
                                                                              {
    // cout<<"abort-1\n";
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    (yyval.node)=createNode("func_body_suite","",{n1,n2,(yyvsp[-1].node),n3}); (yyval.node)->code=(yyvsp[-1].node)->code;
}
#line 5811 "parser.tab.c"
    break;

  case 270: /* func_type_input: func_type nls ENDMARKER  */
#line 2381 "parser.y"
                                         {
    Node * n1=createNode("Endmarker","<<EOF>>",{}); (yyval.node)=createNode("func_type_input","",{(yyvsp[-2].node),(yyvsp[-1].node),n1});
}
#line 5819 "parser.tab.c"
    break;

  case 271: /* nls: nls NEWLINE  */
#line 2384 "parser.y"
                 {(yyval.node)=(yyvsp[-1].node); Node *n1 = createNode("Newline","nl",{}); (yyval.node)->children.push_back(n1);}
#line 5825 "parser.tab.c"
    break;

  case 272: /* nls: %empty  */
#line 2384 "parser.y"
                                                                                                 {(yyval.node)=createNode("nls", "", {});}
#line 5831 "parser.tab.c"
    break;

  case 273: /* func_type: LPAREN typelist RPAREN R_ARR test  */
#line 2385 "parser.y"
                                             { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-3].node), n2, n3, (yyvsp[0].node)});}
#line 5840 "parser.tab.c"
    break;

  case 274: /* func_type: LPAREN RPAREN R_ARR test  */
#line 2389 "parser.y"
                                   { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                (yyval.node)=createNode("func_type", "", {n1, n2, n3, (yyvsp[0].node)});}
#line 5849 "parser.tab.c"
    break;

  case 275: /* typelist: test comm_test comma_typel_maybe  */
#line 2394 "parser.y"
                                           {(yyval.node)=createNode("typelist", "", {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5855 "parser.tab.c"
    break;

  case 276: /* typelist: TIMES test comm_test comma_pow_test_maybe  */
#line 2395 "parser.y"
                                                  { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5861 "parser.tab.c"
    break;

  case 277: /* typelist: TIMES comm_test comma_pow_test_maybe  */
#line 2396 "parser.y"
                                            { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5867 "parser.tab.c"
    break;

  case 278: /* typelist: POW test  */
#line 2397 "parser.y"
                { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("func_type", "", {n1, (yyvsp[0].node)});}
#line 5873 "parser.tab.c"
    break;

  case 279: /* comma_typel_maybe: COMMA type_l  */
#line 2398 "parser.y"
                                { Node *n1=createNode("Delimiter", ",", {}); (yyval.node)=createNode("comma_typel_maybe", "", {n1, (yyvsp[0].node)});}
#line 5879 "parser.tab.c"
    break;

  case 280: /* comma_typel_maybe: COMMA  */
#line 2399 "parser.y"
                        { (yyval.node)=createNode("Delimiter", ",", {});}
#line 5885 "parser.tab.c"
    break;

  case 281: /* comma_typel_maybe: %empty  */
#line 2399 "parser.y"
                                                                 {(yyval.node)=createNode("comma_typel_maybe", "", {});}
#line 5891 "parser.tab.c"
    break;

  case 282: /* type_l: TIMES test comm_test comma_pow_test_maybe  */
#line 2400 "parser.y"
                                                  { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5897 "parser.tab.c"
    break;

  case 283: /* type_l: TIMES comm_test comma_pow_test_maybe  */
#line 2401 "parser.y"
                                               { Node *n1=createNode("Operator", "*", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[-1].node), (yyvsp[0].node)});}
#line 5903 "parser.tab.c"
    break;

  case 284: /* type_l: POW test  */
#line 2402 "parser.y"
                   { Node *n1=createNode("Operator", "**", {}); (yyval.node)=createNode("type_l", "", {n1, (yyvsp[0].node)});}
#line 5909 "parser.tab.c"
    break;

  case 285: /* comma_pow_test_maybe: COMMA POW test  */
#line 2403 "parser.y"
                                     {Node *n1=createNode("Delimiter",",",{});Node *n2=createNode("Operator","*",{});(yyval.node)=createNode("comma_pow_test_maybe","",{n1,n2,(yyvsp[0].node)});}
#line 5915 "parser.tab.c"
    break;

  case 286: /* comma_pow_test_maybe: %empty  */
#line 2403 "parser.y"
                                                                                                                                                                            {(yyval.node)=createNode("comma_pow_test_maybe","",{});}
#line 5921 "parser.tab.c"
    break;


#line 5925 "parser.tab.c"

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
#line 2404 "parser.y"





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
    cout << "-o, --output <output_file_name>\t\t\t Redirect x86 file to output file\n";
    cout << "-v, --verbose \t\t\t\t\t Outputs the entire derivation in command line\n";
    return;
}


int main (int argc, char *argv[]) {
    bool verbose=false;
    if(argc==1){
        cout<<"Incorrect no of arguments"<<endl;
        return -1;
    }
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
    // generateDotFile(output_file);
    
    fclose(program);
    return 1;
}
