struct User {
  username: String,
  password: String,
  paid: bool,
}

fn main() {
  let mut a = User {
    username: String::from("turaiiao"),
    password: String::from("12345678"),
    paid: true,
  };

  a.paid = false;

  println!("username = {}, password = {}, paid = {}",
    a.username, a.password, a.paid);

  let a = build_user(String::from("july"), String::from("000000"));

  println!("username = {}, password = {}, paid = {}",
    a.username, a.password, a.paid);

  let c = User {
    username: String::from("frank"),
    ..a
  };

  println!("username = {}, password = {}, paid = {}",
    c.username, c.password, c.paid);

  struct Color(i32, i32, i32);

  let black = Color(0, 0, 0);

  println!("r = {}, g = {}, b = {}", black.0, black.1, black.2);

  let rect = Rectangle { width: 30, height: 50 };

  println!("The area of the rectangle is {} square pixels.", rect.area());
}

struct Rectangle {
  width: u32,
  height: u32,
}

// field init shorthand.
fn build_user(username: String, password: String) -> User {
  User {
    username,
    password,
    paid: true,
  }
}

impl Rectangle {
  fn area(&self) -> u32 {
    self.width * self.height
  }
}