#ifndef _BITREE_H_
#define _BITREE_H_
#pragma warning(disable:4996)     

#include<iostream>
#include<cmath>

using namespace std;

typedef char elemtype;

typedef struct lBnode
{
	elemtype data;
	struct lBnode* lChild, * rChild;
}BiNode;

void visit(BiNode* T)
{
	if (T)
	{
		cout << T->data << " ";
	}
}

void PreOrder(BiNode* T)
{
	if (T)
	{
		visit(T);
		PreOrder(T->lChild);
		PreOrder(T->rChild);
	}
}

void InOrder(BiNode* T)
{
	if (T)
	{
		InOrder(T->lChild);
		visit(T);
		InOrder(T->rChild);
	}
}

void PostOrder(BiNode* T)
{
	if (T)
	{
		PostOrder(T->lChild);
		PostOrder(T->rChild);
		visit(T);
	}
}

void InOrderDep(BiNode* T, int i)
{
	if (T)
	{
		InOrderDep(T->lChild, i + 1);
		cout << T->data << " -> " << i << endl;
		InOrderDep(T->rChild, i + 1);
	}
}

int BTdepth(BiNode* T)
{
	int l, r;
	if (!T)
	{
		return 0;
	}
	else
	{
		l = BTdepth(T->lChild);
		r = BTdepth(T->rChild);
		if (l > r)
		{
			return l + 1;
		}
		else
		{
			return r + 1;
		}
	}
}

void NodeNum(BiNode* T, int& num)
{
	if (T)
	{
		num++;
		NodeNum(T->lChild, num);
		NodeNum(T->rChild, num);
	}
}

void LeaveNum(BiNode* T, int& num)
{
	if (T)
	{
		if (T && (!(T->lChild) && !(T->rChild)))
		{
			num++;
		}
		LeaveNum(T->lChild, num);
		LeaveNum(T->rChild, num);
	}
}

void SearDoubleCh(BiNode* T, int& num)
{
	if (T)
	{
		if (T->lChild && T->rChild)
		{
			num++;
		}
		SearDoubleCh(T->lChild, num);
		SearDoubleCh(T->rChild, num);
	}
}

void SearchPar(BiNode* T, elemtype c, int& flag)
{
	if (T)
	{
		if (T->lChild && T->lChild->data == c)
		{
			flag = 1;
			cout << "Its parent node is '" << T->data << "'." << endl;
		}
		else if (T->rChild && T->rChild->data == c)
		{
			flag = 1;
			cout << "Its parent node is '" << T->data << "'." << endl;
		}
		else
		{
			SearchPar(T->lChild, c, flag);
			SearchPar(T->rChild, c, flag);
		}
	}
}

void SearchBro(BiNode* T, elemtype c, int& flag)
{
	if (T)
	{
		if (T->lChild)
		{
			if (T->lChild->data == c)
			{
				if (T->rChild)
				{
					flag = 1;
					cout << "Its right brother node is '" << T->rChild->data << "'." << endl;
				}
			}
		}
		if (T->rChild)
		{
			if (T->rChild->data == c)
			{
				if (T->lChild)
				{
					flag = 1;
					cout << "Its left brother node is '" << T->lChild->data << "'." << endl;
				}
			}
		}
		SearchBro(T->lChild, c, flag);
		SearchBro(T->rChild, c, flag);
	}
}

void SearChil(BiNode* T, elemtype c, int& flag)
{
	if (T)
	{
		if (T->data == c)
		{
			if (T->lChild)
			{
				flag = 1;
				cout << "Its left child node is '" << T->lChild->data << "'." << endl;
			}
			if (T->rChild)
			{
				flag = 1;
				cout << "Its right child node is '" << T->rChild->data << "'." << endl;
			}
		}
		else
		{
			SearChil(T->lChild, c, flag);
			SearChil(T->rChild, c, flag);
		}
	}
}

void LocateDepth(BiNode* T, elemtype c, int depth)
{
	if (T)
	{
		LocateDepth(T->lChild, c, ++depth);
		if (T->data == c)
		{
			cout << "Its depth is " << depth << "." << endl;
		}
		depth--;
		LocateDepth(T->rChild, c, ++depth);
	}
}

