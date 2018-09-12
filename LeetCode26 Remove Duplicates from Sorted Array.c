#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) return 0;
	int result = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != nums[result])
		{
			result++;
			nums[result] = nums[i];
		}
	}
	return ++result;
}

int main()
{
	int nums[] = { 1,1,2,2,3,5,9,9 };
	int numsSize = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
	for (int i = 0; i < numsSize; i++) printf("%d", nums[i]);
	return 0;
}
