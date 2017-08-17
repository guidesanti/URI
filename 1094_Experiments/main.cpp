#include <stdio.h>

int main() {
	int n = 0;
	int i = 0;
	int total = 0;
	int rabbit = 0;
	int rat = 0;
	int frog = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int amount = 0;
		char type = 0;
		scanf("%d %c", &amount, &type);
		total += amount;
		switch (type)
		{
		case 'C':
			rabbit += amount;
			break;
		case 'R':
			rat += amount;
			break;
		case 'S':
			frog += amount;
			break;
		default:
			break;
		}
	}

	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", rabbit);
	printf("Total de ratos: %d\n", rat);
	printf("Total de sapos: %d\n", frog);
	printf("Percentual de coelhos: %.2f %%\n", 100 * ((float)rabbit / (float)total));
	printf("Percentual de ratos: %.2f %%\n", 100 * ((float)rat / (float)total));
	printf("Percentual de sapos: %.2f %%\n", 100 * ((float)frog / (float)total));

	return 0;
}