#include "stdio.h"

// 无法超过4294967296
// 模仿自“妙趣横生的算法”P135
int ReverseNum(int input)
{
	int output = 0;
	int m = input;
	while (m)
	{
		// 十进制对10取余，是得到各位
		// 十进制乘以10，是左移一位
		// 十进制除以10，右移一位
		output = output*10 + m%10;
		m = m/10;
	}

	return output;
}

int main()
{
	int input;
	int reverse;

	scanf("%d", &input);

	reverse = ReverseNum(input);

	if(input == reverse)
	{
		printf("是回文数");
	}
	else
	{
		printf("非回文数");
	}

	return 0;
}
