fn main() {
    // fn largest<T>(list: &[T]) -> T {
    //     let mut a = list.get(0);

    //     for &item in list.iter() {
    //         if item > a {
    //             a = item;
    //         }
    //     }

    //     a
    // }

    // let a = vec![12, 43, 53, 22, 67, 84];
    // let b = largest(&a);

    // println!("max is = {}", b);

    struct Point<T, U> {
        x: T,
        y: U
    }

    let a = Point { x: 12.5, y: 12 };
    let b = Point {
        x: 1.3,
        y: String::from("Hello World")
    };

    println!("x = {}, y = {}", a.x, a.y);
    println!("x = {}, y = {}", b.x, b.y);

    // enum Option<T> {
    //     Some(T),
    //     None
    // }

    struct User<T> {
        name: T,
        addr: T
    }

    impl<T> User<T> {
        fn name(&self) -> &T {
            &self.name
        }
    }

    let a = User { name: "turaiiao", addr: "chongqing" };

    println!("a.name = {}", a.name());

    impl<T, U> Point<T, U> {
        fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
            Point {
                x: self.x,
                y: other.y
            }
        }
    }

    let a = Point { x: 5, y: 10.4 };
    let b = Point { x: "Hello", y: 'c' };
    let c = a.mixup(b);

    println!("x = {}, y = {}", c.x, c.y);

    struct Person {
        name: String,
        age: u8
    }

    trait HasVoiceBox {
        // speak
        fn speak(&self);
        // check if can speak
        fn can_speak(&self) -> bool;
    }

    impl HasVoiceBox for Person {
        fn speak(&self) {
            println!("Hello, my name is {}", self.name);
        }

        fn can_speak(&self) -> bool {
            return self.age > 0;
        }
    }

    let a = Person {
        name: String::from("Bob"),
        age: 42
    };

    println!("Person {} can speak ? {}", a.name, a.can_speak());

    let mut a = 20;

    {
        let dom = &mut a;
        *dom += 1;
    }

    println!("a = {}", a); // 21

    
}