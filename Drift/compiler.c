// Drift
// GPL 3.0 License - bingxio <3106740988@qq.com>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum { 
	EOH, LITERAL, NUMBER, STR, CHAR, FLOAT, ADD, SUB, MUL, DIV, 
	SUR, AS_ADD, AS_SUB, AS_MUL, AS_DIV, AS_SUR, R_ARROW, L_ARROW, 
	DOR, COMMA, COLON, EQ, SEMICOLON, GREATER, LESS, GR_EQ, LE_EQ,
	ADDR, OR, BANG, BANG_EQ, EQ_EQ, L_BRACE, R_BRACE, L_PAREN, R_PAREN,
	L_BRACKET, R_BRACKET, UNDERLINE, DEF, RET, FOR, AOP, IF, EF, NF,
	NEW, OUT, GO, MOD, USE
} token_kind;

const char *keyword[12] = {
	"def", "ret", "for", "aop", "if",  "ef", 
	"nf",  "new", "out", "go",  "mod", "use"
};

typedef struct { token_kind kind; const char *literal; int line; } token;
typedef struct { int len; int cap; token *tokens; } lexer_result;

bool peek_to(char c, char p, int i, int fsize, const char *buf) {
	return c == '/' && i + 1 != fsize && buf[i + 1] == p;
}

bool is_space(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
bool is_digit(char c) { return c >= '0' && c <= '9'; }
bool is_ident(char c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_';
}

token_kind to_keyword(const char *literal) {
	for (int i = 0; i < 12; i ++) {
		if (strcmp(literal, keyword[i]) == 0) {
			if (i ==  0) return DEF; if (i ==  1) return RET;
			if (i ==  2) return FOR; if (i ==  3) return AOP;
			if (i ==  4) return IF;  if (i ==  5) return EF;
			if (i ==  6) return NF;  if (i ==  7) return NEW;
			if (i ==  8) return OUT; if (i ==  9) return GO;
			if (i == 10) return MOD; if (i == 11) return USE;
		}
	}
	return LITERAL;
}

token new_token(token_kind k, const char *literal, int line) {
	token t;
	t.kind = k;
	t.literal = literal;
	t.line = line;
	return t;
}

void *append(void *ptr, int *len, int *cap, size_t size) {
	if (*cap == 0 || *len + 1 > *cap) {
		if (*cap == 0) {
			*cap = 4;
		} else {
			*cap *= 2;
		}
		ptr = realloc(ptr, size * (*cap));
	}
	return ptr;
}

void append_token(lexer_result *lex, token tok) {
	lex->tokens = append(lex->tokens, &lex->len, &lex->cap, sizeof(token));
	lex->tokens[lex->len++] = tok;
}

lexer_result *lexer(const char *buf, int fsize) {
	lexer_result *l = (lexer_result *) malloc(sizeof(lexer_result));
	for (int i = 0, line = 1; i < fsize;) {
		char c = buf[i];
		while (is_space(c)) {
			if (c == '\n') line ++;
			c = buf[++ i];
		}
		/*
block:		if (peek_to(c, '*', i, fsize, buf)) {
			i += 2;
			while (i < fsize) {
				c = buf[i];
				if (c == '\n') e ++;
				if (c == '*' && i + 1 != fsize && buf[i + 1] == '/') {
					i += 2;
					c = buf[i];
					break;
				}
				i ++;
			}
		}
line:		if  (peek_to(c, '/', i, fsize, buf)) {
			while (i < fsize) {
				c = buf[++ i];
				if (c == '\n') {
					e ++;
					i ++;
					break;
				}
			}
		}
		if (is_space(c, i, fsize))          goto space;
		if (peek_to(c, '*', i, fsize, buf)) goto block;
		if (peek_to(c, '/', i, fsize, buf)) goto line;
		*/
		if (is_digit(c)) {
			int p = 0;
			bool f = false;
			while (is_digit(c) || c == '.') {
				if (c == '.') f = true;
				p ++;
				c = buf[++ i];
			}
			char *literal = (char *) malloc(p * sizeof(char));
			for (int x = 0, j = p; x < j; x ++) {
				literal[x] = buf[i - p];
				p --;
			}
			append_token(l, new_token(f ? FLOAT : NUMBER, literal, line));
		}
		if (is_ident(c)) {
			int p = 0;
			while (is_ident(c)) {
				p ++;
				c = buf[++ i];
			}
			char *literal = (char *) malloc(p * sizeof(char));
			for (int x = 0, j = p; x < j; x ++) {
				literal[x] = buf[i - p];
				p --;
			}
			append_token(l, new_token(
						to_keyword(literal), literal, line));
		}
		switch (c) {
			case ' ':
			case '\t':
			case '\r':
			case '\n':
			case '\0':
				continue;
			default:
				fprintf(
					stderr,
					"<lexer>: Unknown character '%c' at line %d.\n", 
					c, line);
				exit(EXIT_FAILURE);
		}
	}
	append_token(l, new_token(EOH, "EOH", l->tokens[l->len - 1].line + 1));
	return l;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("usage: ./drift (file)\n");
		exit(EXIT_FAILURE);
	}
	const char *path = argv[1];
	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		printf("Failed to read buffer of file: %s\n", path);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	int fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *buf = (char *) malloc(fsize * sizeof(char));
	
	fread(buf, fsize, sizeof(char), fp);
	buf[fsize] = '\0';

	lexer_result *lex = lexer(buf, fsize);
	for (int i = 0; i < lex->len; i ++) {
		token t = lex->tokens[i];
		printf("TOKEN: %d %s %d\n", t.kind, t.literal, t.line);
	}
	
	fclose(fp);
	return 0;
}
