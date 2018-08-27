#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* convert(char* s, int numRows) {
	int len = strlen(s);
	char *head = (char*)malloc(sizeof(char) * (len + 1));
	char *result = head;
	head[len] = '\0';
	//if only one row, return s
	if (numRows == 1 || numRows > len)
	{
		return s;
	}
	//if s is null or numRows < 1
	if (s == NULL || numRows < 1)
	{
		return NULL;
	}
	for (int row = 0; row < numRows; ++row)
	{
		for (int index = row; index < len; index = index + 2 * numRows - 2)
		{
			*head++ = s[index];
			if ((row > 0) && (row < numRows - 1) && ((index + 2 * numRows - 2 - 2 * row) < len))
			{
				*head++ = s[index + 2 * numRows - 2 - 2 * row];
			}
		}
	}
	return result;
}

int main()
{
	char *input = "PAYPALISHIRING";
	char *output = convert(input, 3);
	printf("%s\n", output);
	free(output);
	return 0;
}