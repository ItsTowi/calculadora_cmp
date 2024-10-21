#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *input_file = fopen(argv[1], "r");
        if (!input_file) {
            fprintf(stderr, "Error al abrir el archivo: %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        yyin = input_file; // Asigna el archivo de entrada
    }

    yyparse(); // Llama al analizador sintáctico

    return EXIT_SUCCESS;
}