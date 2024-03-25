#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkStack {
	char s[10];
	struct ListStack* next;
};

int flag = 0;

void InitStack(struct LinkStack**top)//初始化
{
	*top = NULL;
	flag = 1;
	printf("初始化成功！\n");
}

void PushStack(struct LinkStack** top, char* ch)//进栈
{
	struct LinkStack* p = NULL;
	p = (struct LinkStack*)malloc(sizeof(struct LinkStack));
	strcpy(&(p->s), ch);
	p->next = NULL;
	if (*top == NULL)
	{
		*top = p;
	}
	else
	{
		p->next = *top;
		*top = p;
	}
	printf("进栈成功！\n");
}

void PopStack(struct LinkStack** top)//出栈
{
	if (*top == NULL)
	{
		printf("已经是空栈！\n");
	}
	else
	{
		struct LinkStack* next = (*top)->next;
		free(*top);
		*top = next;
		printf("出栈成功！\n");
	}
}

void PrintStack(struct LinkStack* top)//打印
{
	if (top == NULL)
	{
		printf("为空栈！\n");
	}
	else
	{
		while (top)
		{
			printf("%s->", top->s);
			top = top->next;
		}
		printf("NULL\n");
	}
}

void DestroyStack(struct LinkStack** top)//销毁
{
	struct LinkStack* cur = *top;
	struct LinkStack* next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*top = NULL;
	flag = 0;
	printf("销毁成功！\n");
}

void EmptyStack(struct LinkStack* top)//判断是否为空
{
	if (top == NULL)
	{
		printf("空栈！\n");
	}
	else
	{
		printf("不为空栈！\n");
	}
}

void menu(void)
{
	printf("***************{栈的操作}*******************\n");
	printf("********1.初始化**********2.进栈************\n");
	printf("********3.出栈************4.打印************\n");
	printf("********5.判断空栈********6.销毁************\n");
	printf("******************7.退出********************\n");
}

int main()
{
	char a = 0;
	char s[100] = { 0 };
	struct LinkStack* top = NULL;
	do
	{
		menu();
		do
		{
			printf("请输入对应操作的数字:");
			scanf("%s",s);
			getchar();
			if (strlen(s) == 1)
			{
				a = s[0];
				if (a < '1' || a>'7')
				{
					printf("输入错误！\n");
				}
				else
					break;
			}
			else
			{
				printf("输入错误！\n");
			}
		} while (1);
		if (a == '1')
		{
			if (flag == 1)
			{
				printf("请先销毁！\n");
			}
			else
			{
				InitStack(&top);
			}
		}
		else if (a == '2')
		{
			if (flag == 0)
			{
				printf("请先初始化！\n");
			}
			else
			{
				char ch[100] = { 0 };
				do
				{
					printf("请输入字符串(小于10):");
					gets(ch);
					if (strlen(ch) < 10)
					{
						PushStack(&top, ch);
						break;
					}
					else
					{
						printf("输入错误！\n");
					}
				} while (1);
			}
		}
		else if (a == '3')
		{
			if (flag == 0)
			{
				printf("请先初始化！\n");
			}
			else
			{
				PopStack(&top);
			}
		}
		else if (a == '4')
		{
			if (flag == 0)
			{
				printf("请先初始化！\n");
			}
			else
			{
				PrintStack(top);
			}
		}
		else if (a == '5')
		{
			if (flag == 0)
			{
				printf("请先初始化！\n");
			}
			else
			{
				EmptyStack(top);
			}
		}
		else if (a == '6')
		{
			if (flag == 0)
			{
				printf("请先初始化！\n");
			}
			else
			{
				DestroyStack(&top);
			}
		}
		else if (a == '7')
		{
			break;
		}
	} while (1);
	return 0;
}