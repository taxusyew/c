#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int InputLen(char * str)
{
	char * tmp = str;
	int count = 0;

	while(*tmp != 0)
	{
		count++;
		tmp++;
	}

	return count;
}
void main()
{
	int len;
	char * cInput;
	char * strHead;
	char * strTail;
	
	cInput = (char *) malloc(123);
	memset(cInput, 0, 123);

	scanf("%s", cInput);

	len = InputLen(cInput);
	strHead = cInput;
	strTail = strHead + len - 1;

	if(len == 0)
	{
		printf("��������Ϊ��");
	}
	while(*strHead == *strTail && strHead <= strTail)
	{
		strHead++;
		strTail--;
	}

	if (strHead >= strTail)
	{
		printf("�ǻ�����");
	}
	else
	{
		printf("�ǻ�����");
	}

	getchar();
}