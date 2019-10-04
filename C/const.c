#include <stdio.h>

int main() {
  // 最普通的常量，栈上，它的值不变
  const int a = 23;
  // 栈上的普通变量
  int num = 45, test = 88;
  // 修饰指向的对象，指向可变，指向的对象不可变
  const int* b = &num;
  // 修饰指向的对象，指向可变，指向的对象不可变
  int const* c = &num;
  // 修饰指针，指向不可变，指向的对象可变
  int* const d = &num;
  // 修饰指针和对象都不可变
  const int* const e = &num;
  
  // a = 23, b = 45, c = ?, d = ?, e = ?
  printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, *b);
  // num = 45
  printf("num = %d\n", num);

  return 0;
}
