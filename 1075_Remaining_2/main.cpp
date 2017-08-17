#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	for (i = 1; i <= 10000; i++) {
		if (i % n == 2) {
			printf("%d\n", i);
		}
	}

	return 0;
}