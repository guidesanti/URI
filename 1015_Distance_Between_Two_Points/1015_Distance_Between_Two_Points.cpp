#include <stdio.h>
#include <math.h>

int main() {
	float p1[2];
	float p2[2];

	scanf("%f %f", &p1[0], &p1[1]);
	scanf("%f %f", &p2[0], &p2[1]);

	float d = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));

	printf("%.4f\n", d);

	return 0;
}