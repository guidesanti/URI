#include <stdio.h>
#include <math.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int area = 0;
	int s = 0;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {
			break;
		}

		area = (a * b);
		area = ((100 * area) / c);
		s = (int)sqrt((double)area);

		printf("%d\n", s);
	}

	return 0;
}