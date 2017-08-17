#include <stdio.h>

int main() {
	double s = 0.0;

	scanf("%lf", &s);

	if (s <= 2000.0) {
		printf("Isento\n");
	} else if (s >= 2000.01 && s <= 3000.0) {
		printf("R$ %.2lf\n", 0.08 * (s - 2000.0));
	} else if (s >= 3000.01 && s <= 4500.0) {
		printf("R$ %.2lf\n", 80.0 + (0.18 * (s - 3000.0)));
	} else {
		printf("R$ %.2lf\n", 350.0 + (0.28 * (s - 4500.0)));
	}

	return 0;
}