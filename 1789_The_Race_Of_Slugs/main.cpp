#include <stdio.h>

int main() {
	int l = 0;

	while (scanf("%d", &l) != EOF) {
		int s = 0;

		while (l--) {
			int v = 0;

			scanf("%d", &v);
			if (v < 10) {
				v = 1;
			} else if (v < 20) {
				v = 2;
			} else {
				v = 3;
			}
			if (s < v) {
				s = v;
			}
		}

		printf("%d\n", s);
	}

	return 0;
}