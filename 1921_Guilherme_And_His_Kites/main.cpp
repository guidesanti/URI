#include <stdio.h>

int main() {
	unsigned long long n = 0;

	scanf("%lld", &n);

	unsigned long long r = (((n * n) - (3 * n)) / 2);

	printf("%llu\n", r);

	return 0;
}