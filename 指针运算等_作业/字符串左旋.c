#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char S1[] = "ABCD";


	printf(S1);
	printf("\n");

	int  count = 4;//ͳ�������ַ���

	//����k���ַ�
	int k = 0;
	scanf("%d", &k);

	//while ((S1[count] = getchar()) != '\n')//��ȡ��������η���S1
	//{
	//	count++;
	//}

	while (k--)
	{
		char first_temp = S1[0];//�����һ��
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
				S1[i] = first_temp;
			else
			    S1[i] = S1[i + 1];//ÿ��λ�õ��ַ� ������һ�� �ַ����
		}
		first_temp = S1[0];//���´����һ��
	}

	//��ӡ
	for (int i = 0; i < count; i++)
	{
		printf("%c", S1[i]);
	}

	return 0;
}