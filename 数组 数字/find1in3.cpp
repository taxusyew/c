#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int find1in3(int * a, int len)
{
	int bit[32];
	memset(bit, 0, 32 * sizeof(int));
	int i = 0;
	int result = 0;

	for (i; i < len; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			// 每次把a中的一个数的32位，加到bit数组中
			bit[j] += ((a[i]>>j)&1);
		}
	}

	for (i = 0; i < 32; i++)
	{
		if((bit[i] % 3) != 0)
		{
			result += (1 << i);
		}
	}

	return result;
}

void main()
{
	int a[10] = {1,1,1,2,2,2,3,3,3,0};

	int result = find1in3(a, 10);
	printf("%d\n", result);
	system("pause");
}
