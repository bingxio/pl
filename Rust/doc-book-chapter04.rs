fn main() {
  let a = "Hello, World !";
  let mut b = String::from("");

  b.push_str("Hello, ");
  b.push_str("World !");

  println!("a = {}, b = {}", a, b);

  let c = a.clone();

  println!("c = {}", c);

  let (x, y) = (123, String::from("coder"));

  makes_copy(x);
  takes_ownership(y);

  let s1 = gives_ownership();
  let s2 = String::from("hello");
  let s3 = takes_gives_back(s2);

  println!("s1 = {}, s3 = {}", s1, s3);
    
  let (a, b) = str_length(s1);

  println!("a = {}, b = {}", a, b);

  let a = String::from("The Meet Programming Language");

  println!("{} len is {}", a, calculate_len(&a));

  let mut x = String::from("My name is ");

  change_str(&mut x);

  println!("{}", x);

  // slice
  let a = "hello world";
  let (c, d, e) = (&a[..], &a[0..2], &a[3..a.len()]);

  println!("c = {}, d = {}, e = {}", c, d, e);
    
  let a = String::from("Hello, World !");
    
  takes_ownership(a);
    
  // `a` is moved to function.
  println!("{}", a);
    
  let a = 23;
  let b = a;
    
  println!("{} {}", a, b);
}

fn takes_ownership(x: String) {}

fn makes_copy(y: i32) {}

fn gives_ownership() -> String {
  String::from("hello")
}

fn takes_gives_back(str: String) -> String {
  str
}

fn str_length(str: String) -> (String, usize) {
  let a = str.len();
  (str, a)
}

fn calculate_len(str: &String) -> usize {
  str.len()
}

fn change_str(str: &mut String) {
  str.push_str("Turaiiao");
}
