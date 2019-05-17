#ifndef VALUE_H
#define VALUE_H

#include "common.h"

typedef double value;

typedef struct {
    int capacity;
    int count;

    value* values;
} value_array;

void init_value_array(value_array* array);
void write_value_array(value_array* array, value value);
void free_value_array(value_array* array);

void print_value(value value);

#endif