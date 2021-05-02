#ifndef _SEEK_H_
#define _SEEK_H_

#include<iostream>

#define MAXLEN 50
#define LH 1
#define EH 0
#define RH -1

using namespace std;

typedef int elemtype;

int GetLen(elemtype a[])
{
	int i = 0;
	while (a[i] != -9999)
	{
		i++;
	}
	return i;
}

int BinSearch(elemtype a[], elemtype x)
{
	int len = GetLen(a);
	cout << len << endl;
	int i = 0;
	int mid, low = 0, high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x == a[mid])
		{
			cout << "The " << ++i << " times ----> " << "from " << low << " to " << high << " ----> Location: " << mid << ", data: " << a[mid] << endl;
			return mid;
		}
		else if (x < a[mid])
		{
			cout << "The " << ++i << " times ----> " << "from " << low << " to " << high << " ----> Location: " << mid << ", data: " << a[mid] << endl;
			high = mid - 1;
		}
		else
		{
			cout << "The " << ++i << " times ----> " << "from " << low << " to " << high << " ----> Location: " << mid << ", data: " << a[mid] << endl;
			low = mid + 1;
		}
	}
	return -1;
}

typedef struct node
{
	node* lChild;
	node* rChild;
	elemtype data;
}BSTree;

bool BSTreeIns(BSTree*& T, elemtype x)
{
	if (T == NULL)
	{
		T = new BSTree;
		T->data = x;
		T->lChild = NULL;
		T->rChild = NULL;
		return true;
	}
	else if (T->data == x)
	{
		return false;
	}
	else if (x < T->data)
	{
		return BSTreeIns(T->lChild, x);
	}
	else
	{
		return BSTreeIns(T->rChild, x);
	}
}

BSTree* CreatBST(elemtype a[])
{
	int len = GetLen(a);
	BSTree* T = NULL;
	int i = 0;
	while (i < len)
	{
		if (a[i] == -9999)
		{
			break;
		}
		else
		{
			if (BSTreeIns(T, a[i]))
			{
				i++;
			}
			else
			{
				return NULL;
			}
		}
	}
	return T;
}

BSTree* BSTSearch(BSTree* T, elemtype x)
{
	if (T)
	{
		if (T->data == x)
		{
			return T;
		}
		else if (x < T->data)
		{
			return BSTSearch(T->lChild, x);
		}
		else
		{
			return BSTSearch(T->rChild, x);
		}
	}
	return NULL;
}

BSTree* SearchPa(BSTree* T, elemtype x)
{
	if (T)
	{
		if (T->data == x)
		{
			return NULL;
		}
		else if (x < T->data)
		{
			if (T->lChild->data == x)
			{
				return T;
			}
			return SearchPa(T->lChild, x);
		}
		else
		{
			if (T->rChild->data == x)
			{
				return T;
			}
			return SearchPa(T->rChild, x);
		}
	}
	return NULL;
}

int SearchPaTemp(BSTree* T, elemtype x)
{
	if (T)
	{
		if (T->data == x)
		{
			return 0;
		}
		else if (x < T->data)
		{
			if (T->lChild->data == x)
			{
				return 1;
			}
			return SearchPaTemp(T->lChild, x);
		}
		else
		{
			if (T->rChild->data == x)
			{
				return 2;
			}
			return SearchPaTemp(T->rChild, x);
		}
	}
	return 3;
}

BSTree* SearchNextNode(BSTree* T)
{
	if (T)
	{
		return SearchNextNode(T->lChild);
		if (!(T->lChild))
		{
			return T;
		}
		return SearchNextNode(T->rChild);
	}
	return NULL;
}

BSTree* SearchNext(BSTree* T, elemtype x)
{
	if (T)
	{
		return SearchNext(T->lChild, x);
		if (T->data == x)
		{
			return SearchNextNode(T->rChild);
		}
		return SearchNext(T->rChild, x);
	}
	return NULL;
}

