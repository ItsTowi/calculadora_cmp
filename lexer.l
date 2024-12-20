%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "funciones.h"

%}

%option yylineno
%option noyywrap
%option noinput
%option nounput
%x IN_COMMENT

lletra  [a-zA-Z]
digit   [0-9]
float [0-9]*\.[0-9]*([eE][-+]?[0-9]+)?
espacio [ \t\r]

%%

"true"                      {
                              yylval.expr_val.val_type = BOOLEAN_TYPE;
                              yylval.expr_val.value.val_boolean = 1;
                              printf("Token BOOLEAN: %s\n",yytext);
                              return BOOLEAN;
                            }

"false"                     {
                              yylval.expr_val.val_type = BOOLEAN_TYPE;
                              yylval.expr_val.value.val_boolean = 0;
                              printf("Token BOOLEAN: %s\n",yytext);
                              return BOOLEAN;
                            }

"..."                       {return DOTS;}

"if"                        {printf("TOKEN IF:\n"); return IF;}
"then"                      {return THEN;}
"else"                      {return ELSE;}
"fi"                        {return FI;}
"while"                     {return WHILE;}
"until"                     {return UNTIL;}
"for"                       {return FOR;}
"in"                        {return IN ;}
".."                        {return RANG;}
"repeat"                    { printf("TOKEN REPEAT\n"); return REPEAT; };
"do"                        { printf("TOKEN DO\n"); return DO; };
"done"                      { printf("TOKEN DONE\n"); return DONE; };

"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }


[a-zA-Z][a-zA-Z0-9]*        { 
                              yylval.expr_val.name = (char*)malloc(sizeof(char)*yyleng+1);
                              strncpy(yylval.expr_val.name, yytext, yyleng);
                              yylval.expr_val.name[yyleng] = '\0';
                              
                              value_info aux;
                              if (sym_lookup(yytext, &aux) == SYMTAB_NOT_FOUND){
                                printf("Token ID: %s\n",yytext);
                                return ID;
                              } 
                              else 
                              { 
                                printf("Devuelve una variarble encontrada %s con valor %s\n", aux.name, valueToString(aux));
                                if (aux.val_type == BOOLEAN_TYPE) return B_ID;
                                else printf("Token A_ID: %s\n",yytext); return A_ID;
                              }
                            }

":="                        { 
                              return ASSIGN; 
                            }

","                         { return COMMA; }
"+"                         { printf("Token SUMA: %s\n",yytext); return ADD; }
"-"                         { return SUB; }
"*"                         { return MULT; }
"/"                         { return DIV; }
"%"                         { return MOD; }
"**"                        { return POW; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }

">"                         { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">"; return OPRELACIONAL; }
">="                        { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">="; return OPRELACIONAL; }
"<"                         { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<"; return OPRELACIONAL; }
"<="                        { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<="; return OPRELACIONAL; }
"="                         { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "="; return OPRELACIONAL; }
"<>"                        { yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<>"; return OPRELACIONAL; }


{digit}({digit})*           {
                              yylval.expr_val.value.val_int = atoi(yytext);
                              yylval.expr_val.val_type = INT_TYPE;
                              yylval.expr_val.name = NULL;
                              printf("Token INTEGER: %d\n", yylval.expr_val.value.val_int);
                              return INTEGER;
                            }


{float}({float})*           {
                              yylval.expr_val.value.val_float = atof(yytext);
                              yylval.expr_val.val_type = FLOAT_TYPE;
                              printf("Token FLOAT: %s\n", yytext);
                              return FLOAT;
                            }

"\n"                        { 
                              return EOL;
                            }

{espacio}+                  {} /* eat up whitespaces */
.                           { fprintf(stderr, "Carácter inesperado: '%s' en línea %d\n", yytext, yylineno);}



"//".*"\n"                  { 
                              return ONELINECMNT; 
                            }



<INITIAL>{
"/*"            BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"            BEGIN(INITIAL);
[^*\n]+                             /* eat comment in chunks */
"*"                                 /* eat the lone star */
\n    { return MULTILINECMNT;}
}


%%

