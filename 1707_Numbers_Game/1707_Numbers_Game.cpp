#include <stdio.h>

// What is the sum of the decimal digits of the odd numbers in the range[min(x, y), max(x, y)](including the boundaries) ?

// Constranits
#define MIN_NUMBER_VALUE	1
#define MAX_NUMBER_VALUE	1000000000

// Data
int number1 = 0;
int number2 = 0;
int result = 0;

int main() {
	while (1) {
		// Read the numbers and check the stop condition
		if (scanf("%d %d", &number1, &number2) == EOF) {
			break;
		}

		// Reset
		result = 0;

		// Calculate the sum of the odd numbers
		// TODO

		// Print the result
		printf("%d\n", result);
	}

	return 0;
}