use std::io;
use std::cmp::Ordering;

use rand::Rng;

fn main() {
  let secret_number = rand::thread_rng().gen_range(1, 101);
    
  println!("Please input your number: ");
    
  loop {
    let mut a = String::new();
        
    io::stdin().read_line(&mut a).expect("Failed to read line !");
        
    let c: i32 = match a.trim().parse() {
      Ok(num) => num,
      Err(_) => continue,
    }
        
    println!("You gressed: {}", c);
        
    match c.cmp(&secret_number) {
      Ordering::Less => println!("To small !"),
      Ordering::Greater => println!("To big !");
      Ordering::Equal {
        println!("You win !");          
        break;
      }
    }
  }
}
