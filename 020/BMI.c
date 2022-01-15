#include <stdio.h>

int main() {
	float weight;
	float height;

	printf("How much do you weigh?\n");
	scanf("%f", &weight);

	printf("How tall are you?\n");
	scanf("%f", &height);

	printf("Your BMI is: %.2f", weight / (height * height));

	return 0;
}