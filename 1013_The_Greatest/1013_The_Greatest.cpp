#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if ((a > b) && (a > c)) {
		printf("%d eh o maior\n", a);
	} else if ((b > a) && (b > c)) {
		printf("%d eh o maior\n", b);
	} else {
		printf("%d eh o maior\n", c);
	}

	return 0;
}