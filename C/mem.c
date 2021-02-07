//
// Copyright (c) 2021 bingxio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// memory processing of C language.
int main() {
    int len = 5;
    //
    // scanf("%d", &len); // NOLINT(cert-err34-c)
    // The `calloc` function will allocate memory with length and
    // all items is zero.
    int *arr = (int *) calloc(len, sizeof (int));
    // 0 0 0 0 0..
    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
    //
    free(arr);
    // pointer is freed on top, but its value is not NULL.
    printf("NULL ? %s\n", arr == NULL ? "T" : "F");
    // must set its point to NULL,
    // original its point to freed memory.
    arr = NULL;
    printf("NULL ? %s\n", arr == NULL ? "T" : "F");
    if (arr != NULL) printf("ERR !!\n");
    //
    struct Name {
        // length of elements.
        int len;
        // memory capacity of self.
        int cap;
        // elements
        void *elem;
    };
    //
    // both are NULL in heap memory.
    // if want to use its field will throw error!!
    struct Name *a = NULL;
    struct Name *b = NULL;
    //
    printf("%d %d\n", a == NULL, b == NULL);
    //
    struct Name x; // in stack memory.
    // the `NULL` identification likes keyword,
    // its a value!!
    // there will output its not NULL, that is F
    printf("%d %d %d\n", x.len, x.cap, x.elem == NULL);
    /*
    struct Name *y; // in heap memory.
    // do not give it some value here only statement.
    printf("%d %d %d\n"
           "---------------------\n",
           y->len, y->cap, y->elem == NULL);
    */
    a = malloc(sizeof(struct Name));
    b = malloc(sizeof(struct Name));
    //
    printf("%d %d \na: %d %d\nb: %d %d\n", a == NULL, b == NULL,
           a->len, a->cap,
           b->len, b->cap);
    // initializer
    a->len = 0;
    a->cap = 0;
    a->elem = NULL;
    //
    printf("l: %d c: %d e: %d\n", a->len, a->cap, a->elem == NULL);
    //
    for (int i = 97; i < 123; i ++) {
        if (a->len + 1 > a->cap) {
            // grow capacity
            a->cap = a->cap == 0 ? 8 : a->cap * 2;
            a->elem = realloc(a->elem, sizeof (char) * a->cap);
        }
        // append
        ((char *) a->elem)[a->len ++] = (char) i;
    }
    for (int i = 0; i < a->len; i ++) {
        printf("%c ", ((char *) a->elem)[i]);
    }
    //
    printf("\nl: %d c: %d", a->len, a->cap);
    //
    // clear all
    free(a->elem);
    //
    a->len = 0;
    a->cap = 0;
    a->elem = NULL;
    //
    return 0;
}
