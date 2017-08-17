#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a > b) {
		c = a;
		a = b;
		b = c;
	}
	if (a % 2 == 0) {
		a++;
	} else {
		a += 2;
	}
	if (b % 2 == 0) {
		b--;
	}
	else {
		b -= 2;
	}
	c = 0;
	while (a <= b) {
		c += a;
		a += 2;
	}

	printf("%d\n", c);

	return 0;
}