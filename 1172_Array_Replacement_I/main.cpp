#include <stdio.h>

int main() {
	int x;
	int i = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &x);
		if (x <= 0) {
			x = 1;
		}
		printf("X[%d] = %d\n", i, x);
	}

	return 0;
}