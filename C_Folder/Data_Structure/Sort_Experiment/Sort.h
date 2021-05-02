#ifndef _SORT_H_
#define _SORT_H_

#include<iostream>
#include<time.h>
#include<windows.h>
#define LEN 25
#define left(i) 2 * i + 1
#define right(i) 2 * (i + 1)

using namespace std;

int* CreatRan()
{
	srand((unsigned)time(NULL));

	int* Arr = new int[100];

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		*(Arr + i) = num;
	}
	return Arr;
}

void partition(int a[100], int b, int e, int* p, int& times, int& change)
{
	int x = a[b];
	int i = b, j = e;
	while (i != j)
	{
		times++;
		while (i < j && a[j] > x)
		{
			times++;
			j--;
		}
		if (i < j)
		{
			change++;
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < x)
		{
			times ++;
			i++;
		}
		if (i < j)
		{
			change++;
			a[j] = a[i];
			j--;
		}
	}
	a[i] = x;
	*p = i;
}

void FastSort(int A[], int b, int e, int& times, int& change)
{
	int i;
	times++;
	if (b < e)
	{
		partition(A, b, e, &i, times, change);
		FastSort(A, b, i - 1, times, change);
		FastSort(A, i + 1, e, times, change);
	}
}

void Exchange(int a[])
{
	int be = 0, en = LEN - 1;
	int x;
	int i = 0;
	while (i < en + 1)
	{
		while (a[be] % 3 == 0)
		{
			be++;
		}
		while (a[en] % 3 == 2)
		{
			en--;
		}
		if (i <= be)
		{
			i = be + 1;
		}
		if (i > en)
		{
			break;
		}
		if (a[i] % 3 == 0)
		{
			x = a[be];
			a[be] = a[i];
			a[i] = x;
			be++;
		}
		else if (a[i] % 3 == 2)
		{
			x = a[en];
			a[en] = a[i];
			a[i] = x;
			en--;
		}
		else
		{
			i++;
		}
	}
}

void ShellSort(int a[], int dh, int& len, int& change)
{
	while (dh >= 1)
	{
		for (int i = dh + 1; i < LEN + 1; i++)
		{
			int temp = a[i];
			int j = i;
			len++;
			while (j > dh && temp < a[j - dh])
			{
				a[j] = a[j - dh];
				j = j - dh;
				change++;
			}
			a[j] = temp;
		}
		dh /= 2;
	}
}

void partition1(int a[100], int b, int e, int* p, int& times)
{
	int x = a[b];
	int i = b, j = e;
	while (i != j)
	{
		while (i < j && a[j] > x)
		{
			j--;
		}
		if (i < j)
		{
			a[i] = a[j];
			times++;
			cout << times << "  --->  ";
			for (int k = 0; k < LEN; k++)
			{
				cout << a[k] << " ";
			}
			cout << endl;
			i++;
		}
		while (i < j && a[i] < x)
		{
			i++;
		}
		if (i < j)
		{
			a[j] = a[i];
			times++;
			cout << times << "  --->  ";
			for (int k = 0; k < LEN; k++)
			{
				cout << a[k] << " ";
			}
			cout << endl;
			j--;
		}
	}
	a[i] = x;
	*p = i;
}

void FastSort1(int A[], int b, int e, int& times)
{
	int i;
	if (b < e)
	{
		partition1(A, b, e, &i, times);
		FastSort1(A, b, i - 1, times);
		FastSort1(A, i + 1, e, times);
	}
}

