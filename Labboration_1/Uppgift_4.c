#include <stdio.h>

int main(){
	int highsalary = 204000;
	float brutto;
	float netto;
	float high = 0.5;
	float low = 0.3;

	scanf("%f", &brutto);

	if(brutto <=highsalary){
		netto = brutto -(brutto*low);
	}else{
		netto = brutto - (highsalary * low + (brutto - highsalary)*high);
	}

	printf("%.1f", netto);

}
