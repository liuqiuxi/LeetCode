#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) 
{
	if (numsSize < 1) return 1;
	for (int i = 0; i < numsSize; i++)
	{
		while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])
		{
			int tmp = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = tmp;
		}
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != i + 1) return i + 1;
	}
	return numsSize + 1;
}

int main()
{
	int nums[] = { 3,4,-1,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int result = firstMissingPositive(nums, numsSize);
	printf("The result is %d", result);
	return 0;
}