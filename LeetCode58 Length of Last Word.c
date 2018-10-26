#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) 
{
	int len = strlen(s), result = 0, lastResult = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ' && s[i - 1] != ' ') lastResult = result;
		if (s[i] == ' ')
		{
			result = 0;
			continue;
		}
		result++;
	}
	if (s[len - 1] == ' ') result = lastResult;
	return result;
}

int main()
{
	char s[] = { "   aa   b " };
	int result = lengthOfLastWord(s);
	printf("The result is %d", result);
	return 0;
}