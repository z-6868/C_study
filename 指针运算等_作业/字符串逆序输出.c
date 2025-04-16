//#define _crt_secure_no_warnings 1
//#include <stdio.h>
//
//
//int main()
//{
//	char s1[999];
//	int  count = 0;//统计输入字符数
//	while ( (s1[count] = getchar()) != '\n')//读取输入后依次放入s1
//	{
//		count++;
//	}
//
//    int right = count - 1;
//    int left = 0;
//
//	while (left < right)
//	{
//		char temp;
//		temp = s1[left];
//		s1[left] = s1[right];
//		s1[right] = temp;
//		left++;
//		right--;
//	}
//	
//	for (int i = 0; i < count; i++)
//	{
//		printf("%c", s1[i]);
//	}
//
//	return 0;
//}