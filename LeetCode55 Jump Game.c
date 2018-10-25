#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) 
{
	int arrive = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (i > arrive || arrive >= numsSize - 1) break;
		arrive = arrive > i + nums[i] ? arrive : i + nums[i];
	}
	return arrive >= numsSize - 1;
}

int main()
{
	int nums[] = { 3,2,1,0,4 };
	bool result = canJump(nums, (int)(sizeof(nums) / sizeof(nums[0])));
	printf("The result is %d", result);
	return 0;
}