#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "datos.h"


#define STRING_MAX_SIZE 2056
#define PI 3.14159265358979323846

char *type_to_str(data_type val_type)
{
  if (val_type == UNKNOWN_TYPE) {
    return strdup("Unknown type");
  } else if (val_type == INT_TYPE) {
    return strdup("Integer");
  } else if (val_type == FLOAT_TYPE) {
    return strdup("Float");
  } else if (val_type == STRING_TYPE){
    return strdup("String");
  } else if (val_type == BOOLEAN_TYPE){
    return strdup("Boolean");
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

value_info constantePI() {
    value_info result;
    result.val_type = FLOAT_TYPE;
    result.value.val_float = PI_VALUE;
    return result;
}

value_info constanteE() {
    value_info result;
    result.val_type = FLOAT_TYPE;
    result.value.val_float = E_VALUE;
    return result;
}


value_info sumaAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int + v2.value.val_int;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float + v2.value.val_float;
    }
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
                snprintf(resultado.value.val_string, total_length + 1, "%s%s", v1.value.val_string, v2.value.val_string);
            }
        } else {
            fprintf(stderr, "Error: la concatenación de cadenas excede el tamaño máximo permitido.\n");
            resultado.val_type = UNKNOWN_TYPE;
        }
    }
    else if ((v1.val_type == STRING_TYPE && v2.val_type == INT_TYPE) ||
             (v1.val_type == INT_TYPE && v2.val_type == STRING_TYPE)) {
        resultado.val_type = STRING_TYPE;

        char buffer[20];
        int num = (v1.val_type == INT_TYPE) ? v1.value.val_int : v2.value.val_int;
        snprintf(buffer, sizeof(buffer), "%d", num);

        const char *str_part = (v1.val_type == STRING_TYPE) ? v1.value.val_string : v2.value.val_string;
        size_t total_length = strlen(str_part) + strlen(buffer);

        if (total_length < STR_MAX_LENGTH) {
            resultado.value.val_string = (char *)malloc((total_length + 1) * sizeof(char));
            if (resultado.value.val_string == NULL) {
                fprintf(stderr, "Error: no se pudo asignar memoria para la concatenación de STRING + INT.\n");
                resultado.val_type = UNKNOWN_TYPE;
            } else {
                snprintf(resultado.value.val_string, total_length + 1, "%s%s", str_part, buffer);
            }
        } else {
            fprintf(stderr, "Error: la concatenación de STRING + INT excede el tamaño máximo permitido.\n");
            resultado.val_type = UNKNOWN_TYPE;
        }
    }
    else if ((v1.val_type == STRING_TYPE && v2.val_type == FLOAT_TYPE) ||
             (v1.val_type == FLOAT_TYPE && v2.val_type == STRING_TYPE)) {
        resultado.val_type = STRING_TYPE;

        char buffer[20];
        float num = (v1.val_type == FLOAT_TYPE) ? v1.value.val_float : v2.value.val_float;
        snprintf(buffer, sizeof(buffer), "%.2f", num);

        const char *str_part = (v1.val_type == STRING_TYPE) ? v1.value.val_string : v2.value.val_string;
        size_t total_length = strlen(str_part) + strlen(buffer);

        if (total_length < STR_MAX_LENGTH) {
            resultado.value.val_string = (char *)malloc((total_length + 1) * sizeof(char));
            if (resultado.value.val_string == NULL) {
                fprintf(stderr, "Error: no se pudo asignar memoria para la concatenación de STRING + FLOAT.\n");
                resultado.val_type = UNKNOWN_TYPE;
            } else {
                snprintf(resultado.value.val_string, total_length + 1, "%s%s", str_part, buffer);
            }
        } else {
            fprintf(stderr, "Error: la concatenación de STRING + FLOAT excede el tamaño máximo permitido.\n");
            resultado.val_type = UNKNOWN_TYPE;
        }
    }
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

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int - v2.value.val_int;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float - v2.value.val_float;
    }
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int - v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float - v2.value.val_int;
    }
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de resta.\n");
    }

    return resultado;
}



value_info multAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int * v2.value.val_int;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float * v2.value.val_float;
    }
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int * v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float * v2.value.val_int;
    }
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de multiplicación.\n");
    }

    return resultado;
}


