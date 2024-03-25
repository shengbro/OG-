#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct LNode)

struct LNode {
	char s[20];
	struct LNode* next;
};

int num = 0;
int flag = 0;

struct LNode* Greatlist(int a)//初始化
{
	flag = 0;
	struct LNode* p1, * p2;
	struct LNode* head = NULL;
	head = p1 = p2 = (struct LNode*)malloc(LEN);
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
			p2->next = p1;
			p2 = p1;
		}
	}
	p2->next = NULL;
	return head;
}

void Inputlist(struct LNode* head)//输出链表
{
	struct LNode* p = head;
	while (p)
	{
		printf("%s->", p->s);
		p = p->next;
	}
	printf("NULL\n");
}

void Findmidlist(struct LNode* head)//找到中间
{
	struct LNode* slow = head;
	struct LNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("中间节点:%s\n", slow->s);
}

void Deletelist(struct LNode** pphead)//删除节点
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
		num = num - 1;
		printf("删除成功！");
	}
	else if (i == num)
	{
		struct LNode* prev = NULL;
		struct LNode* tail = *pphead;
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
		struct LNode* prev = NULL;
		struct LNode* tail = *pphead;
		for (int j = 1; j < i; j++)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		num = num - 1;
		printf("删除成功！");
	}
}

void Insertlist(struct LNode** pphead)//插入节点
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
		struct LNode* New = Greatlist(1);
		New->next = *pphead;
		*pphead = New;
		printf("插入成功！\n");
		num = num + 1;
	}
	else
	{
		getchar();
		struct LNode* New = Greatlist(1);
		struct LNode* prev = *pphead;
		struct LNode* cur = *pphead;
		for (int j = 1; j < i; j++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = New;
		New->next = cur;
		printf("插入成功！\n");
		num = num + 1;
	}
}

void Searchlist(struct LNode* head)//查询链表
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
	struct LNode* p = head;
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

void DestroyList(struct LNode** pphead)//销毁
{
	struct LNode* cur = *pphead;
	struct LNode* next = NULL;
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

void Islooplist(struct LNode* head)//判断成环
{
	struct LNode* fast = head;
	struct LNode* slow = head;
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

struct LNode* looplist(struct LNode* head)//成环
{
	struct LNode* p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = head;
	flag = 1;
	printf("成环成功！\n");
}

struct LNode* Reverselist(struct LNode* head)//反转
{
	struct LNode* prev = NULL;
	struct LNode* cur = head;
	while (cur)
	{
		struct LNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	printf("反转成功！\n");
	return prev;
}

void Exchangelist(struct LNode** pphead)//奇偶对调
{
	struct LNode* p = *pphead;
	struct LNode* p1 = *pphead;
	struct LNode* p2 = *pphead;

	p2 = (*pphead)->next;
	*pphead = p2;
	p1->next = p2->next;
	p2->next = p1;
	
	p = (*pphead)->next;
	while (p->next != NULL && p->next->next != NULL)
	{
		p2 = p->next->next;
		p1 = p->next;
		p->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		p = p->next->next;
	}
	printf("调换成功！\n");
}

void menu(void)
{
	printf("   ********{单链表操作}********     \n");
	printf("***1.初始化链表********2.输出链表***\n");
	printf("***3.插入节点**********4.删除节点***\n");
	printf("***5.查询链表**********6.反转链表***\n");
	printf("***7.链表成环**********8.判断成环***\n");
	printf("***9.中间节点**********10.销毁链表***\n");
	printf("***11.奇偶对调*********12.退出*******\n");
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
		while (choose > 12)
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
					head = Reverselist(head);
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
					Exchangelist(&head);
				}
			}
		}
		else if (choose == 12)
		{
			return 0;
		}
		
	}
}