#include <stdio.h>

int main() {
	int a = 0;
	int b = 1;
	int i = 0;
	int j = 0;
	int k = 1;

	scanf("%d %d", &a, &b);

	while (k <= b) {
		for (j = 0; j < (a - 1); j++) {
			printf("%d ", k++);
		}
		printf("%d\n", k++);
	}

	return 0;
}