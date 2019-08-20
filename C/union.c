#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int precdence;
	
    union {
      	bool boolean;
      	double number;
    } as;
} Value;

#define NUMBER_VAL(value) ((Value) { 1, { .number = value } })

int main() {
    Value a = NUMBER_VAL(12.5);
	
    printf("precdence = %d \n", a.precdence);
    printf("it number = %f \n", a.as.number);
	
	return 0;
}
