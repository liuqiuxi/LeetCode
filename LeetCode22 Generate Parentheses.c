#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char **result, int *returnSize, int l, int r, char *tmp, int index)
{
	if (l == 0 && r == 0)
	{
		tmp[index] = 0;
		result[*returnSize] = (char *)malloc(sizeof(char) * index);
		/*strcpy(result[*returnSize], tmp);*/
		strcpy_s(result[*returnSize], sizeof(char) * (index + 1), tmp);
		(*returnSize)++;
		return;
	}
	if (l > 0)
	{
		tmp[index] = '(';
		generate(result, returnSize, l - 1, r, tmp, index + 1);
	}
	if (r > 0 && l < r)
	{
		tmp[index] = ')';
		generate(result, returnSize, l, r - 1, tmp, index + 1);
	}
}

int factor(int n)
{
	if (n > 1)
	{
		return factor(n - 1) * n;
	}
	return 1;
}

char** generateParenthesis(int n, int* returnSize) {
	char **result = (char **)malloc(sizeof(char*) * factor(n));
	char *tmp = (char *)malloc(sizeof(char) * (n * 2 + 1));
	int l = n, r = n;
	*returnSize = 0;
	generate(result, returnSize, l, r, tmp, 0);
	return result;
}

int main()
{
	int returnSize;
	char **result = generateParenthesis(7, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%s\n", result[i]);
	}
	return 0;
}