import java.util.ArrayList;
import java.util.List;

/**
 * A Four-Rule Operational Parser
 *
 * Follow with my blog: https://blog.xyiio.cn/2019/03/27/2019-03-27/
 */
enum TokenType { NUMBER, PLUS, MINUS, STAR, SLASH, EOF }

class Token {
  final String literal;
  final TokenType tokenType;

  Token(String literal, TokenType tokenType) {
    this.literal = literal;
    this.tokenType = tokenType;
  }
}

abstract class Stmt {}

class ExpressionStatement extends Stmt {
  final Expr expr;

  ExpressionStatement(Expr expr) {
    this.expr = expr;
  }

  @Override
  public String toString() {
    return "ExpressionStatement: " + expr;
  }
}

abstract class Expr {}

class Binary extends Expr {
  final Expr left;
  final Token operator;
  final Expr right;

  Binary(Expr left, Token operator, Expr right) {
    this.left = left;
    this.operator = operator;
    this.right = right;
  }

  @Override
  public String toString() {
    return "[ Binary: left = " + left + ", operator = " + operator.literal + ", right = " + right + " ]";
  }
}

class Literal extends Expr {
  Literal(Object value) {
    this.value = value;
  }

  final Object value;

  @Override
  public String toString() {
    return "Literal: " + value;
  }
}

class Parser {
  private int current = 0;

  private List<Token> tokens;

  Parser(List<Token> tokens) {
    this.tokens = tokens;
  }

  List<Stmt> parseProgram() {
    List<Stmt> statements = new ArrayList<>();

    while (tokens.get(current).tokenType != TokenType.EOF) {
      Stmt stmt = statement();

      statements.add(stmt);
    }

    return statements;
  }

  private Stmt statement() {
    if (peek().tokenType == TokenType.NUMBER) return expressionStatement();
    throw new RuntimeException("未知的操作数：" + tokens.get(current));
  }

  private Stmt expressionStatement() {
    Expr expr = expression();
    return new ExpressionStatement(expr);
  }

  private Expr expression() {
    return addition();
  }

  private Expr addition() {
    Expr expr = multiplication();

    while (match(TokenType.MINUS, TokenType.PLUS)) {
      Token operator = previous();
      Expr right = multiplication();

      expr = new Binary(expr, operator, right);
    }

    return expr;
  }

  private Expr multiplication() {
    Expr expr = primary();

    while (match(TokenType.SLASH, TokenType.STAR)) {
      Token operator = previous();
      Expr right = primary();

      expr = new Binary(expr, operator, right);
    }

    return expr;
  }

  private Expr primary() {
    if (match(TokenType.NUMBER)) {
      return new Literal(previous().literal);
    }
    throw new RuntimeException("非法的表达式");
  }

  private Token advance() {
    if (!isAtEnd()) current ++;
    return previous();
  }

  private Token peek() {
    return tokens.get(current);
  }

  private Token previous() {
    return tokens.get(current - 1);
  }

  private boolean isAtEnd() {
    return peek().tokenType == TokenType.EOF;
  }

  private boolean check(TokenType tokenType) {
    if (isAtEnd()) return false;
    return peek().tokenType == tokenType;
  }

  private boolean match(TokenType... tokenTypes) {
    for (TokenType tokenType : tokenTypes) {
      if (check(tokenType)) {
        advance();
        return true;
      }
    }

    return false;
  }
}

public class Main {

  public static void main(String[] args) {
    List<Token> tokens = new ArrayList<>();

    tokens.add(new Token("2", TokenType.NUMBER));
    tokens.add(new Token("+", TokenType.PLUS));
    tokens.add(new Token("5", TokenType.NUMBER));
    tokens.add(new Token("*", TokenType.STAR));
    tokens.add(new Token("2", TokenType.NUMBER));
    tokens.add(new Token("-", TokenType.MINUS));
    tokens.add(new Token("3", TokenType.NUMBER));
    tokens.add(new Token("EOF", TokenType.EOF));

    new Parser(tokens).parseProgram().forEach(System.out::println);
  }
}
