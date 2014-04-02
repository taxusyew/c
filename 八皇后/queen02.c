#include "stdio.h"

// 计算任何n皇后问题，修改下列值即可
int BoardRow = 8;
int Board[8][8];

// 记录一共找到了多少个解
int count = 0;

// 初始化棋盘
void InitBoard()
{
	int j;
	int i;

	for( i = 0; i<BoardRow; i++)
		for ( j = 0; j < BoardRow; j++)
			Board[i][j] = 0;
}

// 清空一行
void InitRow(int row)
{
	int k;
	for(k=0; k < BoardRow; k++)
		Board[row][k] = 0;
}

// 判断该位置是否可行
int CanPlace(int row, int col)
{
	int i,j;
	
	// 该行
	for(i = 0; i < BoardRow; i++)
		if ( (Board[row][i] != 0) && (col != i))
			return 0;

	// 该列
	for(i = 0; i < BoardRow; i++)
		if ( (Board[i][col] != 0) && (row != i))
			return 0;

	// 左上角
	for(i = row-1, j=col -1; i >=0 && j >= 0; i--, j--)
		if (Board[i][j] != 0)
			return 0;

	// 左下角
	for(i = row+1, j=col -1; i < BoardRow && j >= 0; i++, j--)
		if (Board[i][j] != 0)
			return 0;

	// 右上角
	for(i = row-1, j=col + 1; i >=0 && j < BoardRow; i--, j++)
		if (Board[i][j] != 0)
			return 0;

	// 右下角
	for(i = row+1, j=col + 1; i < BoardRow && j < BoardRow; i++, j++)
		if (Board[i][j] != 0)
			return 0;

	return 1;
}

// 输出可行棋盘
void PrintBoard()
{
	int j;
	int i;

	for( i = 0; i < BoardRow; i++)
	{
		for ( j = 0; j < BoardRow; j++)
			printf("%2d", Board[i][j]);
		printf("\n");
	}
	printf("\n");
	
}

// 循环判断寻找解
void GetResult(int row, int col)
{
	int j;
	int i;
	
	// 解空间到底,返回
	if(row == BoardRow)
	{
		PrintBoard();
		count++;
		return;
	}

	for( i = row; i < BoardRow; i++)
		for ( j = 0; j < BoardRow; j++)
		{
			// 每一列中找可行的
			if( CanPlace(i, j) )
			{
				Board[i][j] = 1;
				// 如果可以，进入下一层
				GetResult(row+1, 0);
				// 如果能从这个地方放回，说明已经找到一个解，清除本行，从这个地方再开始找
				InitRow(row);
			}
			
			// 到了最后一列也没有，该分支无解
			if (j == BoardRow -1)
			{
				// 上一行清零
				InitRow(row-1);

				// 剪裁该分支一个返回
				return;
			}
		}
}



void main()
{
	GetResult(0,0);
	printf("---- Total: %d ----", count);
	getchar();
}
