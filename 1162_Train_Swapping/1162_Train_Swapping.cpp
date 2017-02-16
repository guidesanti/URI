#include <stdio.h>

#define MAX_TRAIN_LENGTH	(50)

// Data
int N = 0; // Number of test cases
int L = 0; // Length of the train (0 <= L <= 50)
int T[MAX_TRAIN_LENGTH]; // The train
int S = 0;

// Control
int i; // Loop indexing
int s; // Num of swaps within a loop

int main() {
	// Read the number of test cases
	scanf("%d", &N);

	while (N--) {
		// Read the train length
		scanf("%d", &L);

		// Read the train
		for (i = 0; i < L; i++) {
			scanf("%d", &T[i]);
			T[i]--;
		}

		// Calculate the number of swaps
		S = 0;
		do {
			s = 0;
			for (i = 0; i < (L - 1); i++) {
				if ((T[i] > i) && (T[i] > T[i + 1])) {
					int aux = T[i];
					T[i] = T[i + 1];
					T[i + 1] = aux;
					s++;
					S++;
				}
			}
		} while (s);

		// Print out the result
		printf("Optimal train swapping takes %d swaps.\n", S);
	}

	return 0;
}