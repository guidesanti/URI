#include <stdio.h>

int main() {
	int i = 0;
	int v = 0;

	scanf("%d", &v);

	if (v % 2 == 0) {
		v++;
	}
	for (i = 0; i < 6; i++) {
		printf("%d\n", v);
		v += 2;
	}

	return 0;
}