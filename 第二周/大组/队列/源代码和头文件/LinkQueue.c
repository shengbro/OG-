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

void InitQueue(struct LinkQueue** Q)//��ʼ������
{
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	flag = 1;
	printf("��ʼ���ɹ���\n");
}

void EnQueue(struct LinkQueue** Q, char* ch)//����
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
	printf("��ӳɹ���\n");
}

void DeQueue(struct LinkQueue** Q)//����
{
	if ((*Q)->front == NULL)
	{
		printf("�Ѿ�Ϊ�ն��У�\n");
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
		printf("���ӳɹ���\n");
	}
}

void PrintQueue(struct LinkQueue* Q)//��ӡ����
{
	if (Q->front == NULL)
	{
		printf("����Ϊ�գ�\n");
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

void DestroyQueue(struct LinkQueue** Q)//���ٶ���
{
	while ((*Q)->front)
	{
		(*Q)->rear = (*Q)->front->next;
		free((*Q)->front);
		(*Q)->front = (*Q)->rear;
	}
	flag = 0;
	printf("���ٳɹ���\n");
}

void EmptyQueue(struct LinkQueue* Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->front == NULL)
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("���в�Ϊ�գ�\n");
	}
}

void menu(void)
{
	printf("***************{���еĲ���}*****************\n");
	printf("********1.��ʼ��**********2.����************\n");
	printf("********3.����************4.��ӡ************\n");
	printf("********5.�жϿն���******6.����************\n");
	printf("******************7.�˳�********************\n");
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
			printf("�������Ӧ����������:");
			scanf("%s", s);
			getchar();
			if (strlen(s) == 1)
			{
				a = s[0];
				if (a < '1' || a>'7')
				{
					printf("�������\n");
				}
				else
					break;
			}
			else
			{
				printf("�������\n");
			}
		} while (1);
		if (a == '1')
		{
			if (flag == 1)
			{
				printf("�������٣�\n");
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
				printf("���ȳ�ʼ����\n");
			}
			else
			{
				char ch[100] = { 0 };
				do
				{
					printf("�������ַ���(С��10):");
					gets(ch);
					if (strlen(ch) < 10)
					{
						EnQueue(& Q, ch);
						break;
					}
					else
					{
						printf("�������\n");
					}
				} while (1);
			}
		}
		else if (a == '3')
		{
			if (flag == 0)
			{
				printf("���ȳ�ʼ����\n");
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
				printf("���ȳ�ʼ����\n");
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
				printf("���ȳ�ʼ����\n");
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
				printf("���ȳ�ʼ����\n");
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


