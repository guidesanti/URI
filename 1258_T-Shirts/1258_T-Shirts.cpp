#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_WHITE		(0)
#define COLOR_RED		(1)
#define N_COLORS		(2)
#define COLOR_UNDEFINED	(N_COLORS)

#define SIZE_P			(0)
#define SIZE_M			(1)
#define SIZE_G			(2)
#define N_SIZES			(3)
#define SIZE_UNDEFINED	(N_SIZES)

typedef struct TShirtInfo TShirtInfo;

struct TShirtInfo {
	int			color;
	int			size;
	char*		name;
	TShirtInfo*	next;
};

char* colors[N_COLORS] = {
	"branco",
	"vermelho"
};

char* sizes[N_SIZES] = {
	"P",
	"M",
	"G"
};

// Data
int N = 0; // The amount of t-shirts (1 <= N <= 60)
TShirtInfo* list = NULL;

// Control
int i = 0; // General loop control variable

#define DEFAULT_LINE_LENGTH	(100)
#define DEFAULT_WORD_LENGTH	(15)

char* readLine(void) {
	char* line = (char*)malloc(DEFAULT_LINE_LENGTH * sizeof(char));
	int lineLength = DEFAULT_LINE_LENGTH;
	int index = 0;
	char ch = 0;

	if (!line) {
		return NULL;
	}

	while (1) {
		ch = fgetc(stdin);
		if ((ch == EOF) || (ch == '\n')) {
			break;
		}

		if (index == (lineLength - 1)) {
			char* newLine = (char*)realloc(line, 2 * lineLength);
			if (!newLine) {
				free(line);
				return NULL;
			}
			line = newLine;
			lineLength *= 2;
		}

		line[index++] = ch;
	}
	line[index] = '\0';

	return line;
}

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

int compareTShirt(TShirtInfo* t1, TShirtInfo* t2) {
	if (t1->color < t2->color) {
		return 1;
	} else if (t1->color > t2->color) {
		return 2;
	} else {
		if (t1->size < t2->size) {
			return 1;
		} else if (t1->size > t2->size) {
			return 2;
		} else {
			int len1 = strlen(t1->name);
			int len2 = strlen(t2->name);
			int len = 0;
			(len1 < len2) ? (len = len1) : (len = len2);
			int i = 0;
			for (i = 0; i < len; i++) {
				if (t1->name[i] < t2->name[i]) {
					return 1;
				}
				if (t1->name[i] > t2->name[i]) {
					return 2;
				}
			}
			if (len1 < len2) {
				return 1;
			} else if (len1 > len2) {
				return 2;
			} else {
				return 0;
			}
		}
	}
	return -1;
}

void insertTShirt(char* color, char* size, char* name) {
	TShirtInfo* tshirt = (TShirtInfo*)malloc(sizeof(TShirtInfo));

	// Set the color
	int c = 0;
	for (c = 0; c < N_COLORS; c++) {
		if (!strcmp(color, colors[c])) {
			tshirt->color = c;
			break;
		}
	}

	// Set the size
	int s = 0;
	for (s = 0; s < N_SIZES; s++) {
		if (!strcmp(size, sizes[s])) {
			tshirt->size = s;
			break;
		}
	}

	// Set the name
	tshirt->name = name;

	// Insert into the list
	if (list) {
		if (compareTShirt(tshirt, list) == 1) {
			tshirt->next = list;
			list = tshirt;
		}
		else {
						int done = 0;
			TShirtInfo* prev = list;
			TShirtInfo* curr = prev->next;
			while (curr) {
				if (compareTShirt(tshirt, curr) == 1) {
					tshirt->next = curr;
					prev->next = tshirt;
					done = 1;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			if (!done) {
				prev->next = tshirt;
				tshirt->next = NULL;
			}
		}
	} else {
		tshirt->next = list;
		list = tshirt;
	}
}

void removeTShirt() {
	TShirtInfo* tshirt = list;
	if (tshirt) {
		list = tshirt->next;
		free(tshirt->name);
		free(tshirt);
	}
}

int main() {
	int first = 1;
	while (1) {
		// Read the number of t-shirts
		char* numberOfTShirts = readLine();
		N = atoi(numberOfTShirts);
		//scanf("%d\n", &N);
		free(numberOfTShirts);

		// Check the stop condition
		if (!N) {
			break;
		}

		if (!first) {
			printf("\n");
		}
		first = 0;

		// Read the t-shirts details
		for (i = 0; i < N; i++) {
			// Read the name
			char* name = readLine();

			// Read the color and size
			char* color = readWord();
			char* size = readWord();

			// Insert the t-shirt into the list
			insertTShirt(color, size, name);

			free(color);
			free(size);
		}

		// Print the t-shirt list
		while (list) {
			printf("%s %s %s\n", colors[list->color], sizes[list->size], list->name);
			removeTShirt();
		}
	}

	return 0;
}