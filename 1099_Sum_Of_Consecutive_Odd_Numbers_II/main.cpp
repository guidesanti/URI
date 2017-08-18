#include <stdio.h>

int main() {
	int n = 0;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int aux = 0;
		scanf("%d %d", &x, &y);
		if (x > y) {
			aux = x;
			x = y;
			y = aux;
		}
		if (x % 2) {
			x += 2;
		} else {
			x++;
		}
		if (y % 2) {
			y -= 2;
		} else {
			y--;
		}
		aux = 0;
		for (; x <= y; aux += x, x += 2);
		printf("%d\n", aux);
	}

	return 0;
}