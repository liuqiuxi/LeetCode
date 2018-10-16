#include <stdio.h>

int trap(int* height, int heightSize) 
{
	int level = 0, result = 0;
	for (int i = heightSize - 1; i >= 0; i--)
	{
		int lower = *height < height[i] ? *height++ : height[i];
		if (lower > level) level = lower;
		result = result + level - lower;
	}
	return result;
}

int main()
{
	int height[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int heightSize = sizeof(height) / sizeof(height[0]);
	int result = trap(height, heightSize);
	printf("The result is %d", result);
	return 0;
}