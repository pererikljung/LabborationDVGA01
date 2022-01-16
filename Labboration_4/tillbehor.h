#ifndef TILLBEHOR_H_
#define TILLBEHOR_H_

#include <stdio.h>
#include <string.h>

typedef struct person {
	//int agarnummer;
	char namn[15];
	int alder;

}person;

typedef struct fordon {
	char typ[9];
	char marke[9];
	char regnr[6];
	person agare;	
}fordon;

void addVehicle(fordon *, int);

void printVehicles(fordon *, int);

#endif