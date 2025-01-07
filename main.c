#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

FILE *logout; // Archivo externo para el log

int main(int argc, char *argv[])
{
  int error;

  if (argc == 4) {

    logout = fopen(argv[3], "w");
    if (!logout) {
      printf("The log file %s can not be created\n", argv[3]);
      return EXIT_FAILURE;
    }
    fprintf(logout, "Compilation log started.\n");

    
    error = init_analisi_lexica(argv[1]);
    if (error == EXIT_SUCCESS) {
      fprintf(logout, "Lexical analysis initialized successfully.\n");

      // Inicializar el archivo de salida (segundo argumento)
      error = init_analisi_sintactica(argv[2]);
      if (error == EXIT_SUCCESS) {
        fprintf(logout, "Syntactic analysis initialized successfully.\n");

        // Realizar el análisis semántico
        error = analisi_semantica();
        if (error == EXIT_SUCCESS) {
          fprintf(logout, "Semantic analysis completed successfully.\n");
          printf("The compilation has been successful\n");
        } else {
          fprintf(logout, "Semantic analysis failed.\n");
          printf("ERROR\n");
        }

        // Finalizar el archivo de salida
        error = end_analisi_sintactica();
        if (error == EXIT_FAILURE) {
          fprintf(logout, "Failed to close the output file.\n");
          printf("The output file can not be closed\n");
        }
      } else {
        fprintf(logout, "Failed to initialize syntactic analysis.\n");
        printf("The output file %s can not be created\n", argv[2]);
      }

      // Finalizar el archivo de entrada
      error = end_analisi_lexica();
      if (error == EXIT_FAILURE) {
        fprintf(logout, "Failed to close the input file.\n");
        printf("The input file can not be closed\n");
      }
    } else {
      fprintf(logout, "Failed to initialize lexical analysis.\n");
      printf("The input file %s can not be opened\n", argv[1]);
    }

    fprintf(logout, "Compilation log closed.\n"); // Escribir cierre en el log
    fclose(logout); // Cerrar el archivo de log
  } else {
    printf("\nUsage: %s INPUT_FILE OUTPUT_FILE LOG_FILE\n", argv[0]);
  }

  return EXIT_SUCCESS;
}
