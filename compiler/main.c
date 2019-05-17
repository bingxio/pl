#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char* argv[]) {
    init_vm();

    chunk chunk;

    init_chunk(&chunk);

    int constant = add_constant(&chunk, 2.5);

    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, constant, 1);

    write_chunk(&chunk, OP_RETURN, 3);

    disassemble_chunk(&chunk, "test chunk");

    free_vm();

    free_chunk(&chunk);

    return 0;
}