#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//用 calloc 初始化 开辟40个字节
	int* p = (int*)calloc(10, sizeof(int));

	//判断是否成功开辟
	if (p == NULL)
	{
		perror(calloc);
	}

	//打印 查看初始化情况
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",*(p+i));
	}

	//用 realloc 重新分配空间
	int* ptr = (int*)realloc(p, 80);

	//判断是否成功分配
	if (ptr == NULL)
	{
		perror(realloc);
	}
	p = ptr;


	//用 free 释放空间。
	free(p);
	p = NULL;

	return 0;
}
