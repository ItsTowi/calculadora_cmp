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

"PI"                        { return PI; }
"E"                         { return E; }
"BIN"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "bin"; return BIN; }
"HEX"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "hex"; return HEX; }
"OCT"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "oct"; return OCT; }

"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }
"sin"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "sin"; return SIN; }
"cos"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "cos"; return COS; }
"tan"                       { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "tan"; return TAN; }
"len"                       { return LEN; }
"substr"                    { return SUBSTR; }

[a-zA-Z][a-zA-Z0-9]*        { 
                              yylval.expr_val.name = (char*)malloc(sizeof(char)*yyleng+1);
                              strncpy(yylval.expr_val.name, yytext, yyleng); 


                              value_info aux;
                              if (sym_lookup(yytext, &aux) == SYMTAB_NOT_FOUND){
                                return ID;
                              } 
                              else 
                              {  
                                if (aux.val_type == BOOLEAN_TYPE) return B_ID;
                                else return A_ID;
                              }
                              
                              printf("Token ID: %s\n",yytext);
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


">"                         { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = ">"; return OPRELACIONAL; }
">="                        { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = ">="; return OPRELACIONAL; }
"<"                         { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "<"; return OPRELACIONAL; }
"<="                        { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "<="; return OPRELACIONAL; }
"="                         { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "="; return OPRELACIONAL; }
"<>"                        { yylval.expr_val.val_type = STRING; yylval.expr_val.value.val_string = "<>"; return OPRELACIONAL; }


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

