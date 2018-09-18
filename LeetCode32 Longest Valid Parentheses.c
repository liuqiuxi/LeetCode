#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char* s) 
{
	int len = strlen(s);
	int result = 0, index = 0, tmp;
	int *pos_stack = (int*)malloc(sizeof(int) * len);
	char *str_stack = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '('){
			pos_stack[index] = i;
			str_stack[index] = s[i];
			index++;
		}else {
			if (str_stack[index - 1] == '('){
				index--;
				if (index == 0) tmp = i + 1;
				else tmp = i - pos_stack[index - 1];
				result = result > tmp ? result : tmp;
			}else {
				str_stack[index] = s[i];
				pos_stack[index] = i;
				index++;
			}
		}
	}
	free(pos_stack); free(str_stack);
	return result;
}

int main()
{
	char *s = ")()())";
	int result = longestValidParentheses(s);
	printf("the result is %d", result);
	return 0;
}