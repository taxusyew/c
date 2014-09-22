/*************************************************
File name: prime.cpp
Description: 判断给定范围内的素数个数
Author: taxus
Version: 1.0
Date: 2014-09-22
History: 
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define MAXNUM 100000
int main() {

	int a[MAXNUM+1];
	clock_t start, finish;
	double time;

	// 初始化数组，每个数组元素都放置数值，最大到42亿
	for (int i = 0; i <= MAXNUM + 1; i++) {
		a[i] = i;
	}
	a[1] = 0;

	start = clock();
	// 把数组中初始化为连续整数，从头到尾遍历，i为之前的数组都确定过了，j是i每次固定后的遍历用的
	// 内层循环每次从确定的值开始，向后step=1遍历每个值是否是现在这个值i的倍数
	for (int i = 2; i< sqrt((float)MAXNUM); i++) {
		for (int j = i + 1; j <= MAXNUM; j++) {
			if (a[j] != 0 && a[j] % i == 0) {
				a[j] = 0;
			}
		}
	}
	finish = clock(); time = (double)((finish - start) / CLOCKS_PER_SEC);

	// 打印数据
	int n = 0;
	for (int i = 1; i <= MAXNUM; i++) {
		if (a[i] != 0) {
			n++;
			/*printf("%d\t", a[i]);
			if (++n % 10 == 0) {
				printf("\n");
			}*/
		}
	}
	printf("%d\n", n);
	printf("runtime:%f\n", time);
	//printf("\n");

	return 0;
}
