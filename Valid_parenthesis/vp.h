/*================================================================
*   Copyright (C) 2019 belonging to YangZhengQing. All rights reserved.
*   
*   文件名称：vp.h
*   创 建 者：YangZhengQing
*   创建日期：2019年12月15日
*   描    述：
*
*================================================================*/
#ifndef _VP_H_
#define _VP_H_

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"

/**/
typedef struct linked
{
	char c;
	struct linked *next;
}node;

void push(node **head,char ch);
void pop(node **head);
void stack_free(node *head);
bool is_valid(char *s);


#endif
