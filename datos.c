#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "datos.h"


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
