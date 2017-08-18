#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int s = 0;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a > b) {
		s = a;
		a = b;
		b = s;
	}

	a++;
	b--;
	while (a <= b) {
		if (a % 5 == 2 || a % 5 == 3) {
			printf("%d\n", a);
		}
		a++;
	}

	return 0;
}