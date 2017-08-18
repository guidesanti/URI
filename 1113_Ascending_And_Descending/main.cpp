#include <stdio.h>

int main() {
	while (1) {
		int m = 0;
		int n = 0;

		scanf("%d %d", &m, &n);
		if (m == n) {
			break;
		}

		if (m > n) {
			printf("Decrescente\n");
		} else {
			printf("Crescente\n");
		}
	}

	return 0;
}