#include <stdio.h>

int main() {
	int v = 0;
	int i = 0;

	scanf("%d", &v);

	for (i = 0; i < 10; i++) {
		printf("N[%d] = %d\n", i, v);
		v *= 2;
	}

	return 0;
}