#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_WORD_LENGTH	(15)

char* readWord(void) {
	int wordLength = DEFAULT_WORD_LENGTH;
	char* word = (char*)malloc(wordLength * sizeof(char));
	int index = 0;
	char ch = 0;

	if (!word) {
		return NULL;
	}

	// Find the start of the word
	while (1) {
		ch = fgetc(stdin);
		if ((ch != ' ') && (ch != '\n') && (ch != EOF)) {
			word[index++] = ch;
			break;
		}
	}

	// Read the word
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
	int sd = 0;
	int sh = 0;
	int sm = 0;
	int ss = 0;
	int ed = 0;
	int eh = 0;
	int em = 0;
	int es = 0;
	int t = 0;
	char* str = NULL;

	readWord();
	str = readWord();
	sd = atoi(str);
	
	str = readWord();
	sh = atoi(str);
	readWord();
	str = readWord();
	sm = atoi(str);
	readWord();
	str = readWord();
	ss = atoi(str);

	readWord();
	str = readWord();
	ed = atoi(str);

	str = readWord();
	eh = atoi(str);
	readWord();
	str = readWord();
	em = atoi(str);
	readWord();
	str = readWord();
	es = atoi(str);
	
	t = (((86400 * ed) + (3600 * eh) + (60 * em) + es) - ((86400 * sd) + (3600 * sh) + (60 * sm) + ss));

	printf("%d dia(s)\n", t / 86400);
	t %= 86400;
	printf("%d hora(s)\n", t / 3600);
	t %= 3600;
	printf("%d minuto(s)\n", t / 60);
	t %= 60;
	printf("%d segundo(s)\n", t);

	return 0;
}