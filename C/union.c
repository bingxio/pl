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
    // The union type can only be set to same type as this.
    Value a = { 23, { .isNumber = false, .value = 2.4 } };
    
    if (a.as.isNumber) {
        printf("%d %d %f\n", a.precedence, a.as.isNumber, a.as.value);
        // If it is a different type.
        // Value a;
        // a.as.isNumber = false;
        // a.as.value = 1.2;
    }
    
    return 0;
}
