#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
	int value;
	struct LinkList * next;
}LinkList;

//	����linklist�б�
LinkList * CreatLinkList()
{
	LinkList * ll = (LinkList *)malloc(sizeof(LinkList));
	ll->value = 0;
	ll->next = NULL;

	return ll;
}

// ����linklist
// β�巨
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

// ɾ���ڵ�
void DeleLinkList(LinkList * ll, int value)
{
	LinkList * temp = ll;
	LinkList * p = ll;
	while((temp->value != value) && (temp->next != NULL))
	{
		p = temp;
		temp = temp->next;
	}
	// ������һ������Ҫ�ҵ�Ԫ��
	if((temp->value != value) && (temp->next == NULL))
	{
		printf("û�и���");
		return;
	}

	// �ҵ����Ԫ�أ��������м䣬Ҳ��������β
	if(temp->value == value)
	{
		p->next = temp->next;
		free(temp);
	}
}

// ����б�
// ֻʣ�µ�һ���ڵ�
void EmptyLinkList(LinkList * ll)
{
	LinkList * temp = ll;
	LinkList * p = ll;

	// ���������ֻ��һ��Ԫ��
	if(temp->next != NULL)
	{
		temp = temp->next;
		p->next = NULL;
	}
	else{
		return;
	}

	// �ȶϿ���һ���ڵ�ͺ��������
	// ��һ��һ����ͷ���
	while(temp->next != NULL)
	{
		p = temp;
		temp = temp->next;
		free(p);
	}
	free(temp);
}

// �����б�
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
	// ��ӡ���ʣ���һ��cell
	printf("%d\t", temp->value);

	printf("\n");
}

int main()
{
	LinkList * ll = CreatLinkList();
	PrintLinkList(ll);

	// ����һ��Ԫ��
	InsertLinkList(ll, 10);
	PrintLinkList(ll);

	// ɾ��һ��Ԫ��
	DeleLinkList(ll, 10);
	PrintLinkList(ll);

	InsertLinkList(ll, 10);
	InsertLinkList(ll, 20);
	InsertLinkList(ll, 30);
	InsertLinkList(ll, 40);
	PrintLinkList(ll);

	// ���
	EmptyLinkList(ll);
	PrintLinkList(ll);

	// ����
	//DestoryLinkList(ll);

	return 0;
}