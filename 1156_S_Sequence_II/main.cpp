#include <stdio.h>

int main() {
	double s = 0;
	int i = 0;
	int j = 0;

	for (i = 1, j = 1; i <= 39; i += 2, j *= 2) {
		s += ((double)i / (double)j);
	}
	printf("%.2lf\n", s);

	return 0;
}