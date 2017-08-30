#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if ((a + b > c) && (a + b > d) &&
		(b + c <= a) || (b + c <= d) ||
		(c + d <= a) || (c + d <= b) ||
		(d + a <= b) || (d + a <= c)) {
		printf("S\n");
	} else {
		printf("N\n");
	}

	return 0;
}