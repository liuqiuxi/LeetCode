#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
	int hay = strlen(haystack);
	int need = strlen(needle);
	if (needle == NULL || (int)strlen(needle) == 0) return 0;
	for (int i = 0; i < hay; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (int j = 0; j < need; j++)
			{
				if (haystack[i + j] != needle[j]) break;
				if (j == need - 1) return i;
			}
		}
	}
	return -1;
}

int main()
{
	char *haystack = "aaaaa";
	char *needle = "bba";
	int result = strStr(haystack, needle);
	printf("the result is %d", result);
	return 0;
}