#include <stdio.h>

int main() {
	int n = 0;
	int i = 1;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("%d %d %d\n", i, i * i, i * i * i);
	}

	return 0;
}