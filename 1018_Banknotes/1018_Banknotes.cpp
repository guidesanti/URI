#include <stdio.h>

#define NUMBER_OF_BANK_NOTES	(7)
int notes[NUMBER_OF_BANK_NOTES] = { 100, 50, 20, 10, 5, 2, 1 };

int main() {
	int value = 0;	// The value to be decomposed in bank notes

	// Read the value
	scanf("%d", &value);

	// Decompose the value into bank notes
	printf("%d\n", value);
	int i = 0;
	for (i = 0; i < NUMBER_OF_BANK_NOTES; i++)
	{
		int count = (value / notes[i]);
		value = (value % notes[i]);
		printf("%d nota(s) de R$ %d,00\n", count, notes[i]);
	}

	return 0;
}