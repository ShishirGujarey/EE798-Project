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
    NONE = 271,                    /* NONE  */
    EQUALS = 272,                  /* EQUALS  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    TIMES = 275,                   /* TIMES  */
    DIVIDEDBY = 276,               /* DIVIDEDBY  */
    NEWLINE = 277,                 /* NEWLINE  */
    MOD = 278,                     /* MOD  */
    MODULO = 279,                  /* MODULO  */
    AUGPLUS = 280,                 /* AUGPLUS  */
    AUGMINUS = 281,                /* AUGMINUS  */
    AUGTIMES = 282,                /* AUGTIMES  */
    AUGDIVIDEDBY = 283,            /* AUGDIVIDEDBY  */
    AUGMOD = 284,                  /* AUGMOD  */
    AUGMODULO = 285,               /* AUGMODULO  */
    POW = 286,                     /* POW  */
    AUGPOW = 287,                  /* AUGPOW  */
    BIT_AND = 288,                 /* BIT_AND  */
    BIT_OR = 289,                  /* BIT_OR  */
    BIT_XOR = 290,                 /* BIT_XOR  */
    BIT_NOT = 291,                 /* BIT_NOT  */
    BIT_RSHIFT = 292,              /* BIT_RSHIFT  */
    BIT_LSHIFT = 293,              /* BIT_LSHIFT  */
    AUGBIT_AND = 294,              /* AUGBIT_AND  */
    AUGBIT_OR = 295,               /* AUGBIT_OR  */
    AUGBIT_XOR = 296,              /* AUGBIT_XOR  */
    AUGBIT_NOT = 297,              /* AUGBIT_NOT  */
    AUGBIT_RSHIFT = 298,           /* AUGBIT_RSHIFT  */
    AUGBIT_LSHIFT = 299,           /* AUGBIT_LSHIFT  */
    LPAREN = 300,                  /* LPAREN  */
    RPAREN = 301,                  /* RPAREN  */
    COMMA = 302,                   /* COMMA  */
    DOT = 303,                     /* DOT  */
    COLON = 304,                   /* COLON  */
    SEMICOLON = 305,               /* SEMICOLON  */
    LLIST = 306,                   /* LLIST  */
    RLIST = 307,                   /* RLIST  */
    R_ARR = 308,                   /* R_ARR  */
    EQ = 309,                      /* EQ  */
    NEQ = 310,                     /* NEQ  */
    GT = 311,                      /* GT  */
    GTE = 312,                     /* GTE  */
    LT = 313,                      /* LT  */
    LTE = 314,                     /* LTE  */
    HEX = 315,                     /* HEX  */
    INT = 316,                     /* INT  */
    AWAIT = 317,                   /* AWAIT  */
    LEN = 318,                     /* LEN  */
    AND = 319,                     /* AND  */
    BREAK = 320,                   /* BREAK  */
    DEF = 321,                     /* DEF  */
    ELIF = 322,                    /* ELIF  */
    ELSE = 323,                    /* ELSE  */
    FOR = 324,                     /* FOR  */
    IF = 325,                      /* IF  */
    ENDMARKER = 326,               /* ENDMARKER  */
    RANGE = 327,                   /* RANGE  */
    NOT = 328,                     /* NOT  */
    OR = 329,                      /* OR  */
    RETURN = 330,                  /* RETURN  */
    WHILE = 331,                   /* WHILE  */
    INDENT = 332,                  /* INDENT  */
    DEDENT = 333,                  /* DEDENT  */
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
#line 48 "parser.y"

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
