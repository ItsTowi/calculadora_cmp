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
    list sent;
    int entero;
    char *cadena;
}

%{
 void completa(list lista, int num);
 list crea_lista(int num);
 list fusiona(list l1, list l2);
 value_info contador;
 char* getVariableValue(value_info v);
 void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void multiplicacionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void divisionAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void moduloAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void potenciaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2);
 void addToMatrixSaltoCondicional(value_info v1, char *operador, value_info v2, char * jump_line);
 void addToMatrixSalotIncond(value_info v1, const char* operador, value_info v2, char* jump_line);
%}
 

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL GT GE LT LE EQ NE;
%token <expr_val> ID A_ID B_ID INTEGER FLOAT BOOLEAN DOTS ADD SUB MULT DIV MOD POW LPAREN RPAREN OPRELACIONAL AND OR NOT 
                IF THEN ELSE FI
                WHILE UNTIL FOR IN RANG
                REPEAT DONE DO;
%type <expr_val> exp  aritmetica termino factor primario M
                 booleana bool1 bool2 bool3 bool_aritmetic;

%type <sent>    declaracion lista_declaraciones 
                declaracion_simple declaracion_condicional 
                declaracion_iterativa 
                declaracion_iterativa_incondicional 
                declaracion_iterativa_condicional bucle_while bucle_do_until
                declaracion_iterativa_indexada NEXTLIST;

%type <entero> LIN;
%type <cadena> operador_relacional;

%start programa

%%

programa : lista_declaraciones{print_sentences();};

lista_declaraciones: lista_declaraciones LIN declaracion {
		                completa($1, $2);
		                $$ = $3;
                    }
                    | declaracion;

declaracion: declaracion_simple | declaracion_condicional | declaracion_iterativa;

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
                                    char* oper = malloc(sizeof(char)*5);
                                    strcpy(oper, "PUT");
                                    if ($1.val_type == INT_TYPE) strcat(oper, "I,");
                                    else if ($1.val_type == FLOAT_TYPE) strcat(oper, "F,");
                                    addToMatrix(3, "CALL", oper, "1");
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
                    | SUB termino             { 
                                                $$ = cambioAritmetica($2); 
                                                //addToMatrix(4, $$.place, ":=", "CHSI", getVariableValue($2));
                                              }
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
                                            printf("AQUIIII\n");
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
          | booleana OR LIN bool1 {
                                if ($1.val_type == BOOLEAN_TYPE && $1.value.val_boolean) {
                                    printf("Corto de or\n");
                                    $$ = $1;
                                } else {
                                    $$ = orBooleana($1, $4);
                                }
                                completa($1.falselist, $3);
		                        $$.truelist = fusiona($1.truelist, $4.truelist);
		                        $$.falselist = $4.falselist;
                              };

bool1: bool2
      | bool1 AND LIN bool2 {
                          if ($1.val_type == BOOLEAN_TYPE && !$1.value.val_boolean) {
                              printf("Corto de and\n");
                              $$ = $1;
                          } else {
                              $$ = andBooleana($1, $4);
                          }
                          completa($1.truelist, $3);
                          $$.truelist = $4.truelist;
                          $$.falselist = fusiona($1.falselist, $4.falselist);
                        };

bool2: bool3 
      | NOT bool2                     {
                                        $$.truelist = $2.falselist;
                                        $$.falselist = $2.truelist;
                                        //$$ = notBooleana($2);
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
                                          $$.truelist = crea_lista(sig_linea);
                                          addToMatrix(5,"IF",$1.name,"EQ","1","GOTO");
                                          $$.falselist = crea_lista(sig_linea);
                                          addToMatrix(1, "GOTO");
                                          $$.val_type = $1.val_type;
                                          $$.value = $1.value;
                                        }
                                      };

bool_aritmetic: aritmetica operador_relacional aritmetica  {
                                                      //$$ = opRelacional($1,$2,$3);
                                                      $$.truelist = crea_lista(sig_linea);
                                                      printf("item true list %d\n", $$.truelist.lista[0]);
                                                      addToMatrixSaltoCondicional($1, $2, $3, "");
                                                      $$.falselist = crea_lista(sig_linea);
                                                      printf("item false list %d\n", $$.falselist.lista[0]);
                                                      addToMatrix(1, "GOTO");
                                                    };


