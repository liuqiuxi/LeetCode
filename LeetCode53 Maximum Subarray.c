#include <stdio.h>

#define MIN -2147483647 - 1

int maxSubArray(int* nums, int numsSize) 
{
	int result = MIN, curSum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		curSum = curSum + nums[i] > nums[i] ? curSum + nums[i] : nums[i];
		result = result > curSum ? result : curSum;
	}
	return result;
}

int main()
{
	int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	int result = maxSubArray(nums, sizeof(nums) / sizeof(nums[0]));
	printf("The result is %d", result);
	return 0;
}