#[derive(Debug)]
struct Foo {
    x: i32,
}

fn main() {
    let mut f = Foo { x: 23 };
    let p = &f.x;

    println!(
        "{:?} x = {} p = {}", f, f.x, p);
        
    let u = &mut f;
    
    println!("other = {}", u.x);
    // println!(
    //     "{:?} x = {} p = {}", f, f.x, p);
    // println!("u = {:?}", u);
}
