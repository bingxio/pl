#include "stdio.h"
#include "stdlib.h"

int plus(int a, int b) {
    return a + b;
}

struct Book {
    int id;
    char *name;
};

typedef struct Book c_primer_plus;

void edit_book_name(c_primer_plus *book, char *name) {
    book->id = book->id + 1;
    book->name = name;
}

int main() {
    unsigned char a = 'm';
    unsigned char *b = &a;

    printf("%p %c \n", b, *b);

    int c = plus(12, 6);

    int *d = &c;

    printf("%d \n", *d);

    c_primer_plus *book = malloc(sizeof (c_primer_plus));

    book->id = 1;
    book->name = "the meet programming language";

    printf("%d %s \n", book->id, book->name);

    edit_book_name(book, "the java programming language");

    printf("%d %s \n", book->id, book->name);
}