#include <stdio.h>

int main() {
	int nums[] = {4, 1, 4, 86, 13, 665, 22, 44, 22, 1, 55, 33, 95, 163, 432, 112, 3};
	int largest = 0;

	for (int i = 0; i < (sizeof(nums) / sizeof(nums[0])); i++) {
		if (largest < nums[i]) {
			largest = nums[i];
		}
	}

	printf("%d\n", largest);
	return 0;
}