#ifndef VM_H
#define VM_H

#define STACK_MAX 256

#include "chunk.h"

typedef struct {
    Chunk* chunk;

    uint8_t* ip;

    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(Chunk* chunk);

void push(Value value);
Value pop();

#endif
