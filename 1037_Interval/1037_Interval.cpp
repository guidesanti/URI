#include <stdio.h>
#include <string.h>

int main()
{
	char number[100];	// The number

	// Read the number
	scanf("%s", &number);
	
	int numberLength = (strlen(number) - 1);
	int value1 = 0;
	int value2 = 0;
	int i = 1;
	while (number[numberLength] >= '0' && number[numberLength] <= '9')
	{
		value2 += (i * (number[numberLength--] - '0'));
		i *= 10;
	}
	numberLength--;
	i = 1;
	while ((numberLength >= 0) && (number[numberLength] >= '0') && (number[numberLength] <= '9'))
	{
		value1 += (i * (number[numberLength--] - '0'));
		i *= 10;
	}

	if (number[numberLength] == '-')
	{
		printf("Fora de intervalo\n");
	}
	else if (((value1 >= 0) && (value1 < 25)) ||
		((value1 == 25) && (value2 == 0)))
	{
		printf("Intervalo [0,25]\n");
	}
	else if ((value1 < 50) || ((value1 == 50) && (value2 == 0)))
	{
		printf("Intervalo (25,50]\n");
	}
	else if ((value1 < 75) || ((value1 == 75) && (value2 == 0)))
	{
		printf("Intervalo (50,75]\n");
	}
	else if ((value1 < 100) || ((value1 == 100) && (value2 == 0)))
	{
		printf("Intervalo (75,100]\n");
	}
	else
	{
		printf("Fora de intervalo\n");
	}

	return 0;
}