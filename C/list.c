#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void **data;
    int len;
    int cap;
} list;

list *new_list() {
    list *l = (list*) malloc(sizeof(list));
    l->data = NULL;
    l->len = 0;
    l->cap = 0;
    return l;
}

void append(list *l, void *ptr) {
    if (l->cap == 0 || l->cap + 1 > l->len) {
        l->cap =
            l->cap == 0 ? 4 : l->cap * 2;
        l->data = realloc(l->data, sizeof(void *) * l->cap);
    }
    l->data[l->len ++] = ptr;
}

// struct Foo {int x;};

int main() {
    list *l = new_list();
    append(l, (int *)34);
    append(l, (int *)65);
    append(l, (int *)22);
    append(l, (int *)46);
    append(l, (int *)13);
    append(l, (int *)76);
    append(l, (int *)54);
    append(l, (int *)74);
    
    for (int i = 0; i < l->len; i ++) {
        printf("%d: %d\n", i+1, (int *)(l->data[i]));
    }
    // append(l, "dsad");
    // append(l, "ergc");
    // append(l, "jjnf");
    // append(l, "dsad");
    // append(l, "tred");
    // append(l, "7643");
    // for (int i = 0; i < l->len; i ++) printf("%s\n", l->data[i]);
/*     struct Foo f = {.x = 34};
    append(l, &f);
    struct Foo f1 = {.x = 87};
    append(l, &f1);
    struct Foo f2 = {.x = 46};
    append(l, &f2);
    struct Foo f3 = {.x = 11};
    append(l, &f3);
    struct Foo f4 = {.x = 86};
    append(l, &f4);
    struct Foo f5 = {.x = 36};
    append(l, &f5);
    for (int i = 0; i < l->len; i ++) {
        struct Foo *f = (struct Foo *)l->data[i];
        printf("%d\n", f->x);
    } */
    return(0);
}
