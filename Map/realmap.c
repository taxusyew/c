#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct RMNode{
	int id;					// 每个节点的标示符
	int value;				// 每个节点的数据区
	int type;				// 和上一个节点弧的类型，默认为0，
	struct RMNode * adjoin;
	struct RMNode * next;
} RMNode;

typedef struct RealMap{
	int numNode;				// 节点个数
	int numArc;					// 弧的个数
	struct RMNode * first;		// 第一个节点
} RealMap;

// 新建一个图
RealMap * CreateRM()
{
	RealMap * rm = (RealMap *)malloc(sizeof(RealMap));
	rm->numArc = 0;
	rm->numNode = 0;
	rm->first = 0;

	return rm;
}

// 得到指定id的node
RMNode * GetNode(RealMap * rm,int id)
{
	RMNode * tmp;
	tmp = rm->first;

	while (tmp->id != id)
	{
		tmp = tmp->next;
	}
	
	return tmp;
}

// 添加一个节点
void AddNode(RealMap * rm, int id, int val) 
{
	RMNode * tmp;
	RMNode * node = (RMNode *)malloc(sizeof(RMNode));
	memset(node, 0, sizeof(RMNode));
	node->value = val;
	node->id = id;

	tmp = rm->first;
	// 判断是否第一个节点
	if(!tmp)
	{
		rm->first = node;
	}
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	
	rm->numNode ++;
}

// 实际添加一个弧
void InsertArc(RMNode * node, int des, int weight)
{
	
	RMNode * i;
	RMNode *arc = (RMNode *)malloc(sizeof(RMNode));
	memset(arc, 0, sizeof(RMNode));
	i = node->adjoin;
	
	if(!i)
	{
		node->adjoin = arc;
	}
	else
	{
		arc->adjoin = i;
		node->adjoin = arc;
	}
	arc->value = weight;
	arc->id = des;
}

// 判断要插入的两个节点是否存在
// 0 不存在  1 存在
int IfNodeExist(RealMap * rm, int id)
{
	RMNode * tmp;
	tmp = rm->first;

	if(!tmp)
	{
		printf("The map is empty. Can not insert!\n");
		return 0;
	}
	else
	{
		while (tmp != 0 && tmp->id != id)
		{
			tmp = tmp->next;
		}
		if(tmp == 0)
			return 0;
	}
	
	return 1;
}

// 判断要插入的弧是否存在
// 0 不存在  1 存在
int IfSingalArcExist(RealMap * rm, int src, int des)
{
	RMNode * tmp;
	RMNode * p;
	RMNode * q;
	tmp = rm->first;

	if(!tmp)
	{
		printf("The map is empty. Can not insert!\n");
		return 0;
	}
	else
	{
		tmp = GetNode(rm, src);
		q = p = tmp;

		// 多走一步，以保存上一个adjoin
		p = p->adjoin;
		while (p != 0 && p->id != des)
		{
			p = p->adjoin;
			q = q->adjoin;
		}
	
		if (p == 0)
		{
			// 不存在该弧
			return 0;
		}
		else{
			// 存在该弧
			return 1;
		}
	}
}

// 判断要插入的弧是否存在
// 0 不存在  1 存在
int IfArcExist(RealMap * rm, int src, int des)
{
	return IfSingalArcExist(rm, src, des) | IfSingalArcExist(rm, des, src);
}
// 添加一个弧，逻辑部分
void AddArc(RealMap * rm, int src, int des, int weight)
{
	RMNode * tmp;
	RMNode * arc;
	RMNode * tmparc;
	RMNode * node = (RMNode *)malloc(sizeof(RMNode));
	memset(node, 0, sizeof(RMNode));
	
	tmp = rm->first;
	// 判断要插入的两个节点是否存在
	if(!IfNodeExist(rm, des) || !IfNodeExist(rm, src))
	{
		printf("Error: des node does not exist!\n");
		return;
	}

	// 判断要插入的两个节点是否存在
	if(IfArcExist(rm, src, des))
	{
		printf("Error: Arc exist!\n");
		return;
	}

	//if(!tmp)
	//{
	//	printf("The map is empty. Can not insert!\n");
	//}
	//else
	//{
		while (tmp != 0 && tmp->id != src)
		{
			tmp = tmp->next;
		}
		// 判断是否到达最后
		if (tmp == 0)
		{
			printf("Error: Src node does not exist!\n");
		}
		else{
			// 从头插入弧链表
			InsertArc(tmp, des, weight);
			printf("InsertArc: No. %d -> No.%d\n", src, des);
		}
	//}
	
	rm->numArc++;
}



// 删除一个节点下挂载的一个弧
int DeleteAdjoinNode(RMNode * node,int id)
{
	RMNode * p;
	RMNode * q;
	q = p = node;

	// 多走一步，以保存上一个adjoin
	p = p->adjoin;
	while (p != 0 && p->id != id)
	{
		p = p->adjoin;
		q = q->adjoin;
	}
	
	if (p == 0)
	{
		printf("Error: Arc does not exist!\n");
		return 0;
	}
	else{
		q->adjoin = p->adjoin;
		free(p);
		return 1;
	}
}

