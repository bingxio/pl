// Drift
// GPL 3.0 License - bingxio <3106740988@qq.com>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { LITERAL, NUMBER, STR, CHAR } token_kind;

typedef struct { token_kind kind; const char *literal; int line; } token;
typedef struct { int count; token *tokens[]; } lexer_result;

bool is_space(char c, int i, int fsize) { 
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r') 
		&& i < fsize;
}

bool peek_to(char c, char p, int i, int fsize, const char *buf) {
	return c == '/' && i + 1 != fsize && buf[i + 1] == p;
}

bool is_digit(char c) { return c >= '0' && c <= '9'; }
bool is_identifier(char c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_';
}

token *new_token(token_kind k, const char *literal, int line) {
	token *t = (token *) malloc(sizeof(token));
	t->kind = k;
	t->literal = literal;
	t->line = line;
	return t;
}

lexer_result *lexer(const char *buf, int fsize) {
	lexer_result *l = (lexer_result *) malloc(sizeof(lexer_result));
	l->count = 0;
	for (int i = 0, e = 1; i < fsize; i ++) {
		char c = buf[i];
space:
		while (is_space(c, i, fsize)) {
			if (c == '\n') e ++;
			c = buf[++ i];
		}
block:
		if (peek_to(c, '*', i, fsize, buf)) {
			i += 2;
			while (i < fsize) {
				c = buf[i];
				if (c == '\n') e ++;
				if (c == '*' && i + 1 != fsize
						&& buf[i + 1] == '/') {
					i += 2;
					c = buf[i];
					break;
				}
				i ++;
			}
		}
line:
		if  (peek_to(c, '/', i, fsize, buf)) {
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
			l->tokens[l->count++] = new_token(NUMBER, literal, e);
		}
		if (is_identifier(c)) {
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
	lexer_result *l = lexer(buf, fsize);
	for (int i = 0; i < l->count; i ++) {
		token *tok = l->tokens[i];
		printf("%d %s %d\n", tok->kind, tok->literal, tok->line);
	}
	fclose(fp);
	return 0;
}
