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
	char* s = readLine();
	int v = atoi(s);

	switch (v)
	{
	case 61:
		printf("Brasilia\n");
		break;
	case 71:
		printf("Salvador\n");
		break;
	case 11:
		printf("Sao Paulo\n");
		break;
	case 21:
		printf("Rio de Janeiro\n");
		break;
	case 32:
		printf("Juiz de Fora\n");
		break;
	case 19:
		printf("Campinas\n");
		break;
	case 27:
		printf("Vitoria\n");
		break;
	case 31:
		printf("Belo Horizonte\n");
		break;
	default:
		printf("DDD nao cadastrado\n");
		break;
	}

	return 0;
}