#include <stdio.h>

int main() {
	int n = 0;

	while (scanf("%d", &n) != EOF) {
		int i = 0;
		int j = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j && i == (n / 2)) {
					printf("4");
				} else if (i >= (n / 3) && i < (n - n / 3) && j >= (n / 3) && (j < (n - n / 3))) {
					printf("1");
				} else if (i == j) {
					printf("2");
				} else if (i == (n - j - 1)) {
					printf("3");
				} else {
					printf("0");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}