void ArrToTree(BiNode*& T, elemtype Tree[], int i, int len)
{
	if (i <= len && Tree[i])
	{
		if (Tree[i] != NULL)
		{
			T = new BiNode;
			T->data = Tree[i];
			T->lChild = NULL;
			T->rChild = NULL;
			ArrToTree(T->lChild, Tree, 2 * i, len);
			ArrToTree(T->rChild, Tree, 2 * i + 1, len);
		}
	}
}

void ExchanCh(BiNode*& T)
{
	if (T)
	{
		BiNode* u;
		u = T->lChild;
		T->lChild = T->rChild;
		T->rChild = u;
		ExchanCh(T->lChild);
		ExchanCh(T->rChild);
	}
}

void CopyTree(BiNode* T, BiNode*& T1)
{
	BiNode* u;
	if (T)
	{
		u = new BiNode;
		u->data = T->data;
		u->lChild = NULL;
		u->rChild = NULL;
		T1 = u;
		CopyTree(T->lChild, T1->lChild);
		CopyTree(T->rChild, T1->rChild);
	}
}

void SearchPath(BiNode*T, elemtype p[], int len)
{
	int i;
	if (T)
	{
		if (T->lChild == NULL && T->rChild == NULL)
		{
			cout << T->data << " ";
			for (i = len - 1; i >= 0; i--)
			{
				cout << p[i] << " ";
			}
			cout << endl;
		}
		else
		{
			p[len] = T->data;
			len++;
			SearchPath(T->lChild, p, len);
			SearchPath(T->rChild, p, len);
			len--;
		}
	}
}

void TreeToArr(BiNode* T, elemtype Arr[], int i, int len)
{
	if (T)
	{
		Arr[i] = T->data;
		TreeToArr(T->lChild, Arr, 2 * i, len);
		TreeToArr(T->rChild, Arr, 2 * i + 1, len);
	}
}

void TravUpToDown(BiNode* T)
{
	int len, depth, i, j = 0, num = 0;
	elemtype* Arr, * q;
	NodeNum(T, num);
	q = new elemtype[num];
	depth = BTdepth(T);
	len = (int)pow(2, depth);
	Arr = new elemtype[len];
	for (i = 0; i < len; i++)
	{
		*(Arr + i) = NULL;
	}
	for (i = 0; i < len; i++)
	{
		*(q + i) = NULL;
	}
	TreeToArr(T, Arr, 1, len);
	for (i = 1; i < len; i++)
	{
		if (*(Arr + i))
		{
			cout << *(Arr + i) << " ";
		}
	}
	cout << endl;
}

void SearchChPath(BiNode* T, elemtype p[], int len, elemtype x, int& flag)
{
	if (T)
	{
		if (T->data != x)
		{
			if (flag == 0)
			{
				p[len] = T->data;
				len++;
				SearchChPath(T->lChild, p, len, x, flag);
				SearchChPath(T->rChild, p, len, x, flag);
				len--;
			}
		}
		else
		{
			flag = 1;
		}
	}
}

elemtype SearchPa(BiNode* T, elemtype c, elemtype x)
{
	int depth = BTdepth(T);
	int j = 0, y = 0;
	elemtype p = NULL;
	elemtype* C, * X;
	C = new elemtype[depth];
	X = new elemtype[depth];
	for (int i = 0; i < depth; i++)
	{
		*(C + i) = NULL;
		*(X + i) = NULL;
	}
	SearchChPath(T, C, 0, c, y);
	y = 0;
	SearchChPath(T, X, 0, x, y);
	while (*(C + j) == *(X + j))
	{
		p = *(C + j);
		j++;
	}
	return p;
}

void SearchLong(BiNode* T, int& i, int depth, elemtype* Arr, int& p)
{
	if (T)
	{
		*(Arr + i) = T->data;
		i++;
		SearchLong(T->lChild, i, depth, Arr, ++p);
		SearchLong(T->rChild, i, depth, Arr, ++p);
		i--;
	}
	else
	{
		if (i == depth)
		{
			cout << "The longest is " << depth - 1 << " side: " << endl;
			for (int j = 0; j < depth; j++)
			{
				cout << *(Arr + j) << " ";
			}
			cout << endl;
			exit(0);
		}
	}
}

