#include <stdio.h>

int a[] = { 1, 5, 10, 50, 100, 500, 1000 };

char b[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

int main() {
	int n = 0;
	char s[100];
	int si = 0;
	int i = 0;
	int aux = 0;

	scanf("%d", &n);


	while (n) {
		int minDiff = 1001;
		int minIndex = 0;
		for (i = 0; i < 7; i++) {
			int diff = 0;
			if (n > a[0]) {
				diff = (n - a[0]);
			} else {
				diff = (a[0] - n);
			}
			if (diff < minDiff) {
				minDiff = diff;
				minIndex = i;
			}
		}

	}

	return 0;
}