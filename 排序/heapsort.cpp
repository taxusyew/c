#include "stdlib.h"
#include "stdio.h"

#define LEFT(i) (2*i +1)
#define RIGHT(i) (2*i +2)
#define PARENT(i) (i/2 -1)

/*
	交换数据，摘取最大值，放入有序区
*/
void mvRoot2Leaf(int * array, int a, int b)
{
	int c = array[a];
	array[a] = array[b];
	array[b] = c;
}

/*
	调整为大顶堆
*/
void buildMaxHeap(int * array, int len, int orderLen)
{
	int left = 0;
	int right = 0;
	int parent = 0;

	int last = len - orderLen;

	parent = array[PARENT(last)];
}

void heapSort(int * heap, int len)
{
	int tmpLen = len-1;		// 暂存有序区的第一个序号
	int i = 0;
	int orderLen = 0;		// 有序区长度

	for (i; i < len; i++)
	{
		// 先调整为大根堆
		buildMaxHeap(heap, len, orderLen);

		// 摘取最大值，放入有序区
		mvRoot2Leaf(heap, 0, tmpLen);

		// 重新调整为大根堆，重复，序号向前，长度加1
		tmpLen--;
		orderLen++;
	}
}

void main()
{
	int heap[10] = {12,48,66,34,12,87,84,25,79,34};

	//heapSort(heap, 10);
	printf("%d", 9/2);
	system("pause");
}
