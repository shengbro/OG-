#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode {
	char s[10];
	struct LinkNode* next;
};

struct LinkQueue {
	struct LinkNode* front, * rear;
};

int flag = 0;

void InitQueue(struct LinkQueue** Q)//初始化队列
{
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	flag = 1;
	printf("初始化成功！\n");
}

void EnQueue(struct LinkQueue** Q, char* ch)//进队
{
	struct LinkNode* p = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	strcpy(&p->s, ch);
	p->next = NULL;
	if ((*Q)->front == NULL)
	{
		(*Q)->front = (*Q)->rear = p;
	}
	else
	{
		(*Q)->rear->next = p;
		(*Q)->rear = p;
	}
	printf("入队成功！\n");
}

void DeQueue(struct LinkQueue** Q)//出队
{
	if ((*Q)->front == NULL)
	{
		printf("已经为空队列！\n");
	}
	else
	{
		struct LinkNode* p = (*Q)->front;
		(*Q)->front = p->next;
		if ((*Q)->rear == p)
		{
			(*Q)->front = NULL;
			(*Q)->rear = NULL;
		}
		free(p);
		printf("出队成功！\n");
	}
}

void PrintQueue(struct LinkQueue* Q)//打印队列
{
	if (Q->front == NULL)
	{
		printf("队列为空！\n");
	}
	else
	{
		struct LinkNode* p = Q->front;
		while (p)
		{
			printf("%s->", p->s);
			p = p->next;
		}
		printf("NULL\n");
	}
}

void DestroyQueue(struct LinkQueue** Q)//销毁队列
{
	while ((*Q)->front)
	{
		(*Q)->rear = (*Q)->front->next;
		free((*Q)->front);
		(*Q)->front = (*Q)->rear;
	}
	flag = 0;
	printf("销毁成功！\n");
}

void EmptyQueue(struct LinkQueue* Q)//判断队列是否为空
{
	if (Q->front == NULL)
	{
		printf("队列为空！\n");
	}
	else
	{
		printf("队列不为空！\n");
	}
}

void menu(void)
{
	printf("***************{队列的操作}*****************\n");
	printf("********1.初始化**********2.进队************\n");
	printf("********3.出队************4.打印************\n");
	printf("********5.判断空队列******6.销毁************\n");
	printf("******************7.退出********************\n");
}

int main()
{
	char a = 0;
	char s[100] = { 0 };
	struct LinkQueue* Q = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
	do
	{
		menu();
		do
		{
			printf("请输入对应操作的数字:");
			scanf("%s", s);
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
				InitQueue(&Q);
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
						EnQueue(& Q, ch);
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
				DeQueue(&Q);
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
				PrintQueue(Q);
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
				EmptyQueue(Q);
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
				DestroyQueue(&Q);
			}
		}
		else if (a == '7')
		{
			break;
		}
	} while (1);
	return 0;
}


