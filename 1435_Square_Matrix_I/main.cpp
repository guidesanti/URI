#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		k = 1;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				int v = k;
				if (j < k) {
					v = j;
				}
				if (j > (n - k)) {
					v = (n - j + 1);
				}
				if (j < n) {
					printf("%3d ", v);
				} else {
					printf("%3d\n", v);
				}
			}
			if (i <= (n / 2)) {
				k++;
				if (n % 2 == 0 && k > (n / 2)) {
					k--;
				}
			} else {
				k--;
			}
		}

		printf("\n");
	}

	return 0;
}