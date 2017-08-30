#include <stdio.h>
#include <string.h>

int main() {
	int c = 0;

	scanf("%d", &c);

	while (c--) {
		char p[100];
		int n = 0;

		scanf("%s %d", p, &n);

		if (strcmp(p, "Thor") == 0) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}

	return 0;
}