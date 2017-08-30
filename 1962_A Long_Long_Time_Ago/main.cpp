#include <stdio.h>

int main() {
	int n = 0;

	scanf("%d", &n);

	while (n--) {
		unsigned long long t = 0;

		scanf("%llu", &t);

		if (t >= 2015) {
			printf("%llu A.C.\n", t - 2014);
		} else {
			printf("%llu D.C.\n", 2015 - t);
		}
	}

	return 0;
}