use std::collections;
use std::{cmp::Ordering, io};
use std::io::*;

mod sound {
  pub mod instrument {
    pub mod woodwine {
      pub fn clarinet() {
        println!("call at mod woodwine.");
      }
    }
  }

  mod voice {

  }
}

fn breath_in() {
  println!("call at crate.");
}

mod a {
  pub fn b() {
    super::breath_in();
  }
}

mod plant {
  pub struct Vegetable {
    pub name: String,
    id: i32
  }

  impl Vegetable {
    pub fn new(name: &str) -> Vegetable {
      Vegetable {
        name: String::from(name),
        id: 1
      }
    }
  }
}

mod menu {
  pub enum Appetizer {
    Soup,
    Salad
  }
}

fn main() {
  // absolute path.
  crate::sound::instrument::woodwine::clarinet();
  // relative path.
  sound::instrument::woodwine::clarinet();
  
  a::b();

  let mut a = plant::Vegetable::new("Squash");

  a.name = String::from("Butternut squash");
  println!("a name is {}", a.name);

  // the param id is not public.
  // println!("a id is {}", a.id);

  let a = menu::Appetizer::Soup;
  let b = menu::Appetizer::Salad;

  use crate::sound::instrument::woodwine;
  // or:
  // use self::sound::instrument::woodwine;

  woodwine::clarinet();

  // let mut a: HashMap<i32, i32> = HashMap::new();
  // or:
  // let mut a: collections::HashMap<i32, i32> = collections::HashMap::new();
}