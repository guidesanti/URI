#include <stdio.h>
#include <string.h>

// Constraints
#define MAX_LENGTH	(100)

// Data
char D[MAX_LENGTH + 1];
int dlen = 0;
char S[MAX_LENGTH + 1];
int slen = 0;

int main() {
	while (1) {
		// Read D
		int ret = scanf("%s", D);
		dlen = strlen(D);

		if (ret == EOF) {
			break;
		}

		// Read S
		scanf("%s", S);
		slen = strlen(S);

		int found = 0;
		int i;
		int j = 0;
		for (i = 0; i < (dlen - slen + 1); i++) {
			if (D[i] == S[0]) {
				found = 1;
				for (j = 1; j < slen; j++) {
					if (D[i + j] != S[j]) {
						found = 0;
						break;
					}
				}
			}
			if (found) {
				break;
			}
		}

		if (found) {
			printf("Resistente\n");
		} else {
			printf("Nao resistente\n");
		}
	}

	return 0;
}