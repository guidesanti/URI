#include <stdio.h>

int main() {
	int x = 0;

	while (1) {
		int i = 0;
		int s = 0;

		scanf("%d", &x);

		if (x == 0) {
			break;
		}

		if (x % 2) {
			x++;
		}

		for (i = 0; i < 5; i++) {
			s += x;
			x += 2;
		}

		printf("%d\n", s);
	}

	return 0;
}