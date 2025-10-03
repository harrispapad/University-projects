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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_and = 258,                   /* "and"  */
    T_as = 259,                    /* "as"  */
    T_begin = 260,                 /* "begin"  */
    T_break = 261,                 /* "break"  */
    T_byte = 262,                  /* "byte"  */
    T_continue = 263,              /* "continue"  */
    T_decl = 264,                  /* "decl"  */
    T_def = 265,                   /* "def"  */
    T_elif = 266,                  /* "elif"  */
    T_else = 267,                  /* "else"  */
    T_end = 268,                   /* "end"  */
    T_exit = 269,                  /* "exit"  */
    T_false = 270,                 /* "false"  */
    T_if = 271,                    /* "if"  */
    T_is = 272,                    /* "is"  */
    T_int = 273,                   /* "int"  */
    T_loop = 274,                  /* "loop"  */
    T_not = 275,                   /* "not"  */
    T_or = 276,                    /* "or"  */
    T_ref = 277,                   /* "ref"  */
    T_return = 278,                /* "return"  */
    T_skip = 279,                  /* "skip"  */
    T_true = 280,                  /* "true"  */
    T_var = 281,                   /* "var"  */
    T_assign = 282,                /* ":="  */
    T_eq = 283,                    /* "="  */
    T_neq = 284,                   /* "<>"  */
    T_lt = 285,                    /* "<"  */
    T_gt = 286,                    /* ">"  */
    T_le = 287,                    /* "<="  */
    T_ge = 288,                    /* ">="  */
    T_plus = 289,                  /* "+"  */
    T_minus = 290,                 /* "-"  */
    T_times = 291,                 /* "*"  */
    T_div = 292,                   /* "/"  */
    T_mod = 293,                   /* "%"  */
    T_id = 294,                    /* T_id  */
    T_string = 295,                /* T_string  */
    T_intconst = 296,              /* T_intconst  */
    T_charconst = 297,             /* T_charconst  */
    UMINUS = 298,                  /* UMINUS  */
    UPLUS = 299                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    char* var;
    int num;
    char character;
    char* string;
    char* op;
    Stmt *stmt;
    SimpleStmt *simple_stmt;
    Expr *expr;
    L_val *l_val;
    ExprAux *expr_aux;
    FuncCall *func_call;
    Cond *cond;
    ProcCall *proc_call;
    IfAux *if_aux;
    StmtList *stmt_list;
    Block *block;
    Header *header;
    DataType data_type;
    Type *type;
    IdAux *id_aux;
    VarDef *var_def;
    ArrayType *array_type;
    FparType *fpar_type;
    FuncDecl *func_decl;
    FparDef *fpar_def;
    HeaderAux *header_aux;
    LocalDef *local_def;
    FuncDef *func_def;

#line 139 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
