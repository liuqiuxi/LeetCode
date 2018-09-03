#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	if (numsSize < 4)
	{
		return NULL;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	int **result = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);
	*returnSize = 0;
	for (int i = 0; i < numsSize - 3; i++)
	{
		if (i > 0 &&nums[i] == nums[i - 1])
		{
			continue;
		}
		for (int j = i + 1; j < numsSize - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			int begin = j + 1;
			int end = numsSize - 1;
			while (begin < end)
			{
				int sum = nums[i] + nums[j] + nums[begin] + nums[end];
				if (sum == target){
					int *temp = (int*)malloc(sizeof(int) * 4);
					temp[0] = nums[i];
					temp[1] = nums[j];
					temp[2] = nums[begin];
					temp[3] = nums[end];
					result[*returnSize] = temp;
					(*returnSize)++;
					begin++;
					end--;
					while (begin < end && nums[begin] == nums[begin - 1])begin++;
					while (begin < end && nums[end] == nums[end + 1])end--;
				}
				else if (sum > target){
					end--;
					while (begin < end && nums[end] == nums[end + 1])end--;
				}
				else {
					begin++;
					while (begin < end && nums[begin] == nums[begin - 1])begin++;
				}
			}
		}
	}
	return result;
}


int main(void)
{
	int i, count;
	//int nums[] = { 1, 0, -1, 0, -2, 2 };
	int nums[] = { 0,0,0,0 };
	int **result = fourSum(nums, sizeof(nums) / sizeof(*nums), 0, &count);
	for (i = 0; i < count; i++) {
		printf("%d %d %d %d\n", result[i][0], result[i][1], result[i][2], result[i][3]);
	}
	return 0;
}