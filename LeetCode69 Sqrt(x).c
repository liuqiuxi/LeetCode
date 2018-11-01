#include <stdio.h>
#include <math.h>

int mySqrt(int x)
{
	double n = (double)x;
	int result = (int)sqrt(n);
	return result;
}

int main()
{
	int x = 8;
	int result = mySqrt(x);
	printf("The result is %d", result);
	return 0;
}