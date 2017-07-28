#include <stdio.h>

int main() {
	int d = 0;	// The distance between the cars X and Y

	// Read the distance between the car X and Y
	scanf("%d", &d);

	// Calculate the distance in time
	int t = (2 * d);

	// Write the output
	printf("%d minutos\n", t);

	return 0;
}