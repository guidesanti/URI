#include <stdio.h>

int main() {
	int n = 0;
	int f = 0;

	scanf("%d", &n);

	f = n;
	while (n--) {
		if (n == 0) {
			break;
		}
		f *= n;
	}
	printf("%d\n", f);

	return 0;
}