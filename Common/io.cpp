#include "io.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINE_LENGTH	(100)
#define DEFAULT_WORD_LENGTH	(15)

char* readLine(void) {
	int lineLength = DEFAULT_LINE_LENGTH;
	char* line = (char*)malloc(lineLength * sizeof(char));
	int index = 0;
	char ch = 0;

	if (!line) {
		return NULL;
	}

	while (1) {
		ch = fgetc(stdin);
		if ((ch == '\n') || (ch == EOF)) {
			break;
		}

		if (index == lineLength) {
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