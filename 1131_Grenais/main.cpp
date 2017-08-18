#include <stdio.h>

int main() {
	int grenais = 0;
	int inter = 0;
	int gremio = 0;
	int ties = 0;

	while (1) {
		int a = 0;
		int b = 0;

		scanf("%d %d", &a, &b);
		grenais++;
		if (a > b) {
			inter++;
		} else if (a < b) {
			gremio++;
		} else {
			ties++;
		}

		int op = 0;
		while (op < 1 || op > 2) {
			printf("Novo grenal (1-sim 2-nao)\n");
			scanf("%d", &op);
		}

		if (op == 2) {
			break;
		}
	}

	printf("%d grenais\n", grenais);
	printf("Inter:%d\n", inter);
	printf("Gremio:%d\n", gremio);
	printf("Empates:%d\n", ties);
	if (inter > gremio) {
		printf("Inter venceu mais\n");
	} else if (inter < gremio) {
		printf("Gremio venceu mais\n");
	} else {
		printf("Nao houve vencedor\n");
	}

	return 0;
}