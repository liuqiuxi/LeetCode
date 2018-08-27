#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	int count = 0;
	int temp = x;
	int result = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	temp = x;
	for (int i = 0; i < count; i++)
	{
		int a = pow(10, count - i - 1);
		result = (temp / a) * (int)pow(10, i) + result;
		temp = temp - (temp / a) * a;
	}
	if (result - x == 0)
	{
		return true;
	}else {
		return false;
	}
}


int main()
{
	int num = 12345678;
	bool count = isPalindrome(num);
	printf("%d\n", count);
	return 0;
}