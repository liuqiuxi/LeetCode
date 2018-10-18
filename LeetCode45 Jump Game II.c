#include <stdio.h>

int jump(int* nums, int numsSize)
{
	int result = 0, last = 0, cur = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (i > last)
		{
			last = cur;
			result++;
		}
		cur = cur > i + nums[i] ? cur : i + nums[i];
	}
	return result;
}

int main()
{
	int num[] = { 2,3,1,1,4 };
	int numsSize = sizeof(num) / sizeof(num[0]);
	int result = jump(num, numsSize);
	printf("The result is %d", result);
	return 0;
}