%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXLEN 100
#define SENTENCE_MAX_LENGTH 50

extern FILE *yyout;
extern int yylineno;
extern int yylex();
char *sentenciasC3A[MAXLEN];
int num_temportales = 1;
int sig_linea=1;
char* nou_temporal();
void addToMatrix(int args_count, ...);
void print_sentences();
/*extern void yyerror(char*);*/

%}

%code requires {
  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "datos.h"
  #include "symtab.h"
  #include "funciones.h"
}

%union{
    value_info expr_val;
}

%{
 void sumaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
%}
 

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL
%token <expr_val> ID A_ID B_ID INTEGER FLOAT STRING BOOLEAN PI E ADD SUB MULT DIV MOD POW SIN COS TAN LEN SUBSTR BIN HEX OCT AND OR NOT OPRELACIONAL LPAREN RPAREN
%type <expr_val> declaracion lista_declaraciones exp aritmetica booleana bool1 bool2 bool3 bool_aritmetic termino factor primario op_trig representacioNum

%start programa

%%

programa : lista_declaraciones{print_sentences();};

lista_declaraciones: lista_declaraciones declaracion | declaracion;

declaracion: ID ASSIGN exp EOL {
                                  //fprintf("Una expresión de tipo: %s\n", type_to_str($3.val_type));
                                  if ($3.val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror($3.value.val_string);
                                  } 
                                  else 
                                  {
                                    $1.val_type = $3.val_type;
                                    if (!($1.name == NULL)) {
                                      sym_enter($1.name, &$3);
                                    }
                                    fprintf(yyout, "ID: %s pren amb tipus %s per valor: %s\n", $1.name, type_to_str($1.val_type) ,valueToString($3));
                                  }
                                }
              | exp EOL         {
                                  if ($1.val_type == UNKNOWN_TYPE)
                                  {
                                    yyerror($1.value.val_string);
                                  }
                                  else
                                  {
                                    if ($1.name == NULL) fprintf(yyout, "Line %d, unsaved EXPRESSION with value %s and type %s\n", yylineno, valueToString($1), type_to_str($1.val_type));
										                else fprintf(yyout, "Line %d, EXPRESSION %s with value %s and type %s\n", yylineno, $1.name, valueToString($1), type_to_str($1.val_type));
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
                                                sumaArtimetica3AC(&$$,$1, "+", $3);

                                              }
                    | aritmetica SUB termino  {
                                                $$ = restaAritmetica($1, $3);
                                                restaArtimetica3AC(&$$,$1, "-", $3);
                                              };
                    | SUB termino             { $$ = cambioAritmetica($2); }
                    | ADD termino             { $$ = $2; };   

termino: factor | termino MULT factor {
                                        $$ = multAritmetica($1, $3);
                                        multiplicacionAritmetica3AC(&$$,$1, "*", $3);
                                      } 
                | termino DIV factor  {
                                        $$ = divAritmetica($1, $3);
                                        divisionAritmetica3AC(&$$,$1, "/", $3);
                                      }
                | termino MOD factor  {
                                        $$ = modAritmetica($1, $3);
                                      };

factor: primario 
        | factor POW primario          {
                                          $$ = potAritmetica($1, $3);
                                       };                        

primario: INTEGER                     {
                                        $1.name = NULL;
                                        $$ = $1;
                                      }
          | FLOAT                     {
                                        $$ = $1;
                                      }
          | STRING                    {
                                        printf("%s\n", type_to_str($1.val_type));
                                        $$ = $1;
                                      }
          | PI                        {
                                        $$ = constantePI();
                                      }
          | E                         {
                                        $$ = constanteE();
                                      }
          | ID                        {
                                          if(sym_lookup($1.name, &$1) == SYMTAB_NOT_FOUND) 
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
												                  else 
                                          { 
                                            $$.val_type = $1.val_type;
                                            $$.value =$1.value;
                                          }
                                      }
          | A_ID                        {
                                          if(sym_lookup($1.name, &$1) == SYMTAB_NOT_FOUND) 
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
												                  else 
                                          {
                                            $$.val_type = $1.val_type;
                                            $$.value =$1.value;
                                          }
                                      }
          | LPAREN aritmetica RPAREN  {
                                          $$ = $2;
                                      }
          | op_trig LPAREN aritmetica RPAREN { $$ = opTrigonometrica($1, $3); }
          | LEN LPAREN aritmetica RPAREN { $$ = calcularLen($3); }
          | SUBSTR LPAREN aritmetica COMMA INTEGER COMMA INTEGER RPAREN { $$ = substring($3, $5.value.val_int, $7.value.val_int); }
          | representacioNum LPAREN aritmetica RPAREN { $$ = representacioNum($1 ,$3); }

op_trig: SIN | COS | TAN;

representacioNum: BIN | HEX | OCT;

booleana: bool1 
          | booleana OR bool1         {
                                        $$ = orBooleana($1, $3);
                                      };

bool1: bool2 
      | bool1 AND bool2               {
                                        $$ = andBooleana($1,$3);
                                      };

bool2: bool3 
      | NOT bool2                     {
                                        $$ = notBooleana($2);
                                      };

bool3:  bool_aritmetic
        | LPAREN booleana RPAREN      {
                                        $$ = $2;
                                      }
        | BOOLEAN                     {
                                        $$ = $1;
                                      }
        | B_ID                        {
                                        if (sym_lookup($1.name, &$1) == SYMTAB_NOT_FOUND)
                                        {
                                          yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n");
                                        }
                                        else
                                        {
                                          $$.val_type = $1.val_type;
                                          $$.value = $1.value;
                                        }
                                      };

bool_aritmetic: aritmetica OPRELACIONAL aritmetica  {
                                                      //printf("%s\n", valueToString($1));
                                                      //printf("%d\n", $3.value.val_int);
                                                      $$ = opRelacional($1,$2,$3);
                                                    };

%%


char* nou_temporal(){
  char* buffer = (char *) malloc(sizeof(char)*3+sizeof(int));
  sprintf(buffer, "$t0%d", num_temportales);
  num_temportales++;
  return buffer;
}

void sumaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "+") == 0) {
            // Operación de suma
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "ADDF", v2_str);  // Suma flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "ADDI", v2_str);  // Suma entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "ADDF", v2_str);  // Suma flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "ADDI", v2_str);  // Suma entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}


void restaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "-") == 0) {
            // Operación de resta
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "SUBF", v2_str);  // Resta flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "SUBI", v2_str);  // Resta entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "SUBF", v2_str);  // Resta flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "SUBI", v2_str);  // Resta entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}

void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "*") == 0) {
            // Operación de multiplicación
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "MULF", v2_str);  // Multiplicación flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "MULI", v2_str);  // Multiplicación entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "MULF", v2_str);  // Multiplicación flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "MULI", v2_str);  // Multiplicación entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}

void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos si v1 y v2 son de tipos numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Comprobamos si el divisor (v2) es 0 para evitar la división por cero
        if ((v2.val_type == INT_TYPE && v2.value.val_int == 0) ||
            (v2.val_type == FLOAT_TYPE && v2.value.val_float == 0.0)) {
            // Imprimir un error de división por cero o manejarlo adecuadamente
            printf("Error: División por cero\n");
            return;
        }

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será un flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es un entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si v1.name es NULL, usamos el valor de v1
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);  // Convertimos a cadena el valor entero
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);  // Convertimos a cadena el valor flotante
            }
        } else {
            // Si v1.name no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si v2.name es NULL, usamos el valor de v2
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);  // Convertimos el valor entero
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);  // Convertimos el valor flotante
            }
        } else {
            // Si v2.name no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Generamos la instrucción según el tipo de operación
        if (strcmp(op, "/") == 0) {
            // Operación de división
            if (v1.place == NULL) {
                // Si v1.place es NULL, usamos su valor directamente
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "DIVF", v2_str);  // División flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "DIVI", v2_str);  // División entera
                }
            } else {
                // Si v1.place no es NULL, usamos su lugar
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "DIVF", v2_str);  // División flotante
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "DIVI", v2_str);  // División entera
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}



void addToMatrix(int args_count, ...) {
    va_list args;
    va_start(args, args_count);
    char* buffer = malloc(sizeof(char) * SENTENCE_MAX_LENGTH + 1);
    for (int i = 0; i < args_count; i++) {
        char* arg = va_arg(args, char*);
        strcat(buffer, arg);
        strcat(buffer, " ");  // Agregar espacio entre los argumentos
    }

    sentenciasC3A[sig_linea] = buffer;
    sig_linea++;

    printf("Matriz construida: %s\n", sentenciasC3A[sig_linea-1]);

    va_end(args);
}


void print_sentences(){
  int i;
  for (i=1; i < sig_linea; i++)
	fprintf(yyout, "%d:  %s\n", i, sentenciasC3A[i]);
  fprintf(yyout, "%d:  HALT\n", sig_linea);
}