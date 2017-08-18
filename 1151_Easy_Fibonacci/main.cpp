#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;
	int prev1 = 0;
	int prev2 = 1;

	scanf("%d", &n);

	printf("0 1 ");
	for (i = 2; i < (n - 1); i++) {
		int curr = (prev1 + prev2);
		printf("%d ", curr);
		prev1 = prev2;
		prev2 = curr;
	}
	printf("%d\n", prev1 + prev2);

	return 0;
}