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
/* "%code requires" blocks.  */
#line 24 "parser.y"

  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "datos.h"
  #include "symtab.h"
  #include "funciones.h"

#line 56 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    ONELINECMNT = 259,             /* ONELINECMNT  */
    MULTILINECMNT = 260,           /* MULTILINECMNT  */
    COMMA = 261,                   /* COMMA  */
    EOL = 262,                     /* EOL  */
    ID = 263,                      /* ID  */
    A_ID = 264,                    /* A_ID  */
    B_ID = 265,                    /* B_ID  */
    INTEGER = 266,                 /* INTEGER  */
    FLOAT = 267,                   /* FLOAT  */
    BOOLEAN = 268,                 /* BOOLEAN  */
    DOTS = 269,                    /* DOTS  */
    ADD = 270,                     /* ADD  */
    SUB = 271,                     /* SUB  */
    MULT = 272,                    /* MULT  */
    DIV = 273,                     /* DIV  */
    MOD = 274,                     /* MOD  */
    POW = 275,                     /* POW  */
    LPAREN = 276,                  /* LPAREN  */
    RPAREN = 277,                  /* RPAREN  */
    OPRELACIONAL = 278,            /* OPRELACIONAL  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    IF = 282,                      /* IF  */
    THEN = 283,                    /* THEN  */
    ELSE = 284,                    /* ELSE  */
    FI = 285,                      /* FI  */
    WHILE = 286,                   /* WHILE  */
    UNTIL = 287,                   /* UNTIL  */
    FOR = 288,                     /* FOR  */
    IN = 289,                      /* IN  */
    RANG = 290,                    /* RANG  */
    REPEAT = 291,                  /* REPEAT  */
    DONE = 292,                    /* DONE  */
    DO = 293                       /* DO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

    value_info expr_val;

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
