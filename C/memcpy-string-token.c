#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    const char* current = "if (a > 0) -> println a";

    int i = 0;

    while (i < strlen(current)) {
        printf("%-2d: %-3c ", i, *(current + i ++));

        if (i % 10 == 0)
            printf("\n");
    }

    printf("\n");

    char* literal = (char *) malloc(2);

    current += 2;

    memcpy(literal, current - 2, 2);

    literal[2] = '\n';

    printf("literal = %s", literal);

    return 0;
}
