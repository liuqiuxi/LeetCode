#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) 
{
	int len1 = strlen(num1); int len2 = strlen(num2);
	int i;
	int num = 0;

	char *result = (char*)malloc(sizeof(char) * (len1 + len2 + 1));

	if (num1 == NULL || num2 == NULL) return "";
	if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) return "0";

	for (i = 0; i < len1 + len2 - 1; i++)
	{
		for (int j = 0; j <= (i < (len1 - 1) ? i : (len1 - 1)); j++)
		{
			if (i - j < len2) num = num + (num1[len1 - 1 - j] - '0') * (num2[len2 - 1 - (i - j)] - '0');
		}
		if (i != len1 + len2 - 1 || num > 0)result[i] = num % 10 + '0';
		num = num / 10;
	}
	if (i == len1 + len2 - 1 && num > 0)
	{
		result[i] = num + '0';
		i++;
	}
	for (int j = 0; j < (i) / 2; j++)
	{
		int tmp = result[j];
		result[j] = result[i - j - 1];
		result[i - j - 1] = tmp;
	}
	result[i] = '\0';
	return result;
}

int main()
{
	char num1[] = "123456789";
	char num2[] = "987654321";
	char *result = multiply(num1, num2);
	printf("%s", result);
	free(result);
	return 0;
}