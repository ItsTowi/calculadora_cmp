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
char* temp_sq;
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
 value_info contador;
 void sumaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaArtimetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void addToMatrixSalotIncond(value_info s1, const char* operel, value_info s2, char* line2jump);
%}
 

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL;
%token <expr_val> ID A_ID B_ID INTEGER FLOAT ADD SUB MULT DIV MOD POW LPAREN RPAREN REPEAT DONE DO;
%type <expr_val> declaracion lista_declaraciones declaracion_simple declaracion_iterativa declaracion_iterativa_incondicional exp aritmetica termino factor primario M;

%start programa

%%

programa : lista_declaraciones{print_sentences();};

lista_declaraciones: lista_declaraciones declaracion | declaracion;

declaracion: declaracion_simple | declaracion_iterativa;

declaracion_simple: ID ASSIGN exp EOL {
                                  if ($3.val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror($3.value.val_string);
                                  } 
                                  else 
                                  {
                                    $1.val_type = $3.val_type;
                                    if (!($1.name == NULL)) {
                                      sym_enter($1.name, &$3);
                                      addToMatrix(3, $1.name, ":=", valueToString($3));
                                    }
                                  }
                                }
              | exp EOL         {
                                  if ($1.val_type == UNKNOWN_TYPE)
                                  {
                                    yyerror($1.value.val_string);
                                  }
                                }
              | ONELINECMNT     {

                                }
              | MULTILINECMNT   {
                                };
              | EOL             {};

exp: aritmetica;

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
                                        moduloAritmetica3AC(&$$,$1, "%", $3);
                                      };

factor: primario 
        | factor POW primario          {
                                          $$ = potAritmetica($1, $3);
                                          potenciaAritmetica3AC(&$$,$1, "**", $3);
                                       };                        

primario: INTEGER                     {
                                        $1.name = NULL;
                                        $$ = $1;
                                      }
          | FLOAT                     {
                                        $1.name = NULL;
                                        $$ = $1;
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


declaracion_iterativa: declaracion_iterativa_incondicional;

declaracion_iterativa_incondicional: REPEAT aritmetica DO M EOL lista_declaraciones DONE {

	addToMatrix(5, contador.place, ":=", contador.place, "ADDI", "1");
    printf("valor de aritmetica %s\n", $2.place);
	addToMatrixSalotIncond(contador, "LT", $2, temp_sq);
};


/* M contendrá la información del contador del bucle y guardará la línea donde empieza el bucle*/
M : {$$.place = malloc(sizeof(char)*5);
     $$.val_type = INT_TYPE; /*Un contador siempre es un entero*/
     strcpy($$.place, nou_temporal());
     addToMatrix(3, $$.place, ":=", "0");
     contador.val_type = INT_TYPE;
     contador.place = $$.place;
     temp_sq = malloc(sizeof(char)*5);
     sprintf(temp_sq, "%d", sig_linea);  
};


%%


char* nou_temporal(){
  char* buffer = (char *) malloc(sizeof(char)*3+sizeof(int));
  sprintf(buffer, "$t0%d", num_temportales);
  num_temportales++;
  return buffer;
}

void addToMatrix(int args_count, ...) {
    va_list args;
    va_start(args, args_count);
    char* buffer = malloc(sizeof(char) * (SENTENCE_MAX_LENGTH + 1));
    buffer[0] = '\0';

    for (int i = 0; i < args_count; i++) {
        char* arg = va_arg(args, char*);  // Intento de leer argumento
        printf("%s\n", arg);
        strcat(buffer, arg);
        strcat(buffer, " ");
    }

    sentenciasC3A[sig_linea] = buffer;
    printf("Guardado en sentenciasC3A[%d]: %s\n", sig_linea, buffer);
    sig_linea++;

    va_end(args);
}

void addToMatrixSalotIncond(value_info s1, const char* operel, value_info s2, char* line2jump){
	if (s1.val_type==s2.val_type) {
		char *op= (char *)malloc(sizeof(char)*strlen(operel)+2);
		strcpy(op, operel);
		if (s1.val_type==INT_TYPE) strcat(op, "I");
	 	else strcat(op, "F");
		addToMatrix(6, "IF", s1.place, op, s2.place, "GOTO", line2jump);
		free(op);
	}
	else yyerror("Tienen que tener el mismo tipo!");

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

void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos que ambos operandos sean enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {

        // Comprobamos si el divisor (v2) es 0 para evitar un error de módulo por cero
        if (v2.value.val_int == 0) {
            // Imprimir un error de módulo por cero o manejarlo adecuadamente
            printf("Error: Módulo por cero\n");
            return;
        }

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado
        s0->val_type = INT_TYPE;     // El resultado del módulo siempre es un entero

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            asprintf(&v1_str, "%d", v1.value.val_int);
        } else {
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            asprintf(&v2_str, "%d", v2.value.val_int);
        } else {
            v2_str = v2.name;
        }

        // Generar la instrucción de módulo
        if (strcmp(op, "%") == 0) {
            if (v1.place == NULL) {
                addToMatrix(5, s0->place, ":=", v1_str, "MODI", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1.place, "MODI", v2_str);
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);

    } else {
        // Si uno o ambos operandos no son enteros, se genera un error
        printf("Error: Operación de módulo solo soportada entre enteros\n");
    }
}


void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str;
    char* v2_str;

    // Verificamos que los operandos sean numéricos (enteros o flotantes)
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Comprobar si el exponente es negativo y la base es un entero
        if (v2.val_type == INT_TYPE && v2.value.val_int < 0 && v1.val_type == INT_TYPE) {
            printf("Error: Potencia con exponente negativo requiere un valor flotante\n");
            return;
        }

        s0->place = nou_temporal();  // Nuevo temporal para almacenar el resultado

        // Determinar el tipo del resultado
        if (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) {
            s0->val_type = FLOAT_TYPE;  // El resultado será flotante si alguno de los operandos es flotante
        } else {
            s0->val_type = INT_TYPE;  // Si ambos son enteros, el resultado es entero
        }

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            if (v1.val_type == INT_TYPE) {
                asprintf(&v1_str, "%d", v1.value.val_int);
            } else {
                asprintf(&v1_str, "%f", v1.value.val_float);
            }
        } else {
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            if (v2.val_type == INT_TYPE) {
                asprintf(&v2_str, "%d", v2.value.val_int);
            } else {
                asprintf(&v2_str, "%f", v2.value.val_float);
            }
        } else {
            v2_str = v2.name;
        }

        // Generar la instrucción de potencia
        if (strcmp(op, "**") == 0) {
            if (v1.place == NULL) {
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1_str, "POWF", v2_str);
                } else {
                    addToMatrix(5, s0->place, ":=", v1_str, "POWI", v2_str);
                }
            } else {
                if (s0->val_type == FLOAT_TYPE) {
                    addToMatrix(5, s0->place, ":=", v1.place, "POWF", v2_str);
                } else {
                    addToMatrix(5, s0->place, ":=", v1.place, "POWI", v2_str);
                }
            }
        }

        // Liberar la memoria dinámica asignada con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);

    } else {
        // Error si alguno de los operandos no es numérico
        printf("Error: Operación de potencia solo soportada entre enteros o flotantes\n");
    }
}

void print_sentences(){
  int i;
  for (i=1; i < sig_linea; i++)
	fprintf(yyout, "%d:  %s\n", i, sentenciasC3A[i]);
  fprintf(yyout, "%d:  HALT\n", sig_linea);
}