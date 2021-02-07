//
// Copyright (c) 2021 bingxio. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

enum obj_type {
    Num,
    Str,
};

typedef struct {
    enum obj_type type;
    union {
        double num;
        char* str;
    } val;
} obj;

typedef struct {
    int** item;

    uint8_t* code;

    obj* data;
    obj* cons;
    obj* vars;
    obj* name;
} frame;

void init_frame(frame* f) {
    f->item = {
        {3, 5},
        {3, 5},
        {3, 5},
        {3, 5},
        {3, 5},
    };
    f->code = NULL;
    f->data = NULL;
    f->cons = NULL;
    f->vars = NULL;
    f->name = NULL;
}

void write_frame(frame* f, uint8_t byte) {

}

void free_frame(frame* f) {
    free(f->code);
    init_frame(f);
}

enum opcode {
    loa,
    con,
    nam,
    ret
};

int main(int argc, char** argv) {
    printf("argc = %d argv = %s\n", argc, *argv);
    frame arr;

    init_frame(&arr);

    write_frame(&arr, loa);
    write_frame(&arr, con);
    write_frame(&arr, nam);
    write_frame(&arr, ret);

    free_frame(&arr);

    return 0;
}