void CreatSubTree(BiNode* R, int f)
{
	BiNode* u;
	elemtype x;
	cin >> x;
	if (x != '/')
	{
		u = new BiNode;
		u->data = x;
		u->lChild = NULL;
		u->rChild = NULL;
		if (f == 1)
		{
			R->lChild = u;
		}
		else
		{
			R->rChild = u;
		}
		CreatSubTree(u, 1);
		CreatSubTree(u, 2);
	}
}

void CreatBiTree(BiNode*& BT)
{
	BiNode* u;
	elemtype x;
	cout << "Please enter the binary tree in the preamble sequance('/' indicates no subtree):" << endl;
	cin >> x;
	if (x == '/')
	{
		return;
	}
	BT = new BiNode;
	BT->data = x;
	BT->lChild = NULL;
	BT->rChild = NULL;
	u = BT;
	CreatSubTree(u, 1);
	CreatSubTree(u, 2);
}

bool ReadFileToArray(elemtype filename[10], elemtype strLine[100][3], int& nArrLen)
{
	FILE* pFile;
	elemtype str[1000];
	pFile = fopen("bt21.btr", "r");
	if (!pFile)
	{
		cout << "Fail to open the file!" << endl;
		return false;
	}
	else
	{
		if (fgets(str, 1000, pFile) != NULL)
		{
			if (strcmp(str, "BinaryTree\n") != 0)
			{
				cout << "File format ERROR!" << endl;
				fclose(pFile);
				return false;
			}
		}
		nArrLen = 0;
		while (fscanf(pFile, "%c %c %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF)
		{
			nArrLen++;
		}
		fclose(pFile);
	}
	return true;
}

bool ArrayToTree(BiNode*& T, char strLine[100][3], int nLen, int& nRow)
{
	if ((nRow >= nLen) || (nLen == 0))
	{
		return false;
	}
	T = new BiNode;
	T->data = strLine[nRow][0];
	T->lChild = NULL;
	T->rChild = NULL;
	int nNext = nRow;
	if (strLine[nNext][1] == '1')
	{
		nRow++;
		ArrayToTree(T->lChild, strLine, nLen, nRow);
	}
	if (strLine[nNext][2] == '1')
	{
		nRow++;
		ArrayToTree(T->rChild, strLine, nLen, nRow);
	}
	return true;
}

void graph()
{
	for (int i = 0; i < 70; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "*                            必做题                                  *" << endl;
	cout << "* 1.从文件读取二叉树（bt21.btr）                                     *" << endl;
	cout << "* 2.打印出二叉树的三种遍历序                                         *" << endl;
	cout << "* 3.按中序次序输出二叉树中各结点的值及其所对应的层次数               *" << endl;
	cout << "* 4.求二叉树的高度                                                   *" << endl;
	cout << "* 5.求二叉树的结点数                                                 *" << endl;
	cout << "* 6.求二叉树的叶子结点数                                             *" << endl;
	cout << "* 7.求二叉树的度为2的结点数                                          *" << endl;
	cout << "* 8.键盘输入一个元素,求其父节点                                      *" << endl;
	cout << "* 9.键盘输入一个元素x,求其兄弟节点                                   *" << endl;
	cout << "* 10.键盘输入一个元素x,求其子节点                                    *" << endl;
	cout << "* 11.键盘输入一个元素x,求其在树中的层次                              *" << endl;
	cout << "* 12.将按顺序方式存储在数组中的二叉树转换为二叉链表形式              *" << endl;
	cout << "* 13.交换二叉树中每个结点的左右孩子指针的值                          *" << endl;
	cout << "*                            选做题                                  *" << endl;
	cout << "* 14.复制一棵二叉树T到T1                                             *" << endl;
	cout << "* 15.输出二叉树从每个叶子结点到根结点的路径                          *" << endl;
	cout << "* 16.按层次打印二叉树                                                *" << endl;
	cout << "* 17.求2个结点最近的共同祖先                                         *" << endl;
	cout << "* 18.求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值    *" << endl;
	cout << "* 19.退出                                                            *" << endl;
	for (int i = 0; i < 70; i++)
	{
		cout << "*";
	}
	cout << endl;
}

#endif
