#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int OddIndex(char *s, int middle)
{
	int i = middle - 1;
	int j = middle + 1;
	while (i >=0 && s[j] && s[i] == s[j])
	{
		i--;
		j++;
	}
	return j - 1;
}

int EvenIndex(char *s, int middle)
{
	int i = middle;
	int j = middle + 1;
	while (i >= 0 && s[j] && s[i] == s[j])
	{
		i--;
		j++;
	}
	return j - 1;
}


char* longestPalindrome(char* s) {
	int endIndex, start = 0, end = 0, maxLen = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		endIndex = OddIndex(s, i);
		if (maxLen < (endIndex - i) * 2 + 1)
		{
			maxLen = (endIndex - i) * 2 + 1;
			start = i - (endIndex - i);
			end = endIndex;
		}
		endIndex = EvenIndex(s, i);
		if (maxLen < (endIndex - i) * 2)
		{
			maxLen = (endIndex - i) * 2;
			start = i - (endIndex - i) + 1;
			end = endIndex;
		}
	}
	char *result = (char*)malloc(sizeof(char) * (maxLen + 1));
	for (int i = 0; i < maxLen; i++)
	{
		result[i] = s[start + i];
	}
	result[maxLen] = '\0';
	return result;
}


int main()
{
	char *str = "abbbbc";
	char *result = longestPalindrome(str);
	printf("%s\n", result);
	free(result);
	return 0;
}