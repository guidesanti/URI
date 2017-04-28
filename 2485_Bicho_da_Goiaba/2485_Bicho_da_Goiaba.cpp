#include <stdio.h>

// Constraints
#define MIN_A	(2)
#define MAX_A	(102)
#define MIN_B	(2)
#define MAX_B	(102)

// Types
typedef struct Node Node;

struct Node {
	int row;
	int col;
	Node* next;
};

// Data
int numberOfTestCases = 0;
int numberOfRows = 0;
int numberOfCols = 0;
int treeMap[MAX_A][MAX_B];
int X = 0;
int Y = 0;
Node* list = NULL;
Node* list2 = NULL;
Node nodePool[MAX_A * MAX_B];
int nodePoolIndex = 0;

// Control
int i = 0;
int j = 0;

void ListAdd(Node** list, int row, int col) {
	Node* node = &nodePool[nodePoolIndex++];
	node->row = row;
	node->col = col;
	node->next = *list;
	*list = node;
}

void ListRemove(Node** list) {
	*list = (*list)->next;
}

int SpreadToNeibors(int row, int col) {
	int count = 0;

	// Row - 1
	if (treeMap[row - 1][col - 1] == 1) {
		ListAdd(&list2, row - 1, col - 1);
		treeMap[row - 1][col - 1] = 2;
		count++;
	}
	if (treeMap[row - 1][col] == 1) {
		ListAdd(&list2, row - 1, col);
		treeMap[row - 1][col] = 2;
		count++;
	}
	if (treeMap[row - 1][col + 1] == 1) {
		ListAdd(&list2, row - 1, col + 1);
		treeMap[row - 1][col + 1] = 2;
		count++;
	}

	// Row
	if (treeMap[row][col - 1] == 1) {
		ListAdd(&list2, row, col - 1);
		treeMap[row][col - 1] = 2;
		count++;
	}
	if (treeMap[row][col + 1] == 1) {
		ListAdd(&list2, row, col + 1);
		treeMap[row][col + 1] = 2;
		count++;
	}

	// Row + 1
	if (treeMap[row + 1][col - 1] == 1) {
		ListAdd(&list2, row + 1, col - 1);
		treeMap[row + 1][col - 1] = 2;
		count++;
	}
	if (treeMap[row + 1][col] == 1) {
		ListAdd(&list2, row + 1, col);
		treeMap[row + 1][col] = 2;
		count++;
	}
	if (treeMap[row + 1][col + 1] == 1) {
		ListAdd(&list2, row + 1, col + 1);
		treeMap[row + 1][col + 1] = 2;
		count++;
	}

	return count;
}

int Spread() {
	int days = 0;

	while (list) {
		int count = 0;
		while (list) {
			count += SpreadToNeibors(list->row, list->col);
			ListRemove(&list);
		}
		if (!count) {
			break;
		}
		days++;
		list = list2;
		list2 = NULL;
	}

	return days;
}

int main() {
	// Read the number of test cases
	scanf("%d", &numberOfTestCases);

	while (numberOfTestCases--) {
		// Reset control variables
		list = NULL;
		list2 = NULL;
		nodePoolIndex = 0;

		// Read the map dimensions
		scanf("%d %d", &numberOfRows, &numberOfCols);

		// Read the tree map
		for (i = 0; i < (numberOfRows + 2); i++) {
			treeMap[i][0] = -1;
			treeMap[i][numberOfCols + 1] = -1;
		}
		for (i = 0; i < (numberOfCols + 2); i++) {
			treeMap[0][i] = -1;
			treeMap[numberOfRows + 1][i] = -1;
		}
		for (i = 1; i <= numberOfRows; i++) {
			for (j = 1; j <= numberOfCols; j++) {
				scanf("%d", &treeMap[i][j]);
			}
		}

		// Read the medicine coordinates
		scanf("%d %d", &X, &Y);
		treeMap[X][Y] = 2;
		ListAdd(&list, X, Y);

		// Spread
		printf("%d\n", Spread());
	}

	return 0;
}