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
float [0-9]*\.[0-9]+
string \"([^\\"]|\\.)*\"

%%


{lletra}({lletra}|{digit})* {
                              yylval.ident.lexema = strdup(yytext);
                              yylval.ident.lenght = yyleng;
                              yylval.ident.line = yylineno;
                              yylval.ident.id_val.val_type = UNKNOWN_TYPE;
                              return ID;
                            }

":="                         { return ASSIGN; }

{digit}({digit})*           {
                              yylval.enter = atoi(yytext);
                              return INTEGER;
                            }


{float}({float})*           {
                              yylval.real = atof(yytext);
                              return FLOAT;
                            }

{string}                    {
                              yylval.cadena = strdup(yytext);
                              printf("Token STRING: %s\n", yytext);
                              return STRING;
                            }

"\n"            { return EOL; }
"\t"            {}
"\r"            {}
" "             {}
.                           { fprintf(stderr, "Carácter inesperado: '%s' en línea %d\n", yytext, yylineno);}

%%

