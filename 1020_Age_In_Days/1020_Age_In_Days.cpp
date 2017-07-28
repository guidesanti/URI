#include <stdio.h>

int main() {
	int age = 0;	// The age (in days)

	// Read the age
	scanf("%d", &age);

	// Convert to years, months and days
	int years = (age / 365);
	age %= 365;
	int months = (age / 30);
	age %= 30;
	int days = age;

	// Write the output
	printf("%d ano(s)\n", years);
	printf("%d mes(es)\n", months);
	printf("%d dia(s)\n", days);

	return 0;
}