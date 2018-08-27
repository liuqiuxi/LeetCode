#include <stdio.h>
#include <stdbool.h>

//https://blog.csdn.net/runningtortoises/article/details/45566403
bool isMatch(char* s, char* p) {
	if (s == NULL || p == NULL)
	{
		return false;
	}
	if (!*p)
	{
		return !*s;
	}
	if (*(p + 1) == '*')
	{
		while ((*p == *s) || (*s && *p == '.'))
		{
			if (isMatch(s, p + 2))
			{
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);
	}
	else if ((*p == *s) || (*s && *p == '.'))
	{
		return isMatch(s + 1, p + 1);
	}
	return false;
}

int main()
{
	char *s = "mississippi";
	char *p = "mis*is*p*.";
	bool result = isMatch(s, p);
	printf("%d\n", result);
	return 0;
}