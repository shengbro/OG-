#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InserSort(int* data,int size)
{
	int i = 0;
	for (i = 1; i < size; i++)
	{
		int left = 0;
		int right = i - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (data[mid] > data[i])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		int temp = data[i];
		for (right = i; right > left; right--)
		{
			data[right] = data[right-1];
		}
		data[left] = temp;
	}
}

void MergeSort(int *data,int*tem,int left ,int right)
{
	if (right <= left + 1)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	MergeSort(data, tem, left, mid);
	MergeSort(data, tem, mid, right);

	int ptr1 = left;
	int ptr2 = right;
	int ptrtem = left;
	while (ptr1 < mid && ptr2 < right)
	{
		if (data[ptr1] > data[ptr2])
		{
			tem[ptrtem] = data[ptr2];
			ptr2++;
			ptrtem++;
		}
		else
		{
			tem[ptrtem] = data[ptr1];
			ptr1++;
			ptrtem++;
		}
	}

	while (ptr1 < mid)
	{
		tem[ptrtem] = data[ptr1];
		ptrtem++;
		ptr1++;
	}
	while (ptr2 < right)
	{
		tem[ptrtem] = data[ptr2];
		ptrtem++;
		ptr2++;
	}

	for (int i = left; i < right; i++)
	{
		data[i] = tem[i];
	}
}

void QuickSort(int*data,int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int left = begin;
	int right = end;
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
	key = right;

	QuickSort(data, begin, key - 1);
	QuickSort(data, key + 1, end);

}

void CountSort(int * data,int size)
{
	int max = data[0];
	int min = data[0];
	for (int i = 0; i < size; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	int range = max - min+1;
	int* tem = (int*)malloc(range * sizeof(int));

	for (int i = 0; i < range; i++)
	{
		tem[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		tem[data[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		for (int k = tem[i]; k > 0; k--)
		{
			data[j] = i + min;
			j++;
		}
	}
	free(tem);
	tem = NULL;
}

void RadixCountSort(int*data,int size)
{
	int bucket[10] = { 0 };
	int* buff = (int*)malloc(size * sizeof(int));

	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}

	int count = 0;
	while (max > 0)
	{
		count++;
		max /= 10;
	}

	int base = 1;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < size; j++)
		{
			bucket[(data[j] / base) % 10]++;
		}

		for (int j = 1; j < 10; j++)
		{
			bucket[j] += bucket[j - 1];
		}

		for (int j = size - 1; j >= 0; j--)
		{
			buff[bucket[(data[j] / base) % 10] - 1] = data[j];
			bucket[(data[j] / base) % 10]--;
		}

		for (int j = 0; j < size; j++)
		{
			data[j] = buff[j];
		}
		
		for (int j = 0; j < 10; j++)
		{
			bucket[j] = 0;
		}
		base *= 10;
	}
	free(buff);
	buff = NULL;
}

int* CreatRandNumber(int* size)
{
	printf("请输入你想要的数据大小:");
	scanf("%d", size);
	getchar();
	int* p = (int*)malloc(sizeof(int) * (*size));

	srand(time(NULL));
	for (int i = *size, j = 0; i > 0; i--, j++)
	{
		p[j] = rand() ;
	}
	
	return p;
}

void menu()
{
	printf("====请输入选项====\n");
	printf("====a.插入排序====\n");
	printf("====b.归并排序====\n");
	printf("====c.快速排序====\n");
	printf("====d.计数排序====\n");
	printf("====e.基数计数====\n");
	printf("======f.退出======\n");
}


int main()
{
	while (1)
	{
		menu();
		char choose[50] = { 0 };
		printf("请输入你的选项:");
		scanf("%s", choose);
		while (choose[0] < 'a' || choose[0] >'f' || choose[1] != '\0')
		{
			printf("请输入正确的选项:");
			scanf("%s", choose);
			getchar();
		}
		if (choose[0] == 'f')
		{
			break;
		}
		int size = 0;
		int* data = CreatRandNumber(&size);
		if (choose[0] == 'a')
		{
			clock_t start = clock();
			InserSort(data, size);				
			clock_t diff = clock() - start;
			printf("%d ms\n", diff);
		}
		else if (choose[0] == 'b')
		{
			clock_t start = clock();
			int* tem = (int*)malloc(sizeof(int) * size);
			for (int i = 0; i < size; i++)
			{
				tem[i] = 0;
			}
			MergeSort(data, tem, 0, size - 1);
			clock_t diff = clock() - start;
			printf("%d ms\n", diff);
		}
		else if (choose[0] == 'c')
		{
			clock_t start = clock();
			QuickSort(data, 0, size - 1);
			clock_t diff = clock() - start;
			printf("%d ms\n", diff);
		}
		else if (choose[0] == 'd')
		{
			clock_t start = clock();
			CountSort(data, size);
			clock_t diff = clock() - start;
			printf("%d ms\n", diff);
		}
		else if (choose[0] == 'e')
		{
			clock_t start = clock();
			RadixCountSort(data, size);
			clock_t diff = clock() - start;
			printf("%d ms\n", diff);
		}
		/*for (int i = 0; i < size; i++)
		{
			printf("%d\n", data[i]);
		}*/
		system("pause");
		system("cls");
	}
	return 0;

}