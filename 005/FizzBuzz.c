#include <stdio.h>

int main() {
	for (int i = 1; i < 101; i++) {
		printf("Num %d: ", i);

		if (i % 3 == 0) {
			printf("Fizz");
		}

		if (i % 5 == 0) {
			printf("Buzz");
		}

		printf("\n");
	}
}