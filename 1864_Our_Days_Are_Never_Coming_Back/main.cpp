#include <stdio.h>

char* str = "LIFE IS NOT A PROBLEM TO BE SOLVED";

int main() {
	int n = 0;
	int i = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		putc(str[i], stdout);
	}
	putc('\n', stdout);

	return 0;
}