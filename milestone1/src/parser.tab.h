/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    DELIMITER = 259,               /* DELIMITER  */
    FLOATING_POINT = 260,          /* FLOATING_POINT  */
    NUMBER = 261,                  /* NUMBER  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    TYPE = 264,                    /* TYPE  */
    STR_LIT = 265,                 /* STR_LIT  */
    BYT_LIT = 266,                 /* BYT_LIT  */
    STR = 267,                     /* STR  */
    LIST = 268,                    /* LIST  */
    FLOAT = 269,                   /* FLOAT  */
    BOOL = 270,                    /* BOOL  */
    EQUALS = 271,                  /* EQUALS  */
    PLUS = 272,                    /* PLUS  */
    MINUS = 273,                   /* MINUS  */
    TIMES = 274,                   /* TIMES  */
    DIVIDEDBY = 275,               /* DIVIDEDBY  */
    NEWLINE = 276,                 /* NEWLINE  */
    MOD = 277,                     /* MOD  */
    MODULO = 278,                  /* MODULO  */
    AUGPLUS = 279,                 /* AUGPLUS  */
    AUGMINUS = 280,                /* AUGMINUS  */
    AUGTIMES = 281,                /* AUGTIMES  */
    AUGDIVIDEDBY = 282,            /* AUGDIVIDEDBY  */
    AUGMOD = 283,                  /* AUGMOD  */
    AUGMODULO = 284,               /* AUGMODULO  */
    POW = 285,                     /* POW  */
    AUGPOW = 286,                  /* AUGPOW  */
    BIT_AND = 287,                 /* BIT_AND  */
    BIT_OR = 288,                  /* BIT_OR  */
    BIT_XOR = 289,                 /* BIT_XOR  */
    BIT_NOT = 290,                 /* BIT_NOT  */
    BIT_RSHIFT = 291,              /* BIT_RSHIFT  */
    BIT_LSHIFT = 292,              /* BIT_LSHIFT  */
    AUGBIT_AND = 293,              /* AUGBIT_AND  */
    AUGBIT_OR = 294,               /* AUGBIT_OR  */
    AUGBIT_XOR = 295,              /* AUGBIT_XOR  */
    AUGBIT_NOT = 296,              /* AUGBIT_NOT  */
    AUGBIT_RSHIFT = 297,           /* AUGBIT_RSHIFT  */
    AUGBIT_LSHIFT = 298,           /* AUGBIT_LSHIFT  */
    LPAREN = 299,                  /* LPAREN  */
    RPAREN = 300,                  /* RPAREN  */
    COMMA = 301,                   /* COMMA  */
    DOT = 302,                     /* DOT  */
    COLON = 303,                   /* COLON  */
    SEMICOLON = 304,               /* SEMICOLON  */
    LLIST = 305,                   /* LLIST  */
    RLIST = 306,                   /* RLIST  */
    R_ARR = 307,                   /* R_ARR  */
    EQ = 308,                      /* EQ  */
    NEQ = 309,                     /* NEQ  */
    GT = 310,                      /* GT  */
    GTE = 311,                     /* GTE  */
    LT = 312,                      /* LT  */
    LTE = 313,                     /* LTE  */
    HEX = 314,                     /* HEX  */
    INT = 315,                     /* INT  */
    AWAIT = 316,                   /* AWAIT  */
    LEN = 317,                     /* LEN  */
    AND = 318,                     /* AND  */
    BREAK = 319,                   /* BREAK  */
    DEF = 320,                     /* DEF  */
    ELIF = 321,                    /* ELIF  */
    ELSE = 322,                    /* ELSE  */
    FOR = 323,                     /* FOR  */
    IF = 324,                      /* IF  */
    ENDMARKER = 325,               /* ENDMARKER  */
    RANGE = 326,                   /* RANGE  */
    NOT = 327,                     /* NOT  */
    OR = 328,                      /* OR  */
    RETURN = 329,                  /* RETURN  */
    WHILE = 330,                   /* WHILE  */
    INDENT = 331,                  /* INDENT  */
    DEDENT = 332,                  /* DEDENT  */
    NONE = 333,                    /* NONE  */
    IS = 334,                      /* IS  */
    IN = 335,                      /* IN  */
    CONTINUE = 336,                /* CONTINUE  */
    ASSERT = 337,                  /* ASSERT  */
    NONLOCAL = 338,                /* NONLOCAL  */
    GLOBAL = 339,                  /* GLOBAL  */
    CLASS = 340,                   /* CLASS  */
    ASYNC = 341,                   /* ASYNC  */
    IMPORT = 342,                  /* IMPORT  */
    PASS = 343,                    /* PASS  */
    EXCEPT = 344,                  /* EXCEPT  */
    RAISE = 345,                   /* RAISE  */
    FINALLY = 346,                 /* FINALLY  */
    LAMBDA = 347,                  /* LAMBDA  */
    TRY = 348,                     /* TRY  */
    AS = 349,                      /* AS  */
    FROM = 350,                    /* FROM  */
    DEL = 351,                     /* DEL  */
    WITH = 352,                    /* WITH  */
    YIELD = 353                    /* YIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

  std::string* str;
  int token;
  Node * node;

#line 168 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
