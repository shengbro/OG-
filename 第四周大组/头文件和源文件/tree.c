#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct Bitree {
	int data;
	struct Bitree* left;
	struct Bitree* right;
}Bitree,*BitreePtr;

BitreePtr root = NULL;

int checkint(char* s)
{
	while (*s != '\0')
	{
		if (*s < 48 || *s >57)
		{
			return 1;
		}
		s++;
	}
	return 0;
}

int changeint(char* s)
{
	char* p = s;
	int t = 1;
	int days = 0;
	while (*p != '\0')
	{
		p++;
	}
	for (--p; p >= s; p--)
	{
		days += (*p - '0') * t;
		t *= 10;
	}
	return days;
}

void visit(BitreePtr tree)
{
	printf("%d->", tree->data);
}

void PreOrder(BitreePtr tree)
{
	if (root == NULL)
	{
		printf("二叉树为空！\n");
		return;
	}
	if (tree != NULL)
	{
		visit(tree);
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}

void InOrder(BitreePtr tree)
{
	if (root == NULL)
	{
		printf("二叉树为空！\n");
		return;
	}
	if (tree != NULL)
	{
		InOrder(tree->left);
		visit(tree);
		InOrder(tree->right);
	}
}

void PostOrder(BitreePtr tree)
{
	if (root == NULL)
	{
		printf("二叉树为空！\n");
		return;
	}
	if (tree != NULL)
	{
		PostOrder(tree->left);
		PostOrder(tree->right);
		visit(tree);
	}
}

void Search(BitreePtr tree,int data)
{
	if (root == NULL)
	{
		printf("二叉树为空！\n");
		return;
	}
	while (tree != NULL)
	{
		if (data == tree->data)
		{
			printf("存在！\n");
			return;
		}
		else
		{
			if (data > tree->data)
			{
				tree = tree->right;
			}
			else if (data < tree->data)
			{
				tree = tree->left;
			}
		}
	}
	printf("不存在！\n");
}

void Insert(int data)
{
	BitreePtr temp = root;
	BitreePtr prev = NULL;
	while (temp != NULL)
	{
		prev = temp;
		if (data < temp->data)
		{
			temp = temp->left;
		}
		else if (data > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			printf("插入失败！\n");
			return;
		}
	}

	if (root == NULL)
	{
		root = (BitreePtr)malloc(sizeof(Bitree));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (data < prev->data)
		{
			BitreePtr New = (BitreePtr)malloc(sizeof(Bitree));
			prev->left = New;
			New->data = data;
			New->left = NULL;
			New->right = NULL;
		}
		else
		{
			BitreePtr New = (BitreePtr)malloc(sizeof(Bitree));
			prev->right = New;
			New->data = data;
			New->left = NULL;
			New->right = NULL;
		}
	}
	printf("插入成功！\n");
}

BitreePtr find_parent(int data)
{
	BitreePtr p1 = root;
	BitreePtr p2 = NULL;
	while (p1->data != data)
	{
		p2 = p1;
		if (p1->data > data)
		{
			p1 = p1->left;
		}
		else if (p1->data < data)
		{
			p1 = p1->right;
		}
	}
	return p2;
}

int Delete(BitreePtr tree,int data)
{
	if (root == NULL)
	{
		printf("二叉树为空！\n");
		return 0;
	}
    if (tree->left == NULL && tree->right == NULL)
	{
		if (tree->data == data)
		{
			root = NULL;
			printf("删除成功！\n");
			return 0;
		}
		else
		{
			printf("不存在此节点！\n");
			return 0;
		}
	}
	if (tree == NULL)
	{
		printf("不存在此节点！\n");
		return 0;
	}
	else
	{
		if (tree->data == data)
		{
			BitreePtr parent = find_parent(data);
			BitreePtr temp = NULL;
			
			if (tree->right == NULL)
			{
				temp = tree;
				tree = tree->left;
				if (parent->left != NULL)
				{
					if (parent->left->data == temp->data)
					{
						parent->left = tree;
						free(temp);
						temp = NULL;
					}
					else
					{
						parent->right = tree;
						free(temp);
						temp = NULL;
					}
				}
				else
				{
					parent->right = tree;
					free(temp);
					temp = NULL;
				}
			}
			else if (tree->left == NULL)
			{
				temp = tree;
				tree = tree->right;
				if (parent->right != NULL)
				{
					if (parent->right->data == temp->data)
					{
						parent->right = tree;
						free(temp);
						temp = NULL;
					}
					else
					{
						parent->left = tree;
						free(temp);
						temp = NULL;
					}
				}
				else
				{
					parent->left = tree;
					free(temp);
					temp = NULL;
				}
			}
			else
			{
				temp = tree;
				BitreePtr left_max = tree;
				left_max = tree->left;
				while (left_max->right != NULL)
				{
					temp = left_max;
					left_max = left_max->right;
				}
				tree->data = left_max->data;
				temp->right = left_max->left;
				free(left_max);
				left_max = NULL;
			}
		}
		else if (tree->data > data)
		{
			Delete(tree->left, data);
		}
		else if (tree->data < data)
		{
			Delete(tree->right, data);
		}
	}
	return 1;
}

void menu()
{
	printf("====二叉排序树====\n");
	printf("====A.插入数据====\n");
	printf("====B.删除数据====\n");
	printf("====C.查询数据====\n");
	printf("====D.前序遍历====\n");
	printf("====E.中序遍历====\n");
	printf("====F.后序遍历====\n");
	printf("======G.退出======\n");
}

int main()
{
	while (1)
	{
		char ch[20] = { 0 };
		menu();
		printf("请输入正确的选项:");
		scanf("%s", ch);
		getchar();
		while (strlen(ch) != 1 || ch[0] < 'A' || ch[0] > 'H')
		{
			printf("输入错误请！重新输入:");
			scanf("%s", ch);
		}
		if (ch[0] == 'A')
		{
			char c[20] = { 0 };
			printf("请输入数据:");
			scanf("%s", c);
			while (checkint(c))
			{
				printf("输入的数据错误！请重新输入:");
				scanf("%s", c);
				getchar();
			}
			Insert(changeint(c));
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'B')
		{
			char c[20] = { 0 };
			printf("请输入数据:");
			scanf("%s", c);
			while (checkint(c))
			{
				printf("输入的数据错误！请重新输入:");
				scanf("%s", c);
				getchar();
			}
			BitreePtr tree = root;
			int flag = Delete(tree, changeint(c));
			if (flag == 1)
			{
				printf("删除成功！\n");
			}
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'C')
		{
			char c[20] = { 0 };
			printf("请输入数据:");
			scanf("%s", c);
			while (checkint(c))
			{
				printf("输入的数据错误！请重新输入:");
				scanf("%s", c);
				getchar();
			}
			BitreePtr tree = root;
			Search(tree, changeint(c));
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'D')
		{
			BitreePtr tree = root;
			PreOrder(tree);
			if (root != NULL)
			{
				printf("NULL\n");
			}
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'E')
		{
			BitreePtr tree = root;
			InOrder(tree);
			if (root != NULL)
			{
				printf("NULL\n");
			}
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'F')
		{
			BitreePtr tree = root;
			PostOrder(tree);
			if (root != NULL)
			{
				printf("NULL\n");
			}
			system("pause");
			system("cls");
		}
		else if (ch[0] == 'G')
		{
			return 0;
		}
	}
}