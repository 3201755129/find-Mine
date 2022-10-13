#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("欢迎来到扫雷\n");
	printf("选1开始游戏,选0退出游戏,请选择:>\n");
}
void game()
{
	int count = 0;
	char realboard[ROWS][COLS] = { 0 };
	char board[ROWS][COLS] = { 0 };
	int result = -1;
	initBoard(board, ROWS, COLS,' ');
	initBoard(realboard, ROWS, COLS, '0');
	SetMine(realboard, ROWS, COLS);
	displayBoard(board, ROWS, COLS);
	do
	{
		int i = 0;
		int j = 0;

		printf("请输入坐标(第i行,第j个):(i j)>\n");
		scanf("%d%d", &i, &j);
		//坐标合法
		if (i<1||i>ROW||j<1||j>COLUMN)
		{
			printf("输入的坐标超过可选范围,请重新输入\n");
			continue;
		}
		//坐标为空
		if (board[i][j]!=' ')
		{
			printf("该坐标已被扫过,请重新选择坐标\n");
			continue;
		}
		//清空录入缓冲区
		while (getchar() != '\n')
		{}
		//对坐标进行扫雷
		result=findMine(i,j,board,realboard, ROWS, COLS,&count);
		displayBoard(board, ROWS, COLS);
		//displayBoard(realboard, ROWS, COLS);
		//对扫雷结果进行处理
		if (result==0)
		{
			printf("你输了\n");
			displayBoard(realboard, ROWS, COLS);
		}
		//查看屏幕已扫的格子个数
		//如果屏幕上只剩雷
		else if (count == ROW * COLUMN - MINE)
		{
			printf("你赢了\n");
			result = 1;
		}
	} while (result==-1);
}
void test()
{
	srand((unsigned int)time(NULL));
		int option = 0;
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &option);
		//清空录入缓冲区
		while (getchar() != '\n')
		{}
		if (1==option)
		{
			game();
		}
		else if(0==option)
		{
			printf("退出成功\n");
		}
		else
		{
			printf("选择错误,请重新选择\n");
		}
	} while (option);
}

int main()
{
	test();
	return 0;
}