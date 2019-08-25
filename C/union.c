#include<stdio.h>
#include<stdbool.h>

typedef struct {
  int precedence;

  // Memory Allocation of Magic.
  union {
    bool isNumber;
    double value;
  } as;
} Value;

int main() {
  // The union type can only be set to same type as this.
  Value a = { 23, { .isNumber = false, .value = 2.4 } };
    
  // It is always true, because it address is "next door", like integer 51.
  if (a.as.isNumber) {
    printf("%d %d %f\n", a.precedence, a.as.isNumber, a.as.value);
    // If it is a different type.
    // Value a;
    // a.as.isNumber = false;
    // a.as.value = 1.2;
  }
    
  return 0;
}
