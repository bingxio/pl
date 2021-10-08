// exercise.rs
use std::collections::HashMap;
use std::fmt::Debug;
use std::fs::File;
use std::io;
use std::io::{ErrorKind, Read};

use std::env;

fn main() {
    println!("Hello, Rust!");
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    let b = [3; 5];

    // let mut index = String::new();

    // std::io::stdin()
    //     .read_line(&mut index)
    //     .expect("Failed to read line");
    // let index: i32 = index
    //     .trim()
    //     .parse()
    //     .expect("Index entered was not a number");
    let index: u8 = 0;
    println!("{:?} {:?} index {}", a, b, index);

    let x = 5;
    let y = {
        let x = 3;
        x + 1
    };
    let num = if true { 5 } else { 6 };
    println!("{} {} {}", x, y, num);

    let mut i = 0;
    let r = loop {
        i += 1;

        if i == 10 {
            break i * 2; // To r
        }
    };
    println!("{} {}", i, r);

    let a = [10, 20, 30, 40, 50];
    for e in a.iter() {
        print!("{}\t", e);
    }
    println!();

    for n in (1..4).rev() {
        print!("{}\t", n);
    }
    println!();

    // ownership

    let mut s = String::from("hello");
    s.push_str(", world!"); // push_str() appends a literal to s string
    println!("{}", s); // This will print `hello, world!`
    {
        let _s = String::from("hello"); // s is valid from this point forward
                                        // do stuff with s
    } // this scope is now over, and s is no longer valid
    let s1 = String::from("hello");
    let s2 = s1;
    println!("{}, world!", s2);

    let s1 = String::from("hello");
    let s2 = s1.clone();
    println!("s1 = {} s2 = {}", s1, s2);

    let x = 5;
    let y = x; // copy trait
    println!("x = {} y = {}", x, y);

    fn give_ownership() -> String {
        String::from("hello")
    }
    let s = give_ownership();
    println!("give = {}", s);

    fn calc_length(s: String) -> (String, usize) {
        let len = s.len(); // return into len
        (s, len)
    }
    let s = String::from("bingxio!");
    let x = calc_length(s);
    println!("calc = {} {}", x.0, x.1);

    fn _calc(s: &String) -> usize {
        // s is reference to a String
        s.len()
    } // it does not have ownership, nothing happens.

    let mut s = String::from("return: ");

    fn change(s: &mut String) {
        s.push_str("OK!");
    }
    change(&mut s);
    println!("{}", s);

    {
        let _r1 = &mut s; // _r1 drop
    }
    let _r2 = &mut s;

    let r1 = &s; // immutable borrow
    let r2 = &s;
    // let r3 = &mut s; mutable borrow, it is also borrowed as immutable

    println!("{} {}", r1, r2);

    let mut s = String::from("I LOVE U!");

    let r1 = &s;
    let r2 = &s;
    println!("{} {}", r1, r2); // r1 and r2 will not be used after this point

    let r3 = &mut s;
    println!("{}", r3);

    // fn dangle() -> &String {
    //     let s = String::from("hello");
    //     &s
    // }
    // s goes out of scope, and is dropped. Its memory goes away.

    fn _no_dangle() -> String {
        let s = String::from("hello");
        s
    }

    fn first_word(s: &String) -> usize {
        let bytes = s.as_bytes();

        for (i, &item) in bytes.iter().enumerate() {
            if item == b' ' {
                return i;
            }
        }

        s.len()
    }

    let mut s = String::from("hello, world!");
    let word = first_word(&s);
    println!("{}", word);
    s.clear(); // make it equal to ""

    s.push_str("hello world");
    let hello = &s[0..5];
    let world = &s[6..11];

    println!("{}    {}     {}      {}", hello, world, &s[..2], &s[..]);

    fn first_w(s: &str) -> &str {
        let bytes = s.as_bytes();

        for (i, &item) in bytes.iter().enumerate() {
            if item == b' ' {
                return &s[0..i];
            }
        }

        &s[..]
    }

    let word = first_w(&s); // immutable borrow
                            // s.clear(); // mutable borrow

    let my_str_literal = "hello world";
    println!(
        "first word: {}, {}, {}",
        word,
        first_w(my_str_literal),
        first_w(&my_str_literal[0..6])
    );

    #[derive(Debug)]
    struct Color(i32, i32, i32);

    let black = Color(0, 0, 0);
    println!("{:?}", black); // structure

    #[derive(Debug)]
    struct Rectangle {
        width: u32,
        height: u32,
    }

    impl Rectangle {
        // implement
        fn area(&self) -> u32 {
            self.width * self.height
        }

        fn _hold(&self, other: &Rectangle) -> bool {
            self.width > other.width && self.height > other.height
        }

        fn square(size: u32) -> Rectangle {
            Rectangle {
                width: size,
                height: size,
            }
        }
    }

    let rect = Rectangle {
        width: 30,
        height: 50,
    };
    println!(
        "the area of the rectangle is {} square pixels.",
        rect.area()
    );

    let rect = Rectangle::square(40);
    println!("{:?}", rect);

    enum _MyColor {
        RED,
        GREEN,
    }
    #[derive(Debug)]
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }

    let home = IpAddr::V4(127, 0, 0, 1);
    let loopback = IpAddr::V6(String::from("::1")); // hui huan address

    println!("{:?} {:?}", home, loopback);

    #[derive(Debug)]
    enum Message {
        _Quit,
        _Move { x: i32, y: i32 },
        Write(String),
        _ChangeColor(i32, i32, i32),
    }
    struct _QuitMessage; // unit struct
    struct _MoveMessage {
        x: i32,
        y: i32,
    }
    struct _WriteMessage(String); // tuple struct
    struct _ChangeColorMessage(i32, i32, i32); // tuple struct

    impl Message {
        fn call(&self) {
            // method body would be defined here
        }
    }

    let m = Message::Write(String::from("hello?"));
    m.call();

    let some_number = Some(5);
    let some_string = Some("a string");

    let absent_number: Option<i32> = None;
    println!("{:?} {:?} {:?}", some_number, some_string, absent_number);

    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    // let sum = x + y; // no implementation for i8 + Option<i8>
    let sum = x + y.expect("WHAT ERROR !!");
    println!("sum = {}", sum);

    #[derive(Debug)]
    enum State {
        Alabama,
        _Alaska,
    }

    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter(State),
    }

    fn value_in_cents(coin: Coin) -> u8 {
        match coin {
            Coin::Penny => {
                println!("Luckly penny!");
                1
            }
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter(state) => {
                println!("State quarter from {:?}!", state);
                25
            }
        }
    }

    println!(
        " {}\n {}\n {}\n {}",
        value_in_cents(Coin::Penny),
        value_in_cents(Coin::Nickel),
        value_in_cents(Coin::Dime),
        value_in_cents(Coin::Quarter(State::Alabama))
    );

    fn plus_one(x: Option<i32>) -> Option<i32> {
        match x {
            None => None,
            Some(i) => Some(i + 1),
        }
    }

    println!("{:?} {:?}", plus_one(Some(5)), plus_one(None));

    let some_u8 = 0u8;
    let x: u8 = match some_u8 {
        1 => 2,
        2 => 3,
        3 => 4,
        _ => 5,
    };
    println!("x = {}", x);

    let some_u8 = Some(5);
    if let Some(5) = some_u8 {
        println!("OK!");
    }

    let coin = Coin::Quarter(State::Alabama);

    if let Coin::Quarter(state) = coin {
        println!("State quarter from {:?}", state);
    } else {
        println!("other");
    }

    // call crate module
    crate::front_of_house::hosting::add_to_waitlist();

    let mut v = vec![1, 2, 3, 4, 5];
    let third: &i32 = &v[2];

    println!("The third element is {}", third);

    match v.get(2) {
        Some(num) => println!("{}", num),
        None => println!("NONE"),
    }

    println!("{:?} {:?}", v.get(1), v.get(200));

    for i in &mut v {
        *i += 1;
    }
    for i in &v {
        print!("{} ", i);
    }
    println!();

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let scores: HashMap<_, _> = teams.into_iter().zip(initial_scores.into_iter()).collect();
    println!("{:?}", scores);

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    map.insert(String::from("A"), String::from("123"));

    map.entry(String::from("B")).or_insert(String::from("456"));
    map.entry(String::from("C")).or_insert(String::from("789"));

    for (k, v) in &map {
        println!("{}: {}", k, v);
    }

    fn read_file() -> Result<String, io::Error> {
        let mut f = File::open("hello.txt")?;
        let mut s = String::new();
        f.read_to_string(&mut s)?; // ? operator
        Ok(s)
    }

    match read_file() {
        Ok(content) => {
            println!("Read {}", content);
        }
        Err(e) => println!("Error: {}", e),
    }

    // And use function to handle it.
    File::open("1.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            println!("not found, and will create it named 1.txt on this path");
            File::create("1.txt").unwrap()
        } else {
            panic!("WHAT'S UP!");
        }
    });

    fn largest_i32(list: &[i32]) -> i32 {
        let mut largest = list[0];

        for &item in list {
            if item > largest {
                largest = item;
            }
        }

        largest
    }

    println!("largest {}", largest_i32(&vec![1, 2, 3, 4, 5]));

    struct Point<T, U> {
        x: T,
        y: U,
    }

    impl<T, U> Point<T, U> {
        fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
            Point {
                x: self.x,
                y: other.y,
            }
        }
    }

    let p1 = Point { x: 5, y: 10.4 };
    let p2 = Point { x: "Hello", y: 'c' };

    let p3 = p1.mixup(p2);
    println!("p3.x = {} p3.y = {}", p3.x, p3.y);

    trait Summary {
        fn summarize_def(&self) -> String;

        fn summarize(&self) -> String {
            String::from("(Read default impl)")
        }
    }

    struct Foo {
        x: i32,
    }

    impl Summary for Foo {
        fn summarize_def(&self) -> String {
            String::from("(Read implementation)")
        }
    }

    let f = Foo { x: 666 };
    println!("{} {} {}", f.summarize(), f.summarize_def(), f.x);

    // Trais as parameter
    fn notify(item: &impl Summary) {
        println!("{} {}", item.summarize(), item.summarize_def());
    }
    notify(&f);

    // Trait bound
    fn _notify_more<T: Summary + std::fmt::Display>(_item: &T) {}

    // fn _some_func_1<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {}
    // fn _some_func_2<T, U>(t: &T, u: &U) -> i32
    // where
    //     T: Display + Clone,
    //     U: Clone + Debug,
    // {
    // }

    fn return_summary() -> impl Summary {
        // Foo was implementation of Summary trait
        Foo { x: 9 }
    }
    println!("{}", return_summary().summarize());

    fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
        let mut larg = list[0];

        for &item in list {
            if item > larg {
                larg = item;
            }
        }

        larg
    }

    let number = vec![34, 12, 56, 88, 45, 43, 22];
    let chars = vec!['y', 'w', 'p', 'a'];

    println!("{} {}", largest(&number), largest(&chars));

    struct Pair<T> {
        a: T,
        b: T,
    }

    impl<T> Pair<T> {
        fn new(a: T, b: T) -> Self {
            Self { a, b }
        }
    }

    impl<T: std::fmt::Display + PartialOrd + Copy> Pair<T> {
        fn cmp_display(&self) {
            println!(
                "largest member is {}",
                if self.a >= self.b { self.a } else { self.b }
            );
        }
    }

    impl<T> ToString for Pair<T> {
        fn to_string(&self) -> std::string::String {
            String::from("My Pair{}")
        }
    }

    Pair::new(34, 12).cmp_display();
    Pair::new('p', 'q').cmp_display();

    println!("{}", Pair::new(1, 2).to_string());

    // References with lifetimes

    // {
    //     let r;
    //     {
    //         let x = 5;
    //         r = &x;
    //     } // r drop here
    //     println!("{}", r);
    // }

    /* fn main() {
        {
            let r;                // ---------+-- 'a
                                  //          |
            {                     //          |
                let x = 5;        // -+-- 'b  |
                r = &x;           //  |       |
            }                     // -+       |
                                  //          |
            println!("r: {}", r); //          |
        }                         // ---------+
    } */

    /*     fn main() {
           {
               let x = 5;            // ----------+-- 'b
                                     //           |
               let r = &x;           // --+-- 'a  |
                                     //   |       |
               println!("r: {}", r); //   |       |
                                     // --+       |
           }                         // ----------+
       }
    */
    struct Iter<'a> {
        a: [i32; 3],
        i: usize,
        _m: std::marker::PhantomData<&'a ()>,
    }

    impl<'a> Iterator for Iter<'a> {
        type Item = &'a i32;

        fn next(&mut self) -> Option<&'a i32> {
            if self.i < 3 {
                unsafe {
                    let ret = Some(&(*(self as *mut Iter)).a[self.i]);
                    self.i += 1;
                    ret
                }
            } else {
                None
            }
        }
    }

    let mut it = Iter {
        a: [34, 12, 54],
        i: 0,
        _m: std::marker::PhantomData,
    };
    for _i in 0..5 {
        println!("{:?}", it.next());
    }

    // IO
    let args: Vec<String> = env::args().collect();
    println!("args: {:?}", args);

    let add = |a: i32, b: i32| -> i32 { a + b };
    println!("add {}", add(3, 2));
}

