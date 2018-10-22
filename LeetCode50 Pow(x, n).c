#include <stdio.h>
#include <math.h>

#define MIN -2147483647 - 1

double myPow(double x, int n) 
{
	double result = 1;
	if (n == 0) return 1;
	if (n == MIN)
	{
		n++;
		n = -n;
		result = result * myPow(x * x, abs(n) / 2) * x * x;
		return 1 / result;
	}
	if (n % 2 == 0){
		result = myPow(x * x, abs(n) / 2);
	}else {
		result = myPow(x * x, abs(n) / 2) * x;
	}
	return n > 0 ? result : 1 / result;
}

int main()
{
	double x = 5;
	int n = 2;
	double result = myPow(x, n);
	printf("The result is %g", result);
	return 0;
}