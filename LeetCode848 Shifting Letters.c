#include<stdlib.h>
#include<stdio.h>
int musum(int* shifts, int shiftsSize, int index)
{
	int sum = 0;
	for (int i = shiftsSize; i >= index; i--)
	{
		sum = sum + shifts[i];
	}
	while(sum >= 26)
	{ 
		sum = sum % 26;
	}
	return sum;
}


char* shiftingLetters(char* S, int* shifts, int shiftsSize)
{
	char *array = (char*)malloc(sizeof(S[0]) *  shiftsSize);
	for (int i = 0; i < shiftsSize; i++)
	{
		
		if (S[i] + musum(shifts, shiftsSize, i) <= 'z')
		{
			array[i] = S[i] + musum(shifts, shiftsSize, i);
		}
		else
		{
			array[i] = 'a' + (S[i] + musum(shifts, shiftsSize, i) - 'z') - 1;
		}
	}
	return array;
}

int main()
{
	printf("%d", 188 & 21);
}