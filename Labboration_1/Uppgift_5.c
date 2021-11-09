#include <stdio.h>

int main(){
	char read;
	scanf("%c", &read);

	if(read >= 97 && read <= 122){read -= 32;}

	switch(read){
		case 'S':
			printf("hej");
			break;
		case 'E':
			printf("hello");
			break;
		case 'T':
		       	printf("hallo");
	     		break;		
	}
	return 0;
}
