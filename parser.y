%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyout;
extern FILE *log_file;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/

%}

%code requires {
  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "datos.h"
  #include "funciones.h"
  #include "symtab.h"
}

%union{
    value_info expr_val;
}

%token ASSIGN ONELINECMNT MULTILINECMNT COMMA EOL
%token <expr_val> ID A_ID B_ID INTEGER FLOAT STRING BOOLEAN PI E ADD SUB MULT DIV MOD POW SIN COS TAN LEN SUBSTR BIN HEX OCT AND OR NOT OPRELACIONAL LPAREN RPAREN
%type <expr_val> declaracion lista_declaraciones exp aritmetica booleana bool1 bool2 bool3 bool_aritmetic termino factor primario op_trig representacioNum

%start programa

%%

programa : lista_declaraciones;

lista_declaraciones: lista_declaraciones declaracion | declaracion;

declaracion: ID ASSIGN exp EOL {
                                  if ($3.val_type == UNKNOWN_TYPE) 
                                  {
                                    yyerror($3.value.val_string);
                                  } 
                                  else 
                                  {
                                    $1.val_type = $3.val_type;
                                    sym_enter($1.name, &$3);
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
                            }
              | MULTILINECMNT {
                                fprintf(yyout, "COMENTARIO DE MULTIPLES LINEAS %d\n", yylineno - 1);
                              };

exp: aritmetica | booleana;

aritmetica: termino | aritmetica ADD termino  {
                                                $$ = sumaAritmetica($1, $3);
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
                                        $$ = $1;
                                      }
          | FLOAT                     {
                                        $$ = $1;
                                      }
          | STRING                    {
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
                                                      $$ = opRelacional($1,$2,$3);
                                                    };

%%