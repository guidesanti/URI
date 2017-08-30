#include <stdio.h>

int main() {
	double a = 0.0;
	double b = 0.0;

	scanf("%lf %lf", &a, &b);

	printf("%.2lf%%\n", 100.0 * ((b - a) / a));

	return 0;
}