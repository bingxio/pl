#ifndef DEBUG_H
#define DEBUG_H

#include "chunk.h"

void disassemble_chunk(chunk* chunk, const char* name);

int disassemble_instruction(chunk* chunk, int off_set);

#endif