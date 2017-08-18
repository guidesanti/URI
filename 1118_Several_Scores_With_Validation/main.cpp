#include <stdio.h>

int main() {
	float a = 0.0;
	float b = 0.0;

	while (1) {
		while (1) {
			scanf("%f", &a);
			if (a >= 0.0 && a <= 10.0) {
				break;
			}
			printf("nota invalida\n");
		}

		while (1) {
			scanf("%f", &b);
			if (b >= 0.0 && b <= 10.0) {
				break;
			}
			printf("nota invalida\n");
		}

		printf("media = %.2f\n", (a + b) / 2.0);

		int x = 0;
		while (x < 1 || x > 2) {
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &x);
		}

		if (x == 2) {
			break;
		}
	}

	return 0;
}