value_info divAritmetica(value_info v1, value_info v2, int lineno) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero en la linea %d\n", lineno);
            return resultado;
        }
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int / v2.value.val_int;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        if (v2.value.val_float == 0.0) {
            fprintf(stderr, "Error: División por cero en la linea %d\n", lineno);
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float / v2.value.val_float;
    }
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        if (v2.value.val_float == 0.0) {
            fprintf(stderr, "Error: División por cero en la linea %d\n", lineno);
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_int / v2.value.val_float;
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero en la linea %d\n", lineno);
            return resultado;
        }
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = v1.value.val_float / v2.value.val_int;
    }
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de división.\n");
    }

    return resultado;
}


value_info modAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        if (v2.value.val_int == 0) {
            fprintf(stderr, "Error: División por cero en módulo.\n");
            return resultado;
        }
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = v1.value.val_int % v2.value.val_int;
    }
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de módulo.\n");
    }

    return resultado;
}


value_info potAritmetica(value_info v1, value_info v2) {
    value_info resultado = {.val_type = UNKNOWN_TYPE};

    if (v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = INT_TYPE;
        resultado.value.val_int = (int)pow(v1.value.val_int, v2.value.val_int);
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_float, v2.value.val_float);
    }
    else if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_int, v2.value.val_float);
    }
    else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
        resultado.val_type = FLOAT_TYPE;
        resultado.value.val_float = pow(v1.value.val_float, v2.value.val_int);
    }
    else {
        fprintf(stderr, "Error: tipos incompatibles para la operación de potencia.\n");
    }

    return resultado;
}

value_info representacioNum(value_info representacion, value_info v) {
    value_info resultado = {.val_type = STRING_TYPE};

    if (v.val_type == INT_TYPE) {
        if (strcmp(representacion.value.val_string, "bin") == 0) {
            resultado.value.val_string = transformarBinarioInt(v.value.val_int);
        } else if (strcmp(representacion.value.val_string, "hex") == 0) {
            resultado.value.val_string = transformarHexaInt(v.value.val_int);
        } else if (strcmp(representacion.value.val_string, "oct") == 0) {
            resultado.value.val_string = transformarOctalInt(v.value.val_int);
        }
    } 

    else if (v.val_type == FLOAT_TYPE) {
        if (strcmp(representacion.value.val_string, "bin") == 0) {
            resultado.value.val_string = transformarBinarioInt((int)v.value.val_float);
        } else if (strcmp(representacion.value.val_string, "hex") == 0) {
            resultado.value.val_string = transformarHexaInt((int)v.value.val_float);
        } else if (strcmp(representacion.value.val_string, "oct") == 0) {
            resultado.value.val_string = transformarOctalInt((int)v.value.val_float);
        }
    }

    return resultado;
}

char* transformarBinarioInt(int num) {
    char* binario = (char*)malloc(33);
    binario[32] = '\0';

    for (int i = 31; i >= 0; --i) {
        binario[31 - i] = (num & (1 << i)) ? '1' : '0';
    }

    return binario;
}

char* transformarHexaInt(int num) {
    char* hexa = (char*)malloc(9);
    snprintf(hexa, 9, "%X", num);
    return hexa;
}

char* transformarOctalInt(int num) {
    char* octal = (char*)malloc(12);
    snprintf(octal, 12, "%o", num);
    return octal;
}


value_info cambioAritmetica(value_info v) {
    value_info resultado;
    resultado.val_type = v.val_type;
    
    if (v.val_type == INT_TYPE) {
        resultado.value.val_int = -v.value.val_int;
    } else if (v.val_type == FLOAT_TYPE) {
        resultado.value.val_float = -v.value.val_float;
    } else {
        resultado.val_type = UNKNOWN_TYPE;
        fprintf(stderr, "Error: tipo de dato incompatible para cambio de signo.\n");
    }
    
    return resultado;
}


value_info calcularLen(value_info v) {
    value_info result;
    if (v.val_type == STRING_TYPE) {
        result.val_type = INT_TYPE;
        result.value.val_int = strlen(v.value.val_string);
    } else {
        result.val_type = UNKNOWN_TYPE;
    }
    return result;
}

value_info substring(value_info v1, int inicio, int distancia) {
    value_info result;

    if (v1.val_type == STRING_TYPE) {
        
        int len = strlen(v1.value.val_string);
        if (inicio < 0 || inicio >= len || distancia < 0 || (inicio + distancia) > len) {
            result.val_type = UNKNOWN_TYPE;
            return result;
            printf("UNKOWN");
        }

        // Reservar memoria para la subcadena
        char *sub = (char*)malloc((distancia + 1) * sizeof(char));
        if (!sub) {
            result.val_type = UNKNOWN_TYPE;
            
            return result;
        }

        strncpy(sub, v1.value.val_string + inicio, distancia);
        sub[distancia] = '\0';  // Asegurarse de que la subcadena esté terminada con '\0'

        result.val_type = STRING_TYPE;
        result.value.val_string = sub;
    } else {
        result.val_type = UNKNOWN_TYPE;
    }

    return result;
}

