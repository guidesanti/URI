#include <stdio.h>

int main() {
	int x = 0;
	int z = 0;
	int s = 0;
	int c = 0;

	scanf("%d", &x);
	z = x;

	while (z <= x) {
		scanf("%d", &z);
	}

	while (x <= z) {
		s += x++;
		c++;
		if (s > z) {
			break;
		}
	}

	printf("%d\n", c);

	return 0;
}