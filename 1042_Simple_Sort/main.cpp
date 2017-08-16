#include <stdio.h>

int main() {
	int values1[3] = { 0 };
	int values2[3] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int value = 0;

	// Read the three numbers
	for (i = 0; i < 3; i++) {
		scanf("%d", &value);
		values1[i] = value;
		values2[i] = value;
		for (j = 0; j <= i; j++) {
			if (values2[j] > value) {
				for (k = i; k > j; k--) {
					values2[k] = values2[k - 1];
				}
				values2[j] = value;
				break;
			}
		}
	}

	printf("%d\n%d\n%d\n\n", values2[0], values2[1], values2[2]);
	printf("%d\n%d\n%d\n", values1[0], values1[1], values1[2]);

	return 0;
}