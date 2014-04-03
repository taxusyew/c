#include "stdio.h"

// 判断水仙花数
// 水仙花数：三位数字，每一位数字的三次方之和等于原来的数
int Daffodil(int input)
{
	int output = 0;
	int m = input;
	int i = 0;

	while (m)
	{
		i = m % 10;
		output += i * i * i;
		m = m / 10;
	}

	if (output == input)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i;

	for ( i = 100; i < 1000; i++)
	{
		if(Daffodil(i))
		{
			printf("%d\n", i);
		}
	}

	

	return 0;
}
