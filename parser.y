%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXLEN 150
#define SENTENCE_MAX_LENGTH 150

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
 void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void addToMatrixSalotIncond(value_info s1, const char* operel, value_info s2, char* line2jump);
%}
 

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL;
%token <expr_val> ID A_ID B_ID INTEGER FLOAT BOOLEAN ADD SUB MULT DIV MOD POW LPAREN RPAREN OPRELACIONAL AND OR NOT REPEAT DONE DO;
%type <expr_val> declaracion lista_declaraciones declaracion_simple declaracion_iterativa declaracion_iterativa_incondicional exp 
                aritmetica termino factor primario M
                booleana bool1 bool2 bool3 bool_aritmetic;

%start programa

%%

programa : lista_declaraciones{print_sentences();};

lista_declaraciones: lista_declaraciones declaracion | declaracion;

declaracion: declaracion_simple | declaracion_iterativa;

declaracion_simple: ID ASSIGN exp EOL {
                                  if ($3.val_type == UNKNOWN_TYPE) 
                                  {
                                    printf("ERror tipo\n");
                                    yyerror($3.value.val_string);
                                  } 
                                  else 
                                  {
                                    $1.val_type = $3.val_type;
                                    $3.name = $1.name;
                                    printf("Se asigna a la variable %s el valor %s\n", $1.name, valueToString($3));
                                    if (!($1.name == NULL)) {
                                      sym_enter($1.name, &$3);
                                      if ($3.place != NULL)
                                        addToMatrix(3, $1.name, ":=", $3.place);
                                      else
                                        addToMatrix(3, $1.name, ":=", valueToString($3));
                                    }
                                  }
                                }
              | exp EOL         {
                                  if ($1.val_type == UNKNOWN_TYPE)
                                  {
                                    yyerror($1.value.val_string);
                                  }
                                  else 
                                  {
                                    addToMatrix(2, "PARAM", $1.name);
                                  }
                                }
              | ONELINECMNT     {

                                }
              | MULTILINECMNT   {
                                }
              | EOL             {}
              | A_ID ASSIGN exp EOL {
                                  if ($3.val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror($3.value.val_string);
                                  } 
                                  else 
                                  {
                                    $1.val_type = $3.val_type;
                                    $3.name = $1.name;
                                    printf("Se asigna a la variable %s el valor %s\n", $1.name, valueToString($3));
                                    if (!($1.name == NULL)) {
                                      sym_enter($1.name, &$3);
                                      if ($3.place != NULL)
                                        addToMatrix(3, $1.name, ":=", $3.place);
                                      else
                                        addToMatrix(3, $1.name, ":=", valueToString($3));
                                    }
                                  }
                                }

exp: aritmetica | booleana;

aritmetica: termino | aritmetica ADD termino  {
                                                $$ = sumaAritmetica($1, $3);
                                                sumaAritmetica3AC(&$$,$1, "+", $3);
                                              }
                    | aritmetica SUB termino  {
                                                $$ = restaAritmetica($1, $3);
                                                restaAritmetica3AC(&$$,$1, "-", $3);
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
                                            $$.name = $1.name;
                                            $$.value =$1.value;
                                            $$.place = valueToString($1);
                                          }
                                      }
          | A_ID                      {
                                          if(sym_lookup($1.name, &$1) == SYMTAB_NOT_FOUND)
                                          {	
                                            yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); 
                                          } 
										    else 
                                          {
                                            $$.val_type = $1.val_type;
                                            $$.value =$1.value;
                                            $$.place = $1.name;
                                          }
                                      }
          | LPAREN aritmetica RPAREN  {
                                          $$ = $2;
                                      }


booleana: bool1
          | booleana OR bool1 {
                                if ($1.val_type == BOOLEAN_TYPE && $1.value.val_boolean) {
                                    printf("Corto de or\n");
                                    $$ = $1;
                                } else {
                                    $$ = orBooleana($1, $3);
                                }
                              };

bool1: bool2
      | bool1 AND bool2 {
                          if ($1.val_type == BOOLEAN_TYPE && !$1.value.val_boolean) {
                              printf("Corto de and\n");
                              $$ = $1;
                          } else {
                              $$ = andBooleana($1, $3);
                          }
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
                                                      $$ = opRelacional($1,$2,$3);
                                                    };


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