void print(int a[])
{
	for (int i = 0; i < LEN; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	Sleep(500);
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Proheap(int a[], int i, int N)
{
	int child;
	int temp;
	for (temp = a[i]; 2 * i + 1 < N; i = child)
	{
		child = 2 * i + 1;
		if (child != N - 1 && a[child + 1] > a[child])
		{
			++child;
		}
		if (temp < a[child])
		{
			a[i] = a[child];
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
	print(a);
}

void HeapSort(int a[], int length)
{
	int i;
	for (i = length / 2; i >= 0; --i)
	{
		Proheap(a, i, length);
	}
	for (i = length - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		Proheap(a, 0, i);
	}
}

void merge(int a[], int P, int q, int r, int s)
{
	int i = P, j = r, k = 0;
	int* p = new int[(s - P + 1)];
	int* point = p;
	for (int i = 0; i < (s - P + 1); i++)
	{
		*(p + i) = 0;
		*(point + i) = 0;
	}
	while (i <= q && j <= s)
	{
		if (a[i] <= a[j])
		{
			p[k++] = a[i++];
		}
		else
		{
			p[k++] = a[j++];
		}
	}
	while (i <= q)
	{
		p[k++] = a[i++];
	}
	while (j <= s)
	{
		p[k++] = a[j++];
	}
	for (k = 0; k <= s - P; k++)
	{
		a[P + k] = p[k];
	}
	delete point;
}

void mergeSort(int arr[], int p, int q)
{
	if (p < q)
	{
		int r = (p + q) / 2;
		mergeSort(arr, p, r);
		mergeSort(arr, r + 1, q);
		merge(arr, p, r, r + 1, q);
	}
}

void solution1()
{
	int* p;
	p = CreatRan();
	cout << "It started like this: " << endl;
	for (int i = 0; i < 99; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl << endl;
	int times = 0, change = 0;
	cout << "After sorting: " << endl;
	FastSort(p, 0, 99, times, change);
	for (int i = 0; i < 99; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	cout << times << "    " << change << endl;
}

void solution2()
{
	int key;
	cout << "Please enter the key of your array and exited with '0: ";
	cin >> key;
	while (key != 0)
	{
		switch (key) {
		case 1: {
			int p[LEN] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
			Exchange(p);
			for (int i = 0; i < LEN; i++)
			{
				cout << p[i] << " ";
			}
			cout << endl;
			break;
		}
		case 2: {
			int p[LEN] = { 11,12,13,14,15,1,2,3,4,5,6,10,16,1,22,23,2,17,18,19,20,24,7,8,9 };
			Exchange(p);
			for (int i = 0; i < LEN; i++)
			{
				cout << p[i] << " ";
			}
			cout << endl;
			break;
		}
		case 3: {
			int p[LEN] = { 5,6,7,1,2,3,4,8,9,10,11,12,13,16,17,18,14,25,26,15,19,20,21,22,23 };
			Exchange(p);
			for (int i = 0; i < LEN; i++)
			{
				cout << p[i] << " ";
			}
			cout << endl;
			break;
		}
		case 0:exit(0);
		}
		cout << "Please enter the key of your array and exited with '0': ";
		cin >> key;
	}
}

void solution3()
{
	int len = 0, change = 0;
	int dh;
	cout << "Please input the stride: ";
	cin >> dh;
	int p[LEN + 1] = { 0,106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26 };
	ShellSort(p, dh, len, change);
	for (int i = 1; i < LEN + 1; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	cout << len << "   " << change << endl;
}

void solution4()
{
	int p[LEN] = { 106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26 };
	int b = 0, e = 24, times = 0;
	FastSort1(p, b, e, times);
}

void solution5()
{
	int p[LEN] = { 106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26 };
	HeapSort(p, LEN);
}

void solution6()
{
	int p[LEN] = { 106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26 };
	mergeSort(p, 0, 24);
	for (int i = 0; i < LEN; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

void Graph()
{
	for (int i = 0; i < 120; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "* 第2题数组                                                                                                            *" << endl;
	cout << "* 1 --->(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25)                                            *" << endl;;
	cout << "* 2 --->(11,12,13,14,15,1,2,3,4,5,6,10,16,1,22,23,2,17,18,19,20,24,7,8,9)                                              *" << endl;
	cout << "* 3 --->(5,6,7,1,2,3,4,8,9,10,11,12,13,16,17,18,14,25,26,15,19,20,21,22,23)                                            *" << endl;
	cout << "* 第3题数组                                                                                                            *" << endl;
	cout << "* (106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26)                       *" << endl;
	cout << "* 第4题数组                                                                                                            *" << endl;
	cout << "* (106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26)                       *" << endl;
	cout << "* 第5题数组                                                                                                            *" << endl;
	cout << "* (106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26)                       *" << endl;
	cout << "* 第6题数组                                                                                                            *" << endl;
	cout << "* (106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26)                       *" << endl;
	cout << "* 1. 采用不同实验数据来观察快速排序的实验中比较和交换元素的次数                                                        *" << endl;
	cout << "* 2. 将一个整型数组调整为这样的数组：所有３的倍数在最左边，所有除以３余１的数在中间，而所有除以３余２的数在最右边      *" << endl;
	cout << "* 3. 实现shell排序算法，并观察在采用不同的步长选取方法对排序过程中数据的比较和移动次数的影响                           *" << endl;
	cout << "* 4. 设计算法实现快速排序，要求能用数组或树来演示排序过程，以清晰地表示出排序过程                                      *" << endl;
	cout << "* 5. 以数组和二叉树形式动态演示堆排序算法的排序过程                                                                    *" << endl;
	cout << "* 6. 利用二路归并方法进行排序                                                                                          *" << endl;
	for (int i = 0; i < 120; i++)
	{
		cout << "*";
	}
	cout << endl;
}

#endif