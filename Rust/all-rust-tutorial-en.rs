// I want only use one file to tell about rust programming language.
// it include more details and basics, my english is too bad, practice it !
// Rust is System level programming language, it run fast like c and c++
// Rust not have gc, it use life time and owner ship to keep system memory safety.
// The microsoft will use Rust in the future.
// Does this mean that c or c++ will be eliminated ?
fn main() {
  // A enum data defined here,
  // Explain how to compare two Color, display or debug it.
  enum Color {
    RED,
    BLUE
  }

  // If want to display it, we should implement Debug trait for Color.
  // Use `{:?}` to debug display, `{}` should implement `std::fmt::Display` for Color.
  impl std::fmt::Debug for Color {
    // Implement this function.
    // First parameter is Color self, Second parameter is custom formatter.
    // The function return `std::result::Result`, display errors when has some error.
    fn fmt(&self, f: &mut std::fmt::Formatter) -> Result<(), std::fmt::Error> {
      // Then, match all enum data.
      match self {
        // The `write!()` is macro function, it can display on screen.
        // More macro function is wait for learn, like `writeln!()` output line break.
        Color::RED => write!(f, "Color -> RED"),
        Color::BLUE => write!(f, "Color -> BLUE")
      }
    }
  }

  // We need define a struct data to compare it.
  // Second parameter is we need compare.
  // This defined struct mode was use tuple.
  struct Flower(u8, Color);

  // Implement `PartialEq` for struct.
  impl std::cmp::PartialEq for Flower {
    // Two parameters part is a and b.
    // Both are reference type, return bool to compare.
    fn eq(&self, other: &Self) -> bool {
      // This is point, we compare at second parameter.
      // We can not compare if both are enum data.
      self.0 == other.0
    }
  }

  // Define two variables as enum parameters.
  let a = Flower(3, Color::BLUE);
  let b = Flower(5, Color::RED);

  fn flower_color_compare(a: Flower, b: Flower) {
    // Look this conditional expression, Ha ha ~
    // We can use equal operator to compare it !
    println!("{}", if a == b {
      "flower a is like for b."
    } else {
      "flower a is not like for b."
    });
  }

  flower_color_compare(a, b);

  // This line was add HashMap data to program.
  use std::collections::HashMap;

  // We can not define key parameter and value parameter.
  // Automatic judgment after insert data.
  let mut a = HashMap::new();

  // The key type is `i32`, value type is `&str`.
  a.insert(32, "43");
  a.insert(12, "56");

  // This function can replace HashMap's get function.
  // Return a `Result`, it can custom error message.
  fn search_map_value(a: HashMap<i32, &str>, k: i32) -> std::result::Result<&str, &'static str> {
    if a.get(&k) == None {
      // Custom error message.
      Err("can not find value for hash map.")
    } else {
      Ok(a.get(&k).unwrap())
    }
  }

  // The `Result` was return Ok and Err struct.
  // We can judge it.
  match search_map_value(a.clone(), 12) {
    // The parameter inside is value or error.
    Ok(v) => println!("{}", v),
    Err(e) => println!("{}", e)
  }

  // Some test.
  println!("v = {:?}", search_map_value(a.clone(), 32));
  println!("v = {:?}", search_map_value(a.clone(), 12));
  println!("v = {:?}", search_map_value(a.clone(), 44));

  // The variable x was allocate to the stack.
  let x = 20;

  {
    // Define local variable y.
    // It variable scope is between lines 102 and 112.
    let y = 30;
    // Run successfully, the variable x and y scope here.
    println!("x = {} y = {}", x, y)

    // The variable y dropped here.
    // Because y was allocate to the stack and it is a local variable.
    // It can be said that block statements can allocate new scopes.
  }

  // Error: Undefined variable y, it dropped at line 112.
  // println!("x = {} y = {}", x, y)

  // We can use `vec!` macro function to define empty vector.
  let mut a = vec![];

  // The for loop can traverse a range as array or custom.
  // Get even number list between 1 and 50.
  for i in 1..50 {
    if i % 2 == 0 {
      // Insert item function of vector.
      // First parameter default is vector's length.
      a.insert(a.len(), i);
    }
  }

  // If we need by way of dictionary.
  // Use `iter()` and `enumerate()` function.
  for (k, v) in a.iter().enumerate() {
    // Display them in a dictionary.
    if k % 2 == 0 {
      println!("k = {} v = {}", k, v);
    }
  }

  // Define multiple variables at one time.
  // Not is tuple type.
  let (a, b) = (23, "the system level programming language is rust");

  // If we need more beautiful display, we should format display.
  // Let second parameter value alignment its later display.
  // 23    the system level programming language is rust
  // 23 23 the system level programming language is rust
  println!("{:<5} {}", a, b);
  println!("{} {} {}", a, a, b);
  // Display six decimal, need format.
  println!("{}", format!("{:.*}", 6 as usize, 3.5));

  // Mutable tuple type.
  let mut a = (23, 43, 8);
  println!("{} {} {}", a.0, a.1, a.2);

  match a.0 {
    // We can judge multiple value in one branch.
    23 | 43 => println!("Ha ha ~"),
    // Else branch.
    _ => println!("Third value.")
  }

  // The while statement is no different from other programming languages
  while a.2 > 0 {
    // Output: 8  7  6  5  4  3  2  1
    print!("{:<3}", a.2);
    // The variable a is mutable that we can assign new value.
    a.2 -= 1;
    // When loop is end to display new line.
    if a.2 == 0 {
      println!();
    }
  }

  let mut a = 0;

  // Magic loop statement.
  // It stops at variable a value of 100.
  loop {
    if a == 100 {
      break;
    }
    a += 1;
  }

  // The Struct type.
  struct User {
    // The name is string type.
    // The string is allocate on heap.
    name: String,
    age: u8
  }

  let a = User {
    // We should use `String::from()` function to defined a new string.
    // If allocate on heap, it is dangerous to use it.
    name: String::from("turaiiao"),
    age: 18
  };

  // Display user's age on function call.
  output_age(a.age);
  // The parameter age has here.
  println!("age = {}", a.age);

  // The parameter name was moved to function.
  // Because function parameter are reference values.
  // We need use `clone()` to cloned a new value to function.
  output_name_quote(a.name.clone());
  // Error: use `a.name` after move.
  // println!("name = {}", a.name);

  // The original value is still there,
  // And the function just borrow to the value.
  output_name_borrow(&a.name);
  
  // The trait type like interface on other language.
  // We can add `$self` parameter to get self data.
  trait Human {
    // The human was eating.
    // Return the human is can eat ?
    fn eat(&self,age: u8) -> bool;
    // The human can sleep.
    fn sleep(&self);
  }

  // Implement some method on User struct.
  impl Human for User {
    // Implement eat function with trait.
    fn eat(&self, age: u8) -> bool {
      // If user age greater 8 that it can eat.
      age > 8
    }
    // Implement sleep function with trait.
    fn sleep(&self) {
      println!("{} is sleeping !", self.name)
    }
  }

  // Call method with trait type.
  a.sleep();

  // If it can eat on 12 age.
  if a.eat(12) {
    println!("Eating !!");
  }

  // Defined a struct data.
  // Both T and R are generics type.
  struct Point<T, R> {
    x: T,
    y: T,
    // Z is description.
    z: R
  }

  // Implement Point struct.
  impl<T, R> Point<T, R> {
    // Get borrow for self z parameter.
    // It return a generics type !.
    fn desc(&self) -> &R {
      &self.z
    }
  }

  // Let us to defined a Point !
  // This x and y is extend T generics, both x and y type must is T !
  // The z parameter is R generics that can different for x and y.
  let a = Point {
    x: 23,
    y: 43,
    z: "it is a point."
  };

  println!("{} {}", a.x, a.y);
  println!("{}", a.desc());
  
  // Defined a empty Test.
  enum Test {};

  // We can define some method on other data type.
  impl Test {
    fn show() -> String {
      String::from("hello rust !")
    }
  }

  println!("{}", Test::show());

  // Type alias to custom my type.
  type AnyMap = HashMap<u8, &'static str>;

  // Use like HashMap !!
  let map = AnyMap::new();
  
  // At this struct we used one life time parameter `'a`.
  // The parameter x is borrow value,
  // we should make sure it lives longer than the original variable.
  // If its value was released that parameter x is wild pointer !!!
  // Of course we can add multiply life time parameter.
  struct Foo<'a> {
    x: &'a i32
  }

  let y = &23;
  // Let parameter x assign a borrow value.
  // The compiler will help us to contrast scope length.
  let z = Foo {
    x: y
  };

  // This display `x = 23 y = 23`
  println!("x = {} y = {}", z.x, y);

  let a = "Hello";
  let c;

  {
    let _b = String::from("World");
    // At this line the compiler catch an error,
    // The variable is allocated in other scope, current scope will released before use b.
    /// c = longest(a, b.as_str());
    // The variable b will released at this line.
  }

  // That's all right, it is all in the same scope.
  c = longest(a, "World !");

  // Error: The variable b lift time is not length.
  // Because variable b was released.
  println!("{}", c);

  // Use our custom package in other package.
  // It can write at file header or other space before use.
  use crate::expr::{Operator::*, binary};

  println!("{}", binary(23, 25, Add));
  println!("{}", binary(23, 25, Sub));
  println!("{}", binary(23, 25, Mul));
  println!("{}", binary(23, 25, Div));

  // Use closure to define a lambda function.
  // Use `|` as function paren to set parameters.
  // Return a i32 value.
  let add = |x: i32, y: i32| -> i32 {
    x + y
  };

  println!("{}", add(12, 32));

  // Split string numbers with lambda expression.
  let a: Vec<&str> = "abc3543def343".split(|c: char|
    c.is_numeric()
  ).collect();

  // [ "abc", "def" ]
  println!("{:?}", a);
}

// Define our custom package.
mod expr {
  // The enum data is public.
  // We can use it in other package.
  pub enum Operator { Add, Sub, Mul, Div }

  // This function is add two value and return it.
  pub fn binary(l: i32, r: i32, o: Operator) -> i32 {
    // If use enum datas that we can ellipsis the enum name.
    use super::expr::Operator::*;
    
    match o {
      Add => l + r,
      Sub => l - r,
      Mul => l * r,
      Div => l / r
    }
  }

  // We can define a empty package, its not public.
  mod other {}
}

// Display age parameter in User struct.
fn output_age(age: u8) {
  println!("age = {}", age);
}

// Display name parameter in User struct by refers.
fn output_name_quote(name: String) {
  println!("age = {}", name);
}

// Display name parameter in User struct by borrow.
fn output_name_borrow(name: &String) {
  println!("age = {}", name);
}

// This function used two life time parameter to keep scope length.
// If x or y are different scope that compiler will tell us error.
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
  if x.len() > y.len() {
    x
  } else {
    y
  }
}
