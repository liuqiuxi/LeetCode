#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) 
{
	int **result = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) result[i] = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < m; i++) result[i][0] = 1;
	for (int i = 0; i < n; i++) result[0][i] = 1;
	for (int i = 1; i < m; i++) for (int j = 1; j < n; j++)result[i][j] = result[i - 1][j] + result[i][j - 1];
	int ret = result[m - 1][n - 1];
	for (int i = 0; i < m; i++)free(result[i]);
	free(result);
	return ret;
}

int main()
{
	int m = 7;
	int n = 3;
	int result = uniquePaths(m, n);
	printf("The result is %d", result);
	return 0;
}