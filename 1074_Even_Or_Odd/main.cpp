#include <stdio.h>

int main() {
	int n = 0;
	int v = 0;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &v);
		if (v) {
			if (v % 2) {
				if (v < 0) {
					printf("ODD NEGATIVE\n");
				} else {
					printf("ODD POSITIVE\n");
				}
			}
			else {
				if (v < 0) {
					printf("EVEN NEGATIVE\n");
				}
				else {
					printf("EVEN POSITIVE\n");
				}
			}
		} else {
			printf("NULL\n");
		}
	}

	return 0;
}