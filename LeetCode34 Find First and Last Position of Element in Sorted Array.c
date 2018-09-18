#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int *result = (int*)malloc(sizeof(int) * 2);
	int left = 0, right = numsSize - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (nums[middle] == target) break;
		else if (nums[middle] > target) right = middle - 1;
		else left = middle + 1;
	}
	if (left <= right){
		left = middle - 1;
		while (left >= 0 && nums[left] == nums[middle]) left--;
		right = middle + 1;
		while (right < numsSize && nums[right] == nums[middle]) right++;
		result[0] = left + 1; result[1] = right - 1;
		*returnSize = 2;
		return result;
	}else{
		result[0] = -1; result[1] = -1;
		*returnSize = 2;
		return result;
	}
}

int main()
{
	int nums[] = { 5,7,7,8,8,10};
	int i, target = 8;
	int *result = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &i);
	for (int j = 0; j < i; j++) printf("%d", result[j]);
	free(result);
	return 0;
}