#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getLetterCom(char **result, char *digits, char *tmp, int index, char map[10][5], int *top)
{
	int digit = digits[index] - '0';
	if (digits[index] == 0)
	{
		char *letter = (char *)malloc(sizeof(char) * (index + 1));
		tmp[index] = 0;
		//if use strcpy: strcpy(letter, tmp)
		strcpy_s(letter, (int)strlen(tmp) + 1, tmp);
		result[*top] = letter;
		(*top)++;
		return;
	}
	for (int i = 0; map[digit][i]; i++)
	{
		tmp[index] = map[digit][i];
		getLetterCom(result, digits, tmp, index + 1, map, top);
	}
}

char** letterCombinations(char* digits, int* returnSize) {
	char map[10][5] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int num = 1, length = 0, top = 0;
	while (digits[length])
	{
		if (digits[length] == '0' || digits[length] == '1'){
			continue;
		}else if (digits[length] == '7' || digits[length] == '9') {
			num = num * 4;
		}else {
			num = num * 3;
		}length++;
	}
	char **result = (char**)malloc(sizeof(char *) * num);
	if (length == 0) {
		*returnSize = 0;
		return result;
	}
	char *tmp = (char*)malloc(sizeof(char) * length);
	getLetterCom(result, digits, tmp, 0, map, &top);
	*returnSize = top;
	return result;
}

int main() {
	int size = 0;
	char digits[] = "456";
	char ** letters = letterCombinations(digits, &size);
	for (int i = 0; i < size; i++) {
		printf("%s\n", letters[i]);
		free(letters[i]);
	}
	free(letters);
	return 0;
}