%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Asegúrate de incluir string.h para strdup
#include "exemple_dades.h" // Asegúrate de que este archivo existe y es correcto
int yylex(void);
void yyerror(const char *s);
%}

%option noyywrap

// Definición de los tokens
%token <val_int> INT
%token <val_string> ID
%token ASSIGN

%%

// Reglas del analizador léxico
[0-9]+                { yylval.val_int = atoi(yytext); return INT; } // Enteros
[a-zA-Z_][a-zA-Z0-9_]* { yylval.val_string = strdup(yytext); return ID; } // Identificadores
":="                  { return ASSIGN; } // Operador de asignación
[ \t\n]+             { /* Ignorar espacios y saltos de línea */ } // Ignorar espacios en blanco
.                    { printf("Carácter no reconocido: %s\n", yytext); } // Carácter no reconocido

%%

// Función para manejar errores
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
