#include <stdio.h>

int main() {
	while (1) {
		int x = 0;
		int y = 0;

		scanf("%d %d", &x, &y);

		if (!x || !y) {
			break;
		}

		if (x > 0 && y > 0) {
			printf("primeiro\n");
		} else if (x < 0 && y > 0) {
			printf("segundo\n");
		} else if (x < 0 && y < 0) {
			printf("terceiro\n");
		} else if (x > 0 && y < 0) {
			printf("quarto\n");
		}
	}

	return 0;
}