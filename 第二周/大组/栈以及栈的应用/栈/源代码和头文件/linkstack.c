#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkStack {
	char s[10];
	struct ListStack* next;
};

int flag = 0;

void InitStack(struct LinkStack**top)//��ʼ��
{
	*top = NULL;
	flag = 1;
	printf("��ʼ���ɹ���\n");
}

void PushStack(struct LinkStack** top, char* ch)//��ջ
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
	printf("��ջ�ɹ���\n");
}

void PopStack(struct LinkStack** top)//��ջ
{
	if (*top == NULL)
	{
		printf("�Ѿ��ǿ�ջ��\n");
	}
	else
	{
		struct LinkStack* next = (*top)->next;
		free(*top);
		*top = next;
		printf("��ջ�ɹ���\n");
	}
}

void PrintStack(struct LinkStack* top)//��ӡ
{
	if (top == NULL)
	{
		printf("Ϊ��ջ��\n");
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

void DestroyStack(struct LinkStack** top)//����
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
	printf("���ٳɹ���\n");
}

void EmptyStack(struct LinkStack* top)//�ж��Ƿ�Ϊ��
{
	if (top == NULL)
	{
		printf("��ջ��\n");
	}
	else
	{
		printf("��Ϊ��ջ��\n");
	}
}

void menu(void)
{
	printf("***************{ջ�Ĳ���}*******************\n");
	printf("********1.��ʼ��**********2.��ջ************\n");
	printf("********3.��ջ************4.��ӡ************\n");
	printf("********5.�жϿ�ջ********6.����************\n");
	printf("******************7.�˳�********************\n");
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
			printf("�������Ӧ����������:");
			scanf("%s",s);
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
				InitStack(&top);
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
						PushStack(&top, ch);
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
				PopStack(&top);
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
				PrintStack(top);
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
				EmptyStack(top);
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