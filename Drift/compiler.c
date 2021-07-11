// Drift
// GPL 3.0 License - bingxio <3106740988@qq.com>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	LITERAL, INT, FLOAT, STR,
	CHAR,
} token_kind;

typedef struct {
	token_kind kind;
	const char *literal;
	int line;
} token;

token *tokens;

void lexer(const char *buf) {
	if (tokens == NULL) {
		tokens = (token *) malloc(sizeof(token) * 1024);
	}
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
	
	lexer(buf);
	
	fclose(fp);
	return 0;
}
