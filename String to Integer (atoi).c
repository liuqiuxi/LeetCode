#include <stdio.h>
#include<ctype.h>
#include<string.h>

#define INT_MAX  2147483648
#define INT_MIN -2147483647-1

int myAtoi(char* str) {
	int flag = 1, result = 0, dig;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			flag = -1;
		}
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return flag * result;
		}
		dig = *str - '0';
		if (flag == 1 && result * 10.0 + dig > INT_MAX)
		{
			return INT_MAX;
		}
		else if (flag == -1 && -1 * result * 10.0 - dig < INT_MIN)
		{
			return INT_MIN;
		}
		result = result * 10 + dig;
		str++;
	}
	result = flag * result;
	return result;
}


int main()
{
	char *s = "-91283472332";
	int i = myAtoi(s);
	printf("%d\n", i);
	return 0;
}