#include <stdio.h>

int main() {
	int n = 0;

	scanf("%d", &n);

	while (n--) {
		int x = 0;
		int i = 0;
		int s = 0;

		scanf("%d", &x);

		for (i = 1; i <= (x / 2); i++) {
			if (x % i == 0) {
				s += i;
			}
		}

		if (s == x) {
			printf("%d eh perfeito\n", x);
		} else {
			printf("%d nao eh perfeito\n", x);
		}
	}

	return 0;
}