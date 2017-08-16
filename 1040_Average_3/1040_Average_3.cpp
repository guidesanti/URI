#include <stdio.h>

int main()
{
	float N1 = 0.0;
	float N2 = 0.0;
	float N3 = 0.0;
	float N4 = 0.0;

	// Read the four numbers
	scanf("%f %f %f %f", &N1, &N2, &N3, &N4);

	// Calculate the average
	float average = (((2.0 * N1) + (3.0 * N2) + (4.0 * N3) + (1.0 * N4)) / 10.0);

	printf("Media: %.1f\n", average);

	if (average >= 7.0)
	{
		printf("Aluno aprovado.\n");
	}
	else if (average < 5.0)
	{
		printf("Aluno reprovado.\n");
	}
	else
	{
		float exameScore = 0.0;
		printf("Aluno em exame.\n");
		scanf("%f", &exameScore);
		printf("Nota do exame: %.1f\n", exameScore);
		average = ((average + exameScore) / 2.0);
		if (average >= 5.0)
		{
			printf("Aluno aprovado.\n");
		}
		else
		{
			printf("Aluno reprovado.\n");
		}
		printf("Media final: %.1f\n", average);
	}

	return 0;
}