#include "stdio.h"

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a > b ? b : a;
}

int main() {
  int (* a) (int, int) = max;
  int (* b) (int, int) = min;

  int s = 0, d = 0;

  printf("input two number to print max value and min value: \n");

  scanf("%d %d", &s, &d);

  printf("max = %d, min = %d \n", a(s, d), b(s, d));
}