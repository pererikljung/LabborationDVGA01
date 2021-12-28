#include <stdio.h>

typedef struct person {
	int agarnummer;
	char namn[15];
	int alder;

}person;

typedef struct fordon {
	char typ[9];
	char marke[9];
	char regnr[6];
	person agare;	
}fordon;

typedef struct vektor {
	int written;
	fordon vFordon;
	size_t limit;
	size_t current;
}vektor;


