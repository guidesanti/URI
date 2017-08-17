#include <stdio.h>

int main() {
	int i = 0;
	int v = 0;
	int index = 0;
	int max = 0;

	index = 1;
	scanf("%d", &max);
	for (i = 2; i <= 100; i++) {
		scanf("%d", &v);
		if (v > max) {
			index = i;
			max = v;
		}
	}

	printf("%d\n%d\n", max, index);

	return 0;
}