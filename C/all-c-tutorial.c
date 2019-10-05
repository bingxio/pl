/**
 * This is note for my learning C Programming Language.
 * The C language is built after 50 years ago and it very classic.
 * If you want to study computer programming language that I suggest you study C language first.
 * Because it is minish, strong performance, first high level language and most widely used.
 * Such as Linux OS and Python compiler all built on C.
 * 
 * Let's check it out !!
 */
// If you see the `#` character on start that explain it is macro use.
// The `include` can quote other source and stdlib library.
// This line is Import Input and Output with std library.
#include <stdio.h>
// Or we also can use double quotation marks to import.
// Usually `.h` file extension is header source file and I can import it.
#include "stdio.h"
// This line is import string library it have many method to handle string.
#include <string.h>
#include <stdlib.h>
// This is function defintion before call.
void test_recursion (int x);
// Function was defined before call.
// The `static` keyword explain this function is only show in this file.
// Not show in other file when was include.
static void test (char* name, int age) {
  if (strlen(name) != 0) {
    printf("%s age = %d\n", name, age);
  }
}
// Declare the inline function header.
// Be careful the inline function can not write `inline` keyword to defintion header.
char* test_inline (int x);
// This is a function in C.
// The name is `main` and the program will start on this function.
// It is must be define in each source program.
int main() {
  // After left brace this block is function body.
  // We can write statements here.
  // The `printf` function can output to screen.
  // It is native function.
  printf("Hello World\n");
  // This is variable define statement.
  // <Type> <Name> = <Expr>;
  // The C have many variable type with std and there only use integer type.
  //
  // Output and array data in C.
  //
  int number = 20;
  // At 40 years ago.
  // The C not have string literal but it have char type.
  // We can use pointer type for char to define a string literal.
  // So `str` is a pointer and it is a char array.
  char* str = "This is a string literal chars.";
  // The string literal have `\0` char end of literal.
  // If use array to define string we must add a `\0` in the end to explain use memory end.
  char str2[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
  // This is define a integer array.
  // We can explain the size of array and we can not define it.
  // Must is same type in array values.
  int arr[5] = { 1, 2, 3, 4, 5 };
  // Change the third value to eight in array.
  arr[3] = 8;
  // The `printf` function can have format to output many variable.
  // Use `\n` char to enter a new line.
  // And have '\t' and '\r' more.
  // The `arr[2]` is get the second value in array.
  printf("%d %s %s, %d\n", number, str, str2, arr[2]);
  //
  // Control flow in C.
  //
  // Define two integer variable only line.
  int a = 20, b = 21;
  // The `const` keyword is decorate variable value is fixed and can't changed.
  const int c = 80;
  // The `static` keyword is decorate variable was allocated on heap and,
  // not drop when scope destory !!.
  // Usually use in function.
  static int s_value = 200;
  // `if` Control Flow Statement.
  // if (<Expr>) {}
  // If the expression value is true or greater and equal 1,
  // Execute the body.
  if (a > b) {
    // This is a block.
    // We can write more statement here.
    printf("A is greater than B.");
    printf("The block was executed.");
    // Else if control expression.
  } else if (a == b)
    // This not is a block and just only one statement write here.
    printf("A equal B");
  else
    // Else branch explain the end of control expression.
    printf("A is less than B\n");
  // We can import std libray any where.
  // After this line the program can use boolean value.
  #include <stdbool.h>
  // This is `while` statement that can start a dead loop.
  // while (<Expr>) {}
  while (true) {
    // If the number value is zero to stop loop.
    if (number == 0)
      break;
    // If the number value is eight,
    // The loop will continue next loop on here.
    // Explain after there statements is not executed.
    if (number == 8) {
      printf("Start the next loop.\n");
      // Be careful the control expression,
      // Must not become to dead cycle.
      number --;
      continue;
    }
    // Output the number value on every loop.
    printf("%d\t", number);
    // The number subtract one on every loop.
    number --;
  }
  // The `for` statement is a cycle expression.
  // It have three expression and very easy to use it.
  // for (<Init Expr>; <Control Expr>; <Update Expr>) {}
  for (int i = 0; i < 5; i ++) {
    // This will output the even number in array.
    // Also we can use `continue` and `break` keyword here to control loop.
    if (arr[i] % 2 == 0) printf("%d\t", arr[i]);
    // Will enter a new line at last loop.
    if (i + 1 == 5) printf("\n");
  }
  //
  // Pointer in C.
  //
  // This is a important concept: `Pointer`.
  // This variable is allocate in stack on memory.
  int value = 23, haha = 45;
  // This variable is allocate in heap on memory.
  // The `*` char explain it is a pointer variable.
  // It value is a address for variable on memory !!
  int* ptr = &value;
  // Also I can use `*` operator to change value with not use address.
  *ptr = 103;
  // Change the address value for pointer.
  ptr = &haha;
  // This line will change the value for `haha`.
  // And the `ptr` pointer value was changed !!
  // Because the address of memory is changed that pointer value is changed.
  haha = 48;
  // Output the value of variable.
  printf("%d %d\n", value, *ptr);
  // Use some method to manage memory pointer.
  // Be careful the `stdlib.h` must be declared on file header not `main` function.
  // #include <stdlib.h>
  // The `free` method can clear the pointer value memory.
  // The `ptr` value will be NULL.
  free(ptr);
  // This value is allocate on stack.
  int num = 45;
  // The `const` keyword to explain:
  // Pointer -> Mutable && Value -> Immutable
  const int *num_ptr1 = &num;
  /**
   * // Pointer -> Mutable && Value -> Immutable
   * int const* num_ptr2 = &num;
   * // Pointer -> Mutable && Value -> Immutable
   * int* const num_ptr3 = &num;
   * // Pointer -> Immutable && Value -> Immutable
   * const int* const num_ptr4 = &num;
   */
  //
  // Control flow in C.
  //
  // This is `switch` statement it can judge more expression than `if` statement.
  // switch (<expr>) {}
  // The conditional of switch statement is only integer and char value !!
  switch (value) {
    case 1:
    case 2:
      // When expr value is 1 or 2 will execute here.
      printf("The value is 1 or 2.");
      // Usually use `break` statement to go out `switch` statement.
      // If have not then execute next `case` body.
      break;
    // I can judge a char value because it can judge ascii code.
    case 'g':
      printf("The value ascii char is 'g' and integer is 103\n");
      break;
    // At end if no `case` statement was called.
    // There is a block statement in body.
    default: {
      printf("Unknown value !!");
      printf("The switch statement will drop.");
    }
  }
  // It mean is that do.
  // Go to the defintion and execute it.
  // Be careful if block is defined before `goto` statement that it will to be a loop !!.
  goto block;
  // Just use <identifier>: <block>.
block:
  printf("Called in a block with goto statement !!\n");
  // We can use a brace block to create new scope.
  // A new scope !!
  {
    // Create a new scope variable.
    int a = 29;
    // Be careful there can exit scope.
    if (a > 100)
      // If the `a` value greater than one hundred that return it.
      // Explain exit the scope and not execute statement after there.
      // The `main` function return type is integer so I returned a zero.
      return 0;
    // Not execute this output statement.
    printf("a = %d\n", a);
  }
  //
  // Function data in C.
  //
  // If the function defined after caller.
  // We should declare the function before call !!
  void fun_no_return ();
  void fun_have_parameter (int a, int b);
  // Have return value function.
  float fun_have_parameter_return (float a, double b);
  // Also We can only appoint the type of parameters.
  int fun_return_max (int, int);
  // Call my function.
  fun_no_return();
  // Call my function will parameter.
  fun_have_parameter(12, 22);
  // Call my function and return the sum of parameters.
  float fn_ = fun_have_parameter_return(1.4, 2.5);
  // Call my function and return the max of parameters.
  int max = fun_return_max(100, 200);
  // Output.
  printf("%f\n", fn_);
  printf("%d\n", max);
  // This is output even number function defintion.
  void output_even_number (int *, int);
  // Array.
  int list[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  // Call.
  output_even_number(list, 8);
  // The end value was changed.
  printf("end = %d\n", list[7]);
  // I can use recursion with function.
  test_recursion(-2);
  // Test static function declare here.
  void test_static ();
  // Test.
  test_static();
  test_static();
  test_static();
  // Test the inline function.
  for (int i = 0; i < 100; i ++) {
    // This is call inline function.
    // The inline function will replace the call code to function body.
    // The body statement in inline function must be mini.
    // Replace -> printf("%s\n", i % 2 == 0 ? "radix" : "even");
    printf("%s\n", test_inline(i));
  }
  //
  // Struct data in C.
  //
  struct Book {
    // There is parameters in struct.
    int id;
    // Like variable defintion.
    // <Type> <Identifier>;
    char* name;
  };
  // Create a new struct type variable.
  // struct <Identifier> <Identifier>;
  struct Book CPrimerPlus;
  // Use dot character to define parameters in struct data.
  CPrimerPlus.id = 23;
  CPrimerPlus.name = "C Primer Plus !!";
  // And I can define data on allocate.
  struct Book MyStory = { 24, "The story of me." };
  // Output.
  printf("id = %d, name = %s\n", CPrimerPlus.id, CPrimerPlus.name);
  printf("id = %d, name = %s\n", MyStory.id, MyStory.name);
  //
  // Typedef keyword in c。
  //
  typedef int integer;
  typedef char* string;
  // Return -> int
  // Parameters -> char *name, int age
  typedef void (* function) (char *name, int age);
  // The `typedef` keyword can define a new name use same type.
  // Like int.
  integer int_type = 300;
  // Like char*.
  string str_type = "fuck !!";
  // Like struct.
  typedef struct {
    int id;
  } Foo;
  // A struct was allocate on heap.
  Foo* foo;
  // Pointer to set value.
  foo->id = 244;
  // Output.
  printf("%d\n", foo->id);
  // The `function` type can assign a function !!
  // That the `test_func` is `test` function !!
  function test_func = test;
  // Test typedef function type.
  test_func("this author", 18);
  //
  // Union type in c.
  // All parameters is sharing the same storage area !!
  // At the same time only the value of one of its members can be saved.
  // When the value of a union member is changed, 
  // The value of all members of the union is actually modified.
  // The size in memory of union is max members type in union.
  //
  typedef struct {
    // This paramater self is struct.
    int sum;
    // The `union` type like a new struct type.
    // It is allocated in parent struct.
    union {
      // Parameters.
      bool have;
      // It size in memory is `double` variable.
      double value;
      // And have a name like variable.
    } as;
  } Value;
  // A new struct variable.
  // At this line I defined two parameters in union type that,
  // The `have` parameter value is null and the `value` is ok.
  Value val = { 23, { .have = false, .value = 45.6 } };
  // The `if` statement conditional is true and body will execute ??
  // Because the `have` parameter is find out the address in memory.
  // It is always true !!
  if (val.as.have) {
    printf("%d %f\n", val.sum, val.as.value);
  }
  // At main function usually returned a integer value.
  // Returned a zero value.
  return 0;
}
// The function return type is `void` to explain no return value.
// Function Declare: <ReturnType> <FuncName> (<FuncParameter>) {}
void fun_no_return () {
  // Scope in function body.
  printf("There is called function !!\n");
  printf("Haha ~~\n");
  // A new variable created in scope.
  // It will drop on scope end.
  int a = 20;
  // Output.
  printf("++ a = %d\n", ++ a);
  // The variable `a` will drop here.
}
// Define function will two parameters.
// The function will output the sum in body.
void fun_have_parameter (int a, int b) {
  if (a < 0)
    // This `return` keyword can exit the function.
    return;
  printf("a + b = %d\n", a + b);
}
// Return sum of two float.
float fun_have_parameter_return (float a, double b) {
  return a + (float) b;
}
// Return max of two numbers.
int fun_return_max (int x, int y) {
  int max = x > y ? x : y;
  // How is `return` keyword to do ?
  // 1.Return the scope.
  // 2.Return the scope and an value have returned.
  if (max < 0)
    return -1;
  else {
    printf("max = %d\n", max);
    return max;
  }
}
// Output the even number of array.
// Be careful if parameter is array that we can change it value !!
void output_even_number (int* arr, int len) {
  for (int i = 0; i < len; i ++)
    if (arr[i] % 2 == 0) 
      printf("%d\t", arr[i]);
  printf("\n");
  // Replace the value at end of array.
  // *arr[len] = 88;
}
// The recursion for function.
void test_recursion (int x) {
  if (x < 0)
    // Call self.
    test_recursion(100);
  else
    // Output x value and return scope.
    printf("x = %d and drop function.\n", x);
}
// Test the static function.
void test_static () {
  // Static variable declare in function.
  static int a = 78;
  // Output the variable and plus one after output.
  printf("a = %d\n", a ++);
}
// Test the inline function.
inline char* test_inline (int x) {
  // Return a string literal.
  return x % 2 == 0 ? "radix" : "even";
}