// 删除一个节点下挂载的所有弧
void DeleteAllAdjoinNode(RealMap * rm, RMNode * node)
{
	RMNode * p;
	RMNode * q;
	q = p = node;

	// 多走一步，以保存上一个adjoin
	p = p->adjoin;
	while (p)
	{
		node->adjoin = p->adjoin;
		free(p);
		p = node->adjoin;
		rm->numArc--;
	}

}

// 删除一个单独的弧
void DeleteSignelArc(RealMap * rm, int src, int des)
{
	RMNode * tmp;

	// 判断是否存在
	if( !IfNodeExist(rm, src) || !IfNodeExist(rm, des))
	{
		printf("Error: Node does not exist!\n");
		return;
	}
	tmp = GetNode(rm, src);
	if(DeleteAdjoinNode(tmp, des))
		rm->numArc--;
}

// 删除一个弧，实质是删除两个节点中的所有联系
void DeleteArc(RealMap * rm, int src, int des)
{
	DeleteSignelArc(rm, src, des);
	DeleteSignelArc(rm, des, src);
}

// 处理附着在一个节点上的弧
void DeleteAttachArc(RealMap * rm, int id)
{
	RMNode * tmp;
	
	tmp = GetNode(rm, id);
	DeleteAllAdjoinNode(rm, tmp);
}

// 删除节点链中的该节点
void DeleteNodelist(RealMap * rm, int id)
{
	RMNode * p;
	RMNode * q;
	
	q= p = rm->first;
	while (p->id != id)
	{
		q = p;			
		p = p->next;
	}

	// 特殊处理第一个元素
	if(rm->first == p)
	{
		rm->first = p->next;
	}
	else{
		q->next = p->next;
	}
	
	free(p);
	rm->numNode--;
}

// 删除分散在其他节点中的弧
void DeleteDiscreteArc(RealMap * rm, int id)
{
	RMNode * tmp;
	tmp = rm->first;

	while(tmp)
	{
		if(DeleteAdjoinNode(tmp, id))
			rm->numArc--;

		tmp = tmp->next;
	}
	
}

// 删除一个节点
void DeleteNode(RealMap * rm, int id)
{
	// 判断是否存在
	if( !IfNodeExist(rm, id))
	{
		printf("Error: Node does not exist!\n");
		return;
	}
	DeleteAttachArc(rm, id);
	DeleteNodelist(rm, id);
	DeleteDiscreteArc(rm, id);
}

// 清空一个图
// 销毁一个图

// 输出图的所有节点
void PrintRMNode(RealMap * rm)
{
	RMNode * tmp;
	tmp = rm->first;
	// 判断是否第一个节点
	if(!tmp)
	{
		printf("The map is empty.\n");
	}
	else
	{
		printf("Total node: %d.\n", rm->numNode);
		while (tmp)
		{
			printf("The No. %d node value is %d.\n", tmp->id, tmp->value);
			tmp = tmp->next;
		}
		
	}
}

// 输出图的某一节点的弧
void PrintRMNodeArc(RMNode * node)
{
	int id = node->id;
	
	RMNode * tmp;
	tmp = node->adjoin;
	
	
	if(!tmp)
	{
		// 改节点后没有弧
	}
	else
	{
		while (tmp)
		{
			printf("Arc: No. %d -> No.%d\n", id, tmp->id);
			// 输出该链上的弧
			tmp = tmp->adjoin;
		}
		
	}
}

// 输出图的所有弧
void PrintRMArc(RealMap * rm)
{
	RMNode * tmp;
	tmp = rm->first;
	// 判断是否第一个节点
	if(!tmp)
	{
		printf("The map is empty.\n");
	}
	else
	{
		printf("Total Arc: %d.\n", rm->numArc);

		while (tmp)
		{
			PrintRMNodeArc(tmp);
			// 找输出下一个节点的弧
			tmp = tmp->next;
		}
		
	}
}

// 输出图
void PrintRM(RealMap * rm)
{
	PrintRMNode(rm);
	PrintRMArc(rm);
}

// 判断最短路径
// 判断是否联通
// 判断多少个域

void main()
{
	RealMap * rm = CreateRM();
	
	AddNode(rm, 1, 33);
	AddNode(rm, 2, 44);
	AddNode(rm, 3, 55);
	AddNode(rm, 4, 66);
	AddNode(rm, 5, 77);

	AddArc(rm, 2, 3, 41);
	AddArc(rm, 1, 3, 16);
	AddArc(rm, 1, 2, 78);
	AddArc(rm, 2, 1, 78);
	//AddArc(rm, 1, 7, 78);
	AddArc(rm, 1, 4, 78);
	AddArc(rm, 1, 4, 78);
	AddArc(rm, 1, 5, 78);
	AddArc(rm, 4, 5, 78);
	AddArc(rm, 3, 4, 78);
	AddArc(rm, 3, 1, 78);

	PrintRM(rm);

	//DeleteArc(rm, 1, 5);
	//DeleteArc(rm, 1, 2);
	//DeleteArc(rm, 1, 3);
	//DeleteArc(rm, 1, 7);

	DeleteNode(rm, 1);

	PrintRM(rm);
}
