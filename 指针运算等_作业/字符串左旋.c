#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char S1[] = "ABCD";


	printf(S1);
	printf("\n");

	int  count = 4;//统计输入字符数

	//左旋k个字符
	int k = 0;
	scanf("%d", &k);

	//while ((S1[count] = getchar()) != '\n')//读取输入后依次放入S1
	//{
	//	count++;
	//}

	while (k--)
	{
		char first_temp = S1[0];//储存第一个
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
				S1[i] = first_temp;
			else
			    S1[i] = S1[i + 1];//每个位置的字符 用它后一个 字符替代
		}
		first_temp = S1[0];//重新储存第一个
	}

	//打印
	for (int i = 0; i < count; i++)
	{
		printf("%c", S1[i]);
	}

	return 0;
}