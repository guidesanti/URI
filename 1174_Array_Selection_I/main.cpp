#include <stdio.h>

int main() {
	float v = 0;
	int i = 0;

	for (i = 0; i < 100; i++) {
		scanf("%f", &v);
		if (v <= 10.0) {
			printf("A[%d] = %.1f\n", i, v);
		}
	}

	return 0;
}