fn main() {
    enum IpAddrKind {
        V4(u8, u8, u8, u8),
        V6(String)
    }

    let a = IpAddrKind::V4(127, 0, 0, 1);
    let b = IpAddrKind::V6(String::from("::1"));

    // enum Option<T> {
    //     Some(T),
    //     None
    // }

    // let some_number = Some(123);
    // let some_string = Some("hello world");

    let absent_number: Option<i32> = None;

    let a = Some(23);
    let b = plus_one(a);

    println!("b = {:?}", b);
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}