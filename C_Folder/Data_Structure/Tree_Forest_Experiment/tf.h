#ifndef _TF_H_
#define _TF_H_
#define MAXLEN 100
#pragma warning(disable:4996)

#include<iostream>
#include"createTree.h"

bool JudgeLeave(pTree& T, elementType x)
{
	int i, w;
	bool flag = false;
	for (w = 0; w < T.n; w++)
	{
		if (T.node[w].data == x)
			break;
	}
	if (w >= T.n)
		return false;
	for (i = 0; i < T.n; i++)
	{
		if (T.node[i].parent == w)
			flag = true;
	}
	return flag;
}

void TraverseUptoDown(pTree& T)
{
	int len = 0, flag = 0;
	for (int i = 0; i < T.n; i++)
	{
		len = pDepth(T, T.node[i].data);
		if (len > flag)
		{
			flag = len;
		}
	}
	for (int j = 1; j <= len; j++)
	{
		for (int i = 0; i < T.n; i++)
		{
			if (pDepth(T, T.node[i].data) == j)
			{
				cout << T.node[i].data << "  ";
			}
		}
	}
}

int Childnum(pTree& T, elementType x)
{
	int i, w;
	int num = 0;
	for (w = 0; w < T.n; w++)
	{
		if (T.node[w].data == x)
			break;
	}
	if (w >= T.n)
		return 0;
	for (i = 0; i < T.n; i++)
	{
		if (T.node[i].parent == w)
			num++;
	}
	return num;
}

void Travel(csNode* T1, char a[], int& i, int b[])
{
	if (T1)
	{
		int j = i;
		a[i++] = T1->data;
		b[j] = T1->depth;
		Travel(T1->firstChild, a, i, b);
		Travel(T1->nextSibling, a, i, b);
	}
}

void Solution1(pTree T)
{
	preTraverse(T);
	cout << endl;
	postTraverse(T);
	cout << endl;
	TraverseUptoDown(T);
	cout << endl;
}

void Solution2(pTree T)
{
	int len, flag = 0;
	for (int i = 0; i < T.n; i++)
	{
		len = pDepth(T, T.node[i].data);
		if (len > flag)
		{
			flag = len;
		}
	}
	cout << "Its depth is " << flag << "." << endl;
}

void Solution3(pTree T)
{
	cout << "It has " << T.n << " points." << endl;
}

void Solution4(pTree T)
{
	int num = 0;
	for (int i = 0; i < T.n; i++)
	{
		if (JudgeLeave(T, T.node[i].data))
		{
			num++;
		}
	}
	cout << "It has " << num << " leaves." << endl;
}

void Solution5(pTree T)
{
	int flag = 0, degree;
	for (int i = 0; i < T.n; i++)
	{
		degree = Childnum(T, T.node[i].data);
		if (degree > flag)
		{
			flag = degree;
		}
	}
	cout << "Its degree is " << flag << "." << endl;
}

void Solution6(pTree T)
{
	preTraverseDepth(T);
	cout << endl;
}

void Solution7(pTree T)
{
	csNode* T1;
	char a[50];
	int b[50] = { 0 };
	int j = 0;
	for (int i = 0; i < 50; i++)
	{
		a[i] = NULL;
	}
	createCsTree(T1, T);
	Travel(T1, a, j, b);
	for (int i = 0; i < 50; i++)
	{
		int c;
		if (a[i])
		{
			cout << a[i];
			if (a[i + 1])
			{
				c = b[i] - b[i + 1];
				if (c < 0)
				{
					c = -c;
					for (int l = 0; l < c; l++)
					{
						cout << "(";
					}
				}
				else if (c == 0)
				{
					cout << ",";
				}
				else
				{
					for (int l = 0; l < c; l++)
					{
						cout << ")";
					}
				}
			}
		}
	}
	cout << endl;
}

void Graph()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "* 1.从文件创建树(森林) [F20.tre]                 *" << endl;
	cout << "* 2.按先序、后序、层次遍历森林                   *" << endl;
	cout << "* 3.求森林的高度                                 *" << endl;
	cout << "* 4.求森林结点总数                               *" << endl;
	cout << "* 5.求森林叶子结点数                             *" << endl;
	cout << "* 6.求森林的度                                   *" << endl;
	cout << "* 7.先序输出结点值及其层次号                     *" << endl;
	cout << "* 8.输出广义表表示的树                           *" << endl;
	cout << "* 9.退出                                         *" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "*";
	}
	cout << endl;
}

#endif