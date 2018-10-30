#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) 
{
	if (obstacleGrid[0][0] == 1 || obstacleGrid == NULL) return 0;
	int **result = (int**)malloc(sizeof(int *) * obstacleGridRowSize);
	for (int i = 0; i < obstacleGridRowSize; i++)result[i] = (int*)calloc(obstacleGridColSize, sizeof(int));
	result[0][0] = 1;
	for (int i = 1; i < obstacleGridRowSize; i++) if (result[i - 1][0] != 0 && obstacleGrid[i][0] != 1) result[i][0] = 1;
	for (int i = 1; i < obstacleGridColSize; i++) if (result[0][i - 1] != 0 && obstacleGrid[0][i] != 1) result[0][i] = 1;
	for (int row = 1; row < obstacleGridRowSize; row++) for (int col = 1; col < obstacleGridColSize; col++) if (obstacleGrid[row][col] != 1) result[row][col] = result[row - 1][col] + result[row][col - 1];
	int ret = result[obstacleGridRowSize - 1][obstacleGridColSize - 1];
	for (int i = 0; i < obstacleGridRowSize; i++)free(result[i]);
	free(result);
	return ret;
}

int main()
{
	int copy[3][3] = { {0,0,0}, {0,1,0}, {0,0,0} };
	int **obstacleGrid = (int**)malloc(sizeof(int*) * 3);
	for (int row = 0; row < 3; row++) obstacleGrid[row] = (int*)malloc(sizeof(int) * 3);
	for (int row = 0; row < 3; row++) for (int col = 0; col < 3; col++) obstacleGrid[row][col] = copy[row][col];
	int result = uniquePathsWithObstacles(obstacleGrid, 3, 3);
	for (int row = 0; row < 3; row++) free(obstacleGrid[row]);
	free(obstacleGrid);
	printf("The result is %d", result);
	return 0;
}