#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINE_LENGTH	(100)

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

int main() {
	char* a = readLine();
	char* b = readLine();
	char* c = readLine();

	if (strcmp(a, "vertebrado") == 0) {
		if (strcmp(b, "ave") == 0) {
			if (strcmp(c, "carnivoro") == 0) {
				printf("aguia\n");
			} else {
				printf("pomba\n");
			}
		} else {
			if (strcmp(c, "onivoro") == 0) {
				printf("homem\n");
			}
			else {
				printf("vaca\n");
			}
		}
	} else {
		if (strcmp(b, "inseto") == 0) {
			if (strcmp(c, "hematofago") == 0) {
				printf("pulga\n");
			}
			else {
				printf("lagarta\n");
			}
		}
		else {
			if (strcmp(c, "hematofago") == 0) {
				printf("sanguessuga\n");
			}
			else {
				printf("minhoca\n");
			}
		}
	}

	return 0;
}