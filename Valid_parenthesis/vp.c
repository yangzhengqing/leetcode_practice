/*================================================================
 *   Copyright (C) 2019 belonging to YangZhengQing. All rights reserved.
 *   
 *   文件名称：vp.c
 *   创 建 者：YangZhengQing
 *   创建日期：2019年12月15日
 *   描    述：检测有效的括号。利用单项链表和栈实现
 *
 *================================================================*/

#include "vp.h"

/*定义一个全局的链表节点*/
/*struct node
  {
  char c;
  struct node *next;
  }
 */
int main(int argc,char **argv)
{

	char s[5] = {'(','[',']',')'};
	bool re = is_valid(s);
	if(re == true)
	{
		printf("有效!\n");
	}
	else
	{
		printf("无效\n");
	}
	return 0;
}

/*压入栈*/
void push(node **head,char ch)
{
	node *ptr = (node *)malloc(sizeof(node *));
	if(ptr == NULL)
	{
		printf("push 分配内存失败\n");
	}

	ptr->c = ch;
	ptr->next = *head;
	*head = ptr;

}

/*弹出栈*/
void pop(node **head)
{
	node *temp = NULL;

	temp = *head;
	*head = temp->next;
	free(temp);
}

/*释放栈*/
void stack_free(node *head)
{
	node *temp = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("栈释放成功!\n");
}

/*检测输入的括号是否有效*/
bool is_valid(char *s)
{
	node *head = NULL;//头节点

	while(*s != 0)
	{
		if(head != NULL && (*s == (head->c) + 1 || *s == (head->c) + 2))//其中一对括号之间相差1或2
		{
			pop(&head);
		}

		else
		{
			push(&head,*s);
		}
		s++;
	}

	if(head == NULL)
	{
		return true;
	}
	else
	{
		stack_free(head);
		return false;
	}

}




/*方法二*/

bool isValid2(char * s)
{
	int i ;
	int top = 0;
	char *stack = (char *)malloc(strlen(s)+1);
	for(i = 0;s[i];i++)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			stack[top] = s[i];
			top++;
		}
		else
		{
			if(--top<0)return false;
			if(s[i] == '}' && stack[top] != '{')return false;
			if(s[i] == ']' && stack[top] != '[')return false;
			if(s[i] == ')' && stack[top] != '(')return false;
		}
	}
	free(stack);
	return (!top);
}
