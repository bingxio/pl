package main

import "fmt"

const (
	number = iota
	add
	sub
	mul
	div
	lp
	rp

	unary
	eof
)

const lowest = 0

var precedence = map[int]int{
	number: 1,
	add:    2,
	sub:    2,
	mul:    3,
	div:    3,
	unary:  4,
	lp:     5,
}

type token struct {
	kind    int
	literal string
}

type expr interface {
	stringer() string
}

type literal struct {
	content string
}

func (l literal) stringer() string {
	return fmt.Sprintf("<literal %s>", l.content)
}

type prefix struct {
	op   token
	expr expr
}

func (p prefix) stringer() string {
	return fmt.Sprintf(
		"<prefix op=%s expr=%s>", p.op.literal, p.expr.stringer())
}

type infix struct {
	left  expr
	op    token
	right expr
}

func (i infix) stringer() string {
	return fmt.Sprintf("<infix left=%s op=%s right=%s>",
		i.left.stringer(), i.op.literal, i.right.stringer())
}

func main() {
	/* tokens := []token{ // 2 + 3 * 4
		{number, "2"},
		{add, "+"},
		{number, "3"},
		{mul, "*"},
		{number, "4"},
		{eof, "eof"},
	} */
	/*tokens := []token{ // -3 * 2
		{sub, "-"},
		{number, "3"},
		{mul, "*"},
		{number, "2"},
		{eof, "eof"},
	}*/
	tokens := []token{ // 3 * (4 - 2) + 5
		{number, "3"},
		{mul, "*"},
		{lp, "("},
		{number, "4"},
		{sub, "-"},
		{number, "2"},
		{rp, ")"},
		{add, "+"},
		{number, "5"},
		{eof, "eof"},
	}
	p := parser{
		iter: func(tokens []token) func() token {
			i := -1
			return func() token {
				i++
				if i >= len(tokens) {
					panic("invalid expression!")
				}
				return tokens[i]
			}
		}(tokens),
		prefixFn: make(map[int]func() expr),
		infixFn:  make(map[int]func(expr) expr),
	}
	expr := p.parse()
	if expr == nil {
		panic("expression is nil!")
	}
	fmt.Println(expr.stringer())
}

type parser struct {
	iter     func() token
	pre      token
	cur      token
	prefixFn map[int]func() expr
	infixFn  map[int]func(expr) expr
}

func (p *parser) next() {
	p.pre = p.cur
	p.cur = p.iter()
}

func (p *parser) parse() expr {
	p.next() // * 2
	p.next() // 2 +

	p.prefixFn[number] = p.literal
	p.prefixFn[sub] = p.prefix
	p.prefixFn[lp] = p.group

	p.infixFn[add] = p.infix
	p.infixFn[sub] = p.infix
	p.infixFn[mul] = p.infix
	p.infixFn[div] = p.infix

	return p.setPrecedence(lowest)
}

func (p parser) getPrePrecdence() int {
	if v, ok := precedence[p.pre.kind]; ok {
		return v
	}
	return lowest
}

func (p parser) getCurPrecedence() int {
	if v, ok := precedence[p.cur.kind]; ok {
		return v
	}
	return lowest
}

func (p *parser) setPrecedence(precedence int) expr {
	prefix := p.prefixFn[p.pre.kind]
	if prefix == nil {
		panic("no prefix parse function")
	}
	expr := prefix()
	for precedence < p.getCurPrecedence() {
		infix := p.infixFn[p.cur.kind]
		p.next()
		expr = infix(expr)
	}
	return expr
}

func (p *parser) literal() expr {
	return literal{content: p.pre.literal}
}

func (p *parser) prefix() expr {
	expr := prefix{
		op: p.pre,
	}
	p.next()
	expr.expr = p.setPrecedence(unary)
	return expr
}

func (p *parser) infix(left expr) expr {
	expr := infix{
		left: left,
		op:   p.pre,
	}
	prec := p.getPrePrecdence()
	p.next()
	expr.right = p.setPrecedence(prec)
	return expr
}

func (p *parser) group() expr {
	p.next()
	expr := p.setPrecedence(lowest)
	if p.cur.kind != rp {
		panic("lost right paren symbol")
	} else {
		p.next()
	}
	return expr
}
