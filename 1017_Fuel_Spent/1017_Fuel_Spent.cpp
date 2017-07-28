#include <stdio.h>

int main() {
	int time = 0;			// Spent time (in hours)
	int averageSpeed = 0;	// Average speed (in Km/h)
	float liters = 0;		// Required fuel (in liters)

	// Read spent time
	scanf("%d", &time);

	// Read the average speed
	scanf("%d", &averageSpeed);

	// Calculate the required fuel
	liters = ((((float)time) * ((float)averageSpeed)) / 12.0);

	// Write the output
	printf("%.3f\n", liters);

	return 0;
}