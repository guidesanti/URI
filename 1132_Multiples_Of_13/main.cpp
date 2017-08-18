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

	s = 0;
	while (a <= b) {
		if (a % 13) {
			s += a;
		}
		a++;
	}

	printf("%d\n", s);

	return 0;
}