#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vex
{
	int Vexs;
	struct Vex *next;
}Vex;

typedef struct DiGraph
{
	Vex * vexList;
	int vexNum;
	int arcNum;
}DiGraph;

// 创建无向图
// 节点从0开始
// 节点数为nodeNum
DiGraph * CreateDiGraph(int nodeNum)
{
	DiGraph * dg = (DiGraph * )malloc(sizeof(DiGraph));
	Vex * vexList = (Vex * )malloc(sizeof(Vex)* nodeNum);
	memset(vexList, 0, sizeof(Vex)*nodeNum);
	// Vex vexList[10];

	dg->vexNum = nodeNum;
	dg->arcNum = 0;
	dg->vexList = vexList;

	return dg;
}

// 插入弧
// 起点src，终点des
void InsertArc(DiGraph * dg, int src, int des)
{
	// 如果刚开始获得节点数组的dg->vexList[src].next,那么稍后会因为多出一个next而操作0x0000地址的内容
	// 所以应该先得到一次节点，但是只拿到节点还是不能向后搜索链表，所以再把节点的next缓存一下，等下用它遍历链表
	// 但是会遇到第一个节点的特殊问题，如果第一个就是空，那么就不用遍历，直接覆盖父节点的next
	// 如果第一个不为空，那么父节点的表示方法就会从vex变为vexp，没办法统一，所以单列出来
	// 要成功插入一个弧，主要矛盾就是结构体数组的成员vex不能像指针一样++，而插入next区域需要得到父级（所在cell）的地址
	// 即要保存包裹cell的地址，所以产生矛盾
	Vex * vex = dg->vexList+src;
	//Vex * vexp = vex.next;
	Vex * temp = (Vex * )malloc(sizeof(Vex));
	temp->Vexs = des;
	temp->next = NULL;

	// 判断第一个节点是否为空
	//if(vex.next == NULL)
	//{
	//	vex.next = temp;
	//	return;
	//}

	// 类似单链表插入
	/*while ( vexp != NULL)
	{
		if(vexp->next != NULL)
			vexp = vexp->next;
		
	}
	*/

	//vexp->next = temp;

	while ( vex->next != NULL)
	{
		vex = vex->next;
	}
	vex->next = temp;
}

void PrintDiGraph(DiGraph * dg)
{
	Vex * vex = dg->vexList[0].next;
	int i = 0;
	int vexNum = dg->vexNum;

	for (i; i < vexNum; i++)
	{
		vex = dg->vexList[i].next;

		printf("%d", i);
		while ( vex != NULL)
		{
			printf("->");
			printf("%d", vex->Vexs);
			vex = vex->next;
		}
		printf("\n");
	}
	
}
int main()
{
	DiGraph * dg = CreateDiGraph(10);
	InsertArc(dg, 1, 2);
	InsertArc(dg, 1, 4);
	InsertArc(dg, 2, 5);
	InsertArc(dg, 4, 3);
	InsertArc(dg, 3, 5);
	
	PrintDiGraph(dg);

	return 0;
}