void BSTDelete(BSTree*& T, elemtype x)
{
	BSTree* u;
	BSTree* p;
	int i;
	u = BSTSearch(T, x);
	if (!u)
	{
		cout << "Fail to search the data!" << endl;
		return;
	}
	else
	{
		i = SearchPaTemp(T, x);
		p = SearchPa(T, x);
		if (!(u->lChild) && !(u->rChild))
		{
			delete u;
		}
		else if ((u->lChild) && !(u->rChild))
		{
			if (i == 0)
			{
				delete u;
			}
			else if (i == 1)
			{
				p->lChild = u->lChild;
				delete u;
			}
			else
			{
				p->rChild = u->lChild;
				delete u;
			}
		}
		else if (!(u->lChild) && (u->rChild))
		{
			if (i == 0)
			{
				delete u;
			}
			else if (i == 1)
			{
				p->lChild = u->rChild;
				delete u;
			}
			else
			{
				p->rChild = u->rChild;
				delete u;
			}
		}
		else if ((u->lChild) && (u->rChild))
		{
			BSTree* s = SearchNext(u, x);
			i = SearchPaTemp(T, s->data);
			p = SearchPa(T, s->data);
			if (i == 1)
			{
				p->lChild = NULL;
			}
			else
			{
				p->rChild = NULL;
			}
			s->lChild = u->lChild;
			s->rChild = u->rChild;
			delete u;
		}
	}
}

typedef struct BSTBT
{
	elemtype data;
	int bf;
	struct BSTBT* lChild, * rChild;
}BSTBtree;

void R_Roate(BSTBtree*& T)
{
	BSTBtree* u = T->lChild;
	T->lChild = u->rChild;
	u->rChild = T;
	T = u;
}

void L_Roate(BSTBtree*& T)
{
	BSTBtree* u = T->rChild;
	T->rChild = u->lChild;
	u->lChild = T;
	T = u;
}

void LTBalancee(BSTBtree*& T)
{
	BSTBtree* u = T->lChild;
	if (u)
	{
		if (u->bf == LH)
		{
			T->bf = u->bf = EH;
			R_Roate(T);
		}
		else if (u->bf == RH)
		{
			BSTBtree* s = u->rChild;
			if (s->bf == LH)
			{
				u->bf = EH;
				T->bf = RH;
			}
			else if (s->bf == EH)
			{
				u->bf = EH;
				T->bf = EH;
			}
			else
			{
				u->bf = LH;
				T->bf = EH;
			}
			s->bf = EH;
			L_Roate(T->lChild);
			R_Roate(T);
		}
		else
		{
		}
	}
}

void RTBalance(BSTBtree*& T)
{
	BSTBtree* u = T->rChild;
	if (u)
	{
		if (u->bf == RH)
		{
			T->bf = u->bf = EH;
			L_Roate(T);
		}
		else if (u->bf == LH)
		{
			BSTBtree* s = u->lChild;
			if (s->bf == LH)
			{
				u->bf = RH;
				T->bf = EH;
			}
			else if (s->bf == EH)
			{
				u->bf = EH;
				T->bf = EH;
			}
			else
			{
				u->bf = EH;
				T->bf = LH;
			}
			s->bf = EH;
			R_Roate(T->rChild);
			L_Roate(T);
		}
		else
		{
		}
	}
}

bool InserAVL(BSTBtree*& T, elemtype x, bool& flag)
{
	if (!T)
	{
		T = new BSTBtree;
		T->data = x;
		T->bf = EH;
		T->lChild = T->rChild = NULL;
		flag = true;
	}
	else
	{
		if (x == T->data)
		{
			flag = false;
			return false;
		}
		else if (x < T->data)
		{
			if (!InserAVL(T->lChild, x, flag))
			{
				return false;
			}
			if (flag)
			{
				if (T->bf == LH)
				{
					LTBalancee(T);
					flag = false;
				}
				else if (T->bf == EH)
				{
					flag = true;
					T->bf = LH;
				}
				else
				{
					flag = false;
					T->bf = EH;
				}
			}
		}
		else
		{
			if (!InserAVL(T->rChild, x, flag))
			{
				return false;
			}
			if (flag)
			{
				if (T->bf == LH)
				{
					T->bf = EH;
					flag = false;
				}
				else if (T->bf == EH)
				{
					flag = true;
					T->bf = RH;
				}
				else
				{
					RTBalance(T);
					flag = false;
				}
			}
		}
	}
	return true;
}

