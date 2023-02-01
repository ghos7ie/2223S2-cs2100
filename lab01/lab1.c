#include <stdio.h>

int main(void){
	int a = 100;
	int b = 10;
	int c = a+b;
	int d = a-b;
	// Change a/d to b/a, since result is fractional, will be truncated
	int e = b/a; 
	int f = a*b;
	int i;
	char *day[7] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	printf("Arithmetic operations:\n");
	printf("a+b = %d\n", c);
	printf("a-b = %d\n", d);
	printf("b/a = %d\n", e);
	printf("a*b = %d\n\n", f);

	printf("Days of the week:\n");
	for (i=0; i<8; i++) {
		printf("Day[%d] = %s\n", i, day[i]);
	}

	return 0;
}
