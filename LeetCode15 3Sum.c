#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void twoSum(int *nums, int low, int high, int target, int **result, int *count)
{
	while (low < high)
	{
		int diff = target - nums[low];
		if (diff > nums[high]){
			while(++low < high && nums[low] == nums[low - 1]){}
		}else if (diff < nums[high]){
			while(--high > low && nums[high] == nums[high + 1]){}

		}else {
			result[*count] = malloc(sizeof(int) * 3);
			result[*count][0] = -target;
			result[*count][1] = nums[low];
			result[*count][2] = nums[high];
			(*count)++;
			while (++low < high && nums[low] == nums[low - 1]) {}
			while (--high > low && nums[high] == nums[high + 1]) {}
		}
	}
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
	if (numsSize < 3)
	{
		return NULL;
	}
	qsort(nums, numsSize, sizeof(*nums), cmp);
	*returnSize = 0;
	int **result = malloc(sizeof(int *) * (numsSize * numsSize * numsSize));
	for (int i = 0; i < numsSize; i++)
	{
		if (i == 0 || i > 0 && nums[i] != nums[i - 1])
		{
			twoSum(nums, i + 1, numsSize - 1, -nums[i], result, returnSize);
		}
	}
	return result;
}

int main(void)
{
	int count;
	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int **triplets = threeSum(nums, sizeof(nums) / sizeof(*nums), &count);
	for (int i = 0; i < count; i++) {
		printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
	}

	return 0;
}