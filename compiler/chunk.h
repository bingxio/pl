#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"

typedef struct {
    int count;
    int capacity;

    uint8_t* code;

    int* lines;

    value_array constants;
} chunk;

void init_chunk(chunk* chunk);
void free_chunk(chunk* chunk);
void write_chunk(chunk* chunk, uint8_t byte, int line);

int add_constant(chunk* chunk, value value);

#endif
