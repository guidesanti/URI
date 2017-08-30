#include <stdio.h>

int main() {
	char op = 0;
	int i = 0;
	int j = 0;
	double r = 0.0;

	scanf("%c", &op);

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			double v = 0.0;
			scanf("%lf", &v);
			if ((j < i) && (j < (11 - i)) && (j < 5)) {
				r += v;
			}
		}
	}

	if (op == 'M') {
		r /= 30.0;
	}

	printf("%.1lf\n", r);

	return 0;
}