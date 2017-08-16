#include <stdio.h>

int main()
{
	unsigned int n1 = 0;
	unsigned int n2 = 0;

	// Read the two numbers
	while (scanf("%u %u", &n1, &n2) != EOF)
	{
		// Calculate the sum
		unsigned int sum = (n1 ^ n2);

		// Write the output
		printf("%u\n", sum);
	}

	return 0;
}