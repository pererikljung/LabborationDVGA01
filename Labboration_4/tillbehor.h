#ifndef TILLBEHOR_H_
#define TILLBEHOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char namn[15];
	int alder;
}person;

typedef struct fordon {
	char typ[9];
	char marke[9];
	char regnr[6];
	person agare;	
}fordon;

int compareString(char [], char []);

void addVehicle(fordon *, int);
void removeVehicle(fordon *, int, int);
void sortVehicles(fordon *, int);

void printVehicles(fordon *, int);

#endif
