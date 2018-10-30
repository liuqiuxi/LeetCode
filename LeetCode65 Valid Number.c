#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void skipBlank(char **s)
{
	while (**s == ' ') (*s)++;
}

int digitNumber(char **s, bool allowSign)
{
	int number = 0;
	if (allowSign == true) if (**s == '+' || **s == '-') (*s)++;
	while (**s >= '0' && **s <= '9')
	{
		(*s)++; number++;
	}
	return number;
}

bool isNumber(char* s)
{
	skipBlank(&s);
	int number = 0, floatnumber = 0;
	number = digitNumber(&s, true);
	if (*s == '.')
	{
		s++;
		floatnumber = digitNumber(&s, false);
	}
	if ((*s == 'e' || *s == 'E') && (number + floatnumber > 0))
	{
		s++;
		if (!(number = digitNumber(&s, true))) return false;
	}
	skipBlank(&s);
	return (number + floatnumber) && !*s;
}

int main()
{
	char *s = " 2e10 ";
	bool result = isNumber(s);
	printf("The result is %d", result);
	return 0;
}