#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	for(int i = 1;i<11 ; ++i){
		printf("%d\n", rand() % 901);
	}
}


