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
espacio [ \t\r]

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

"..."                       { fprintf(log_file,"Token DOTS at line %d\n", yylineno - 1); return DOTS;}

"if"                        { fprintf(log_file,"Token IF at line %d\n", yylineno - 1); return IF;}
"then"                      { fprintf(log_file,"Token THEN at line %d\n", yylineno - 1); return THEN;}
"else"                      { fprintf(log_file,"Token ELSE at line %d\n", yylineno - 1); return ELSE;}
"fi"                        { fprintf(log_file,"Token FI at line %d\n", yylineno - 1); return FI;}
"while"                     { fprintf(log_file,"Token WHILE at line %d\n", yylineno - 1); return WHILE;}
"until"                     { fprintf(log_file,"Token UNTIL at line %d\n", yylineno - 1); return UNTIL;}
"for"                       { fprintf(log_file,"Token FOR at line %d\n", yylineno - 1); return FOR;}
"in"                        { fprintf(log_file,"Token IN at line %d\n", yylineno - 1); return IN ;}
".."                        { fprintf(log_file,"Token RANG at line %d\n", yylineno - 1); return RANG;}
"repeat"                    { fprintf(log_file,"Token REPEAT at line %d\n", yylineno - 1); return REPEAT; };
"do"                        { fprintf(log_file,"Token DO at line %d\n", yylineno - 1); return DO; };
"done"                      { fprintf(log_file,"Token DONE at line %d\n", yylineno - 1); return DONE; };

"and"                       { fprintf(log_file,"Token AND at line %d\n", yylineno - 1); return AND; }
"or"                        { fprintf(log_file,"Token OR at line %d\n", yylineno - 1); return OR; }
"not"                       { fprintf(log_file,"Token NOT at line %d\n", yylineno - 1); return NOT; }


[a-zA-Z][a-zA-Z0-9]*        { 
                              yylval.expr_val.name = (char*)malloc(sizeof(char)*yyleng+1);
                              strncpy(yylval.expr_val.name, yytext, yyleng);
                              yylval.expr_val.name[yyleng] = '\0';
                              
                              value_info aux;
                              if (sym_lookup(yytext, &aux) == SYMTAB_NOT_FOUND){
                                fprintf(log_file,"Token ID at line %d\n", yylineno - 1);
                                return ID;
                              } 
                              else 
                              { 
                                if (aux.val_type == BOOLEAN_TYPE)
                                { 
                                  fprintf(log_file,"Token B_ID at line %d\n", yylineno - 1); 
                                  return B_ID;
                                } 
                                else {
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
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1); 
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">"; return GT; 
                            }
">="                        { 
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = ">="; return GE;
                            }
"<"                         {
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<"; return LT;
                            }
"<="                        { 
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<="; return LE;
                            }
"="                         { 
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "="; return EQ;
                            }
"<>"                        { 
                              fprintf(log_file, "Token GT at line %d\n",yylineno - 1);
                              yylval.expr_val.val_type = STRING_TYPE; yylval.expr_val.value.val_string = "<>"; return NE;
                            }


{digit}({digit})*           {
                              yylval.expr_val.value.val_int = atoi(yytext);
                              yylval.expr_val.val_type = INT_TYPE;
                              yylval.expr_val.name = NULL;
                              fprintf(log_file,"Token INTEGER at line %d\n", yylineno - 1);
                              return INTEGER;
                            }


{float}({float})*           {
                              yylval.expr_val.value.val_float = atof(yytext);
                              yylval.expr_val.val_type = FLOAT_TYPE;
                              yylval.expr_val.name = NULL;
                              fprintf(log_file,"Token FLOAT at line %d\n", yylineno - 1);
                              return FLOAT;
                            }

"\n"                        { 
                              fprintf(log_file,"Token EOL at line %d\n \n", yylineno - 1);
                              return EOL;
                            }

{espacio}+                  {} /* eat up whitespaces */
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

