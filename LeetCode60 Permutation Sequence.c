#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return n * factorial(n - 1);
}

char* getPermutation(int n, int k)
{
	int *permutation = (int*)malloc(sizeof(int) * n);
	char *result = (char*)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++)permutation[i] = i + 1;
	for (int i = 0; i < n; i++)
	{
		int fac = factorial(n - i - 1);
		int j = k > 1 ? (k - 1) / fac : 0;
		result[i] = permutation[j] + '0';
		k = k - j * fac;
	/*	memmove(permutation + j, permutation + j + 1, (n - j) * sizeof(int));*/
	}
	result[n] = '\0';
	free(permutation);
	return result;
}

int main()
{
	int n = 4, k = 9;
	char *result = getPermutation(n, k);
	printf("%s", result);
	free(result);
	return 0;
}

