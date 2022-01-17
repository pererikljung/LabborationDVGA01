#ifndef TILLBEHOR_H_
#define TILLBEHOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void checkInputLength(char *, char *, int);
int checkNumber(char *);
int compareString(char [], char []);

void addVehicle(fordon *, int);
void removeVehicle(fordon *, int);
void sortVehicles(fordon *, int);
void vehicleInfo(fordon *, int);
void printVehicles(fordon *, int);

#endif
