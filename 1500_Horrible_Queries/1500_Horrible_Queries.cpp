#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constraints
#define MAX_NUMBER_OF_ELEMENTS	(100000)
#define MAX_NUMBER_OF_COMMANDS	(100000)

#define PARENT(i)				((i % 2) ? ((i - 1) / 2) : ((i - 2) / 2))
#define LEFT(i)					((2 * (i)) + 1)
#define RIGHT(i)				((2 * (i)) + 2)

// Data
int		dictionarySize = 0;
int		numberOfElements = 0;
int		numberOfCommands = 0;
long*	tree = NULL;
int		treeHeight = 0;
int		treeSize = 0;
long*	lazyTree = NULL;
int		arraySize = 0;

#if 0

void updateTree(int* tree, int treeIndex, int start, int end, int i, int diff) {
	if ((i < start) || (i > end)) {
		return;
	}

	tree[treeIndex] += diff;
	if (start != end) {
		int middle = (start + ((end - start) / 2));
		updateTree(tree, LEFT(treeIndex), start, middle, i, diff);
		updateTree(tree, RIGHT(treeIndex), middle + 1, end, i, diff);
	}
}

void updateElement(int* tree, int n, int i, int diff) {
	updateTree(tree, 0, 0, n - 1, i, diff);
}

void updateRange(int* tree, int n, int start, int end, int diff) {
	while (start <= end) {
		updateElement(tree, n, start, diff);
		start++;
	}
}

void updateArray(int* array, int start, int end, int diff) {
	while (start <= end) {
		upArray[start] = 1;
		array[start++] += diff;
	}
}

void updateTree(int* tree, int start, int end, int diff) {
	int index;
	int s = 0;
	int e = 0;
	while (start < end) {
		if (upArray[start]) {
			s = 1;
		} else {
			start++;
			if (start == end) {
				break;
			}
		}
		if (upArray[end]) {
			e = 1;
		}
		else {
			end--;
			if (start == end) {
				break;
			}
		}
		if (s && e) {
			break;
		}
	}
	while ((start >= 0) && (end >= 0)) {
		for (index = start; index <= end; index++) {
			tree[index] = (tree[LEFT(index)] + tree[RIGHT(index)]);
		}
		start = PARENT(start);
		end = PARENT(end);
	}
}

int sumRange(int* tree, int treeIndex, int start, int end, int starti, int endi) {
	int sum = 0;

	if ((starti > end) || (endi < start)) {
		return 0;
	}

	if (starti == endi) {
		sum += tree[treeIndex];
	} else {
		int left = LEFT(treeIndex);
		int right = RIGHT(treeIndex);
		int middle = (starti + ((endi - starti) / 2));
		sum += sumRange(tree, left, start, end, starti, middle);
		sum += sumRange(tree, right, start, end, middle + 1, endi);
	}

	return sum;
}

#endif

void updateRange(int start, int end, long diff) {
	int rangeSize = arraySize;
	int s = 1;
	int e = numberOfElements;
	int ss = 1;
	int ee = 2;
	int i;
	lazyTree[0] += diff;
	while ((s < start) || (e < end)) {
		// Update level
		for (i = ss; i <= ee; i++) {
			lazyTree[i] += diff;
		}
		
		// Next level
		rangeSize /= 2;
		if (start < ) {

		}
	}
}

void sumRange(int start, int end, long diff) {
	// TODO
}

void printTree(int* tree, int treeSize) {
	int h = 0;
	int i = 0;
	int n = 1;
	int j = 0;

	printf("Trre:\n");
	while (i < treeSize) {
		printf("%d: ", h);

		for (j = 0; j < n; j++) {
			printf("%d ", tree[i++]);
		}
		h++;
		n *= 2;

		printf("\n");
	}
}

int main() {
	// Read the number of test cases
	scanf("%d", &dictionarySize);

	while (dictionarySize--) {
		// Read N and C
		scanf("%d %d", &numberOfElements, &numberOfCommands);

		// Allocate memory for the tree
		//int x = (int)(ceil(log2(numberOfElements)));
		//treeSize = (2 * (int)pow(2, x) - 1);
		arraySize = 1;
		treeHeight = 0;
		treeSize = 1;
		while (arraySize < numberOfElements) {
			arraySize <<= 1;
			treeHeight++;
			treeSize += arraySize;
		}
		tree = (long*)calloc(treeSize, sizeof(long));
		lazyTree = (long*)calloc(treeSize, sizeof(long));

		// Read each command
		while (numberOfCommands--) {
			int command = 0;
			int start = 0;
			int end = 0;
			long diff = 0;

			scanf("%d %d %d", &command, &start, &end);
			start--;
			end--;

			if (command) {
				//printf("%d\n", sumRange(tree, 0, start, end, 0, numberOfElements - 1));
			} else {
				scanf("%d", &diff);
				//updateRange(start, end, diff);
			}
		}

		free(tree);
		free(lazyTree);
	}

	return 0;
}