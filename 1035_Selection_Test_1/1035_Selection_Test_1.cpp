#include <stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

	// Read the values
	scanf("%d %d %d %d", &A, &B, &C, &D);

	if ((B > C) &&
		(D > A) &&
		((C + D) > (A + B)) &&
		((C > 0) && (D > 0)) &&
		((A % 2) == 0))
	{
		printf("Valores aceitos\n");
	}
	else
	{
		printf("Valores nao aceitos\n");
	}

    return 0;
}

