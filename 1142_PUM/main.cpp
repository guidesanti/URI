#include <stdio.h>

int main() {
	int n = 0;
	int i = 1;

	scanf("%d", &n);

	while (n--) {
		printf("%d %d %d PUM\n", i, i + 1, i + 2);
		i += 4;
	}

	return 0;
}