void Solution1()
{
	elemtype* a = NULL;
	int len;
	int num, j = 0;
	cout << "Please enter the length of you data: ";
	cin >> len;
	a = new elemtype[len + 1];
	cout << "Please input data: " << endl;
	while (j < len)
	{
		cin >> num;
		*(a + j) = num;
		j++;
	}
	*(a + j) = -9999;
	cout << "Please input the num you are searching: ";
	cin >> num;
	cout << "Location: " << BinSearch(a, num) << endl;
}

void Pre(BSTree* T)
{
	if (T)
	{
		cout << T->data << " ";
		Pre(T->lChild);
		Pre(T->rChild);
	}
}

void Solution2()
{
	elemtype* a = NULL;
	BSTree* T;
	int len;
	int num, j = 0;
	cout << "Please enter the length of you data: ";
	cin >> len;
	a = new elemtype[len + 1];
	cout << "Please input data: " << endl;
	while (j < len)
	{
		cin >> num;
		*(a + j) = num;
		j++;
	}
	*(a + j) = -9999;
	T = CreatBST(a);
	elemtype x;
	cout << "Please input the num you are inserting: ";
	cin >> x;
	if (BSTreeIns(T, x))
	{
		cout << "Success!" << endl;
		Pre(T);
		cout << endl;
	}
	else
	{
		cout << "Fail!" << endl;
	}
}

void Solution3()
{
	elemtype* a = NULL;
	BSTree* T, * u;
	int len;
	elemtype x;
	int num, j = 0;
	cout << "Please enter the length of you data: ";
	cin >> len;
	a = new elemtype[len + 1];
	cout << "Please input data: " << endl;
	while (j < len)
	{
		cin >> num;
		*(a + j) = num;
		j++;
	}
	*(a + j) = -9999;
	T = CreatBST(a);
	cout << "Please enter the num you're searching: ";
	cin >> x;
	u = BSTSearch(T, x);
	if (u)
	{
		cout << "Success!" << endl;
	}
	else
	{
		cout << "Fail!" << endl;
	}
}

void Solution4()
{
	elemtype* a = NULL;
	BSTree* T;
	int len;
	elemtype x;
	int num, j = 0;
	cout << "Please enter the length of you data: ";
	cin >> len;
	a = new elemtype[len + 1];
	cout << "Please input data: " << endl;
	while (j < len)
	{
		cin >> num;
		*(a + j) = num;
		j++;
	}
	*(a + j) = -9999;
	T = CreatBST(a);
	cout << "Please enter the num you're going to delete and end by '-9999': ";
	cin >> x;
	while (x != -9999)
	{
		BSTDelete(T, x);
		cin >> x;
	}
	Pre(T);
	cout << endl;
}

void PreB(BSTBtree* T)
{
	if (T)
	{
		cout << T->data << " ";
		PreB(T->lChild);
		PreB(T->rChild);
	}
}

void Solution5()
{
	elemtype* a = NULL;
	int len;
	int num, j = 0;
	cout << "Please enter the length of you data: ";
	cin >> len;
	a = new elemtype[len + 1];
	cout << "Please input data: " << endl;
	while (j < len)
	{
		cin >> num;
		*(a + j) = num;
		j++;
	}
	*(a + j) = -9999;
	BSTBtree* T{};
	int i = 0;
	bool flag;
	while (*(a + i) != -9999)
	{
		if (InserAVL(T, a[i], flag))
		{
			i++;
		}
	}
	PreB(T);
	cout << endl;
}

void Graph()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "* 1. 二分查找算法实现查找，给出查找过程依次所比较的元素（的下标）              *" << endl;
	cout << "* 2. 设计出在二叉排序树中插入结点的算法，在此基础上实现构建二叉排序树的算法    *" << endl;
	cout << "* 3. 设计算法在二叉排序树中查找指定值的结点                                    *" << endl;
	cout << "* 4. 设计算法在二叉排序树中删除特定值的结点                                    *" << endl;
	cout << "* 5. 设计算法以构造一棵平衡的二叉排序树来存放数组中的所有元素                  *" << endl;
	cout << "* 6. 退出                                                                      *" << endl;
	for (int i = 0; i < 80; i++)
	{
		cout << "*";
	}
	cout << endl;
}

#endif