%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyout;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/

%}

%code requires {
  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "datos.h"
  #include "funciones.h"
}

%union{
    value_info expr_val;
}

%token ASSIGN ONELINECMNT MULTILINECMNT EOL
%token <expr_val> ID INTEGER FLOAT STRING BOOLEAN ADD SUB MULT DIV MOD POW LPAREN RPAREN
%type <expr_val> declaracion lista_declaraciones exp aritmetica booleana termino factor primario

%start programa

%%

programa : lista_declaraciones;

lista_declaraciones: lista_declaraciones declaracion | declaracion;

declaracion: ID ASSIGN exp EOL {
                                  //fprintf("Una expresión de tipo: %s\n", type_to_str($3.val_type));
                                  if ($3.val_type == UNKNOWN_TYPE) {
                                    yyerror($3.value.val_string);
                                  } else {
                                    fprintf(yyout, "ID: %s pren per valor: %s\n", $1.name, valueToString($3));
                                    //yylineno++;
                                  }
                                }
              | ONELINECMNT {
                              fprintf(yyout, "COMENTARIO DE UNA LINEA EN LA LINEA %d\n", yylineno - 1);
                              //yylineno++;
                            }
              | MULTILINECMNT {
                                fprintf(yyout, "COMENTARIO DE MULTIPLES LINEAS %d\n", yylineno - 1);
                              };

exp: aritmetica | booleana;

aritmetica: termino | aritmetica ADD termino  {
                                                $$ = sumaAritmetica($1, $3);
                                              } 
                    | aritmetica SUB termino  {
                                                $$ = restaAritmetica($1, $3);
                                              };

termino: factor | termino MULT factor {
                                        $$ = multAritmetica($1, $3);
                                      } 
                | termino DIV factor  {
                                        $$ = divAritmetica($1, $3);
                                      }
                | termino MOD factor  {
                                        $$ = modAritmetica($1, $3);
                                      };

factor: primario | factor POW primario  {
                                          $$ = potAritmetica($1, $3);
                                        };

primario: INTEGER 
          | FLOAT 
          | STRING 
          | ID 
          | LPAREN aritmetica RPAREN  {
                                          $$ = $2;
                                      };

booleana: BOOLEAN {
        $$ = $1;
        $$.val_type = BOOLEAN_TYPE;
      };

%%
