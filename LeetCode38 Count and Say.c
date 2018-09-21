#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate(char *s, int n, int count)
{
	char *result = (char*)malloc(sizeof(char) * 10086);
	int index = 0, i = 0, cnt = 1;
	if (count == n) return s;
	while (s[i] != 0)
	{
		if (s[i] == s[i + 1]){
			cnt++; i++;
		}else {
			result[index++] = cnt + '0';
			result[index++] = s[i];
			i++;
			cnt = 1;
		}
	}
	result[index] = 0;
	return generate(result, n, count + 1);
}


char* countAndSay(int n)
{
	return generate("1", n, 1);
}

int main()
{
	char *s = countAndSay(4);
	for (int i = 0; i < (int)strlen(s); i++) printf("%c", s[i]);
	free(s);
	return 0;
}