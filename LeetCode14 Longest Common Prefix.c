#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestcommonprefix(char** strs, int strsSize) {
	int len = strlen(strs[0]);
	char *result = (char*)malloc(sizeof(strs[0]) * (len + 1));
	// VS Code do not supply strncpy, if want upolad leetcode please use strncpy
	// strncpy(result, strs[0], sizeof(strs[0]) * (len + 1));
	strncpy_s(result, sizeof(strs[0]) * (len + 1), strs[0], sizeof(strs[0]) * (len + 2));
	if (strsSize == 0)
	{
		return "";
	}
	for (int i = 1; i < strsSize; i++)
	{
		int j = 0;
		while (result[j] && strs[i][j] && result[j] == strs[i][j])
		{
			j++;
		}
		result[j] = 0;
	}
	return result;
}

int main()
{
	char *s[2] = { "hello", "world" };
	char *result = longestcommonprefix(s, 2);
	printf("%s\n", result);
	free(result);
	return 0;
}