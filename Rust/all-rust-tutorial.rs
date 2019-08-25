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
}
