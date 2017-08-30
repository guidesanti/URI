#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;

	scanf("%d %d %d", &a, &b, &c);

	if (
		(a > b && b <= c) ||
		(a < b && b < c && (b - a) <= (c - b)) ||
		(a > b && b > c && (a - b > b - c)) ||
		(a == b && b < c)) {
		printf(":)\n");
	} else {
		printf(":(\n");
	}

	return 0;
}