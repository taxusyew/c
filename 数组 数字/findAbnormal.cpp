#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main()
{
	int num[8] = {1,1,2,2,3,3,125,8};
	int result = num[0];
	int i = 1;

	int abnormalA = 0;
	int abnormalB = 0;

	for (i; i < 8; i++)
	{
		result = result ^ num[i];
	}

	// 找到第几位不同
	int totalbit = sizeof(int) * 8;
	int j = 0;
	for (j; j < totalbit; j++)
	{
		if (((result>>j)& 1) == 1)
		{
			break;
		}
	}

	int * numA = (int *)malloc(sizeof(int)*8);
	int * numB = (int *)malloc(sizeof(int)*8);
	memset(numA, 0 , sizeof(int)*8);
	memset(numB, 0 , sizeof(int)*8);
	int * tmpnumA = numA;
	int * tmpnumB = numB;

	// 划分两个数组
	for (i = 0; i < 8; i++)
	{
		if (((num[i]>>j) & 1) == 1)
		{
			*tmpnumA = num[i];
			tmpnumA++;
		}
		else
		{
			*tmpnumB = num[i];
			tmpnumB++;
		}

	}

	// 分别对两个数组异或
	for (i = 0; i < 8; i++)
	{
		abnormalA = abnormalA ^ numA[i];
	}

	for (i = 0; i < 8; i++)
	{
		abnormalB = abnormalB ^ numB[i];
	}

	free(numA);
	free(numB);
	printf("%d\n", abnormalA);
	printf("%d\n", abnormalB);
	system("pause");
}