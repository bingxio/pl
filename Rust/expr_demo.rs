// See: https://github.com/OhBonsai/calc/blob/master/calc.go#L238
use std::collections::HashMap;
use std::fmt::Debug;
use std::slice::Iter;

#[derive(Debug)]
struct Token<'a> {
    types: &'a str,
    literal: &'a str,
}

impl<'a> Token<'a> {
    pub fn new(types: &'a str, literal: &'a str) -> Self {
        Token { types, literal }
    }
}

const LOWEST: i32 = 1; // X
const SUM: i32 = 2; // + -
const PRODUCT: i32 = 3; // * /
const PREFIX: i32 = 4; // -X
const CALL: i32 = 5; // (X)

#[derive(Debug)]
enum Expression<'a> {
    IntegerLiteral(i32),
    Prefix(&'a str, Box<Expression<'a>>),
    Infix(Box<Expression<'a>>, &'a str, Box<Expression<'a>>),
}

type PrefixParseFn = fn() -> Expression<'static>;
type InfixParseFn = fn(Expression) -> Expression;

struct Parser<'a> {
    lexer: Iter<'a, Token<'a>>,
    cur_token: Token<'a>,
    peek_token: Token<'a>,
    prefix_parse_fn: HashMap<&'a str, PrefixParseFn>,
    infix_parse_fn: HashMap<&'a str, InfixParseFn>,
}

impl<'a> Parser<'a> {
    pub fn new(tokens: Vec<Token>) -> Self {
        unimplemented!()
    }
}

fn main() {
    let tokens = vec![
        Token::new("int", "3"),
        Token::new("star", "*"),
        Token::new("int", "6"),
        Token::new("plus", "+"),
        Token::new("int", "4"),
    ];

    let mut precedences: HashMap<&str, i32> = HashMap::new();

    precedences.insert("+", SUM);
    precedences.insert("-", SUM);
    precedences.insert("*", PRODUCT);
    precedences.insert("/", PRODUCT);
    precedences.insert("(", CALL);
}

fn calc(input: &str) {}
