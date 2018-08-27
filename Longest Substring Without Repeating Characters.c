#include<string.h>
#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
	int maxlen = 0;
	int currlen = 0;
	int table[256];
	int start = 0;
	memset(table, 0, sizeof(table));
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if ((++table[s[i]]) == 2)
		{
			if (currlen > maxlen)
			{
				maxlen = currlen;
			}
			for (int j = start; j < i; ++j)
			{
				if (s[i] == s[j])
				{
					table[s[j]] = 1;
					start = j + 1;
					break;
				}else {
					--currlen;
					table[s[j]] = 0;
				}
			}
		}else {
			++currlen;
		}
	}
	if (currlen > maxlen)
	{
		maxlen = currlen;
	}
	return maxlen;
}