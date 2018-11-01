#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillWords(char *line, int len, char **words, int *wordLen, int maxWidth, int evenSpace, int remainSpace, int start, int end)
{
	char *p = line;
	for (int i = start; i < end; i++)
	{
		memcpy(p, words[i], wordLen[i]);
		p = p + wordLen[i];
		if (i < end - 1)
		{
			for (int j = 0; j < evenSpace; j++) *(p++) = ' ';
			if (remainSpace > 0)
			{
				*(p++) = ' ';
				remainSpace--;
			}

		}
	}
	while (p - line < maxWidth) *(p++) = ' ';
	*(p++) = '\0';
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) 
{
	int amt = 100; *returnSize = 0;
	char **result = (char**)malloc(sizeof(char*) * amt);
	char *buf = (char*)malloc((maxWidth + 1) * amt);
	for (int i = 0; i < amt; i++) result[i] = buf + i * (maxWidth + 1);
	int *wordLen = (int*)malloc(sizeof(int) * wordsSize);
	for (int i = 0; i < wordsSize;i++) wordLen[i] = strlen(words[i]);
	int wordCount = 0, len = 0, start = 0, chars = 0;
	for (int i = 0; i < wordsSize; i++)
	{
		if (len + wordLen[i] > maxWidth) {
			int evenSpace = wordCount == 1 ? 0 : (maxWidth - chars) / (wordCount - 1);
			int remainSpace = wordCount == 1 ? 0 : (maxWidth - chars) % (wordCount - 1);
			fillWords(result[*returnSize], len, words, wordLen, maxWidth, evenSpace, remainSpace, start, i);
			(*returnSize)++; wordCount = 1; len = wordLen[i] + 1; chars = wordLen[i]; start = i;
		}else if (len + wordLen[i] == maxWidth) {
			chars = wordLen[i] + chars;
			int evenSpace = wordCount == 0 ? 0 : (maxWidth - chars) / wordCount;
			int remainSpace = wordCount == 0 ? 0 : (maxWidth - chars) % wordCount;
			fillWords(result[*returnSize], len, words, wordLen, maxWidth, evenSpace, remainSpace, start, i + 1);
			(*returnSize)++; wordCount = 0; len = 0; chars = 0; start = i + 1;
		}else {
			chars = wordLen[i] + chars;
			len = wordLen[i] + 1 + len;
			wordCount++;
		}
	}
	if (wordCount > 0)
	{
		char *p = result[*returnSize];
		for (int i = start; i < start + wordCount; i++)
		{
			memcpy(p, words[i], wordLen[i]);
			p = p + wordLen[i];
			if (i < start + wordCount - 1) *(p++) = ' ';
		}
		while (p - result[*returnSize] < maxWidth) *(p++) = ' ';
		*(p++) = '\0';
		(*returnSize)++;
	}
	free(wordLen);
	return result;
}

int main()
{
	char *words[] = { "This", "is", "an", "example", "of", "text", "justification." };
	int maxWidth = 16;
	int returnSize;
	char **result = fullJustify(words, 7, maxWidth, &returnSize);
	for (int i = 0; i < returnSize; i++) printf("%s\n", result[i]);
	free(result);
	return 0;
}