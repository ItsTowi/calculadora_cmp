%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "funciones.h"

extern FILE *log_file;

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
                              fprintf(log_file,"Token BOOLEAN TRUE at line %d\n", yylineno - 1);
                              return BOOLEAN;
                            }

"false"                     {
                              yylval.expr_val.val_type = BOOLEAN_TYPE;
                              yylval.expr_val.value.val_boolean = 0;
                              fprintf(log_file,"Token BOOLEAN FALSE at line %d\n", yylineno - 1);
                              return BOOLEAN;
                            }

"PI"                        { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return PI; }
"E"                         { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return E; }
"BIN"                       { 
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "bin"; return BIN; 
                            }
"HEX"                       {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "hex"; return HEX; 
                            }
"OCT"                       { 
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "oct"; return OCT; 
                            }

"and"                       { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return AND; }
"or"                        { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return OR; }
"not"                       { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return NOT; }
"sin"                       {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "sin"; return SIN; 
                            }
"cos"                       { 
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "cos"; return COS; 
                            }
"tan"                       { 
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "tan"; return TAN; 
                            }
"len"                       { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return LEN; }
"substr"                    { fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); return SUBSTR; }

[a-zA-Z][a-zA-Z0-9]*        { 
                              yylval.expr_val.name = (char*)malloc(sizeof(char)*yyleng+1);
                              strncpy(yylval.expr_val.name, yytext, yyleng);


                              value_info aux;
                              if (sym_lookup(yytext, &aux) == SYMTAB_NOT_FOUND){
                                fprintf(log_file,"Token ID at line %d\n", yylineno - 1);
                                return ID;
                              } 
                              else 
                              {  
                                if (aux.val_type == BOOLEAN_TYPE){
                                  fprintf(log_file,"Token B_ID at line %d\n", yylineno - 1);
                                  return B_ID;
                                } else {
                                  fprintf(log_file,"Token A_ID at line %d\n", yylineno - 1);
                                  return A_ID;
                                }
                              }
                            }

":="                        { 
                              fprintf(log_file,"Token ASSIGN at line %d\n", yylineno - 1); return ASSIGN; 
                            }

","                         { fprintf(log_file,"Token COMMA at line %d\n", yylineno - 1); return COMMA; }
"+"                         { fprintf(log_file, "Token SUMA at line %d\n",yylineno - 1); return ADD; }
"-"                         { fprintf(log_file,"Token SUB at line %d\n", yylineno - 1); return SUB; }
"*"                         { fprintf(log_file,"Token MULT at line %d\n", yylineno - 1);  return MULT; }
"/"                         { fprintf(log_file,"Token DIV at line %d\n", yylineno - 1); return DIV; }
"%"                         { fprintf(log_file,"Token MOD at line %d\n", yylineno - 1);  return MOD; }
"**"                        { fprintf(log_file,"Token POW at line %d\n", yylineno - 1); return POW; }
"("                         { fprintf(log_file,"Token LPAREN at line %d\n", yylineno - 1);  return LPAREN; }
")"                         { fprintf(log_file,"Token RPAREN at line %d\n", yylineno - 1);  return RPAREN; }


">"                         {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">"; return OPRELACIONAL; 
                            }
">="                        {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">="; return OPRELACIONAL;
                            }
"<"                         {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<"; return OPRELACIONAL;
                            }
"<="                        {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<="; return OPRELACIONAL;
                            }
"="                         {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "="; return OPRELACIONAL;
                            }
"<>"                        {
                              fprintf(log_file,"Token %s at line %d\n",yytext, yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<>"; return OPRELACIONAL; 
                            }


{digit}({digit})*           {
                              yylval.expr_val.value.val_int = atoi(yytext);
                              yylval.expr_val.val_type = INT_TYPE;
                              fprintf(log_file,"Token INTEGER at line %d\n", yylineno - 1);
                              return INTEGER;
                            }


{float}({float})*           {
                              yylval.expr_val.value.val_float = atof(yytext);
                              yylval.expr_val.val_type = FLOAT_TYPE;
                              fprintf(log_file,"Token FLOAT at line %d\n", yylineno - 1);
                              return FLOAT;
                            }

{string}                    {
                              // Asegúrate de que la longitud de yytext no exceda STR_MAX_LENGTH
                              yylval.expr_val.val_type = STRING_TYPE;
                              int len = yyleng-2;
                              yylval.expr_val.value.val_string = (char*)malloc(sizeof(char)*len+1);
                              strncpy(yylval.expr_val.value.val_string, yytext+1, len);

                              fprintf(log_file,"Token STRING at line %d\n", yylineno - 1);
                              return STRING;
                            }

"\n"                        { 
                              fprintf(log_file,"Token EOL at line %d\n \n", yylineno - 1);
                              return EOL;
                            }
"\t"                        {}
"\r"                        {}
" "                         {}
.                           { fprintf(stderr, "Carácter inesperado: '%s' en línea %d\n", yytext, yylineno);}



"//".*"\n"                  { fprintf(log_file,"Token INTEGER at line %d\n", yylineno - 1); return ONELINECMNT; }


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

