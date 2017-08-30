#include <stdio.h>

int main() {
	char op = 0;
	int i = 0;
	int j = 0;
	float r = 0.0;

	scanf("%c", &op);

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			float v = 0.0;
			scanf("%f", &v);
			if (j < (11 - i)) {
				r += v;
			}
		}
	}

	if (op == 'M') {
		r /= 66.0;
	}

	printf("%.1f\n", r);

	return 0;
}