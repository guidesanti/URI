#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		k = 1;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				int v = (k << (j - 1));
				switch (n)
				{
				case 1:
				case 2:
					printf("%1d", v);
					break;
				case 3:
				case 4:
					printf("%2d", v);
					break;
				case 5:
					printf("%3d", v);
					break;
				case 6:
				case 7:
					printf("%4d", v);
					break;
				case 8:
				case 9:
					printf("%5d", v);
					break;
				case 10:
					printf("%6d", v);
					break;
				case 11:
				case 12:
					printf("%7d", v);
					break;
				case 13:
				case 14:
					printf("%8d", v);
					break;
				case 15:
					printf("%9d", v);
					break;
				default: break;
				}
				if (j < n) {
					printf(" ");
				}
				else {
					printf("\n");
				}
			}
			k <<= 1;
		}

		printf("\n");
	}

	return 0;
}