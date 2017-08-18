#include <stdio.h>

int main() {
	int l = 0;
	char op = 0;
	float v = 0;
	int i = 0;
	int j = 0;
	float r = 0;

	scanf("%d\n", &l);
	scanf("%c", &op);

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			scanf("%f", &v);
			if (i == l) {
				r += v;
			}
		}
	}

	if (op == 'M') {
		r /= 12.0;
	}

	printf("%.1f\n", r);

	return 0;
}