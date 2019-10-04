#include <stdio.h>

void static_func () {
  static int a = 20;
  
  printf("++ a = %d\n", ++ a);
}

int main() {
  static_func();
  static_func();
  static_func();
  return 0;
}
