#ifndef CHUNK_H
#define CHUNK_H

#include <stdint.h>
#include "value.h"

typedef struct {
    int count;
    int capacity;

    uint8_t* code;

    int* lines;

    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte, int line);

int addConstant(Chunk* chunk, Value value);

#endif