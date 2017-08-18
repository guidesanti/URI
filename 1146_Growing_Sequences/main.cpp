#include <stdio.h>

int main() {
	while (1) {
		int x = 0;
		int i = 0;

		scanf("%d", &x);

		if (!x) {
			break;
		}

		for (i = 1; i < x; i++) {
			printf("%d ", i);
		}
		printf("%d\n", i);
	}

	return 0;
}