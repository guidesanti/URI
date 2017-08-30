#include <stdio.h>

int main() {
	int p = 0;
	int n = 0;
	int i = 0;
	int c = 0;
	int r = 0;

	scanf("%d %d", &p, &n);
	scanf("%d", &c);
	for (i = 1; i < n; i++) {
		int v = 0;
		int d = 0;
		scanf("%d", &v);
		if (v > c) {
			d = (v - c);
		} else {
			d = (c - v);
		}
		if (d > p) {
			r = 1;
		}
		c = v;
	}

	if (r) {
		printf("GAME OVER\n");
	}
	else {
		printf("YOU WIN\n");
	}

	return 0;
}