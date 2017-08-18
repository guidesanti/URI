#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0, j = 1; i < 2; i++, j++) {
		for (k = 0; k < 10; k += 2) {
			if (k == 0) {
				printf("I=%d J=%d\n", i, j);
				printf("I=%d J=%d\n", i, j + 1);
				printf("I=%d J=%d\n", i, j + 2);
			} else {
				printf("I=%d.%d J=%d.%d\n", i, k, j, k);
				printf("I=%d.%d J=%d.%d\n", i, k, j + 1, k);
				printf("I=%d.%d J=%d.%d\n", i, k, j + 2, k);
			}
		}
	}
	printf("I=%d J=%d\n", i, j);
	printf("I=%d J=%d\n", i, j + 1);
	printf("I=%d J=%d\n", i, j + 2);

	return 0;
}