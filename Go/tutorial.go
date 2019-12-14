// This file is a tutorial for Go programming language.
// The Go is very popular on China more company was used it.
// It's have very simple syntax and strong performance and I like it !
//
// Appoint this file is main entrance of project because it's `main` package.
// The program was execute this file first.
package main

// I can import standard and custom library.
import (
  "fmt"
  "time"
)

// Use `itoa` keyword to assign many const variables.
const (
  x1 = iota   // 0
  x2          // 1
  x3          // 2
  x4 = "Test" // Test
  x5          // Test
  x6 = iota   // 5
)

// This is main entrance function.
func main() {
  // Call function in standard library.
  fmt.Println("Hello Go !!")
  // I can write down type to variable define.
  var a int = 45
  // There is type checker.
  var b = "Hello World"
  // Assign to default value.
  var c bool
  // Create many variable use `var` keyword.
  var x, y = 56, 2.5
  // Use paren block to create many variables.
  var (
    t1 = "34"
    // Array.
    t2 = [] int{99}
  )
  /*
   * The `var` keyword is not standard to used in scope,
   * It usually used out of scope like public and const variable.
   */
  //
  // IMMutable variable.
  const WIDTH int = 200
  // Output its.
  fmt.Println(a, b, c, x, y, WIDTH, t1, t2)
  // 0 1 2 Test Test
  fmt.Println(x1, x2, x3, x4, x5, x6)
  // Create a new array list use assign syntax.
  // <ident> := <expr>
  arr := [] int{34, 55, 22, 12, 54, 33}
  // Get iterator of array generate key and value.
  // k, v := range <array>
  for _, v := range arr {
    // Call function in standard library.
    print(v, " ")
  }
  //
  for i := 0; i < 5; i++ {
    if i == 3 {
      // There will be exit loop.
      break
    } else {
      // Go to next.
      fmt.Println(i)
      continue
    }
    // Not be executed.
    fmt.Println(i)
  }
  // Dead cycle.
  for {
    break
  }
  // If condition statement.
  // It's no difference in other programming language.
  if 1 > 2 {
    // The body must be write down brace block.
    fmt.Println("Error !!")
  } else if 2 > 3 {
    fmt.Println("Error !!")
  } else {
    fmt.Println("OK !!")
  }
  // Switch statement.
  switch 34 + 56 {
  case 0:
    println("Error !!")
    // The case statement is default to have `break` keyword.
    // And isn't to do next branch.
  case 90:
    println("OK")
    // I can use `fallthrough` keyword to continue execute next branch.
    fallthrough
  case 100:
    println("Called !!")
  default:
    // Default branch.
    println("Default branch..")
  }
  // Select is a control structure in go.
  // Similar to the switch statement used for communication.
  // Each case must be a communication operation, either sending or receiving.
  c1 := make(chan string)
  c2 := make(chan string)
  // Select randomly executes a runnable case.
  // If there is no case to run, it will block until there is a case to run.
  // A default clause should always be runnable.
  go func() {
    time.Sleep(time.Second * 3)
    c1 <- "video data"
  }()
  // Goroutine anonymous function..
  go func() {
    time.Sleep(time.Second * 5)
    c2 <- "audio data"
  }()
  // Use loop to get two select statement.
  for i := 0; i < 2; i++ {
    select {
    // If the c1 was received and assign to variable.
    case msg := <-c1:
      fmt.Println("Received: ", msg)
    // If the c2 was received and assign value and is ok variables.
    case msg, ok := <-c2:
      if !ok {
        // Failed.
        fmt.Println("Received Failed..")
      }
      fmt.Println("Received: ", msg)
    }
  }
  // Integer variable defined.
  r1 := 20
  // This is loop statement with label expression.
  // Not like is to C language.
LOOP:
  // Loop !
  for r1 > 0 {
    if r1 == 9 {
      r1--
      // Go to next loop like to `continue` keyword.
      // There is not like to C language.
      goto LOOP
    }
    // Output current value of variable.
    fmt.Printf("% 2d\n", r1)
    r1--
  }
  // Call function with two parameters amd returned value.
  println(add(2, 5))
  println(addWithError(23, 55))
  // This line will panic a message.
  // println(addWithError(45, 4.5))
}

// Two parameters.
// Returned number of plus a + b.
func add(a, b int) int {
  return a + b
}

// Two parameters `int` and `interface{}`,
// The `interface{}` is any types.
// If type of b is not int then panic message else returned a + b.
func addWithError(a int, b interface{}) int {
  // I can use `switch` statement to catch variable type.
  // If I want to get type of variable,
  // Must use `switch` statement to case its.
  switch b.(type) {
  case int:
    // There used type inference to integer.
    return a + b.(int)
  default:
    panic("Please follow type of function parameters.")
  }
}
