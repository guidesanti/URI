#include <stdio.h>

/// Constrainsts
#define MAX_N	(100000)	// N -> (2 <= N <= 100000)
// Xi -> (1 <= Xi <= 1000000000)
// Q -> 1 <= Q <= 99999

// Data sturcture
typedef struct Student Student;

struct Student {
	int id;
	Student* parent;
	Student* left;
	Student* right;
};

// Data
int N = 0;
int Q = 0;
//int Qi[MAX_Q];
Student* studentsTree = NULL;
Student studentsList[MAX_N];
int index = 0;

void Add(int number, int id) {
	Student* newStudent = &studentsList[index++];
	newStudent->id = id;
	newStudent->parent = NULL;
	newStudent->left = NULL;
	newStudent->right = NULL;

	if (!studentsTree) {
		studentsTree = newStudent;
	} else {
		Student* student = studentsTree;
		while (1) {
			if (id < student->id) {
				if (student->left) {
					student = student->left;
				} else {
					newStudent->parent = student;
					student->left = newStudent;
					break;
				}
			} else {
				if (student->right) {
					student = student->right;
				}
				else {
					newStudent->parent = student;
					student->right = newStudent;
					break;
				}
			}
		}
	}
}

int main() {
	int i = 0;
	int j = 0;

	// Read N (the number of students)
	scanf("%d", &N);

	// Read Xi (the students IDs)
	for (i = 0; i < N; i++) {
		int id = 0;
		scanf("%d", &id);
		Add(i + 1, id);
	}

	// Read Q (the number of deleted students IDs)
	scanf("%d", &Q);

	// Read Qi
	for (i = 0; i < Q; i++) {
		int number = 0;
		scanf("%d", &number);
		number--;
		if (i < (Q - 1)) {
			printf("%d ", studentsList[number].parent->id);
		} else {
			printf("%d\n", studentsList[number].parent->id);
		}
	}

	return 0;
}