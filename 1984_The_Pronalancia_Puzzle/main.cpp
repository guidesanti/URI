#include <stdio.h>

int main() {
	unsigned long long n;

	scanf("%llu", &n);

	while (n) {
		int v = (n % 10);
		printf("%d", v);
		n /= 10;
	}
	printf("\n");

	return 0;
}