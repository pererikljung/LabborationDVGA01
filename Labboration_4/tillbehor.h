#ifndef TILLBEHOR_H_
#define TILLBEHOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct person {
	char namn[50];
	int alder;
}person;

typedef struct fordon {
	char typ[10];
	char marke[15];
	char regnr[10];
	person agare;
}fordon;

int compareString(char [], char []);
void clrStdin();

void addVehicle(fordon *, int);
void removeVehicle(fordon *, int, int);
void sortVehicles(fordon *, int);
void vehicleInfo(fordon *, int, int);
void printVehicles(fordon *, int);

#endif
