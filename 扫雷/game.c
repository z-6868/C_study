#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��Ϸʵ�ֵ��߼� -- ������ʵ��

//��ʼ������
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


//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//����
	printf("--------------------\n");
	//��ӡ������
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//�������̴�ӡ
	for (i = 1; i <= col; i++)
	{
		//��ӡ������
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	} 
	//����
	printf("--------------------\n");
}

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//���貼�õ�����Ŀ
	int count = Count_Mine;
	
	while (count)
	{

		//��������� x y
		int x = rand() % row + 1;//1-row
		int y = rand() % col + 1;

		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//ͳ���׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	//�����ԣ�x,y��Ϊ���ĵľŹ���
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

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	//����Ҫ�Ų��λ��
	int x, y;
	while (1)
	{
		printf("������Ҫ�Ų��λ�ã�");
		scanf("%d %d", &x, &y);
		//�ж�����λ���Ƿ���Ч
		if (x > 0 && x < rows && y>0 && y < cols)
		{
			//�жϸ�λ���Ƿ�Ϊ��
			if (mine[x][y] == '0')
			{
				//ͳ����Χ���׵ĸ��� �� ���� show[][] ��
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';
				//printf("%c \n", show[x][y]);
				DisplayBoard(show, ROW, COL);
			}
			else
			{
				printf("�㱻ը���ˣ���Ϸ������\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("��ȷ������ĺ�������Ϊ 1-9 \n");
		}
	}

}