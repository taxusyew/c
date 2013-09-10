#include "stdio.h"

int swap(int * a, int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
// 冒泡排序
int * BUBBLE(int * output, int n)
{
	int i = 0;
	int j = 1;

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (output[i] > output [j])
			{
				swap(output+i, output+j);
			}
		}
	}
	return 0;
}

int main()
{
	int input[] = {100,26,2,89,4,7,9};
	int i = 0;

	int * output;

	BUBBLE(input, 7);

	for (i; i < 7; i++)
	{
		printf("%d\n", input[i]);
	}
	
	return 0;
}
