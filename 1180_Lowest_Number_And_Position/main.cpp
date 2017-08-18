#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	unsigned long arraySize = 0;
	unsigned long index = 0;
	long long inputValue = 0;
	long long outputValue = 0;

	// Read the array size
	scanf("%d", &arraySize);

	if (arraySize > 0)
	{
		scanf("%lld", &outputValue);
		for (unsigned long i = 1; i < arraySize; i++)
		{
			scanf("%lld", &inputValue);
			if (inputValue < outputValue)
			{
				index = i;
				outputValue = inputValue;
			}
		}

		printf("Menor valor: %lld\n", outputValue);
		printf("Posicao: %lu\n", index);
	}

	return 0;
}