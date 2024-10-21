%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

void yyerror(const char *s);
int yylex(void);

// Definir el tipo de datos que usará el parser
typedef union {
    int val_int;
    char* val_string;
} YYSTYPE;

value_info variables[STR_MAX_LENGTH]; // Arreglo de variables
int var_count = 0; // Contador de variables

value_info get_variable(const char *id);
void set_variable(const char *id, int value);
%}

%token <val_int> INT
%token <val_string> ID
%token ASSIGN

%%

// Reglas de la gramática
program:
    statements
;

statements:
    statement
    | statements statement
;

statement:
    ID ASSIGN INT { set_variable($1, $3); }
;

%%

// Funciones y errores (sin cambios)
