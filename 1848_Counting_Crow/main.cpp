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
	char* str = NULL;
	int c = 0;
	int s = 0;

	while (1) {
		str = readLine();

		if (strcmp(str, "caw caw") == 0) {
			printf("%d\n", s);
			s = 0;
			c++;
			if (c >= 3) {
				break;
			}
		}

		if (str[0] == '*') s += 4;
		if (str[1] == '*') s += 2;
		if (str[2] == '*') s += 1;
	}

	return 0;
}