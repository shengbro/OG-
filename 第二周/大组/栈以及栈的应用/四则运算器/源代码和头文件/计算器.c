#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 256

struct Stack {
	char ch[MAXSIZE];
	int top;
};

char mid[MAXSIZE] = { 0 };
char rear[MAXSIZE] = { 0 };

void InitStack(struct Stack**s)//初始化栈
{
	(*s)->top = -1;
}

void Push(struct Stack** s,char c)
{
	(*s)->top++;
	(*s)->ch[(*s)->top] = c;
}

char Pop(struct Stack** s)
{
	char c = 0;
	c = (*s)->ch[(*s)->top];
	(*s)->top--;
	return c;
}

char Gettop(struct Stack* s)
{
	char c = 0;
	c = s->ch[s->top];
	return c;
}

int EmptyStack(struct Stack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
	return 0;
}

int Pri(char c)
{
	if (c == '+' || c == '-')
	{
		return 0;
	}
	if(c == '*' || c== '/')
	{
		return 1;
	}
	if (c == '(')
	{
		return -1;
	}
}

int Check(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == '*' || c == '/')
		return 3;
	else if (c == '.')
		return 4;
	else if (c == ' ')
		return 5;
	else if (c == '(')
		return 6;
	else if (c == ')')
		return 7;
	else
		return 0;
}

void charput(char c)
{
	static int i = 0;
	rear[i++] = c;
}

void Despace(char* m,char*mid)
{
	int n1, n2;
	n1 = n2 = 0;
	while (m[n1] != '\0')
	{
		if (m[n1] != ' ')
		{
			mid[n2] = m[n1];
			n2++;
		}
		n1++;
	}
}


int  Trans()
{
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	InitStack(&s);
	int j = 0;

	if (Check(mid[0]) == 2)
	{
		charput('0');
		charput(' ');
	}
	else if (Check(mid[0]) == 4 || Check(mid[0]) == 0 || Check(mid[0]) == 3)
	{
		printf("算式错误！\n");
		return 0;
	}
	while (mid[j] != '\0')
	{
		if (Check(mid[j]))
		{
			if (Check(mid[j]) == 1)
			{
				if (mid[j + 1] != '\0')
				{
					if (Check(mid[j + 1]) == 1 || Check(mid[j + 1]) == 4)
					{
						charput(mid[j]);
					}
					else if(Check(mid[j+1]) == 6)
					{
						printf("算式错误！\n");
						return 0;
					}
					else
					{
						charput(mid[j]);
						charput(' ');
					}
				}
				else
				{
					charput(mid[j]);
					charput(' ');
				}
			}
			else if (Check(mid[j]) == 2 || Check(mid[j]) == 3 )
			{
				if (mid[j+1] == '0' && mid[j] == '/')
				{
					printf("此算式无意义！\n");
					return 0;
				}
				if (mid[j + 1] != '0')
				{
					if (Check(mid[j + 1]) == 2 || Check(mid[j + 1]) == 3)
					{
						printf("算式错误！\n");
						return 0;
					}
				}
				if (EmptyStack(s) == 0)
				{
					while (EmptyStack(s) == 0 && Pri(mid[j]) <= Pri(Gettop(s)))
					{
						charput(Pop(&s));
						charput(' ');
					}
					Push(&s, mid[j]);
				}
				else
				{
					Push(&s, mid[j]);
				}
			}
			else if (Check(mid[j]) == 6)
			{
				Push(&s, mid[j]);
			}
			else if (Check(mid[j]) == 7)
			{
				while (Check(Gettop(s)) != 6)
				{
					charput(Pop(&s));
					if (EmptyStack(s) == 1)
					{
						printf("缺少左括号！\n");
						return 0;
					}
				}
				Pop(&s);
			}
			else if (Check(mid[j]) == 4)
			{
				if (mid[j + 1] != '\0')
				{
					if (Check(mid[j + 1]) != 1)
					{
						printf("算式错误!\n");
						return 0;
					}
				}
				else
				{
					printf("算式错误!\n");
					return 0;
				}
				charput(mid[j]);
			}
		}
		else
		{
			printf("算式错误！\n");
			return 0;
		}
		j++;
	}
	if (mid[j] == '\0')
	{
		while (EmptyStack(s) == 0)
		{
			if (Gettop(s) == '(')
			{
				printf("缺少右括号！\n");
				return 0;
			}
			charput(Pop(&s));
			charput(' ');
		}
	}
	else
	{
		printf("没有遍历完！\n");
		return 0;
	}
	return 1;
}

struct stack {
	double data[MAXSIZE];
	int top;
};

void Initstack(struct stack**s)
{
	(*s)->top = -1;
}

void push(struct stack** s,double a)
{
	(*s)->top++;
	(*s)->data[(*s)->top] = a;
}

double pop(struct stack** s)
{
	double a = 0;
	a = (*s)->data[(*s)->top];
	(*s)->top--;
	return a;
}

double get(struct stack* s)
{
	return s->data[s->top];
}

int emptystack(struct stack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
		return 0;
}

double express(double left, double right, char op)
{
	switch (op)
	{
	case '+':
		return left + right;
	case'-':
		return left - right;
	case'*':
		return left * right;
	case'/':
		if (right == 0)
		{
			return 999999;
		}
		return left / right;
	default:
		break;
	}
}

double change(char* s)//将字符型变量转化为double型变量
{
	char* p1 = s;
	char* p2 = s;
	double data = 0.0;
	int t1 = 1;
	while (*p1 != '\0')
	{
		p1++;
	}
	p2 = p1;
	for (--p1; p1 >= s; p1--)
	{
		if (*p1 == '.')
			continue;
		data += (*p1 - '0') * t1;
		t1 *= 10;
	}
	int n = 0;
	int flag = 0;
	for (--p2; p2 >= s; p2--)
	{
		if (*p2 == '.')
		{
			flag = 1;
			break;
		}
		n++;
	}
	if (flag)
	{
		for (int i = 1; i <= n; i++)
		{
			flag *= 10;
		}
		data = data / flag;
	}

	return data;
}

double calculate()
{
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	Initstack(&s);

	int i = 0;
	while (rear[i] != '\0')
	{
		char c[10] = { 0 };
		int j = 0;
		while (Check(rear[i]) == 1 || Check(rear[i]) == 4)
		{
			c[j] = rear[i];
			i++;
			j++;
		}
		if (c[0] != '\0')
		{
			push(&s, change(c));
		}
		if (Check(rear[i]) == 2 || Check(rear[i]) == 3)
		{
			c[0] = rear[i];
			push(&s, express(pop(&s), pop(&s), c[0]));
		}
		i++;
	}
	return pop(&s);
}

void menu()
{
	printf("======四则计算器=====\n");
	printf("=======1.开始========\n");
	printf("=======2.退出========\n");
}

int main()
{
	do
	{
		menu();
		char choose[50] = { 0 };
		while (1)
		{
			printf("请输入正确的选项:");
			scanf("%[^\n]", choose);
			getchar();
			if (strlen(choose) == 1 && (choose[0] == '1' || choose[0] == '2'))
				break;
		}
		if (choose[0] == '1')
		{
			char m[MAXSIZE] = { 0 };
			printf("请输入正确的算式:");
			scanf("%[^\n]", m);
			getchar();
			Despace(m, mid);
			int a = Trans();
			if (a == 1)
			{
				printf("后缀式:%s\n", rear);
				printf("结果是:%lf\n", calculate());
			}
		}
		else if (choose[0] == '2')
		{
			break;
		}

	} while (1);
	

	
	return 0;
}