#include <stdio.h>
#include <string.h>

typedef int (* function) (char* message);

int test(char* message) {
  return strlen(message);
}

int main() {
  function a = test;
	
  int len = a("hello world");
	
  printf("byte = %d \n", len + 1);
	
  return 0;
}
