#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int x = 0;
		int y = 0;
		int s = 0;
		int j = 0;

		scanf("%d %d", &x, &y);

		if (x % 2 == 0) {
			x++;
		}

		for (j = 0; j < y; j++) {
			s += x;
			x += 2;
		}

		printf("%d\n", s);
	}

	return 0;
}