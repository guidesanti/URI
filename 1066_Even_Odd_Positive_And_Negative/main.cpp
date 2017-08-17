#include <stdio.h>

int main() {
	int i = 0;
	int e = 0;
	int o = 0;
	int p = 0;
	int n = 0;
	int v = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &v);
		if ((v % 2) == 0) {
			e++;
		} else {
			o++;
		}
		if (v < 0) {
			n++;
		}
		if (v > 0) {
			p++;
		}
	}

	printf("%d valor(es) par(es)\n", e);
	printf("%d valor(es) impar(es)\n", o);
	printf("%d valor(es) positivo(s)\n", p);
	printf("%d valor(es) negativo(s)\n", n);

	return 0;
}