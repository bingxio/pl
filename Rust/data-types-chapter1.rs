fn main() {
    let guess: i32 = " 123 ".trim().parse().expect("Not a number !");

    println!("Guess = {}", guess);

    let heart_eyed_cat = '😻';

    println!("{}", heart_eyed_cat);

    // tuple
    let tup: (i32, f32, u8) = (500, 12.6, 1);
    let (x, y, z) = tup;

    println!("x = {}, y = {}, z = {}", x, y, z);

    let tup_two_index = tup.1;

    println!("tup_two_index = {}", tup_two_index);

    // array
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    let b = ["meet"; 3];

    println!("a = {:?}, b = {:?}", a, b);

    // function
    println!("max 12, 34 = {}", max(12, 34));

    // use chunk to define var.
    let x = 12;
    let y = { x + 1 };

    println!("the value of y = {}", y);

    // if statement
    let mut a = if 1 > 2 {
        1
    } else {
        200
    };

    let b = loop {
        a -= 1;

        if a < 0 {
            break a + 2
        }
    };

    println!("if stmt a = {}, loop stmt b = {}", a, b);
}

fn max(x: i32, y: i32) -> i32 {
    if x > y {
        x
    } else {
        y
    }
}
