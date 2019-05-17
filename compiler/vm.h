#ifndef VM_H
#define VM_H

#include "chunk.h"

typedef struct {
    chunk* chunk;

    uint8_t* ip;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} interpret_result;

void init_vm();
void free_vm();

interpret_result interpret(chunk* chunk);

#endif