operador_relacional: GT {$$="GT";} | LT {$$="LT";} | GE {$$="GE";} | LE {$$="LE";} | EQ {$$="EQ";} | NE {$$="NE";};

declaracion_condicional: IF booleana THEN LIN lista_declaraciones FI 
                        {
                            printf("LLEGO AL IF\n");
                            completa($2.truelist, $4);
	                        $$=fusiona($2.falselist, $5);
                        }
                        |
                        IF booleana THEN LIN lista_declaraciones ELSE NEXTLIST LIN lista_declaraciones FI
                        {
                            completa($2.truelist, $4);
	                        completa($2.falselist, $8);
	                        $$=fusiona($5, fusiona($7, $9));
                            printf("SE HA ENCONTRADO UN IF/ELSE \n");
                        };



declaracion_iterativa: declaracion_iterativa_incondicional | declaracion_iterativa_condicional | declaracion_iterativa_indexada;

declaracion_iterativa_incondicional: REPEAT aritmetica DO M EOL lista_declaraciones DONE {
	addToMatrix(5, contador.place, ":=", contador.place, "ADDI", "1");
    printf("valor de aritmetica %s\n", $2.place);
	addToMatrixSalotIncond(contador, "LT", $2, temp_sq);
};

declaracion_iterativa_condicional: bucle_do_until | bucle_while

bucle_do_until: DO LIN EOL lista_declaraciones UNTIL booleana {printf("BUCLE DO/UNTIL DETECTADO\n");}
 
bucle_while: WHILE LIN booleana DO LIN EOL lista_declaraciones DONE 
            {
                completa($3.truelist, $5);
                completa($7, $2);
                $$ = $3.falselist;
                char *m_buffer = malloc(sizeof(char)*5);
                sprintf(m_buffer, "%d", $2); 
                addToMatrix(2, "GOTO", m_buffer);
            }

declaracion_iterativa_indexada: FOR A_ID IN aritmetica DOTS aritmetica DO EOL lista_declaraciones DONE {printf("BUCLE FOR DETECTADO\n");}


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

/* Guarda el quat actual */
LIN: {
	$$=sig_linea;
};

/*Crea la siguiente lista*/
NEXTLIST: {
    $$=crea_lista(sig_linea);
	addToMatrix(1, "GOTO");
};

%%


char* nou_temporal(){
  char* buffer = (char *) malloc(sizeof(char)*3+sizeof(int));
  sprintf(buffer, "$t0%d", num_temportales);
  num_temportales++;
  return buffer;
}

list crea_lista(int num){
	list temp;
	temp.lista = malloc(MAXLEN*sizeof(int));
	temp.lista[0]=num;
	temp.size = 1;
	return temp;
}

void completa(list lista, int num){
	int i;
	char* num_buffer = malloc(sizeof(char)*5);
	sprintf(num_buffer, "%d", num);
	for (i=0; i < lista.size; i++){
	strcat(sentenciasC3A[lista.lista[i]],num_buffer);
	}
}

