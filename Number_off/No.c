/*================================================================
 *   Copyright (C) 2019 belonging to YangZhengQing. All rights reserved.
 *   
 *   文件名称：No.c
 *   创 建 者：YangZhengQing
 *   创建日期：2019年12月19日
 *   描    述：尾递归,如果一个函数中所有递归形式的调用都出现在函数的末尾，
 *			   我们称这个递归函数是尾递归的
 *
 *================================================================*/


#include "No.h"


int main(int argc,int argv)
{

	printf("报数：%s\n",countAndSay(4));
	return 0;

}

/*递归报数*/
char * number_off(char *str,int n)
{
	int count;//相同字符的个数
	char ch[10000];//报str的数，然后暂存到ch中
	char *ptr = ch;

	memset(ch,0,sizeof(ch));

	if(n == 1)
	{
		return str;
	}

	while(*str != '\0')//从左到右读str，至到最后一个字符
	{
		count = 1;

		while(*str == *(str+1))//相同字符
		{
			count++;
			str++;
		}

		*ptr++ = (count + '0');//int型转换为char型，存入缓存ch中

		*ptr++ = *str++;//将str里的原来的字符存到缓存ch中
	}
	return number_off(ch,n-1);//递归调用，直到n=1时返回&ch
}



char * countAndSay(int n)
{

	return number_off("1",n);

}

