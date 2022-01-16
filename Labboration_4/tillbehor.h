#ifndef TILLBEHOR_H_
#define TILLBEHOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char namn[100];
	int alder;
}person;

typedef struct fordon {
	char typ[9];
	char marke[15];
	char regnr[6];
	person agare;	
}fordon;

int compareString(char [], char []);

void addVehicle(fordon *, int);
void removeVehicle(fordon *, int, int);
void sortVehicles(fordon *, int);
void vehicleInfo(fordon *, int, int);
void printVehicles(fordon *, int);

#endif
