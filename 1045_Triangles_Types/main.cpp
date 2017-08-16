#include <stdio.h>

int main() {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double aux = 0.0;

	scanf("%lf %lf %lf", &a, &b, &c);
	if (b > a && b > c) {
		aux = a;
		a = b;
		b = aux;
	} else if (c > a && c > b) {
		aux = a;
		a = c;
		c = aux;
	}

	if (a >= (b + c)) {
		printf("NAO FORMA TRIANGULO\n");
	} else {
		if ((a*a) == ((b*b) + (c*c))) {
			printf("TRIANGULO RETANGULO\n");
		}
		else if ((a*a) > ((b*b) + (c*c))) {
			printf("TRIANGULO OBTUSANGULO\n");
		}
		else if ((a*a) < ((b*b) + (c*c))) {
			printf("TRIANGULO ACUTANGULO\n");
		}
		if (a == b && a == c) {
			printf("TRIANGULO EQUILATERO\n");
		}
		else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a)) {
			printf("TRIANGULO ISOSCELES\n");
		}
	}

	return 0;
}