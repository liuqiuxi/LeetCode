#include <math.h>
int reverse(int x)
{
	int len = numberlen(x);
	int res = 0;
	if (x > abs((int)pow(2, 32)) - 1 || x < -1 * abs((int)pow(2, 32)))
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			res = res + x / (int)pow(10, len - i - 1) * (int)pow(10, i);
			x = x - x / (int)pow(10, len - i - 1) * (int)pow(10, len - i - 1);
		}
		return res;
	}
	
}

int numberlen(int x)
{
	int res = 0;
	while (x != 0)
	{
		x = x / 10;
		res++;
	}
	return res;
}
