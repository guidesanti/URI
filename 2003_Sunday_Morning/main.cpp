#include <stdio.h>

int main() {
	int h = 0;
	int m = 0;

	while (scanf("%d:%d", &h, &m) != EOF) {
		int t = (480 - ((h * 60) + m + 60));

		if (t > 0 ) {
			t = 0;
		} else {
			t = -t;
		}

		printf("Atraso maximo: %d\n", t);
	}

	return 0;
}