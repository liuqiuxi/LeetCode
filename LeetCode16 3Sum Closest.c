#include<stdio.h>
#include<math.h>

int threeSumClosest(int* nums, int numsSize, int target) {
	int min = 1000;
	int result;
	if (numsSize < 3)
	{
		return NULL;
	}
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			for (int k = j + 1; k < numsSize; k++)
			{
				int sub = nums[i] + nums[j] + nums[k] - target;
				if (abs(sub) < abs(min))
				{
					min = sub;
					result = nums[i] + nums[j] + nums[k];
				}
			}
		}
	}
	return result;
}

int main()
{
	int nums[] = {1,1,1,0};
	int result = threeSumClosest(nums, 4, -100);
	printf("%d\n", result);
	return 0;
}