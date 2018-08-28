#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(char s)
{
	switch (s)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default :
		return 0;
	}
}

int romanToInt(char* s) {
	int result = getInt(s[0]);
	for (int i = 1; i < (int)strlen(s); i++)
	{
		int j = getInt(s[i - 1]);
		int k = getInt(s[i]);
		if (j < k)
		{
			result = result + k - j * 2;
		}
		else {
			result = result + k;
		}
	}
	return result;
}

int main()
{
	char *s = "MCMXCIV";
	int result = romanToInt(s);
	printf("%d\n", result);
	return 0;
}