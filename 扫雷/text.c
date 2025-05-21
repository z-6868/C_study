#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//测试游戏的主逻辑
void menu()
{
	printf("******************************\n");
	printf("**********  1.strat **********\n");
	printf("**********  0.exit  **********\n");
	printf("******************************\n");
}

//完成扫雷游戏的测试
void game()
{
	char mine[ROWS][COLS] = { 0 };//储存布置好的雷的信息---"0"
	char show[ROWS][COLS] = { 0 };//储存排查出的雷的信息---"*"

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	SetMine(mine, ROW, COL);


	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);


	//排查雷
	FindMine(mine,show,ROWS,COLS);
}
	


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷开始！\n");
			game();
			break;
		case 0:
			printf("已退出游戏！\n");
			break;
		default: 
			printf("请重新选择！\n");  
			break;
		}

	} while (input);
}