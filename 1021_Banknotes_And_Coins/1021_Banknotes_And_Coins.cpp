#include <stdio.h>
#include <string.h>

#define NUMBER_OF_NOTES	(6)
int notes[NUMBER_OF_NOTES] = { 100, 50, 20, 10, 5, 2 };
#define NUMBER_OF_COINS	(6)
int coins[NUMBER_OF_COINS] = { 100, 50, 25, 10, 5, 1 };

int main() {
	char valueStr[20];	// The value to be decomposed in notes and coins

	// Read the value
	scanf("%s", &valueStr);

	int valueStrLen = (strlen(valueStr) - 1);
	int value1 = 0;
	int value2 = 0;
	int i = 1;
	while (valueStr[valueStrLen] >= '0' && valueStr[valueStrLen] <= '9')
	{
		value2 += (i * (valueStr[valueStrLen--] - '0'));
		i *= 10;
	}
	valueStrLen--;
	i = 1;
	while (valueStrLen >= 0)
	{
		value1 += (i * (valueStr[valueStrLen--] - '0'));
		i *= 10;
	}
	
	// Decompose the value into notes
	printf("NOTAS:\n");
	for (i = 0; i < NUMBER_OF_NOTES; i++)
	{
		int count = (value1 / notes[i]);
		value1 = (value1 % notes[i]);
		printf("%d nota(s) de R$ %d.00\n", count, notes[i]);
	}

	// Decompose the value into coins
	value2 += (100 * value1);
	printf("MOEDAS:\n");
	for (i = 0; i < NUMBER_OF_COINS; i++)
	{
		int count = (value2 / coins[i]);
		value2 = (value2 % coins[i]);
		printf("%d moeda(s) de R$ %.2f\n", count, (float)coins[i]/100.0);
	}

	return 0;
}