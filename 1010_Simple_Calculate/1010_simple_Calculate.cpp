#include <stdio.h>

int main() {
	int	code = 0;
	int	amount = 0;
	double price = 0.0;
	double total = 0.0;
	int	i;
	for (i = 0; i < 2; i++) {
		scanf("%d %d %lf", &code, &amount, &price);
		total += ((double)amount * price);
	}

	printf("VALOR A PAGAR: R$ %.2f\n", total);

	return 0;
}