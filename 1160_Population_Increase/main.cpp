#include <stdio.h>

int main() {
	int t = 0;

	scanf("%d", &t);

	while (t--) {
		int pa = 0;
		int pb = 0;
		double g1 = 0.0;
		double g2 = 0.0;
		int a = 0;

		scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
		g1 /= 100.0;
		g2 /= 100.0;

		while ((pa <= pb) && (a <= 100)) {
			pa = (pa + (pa * g1));
			pb = (pb + (pb * g2));
			a++;
		}

		if (a <= 100) {
			printf("%d anos.\n", a);
		} else {
			printf("Mais de 1 seculo.\n");
		}
	}

	return 0;
}