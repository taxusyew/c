#include "stdio.h"

int swap(int * a, int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 开始快排算法
int * QSort(int * output, int i, int j)
{
	
	// int len ;应当暂存j
	int len = j;
	// 同样暂存i
	int start = i;
	int pivotal = 0;
	// pivotal = output[0];pivotal选为本次开头，而不是固定的0号位置
	pivotal = output[i];

	// 加入退出递归的条件
	if (i > j)
	{
		return 0;
	}

	// while(i<=j)应当是小于
	while(i<j)
	{
		// 从后往前
		while(pivotal < output[j] && i<=j)
			j--;
		if(i < j)
			swap(output+i, output+j);
		
		// 从前往后
		while(pivotal > output[i] && i<=j)
			i++;
		// 判断一下是否是因为i<=j退出
		if(i < j)
			swap(output+i, output+j);
	}
	output[i] = pivotal;
	// QSort(output, 0, i-1);同样开头不能是0，应该是本次开始
	QSort(output, start, i-1);
	QSort(output, i+1, len);
	
	return 0;
	
}
int main()
{
	int input[] = {100,26,2,89,4,7,9};
	int i = 0;
	
	QSort(input, 0, 6);
	
	for (i; i < 7; i++)
	{
		printf("%d\n", input[i]);
	}
	
	return 0;
}