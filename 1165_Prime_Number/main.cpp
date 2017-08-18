#include <stdio.h>

int main() {
	int n = 0;

	scanf("%d", &n);

	while (n--) {
		int x = 0;
		int i = 0;
		int p = 1;

		scanf("%d", &x);

		if (x > 2) {
			for (i = 2; i <= (x / 2); i++) {
				if (x % i == 0) {
					p = 0;
					break;
				}
			}
		}

		if (p) {
			printf("%d eh primo\n", x);
		}
		else {
			printf("%d nao eh primo\n", x);
		}
	}

	return 0;
}