#include<stdlib.h>
#include<stdio.h>
int mycompare(const void *a, const void *b)
{
	int *pa = (int *)a;
	int *pb = (int *)b;
	return (*pb) - (*pa);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	qsort(g, gSize, sizeof(g[0]), mycompare);
	qsort(s, sSize, sizeof(s[0]), mycompare);
	int j = 0;
	int count = 0;
	for (int i = 0; i < gSize; i++)
	{
		if (g[i] <= s[j] && j < sSize)
		{
			j++;
			count++;
		}
	}
	return count;
}

