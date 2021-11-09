#include <stdio.h>

int main(){
	int a, b, c, d, e;
	char o[4] = "odd", ev[5] = "even";
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);

	printf("%s\n", a % 2 == 0 ? ev:o);
	printf("%s\n", b % 2 == 0 ? ev:o);
	printf("%s\n", c % 2 == 0 ? ev:o);
	printf("%s\n", d % 2 == 0 ? ev:o);
	printf("%s\n", e % 2 == 0 ? ev:o);
}
