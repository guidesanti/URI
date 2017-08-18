#include <stdio.h>

int main() {
	int n = 0;
	int i = 1;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		int a = (i * i);
		int b = (a * i);
		printf("%d %d %d\n", i, a, b);
		printf("%d %d %d\n", i, a + 1, b + 1);
	}

	return 0;
}