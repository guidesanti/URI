#include <stdio.h>

int main() {
	while (1) {
		int m = 0;
		int n = 0;
		int aux = 0;
		int sum = 0;

		scanf("%d %d", &m, &n);
		if ((m <= 0) || (n <= 0)) {
			break;
		}

		if (m > n) {
			aux = m;
			m = n;
			n = aux;
		}

		for (aux = m; aux <= n; aux++) {
			sum += aux;
			printf("%d ", aux);
		}
		printf("Sum=%d\n", sum);
	}

	return 0;
}