value_info opTrigonometrica(value_info trigFunction, value_info v1)
{
    value_info resultado;
    resultado.val_type = FLOAT_TYPE;

    if (v1.val_type != INT_TYPE && v1.val_type != FLOAT_TYPE) {
        printf("Error: el argumento de la función trigonométrica debe ser un número.\n");
        resultado.val_type = UNKNOWN_TYPE;
        return resultado;
    }

    float valor = (v1.val_type == INT_TYPE) ? (float)v1.value.val_int : v1.value.val_float;
    double radians = valor * (PI / 180.0);

    if (strcmp(trigFunction.value.val_string, "sin") == 0) {
        resultado.value.val_float = sin(radians);
    }
    else if (strcmp(trigFunction.value.val_string, "cos") == 0) {
        resultado.value.val_float = cos(radians);
    }
    else if (strcmp(trigFunction.value.val_string, "tan") == 0) {
        resultado.value.val_float = tan(radians);
    }
    else {
        printf("Error: función trigonométrica no reconocida.\n");
        resultado.val_type = UNKNOWN_TYPE;
    }

    return resultado;
}

value_info orBooleana(value_info v1, value_info v2)
{
    value_info resultado = {.val_type = BOOLEAN_TYPE};
    if (v1.val_type == BOOLEAN_TYPE && v2.val_type == BOOLEAN_TYPE) {
        resultado.value.val_boolean = v1.value.val_boolean || v2.value.val_boolean;
    } else {
        resultado.val_type = UNKNOWN_TYPE;
    }
    return resultado;
}

value_info andBooleana(value_info v1, value_info v2)
{
    value_info resultado = {.val_type = BOOLEAN_TYPE};
    if (v1.val_type == BOOLEAN_TYPE && v2.val_type == BOOLEAN_TYPE) {
        resultado.value.val_boolean = v1.value.val_boolean && v2.value.val_boolean;
    } else {
        resultado.val_type = UNKNOWN_TYPE;
    }
    return resultado;
}

value_info notBooleana(value_info v1)
{
    value_info resultado = {.val_type = BOOLEAN_TYPE};
    if (v1.val_type == BOOLEAN_TYPE) {
        resultado.value.val_boolean = !v1.value.val_boolean;
    } else {
        resultado.val_type = UNKNOWN_TYPE;
    }
    return resultado;
}

value_info opRelacional(value_info v1, value_info operador, value_info v2)
{
    value_info resultado = {.val_type = BOOLEAN_TYPE};

    if ((v1.val_type == INT_TYPE && v2.val_type == INT_TYPE) ||
        (v1.val_type == FLOAT_TYPE && v2.val_type == FLOAT_TYPE) ||
        (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) ||
        (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE)) {

        if (v1.val_type == INT_TYPE && v2.val_type == FLOAT_TYPE) {
            v1.value.val_float = (float)v1.value.val_int;
            v1.val_type = FLOAT_TYPE;
        }
        else if (v1.val_type == FLOAT_TYPE && v2.val_type == INT_TYPE) {
            v2.value.val_float = (float)v2.value.val_int;
            v2.val_type = FLOAT_TYPE;
        }

        if (strcmp(operador.value.val_string, "<") == 0) {
            resultado.value.val_boolean = v1.value.val_float < v2.value.val_float;
        }
        else if (strcmp(operador.value.val_string, "<=") == 0) {
            resultado.value.val_boolean = v1.value.val_float <= v2.value.val_float;
        }
        else if (strcmp(operador.value.val_string, ">") == 0) {
            resultado.value.val_boolean = v1.value.val_float > v2.value.val_float;
        }
        else if (strcmp(operador.value.val_string, ">=") == 0) {
            resultado.value.val_boolean = v1.value.val_float >= v2.value.val_float;
        }
        else if (strcmp(operador.value.val_string, "=") == 0) {
            resultado.value.val_boolean = v1.value.val_float == v2.value.val_float;
        }
        else if (strcmp(operador.value.val_string, "<>") == 0) {
            resultado.value.val_boolean = v1.value.val_float != v2.value.val_float;
        }
        else {
            resultado.val_type = UNKNOWN_TYPE;
        }
    }
    else {
        resultado.val_type = UNKNOWN_TYPE;
    }

    return resultado;
}