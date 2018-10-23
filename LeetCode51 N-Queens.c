#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Queens
{
	char **queens[1000];
	int count;
}Queens;

bool isValid(int row, int *arrays)
{
	for (int i = 0; i < row; i++) if (arrays[row] == arrays[i] || abs(arrays[row] - arrays[i]) == row - i) return false;
	return true;
}

void updateBoard(int n, int *arrays, Queens *Q)
{
	char **matrix = (char**)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (char*)calloc(n + 1, sizeof(char));
		for (int j = 0; j < n; j++) matrix[i][j] = '.';
		matrix[i][arrays[i]] = 'Q';
	}
	*(Q->queens + Q->count) = matrix; (Q->count)++;
}

void nqueens(int row, int n, int *arrays, Queens *Q)
{
	if (row == n) updateBoard(n, arrays, Q);
	for (int i = 0; i < n; i++)
	{
		arrays[row] = i;
		if (isValid(row, arrays)) nqueens(row + 1, n, arrays, Q);
	}
}

char*** solveNQueens(int n, int* returnSize) 
{
	if (n < 1 || returnSize == NULL) return NULL;
	Queens *Q = (Queens*)calloc(1, sizeof(Queens));
	int *arrays = (int*)calloc(n + 1, sizeof(int));
	nqueens(0, n, arrays, Q);
	*returnSize = Q->count;
	free(arrays);
	return Q->queens;
}

int main()
{
	int n = 8;
	int returnSize;
	char ***result = solveNQueens(n, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%c ", result[i][row][col]);
			}
			printf("\n"); free(result[i][row]);
		}
		printf("\n");free(result[i]);
	}
	return 0;
}