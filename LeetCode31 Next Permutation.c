#include <stdio.h>
#include <stdlib.h>

//没看懂题目的意思，答案是抄过来的
void nextPermutation(int* nums, int numsSize) {

	int i = numsSize - 1;
	int j, tmp;
	while (i > 0 && nums[i] <= nums[i - 1]) i--;
	if (i != 0)
	{
		j = numsSize - 1;
		while (j >= i && nums[j] <= nums[i - 1]) j--;
		tmp = nums[j];
		nums[j] = nums[i - 1];
		nums[i - 1] = tmp;
	}
	j = numsSize - 1;
	while (i < j)
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
		i++;j--;
	}
}

int main()
{
	int nums[] = { 3,2,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	nextPermutation(nums, numsSize);
	for (int i = 0; i < numsSize; i++) printf("%d", nums[i]);
	return 0;
}