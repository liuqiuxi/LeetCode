#include <stdlib.h>
#include<stdio.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int* nums = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
	for (int i = 0; i < nums1Size + nums2Size; i++)
	{
		if (i < nums1Size)
		{
			nums[i] = nums1[i];
		}else {
			nums[i] = nums2[i - nums1Size];
		}
	}
	qsort(nums, nums1Size + nums2Size, sizeof(nums[0]), cmp);
	double result = ((nums1Size + nums2Size) % 2 == 0 ? (((double)nums[(nums1Size + nums2Size) / 2 - 1] + (double)nums[(nums1Size + nums2Size) / 2]) / 2.0) : (double)nums[(nums1Size + nums2Size) / 2]);
	free(nums);
	return result;
}

int main()
{
	int nums1[4] = { 1,2,3,4 };
	int nums2[6] = { 5,6,7,8,9,10 };
	double x = findMedianSortedArrays(nums1, 4, nums2, 6);
	printf("%g\n", x);
	return 0;
}