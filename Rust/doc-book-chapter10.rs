fn main() {
  let x;

  {
    let y = 5;
    x = &y;

    println!("x = {}", x);

    // `y` dropped here.
  }

  // error: borrowed value deos not live long enough.
  // println!("x = {}", x);

  // life time annotation:
  // 
  // explicit lifecycle reference.
  // &'a i32
  // explicit lifecycle variable reference.
  // &'a mut i32

  fn longest<'a>(x: &'a str, y:&'a str) -> &'a str {
    if x.len() > y.len() {
      x
    } else {
      y
    }
  }

  let a = String::from("abcd");
  let b = "xyz";

  println!("the longest string is {}.", longest(a.as_str(), b));

  // life time in the structure.
  struct ImportantExcerpt<'a> {
    part: &'a str
  }

  let novel = String::from("call me ishmael. some years ago...");
  let first_sentence = novel.split('.').next().expect("could not find a '.'");

  let i = ImportantExcerpt { part: first_sentence };

  println!("i = {}", i.part);

  // life time elision rules.
  // we know every referene has a life time, we need in order to used function or
  // structure to designated life time.
  // all right, this function not use life time, but it works well, why ?
  fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
      if item == b' ' || item == b',' {
        return &s[0..i];
      }
    }

    &s[..]
  }

  let a = "hello, my name is turaiiao, i am a 17 age coder.";
  let b = first_word(a);

  println!("b = {}", b);

  // the pattern of citation analysis is called 'lifetime elision rules',
  // this is not a rule that the programmers need to follow.
  // this rules are a series of specific scenarios.
  // at this point the compiler will consider, if the code matches these scenarios, 
  // it no need to explicitly specify the lifetime.

  // lifetime in method defintion.
  impl <'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
      12
    }

    fn announce_and_return_part(&self, announcement: &str) -> &str {
      println!("attention please: {}", announcement);
      self.part
    }
  }

  println!("i level = {}, part = {}", i.level(), i.announce_and_return_part("OK"));

  // static lifetime.
  // if defined static, it survive between programs.
  // every string literal was static lifetime.
  // also, we can write this code:
  let a: &'static str = "i have a static lifetime.";

  println!("a = {}", a);

  // generic param and trait bounds lifetime.
  use std::fmt::Display;

  fn longest_with_an_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str where T: Display {
    println!("announcement! {}", ann);

    if x.len() > y.len() {
      x
    } else {
      y
    }
  }

  // the name `ann` type is generic T, why ?

  let (a, b) = ("1234", "56789");

  let c = longest_with_an_announcement(a, b, "why? why? what is lifetime ?");

  println!("c = {}", c);
}