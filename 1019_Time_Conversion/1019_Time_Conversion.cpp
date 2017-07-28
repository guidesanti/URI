#include <stdio.h>

int main() {
	int time = 0;	// time (in seconds)

	// Read the time
	scanf("%d", &time);

	// Calculate the hours, minutes and seconds
	int hours = (time / 3600);
	time %= 3600;
	int minutes = (time / 60);
	time %= 60;
	int seconds = time;

	// Write the output
	printf("%d:%d:%d\n", hours, minutes, seconds);

	return 0;
}