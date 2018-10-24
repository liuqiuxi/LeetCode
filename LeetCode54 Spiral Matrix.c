#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
	if (matrixColSize == 0 || matrixRowSize == 0 || matrix == NULL) return NULL;
	int *result = (int*)malloc(sizeof(int) * (matrixRowSize * matrixColSize + 1));
	int left = 0, right = matrixColSize - 1, top = 0, bottom = matrixRowSize - 1, count = 0;
	while ((left <= right) && (top <= bottom))
	{
		for (int i = left; i <= right; i++)
		{
			result[count] = matrix[top][i];
			count++;
		}
		top++;
		if (top > bottom) break;
		for (int i = top; i <= bottom; i++)
		{
			result[count] = matrix[i][right];
			count++;
		}
		right--;
		if (left > right) break;
		for (int i = right; i >= left; i--)
		{
			result[count] = matrix[bottom][i];
			count++;
		}
		bottom--;
		if (top > bottom) break;
		for (int i = bottom; i >= top; i--)
		{
			result[count] = matrix[i][left];
			count++;
		}
		left++;
		if (left > right) break;
	}
	return result;
}

int main()
{
	int number[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int **matrix = (int**)malloc(sizeof(int*) * 3);
	for (int row = 0; row < 3; row++)
	{
		matrix[row] = (int*)malloc(sizeof(int) * 4);
		for (int col = 0; col < 4; col++) matrix[row][col] = number[row][col];
	}
	int *result = spiralOrder(matrix, 3, 4);
	for (int i = 0; i < 3 * 4; i++) printf("%d", result[i]);
	free(result);
	for (int row = 0; row < 3; row++) free(matrix[row]);
	free(matrix);
	return 0;
}