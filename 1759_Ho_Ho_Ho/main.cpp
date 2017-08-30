#include <stdio.h>

int main() {
	int n = 0;

	scanf("%d", &n);

	while (n--) {
		if (n) {
			printf("Ho ");
		}
		else {
			printf("Ho!\n");
		}
	}

	return 0;
}