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

// ´´½¨ÎÞÏòÍ¼
// ½Úµã´Ó0¿ªÊ¼
// ½ÚµãÊýÎªnodeNum
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

// ²åÈë»¡
// Æðµãsrc£¬ÖÕµãdes
void InsertArc(DiGraph * dg, int src, int des)
{
	// Èç¹û¸Õ¿ªÊ¼»ñµÃ½ÚµãÊý×éµÄdg->vexList[src].next,ÄÇÃ´ÉÔºó»áÒòÎª¶à³öÒ»¸önext¶ø²Ù×÷0x0000µØÖ·µÄÄÚÈÝ
	// ËùÒÔÓ¦¸ÃÏÈµÃµ½Ò»´Î½Úµã£¬µ«ÊÇÖ»ÄÃµ½½Úµã»¹ÊÇ²»ÄÜÏòºóËÑË÷Á´±í£¬ËùÒÔÔÙ°Ñ½ÚµãµÄnext»º´æÒ»ÏÂ£¬µÈÏÂÓÃËü±éÀúÁ´±í
	// µ«ÊÇ»áÓöµ½µÚÒ»¸ö½ÚµãµÄÌØÊâÎÊÌâ£¬Èç¹ûµÚÒ»¸ö¾ÍÊÇ¿Õ£¬ÄÇÃ´¾Í²»ÓÃ±éÀú£¬Ö±½Ó¸²¸Ç¸¸½ÚµãµÄnext
	// Èç¹ûµÚÒ»¸ö²»Îª¿Õ£¬ÄÇÃ´¸¸½ÚµãµÄ±íÊ¾·½·¨¾Í»á´Óvex±äÎªvexp£¬Ã»°ì·¨Í³Ò»£¬ËùÒÔµ¥ÁÐ³öÀ´
	// Òª³É¹¦²åÈëÒ»¸ö»¡£¬Ö÷ÒªÃ¬¶Ü¾ÍÊÇ½á¹¹ÌåÊý×éµÄ³ÉÔ±vex²»ÄÜÏñÖ¸ÕëÒ»Ñù++£¬¶ø²åÈënextÇøÓòÐèÒªµÃµ½¸¸¼¶£¨ËùÔÚcell£©µÄµØÖ·
	// ¼´Òª±£´æ°ü¹ücellµÄµØÖ·£¬ËùÒÔ²úÉúÃ¬¶Ü
	Vex * vex = dg->vexList+src;
	//Vex * vexp = vex.next;
	Vex * temp = (Vex * )malloc(sizeof(Vex));
	temp->Vexs = des;
	temp->next = NULL;

	// ÅÐ¶ÏµÚÒ»¸ö½ÚµãÊÇ·ñÎª¿Õ
	//if(vex.next == NULL)
	//{
	//	vex.next = temp;
	//	return;
	//}

	// ÀàËÆµ¥Á´±í²åÈë
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
