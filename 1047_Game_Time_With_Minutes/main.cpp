#include <stdio.h>

int main() {
	int sh = 0;
	int sm = 0;
	int eh = 0;
	int em = 0;
	int h = 0;
	int m = 0;

	scanf("%u %u %u %u", &sh, &sm, &eh, &em);

	sm += (60 * sh);
	em += (60 * eh);

	if (sm < em) {
		printf("O JOGO DUROU %u HORA(S) E %u MINUTO(S)\n", (em - sm) / 60, (em - sm) % 60);
	} else {
		printf("O JOGO DUROU %u HORA(S) E %u MINUTO(S)\n", (1440 - sm + em) / 60, (1440 - sm + em) % 60);
	}

	return 0;
}