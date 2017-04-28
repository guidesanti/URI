#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constraints
#define MAX_MURDERERS	(100000)
#define MAX_NAME_LENGTH	(11)	// The maximum name length including the trailing '\0'

// Data structure
typedef struct Murderer Murderer;

struct Murderer {
	char		name[MAX_NAME_LENGTH];
	int			numberOfMurders;
	//Murderer*	prev;
	//Murderer*	next;
};

// Data
Murderer murderers[MAX_MURDERERS];
Murderer* first = NULL;
int count = 0;

// Functions
int Compare(char* name1, char* name2) {
	int len1 = strlen(name1);
	int len2 = strlen(name2);
	int len = ((len1 < len2) ? (len1) : (len2));
	int i = 0;

	for (i = 0; i < len; i++) {
		if (name1[i] < name2[i]) {
			return 1;
		}
		if (name1[i] > name2[i]) {
			return 2;
		}
	}

	if (len1 < len2) {
		return 1;
	}

	return 2;
}

void Add(char* name1, char* name2) {
	if (!first) {
		Murderer* murderer = &murderers[count++];
		strcpy(murderer->name, name1);
		murderer->numberOfMurders = 1;
		//murderer->prev = NULL;
		//murderer->next = NULL;
		first = murderer;

		Murderer* murdered = &murderers[count++];
		strcpy(murdered->name, name2);
		murdered->numberOfMurders = 0;
		//murdered->prev = NULL;
		//murdered->next = NULL;
	} else {
		// Search for the murderer

	}
}

int main() {
	char murdererName[MAX_NAME_LENGTH];
	char murderedName[MAX_NAME_LENGTH];

	while (scanf("%s %s", murdererName, murderedName) != EOF) {
		int m1 = 0;
		int m2 = 0;
		Murderer* prev = NULL;
		Murderer* murderer = murderers;
		while (murderer) {
			if (!m1) {
				if (strcmp(murderer->name, murdererName) == 0) {
					murderer->numberOfMurders++;
					m1 = 1;
				}
			}
			if (!m2) {
				if (strcmp(murderer->name, murderedName) == 0) {
					murderer->murdered = 1;
					m2 = 1;
				}
			}
			if (m1 & m2) {
				break;
			}
			prev = murderer;
			murderer = murderer->next;
		}
		if (!m1) {
			Murderer* newMurderer = (Murderer*)malloc(sizeof(Murderer));
			strcpy(newMurderer->name, murdererName);
			newMurderer->murdered = 0;
			newMurderer->numberOfMurders = 1;
			newMurderer->next = NULL;

			// Insert ordered in the list
			if (!murderers) {
				murderers = newMurderer;
			} else if (Compare(murdererName, murderers->name) == 1) {
				newMurderer->next = murderers;
				murderers = newMurderer;
			} else {
				murderer = murderers;
				while (murderer->next) {
					if (Compare(murdererName, murderer->next->name) == 1) {
						newMurderer->next = murderer->next;
						murderer->next = newMurderer;
						break;
					}
					murderer = murderer->next;
				}
				if (!murderer->next) {
					murderer->next = newMurderer;
				}
			}
		}
		if (!m2) {
			Murderer* newMurderer = (Murderer*)malloc(sizeof(Murderer));
			strcpy(newMurderer->name, murderedName);
			newMurderer->murdered = 1;
			newMurderer->numberOfMurders = 0;
			newMurderer->next = NULL;

			// Insert ordered in the list
			if (!murderers) {
				murderers = newMurderer;
			}
			else if (Compare(murdererName, murderers->name) == 1) {
				newMurderer->next = murderers;
				murderers = newMurderer;
			}
			else {
				murderer = murderers;
				while (murderer->next) {
					if (Compare(murdererName, murderer->next->name) == 1) {
						newMurderer->next = murderer->next;
						murderer->next = newMurderer;
						break;
					}
					murderer = murderer->next;
				}
				if (!murderer->next) {
					murderer->next = newMurderer;
				}
			}
		}
	}

	// Print the result
	printf("HALL OF MURDERERS\n");
	Murderer* murderer = murderers;
	while (murderer) {
		if (!murderer->murdered) {
			printf("%s %d\n", murderer->name, murderer->numberOfMurders);
			murderer = murderer->next;
		}
	}

	return 0;
}