#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> //mallocͷ�ļ� 



int main()
{
	//��̬����40���ֽڵĿռ�
	int * p = (int * )malloc(10*sizeof(int));//�� malloc ���ص�(void *) ǿ��ת��Ϊ (int *)
	if (p == NULL)//���δ�ܿ��ٿռ�
	{
		perror(malloc);//���������Ϣ����ʽΪ��malloc + [������Ϣ]��
	}

	//���¿��ٵĿռ丳ֵ
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	


	free(p);//ʹ�ú���free�ͷſռ䣨���ÿռ䲻��malloc���ٵ� �� free ���޶���ģ� malloc ��  free Ҫ�ɶ�ʹ�á� 
	//�ͷſռ�֮�� p ����Ұָ��
	p = NULL;//ָ����Ϊ��

	return 0;
}