#include <stdio.h>

char* months[] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

int main() {
	int m = 0;

	scanf("%d", &m);
	printf("%s\n", months[m]);

	return 0;
}