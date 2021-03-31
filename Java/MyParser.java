import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Token {
    String k;

    Token(String k) {
        this.k = k;
    }

    @Override
    public String toString() {
        return "<Token" + " K='" + k + '\'' + '>';
    }
}

class App {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Token> tokens = new ArrayList<>();

        System.out.print("INPUT: ");

        char[] line = scanner.nextLine().toCharArray();
        for (char i : line) {
            if (i == ' ') {
                continue;
            }
            tokens.add(new Token(String.valueOf(i)));
        }

        scanner.close();
        System.out.println(new Parser(tokens).parse());
    }
}

enum Op {
    ADD, SUB, MUL, DIV, RP;

    @Override
    public String toString() {
        return switch (this) {
        case ADD -> "+";
        case SUB -> "-";
        case MUL -> "*";
        case DIV -> "/";
        case RP -> ")";
        };
    }
}

abstract class Expr {
}

class I extends Expr {
    int val;

    I(int val) {
        this.val = val;
    }

    @Override
    public String toString() {
        return val + "";
    }
}

class BE extends Expr {
    Expr L;
    Op P;
    Expr R;

    BE(Expr l, Op p, Expr r) {
        this.L = l;
        this.P = p;
        this.R = r;
    }

    @Override
    public String toString() {
        return "<BE" + " L=" + L + " P=" + P + " R=" + R + '>';
    }
}

class Parser {
    private final ArrayList<Token> tokens;
    private int p = 0;

    private boolean ignore = false;

    Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
    }

    Op from(String l) {
        return switch (l) {
        case "+" -> Op.ADD;
        case "-" -> Op.SUB;
        case "*" -> Op.MUL;
        case "/" -> Op.DIV;
        case ")" -> Op.RP;

        default -> throw new IllegalStateException("Unexpected value: " + l);
        };
    }

    int getPrecedence(Op op) {
        return switch (op) {
        case ADD, SUB -> 1;
        case MUL, DIV -> 2;

        case RP -> 0;
        };
    }

    void append(Op op, Stack<Expr> l, Stack<Expr> s) {
        if (op != null) {
            switch (op) {
            case ADD, SUB, MUL, DIV -> {
                Expr er = l.pop();

                if (l.empty()) {
                    BE b = (BE) s.pop();

                    if (getPrecedence(op) > getPrecedence(b.P) && !ignore) {
                        b.R = new BE(b.R, op, er);
                    } else {
                        b.L = new BE(b.L, b.P, b.R);
                        b.P = op;
                        b.R = er;

                        if (ignore) {
                            ignore = false;
                        }
                    }

                    s.push(b);
                } else {
                    s.push(new BE(l.pop(), op, er));
                }
            }
            default -> throw new IllegalArgumentException("Unexpected value: " + op);
            }
        }
    }

    Expr parse() {
        Op top = null;

        Stack<Expr> l = new Stack<>();
        Stack<Expr> s = new Stack<>();

        while (p < tokens.size()) {
            Token token = tokens.get(p);

            switch (token.k) {

            case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" -> {
                l.push(new I(Integer.parseInt(token.k)));

                append(top, l, s);
                top = null;
            }

            case "+", "-", "*", "/" -> top = from(token.k);

            case "(" -> {
                p++;

                s.push(parse());

                this.ignore = true;

                append(top, l, s);
                top = null;
            }

            case ")" -> {
                return s.pop();
            }
            }
            p++;
        }
        return s.pop();
    }
}
