#include<stdio.h>
#include<stdbool.h>

typedef struct {
	int precedence;
	
	union {
		bool isNumber;
		double value;
	}
} Value;

int main() {
	Value a = { 23, {
			.isNumber = false,
			.value = 2.4,
		},
	};
	
	return 0;
}
