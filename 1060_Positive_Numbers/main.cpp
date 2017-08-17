#include <stdio.h>

int main() {
	int i = 0;
	int c = 0;
	double n = 0.0;

	for (i = 0; i < 6; i++) {
		scanf("%lf", &n);
		if (n > 0.0) {
			c++;
		}
	}

	printf("%d valores positivos\n", c);

	return 0;
}