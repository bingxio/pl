#include <stdio.h>

#include "vm.h"
#include "common.h"
#include "debug.h"

VM vm;

void init_vm() {

}

void free_vm() {

}

static interpret_result run() {
#define READ_BYTE() (* vm.ip ++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        disassemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif

        uint8_t instruction;

        switch (instruction == READ_BYTE()) {
            case OP_CONSTANT: {
                value constant = READ_CONSTANT();
                print_value(constant);
                printf("\n");
                break;
            }
            case OP_RETURN: {
                return INTERPRET_OK;
            }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

interpret_result interpret(chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;

    return run();
}