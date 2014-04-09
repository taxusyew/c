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

// ��������ͼ
// �ڵ��0��ʼ
// �ڵ���ΪnodeNum
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

// ���뻡
// ���src���յ�des
void InsertArc(DiGraph * dg, int src, int des)
{
	// ����տ�ʼ��ýڵ������dg->vexList[src].next,��ô�Ժ����Ϊ���һ��next������0x0000��ַ������
	// ����Ӧ���ȵõ�һ�νڵ㣬����ֻ�õ��ڵ㻹�ǲ�������������������ٰѽڵ��next����һ�£�����������������
	// ���ǻ�������һ���ڵ���������⣬�����һ�����ǿգ���ô�Ͳ��ñ�����ֱ�Ӹ��Ǹ��ڵ��next
	// �����һ����Ϊ�գ���ô���ڵ�ı�ʾ�����ͻ��vex��Ϊvexp��û�취ͳһ�����Ե��г���
	// Ҫ�ɹ�����һ��������Ҫì�ܾ��ǽṹ������ĳ�Աvex������ָ��һ��++��������next������Ҫ�õ�����������cell���ĵ�ַ
	// ��Ҫ�������cell�ĵ�ַ�����Բ���ì��
	Vex * vex = dg->vexList+src;
	//Vex * vexp = vex.next;
	Vex * temp = (Vex * )malloc(sizeof(Vex));
	temp->Vexs = des;
	temp->next = NULL;

	// �жϵ�һ���ڵ��Ƿ�Ϊ��
	//if(vex.next == NULL)
	//{
	//	vex.next = temp;
	//	return;
	//}

	// ���Ƶ��������
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