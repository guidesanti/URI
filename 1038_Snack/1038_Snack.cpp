#include <stdio.h>

#define NUMBER_OF_ITEMS	(5)
float priceTable[NUMBER_OF_ITEMS] = { 4.0, 4.5, 5.0, 2.0, 1.5 };

int main()
{
	int X = 0;
	int Y = 0;

	// Read X and Y
	scanf("%d %d", &X, &Y);

	// Calculate and print the total price
	printf("Total: R$ %.2f\n", priceTable[X - 1] * Y);

	return 0;
}