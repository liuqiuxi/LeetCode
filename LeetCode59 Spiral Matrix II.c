#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n) 
{
	int **result = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) result[i] = (int*)malloc(sizeof(int) * n);
	int left = 0, right = n - 1, top = 0, bottom = n - 1, count = 1;
	while (count <= n * n)
	{
		for (int i = left; i <= right; i++)
		{
			result[top][i] = count;
			count++;
		}
		top++; if (top > bottom)break;
		for (int i = top; i <= bottom; i++)
		{
			result[i][right] = count;
			count++;
		}
		right--; if (left > right) break;
		for (int i = right; i >= left; i--)
		{
			result[bottom][i] = count;
			count++;
		}
		bottom--; if (top > bottom)break;
		for (int i = bottom; i >= top; i--)
		{
			result[i][left] = count;
			count++;
		}
		left++; if (left > right) break;
	}
	return result;
}

int main()
{
	int n = 5;
	int **result = generateMatrix(n);
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			printf("%10d", result[row][col]);
		}
		printf("\n");
		free(result[row]);
	}
	free(result);
	return 0;
}