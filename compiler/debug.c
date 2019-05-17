#include <stdio.h>

#include "debug.h"

void disassemble_chunk(chunk* chunk, const char* name) {
    printf("== %s == \n", name);

    for (int off_set = 0; off_set < chunk->count;) {
        off_set = disassemble_instruction(chunk, off_set);
    }
}

static int simple_instruction(const char* name, int off_set) {
    printf("%s \n", name);

    return off_set + 1;
}

static int constant_instruction(const char* name, chunk* chunk, int off_set) {
    uint8_t constant = chunk->code[off_set + 1];

    printf("%-16s %4d '", name, constant);
    print_value(chunk->constants.values[constant]);
    printf("' \n");

    return off_set + 2;
}

int disassemble_instruction(chunk* chunk, int off_set) {
    printf("%04d ", off_set);

    if (off_set > 0 && chunk->lines[off_set] == chunk->lines[off_set - 1]) {
        printf("   |  ");
    } else {
        printf("%4d ", chunk->lines[off_set]);
    }

    uint8_t instruction = chunk->code[off_set];

    switch (instruction) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, off_set);
        case OP_RETURN:
            return simple_instruction("OP_RETURN", off_set);
        default:
            printf("unknown opcode %d \n", instruction);
            return off_set + 1;
    }
}