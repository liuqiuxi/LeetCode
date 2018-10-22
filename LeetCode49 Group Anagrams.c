#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct HashMap
{
	char *word;
	int num;
	int indexes[10];
}HashMap;

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int BKDRhash(char *s, size_t size)
{
	int seed = 31;
	unsigned long hash = 0;
	while (*s != '\0') hash = hash * seed + *s++;
	return hash % size;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) 
{
	
	HashMap *map = calloc(strsSize, sizeof(HashMap));
	*returnSize = 0;
	char **words = (char**)malloc(sizeof(char*) * strsSize);
	int hashValue;
	for (int i = 0; i < strsSize; i++)
	{
		int len = strlen(strs[i]);
		words[i] = (char*)malloc(sizeof(char) * (len + 1));
		/*strcpy(words[i], strs[i]);*/
		strcpy_s(words[i], len + 1, strs[i]);
		qsort(words[i], len, sizeof(char), cmp);
		int hash = BKDRhash(words[i], strsSize);
		for(hashValue = hash; map[hashValue].num > 0 && strcmp(map[hashValue].word, words[i]); hashValue = ++hashValue % strsSize){}
		if (map[hashValue].num == 0)
		{
			map[hashValue].word = words[i];
			(*returnSize)++;
		}
		map[hashValue].indexes[map[hashValue].num++] = i;
	}
	
	char ***result = (char***)malloc(sizeof(char**) * (*returnSize));
	*columnSizes = (int*)malloc(sizeof(int) * (*returnSize));
	int columnSizesIndex = 0;
	for (int i = 0; i < strsSize; i++)
	{
		if (map[i].num > 0)
		{
			(*columnSizes)[columnSizesIndex] = map[i].num;
			result[columnSizesIndex] = (char**)malloc(sizeof(char *) * map[i].num);
			for (int j = 0; j < map[i].num; j++)
			{
				int index = map[i].indexes[j];
				result[columnSizesIndex][j] = strs[index];
			}
			columnSizesIndex++;
		}
		free(words[i]);
	}
	free(words);
	return result;
}

int main()
{
	char *dest[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	int strsSize = 6;
	int **columnSizes = (int**)malloc(sizeof(int*) * 3);
	int returnSize;
	char **strs = (char**)malloc(sizeof(char*) * strsSize);
	for (int i = 0; i < strsSize; i++)
	{
		int len = strlen(dest[i]);
		strs[i] = malloc(sizeof(char) * (len + 1));
		for (int j = 0; j < len; j++) strs[i][j] = dest[i][j];
		strs[i][len] = '\0';
		
	}
	char ***result = groupAnagrams(strs, strsSize, columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < columnSizes[0][i]; j++)
		{
			printf("%s ", result[i][j]);
			free(result[i][j]);
		}
		printf("\n"); free(result[i]);
	}
	free(result);
	return 0;
}