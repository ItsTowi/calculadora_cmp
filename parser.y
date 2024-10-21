%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin; // Asegúrate de que esta línea esté presente
#include "datos.h"

void yyerror(const char *s);
int yylex();
%}

%union {
    int val_int;
    char* val_string;
}

%token <val_int> INT
%token <val_string> ID
%token ASSIGN

%%

// Definición de la gramática
program:
    statement
;

statement:
    ID ASSIGN INT {
        printf("Asignación: %s := %d\n", $1, $3);
    }
;

%%

// Función para manejar errores
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    FILE *input_file;

    if (argc > 1) {
        input_file = fopen(argv[1], "r");
        if (!input_file) {
            perror("Error abriendo el archivo");
            return EXIT_FAILURE;
        }
        yyin = input_file; // Asigna el archivo de entrada
    } else {
        yyin = stdin; // Si no se proporciona archivo, lee de la entrada estándar
    }

    yyparse(); // Llamar al parser de Bison
    fclose(input_file);
    return EXIT_SUCCESS;
}
