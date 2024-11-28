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
 void aritmeticCalc(value_info v1, char *op, value_info v2);
%}
 

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL
%token <expr_val> ID A_ID B_ID INTEGER FLOAT STRING BOOLEAN PI E ADD SUB MULT DIV MOD POW SIN COS TAN LEN SUBSTR BIN HEX OCT AND OR NOT OPRELACIONAL LPAREN RPAREN
%type <expr_val> declaracion lista_declaraciones exp aritmetica booleana bool1 bool2 bool3 bool_aritmetic termino factor primario op_trig representacioNum

%start programa

%%

programa : lista_declaraciones;

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
                                                aritmeticCalc($1, "+", $3);

                                              }
                    | aritmetica SUB termino  {
                                                $$ = restaAritmetica($1, $3);
                                              };
                    | SUB termino             { $$ = cambioAritmetica($2); }
                    | ADD termino             { $$ = $2; };   

termino: factor | termino MULT factor {
                                        $$ = multAritmetica($1, $3);
                                      } 
                | termino DIV factor  {
                                        $$ = divAritmetica($1, $3);
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

void aritmeticCalc(value_info v1, char *op, value_info v2) {
    value_info result = {.val_type = UNKNOWN_TYPE};
    result.place = (char*)malloc(100);

    char* v1_str;
    char* v2_str;

    // Verificamos si los tipos de v1 y v2 son enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        result.val_type = INT_TYPE;
        strcpy(result.place, nou_temporal());

        printf("%s\n", op);
        printf("valor1 %d nombre %s\n", v1.value.val_int, v1.name);
        printf("valor2 %d nombre %s\n", v2.value.val_int, v2.name);

        // Asignar v1_str dependiendo de si v1.name es NULL o no
        if (v1.name == NULL) {
            // Si el es NULL, usamos el valor
            asprintf(&v1_str, "%d", v1.value.val_int);  // asprintf es más seguro para manejar cadenas dinámicas
        } else {
            // Si no es NULL, usamos el nombre de la variable
            v1_str = v1.name;
        }

        // Asignar v2_str dependiendo de si v2.name es NULL o no
        if (v2.name == NULL) {
            // Si el nombre es NULL, usamos el valor
            asprintf(&v2_str, "%d", v2.value.val_int);
        } else {
            // Si no es NULL, usamos el nombre de la variable
            v2_str = v2.name;
        }

        // Ahora, llamamos a addToMatrix pasando las cadenas correctas
        if (strcmp(op, "+") == 0) {
            // Llamar a addToMatrix pasando los valores como cadenas
            addToMatrix(4, result.place, v1_str, "ADDI", v2_str);
        }

        // Liberar la memoria dinámica que hemos creado con asprintf
        if (v1.name == NULL) free(v1_str);
        if (v2.name == NULL) free(v2_str);
    }
}

void addToMatrix(int args_count, ...) {
    va_list args;
    va_start(args, args_count);

    char* buffer = malloc(sizeof(char) * SENTENCE_MAX_LENGTH + 1);
    buffer[0] = '\0';  // Inicializamos buffer como cadena vacía

    for (int i = 0; i < args_count; i++) {
        char* arg = va_arg(args, char*);
        strcat(buffer, arg);
        strcat(buffer, " ");  // Agregar espacio entre los argumentos
    }


    sentenciasC3A[sig_linea] = buffer;
    sig_linea++;

    printf("Matriz construida: %s\n", sentenciasC3A[sig_linea-1]);

    va_end(args);
    free(buffer);  // Liberar memoria después de usarla
}