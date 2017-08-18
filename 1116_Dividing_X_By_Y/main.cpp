#include <stdio.h>

int main() {
	int n = 0;

	scanf("%d", &n);

	while (n--) {
		float x = 0;
		float y = 0;

		scanf("%f %f", &x, &y);

		if (y == 0.0) {
			printf("divisao impossivel\n");
		} else {
			printf("%.1f\n", x / y);
		}
	}

	return 0;
}