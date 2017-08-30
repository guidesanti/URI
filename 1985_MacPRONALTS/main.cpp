#include <stdio.h>

double v[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };

int main() {
	int p = 0;
	double t = 0;

	scanf("%d", &p);

	while (p--) {
		int a = 0;
		int b = 0;

		scanf("%d %d", &a, &b);

		t += (b * v[a - 1001]);
	}

	printf("%.2lf\n", t);

	return 0;
}