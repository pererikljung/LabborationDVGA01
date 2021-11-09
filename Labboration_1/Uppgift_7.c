#include <stdio.h>

int main(){
	int input;
	int store = 0;
	while(1){
		scanf("%d", &input);
		if(input == 0){break;}
		store += input;
		printf("%d\n", store);
	}
}
