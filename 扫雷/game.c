#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//游戏实现的逻辑 -- 函数的实现

//初始化棋盘
void  InitBoard(char arr[ROWS][COLS], int rows, int cols, char set) 
{
	int i, j;
	for (i = 1; i < cols; i++)
	{
		for (j = 1; j < rows; j++)
		{
			arr[i][j] = set;
		}
	}

}


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//横线
	printf("--------------------\n");
	//打印横坐标
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//遍历棋盘打印
	for (i = 1; i <= col; i++)
	{
		//打印纵坐标
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	} 
	//横线
	printf("--------------------\n");
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//还需布置的雷数目
	int count = Count_Mine;
	
	while (count)
	{

		//生成随机数 x y
		int x = rand() % row + 1;//1-row
		int y = rand() % col + 1;

		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//统计雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	//遍历以（x,y）为中心的九宫格
	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			count += mine[x+m][y+n] - '0';
		}
	}
	//printf("%d\n", count);
	return count;
	//return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x -1][y + 1] + mine[x][y - 1] +
 mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8*'0';
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	//输入要排查的位置
	int x, y;
	while (1)
	{
		printf("请输入要排查的位置：");
		scanf("%d %d", &x, &y);
		//判断输入位置是否有效
		if (x > 0 && x < rows && y>0 && y < cols)
		{
			//判断该位置是否为雷
			if (mine[x][y] == '0')
			{
				//统计周围的雷的个数 并 存入 show[][] 中
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';
				//printf("%c \n", show[x][y]);
				DisplayBoard(show, ROW, COL);
			}
			else
			{
				printf("你被炸死了！游戏结束！\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("请确保输入的横纵坐标为 1-9 \n");
		}
	}

}