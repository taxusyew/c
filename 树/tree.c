#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int value;
	struct node * lc;
	struct node * rc;

}Node;

/**
 * 插入节点
 * pre = 父节点,me = 现在节点
 */
int insertTree(Node * pre, Node * me)
{
	// 找父节点
	if(me->value > pre->value)
	{
		// 如果大于父节点，且父节点的右子树为空，则就地插入右子树
		if(pre->rc == NULL)
		{
			pre->rc = me;
			return 1;
		}
		else{
			insertTree(pre->rc, me);
		}
	}
	else if(me->value < pre->value){
		// 如果小于父节点，且父节点的左子树为空，则就地插入左子树
		if(pre->lc == NULL)
		{
			pre->lc = me;
			return 1;
		}
		else{
			insertTree(pre->lc, me);
		}
	}
}

/**
 * 先序遍历
 * @return
 */
int AFS(Node * tree)
{
	printf("%d  ", tree->value);
	if(tree->lc != NULL)
		AFS(tree->lc);
	
	if (tree->rc != NULL)
	{
		AFS(tree->rc);
	}
	return 1;
}

/**
 * 中序遍历
 */
int BFS(Node * tree)
{
	if(tree->lc != NULL)
		BFS(tree->lc);
	printf("%d  ", tree->value);
	if (tree->rc != NULL)
	{
		BFS(tree->rc);
	}
	return 1;
}

/**
 * 后序遍历
 * @return
 */
int CFS(Node * tree)
{
	if(tree->lc != NULL)
		CFS(tree->lc);
	
	if (tree->rc != NULL)
	{
		CFS(tree->rc);
	}
	printf("%d  ", tree->value);
	return 1;
}

/*
* 删除树
* 
*/
int destory(Node * tree)
{
	if(tree->lc != NULL)
		destory(tree->lc);
	
	if (tree->rc != NULL)
	{
		destory(tree->rc);
	}
	free(tree);

	return 1;
}
int main()
{
	Node * tree = (Node *)malloc(sizeof(Node));

	int value = 0;
	
	scanf("%d",&value);
	
	tree->lc = NULL;
	tree->rc = NULL;
	tree->value = value;
	

	while (scanf("%d",&value) && value != 999)
	{
		Node * temp = (Node *)malloc(sizeof(Node));
		temp->value = value;
		temp->lc = NULL;
		temp->rc = NULL;

		insertTree(tree, temp);
	}

	printf("中序遍历：");
	BFS(tree);
	printf("\n");

	printf("先序遍历：");
	AFS(tree);
	printf("\n");

	printf("后序遍历：");
	CFS(tree);
	printf("\n");
	
	destory(tree);
	
	return 1;
}