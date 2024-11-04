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

lletra  [a-zA-Z]
digit   [0-9]
float [0-9]*\.[0-9]*([eE][-+]?[0-9]+)?
string \"([^\\"]|\\.)*\"

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

[a-zA-Z][a-zA-Z0-9]*        { 
                              yylval.expr_val.name = (char*)malloc(sizeof(char)*yyleng+1);
                              strncpy(yylval.expr_val.name, yytext, yyleng); 
                              printf("Token ID: %s\n",yytext);
                              return ID; 
                            }

":="                        { 
                              return ASSIGN; 
                            }

{digit}({digit})*           {
                              yylval.expr_val.value.val_int = atoi(yytext);
                              yylval.expr_val.val_type = INT_TYPE;
                              printf("Token INTEGER: %d\n", yylval.expr_val.value.val_int);
                              return INTEGER;
                            }


{float}({float})*           {
                              yylval.expr_val.value.val_float = atof(yytext);
                              yylval.expr_val.val_type = FLOAT_TYPE;
                              printf("Token FLOAT: %s\n", yytext);
                              return FLOAT;
                            }

{string}                    {
                              // Asegúrate de que la longitud de yytext no exceda STR_MAX_LENGTH
                              yylval.expr_val.val_type = STRING_TYPE;
                              int len = yyleng-2;
                              yylval.expr_val.value.val_string = (char*)malloc(sizeof(char)*len+1);
                              strncpy(yylval.expr_val.value.val_string, yytext+1, len);

                              printf("Token STRING: %s\n", yylval.expr_val.value.val_string);
                              return STRING;
                            }

"\n"                        { 
                              return EOL;
                            }
"\t"                        {}
"\r"                        {}
" "                         {}
.                           { fprintf(stderr, "Carácter inesperado: '%s' en línea %d\n", yytext, yylineno);}

%%

