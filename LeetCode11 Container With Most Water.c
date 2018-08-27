#include <stdio.h>

int maxArea(int* height, int heightSize) {
	int maxSize = 0;
	if (heightSize == 2)
	{
		return (height[0] >= height[1]) ? height[1] : height[0];
	}
	for (int i = 0; i < heightSize; i++)
	{
		for (int j = i + 1; j < heightSize; j++)
		{
			int length = (height[i] >= height[j]) ? height[j] : height[i];
			if (maxSize < length * (j - i))
			{
				maxSize = length * (j - i);
			}
		}
	}
	return maxSize;
}

int main()
{
	int height[3] = { 1,2,1 };
	int maxSize = maxArea(height, 3);
	printf("%d\n", maxSize);
	return 0;
}