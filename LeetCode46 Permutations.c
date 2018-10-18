#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void recursion(int **result, int *nums, int numsSize, int *returnSize, bool *used, int *tmp, int size)
{
	if (size == numsSize)
	{
		result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
		for (int i = 0; i < numsSize; i++) result[*returnSize][i] = tmp[i];
		size = 0;
		(*returnSize)++;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			tmp[size] = nums[i];
			recursion(result, nums, numsSize, returnSize, used, tmp, size + 1);
			used[i] = false;
		}
	}
}

int** permute(int* nums, int numsSize, int* returnSize) 
{
	if (numsSize == 0 || nums == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int **result = (int**)malloc(sizeof(int *) * ((int)pow(numsSize, numsSize)));
	bool *used = (bool*)malloc(sizeof(bool) * numsSize);
	int *tmp = (int*)malloc(sizeof(int) * numsSize);
	*returnSize = 0;
	memset(used, (bool)false, numsSize);
	recursion(result, nums, numsSize, returnSize, used, tmp, 0);
	free(used); free(tmp);
	return result;
}

int main()
{
	int nums[] = { 1,2,3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int **result = permute(nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < numsSize; j++) printf("%d", result[i][j]);
		printf("\n");
		free(result[i]);
	}
	free(result);
}