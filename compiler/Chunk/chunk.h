#ifndef CHUNK_H
#define CHUNK_H

#include <stdint.h>

typedef struct {
    int count;
    int capacity;

    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte);

#endif