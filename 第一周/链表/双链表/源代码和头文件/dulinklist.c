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
	printf("   ********{˫���������}********     \n");
	printf("***1.��ʼ������********2.�������***\n");
	printf("***3.����ڵ�**********4.ɾ���ڵ�***\n");
	printf("***5.��ѯ����**********6.��ת���***\n");
	printf("***7.����ɻ�**********8.�жϳɻ�***\n");
	printf("***9.�м�ڵ�**********10.��������***\n");
	printf("**************11.�˳�****************\n");
}

struct duLNode* Greatlist(int a)//��ʼ��
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
			printf("����ڵ�(С��20���ַ���):");
			char ch[100] = { 0 };
			gets(ch);
			if (strlen(ch) < 20)
			{
				strcpy(&p1->s, ch);
				break;
			}
			else
			{
				printf("�������!\n");
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

void Inputlist(struct duLNode* head)//�������
{
	struct duLNode* p = head;
	while (p)
	{
		printf("%s->", p->s);
		p = p->next;
	}
	printf("NULL\n");
}

void ReverseInput(struct duLNode* head)//�����������
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

void Findmidlist(struct duLNode* head)//�ҵ��м�
{
	struct duLNode* slow = head;
	struct duLNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("�м�ڵ�:%s\n", slow->s);
}

void Deletelist(struct duLNode** pphead)//ɾ���ڵ�
{
	int i = 0;
	printf("������Ҫɾ���Ľڵ�:");
	scanf("%d", &i);
	while (i > num)
	{
		printf("�������!����������:");
		scanf("%d", &i);
	}
	if (i == 1)
	{
		struct LNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
		(*pphead)->prev = NULL;
		num = num - 1;
		printf("ɾ���ɹ���");
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
		printf("ɾ���ɹ���");
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
		printf("ɾ���ɹ���");
	}
}

void Insertlist(struct duLNode** pphead)//����ڵ�
{
	int i = 0;
	printf("���������ĸ��ڵ�ǰ����:");
	scanf("%d", &i);
	while (i > num)
	{
		printf("�����������������:");
		scanf("%d", &i);
	}
	if (i == 1)
	{
		getchar();
		struct duLNode* New = Greatlist(1);
		New->next = *pphead;
		(*pphead)->prev = New;
		*pphead = New;
		printf("����ɹ���\n");
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
		printf("����ɹ���\n");
		num = num + 1;
	}
}

void Searchlist(struct duLNode* head)//��ѯ����
{
	char ch1[20] = { 0 };
	getchar();
	while (1)
	{
		printf("�������ѯ���ַ���(С��20):");
		char ch2[100] = { 0 };
		gets(ch2);
		if (strlen(ch2) < 20)
		{
			strcpy(ch1, ch2);
			break;
		}
		else
		{
			printf("�������!\n");
		}
	}
	struct duLNode* p = head;
	while (p)
	{
		if (strcmp(ch1, p->s) == 0)
		{
			printf("�д��ַ�����\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�޴��ַ�����\n");
	}
}

void DestroyList(struct duLNode** pphead)//����
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
	printf("���ٳɹ���\n");
	num = 0;
}

void Islooplist(struct duLNode* head)//�жϳɻ�
{
	struct duLNode* fast = head;
	struct duLNode* slow = head;
	while (1)
	{
		if (fast == NULL || fast->next == NULL)
		{
			printf("û�гɻ���\n");
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			printf("�ɻ���\n");
			break;
		}
	}
}

struct LNode* looplist(struct duLNode* head)//�ɻ�
{
	struct duLNode* p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = head;
	head->prev = p;
	flag = 1;
	printf("�ɻ��ɹ���\n");
}

int main()
{
	struct LNode* head = NULL;
	while (1)
	{
		menu();
		int choose = 0;
		printf("������ѡ������:");
		scanf("%d", &choose);
		while (choose > 11)
		{
			printf("�����������������:");
			scanf("%d", choose);
		}
		if (choose == 1)
		{
			printf("������ڵ�����:");
			scanf("%d", &num);
			getchar();
			head = Greatlist(num);
		}
		else if (choose == 2)
		{
			if (flag == 1)
			{
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
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
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
				}
				else
					Insertlist(&head);
			}
		}
		else if (choose == 4)
		{
			if (flag == 1)
			{
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
				}
				else
					Deletelist(&head);
			}
		}
		else if (choose == 5)
		{
			if (flag == 1)
			{
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
				}
				else
					Searchlist(head);
			}
		}
		else if (choose == 6)
		{
			if (flag == 1)
			{
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
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
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
				}
				else if (num == 1)
				{
					printf("ֻ��һ���ڵ㣡\n");
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
				printf("���ȳ�ʼ������\n");
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
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
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
				printf("�����ѳɻ���\n");
			}
			else
			{
				if (num == 0)
				{
					printf("���ȳ�ʼ������\n");
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