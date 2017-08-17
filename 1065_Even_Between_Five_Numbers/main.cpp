#include <stdio.h>

int main() {
	int i = 0;
	int c = 0;
	int v = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &v);
		if ((v % 2) == 0) {
			c++;
		}
	}

	printf("%d valores pares\n", c);

	return 0;
}