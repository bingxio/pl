#include <stdio.h>
#include "chunk.h"
#include "common.h"
#include "debug.h"

int main() {
    Chunk chunk;

    initChunk(&chunk);

    writeChunk(&chunk, OP_RETURN);

    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);

    getchar();

    return 0;
}