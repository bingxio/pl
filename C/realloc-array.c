#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
    int* code = NULL, size = 0;

	int a[] = {23, 45, 65, 3, 43, 23, 32, 0}, i = 0;

	while (true) {
		if (a[i] > 0) {
			if (i >= size)
				code = (int *) realloc(code, size);
			code[size ++] = a[i ++];
		} else
			break;
    }

	printf("size = %d\n", size);

	for (int i = 0; i < size; i ++)
		printf("%-5d", code[i]);

    free(code);

	return 0;
}
