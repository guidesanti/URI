#include <stdio.h>

int main() {
	int i = 0;

	for (i = 1; i <= 9; i += 2) {
		printf("I=%d J=7\n", i);
		printf("I=%d J=6\n", i);
		printf("I=%d J=5\n", i);
	}

	return 0;
}