#include <stdio.h>

int main() {
	double s = 0.0;
	double r = 0.0;
	int p = 0;

	scanf("%lf", &s);

	if (s > 0.0 && s <= 400.0) {
		p = 15;
		r = 0.15 * s;
		s += r;
	} else if (s >= 400.01 && s <= 800.0) {
		p = 12;
		r = 0.12 * s;
		s += r;
	} else if (s >= 800.01 && s <= 1200.0) {
		p = 10;
		r = 0.10 * s;
		s += r;
	} else if (s >= 1200.01 && s <= 2000.0) {
		p = 7;
		r = 0.07 * s;
		s += r;
	} else {
		p = 4;
		r = 0.04 * s;
		s += r;
	}

	printf("Novo salario: %.2lf\n", s);
	printf("Reajuste ganho: %.2lf\n", r);
	printf("Em percentual: %d %%\n", p);

	return 0;
}