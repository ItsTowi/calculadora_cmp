#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern FILE *log_file;
extern int yylineno;


int init_analisi_lexica(char *filename)
{
  int error;
  yyin = fopen(filename,"r");
  if(yyin == NULL) {
    error = EXIT_FAILURE;
  } else {
    error = EXIT_SUCCESS;
  }
  return error;
}


int end_analisi_lexica()
{
  int error;
  error = fclose(yyin);
  if (error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}


int init_analisi_sintactica(char* filename)
{
  int error = EXIT_SUCCESS;
  yyout = fopen(filename,"w");
  if (yyout == NULL) {
    error = EXIT_FAILURE;
  }
  return error;
}


int end_analisi_sintactica(void)
{
  int error;

  error = fclose(yyout);

  if(error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}


int analisi_semantica(void)
{
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), yyin) != NULL) {
        //printf("Line: %s", buffer);  // Muestra cada línea leída
    }
    fseek(yyin, 0, SEEK_SET);  // Vuelve al inicio del archivo para el análisis
    
    if (yyparse() == 0) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}


void yyerror(char *explanation)
{
  fprintf(stderr, "Error: %s , in line %d\n", explanation, yylineno);
}

int init_log_file(char *filename) {
  log_file = fopen(filename, "w");
  if (log_file == NULL) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int close_log_file(void) {
  if (fclose(log_file) == 0) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}