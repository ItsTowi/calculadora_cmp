#include <stdbool.h>

#ifndef datos_H
#define datos_H

#define STR_MAX_LENGTH 200

typedef enum {
  UNKNOWN_TYPE = 1,
  INT_TYPE,
  FLOAT_TYPE,
  STRING_TYPE,
  BOOLEAN_TYPE
} data_type;


typedef struct {
  char * name;
  union {
    int val_int;
    float val_float;
    bool val_boolean;
    char *val_string;
  } value;
  data_type val_type;
} value_info;


char *type_to_str(data_type val_type);
char *value_info_to_str(value_info value);
char *valueToString(value_info v);


#endif
