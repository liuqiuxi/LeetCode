#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (target == nums[middle]) return middle;
		if (nums[left] < nums[right]){
			if (target < nums[middle]) right = middle - 1;
			else left = middle + 1;
		}else if (nums[left] <= nums[middle]){
			if (target > nums[middle] || target < nums[left]) left = middle + 1;
			else right = middle - 1;
		}else {
			if (target < nums[middle] || target > nums[right]) right = middle - 1;
			else left = middle + 1;
		}
	}
	return -1;
}

int main()
{
	int nums[] = { 4,5,6,7,0,1,2 };
	int target = 0;
	int result = search(nums, sizeof(nums) / sizeof(nums[0]), target);
	printf("the result is %d", result);
	return 0;
}