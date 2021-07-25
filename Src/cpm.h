/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
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


/* Line 2058 of yacc.c  */
#line 141 "y.tab.h"
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
