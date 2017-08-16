#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;

	// Read the values A and B
	scanf("%d %d", &a, &b);

	if ((a >= b) && ((a % b) == 0) ||
		(a < b) && ((b % a) == 0)) {
		printf("Sao Multiplos\n");
	} else {
		printf("Nao sao Multiplos\n");
	}

	return 0;
}