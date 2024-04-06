#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Parttition(int *data,int left,int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && data[key] <= data[right])
		{
			right--;
		}
		while (left < right && data[key] >= data[left])
		{
			left++;
		}
		swap(&(data[left]), &(data[right]));
	}
	swap(&(data[key]), &(data[right]));

	return right;
}

int QuickSortGetTop(int* data, int left, int right,int k)
{
	int partition = -1;
	if (left < right && k)
	{
		partition = Parttition(data, left, right);
		if (partition == k)
		{
			return k;
		}
		else if (partition < k)
			return QuickSortGetTop(data, partition + 1, right, k);
		else
			return QuickSortGetTop(data, left, partition - 1, k);
	}

}

int main()
{
	int a[7] = { 1,34,6,7,83,4,7 };
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	QuickSortGetTop(&a, 0, 6, 2);
	printf("%d\n", a[2]);
	system("pause");
	return 0;

}