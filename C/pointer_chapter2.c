#include "stdio.h"
#include "string.h"

void show(int arr[], int size) {
  for (int i = 0; i < size; i ++)
    printf("%5d", arr[i]);
  printf("\n");
}

void show_with_pointer(const int *arr, int size) {
  for (int i = 0; i < size; i ++)
    printf("%5d", arr[i]);
  printf("\n");
}

void show_with_string(const char *arr) {
  for (int i = 0; i < strlen(arr); i ++)
    printf("%5c", arr[i]);
  printf("\n");
}

int main() {
  int arr[10] = { 2, 4, 6, 8, 10, 12, 14 };

  char *word = "hello world";

  show(arr, 10);
  show_with_pointer(arr, 10);
  show_with_string(word);
}