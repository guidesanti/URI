#include <stdio.h>

int main() {
	int a = 0;
	int s = 0;
	int i = 0;

	while (1) {
		scanf("%d", &a);

		if (a < 0) {
			break;
		}

		s += a;
		i++;
	}

	if (i > 0) {
		printf("%.2lf\n", (double)s / (double)i);
	} else {
		printf("0.00\n");
	}

	return 0;
}