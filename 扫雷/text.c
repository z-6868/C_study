#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//������Ϸ�����߼�
void menu()
{
	printf("******************************\n");
	printf("**********  1.strat **********\n");
	printf("**********  0.exit  **********\n");
	printf("******************************\n");
}

//���ɨ����Ϸ�Ĳ���
void game()
{
	char mine[ROWS][COLS] = { 0 };//���沼�úõ��׵���Ϣ---"0"
	char show[ROWS][COLS] = { 0 };//�����Ų�����׵���Ϣ---"*"

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);


	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);


	//�Ų���
	FindMine(mine,show,ROWS,COLS);
}
	


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ�׿�ʼ��\n");
			game();
			break;
		case 0:
			printf("���˳���Ϸ��\n");
			break;
		default: 
			printf("������ѡ��\n");  
			break;
		}

	} while (input);
}