#include <stdio.h>

int main() {
	long double x = 0;

	scanf("%lf", &x);

	if (x >= 0.0) {
		printf("+%.4E\n", x);
	} else {
		printf("%.4E\n", x);
	}

	return 0;
}