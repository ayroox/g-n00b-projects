#include <stdio.h>

int main() {
	int age; 

	printf("How many years old are you?\n");
	scanf("%d", &age);
	printf("That is approximately %d seconds!\n", (age * 365 * 24 * 60 * 60));

	return 0;
}