#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//初始化数组
void initBoard(char board[][COLUMN + 2], int raw, int column,char set)
{
	//全部为字符set
	int i = 0;
	for ( i = 0; i < raw; i++)
	{
		int j = 0;
		for ( j = 0; j < column; j++)
		{
			board[i][j] = set;
		}
	}
}
//雷化真实数组
void SetMine(char realboard[][COLUMN + 2], int raw, int column)
{
	//随机10个坐标为'1'
	int x = 0;
	int y = 0;
	int i = MINE;
	while (i)
	{
		x= rand() % (ROW - 1) + 1;
		y = rand() % (COLUMN - 1) + 1;
		//如果(x,y)没添加过,则添加该雷坐标
		if (realboard[x][y]=='0')
		{
		realboard[x][y] = '1';
			i--;
		}
	}
}
void displayBoard(char board[][COLUMN + 2], int row, int column)
{
	int i = 0;
	//打印行号
	printf("%c%c", ' ', ' ');
	for ( i = 1; i < column-1; i++)
	{
		printf("%c%d%c%c",' ', i,' ',' ');
	}
	printf("\n");
	//打印一行及分隔行
	for (i = 1; i < row - 1;i++) 
	{
		printf("%d%c", i,' ');
		int j = 0;
		for (j = 1; j < column - 1; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != column - 2)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i!=row-2)
		{
			printf("%c%c", ' ',' ');
			for ( j = 1; j < column-1; j++)
			{
				printf("---");
				if (j!=column-2)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
int findMine(int i,int j,char board[][COLUMN + 2], char realboard[][COLUMN + 2], int row, int column,int* count)
{
	//隐藏坐标被扫到直接返回-1,继续
	if (i==0||i==row-1||j==0||j==column-1)
	{
		return -1;
	}
	//确认没踩雷
	if (realboard[i][j]=='0')
	{
	//查看realbo上该坐标周围元素含雷数,写入board上的该坐标处
	int sum = 0;
	int m = 0;
		int n = 0;
	for ( m = i-1; m < i+2; m++)
	{
		for ( n = j-1; n < j+2; n++)
		{
			sum += realboard[m][n]-'0';
		}
	}
	board[i][j] = sum+'0';
	(*count)++;
	//如果扫到'0',把周围扫完
	if (board[i][j]=='0')
	{
		for ( m = i-1; m < i+2; m++)
		{
			for ( n = j-1; n < j+2; n++)
			{
				if (board[m][n]==' ')
				{

				findMine(m, n, board, realboard, row , column,count);
				}
			}
		}
		
	}
	return -1;
	}
	//不幸踩雷
	else
	{
		board[i][j] = '*';
		return 0;
	}
}
