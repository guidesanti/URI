#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;

	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		for (i = 1; i <= n; i++) {
			a = i;
			b = 2;
			for (j = 1; j <= n; j++) {
				int v = 0;
				if (a > 0) {
					v = a;
					a--;
				} else {
					v = b;
					b++;
				}
				if (j < n) {
					printf("%3d ", v);
				}
				else {
					printf("%3d\n", v);
				}
			}
		}

		printf("\n");
	}

	return 0;
}