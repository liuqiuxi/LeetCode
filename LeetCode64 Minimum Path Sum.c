#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
	int **result = (int**)malloc(sizeof(int*) * gridRowSize);
	for (int row = 0; row < gridRowSize; row++) result[row] = (int*)malloc(sizeof(int) * gridColSize);
	result[0][0] = grid[0][0];
	for (int row = 1; row < gridRowSize; row++) result[row][0] = result[row - 1][0] + grid[row][0];
	for (int col = 1; col < gridColSize; col++) result[0][col] = result[0][col - 1] + grid[0][col];
	for (int row = 1; row < gridRowSize; row++) for (int col = 1; col < gridColSize; col++) result[row][col] = grid[row][col] + (result[row - 1][col] < result[row][col - 1] ? result[row - 1][col] : result[row][col - 1]);
	int ret = result[gridRowSize - 1][gridColSize - 1];
	for (int row = 0; row < gridRowSize; row++) free(result[row]);
	free(result);
	return ret;
}

int main()
{
	int copy[3][3] = { {1,3,1}, {1,5,1}, {4,2,1} };
	int **grid = (int**)malloc(sizeof(int*) * 3);
	for (int row = 0; row < 3; row++) grid[row] = (int*)malloc(sizeof(int) * 3);
	for (int row = 0; row < 3; row++) for (int col = 0; col < 3; col++) grid[row][col] = copy[row][col];
	int result = minPathSum(grid, 3, 3);
	for (int row = 0; row < 3; row++) free(grid[row]);
	free(grid);
	printf("The result is %d", result);
	return 0;
}

