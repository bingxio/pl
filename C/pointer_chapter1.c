#include "stdio.h"

int main() {
  int a = 20;

  int *ptr = &a;

  printf("ptr = %p *ptr = %d \n", ptr, *ptr);

  a ++;

  printf("ptr = %p *ptr = %d \n", ptr, *ptr);

  return 0;
}
