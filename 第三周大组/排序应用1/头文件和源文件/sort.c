#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a[7] = { 1,2,1,0,2,0,0 };
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int p1, p0, p2;
	p1 = p0 = 0;
	p2 = 6;

	while(p1 < p2)
	{
		if (a[p1] == 0)
		{
			swap(&a[p1], &a[p0]);
			p0++;
			if (a[p1] == 0)
			{
				swap(&a[p1], &a[p0]);
				p0++;

			}
			else if (a[p1] == 2)
			{
				swap(&(a[p1]), &(a[p2]));
				p2--;
			}
		}
        else if (a[p1] == 2)
		{
			swap(&(a[p1]), &(a[p2]));
			p2--;
			if (a[p1] == 0)
			{
				swap(&a[p1], &a[p0]);
				p0++;
			}
			else if (a[p1] == 2)
			{
				swap(&(a[p1]), &(a[p2]));
				p2--;
			}
		}
		p1++;
	}
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}