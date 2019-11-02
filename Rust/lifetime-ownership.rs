fn main() {
  pub fn take_ownership <'a> (x: &'a i32, y: &'a i32) -> &'a i32 {
    println!("x = {} and y = {}", x, y);

    if x > y {
      x
    } else {
      y
    }
  }

  let a = 23;

  {
    let b = 56;
    take_ownership(&a, &b);
  }

  take_ownership(&a, &98);
}
