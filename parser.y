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
    struct {
        char *lexema;
        int lenght;
        int line;
        value_info id_val;
    } ident;
    int enter;
    float real;
    value_info expr_val;
    void *sense_valor;
    char *cadena;
}

%token <sense_valor> ASSIGN ENDLINE
%token <enter> INTEGER
%token <real> FLOAT
%token <cadena> STRING
%token <ident> ID

%type <sense_valor> programa
%type <expr_val> expressio

%start programa

%%

programa : expressio ENDLINE { // Cambia a expressio seguido de un ENDLINE
    //fprintf(yyout, "Fin del programa\n");
}
        | programa expressio ENDLINE { // Para permitir múltiples expresiones
            //fprintf(yyout, "Fin del programa\n");
        }

expressio : ID ASSIGN FLOAT {
              fprintf(yyout, "ID: %s pren per valor: %f\n", $1.lexema, $3);
              $$.val_type = FLOAT_TYPE; // Asegúrate de que FLOAT_TYPE esté definido
              $$.val_float = $3;
            }
          | ID ASSIGN INTEGER {
              fprintf(yyout, "ID: %s pren per valor: %d\n", $1.lexema, $3);
              $$.val_type = INT_TYPE; // Asegúrate de que INT_TYPE esté definido
              $$.val_int = $3; // Suponiendo que tienes un campo para enteros
            }
          | ID ASSIGN STRING {
              fprintf(yyout, "ID: %s pren per valor: %s\n", $1.lexema, $3);
              $$.val_type = STRING_TYPE;
              strncpy($$.val_string, $3, STR_MAX_LENGTH - 1); // Copiar la cadena
              $$.val_string[STR_MAX_LENGTH - 1] = '\0'; 
            }
          ;
%%
