#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


bool isValid(char* s) {
	char *result = (char*)malloc(sizeof(char) * (int)strlen(s));
	int top = -1;
	int len = 0;
	while (s[len])
	{
		if (s[len] == ')')
		{
			if (top >= 0 && result[top] == '(')
			{
				top--;
			}
			else {
				return false;
			}
		}
		else if (s[len] == ']')
		{
			if (top >= 0 && result[top] == '[')
			{
				top--;
			}
			else {
				return false;
			}
		}
		else if (s[len] == '}')
		{
			if (top >= 0 && result[top] == '{')
			{
				top--;
			}
			else {
				return false;
			}
		}
		else {
			top = top + 1;
			result[top] = s[len];
		}
		len++;
	}
	free(result);
	return top == -1;
}

int main()
{
	char *s = "[({(())}[()])]";
	bool i = isValid(s);
	printf("%d\n", i);
	return 0;
}