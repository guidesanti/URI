#include <stdio.h>
#include <math.h>

int main()
{
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;

	// Read the three numbers
	scanf("%f %f %f", &a, &b, &c);

	// Calculate the roots
	float d = (pow(b, 2) - (4.0 * a * c));
	if ((a == 0.0) || (d <= 0.0))
	{
		printf("Impossivel calcular\n");
	}
	else
	{
		d = sqrt(d);
		float x1 = ((-b + d) / (2.0 * a));
		float x2 = ((-b - d) / (2.0 * a));
		printf("R1 = %.5f\n", x1);
		printf("R2 = %.5f\n", x2);
	}

	return 0;
}