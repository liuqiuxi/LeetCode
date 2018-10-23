#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool isValid(int row, int *arrays)
{
	for (int i = 0; i < row; i++) if (arrays[row] == arrays[i] || abs(arrays[row] - arrays[i]) == row - i) return false;
	return true;
}

void nqueens(int row, int n, int *arrays, int *returnSize)
{
	if (row == n) (*returnSize)++;
	for (int i = 0; i < n; i++)
	{
		arrays[row] = i;
		if (isValid(row, arrays)) nqueens(row + 1, n, arrays, returnSize);
	}
}

int totalNQueens(int n)
{
	if (n < 1 ) return 0;
	int *arrays = (int*)calloc(n + 1, sizeof(int));
	int returnSize = 0;
	nqueens(0, n, arrays, &returnSize);
	free(arrays);
	return returnSize;
}

int main()
{
	int n = 4;
	int result = totalNQueens(n);
	printf("The result is %d", result);
	return 0;
}