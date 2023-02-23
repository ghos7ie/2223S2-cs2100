#include <stdio.h>

void display(int);

int main() {
	int ageArray[] = { 2, 15, 4, 20 };
	display(ageArray[2]);
	printf("Size of the array is %d", sizeof(ageArray)/sizeof(ageArray[0]));
	return 0;
}

void display(int age) {
	printf("%d\n", age);
}
