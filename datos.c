#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "datos.h"


#define STRING_MAX_SIZE 2056  // Tamaño máximo para cadenas

char *type_to_str(data_type val_type)
{
  if (val_type == UNKNOWN_TYPE) {
    return strdup("Unknown type");
  } else if (val_type == INT_TYPE) {
    return strdup("Integer");
  } else if (val_type == FLOAT_TYPE) {
    return strdup("Float");
  } else {
    return strdup("Error: incorrect value for 'val_type'");
  }
}


char *value_info_to_str(value_info value)
{
  char buffer[STR_MAX_LENGTH];

  if (value.val_type == UNKNOWN_TYPE) {
    sprintf(buffer, "Unknown value type");
  } else if (value.val_type == INT_TYPE) {
    sprintf(buffer, "Integer: %d", value.value.val_int);
  } else if (value.val_type == FLOAT_TYPE) {
    sprintf(buffer, "Float: %f", value.value.val_float);
  } else {
    sprintf(buffer, "Error: incorrect value for 'value.val_type'");
  }
  return strdup(buffer);
}



char* valueToString(value_info v) {
    char* str = (char*)malloc(sizeof(char)*10+1);
    switch(v.val_type) {
        case INT_TYPE:
            sprintf(str, "%d", v.value.val_int);
            break;
        case FLOAT_TYPE:
            sprintf(str, "%f", v.value.val_float);
            break;
        case STRING_TYPE:
            str = v.value.val_string;
            break;
        case BOOLEAN_TYPE:
            str = v.value.val_boolean ? "true" : "false";
            break;
        default:
            str = "undefined";
    }
    return str;
}


value_info sumaAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // Sumar enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int + v2.value.val_int;
    }
    // Sumar floats
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float + v2.value.val_float;
    }
    // Concatenar cadenas
    else if (v1.val_type == STRING_TYPE && v2.val_type == STRING_TYPE) {
        resultado.val_type = STRING_TYPE;
        
        // Calcular el tamaño total de la nueva cadena
        size_t total_length = strlen(v1.value.val_string) + strlen(v2.value.val_string);
        
        // Asegúrate de que no exceda el tamaño máximo
        if (total_length < STR_MAX_LENGTH) {
            // Reserva memoria para la nueva cadena
            resultado.value.val_string = (char *)malloc((total_length + 1) * sizeof(char));
            if (resultado.value.val_string == NULL) {
                fprintf(stderr, "Error: no se pudo asignar memoria para la concatenación de cadenas.\n");
                resultado.val_type = UNKNOWN_TYPE;
            } else {
                // Concatenar las cadenas
                snprintf(resultado.value.val_string, total_length + 1, "%s%s", v1.value.val_string, v2.value.val_string);
            }
        } else {
            fprintf(stderr, "Error: la concatenación de cadenas excede el tamaño máximo permitido.\n");
            resultado.val_type = UNKNOWN_TYPE;
        }
    }
    // Manejo de combinaciones de tipos
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int + v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float + v2.value.val_int;
    }

    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación.\n");
    }

    return resultado;
}


value_info restaAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // Restar enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int - v2.value.val_int;
    }
    // Restar flotantes
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float - v2.value.val_float;
    }
    // Manejo de combinaciones de tipos
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int - v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float - v2.value.val_int;
    }
    // Manejar caso donde los tipos no son compatibles
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de resta.\n");
    }

    return resultado;
}



value_info multAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // Multiplicar enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int * v2.value.val_int;
    }
    // Multiplicar flotantes
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float * v2.value.val_float;
    }
    // Manejo de combinaciones de tipos
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int * v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float * v2.value.val_int;
    }
    // Manejar caso donde los tipos no son compatibles
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de multiplicación.\n");
    }

    return resultado;
}


value_info divAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // División entre enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero.\n");
            // Retornar un valor indeterminado o manejar el error según tus necesidades
            return resultado;
        }
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int / v2.value.val_int;
    }
    // División entre flotantes
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        if (v2.value.val_float == 0.0) {
            fprintf(stderr, "Error: División por cero.\n");
            // Retornar un valor indeterminado o manejar el error según tus necesidades
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float / v2.value.val_float;
    }
    // Manejo de combinaciones de tipos
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        if (v2.value.val_float == 0.0) {
            fprintf(stderr, "Error: División por cero.\n");
            // Retornar un valor indeterminado o manejar el error según tus necesidades
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int / v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero.\n");
            // Retornar un valor indeterminado o manejar el error según tus necesidades
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float / v2.value.val_int;
    }
    // Manejar caso donde los tipos no son compatibles
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de división.\n");
    }

    return resultado;
}


value_info modAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // Módulo entre enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero en módulo.\n");
            // Retornar un valor indeterminado o manejar el error según tus necesidades
            return resultado;
        }
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int % v2.value.val_int;
    }
    // Manejo de tipos incompatibles
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de módulo.\n");
    }

    return resultado;
}


value_info potAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    // Potencia entre enteros
    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = (int)pow(v1.value.val_int, v2.value.val_int);
    }
    // Potencia entre flotantes
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_float, v2.value.val_float);
    }
    // Combinación de tipos: int y float
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_int, v2.value.val_float);
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_float, v2.value.val_int);
    }
    // Manejo de tipos incompatibles
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de potencia.\n");
    }

    return resultado;
}