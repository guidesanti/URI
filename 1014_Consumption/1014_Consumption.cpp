#include <stdio.h>

int main() {
	int X = 0;
	float Y = 0.0;

	scanf("%d", &X);
	scanf("%f", &Y);

	printf("%.3f km/l\n", ((double)X)/Y);

	return 0;
}