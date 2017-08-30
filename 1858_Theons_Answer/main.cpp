#include <stdio.h>

int main() {
	int n = 0;
	int m = 20;
	int i = 0;
	int r = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		int v = 0;
		scanf("%d", &v);
		if (v < m) {
			m = v;
			r = i;
		}
	}

	printf("%d\n", r);

	return 0;
}