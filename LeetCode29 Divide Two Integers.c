#include<stdio.h>
#include<math.h>

#define MIN -2147483647 - 1
#define MAX  2147483647

int divide(int dividend, int divisor) {
	int sign = 0, i = 0;
	long long a = llabs((long long)dividend);
	long long b = llabs((long long)divisor);
	long long result = 0, map[33], times[33];
	if (dividend == 0) return 0;
	if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) sign = 1;
	map[0] = b; times[0] = 1;
	while (map[i] <= a && i < 33)
	{
		i++;
		map[i] = map[i - 1] + map[i - 1];
		times[i] = times[i - 1] + times[i - 1];
	}
	for (int j = i - 1; j >= 0; j--)
	{
		while (a >= map[j])
		{
			a = a - map[j];
			result = result + times[j];
		}
	}
	result = sign? result: -result;
	if (result < MIN || result > MAX) return MAX;
	return (int)result;
}

int main()
{
	int dividend = 100;
	int divisor = 5;
	int result = divide(dividend, divisor);
	printf("the result is %d\n", result);
	return 0;
}