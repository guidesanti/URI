#include <stdio.h>

int main() {
	int s = 0;
	int e = 0;

	scanf("%u %u", &s, &e);

	if (s < e) {
		printf("O JOGO DUROU %u HORA(S)\n", e - s);
	} else {
		printf("O JOGO DUROU %u HORA(S)\n", 24 - s + e);
	}

	return 0;
}