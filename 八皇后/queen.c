#include "stdio.h"


int Board[4][4];

// 初始化棋盘
void InitBoard()
{
	int j;
	int i;

	for( i = 0; i<4; i++)
		for ( j = 0; j < 4; j++)
			Board[i][j] = 0;
}

// 判断该位置是否可行
int CanPlace(int row, int col)
{
	int i,j;
	int tmp_row = row;
	int tmp_col = col;

	// 该行
	for(i = 0; i < 4; i++)
		if ( (Board[row][i] != 0) && (col != i))
			return 0;
		
	// 该列
	for(i = 0; i < 4; i++)
		if ( (Board[i][col] != 0) && (row != i))
			return 0;

	// 左上角
	for(i = row-1, j=col -1; i >=0 && j >= 0; i--, j--)
		if (Board[i][j] != 0)
			return 0;

	// 左下角
	for(i = row+1, j=col -1; i <=3 && j >= 0; i++, j--)
		if (Board[i][j] != 0)
			return 0;

	// 右上角
	for(i = row-1, j=col + 1; i >=0 && j <= 3; i--, j++)
		if (Board[i][j] != 0)
			return 0;

	// 右下角
	for(i = row+1, j=col + 1; i <=3 && j <= 3; i++, j++)
		if (Board[i][j] != 0)
			return 0;

	return 1;
}

// 循环判断寻找解
void GetResult()
{
	int j;
	int i;

	for( i = 0; i<4; i++)
		for ( j = 0; j < 4; j++)
			if( CanPlace(i,j) )
				Board[i][j] = 1;
}

// 输出可行棋盘
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