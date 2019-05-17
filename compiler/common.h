#ifndef COMMON_H
#define COMMON_H

#include "stdbool.h"
#include "stdint.h"
#include "stddef.h"

#define DEBUG_TRACE_EXECUTION

typedef enum {
    OP_CONSTANT,
    OP_RETURN
} op_code;

#endif
