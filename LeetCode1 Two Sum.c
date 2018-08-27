#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target)
{
	int * array = (int *)malloc(sizeof(nums[0]) * 2);
	for (int i = 0;i<numsSize - 1;i++) {
		for (int j = 0;j<numsSize;j++) {
			if (target == nums[i] + nums[j] && i != j) {
				
				array[0] = i;
				array[1] = j;
				return array;
			}
		}
	}

	return NULL;
}