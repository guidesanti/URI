#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	while (1) {
		char* password = readWord();
		if (strcmp(password, "2002") == 0) {
			printf("Acesso Permitido\n");
			break;
		} else {
			printf("Senha Invalida\n");
		}
	}

	return 0;
}