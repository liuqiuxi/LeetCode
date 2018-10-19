#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) 
{
	for (int row = 0; row < matrixRowSize; row++)
	{
		for (int col = row + 1; col < matrixRowSize; col++)
		{
			int tmp = matrix[row][col];
			matrix[row][col] = matrix[col][row];
			matrix[col][row] = tmp;
		}
	}
	for (int row = 0; row < matrixRowSize; row++)
	{
		for (int col = 0; col < (*matrixColSizes) / 2; col++)
		{
			int tmp = matrix[row][col];
			matrix[row][col] = matrix[row][*matrixColSizes - col - 1];
			matrix[row][*matrixColSizes - col - 1] = tmp;
		}
	}
}

int main()
{
	int copy[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int matrixColSizes = 3;
	int **matrix = (int**)malloc(sizeof(int*) * matrixColSizes);
	for (int row = 0; row < matrixColSizes; row++)
	{
		matrix[row] = (int*)malloc(sizeof(int) * matrixColSizes);
		for (int col = 0; col < matrixColSizes; col++) matrix[row][col] = copy[row][col];
	}
	rotate(matrix, 3, &matrixColSizes);
	for (int row = 0; row < matrixColSizes; row++)
	{
		for (int col = 0; col < matrixColSizes; col++) printf("%d ", matrix[row][col]);
		printf("\n");
		free(matrix[row]);
	}
	free(matrix);
	return 0;
}