void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str = NULL;
    char* v2_str = NULL;

    printf("El nombre de v1 es: %s\n", v1.name ? v1.name : "(null)");
    printf("El nombre de v2 es: %s\n", v2.name ? v2.name : "(null)");

    // Verificar que ambos son numéricos
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Crear un nuevo temporal
        s0->place = nou_temporal();

        // Determinar tipo del resultado
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        // Asignar cadenas para v1 y v2 (o sus lugares si existen)
        v1_str = (v1.name != NULL) ? v1.name : 
                 (v1.val_type == INT_TYPE) ? (asprintf(&v1_str, "%d", v1.value.val_int), v1_str) : 
                 (asprintf(&v1_str, "%f", v1.value.val_float), v1_str);

        v2_str = (v2.name != NULL) ? v2.name : 
                 (v2.val_type == INT_TYPE) ? (asprintf(&v2_str, "%d", v2.value.val_int), v2_str) : 
                 (asprintf(&v2_str, "%f", v2.value.val_float), v2_str);

        // Generar instrucción
        if (strcmp(op, "+") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1.place ? v1.place : v1_str, "ADDF", v2.place ? v2.place : v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1.place ? v1.place : v1_str, "ADDI", v2.place ? v2.place : v2_str);
            }
        }

        // Liberar memoria solo si fue asignada dinámicamente
        if (v1.name == NULL && v1_str) free(v1_str);
        if (v2.name == NULL && v2_str) free(v2_str);
    }
}


void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char* v1_str = NULL;
    char* v2_str = NULL;

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        v1_str = (v1.name != NULL) ? v1.name : 
                 (v1.val_type == INT_TYPE) ? (asprintf(&v1_str, "%d", v1.value.val_int), v1_str) : 
                 (asprintf(&v1_str, "%f", v1.value.val_float), v1_str);

        v2_str = (v2.name != NULL) ? v2.name : 
                 (v2.val_type == INT_TYPE) ? (asprintf(&v2_str, "%d", v2.value.val_int), v2_str) : 
                 (asprintf(&v2_str, "%f", v2.value.val_float), v2_str);

        if (strcmp(op, "-") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1.place ? v1.place : v1_str, "SUBF", v2.place ? v2.place : v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1.place ? v1.place : v1_str, "SUBI", v2.place ? v2.place : v2_str);
            }
        }

        if (v1.name == NULL && v1_str) free(v1_str);
        if (v2.name == NULL && v2_str) free(v2_str);
    }
}


void generarValorCadena(value_info v, char **v_str) {
    if (v.name == NULL) {
        // Si el nombre es NULL, usamos el valor directamente
        if (v.val_type == INT_TYPE) {
            asprintf(v_str, "%d", v.value.val_int);
        } else {
            asprintf(v_str, "%f", v.value.val_float);
        }
    } else {
        *v_str = v.name;
    }
}

void liberarValorCadena(value_info v, char *v_str) {
    if (v.name == NULL) {
        free(v_str);
    }
}

void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char *v1_str, *v2_str;

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {
        
        s0->place = nou_temporal();
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        generarValorCadena(v1, &v1_str);
        generarValorCadena(v2, &v2_str);

        if (strcmp(op, "*") == 0) {
            addToMatrix(5, s0->place, ":=", 
                        v1.place ? v1.place : v1_str, 
                        s0->val_type == FLOAT_TYPE ? "MULF" : "MULI", 
                        v2_str);
        }

        liberarValorCadena(v1, v1_str);
        liberarValorCadena(v2, v2_str);
    }
}

void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    char *v1_str, *v2_str;

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        if ((v2.val_type == INT_TYPE && v2.value.val_int == 0) ||
            (v2.val_type == FLOAT_TYPE && v2.value.val_float == 0.0)) {
            printf("Error: División por cero\n");
            return;
        }

        s0->place = nou_temporal();
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        generarValorCadena(v1, &v1_str);
        generarValorCadena(v2, &v2_str);

        if (strcmp(op, "/") == 0) {
            addToMatrix(5, s0->place, ":=", 
                        v1.place ? v1.place : v1_str, 
                        s0->val_type == FLOAT_TYPE ? "DIVF" : "DIVI", 
                        v2_str);
        }

        liberarValorCadena(v1, v1_str);
        liberarValorCadena(v2, v2_str);
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