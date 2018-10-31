#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) 
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int len = lena > lenb ? lena + 1 : lenb + 1;
	char *result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0'; result[len - 1] = '\0';
	len = 0;
	int carry = 0;
	for (int i = lena - 1, j = lenb - 1; carry != 0 || i >= 0 || j >= 0; i--, j--)
	{
		int numberA = i >= 0 ? a[i] - '0' : 0;
		int numberB = j >= 0 ? b[j] - '0' : 0;
		result[len] = (numberA ^ numberB ^ carry) + '0';
		len++;
		carry = carry + numberA + numberB > 1 ? 1 : 0;
	}
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		char c = result[i];
		result[i] = result[j];
		result[j] = c;
	}
	return result;
}

int main()
{
	char *a = "1010";
	char *b = "1011";
	char *result = addBinary(a, b);
	printf("The result is %s", result);
	return 0;
}