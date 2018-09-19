#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) 
{
	if (nums[0] > target) return 0;
	if (nums[numsSize - 1] < target) return numsSize;
	for (int i = 0; i < numsSize; i++) if ((nums[i] == target) || (nums[i - 1] < target && nums[i] > target)) return i;
	return NULL;
}

int main()
{
	int nums[] = {1,3,5,6};
	int target = 5;
	int result = searchInsert(nums, sizeof(nums) / sizeof(nums[0]), target);
	printf("the result is %d", result);
	return 0;
}