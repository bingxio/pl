#include <stdio.h>

#include "value.h"
#include "memory.h"

void init_value_array(value_array* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

void write_value_array(value_array* array, value v) {
    if (array->capacity < array->count + 1) {
        int old_capacity = array->capacity;

        array->capacity = GROW_CAPACITY(old_capacity);
        array->values = GROW_ARRAY(array->values, value, old_capacity, array->capacity);
    }

    array->values[array->count] = v;
    array->count ++;
}

void free_value_array(value_array* array) {
    FREE_ARRAY(value, array->values, array->capacity);

    init_value_array(array);
}

void print_value(value value) {
    printf("%g", value);
}