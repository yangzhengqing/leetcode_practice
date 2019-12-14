/*================================================================
*   Copyright (C) 2019 belonging to YangZhengQing. All rights reserved.
*   
*   文件名称：lcp.c
*   创 建 者：YangZhengQing
*   创建日期：2019年12月14日
*   描    述：最长公共前缀
*
*================================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "lcp.h"

int main(int argc,char *argv)
{
	char *str[] = {"flower","flow","flight"};
	char *re_cp;
	int strsSize = sizeof(str)/sizeof(str[0]);
	
	re_cp = longestCommonPrefix(str,strsSize);
	if(re_cp == NULL)
	{
		printf("字符串不存在!\n");
	}
	else
	{
		printf("公共前缀为:%s\n",re_cp);
		free(re_cp);
	}
	return 0;
}

/*
   功能：计算出最长的公共前缀
*/
char *longestCommonPrefix(char **strs, int strsSize)
{
	char *cp = (char *)malloc(10);//保存公共前缀
	int cp_count;//公共前缀的个数
	char *current_str;//向后移动的指针
	int i,j;

	//cp = strs[0];//将第一个字符串作为首个公共前缀，后面一次去掉不是公共的字符
	strcpy(cp,strs[0]);
	cp_count = strlen(cp);
	if(strsSize == 0)
	{
		return NULL;
	}
	else
	{
		for(i = 0;i < 3;i++)
		{
			current_str = strs[i];//取出一个字符串
			for(j = 0;j < cp_count;j++)//再逐个字符比较
			{
				if(cp[j] != current_str[j])//当出现首个不等的字符时跳出此循环,记下下标作为此时公共前缀的个数
				{
					break;
				}
				
			}

			cp_count = j ;
			cp[j] = '\0';
			
		}
		return cp;

	}
	
}
