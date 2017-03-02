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
	int		numberOfFlightsIn;
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
	city->numberOfFlightsIn = 0;
	city->numberOfFlightsOut = 0;
}

void AddEventCity(char* name) {
	City* city = &cities[numberOfCities++];
	city->name = name;
	city->numberOfPassengers = 0;
	city->numberOfSeats = 0;
	city->numberOfFlightsIn = 0;
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
		srcCity->numberOfFlightsIn = 0;
		srcCity->numberOfFlightsOut = 0;
	}
	srcCity->numberOfSeats += numberOfSeats;
	srcCity->numberOfFlightsOut++;
	if (!dstCity) {
		dstCity = &cities[numberOfCities++];
		dstCity->name = dstCityName;
		dstCity->numberOfPassengers = 0;
		dstCity->numberOfFlightsIn = 0;
		dstCity->numberOfFlightsOut = 0;
	}
	dstCity->numberOfFlightsIn++;

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
	flight->dst->numberOfFlightsIn--;

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

		while (1) {
			int count = 0;
			Flight* flight = flights;
			Flight* obsoleteFlight = NULL;
			while (flight) {
				if ((flight->dst != eventCity) && (flight->dst->numberOfFlightsOut == 0)) {
					obsoleteFlight = flight;
					count++;
				}
				flight = flight->next;
				if (obsoleteFlight) {
					RemoveFlight(obsoleteFlight);
					obsoleteFlight = NULL;
				}
			}
			if (!count) {
				break;
			}
		}

		// Calculate the viability
		int stop = 0;
		viable = 0;
		while (1) {
			int count = 0;
			Flight* flight = flights;
			while (flight) {
				Flight* obsoleteFlight = NULL;
				if ((flight->src->numberOfPassengers == 0) && (flight->src->numberOfFlightsIn == 0)) {
					obsoleteFlight = flight;
				} else if ((flight->src->numberOfPassengers > 0) && (flight->src->numberOfFlightsIn == 0)) {
					if ((flight->src->numberOfFlightsOut == 1) && (flight->src->numberOfFlightsIn == 0)) {
						if (flight->src->numberOfPassengers <= flight->numberOfSeats) {
							flight->dst->numberOfPassengers += flight->src->numberOfPassengers;
							flight->dst->numberOfSeats -= flight->src->numberOfPassengers;
							flight->src->numberOfPassengers = 0;
							obsoleteFlight = flight;
						} else {
							stop = 1;
							break;
						}
						count++;
					} else if (flight->dst->numberOfFlightsIn == 1) {
						int nPassengers = 0;
						if (flight->numberOfSeats <= flight->dst->numberOfSeats) {
							nPassengers = flight->numberOfSeats;
						} else {
							nPassengers = flight->dst->numberOfSeats;
						}
						flight->dst->numberOfPassengers += nPassengers;
						flight->dst->numberOfSeats -= nPassengers;
						flight->src->numberOfPassengers -= nPassengers;
						obsoleteFlight = flight;
						count++;
					}
				}
				flight = flight->next;
				if (obsoleteFlight) {
					RemoveFlight(obsoleteFlight);
				}
			}
			if (eventCity->numberOfPassengers == remainingPassengers) {
				viable = 1;
				break;
			}
			if (stop) {
				break;
			}
			if (!count) {
				Flight* currFlight = flights;
				flight = flights;
				currFlight = currFlight->next;
				while (currFlight) {
					if ((currFlight->src->numberOfPassengers > 0) && (currFlight->dst->numberOfFlightsIn < flight->dst->numberOfFlightsIn)) {
						flight = currFlight;
					}
					currFlight = currFlight->next;
				}
				int nPassengers = 0;
				if (flight->numberOfSeats <= flight->dst->numberOfSeats) {
					nPassengers = flight->numberOfSeats;
				}
				else {
					nPassengers = flight->dst->numberOfSeats;
				}
				flight->dst->numberOfPassengers += nPassengers;
				flight->dst->numberOfSeats -= nPassengers;
				flight->src->numberOfPassengers -= nPassengers;
				RemoveFlight(flight);
			}
			if (eventCity->numberOfPassengers == remainingPassengers) {
				viable = 1;
				break;
			}
			if (stop) {
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