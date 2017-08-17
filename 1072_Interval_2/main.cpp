#include <stdio.h>

int main() {
	int n = 0;
	int x = 0;
	int i = 0;
	int in = 0;
	int out = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x >= 10 && x <= 20) {
			in++;
		} else {
			out++;
		}
	}

	printf("%d in\n", in);
	printf("%d out\n", out);

	return 0;
}