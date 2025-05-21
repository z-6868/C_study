#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Count_Mine 10

//游戏实现的逻辑 -- 函数的声明


//初始化棋盘
void  InitBoard(char arr[ROWS][COLS],int rows,int cols,char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);