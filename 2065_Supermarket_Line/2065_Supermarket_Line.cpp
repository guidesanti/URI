#include <stdio.h>
#include <stdlib.h>

// Constraints
#define MAX_CASHIERS	(10000)	// The maximum number of cashiers
#define MAX_CLIENTS		(10000)	// The maximum number of clients

// Data
int N = 0;				// The number of cashiers (values from 1 to MAX_CASHIERS)
int v[MAX_CASHIERS];	// The time to process an item for each cashier
int M = 0;				// The number of clients (values from 1 to MAX_CLIENTS)
int c[MAX_CLIENTS];		// The number of items in the basket for each client
int time = 0;			// Time to process all items from all clients

// Control
int i = 0;						// Index to control loops
int cashiers[MAX_CASHIERS];		// The cashiers to process client items
int* clientQueueStart = NULL;	// A pointer to indicate the start of the client queue
//int clientQueueLenth = 0;		// The length of the client queue

#define DEFAULT_WORD_LENGTH	(10)
char* readWord(void) {
	int wordLength = DEFAULT_WORD_LENGTH;
	char* word = (char*)malloc(wordLength * sizeof(char));
	int index = 0;
	char ch = 0;

	if (!word) {
		return NULL;
	}

	while (1) {
		ch = fgetc(stdin);
		if ((ch == ' ') || (ch == '\n') || (ch == EOF)) {
			break;
		}

		if (index == wordLength) {
			char* newLine = (char*)realloc(word, 2 * wordLength);
			if (!newLine) {
				free(word);
				return NULL;
			}
			word = newLine;
			wordLength *= 2;
		}

		word[index++] = ch;
	}
	word[index] = '\0';

	return word;
}

int main() {
	// Initialize the cashiers
	for (i = 0; i < MAX_CASHIERS; i++) {
		cashiers[i] = 0;
	}

	// Read N and M
	scanf("%d %d\n", &N, &M);

	// Read the time to process an item for each cashier
	for (i = 0; i < N; i++) {
		char* value = readWord();
		v[i] = atoi(value);
		free(value);
	}

	// Read the number of items in the basket of each client
	for (i = 0; i < M; i++) {
		char* value = readWord();
		c[i] = atoi(value);
		free(value);
	}
	clientQueueStart = &c[0];

	// Process the input
	while (1) {
		int numberOfProcessedItems = 0;
		for (i = 0; i < N; i ++) {
			if (cashiers[i]) {
				cashiers[i]--;
				numberOfProcessedItems++;
			} else {
				if (M) {
					cashiers[i] = ((v[i] * (*clientQueueStart)) - 1);
					clientQueueStart++;
					M--;
					numberOfProcessedItems++;
				}
			}
		}
		if (!numberOfProcessedItems) {
			break;
		}
		time++;
	}

	// Print the time to process all items from all clients
	printf("%d\n", time);

	return 0;
}