#[derive(Debug)]
pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 || value > 100 {
            panic!("Guess value must be between 1 and 100, got {}.", value);
        }
        Guess { value }
    }
}

mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {
            println!("CALL {}", num());
        }

        fn num() -> u8 {
            6
        }
    }
}

pub fn add_two(x: i32) -> i32 {
    x + x
}

pub struct Cacher<T>
where
    T: Fn(u32) -> u32,
{
    calculation: T,
    value: Option<u32>,
}

impl<T> Cacher<T>
where
    T: Fn(u32) -> u32,
{
    fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            value: None,
        }
    }

    fn value(&mut self, arg: u32) -> u32 {
        match self.value {
            Some(v) => v,
            None => {
                let v = (self.calculation)(arg);
                self.value = Some(v);
                v
            }
        }
    }
}

use std::thread;
use std::time::Duration;

fn generate_workout(intensity: u32, random_number: u32) {
    let mut expensive_result = Cacher::new(|num| {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    });
    if intensity < 25 {
        println!("Today, do {} pushups!", expensive_result.value(intensity));
        println!("Next, do {} situps!", expensive_result.value(intensity));
    } else {
        if random_number == 3 {
            println!("Take a break today! Remember to stay hydrated!");
        } else {
            println!(
                "Today, run for {} minutes!",
                expensive_result.value(intensity)
            );
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn greater_than_100() {
        Guess::new(200);
    }

    #[test]
    fn it_works() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        } else {
            Err(String::from("tow plus tow does not equal four"))
        }
    }

    #[test]
    fn add_test() {
        assert_eq!(add_two(4), 8);
    }

    #[test]
    fn call_with_different_values() {
        let mut c = Cacher::new(|x| x);

        let v1 = c.value(1);
        let v2 = c.value(2);

        assert_eq!(v2, 2);
    }
}
