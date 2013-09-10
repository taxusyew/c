#include "stdio.h"

typedef struct node
{
	int value;
	struct node * lc;
	struct node * rc;

}Node;

/**
 * 生成树
 * @return
 */
Node genTree()
{
	// 根据输入输入数字插入树中
	int c;
	Node t;
	t.lc = null;
	t.rc = null;
	t.value = 0;

	while(c != '#')
	{
		getc(&c);
		insertTree(t, c);
	}
	printTree();
}

/**
 * 插入节点
 * t=现在节点，pre=父节点，c=值
 */
insertTree(Node t, Node pre, int c)
{

	// 找到节点，开始插入
	if(t.value == null)
	{
		Node tmp = (Node *)malloc(sizeof(Node));
		tmp.value = c;
		tmp.lc = null;
		tmp.rc = null;
		if(c > pre.value)
		{
			pre.rc = tmp;
		}
		pre.lc = tmp;

	}
	// 找父节点
	if(c > t.value))
	{
		insertTree(t.rc, t, c)
	}
	else if(c < t.value){
		insertTree(t.lc, t, c)
	}

	// 开始插入
	
}

/**
 * 先序遍历
 * @return
 */
Node AFS()
{

}

/**
 * 中序遍历
 */
Node BFS()
{

}

/**
 * 后序遍历
 * @return
 */
Node CFS()
{

}
int main()
{

	return 1;
}