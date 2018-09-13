#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int result = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[result] = nums[i];
			result++;
		}
	}
	return result;
}

int main()
{
	int nums[] = { 3,2,2,3 };
	int len = removeElement(nums, sizeof(nums) / sizeof(nums[0]), 2);
	for (int i = 0; i < len; i++) printf("%d", nums[i]);
	return 0;
}