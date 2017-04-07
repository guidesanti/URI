#include <stdio.h>

// Constraints
#define PI	(3.14159)

int main() {
	double A;
	double B;
	double C;

	// Read A, B and C
	scanf("%lf %lf %lf", &A, &B, &C);
	printf("TRIANGULO: %.3lf\n", (double)((A * C) / 2.0));
	printf("CIRCULO: %.3lf\n", PI * C * C);
	printf("TRAPEZIO: %.3lf\n", ((A + B) * C) / 2.0);
	printf("QUADRADO: %.3lf\n", B * B);
	printf("RETANGULO: %.3lf\n", A * B);

	return 0;
}