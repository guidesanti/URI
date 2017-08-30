#include <stdio.h>
#include <string.h>

int main() {
	int t = 0;
	int i = 0;

	scanf("%d", &t);

	for (i = 1; i <= t; i++) {
		char s1[20];
		char s2[20];

		scanf("%s %s", &s1, &s2);

		if (strcmp(s1, s2) == 0) {
			printf("Caso #%d: De novo!\n", i);
		} else if ((strcmp(s1, "tesoura") == 0 && strcmp(s2, "papel") == 0) ||
			(strcmp(s1, "papel") == 0 && strcmp(s2, "pedra") == 0) ||
			(strcmp(s1, "pedra") == 0 && strcmp(s2, "lagarto") == 0) ||
			(strcmp(s1, "lagarto") == 0 && strcmp(s2, "Spock") == 0) ||
			(strcmp(s1, "Spock") == 0 && strcmp(s2, "tesoura") == 0) ||
			(strcmp(s1, "tesoura") == 0 && strcmp(s2, "lagarto") == 0) ||
			(strcmp(s1, "lagarto") == 0 && strcmp(s2, "papel") == 0) ||
			(strcmp(s1, "papel") == 0 && strcmp(s2, "Spock") == 0) ||
			(strcmp(s1, "Spock") == 0 && strcmp(s2, "pedra") == 0) ||
			(strcmp(s1, "pedra") == 0 && strcmp(s2, "tesoura") == 0)) {
			printf("Caso #%d: Bazinga!\n", i);
		} else {
			printf("Caso #%d: Raj trapaceou!\n", i);
		}
	}

	return 0;
}