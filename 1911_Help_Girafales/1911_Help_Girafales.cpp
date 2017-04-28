#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constraints
#define MIN_NUMBER_OF_STUDENTS	1
#define MAX_NUMBER_OF_STUDENTS	50
#define MIN_NUMBER_OF_ATENDEES	0
#define MAX_NUMBER_OF_ATENDEES	50
#define MAX_NAME_LENGTH			20
#define MAX_SIGNATURE_LENGTH	20

// Data structures
typedef struct Student Student;

struct Student {
	char name[MAX_NAME_LENGTH + 1];
	char signature[MAX_SIGNATURE_LENGTH + 1];
};

// Data
int numberOfStudents = 0;					// The number of students in the class
int numberOfAttendees = 0;					// The number of students attending the class
Student studentsTree[MAX_NUMBER_OF_STUDENTS];	// The students list
int result = 0;								// The number of false signatures
int i = 0;									// Loop control
int j = 0;									// Loop control
int k = 0;									// Loop control
int count = 0;								// Count the number of differences between two signatures

// Functions
int main() {
	while (1) {
		// Read the number of students
		scanf("%d", &numberOfStudents);

		// Check the stop condition
		if (!numberOfStudents) {
			break;
		}

		// Reset
		result = 0;
		memset(studentsTree, 0, sizeof(studentsTree));

		// Read the students names and signatures
		for (i = 0; i < numberOfStudents; i++) {
			scanf("%s %s", studentsTree[i].name, studentsTree[i].signature);
		}

		// Read the number of attendees
		scanf("%d", &numberOfAttendees);

		// Read the studants names and signatures of the day
		char name[MAX_NAME_LENGTH + 1];
		char signature[MAX_SIGNATURE_LENGTH + 1];
		memset(signature, 0, sizeof(signature));
		for (i = 0; i < numberOfAttendees; i++) {
			scanf("%s %s", name, signature);

			// Check the name and signature
			for (j = 0; j < numberOfStudents; j++) {
				if (strcmp(studentsTree[j].name, name) == 0) {
					count = 0;
					for (k = 0; k < MAX_SIGNATURE_LENGTH; k++) {
						if (studentsTree[j].signature[k] != signature[k]) {
							count++;
							if (count > 1) {
								result++;
								break;
							}
						}
					}
					break;
				}
			}
		}

		// Print the result
		printf("%d\n", result);
	}

	return 0;
}