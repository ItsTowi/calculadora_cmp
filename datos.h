#include <stdbool.h>
#include <math.h>

#ifndef datos_H
#define datos_H

#define STR_MAX_LENGTH 200
#define PI_VALUE 3.14159265359
#define E_VALUE  2.71828182846

typedef enum {
  UNKNOWN_TYPE,
  INT_TYPE,
  FLOAT_TYPE,
  STRING_TYPE,
  BOOLEAN_TYPE
} data_type;

typedef struct list_t
{
		int *lista;
		int size;
} list;

typedef struct variables {
  char * name;
  char * place;
  union {
    int val_int;
    float val_float;
    bool val_boolean;
    char *val_string;
  } value;
  data_type val_type;

  int repeat;
  list truelist;
  list falselist;
  list nextlist;

} value_info;

char *type_to_str(data_type val_type);
char *value_info_to_str(value_info value);
char *valueToString(value_info v);
value_info constantePI();
value_info constanteE();
value_info sumaAritmetica(value_info v1, value_info v2);
value_info restaAritmetica(value_info v1, value_info v2);
value_info multAritmetica(value_info v1, value_info v2);
value_info divAritmetica(value_info v1, value_info v2);
value_info modAritmetica(value_info v1, value_info v2);
value_info potAritmetica(value_info v1, value_info v2);
value_info cambioAritmetica(value_info v);
value_info calcularLen(value_info v);
value_info substring(value_info v1, int inicio , int distancia);
value_info representacioNum(value_info representacion, value_info v);
char* transformarBinarioInt(int num);
char* transformarHexaInt(int num);
char* transformarOctalInt(int num);
value_info orBooleana(value_info v1, value_info v2);
value_info andBooleana(value_info v1, value_info v2);
value_info notBooleana(value_info v1);
value_info opRelacional(value_info v1, value_info operator, value_info v2);
value_info opTrigonometrica(value_info trigFunction, value_info v1);

#endif
