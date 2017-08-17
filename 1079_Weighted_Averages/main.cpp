#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		float a = 0.0;
		float b = 0.0;
		float c = 0.0;
		float avg = 0.0;
		
		scanf("%f %f %f", &a, &b, &c);

		avg = (((2.0 * a) + (3.0 * b) + (5.0 * c)) / 10.0);

		printf("%.1f\n", avg);
	}

	return 0;
}