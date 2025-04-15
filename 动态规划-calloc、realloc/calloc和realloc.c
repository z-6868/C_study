#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//�� calloc ��ʼ�� ����40���ֽ�
	int* p = (int*)calloc(10, sizeof(int));

	//�ж��Ƿ�ɹ�����
	if (p == NULL)
	{
		perror(calloc);
	}

	//��ӡ �鿴��ʼ�����
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",*(p+i));
	}

	//�� realloc ���·���ռ�
	int* ptr = (int*)realloc(p, 80);

	//�ж��Ƿ�ɹ�����
	if (ptr == NULL)
	{
		perror(realloc);
	}
	p = ptr;


	//�� free �ͷſռ䡣
	free(p);
	p = NULL;

	return 0;
}
