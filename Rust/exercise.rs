// exercise.rs
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
}
