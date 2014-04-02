#include "stdio.h"


int Board[4][4];

// ��ʼ������
void InitBoard()
{
	int j;
	int i;

	for( i = 0; i<4; i++)
		for ( j = 0; j < 4; j++)
			Board[i][j] = 0;
}

// �жϸ�λ���Ƿ����
int CanPlace(int row, int col)
{
	int i,j;
	int tmp_row = row;
	int tmp_col = col;

	// ����
	for(i = 0; i < 4; i++)
		if ( (Board[row][i] != 0) && (col != i))
			return 0;
		
	// ����
	for(i = 0; i < 4; i++)
		if ( (Board[i][col] != 0) && (row != i))
			return 0;

	// ���Ͻ�
	for(i = row-1, j=col -1; i >=0 && j >= 0; i--, j--)
		if (Board[i][j] != 0)
			return 0;

	// ���½�
	for(i = row+1, j=col -1; i <=3 && j >= 0; i++, j--)
		if (Board[i][j] != 0)
			return 0;

	// ���Ͻ�
	for(i = row-1, j=col + 1; i >=0 && j <= 3; i--, j++)
		if (Board[i][j] != 0)
			return 0;

	// ���½�
	for(i = row+1, j=col + 1; i <=3 && j <= 3; i++, j++)
		if (Board[i][j] != 0)
			return 0;

	return 1;
}

// ѭ���ж�Ѱ�ҽ�
void GetResult()
{
	int j;
	int i;

	for( i = 0; i<4; i++)
		for ( j = 0; j < 4; j++)
			if( CanPlace(i,j) )
				Board[i][j] = 1;
}

// �����������
void PrintBoard()
{
	int j;
	int i;

	for( i = 0; i<4; i++)
	{
		for ( j = 0; j < 4; j++)
			printf("%2d", Board[i][j]);
		printf("\n");
	}
	printf("\n");
	getchar();
	
}

void main()
{
	Board[0][2] = 1;
	GetResult();
	PrintBoard();
}