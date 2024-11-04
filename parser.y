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

%token ASSIGN EOL
%token <expr_val> ID INTEGER FLOAT STRING BOOLEAN
%type <expr_val> declaracion lista_declaraciones exp aritmetica booleana

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
                                  }
                                };

exp: aritmetica | booleana;

aritmetica: INTEGER {
          $$ = $1;
          $$.val_type = INT_TYPE;
      }
    | FLOAT {
          $$ = $1;
          $$.val_type = FLOAT_TYPE;
      }
    | STRING {
          $$ = $1;
          $$.val_type = STRING_TYPE;
      }
    | ID {
          // Aquí podrías buscar el ID en tu tabla de símbolos para determinar el tipo
          $$.val_type = UNKNOWN_TYPE; // Actualiza esto según tu lógica
      };


booleana: BOOLEAN {
        $$ = $1;
        $$.val_type = BOOLEAN_TYPE;
      };

%%
