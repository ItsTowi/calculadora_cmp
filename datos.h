// datos.h
#ifndef DATOS_H
#define DATOS_H

typedef enum {
    UNKNOWN_TYPE,
    INT_TYPE
} data_type;

typedef struct {
    data_type val_type;
    int val_int;
} value_info;

#define STR_MAX_LENGTH 256

#endif // DATOS_H