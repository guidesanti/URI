#include <stdio.h>
#include <string.h>

int main() {
	int qt = 0;

	scanf("%d", &qt);

	while (qt--) {
		char p1[100];
		char p2[100];
		char c1[6];
		char c2[6];
		int v1 = 0;
		int v2 = 0;
		int s = 0;

		scanf("%s %s %s %s", p1, c1, p2, c2);
		scanf("%d %d", &v1, &v2);

		s = (v1 + v2);

		if (s % 2) {
			if (strcmp(c1, "IMPAR") == 0) {
				printf("%s\n", p1);
			} else {
				printf("%s\n", p2);
			}
		}
		else {
			if (strcmp(c1, "PAR") == 0) {
				printf("%s\n", p1);
			}
			else {
				printf("%s\n", p2);
			}
		}
	}

	return 0;
}