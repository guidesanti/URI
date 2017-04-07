#include <stdio.h>

// Constraints
#define PI	(3.14159)

int main() {
	double radius = 0.0;
	scanf("%lf", &radius);
	printf("VOLUME = %.3f\n", (double)((4.0/3.0)*PI*radius*radius*radius));

	return 0;
}