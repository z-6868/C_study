#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> //malloc头文件 



int main()
{
	//动态分配40个字节的空间
	int * p = (int * )malloc(10*sizeof(int));//将 malloc 返回的(void *) 强制转换为 (int *)
	if (p == NULL)//如果未能开辟空间
	{
		perror(malloc);//输出错误信息。格式为“malloc + [错误信息]”
	}

	//给新开辟的空间赋值
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	


	free(p);//使用函数free释放空间（若该空间不是malloc开辟的 则 free 是无定义的） malloc 和  free 要成对使用。 
	//释放空间之后 p 会变成野指针
	p = NULL;//指针置为空

	return 0;
}