list fusiona(list l1, list l2){
	list temp;
	temp.lista = malloc(MAXLEN*sizeof(int));
	int i;
	for (i=0; i < l1.size; i++){
	temp.lista[i]=l1.lista[i];
	}
	int j;
	for (j=0; j < l2.size; j++){
	temp.lista[i]=l2.lista[j];
	i++;
	}

	temp.size = l1.size + l2.size;
	return temp;
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

void addToMatrixSalotIncond(value_info v1, const char* operador, value_info v2, char* jump_line){
	if (v1.val_type==v2.val_type) {
		char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
		strcpy(op, operador);
		if (v1.val_type==INT_TYPE) strcat(op, "I");
	 	else strcat(op, "F");
		addToMatrix(6, "IF", v1.place, op, v2.place, "GOTO", jump_line);
		free(op);
	}
	else yyerror("Tienen que tener el mismo tipo!");
}


void addToMatrixSaltoCondicional(value_info v1, char *operador, value_info v2, char * jump_line) {
	
    char* valor_v1 = getVariableValue(v1);
    char* valor_v2 = getVariableValue(v2);
    
    if (strcmp(operador, "=")==0 || strcmp(operador, "<>")==0){
		if (v1.val_type==v2.val_type) {
			char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
			strcpy(op, operador);
			if (v1.val_type==INT_TYPE) strcat(op, "I");
		 	else strcat(op, "F");
			addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			free(op);
		}
		else yyerror("Las dos variables tienen que tener el mismo tipo para realizar esta operación!");
	} else {
		char *op= (char *)malloc(sizeof(char)*strlen(operador)+2);
		strcpy(op, operador);
		if (v1.val_type==v2.val_type) {
			if (v1.val_type==INT_TYPE){
				 strcat(op, "I");
			} else {
				 strcat(op, "F");
			}
			addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);

		} else if (v1.val_type==FLOAT_TYPE || v2.val_type==FLOAT_TYPE){
			strcat(op, "F");
			if (v1.val_type==FLOAT_TYPE) {
				char *castedValue;
				if (v2.name != NULL) {
					castedValue = nou_temporal();
					addToMatrix(4, castedValue, ":=", "I2F", v2.place);
				} else {
					castedValue = (char *) malloc(sizeof(char)*5);
					sprintf(castedValue, "%.1f", atof(v2.place));
				}
				addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			}
			else if (v2.val_type==FLOAT_TYPE){
				char *castedValue;
				if (v1.name != NULL) {
					castedValue = nou_temporal();
					addToMatrix(4, castedValue, ":=", "I2F", v1.place);
				} else {
					castedValue = (char *) malloc(sizeof(char)*5);
					sprintf(castedValue, "%.1f", atof(v1.place));
				}
				addToMatrix(6, "IF", valor_v1, op, valor_v2, "GOTO", jump_line);
			} else yyerror("OPERACION NO PERMITIDA");
		} else yyerror("OPERACION NO PERMITIDA");
		free(op);
	}
}

char* getVariableValue(value_info v) {
    if (v.place != NULL && strlen(v.place) > 0) {
        return v.place;
    } else {
        return valueToString(v);
    }
}

void sumaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {

    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        s0->place = nou_temporal();

        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        char* v1_str = getVariableValue(v1);
        char* v2_str = getVariableValue(v2);

        if (strcmp(op, "+") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1_str, "ADDF", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1_str, "ADDI", v2_str);
            }
        }

        if (v1.place == NULL) free(v1_str);
        if (v2.place == NULL) free(v2_str);
    } else {
        printf("Error: Los operandos deben ser numéricos.\n");
    }
}

void restaAritmetica3AC(value_info *s0, value_info v1, char *op, value_info v2) {
    if ((v1.val_type == INT_TYPE || v1.val_type == FLOAT_TYPE) &&
        (v2.val_type == INT_TYPE || v2.val_type == FLOAT_TYPE)) {

        // Crear un nuevo temporal
        s0->place = nou_temporal();

        // Determinar tipo del resultado
        s0->val_type = (v1.val_type == FLOAT_TYPE || v2.val_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;

        // Obtener cadenas para v1 y v2
        char* v1_str = getVariableValue(v1);
        char* v2_str = getVariableValue(v2);

        // Generar instrucción basada en el operador
        if (strcmp(op, "-") == 0) {
            if (s0->val_type == FLOAT_TYPE) {
                addToMatrix(5, s0->place, ":=", v1_str, "SUBF", v2_str);
            } else {
                addToMatrix(5, s0->place, ":=", v1_str, "SUBI", v2_str);
            }
        }

        // Liberar memoria de las cadenas generadas dinámicamente
        if (v1.place == NULL) free(v1_str);
        if (v2.place == NULL) free(v2_str);
    } else {
        printf("Error: Los operandos deben ser numéricos.\n");
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