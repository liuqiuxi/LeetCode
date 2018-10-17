#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) 
{
	char *scur = s, *pcur = p, *sstar = NULL, *pstar = NULL;
	while (*scur)
	{
		if (*scur == *pcur || *pcur == '?'){
			scur++;
			pcur++;
		}else if (*pcur == '*') {
			pstar = pcur++;
			sstar = scur;
		}else if (pstar) {
			pcur = pstar + 1;
			scur = sstar++;
		}else {
			return false;
		}
	}
	while (*pcur == '*') pcur++;
	return !*pcur;
}

int main()
{
	char s[] = "adceb";
	char p[] = "*a*b";
	bool result = isMatch(s, p);
	printf("The result is %d", result);
	return 0;
}