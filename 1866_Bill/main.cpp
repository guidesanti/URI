#include <stdio.h>

int main() {
	int c = 0;

	scanf("%d", &c);

	while (c--) {
		int n = 0;

		scanf("%d", &n);

		if (n % 2) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}

	return 0;
}