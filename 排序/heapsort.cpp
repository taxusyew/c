#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

#define LEFT(i) (2*i +1)
#define RIGHT(i) (2*i +2)
#define PARENT(i) (i/2 + i%2 -1)

void swap(int * array, int a, int b);
void sswap(int * array, int a, int b);
void mvRoot2Leaf(int * array, int a, int b);
void buildMaxHeap(int * array, int len, int orderLen);
void heapSort(int * heap, int len);
void printHeap(int * heap, int len);

void swap(int * array, int a, int b)
{
	int tmp = 0;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/*
	smart swap 判断两个值，如果第一个大于第二个，就交换
	如果不大于，不交换
*/
void sswap(int * array, int a, int b)
{
	if (array[a] < array[b])
		swap(array, a, b);
}

/*
	交换数据，摘取最大值，放入有序区
*/
void mvRoot2Leaf(int * array, int a, int b)
{
	swap(array, a, b);
}

/*
	调整为大顶堆

	do while(1) 优化？
*/
void buildMaxHeap(int * array, int len, int orderLen)
{
	int i = len - orderLen - 1;	// 记录无序区最后一个下标，所以多-1
	
	// 刚开始为奇数,只有一片叶子
	if (i%2 == 1)
	{
		sswap(array, PARENT(i), i);
		i--;
	}

	for(i; i > 0; i--)
	{
		// 两个叶子都和父节点交换
		sswap(array, PARENT(i), i-1);
		sswap(array, PARENT(i), i);

		i--;
	}
}

void heapSort(int * heap, int len)
{
	int tmpLen = len-1;		// 暂存有序区的第一个序号
	int i = 0;
	int orderLen = 0;		// 有序区长度

	// 排除长度为1的情况
	if ( len == 1) return;
	
	for (i; i < len; i++)
	{
		// 先调整为大根堆，选出无序组中的最大的
		buildMaxHeap(heap, len, orderLen);

		// 摘取最大值，放入有序区
		mvRoot2Leaf(heap, 0, tmpLen);

		// 重新调整为大根堆，重复，序号向前，长度加1
		tmpLen--;
		orderLen++;

		printHeap(heap, len);
	}
}

/*
	输出堆
*/
void printHeap(int * heap, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", heap[i]);
	}
	printf("\n");
}

void main()
{
	//int heap[10] = {12,48,66,34,12,87,84,25,79,34};
	//int heap[2] = {120,48};

	// 设置随机数种子
	srand((int)time(0));
	// 第一次是固定的2
	(int)(20.0*rand()/(RAND_MAX+1.0));				
	int length = (int)(20.0*rand()/(RAND_MAX+1.0));
	int * heap = (int *)malloc(sizeof(int)*length);
	memset(heap, 0 , sizeof(int)*length);

	printf("数组长度为 %d\n", length);

	// 初始化数组
	for (int i = 0; i < length; i++)
	{
		heap[i] = (int)(500.0*rand()/(RAND_MAX+1.0))+1;
		//printf("%d\n", (int)(20.0*rand()/(RAND_MAX+1.0)) );
	}
	
	printf("初始数组为：", length);
	printHeap(heap, length);

	// 排序
	heapSort(heap, length);

	free(heap);
	system("pause");
}
