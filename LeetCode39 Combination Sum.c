#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void combinationSumDFS(int* candidates, int candidatesSize, int target, int* columnSizes, int* returnSize, int** result, int*stack, int stacklen, int start)
{
	if (target == 0)
	{
		result[*returnSize] = (int*)malloc(stacklen * sizeof(int));
		//memcpy(result[*returnSize], stack, stacklen * sizeof(int));
		memcpy_s(result[*returnSize], sizeof(int) * stacklen, stack, sizeof(int) * stacklen);
		columnSizes[*returnSize] = stacklen;
		(*returnSize)++;
		return;
	}
	for (int i = start; i < candidatesSize; i++)
	{
		if (target < candidates[i]) break;
		if (candidates[i] == candidates[i - 1]) continue;
		stack[stacklen] = candidates[i];
		combinationSumDFS(candidates, candidatesSize, target - candidates[i], columnSizes, returnSize, result, stack, stacklen + 1, i);
	}
}


int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	int tmp = 1000;
	int *stack = (int*)malloc(tmp * sizeof(int));
	int **result = (int**)malloc(tmp * sizeof(int*));
	*columnSizes = (int*)malloc(tmp * sizeof(int));
	*returnSize = 0;
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	combinationSumDFS(candidates, candidatesSize, target, *columnSizes, returnSize, result, stack, 0, 0);
	free(stack);
	return result;
}

int main()
{
	int candidates[] = { 8,10,6,3,4,12,11,5,9 };
	int target = 28;
	int returnSize;
	int *columnSizes;
	int **result = combinationSum(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < columnSizes[i]; j++)
		{
			printf("%d", result[i][j]);
		}
		printf("\n");
		free(result[i]);
	}
	free(columnSizes);free(result);
	return 0;
}