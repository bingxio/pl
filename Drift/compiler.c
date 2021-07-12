// Drift
// GPL 3.0 License - bingxio <3106740988@qq.com>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { LITERAL, NUMBER, STR, CHAR } token_kind;

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

lexer_result *lexer(const char *buf, int fsize) {
	lexer_result *l = (lexer_result *) malloc(sizeof(lexer_result));
	for (int i = 0, e = 1; i < fsize; i ++) {
		char c = buf[i];
space:		while (is_space(c)) {
			if (c == '\n') {
				printf("LINE %d\n", e + 1);
				e ++;
			}
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
			while (is_digit(c)) {
				p ++;
				c = buf[++ i];
			}
			char *literal = (char *) malloc(p * sizeof(char));
			for (int x = 0, j = p; x < j; x ++) {
				literal[x] = buf[i - p];
				p --;
			}
			l->tokens = append(l->tokens, &l->len, &l->cap, sizeof(token));
			l->tokens[l->len++] = new_token(NUMBER, literal, e);
		}
		if (is_ident(c)) {
			printf("IDENTIFIER: %c LINE: %d\n", c, e);
		}
	}
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
