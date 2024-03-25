#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct duLNode)

struct duLNode {
	char s[20];
	struct duLNode* next;
	struct duLNode* prev;
};

int num = 0;
int flag = 0;

void menu(void)
{
	printf("   ********{双向链表操作}********     \n");
	printf("***1.初始化链表********2.输出链表***\n");
	printf("***3.插入节点**********4.删除节点***\n");
	printf("***5.查询链表**********6.反转输出***\n");
	printf("***7.链表成环**********8.判断成环***\n");
	printf("***9.中间节点**********10.销毁链表***\n");
	printf("**************11.退出****************\n");
}

struct duLNode* Greatlist(int a)//初始化
{
	flag = 0;
	struct duLNode* p1, * p2;
	struct duLNode* head = NULL;
	head = p1 = p2 = (struct duLNode*)malloc(LEN);
	p1->prev = NULL;
	for (int i = 1; i <= a; i++)
	{
		while (1)
		{
			printf("输入节点(小于20的字符串):");
			char ch[100] = { 0 };
			gets(ch);
			if (strlen(ch) < 20)
			{
				strcpy(&p1->s, ch);
				break;
			}
			else
			{
				printf("输入错误!\n");
			}
		}
		if (i < a)
		{
			p1 = (struct LNode*)malloc(LEN);
			p1->prev = p2;
			p2->next = p1;
			p2 = p1;
		}
	}
	p2->next = NULL;
	return head;
}

void Inputlist(struct duLNode* head)//输出链表
{
	struct duLNode* p = head;
	while (p)
	{
		printf("%s->", p->s);
		p = p->next;
	}
	printf("NULL\n");
}

void ReverseInput(struct duLNode* head)//反向遍历链表
{
	struct duLNode* p = head;
	while (p->next)
	{
		p = p->next;
	}
	while (p)
	{
		printf("%s->", p->s);
		p = p->prev;
	}
	printf("NULL\n");
}

void Findmidlist(struct duLNode* head)//找到中间
{
	struct duLNode* slow = head;
	struct duLNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("中间节点:%s\n", slow->s);
}

void Deletelist(struct duLNode** pphead)//删除节点
{
	int i = 0;
	printf("请输入要删除的节点:");
	scanf("%d", &i);
	while (i > num)
	{
		printf("输入错误!请重新输入:");
		scanf("%d", &i);
	}
	if (i == 1)
	{
		struct LNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
		(*pphead)->prev = NULL;
		num = num - 1;
		printf("删除成功！");
	}
	else if (i == num)
	{
		struct duLNode* prev = NULL;
		struct duLNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
		num = num - 1;
		printf("删除成功！");
	}
	else
	{
		struct duLNode* prev = NULL;
		struct duLNode* tail = *pphead;
		for (int j = 1; j < i; j++)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		tail->next->prev = prev;
		free(tail);
		num = num - 1;
		printf("删除成功！");
	}
}

void Insertlist(struct duLNode** pphead)//插入节点
{
	int i = 0;
	printf("请输入在哪个节点前插入:");
	scanf("%d", &i);
	while (i > num)
	{
		printf("输入错误！请重新输入:");
		scanf("%d", &i);
	}
	if (i == 1)
	{
		getchar();
		struct duLNode* New = Greatlist(1);
		New->next = *pphead;
		(*pphead)->prev = New;
		*pphead = New;
		printf("插入成功！\n");
		num = num + 1;
	}
	else
	{
		getchar();
		struct duLNode* New = Greatlist(1);
		struct duLNode* prev = *pphead;
		struct duLNode* cur = *pphead;
		for (int j = 1; j < i; j++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = New;
		New->prev = prev;
		New->next = cur;
		cur->prev = New;
		printf("插入成功！\n");
		num = num + 1;
	}
}

void Searchlist(struct duLNode* head)//查询链表
{
	char ch1[20] = { 0 };
	getchar();
	while (1)
	{
		printf("请输入查询的字符串(小于20):");
		char ch2[100] = { 0 };
		gets(ch2);
		if (strlen(ch2) < 20)
		{
			strcpy(ch1, ch2);
			break;
		}
		else
		{
			printf("输入错误!\n");
		}
	}
	struct duLNode* p = head;
	while (p)
	{
		if (strcmp(ch1, p->s) == 0)
		{
			printf("有此字符串！\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("无此字符串！\n");
	}
}

void DestroyList(struct duLNode** pphead)//销毁
{
	struct duLNode* cur = *pphead;
	struct duLNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
	printf("销毁成功！\n");
	num = 0;
}

void Islooplist(struct duLNode* head)//判断成环
{
	struct duLNode* fast = head;
	struct duLNode* slow = head;
	while (1)
	{
		if (fast == NULL || fast->next == NULL)
		{
			printf("没有成环！\n");
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			printf("成环！\n");
			break;
		}
	}
}

struct LNode* looplist(struct duLNode* head)//成环
{
	struct duLNode* p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = head;
	head->prev = p;
	flag = 1;
	printf("成环成功！\n");
}

int main()
{
	struct LNode* head = NULL;
	while (1)
	{
		menu();
		int choose = 0;
		printf("请输入选择数字:");
		scanf("%d", &choose);
		while (choose > 11)
		{
			printf("输入错误！请重新输入:");
			scanf("%d", choose);
		}
		if (choose == 1)
		{
			printf("请输入节点数量:");
			scanf("%d", &num);
			getchar();
			head = Greatlist(num);
		}
		else if (choose == 2)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
				{
					Inputlist(head);
				}
			}
		}
		else if (choose == 3)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
					Insertlist(&head);
			}
		}
		else if (choose == 4)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
					Deletelist(&head);
			}
		}
		else if (choose == 5)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
					Searchlist(head);
			}
		}
		else if (choose == 6)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
				{
					ReverseInput(head);
				}
			}
		}
		else if (choose == 7)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else if (num == 1)
				{
					printf("只有一个节点！\n");
				}
				else
				{
					looplist(head);
				}
			}
		}
		else if (choose == 8)
		{
			if (num == 0)
			{
				printf("请先初始化链表！\n");
			}
			else
			{
				Islooplist(head);
			}
		}
		else if (choose == 9)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
				{
					Findmidlist(head);
				}
			}
		}
		else if (choose == 10)
		{
			if (flag == 1)
			{
				printf("链表已成环！\n");
			}
			else
			{
				if (num == 0)
				{
					printf("请先初始化链表！\n");
				}
				else
					DestroyList(&head);
			}
		}
		else if (choose == 11)
		{
			return 0;
		}
	}
}