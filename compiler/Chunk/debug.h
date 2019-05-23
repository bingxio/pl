#include "chunk.h"

#ifndef DEBUG_H
#define DEBUG_H

void disassembleChunk(Chunk* chunk, const char* name);

int disassembleInstruction(Chunk* chunk, int offset);

#endif
