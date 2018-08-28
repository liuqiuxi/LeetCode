#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// LeetCode don't support strcat_s
// use strcat instead of strcat_s and delete second parameters


char* intToRoman(int num) {
	char *A[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	char *B[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char *C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	char *D[] = { "", "M", "MM", "MMM" };
	char *result = (char*)malloc(sizeof(char) * 1000);
	memset(result, 0, sizeof(result));
	strcat_s(result, sizeof(result) * strlen(result) + sizeof(D[num / 1000]) * strlen(D[num / 1000]) + sizeof(char), D[num / 1000]);
	strcat_s(result, sizeof(result) * strlen(result) + sizeof(C[(num % 1000) / 100]) * strlen(C[(num % 1000) / 100]) + sizeof(char), C[(num % 1000) / 100]);
	strcat_s(result, sizeof(result) * strlen(result) + sizeof(B[(num % 100) / 10]) * strlen(B[(num % 100) / 10]) + sizeof(char), B[(num % 100) / 10]);
	strcat_s(result, sizeof(result) * strlen(result) + sizeof(A[(num % 10)]) * strlen(A[(num % 10)]) + sizeof(char), A[(num % 10)]);
	return result;
}

int main()
{
	char *S = intToRoman(1994);
	printf("%s\n", S);
	free(S);
	return 0;
}