#include "stdio.h"
#include "stdlib.h"
#include "string.h"

main() {

	int step = 2016;
	int i = 0;

	float * array = (float *)malloc(sizeof(float) * step);
	float * p = array;
	memset(array, 0, sizeof(float) * step);

	// 初始化p0
	*p = 1; p++;
	// p1
	*p = *(p - 1) / 6; p++;
	// p2
	*p = (*(p - 1) + *(p - 2)) / 6; p++;
	// p3
	*p = (*(p - 1) + *(p - 2) + *(p - 3)) / 6; p++;
	// p4
	*p = (*(p - 1) + *(p - 2) + *(p - 3) + *(p - 4)) / 6; p++;
	// p5
	*p = (*(p - 1) + *(p - 2) + *(p - 3) + *(p - 4) + *(p - 5)) / 6; p++;
	// p6
	*p = (*(p - 1) + *(p - 2) + *(p - 3) + *(p - 4) + *(p - 5) + *(p - 6)) / 6; p++;

	for (i=7; i < step; p++, i++)
	{
		*p = (*(p - 1) + *(p - 2) + *(p - 3) + *(p - 4) + *(p - 5) + *(p - 6)) / 6;
	}

	free(array);
}
