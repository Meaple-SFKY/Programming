#ifndef _TREE_H_
#define _TREE_H_

#include<iostream>
#include<queue>

using namespace std;

typedef int elemtype;

typedef struct TNode
{
	elemtype data;
	struct TNode* firstChild, * nextSibling;
}BT;

void LevelOrder(BT* T)
{
	queue<BT*>q;
	BT* u, * n, * p;
	if (!T)
	{
		return;
	}
	n = T;
	while (n)
	{
		p = n;
		q.push(p);
		while (!q.empty())
		{
			p = q.front();
			cout << (char)p->data << " ";
			u = p->firstChild;
			while (u)
			{
				p = u;
				q.push(p);
				u = u->nextSibling;
			}
			q.pop();
		}
		n = n->nextSibling;
	}
}

void destroy(BT* T)
{
	if (T)
	{
		destroy(T->firstChild);
		destroy(T->nextSibling);
		delete T;
	}
}

#endif