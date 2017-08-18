#include <stdio.h>

int main() {
	int a = 0;
	int n = 0;
	int i = 0;
	int s = 0;

	scanf("%d", &a);

	while (n <= 0) {
		scanf("%d", &n);
	}

	for (i = 0, s = 0; i < n; s += a, i++, a++);
	printf("%d\n", s);

	return 0;
}