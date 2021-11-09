#include <stdio.h>


int main(){
	
	int store;
	int big;
	int small;

	for(int n = 0; n < 10; n++){
		scanf("%d", &store);
		if(n == 0){
			big = store;
			small = store;	
		}else if(big < store){
			big = store;
		}else if( small > store){
			small = store;
		}
	}
	printf("%d %d", big, small);

}
