#include <stdio.h>

void static_value () {
  static int a = 20;
  
  printf("++ a = %d\n", ++ a);
}

static void static_func () {
  printf("Call static function.");
}

int main() {
  static_value();
  static_value();
  static_value();
  
  static_func();
  
  return 0;
}
