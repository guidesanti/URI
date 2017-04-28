#include <stdio.h>

// Constraints
#define MAX_DICTIONARY_SIZE		(75000)
#define MIN_NUMBER_OF_PHONES	(1)
#define MAX_NUMBER_OF_PHONES	(100000)
#define MAX_WORD_SIZE			(50)

// Data
int dictionarySize = 0;
char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_SIZE + 1];
int numberOfPhones = 0;

// Control
int i = 0;

int main() {

	while (1) {
		// Read the dictionary size
		scanf("%d", &dictionarySize);

		if (!dictionarySize) {
			break;
		}

		// Read the dictionary
		for (i = 0; i < dictionarySize; i++) {
			scanf("%s", dictionary[i]);
		}

		// Read the number of phones
		scanf("%d", &numberOfPhones);

		// Read the phones
		for (i = 0; i < numberOfPhones; i++) {
			char phone[50];
			scanf("%s", phone);
		}
	}

	return 0;
}