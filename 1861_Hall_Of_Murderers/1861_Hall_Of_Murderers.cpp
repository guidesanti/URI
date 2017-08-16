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
	Murderer*	prev;
	Murderer*	next;
};

// Data
Murderer mPool[MAX_MURDERERS];
int mPoolIndex = 0;
Murderer* m1List = NULL;
Murderer* m2List = NULL;

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

	if (len1 == len2) {
		return 0;
	}
	if (len1 < len2) {
		return 1;
	}
	if (len1 > len2) {
		return 2;
	}
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
	char m1Name[MAX_NAME_LENGTH];
	char m2Name[MAX_NAME_LENGTH];

	while (scanf("%s %s", m1Name, m2Name) != EOF) {
		Murderer* m = m2List;
		int m1Flag = 1;
		int m2Flag = 1;

		while (m) {
			if (m1Flag) {
				int res = Compare(m1Name, m->name);
				if (res == 0) {
					m->numberOfMurders++;
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