#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
	int value;
	struct LinkList * next;
}LinkList;

//	创建linklist列表
LinkList * CreatLinkList()
{
	LinkList * ll = (LinkList *)malloc(sizeof(LinkList));
	ll->value = 0;
	ll->next = NULL;

	return ll;
}

// 插入linklist
// 尾插法
void InsertLinkList(LinkList * ll, int value)
{
	
	LinkList * temp = ll;
	LinkList * p = (LinkList *)malloc(sizeof(LinkList));
	
	while(temp->next != NULL)
	{
		temp = temp->next;	
	}
	
	p->value = value;
	p->next = NULL;

	temp->next = p;
		
}

// 删除节点
void DeleLinkList(LinkList * ll, int value)
{
	LinkList * temp = ll;
	LinkList * p = ll;
	while((temp->value != value) && (temp->next != NULL))
	{
		p = temp;
		temp = temp->next;
	}
	// 如果最后一个不是要找的元素
	if((temp->value != value) && (temp->next == NULL))
	{
		printf("没有该项");
		return;
	}

	// 找到这个元素，可能是中间，也可能是链尾
	if(temp->value == value)
	{
		p->next = temp->next;
		free(temp);
	}
}

// 清空列表
// 只剩下第一个节点
void EmptyLinkList(LinkList * ll)
{
	LinkList * temp = ll;
	LinkList * p = ll;

	// 如果链表不是只有一个元素
	if(temp->next != NULL)
	{
		temp = temp->next;
		p->next = NULL;
	}
	else{
		return;
	}

	// 先断开第一个节点和后面的链接
	// 再一个一个从头清空
	while(temp->next != NULL)
	{
		p = temp;
		temp = temp->next;
		free(p);
	}
	free(temp);
}

// 销毁列表
void DestoryLinkList(LinkList * ll)
{
	EmptyLinkList(ll);
	free(ll);
}

void PrintLinkList(LinkList * ll)
{
	LinkList * temp = ll;

	while (temp->next != NULL)
	{
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	// 打印最后剩余的一个cell
	printf("%d\t", temp->value);

	printf("\n");
}

int main()
{
	LinkList * ll = CreatLinkList();
	PrintLinkList(ll);

	// 插入一个元素
	InsertLinkList(ll, 10);
	PrintLinkList(ll);

	// 删除一个元素
	DeleLinkList(ll, 10);
	PrintLinkList(ll);

	InsertLinkList(ll, 10);
	InsertLinkList(ll, 20);
	InsertLinkList(ll, 30);
	InsertLinkList(ll, 40);
	PrintLinkList(ll);

	// 清空
	EmptyLinkList(ll);
	PrintLinkList(ll);

	// 销毁
	//DestoryLinkList(ll);

	return 0;
}