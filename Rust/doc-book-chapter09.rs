fn main() {
    let mut a: Vec<i8> = Vec::new();

    a.push(23);
    a.push(43);
    a.push(68);

    println!("a size = {}", a.len());

    let i = 4;

    if i >= a.len() {
        // panic some message and exit program.
        // panic!("index out of range.");
    }

    use std::fs::File;
    use std::io::ErrorKind;

    match File::open("hello.txt") {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("error to create file: {:?}", e)
            },
            other_error => panic!("there was a problem to opening the file: {:?}", other_error)
        }
    };

    let _a = File::open("hello.txt").map_err(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| {
                panic!("error to create file: {:?}", error);
            })
        } else {
            panic!("there was a problem to opening the file: {:?}", error);
        }
    });

    // throw it if there is an error.
    let _a = File::open("hello.txt").unwrap();

    //  custom error message.
    let _a = File::open("hello.txt").expect("error !");

    use std::io::Read;

    // TODO: how to catch this error ?
    fn _read_username_from_file() -> Result<String, std::io::Error> {
        let mut a = String::new();

        File::open("hello.txt")?.read_to_string(&mut a)?;

        Ok(a)
    }
}
