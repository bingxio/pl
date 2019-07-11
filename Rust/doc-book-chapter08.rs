fn main() {
    let mut a: Vec<i32> = Vec::new();

    a.push(12);
    a.push(35);
    a.push(85);

    let mut a = vec![2, 5, 23];

    let (b, c, d) = (&a[1], a.get(1), a.get(2));

    println!("a = {}, b = {:?}, c = {:?}", b, c, d);

    for i in &mut a {
        // dereference operator '*'.
        *i += 20;
    }

    enum Hello {
        Int(i32), 
        Float(f32), 
        String(String) 
    }

    let _row = vec![
        Hello::Int(12),
        Hello::Float(1.5),
        Hello::String(String::from("Hello World"))
    ];

    // TODO: error ?
    // println!("{:#?}", row);

    use std::collections::HashMap as HP;

    let mut a: HP<i8, i8> = HP::new();

    a.insert(14, 31);
    a.insert(43, 23);

    let mut a: Vec<String> = Vec::new();

    a.push(String::from("Yellow"));
    a.push(String::from("Blue"));

    let b = vec![10, 20];

    use std::collections::HashMap;

    let c: HashMap<_, _> = a.iter().zip(b.iter()).collect();

    println!("{:?}", c);

    for (k, v) in &c {
        println!("{} : {}", k, v);
    }

    let mut a: HashMap<String, i8> = HashMap::new();

    a.insert(String::from("Yellow"), 2);
    
    // if the map not have Blue Key, then push and value.
    a.entry(String::from("Blue")).or_insert(5);

    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);

        *count += 1;
    }

    println!("{:?}", map);
}