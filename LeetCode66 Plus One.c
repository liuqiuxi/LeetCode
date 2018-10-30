#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int count = 0;
	for (int i = 0; i < digitsSize; i++)
	{
		if (digits[i] == 9) count++;
		else count = 0;
	}
	if (count == digitsSize){
		*returnSize = digitsSize + 1;
		int *result = (int*)calloc(digitsSize + 1, sizeof(int));
		result[0] = 1;
		return result;
	}else {
		*returnSize = digitsSize;
		int index = digitsSize - count;
		int *result = (int*)calloc(digitsSize, sizeof(int));
		memcpy(result, digits, index * sizeof(int));
		result[index - 1]++;
		return result;
	}
}

int main()
{
	int digits[] = { 8,9,9,9 };
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int *result = plusOne(digits, digitsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) printf("%d", result[i]); free(result);
	return 0;
}

