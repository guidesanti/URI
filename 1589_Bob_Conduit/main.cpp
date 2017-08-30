#include <stdio.h>

int main() {
	int t = 0;

	scanf("%d", &t);

	while (t--) {
		int r1 = 0;
		int r2 = 0;

		scanf("%d %d", &r1, &r2);

		printf("%d\n", r1 + r2);
	}

	return 0;
}