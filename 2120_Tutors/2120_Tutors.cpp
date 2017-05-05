#include <stdio.h>
#include <stdlib.h>

// Constrainsts
#define MAX_STUDENTS	(100000)

// Types
typedef struct Student Student;

struct Student {
	int			id;
	Student*	parent;
	Student*	left;
	Student*	right;
};

// Data
int N = 0;
int Q = 0;
Student* tree = NULL;
Student* min = NULL;
Student* max = NULL;
Student students[MAX_STUDENTS] = { 0 };

void Add(Student* root, int index, int id) {
	Student* newStudent = &students[index];
	newStudent->id = id;

	Student* student = root;
	while (student) {
		if (id < student->id) {
			if (!(student->left)) {
				student->left = newStudent;
				newStudent->parent = student;
				break;
			}
			student = student->left;
		}
		else {
			if (!(student->right)) {
				student->right = newStudent;
				newStudent->parent = student;
				break;
			}
			student = student->right;
		}
	}
}

int main() {
	int i = 0;
	int j = 0;

	// Read N (the number of students)
	scanf("%d", &N);

	// Read X0
	tree = &students[0];
	scanf("%d", &(tree->id));
	min = tree;
	max = tree;

	// Read Xi (the students IDs)
	for (i = 1; i < N; i++) {
		int id = 0;
		scanf("%d", &id);
		if (id < min->id) {
			Add(min, i, id);
			min = &students[i];
		} else if (id > max->id) {
			Add(max, i, id);
			max = &students[i];
		} else {
			Add(tree, i, id);
		}
	}

	// Read Q (the number of deleted students IDs)
	scanf("%d", &Q);

	// Read Qi
	int number = 0;
	if (Q > 1) {
		for (i = 0; i < (Q - 1); i++) {
			scanf("%d", &number);
			number--;
			printf("%d ", students[number].parent->id);
		}
	}
	scanf("%d", &number);
	number--;
	printf("%d", students[number].parent->id);
	printf("\n");

	return 0;
}