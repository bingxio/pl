fn add(x: i32, y: i32) -> i32 {
  return x + y
}

fn apply<T>(term: T, x: i32) -> i32 where term: Fn(i32, i32) -> i32 {
  term(1, x)
}

fn main() {
  let a = apply(add, 2);
  let transform: fn(i32, i32) -> i32 = add;
  
  println!("a = {}", a);
  println!("{}", apply(transform, 55));
}
