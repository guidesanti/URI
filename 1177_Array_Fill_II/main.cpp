#include <stdio.h>

int main() {
	int t = 0;
	int i = 0;
	int v = 0;

	scanf("%d", &t);

	for (i = 0; i < 1000; i++) {
		printf("N[%d] = %d\n", i, v);
		v = ((v + 1) % t);
	}

	return 0;
}