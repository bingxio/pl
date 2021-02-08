//
// Copyright (c) 2021 bingxio. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    loa,
    con,
    nam,
    ret
} opcode;

const char* opcode_str(opcode byte) {
    switch (byte) {
        case loa:
            return "loa";
        case con:
            return "con";
        case nam:
            return "nam";
        case ret:
            return "ret";
        default:
            return NULL;
    }
}

typedef enum{
    num,
    str,
} obj_type;

typedef struct {
    obj_type type;
    union {
        double* num;
        char* str;
    } val;
} obj;

void init_obj(obj* obj, obj_type type, void* value) {
    obj->type = type;
    switch (obj->type) {
        case num:
            obj->val.num = (double *) value;
            break;
        case str:
            obj->val.str = (char *) value;
            break;
    }
}

void free_obj(obj* obj) {
    obj->type = -1;
}

typedef struct {
    int item[5][2];

    uint8_t* code;

    obj* data;
    obj* cons;
    obj* vars;
    obj* name;
} frame;

void init_frame(frame* f) {
    int back[5][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };
    memcpy(f->item, &back, sizeof back);
    f->code = NULL;
    f->data = NULL;
    f->cons = NULL;
    f->vars = NULL;
    f->name = NULL;
}

#define CODE 1
#define DATA 2
#define CONS 3
#define VARS 4
#define NAME 5

void grow_cap(frame* f, int mode) {
    int x;
    int y;
    switch (mode) {
        case CODE:
            x = f->item[0][0];
            y = f->item[0][1];
            break;
        case DATA:
            x = f->item[1][0];
            y = f->item[1][1];
            break;
        case CONS:
            x = f->item[2][0];
            y = f->item[2][1];
            break;
        case VARS:
            x = f->item[3][0];
            y = f->item[3][1];
            break;
        case NAME:
            x = f->item[4][0];
            y = f->item[4][1];
            break;
        default:
            return;
    }
    if (x + 1 > y) {
        y = y == 0 ? 8 : y * 2;
        if (mode == CODE) {
            f->item[0][1] = y;
            f->code = realloc(f->code, sizeof (uint8_t) * y);
            return;
        }
        if (mode == DATA) {
            f->item[1][1] = y;
            f->data = realloc(f->data, sizeof (obj) * y);
            return;
        }
        if (mode == CONS) {
            f->item[2][1] = y;
            f->cons = realloc(f->cons, sizeof (obj) * y);
            return;
        }
        if (mode == VARS) {
            f->item[3][1] = y;
            f->vars = realloc(f->vars, sizeof (obj) * y);
            return;
        }
        f->item[4][1] = y;
        f->name = realloc(f->name, sizeof (obj) * y);
        return;
    }
}

void write_frame(frame* f, void* value, int mode) {
    grow_cap(f, mode);
    switch (mode) {
        case CODE:
            f->code[f->item[0][0] ++] = *(opcode *) value;
            break;
        case DATA:
            f->data[f->item[1][0] ++] = *(obj *) value;
            break;
        case CONS:
            f->cons[f->item[2][0] ++] = *(obj *) value;
            break;
        case VARS:
            f->vars[f->item[3][0] ++] = *(obj *) value;
            break;
        case NAME:
            f->name[f->item[4][0] ++] = *(obj *) value;
            break;
        default:
            return;
    }
}

void free_frame(frame* f) {
    free(f->code);
    free(f->data);
    free(f->cons);
    free(f->vars);
    free(f->name);
    init_frame(f);
}

int main(int argc, char** argv) {
    printf("argc = %d argv = %s\n", argc, *argv);
    frame arr;

    init_frame(&arr);

    write_frame(&arr, (opcode *) con, CODE);
    write_frame(&arr, (opcode *) nam, CODE);
    write_frame(&arr, (opcode *) ret, CODE);

    obj obj;
    init_obj(&obj, str, "Hello World !!");

    free_frame(&arr);
    free_obj(&obj);

    return 0;
}
