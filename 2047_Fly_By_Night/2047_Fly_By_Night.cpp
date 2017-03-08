#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constraints
#define MAX_CITIES				(101)
#define MAX_CITY_NAME_LENGTH	(21)

// Data types
typedef struct City City;
typedef struct Flight Flight;

struct City {
	char*	name;
	int		numberOfPassengers;
	int		numberOfSeats;
	int		numberOfFlightsOut;
};

struct Flight {
	int		numberOfSeats;
	City*	src;
	City*	dst;
	Flight* prev;
	Flight* next;
};

// Data
int numberOfOriginCities = 0;	// The number of origin cities
City cities[MAX_CITIES];		// A pool of cities
int numberOfFlights = 0;		// The number of flights
City* eventCity = NULL;			// A pointer to the event city
int viable = 0;					// A variable to sotre the result
int instance = 0;				// The number of the instance being processed
int i = 0;						// Variable to control loops
int numberOfCities = 0;			// An index to control the use of cities within the cities pool
Flight* flights = NULL;			// The list of flights
int remainingPassengers = 0;

// Functions

#define DEFAULT_WORD_LENGTH	(21)

char* readWord(void) {
	int wordLength = DEFAULT_WORD_LENGTH;
	char* word = (char*)malloc(wordLength * sizeof(char));
	int index = 0;
	char ch = 0;

	if (!word) {
		return NULL;
	}

	// Find the start of the word
	while (1) {
		ch = fgetc(stdin);
		if ((ch != ' ') && (ch != '\n') && (ch != EOF)) {
			word[index++] = ch;
			break;
		}
	}

	// Read the word
	while (1) {
		ch = fgetc(stdin);
		if ((ch == ' ') || (ch == '\n') || (ch == EOF)) {
			break;
		}

		if (index == wordLength) {
			char* newLine = (char*)realloc(word, 2 * wordLength);
			if (!newLine) {
				free(word);
				return NULL;
			}
			word = newLine;
			wordLength *= 2;
		}

		word[index++] = ch;
	}
	word[index] = '\0';

	return word;
}

void AddCity(char* name, int numberOfPassengers) {
	// Add the origin city (ordered by the lowest number of flights first)
	City* city = &cities[numberOfCities++];
	city->name = name;
	city->numberOfPassengers = numberOfPassengers;
	city->numberOfSeats = 0;
	city->numberOfFlightsOut = 0;
}

void AddEventCity(char* name) {
	City* city = &cities[numberOfCities++];
	city->name = name;
	city->numberOfPassengers = 0;
	city->numberOfSeats = 0;
	city->numberOfFlightsOut = 0;
	eventCity = city;
}

void AddFlight(char* srcCityName, char* dstCityName, int numberOfSeats) {
	// Search src and dst cities on the current used cities
	City* srcCity = NULL;
	City* dstCity = NULL;
	int i = 0;
	for (i = 0; i < numberOfCities; i++) {
		if (!srcCity) {
			if (strcmp(cities[i].name, srcCityName) == 0) {
				srcCity = &cities[i];
				if (dstCity) {
					break;
				}
			}
		}
		if (!dstCity) {
			if (strcmp(cities[i].name, dstCityName) == 0) {
				dstCity = &cities[i];
				if (srcCity) {
					break;
				}
			}
		}
	}
	if (!srcCity) {
		srcCity = &cities[numberOfCities++];
		srcCity->name = srcCityName;
		srcCity->numberOfPassengers = 0;
		srcCity->numberOfSeats = 0;
		srcCity->numberOfFlightsOut = 0;
	}
	srcCity->numberOfFlightsOut++;
	if (!dstCity) {
		dstCity = &cities[numberOfCities++];
		dstCity->name = dstCityName;
		dstCity->numberOfPassengers = 0;
		dstCity->numberOfSeats = 0;
		dstCity->numberOfFlightsOut = 0;
	}

	// Add the flight to the list
	Flight* newFlight = (Flight*)malloc(sizeof(Flight));
	newFlight->numberOfSeats = numberOfSeats;
	newFlight->src = srcCity;
	newFlight->dst = dstCity;
	newFlight->prev = NULL;
	newFlight->next = flights;

	if (flights) {
		flights->prev = newFlight;
	}
	flights = newFlight;
}

void RemoveFlight(Flight* flight) {
	flight->src->numberOfFlightsOut--;

	if (flight == flights) {
		flights = flight->next;
		if (flights) {
			flights->prev = NULL;
		}
	} else {
		if (flight->prev) {
			flight->prev->next = flight->next;
		}
		if (flight->next) {
			flight->next->prev = flight->prev;
		}
	}

	free(flight);
}

int main() {
	while (1) {
		instance++;

		// Reset variables
		remainingPassengers = 0;
		numberOfCities = 0;
		eventCity = NULL;
		flights = NULL;

		// Read the number of origin cities
		scanf("%d", &numberOfOriginCities);

		// Check the stop condition
		if (!numberOfOriginCities) {
			break;
		}

		// Read the source cities and number of passengers
		char* cityName = NULL;
		int numberOfPassengers = 0;
		for (i = 0; i < numberOfOriginCities; i++) {
			cityName = readWord();
			scanf("%d", &numberOfPassengers);
			AddCity(cityName, numberOfPassengers);
			remainingPassengers += numberOfPassengers;
		}

		// Read the number of flights in the instance and the event city name
		scanf("%d", &numberOfFlights);
		cityName = readWord();
		AddEventCity(cityName);

		// Read the flights
		char* cityName2 = NULL;
		int numberOfSeats = 0;
		for (i = 0; i < numberOfFlights; i++) {
			cityName = readWord();
			cityName2 = readWord();
			scanf("%d", &numberOfSeats);
			AddFlight(cityName, cityName2, numberOfSeats);
		}

		// Calculate the viability
		viable = 1;
		Flight* flight = flights;
		Flight* obsoleteFlight = NULL;
		while (flights) {
			if (flight->dst->numberOfFlightsOut == 0) {
				flight->src->numberOfSeats += flight->numberOfSeats;
				obsoleteFlight = flight;
			}
			flight = flight->next;
			if (obsoleteFlight) {
				RemoveFlight(obsoleteFlight);
				obsoleteFlight = NULL;
			}
			if (!flight) {
				flight = flights;
			}
		}
		for (i = 0; i < numberOfCities; i++) {
			if (cities[i].numberOfPassengers > cities[i].numberOfSeats) {
				viable = 0;
				break;
			}
		}

		// Clear remaining flights
		while (flights) {
			RemoveFlight(flights);
		}

		// Write the result
		printf("instancia %d\n", instance);
		if (viable) {
			printf("viavel\n\n");
		} else {
			printf("inviavel\n\n");
		}
	}
	printf("\n");

	return 0;
}