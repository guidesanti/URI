#include <stdio.h>

// Constraints
#define MAX_NUMBER_OF_TEAMS	(100)	// MAximum number of teams

// Data structures
typedef struct Team Team;

struct Team {
	int		number;
	int		pointsScored;
	int		pointsReceived;
	int		points;
	double	averageBasket;
	Team*	next;
};

// Data
int numberOfTeams = 0;				// The number of teams
int numberOfMatches = 0;			// The number of matches
int instanceNumber = 0;				// The instance number
Team teams[MAX_NUMBER_OF_TEAMS];	// The teams of the league
Team* rank = NULL;					// The rank of the teams
int i = 0;							// Loop control

// Functions
int Compare(Team* t1, Team* t2) {
	if (t1->points > t2->points) {
		return 1;
	} else if (t1->points < t2->points) {
		return 2;
	} else {
		if (t1->averageBasket > t2->averageBasket) {
			return 1;
		} else if (t1->averageBasket < t2->averageBasket) {
			return 2;
		} else {
			if (t1->pointsScored > t2->pointsScored) {
				return 1;
			} else if (t1->pointsScored < t2->pointsScored) {
				return 2;
			} else{
				if (t1->number < t2->number) {
					return 1;
				}
				else {
					return 2;
				}
			}
		}
	}
}

int main() {
	while (1) {
		// Read the number of teams
		scanf("%d", &numberOfTeams);

		// Check stop condition
		if (!numberOfTeams) {
			break;
		}

		// Reset
		for (i = 0; i < numberOfTeams; i++) {
			teams[i].number = (i + 1);
			teams[i].pointsScored = 0;
			teams[i].pointsReceived = 0;
			teams[i].points = 0;
			teams[i].averageBasket = 0.0;
			teams[i].next = NULL;
		}

		// Read the match results
		numberOfMatches = ((numberOfTeams * (numberOfTeams - 1)) / 2);
		for (i = 0; i < numberOfMatches; i++) {
			int x;
			int y;
			int z;
			int w;
			scanf("%d %d %d %d", &x, &y, &z, &w);
			x--;
			z--;
			teams[x].pointsScored += y;
			teams[x].pointsReceived += w;
			teams[z].pointsScored += w;
			teams[z].pointsReceived += y;
			if (y > w) {
				teams[x].points += 2;
				teams[z].points += 1;
			} else if (y < w) {
				teams[x].points += 1;
				teams[z].points += 2;
			} else {
				// It shall not reach here
			}
		}

		// Calculate the average basket for each team
		for (i = 0; i < numberOfTeams; i++) {
			teams[i].averageBasket = (double)(teams[i].pointsScored);
			if (teams[i].pointsReceived > 0) {
				teams[i].averageBasket /= (double)(teams[i].pointsReceived);
			}
		}

		// Rank the teams
		rank = &teams[0];
		for (i = 1; i < numberOfTeams; i++) {
			if (Compare(&teams[i], rank) == 1) {
				teams[i].next = rank;
				rank = &teams[i];
			} else {
				Team* team = rank;
				while (team->next) {
					if (Compare(&teams[i], team->next) == 1) {
						teams[i].next = team->next;
						team->next = &teams[i];
						break;
					}
					team = team->next;
				}
				if (!team->next) {
					team->next = &teams[i];
				}
			}
		}

		// Print the result
		if (instanceNumber) {
			printf("\n");
		}
		printf("Instancia %d\n", ++instanceNumber);
		while (rank) {
			if (rank->next) {
				printf("%d ", rank->number);
			} else {
				printf("%d\n", rank->number);
			}
			rank = rank->next;
		}
	}

	return 0;
}