#include <stdio.h>

int main() {
	int i = 0;
	int v = 0;

	scanf("%d", &v);

	for (i = 1; i <= v; i += 2) {
		printf("%d\n", i);
	}

	return 0;
}