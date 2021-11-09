#include <stdio.h>


int main(){
	int n = 1;
	int sum = 1;
	int choice;

	scanf("%d", &choice);

	while(choice >= sum){
		n += 1;
		sum += n;
	}
	printf("%d %d", sum, n);

}
