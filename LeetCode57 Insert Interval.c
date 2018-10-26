#include <stdio.h>
#include <stdlib.h>

struct Interval
{
	int start;
	int end;
};

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize)
{
	struct Interval *result = (struct Interval*)malloc(sizeof(struct Interval) * (intervalsSize + 1));
	int curr = 0;
	while (curr < intervalsSize && intervals[curr].end < newInterval.start)
	{
		result[curr] = intervals[curr];
		curr++;
	}
	int index = curr;
	while (index < intervalsSize && intervals[index].start <= newInterval.end)
	{
		newInterval.start = newInterval.start < intervals[index].start ? newInterval.start : intervals[index].start;
		newInterval.end = newInterval.end > intervals[index].end ? newInterval.end : intervals[index].end;
		index++;
	}
	result[curr] = newInterval; curr++;
	while (index < intervalsSize)
	{
		result[curr] = intervals[index];
		curr++; index++;
	}
	*returnSize = curr;
	return result;
}

int main()
{
	int start[] = { 1,3,6,8,12 };
	int end[] = { 2,5,7,10,16 };
	int intervalsSize = sizeof(start) / sizeof(start[0]);
	struct Interval* intervals = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
	for (int i = 0; i < intervalsSize; i++)
	{
		intervals[i].start = start[i];
		intervals[i].end = end[i];
	}
	int returnSize;
	struct Interval newInterval;
	newInterval.start = 4; newInterval.end = 8;
	struct Interval* result = insert(intervals, intervalsSize, newInterval, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("[%d %d]\n", result[i].start, result[i].end);
	}
	free(intervals);free(result);
	return 0;
}