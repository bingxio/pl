#include<stdio.h>
#include<stdbool.h>

typedef struct {
    int precedence;

    union {
	    bool isNumber;
	    double value;
    } as;
} Value;

int main() {
	Value a = { 23, { .isNumber = false, .value = 2.4 } };
	
	if (a.as.isNumber) {
		printf("%d %d %f\n", a.precedence, a.as.isNumber, a.as.value);
	}

	return 0;
}
