#include <stdio.h>
#include <string.h>

// Constraints
#define MAX_LENGTH	(30)

int main() {
	while (1) {
		char word[MAX_LENGTH + 1];
		int res = scanf("%s", word);
		int wordLen = strlen(word);

		if (res == EOF) {
			break;
		}

		int maxCount = 0;
		int count = 0;
		int middle = ((wordLen / 2) + 1);
		int i;
		for (i = 1; i < middle; i++) {
			int start = (wordLen - (2 * i));
			int end = (wordLen - i);
			count = 0;
			int j;
			for (j = start; j < end; j++) {
				if (word[j] != word[j + i]) {
					break;
				}
				count++;
			}
			if (j == end) {
				maxCount = count;
			}
		}
		word[wordLen - maxCount] = '\0';

		printf("%s\n", word);
	}

	return 0;
}