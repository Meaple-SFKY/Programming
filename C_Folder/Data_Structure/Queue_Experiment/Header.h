#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>

using namespace std;

#define MaxLen 100

typedef int elemtype;

typedef struct sQueue
{
	elemtype data[MaxLen];
	int front;
	int rear;
}CirQueue;

typedef struct CQueue
{
	char data[MaxLen];
	int front;
	int rear;
}CirCQueue;

void CQinitial(CirQueue& Q)
{
	Q.front = 0;
	Q.rear = 0;
}

void CQCinitial(CirCQueue& Q)
{
	Q.front = 0;
	Q.rear = 0;
}

bool CQempty(CirQueue& Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CQCempty(CirCQueue& Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CQfull(CirQueue& Q)
{
	if (Q.front == (Q.rear + 1) % MaxLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CQCfull(CirCQueue& Q)
{
	if (Q.front == (Q.rear + 1) % MaxLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enterCQ(CirQueue& Q, elemtype x)
{
	if (CQfull(Q))
	{
		cout << "Circle queue is full, operation failed!" << endl;
	}
	else
	{
		Q.rear = (Q.rear + 1) % MaxLen;
		Q.data[Q.rear] = x;
	}
}

void enterCCQ(CirCQueue& Q, char x)
{
	if (CQCfull(Q))
	{
		cout << "Circle queue is full, operation failed!" << endl;
	}
	else
	{
		Q.rear = (Q.rear + 1) % MaxLen;
		Q.data[Q.rear] = x;
	}
}

void outCQ(CirQueue& Q)
{
	if (CQempty(Q))
	{
		cout << "Circle queue is empty, operation failed!" << endl;
	}
	else
	{
		Q.front = (Q.front + 1) % MaxLen;
	}
}

elemtype CQFget(CirQueue& Q, elemtype x)
{
	if (CQempty(Q))
	{
		cout << "Circle queue is empty, operation failed!" << endl;
		return 0;
	}
	else
	{
		x = Q.data[(Q.front + 1) % MaxLen];
		return x;
	}
}

int CQlen(CirQueue& Q)
{
	return (Q.rear + MaxLen - Q.front) % MaxLen;
}

void CQprint(CirQueue& Q)
{
	if (CQempty(Q))
	{
		cout << "Circle queue is empty!" << endl;
	}
	else
	{
		int i = Q.front + 1;
		while (i != Q.rear + 1)
		{
			cout << Q.data[i] << " ";
			i++;
			i = i % MaxLen;
		}
		cout << endl;
	}
}

void CQCprint(CirCQueue& Q)
{
	if (CQCempty(Q))
	{
		cout << "Circle queue is empty!" << endl;
	}
	else
	{
		int i = Q.front + 1;
		while (i != Q.rear + 1)
		{
			cout << Q.data[i] << " ";
			i++;
			i = i % MaxLen;
		}
		cout << endl;
	}
}

void Cirent(CirQueue& Q)
{
	for (int i = 1; i < 100; i++)
	{
		enterCQ(Q, i);
	}
}

void CQcrea(CirQueue& Q)
{
	elemtype x;
	cout << "Creating circle queue¡­¡­¡­¡­" << endl;
	cout << "Please input nums separated with 'Space' and end with '-9999':" << endl;
	cin >> x;
	while (x != -9999)
	{
		enterCQ(Q, x);
		cin >> x;
	}
}

void CQenCH(CirCQueue& Q)
{
	char c;
	int i, k;
	cout << "Please input the length of your queue:" << endl;
	cin >> k;
	cout << "Please input your chars separated with 'Space':" << endl;
	for (i = 0; i < k; i++)
	{
		cin >> c;
		enterCCQ(Q, c);
	}
}

void CQopera(CirQueue& Q)
{
	int i;
	cout << "Please input the num and exit with '0': " << endl;
	cin >> i;
	while (i != 0)
	{
		if (i % 2 != 0)
		{
			enterCQ(Q, i);
			CQprint(Q);
		}
		else
		{
			outCQ(Q);
			CQprint(Q);
		}
		cin >> i;
	}
	cout << "Exited!" << endl;
}

typedef struct lNode
{
	elemtype data;
	struct lNode* next;
}node;

typedef struct clNode
{
	char data;
	struct clNode* next;
}cnode;

typedef struct
{
	node* front;
	node* rear;
	int len;
}linkQueue;

typedef struct
{
	cnode* front;
	cnode* rear;
	int len;
}linkCQueue;

void LQinitial(linkQueue& Q)
{
	Q.front = NULL;
	Q.rear = Q.front;
	Q.len = 0;
}

void LCQinitial(linkCQueue& Q)
{
	Q.front = NULL;
	Q.rear = Q.front;
	Q.len = 0;
}

bool LQempty(linkQueue& Q)
{
	return (Q.len == 0);
}

bool LQfull(linkQueue& Q)
{
	return (Q.len == MaxLen - 1);
}

bool LCQfull(linkCQueue& Q)
{
	return (Q.len == MaxLen);
}

void enterLQ(linkQueue& Q, elemtype x)
{
	node* q = new node;
	q->data = x;
	q->next = NULL;
	if (LQfull(Q))
	{
		cout << "Link Queue is full, operation failed!" << endl;
	}
	else if (Q.len == 0)
	{
		Q.rear = Q.front = q;
		Q.len++;
	}
	else
	{
		(Q.rear)->next = q;
		Q.rear = q;
		Q.len++;
	}
}

void enterLCQ(linkCQueue& Q, elemtype x)
{
	cnode* q = new cnode;
	q->data = x;
	q->next = NULL;
	if (LCQfull(Q))
	{
		cout << "Link Queue is full, operation failed!" << endl;
	}
	else if (Q.len == 0)

	{
		Q.rear = Q.front = q;
		Q.len++;
	}
	else
	{
		Q.rear->next = q;
		Q.rear = q;
		Q.len++;
	}
}

void outLQ(linkQueue& Q)
{
	node* q;
	if (LQempty(Q))
	{
		cout << "Link queue is empty, operation failed!" << endl;
	}
	else
	{
		q = Q.front;
		Q.front = q->next;
		delete q;
		Q.len--;
		if (Q.front == NULL && Q.len == 0)
		{
			Q.rear = Q.front;
		}
	}
}

void LQFget(linkQueue& Q, elemtype x)
{
	if (LQempty(Q))
	{
		cout << "Link queue is empty, operation failed!" << endl;
	}
	else
	{
		x = (Q.front)->data;
	}
}

int LQlen(linkQueue& Q)
{
	return Q.len;
}

void LQprint(linkQueue& Q)
{
	int i;
	node* q = Q.front;
	for (i = 0; i < Q.len; i++)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}

void LCQprint(linkCQueue& Q)
{
	int i;
	cnode* q = Q.front;
	for (i = 0; i < Q.len; i++)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}

void LQcrea(linkQueue& Q)
{
	elemtype x;
	cout << "Please input nums separated with 'Space' and end with '-9999':" << endl;
	cin >> x;
	while (x != -9999)
	{
		enterLQ(Q, x);
		cin >> x;
	}
}

void cirLQcrea(linkQueue& Q)
{
	elemtype x;
	for (x = 1; x < 100; x++)
	{
		enterLQ(Q, x);
	}
}

void LCQcrea(linkCQueue& Q)
{
	char x;
	int k, i;
	cout << "Please input the length of your queue:" << endl;
	cin >> k;
	cout << "Please input chars separated with 'Space':" << endl;
	for (i = 0; i < k; i++)
	{
		cin >> x;
		enterLCQ(Q, x);
	}
}

void LQopera(linkQueue& Q)
{
	int i;
	cout << "Please input the key and exit with '0': " << endl;
	cin >> i;
	while (i != 0)
	{
		if (i % 2 != 0)
		{
			enterLQ(Q, i);
			LQprint(Q);
		}
		else
		{
			outLQ(Q);
			LQprint(Q);
		}
		cin >> i;
	}
}

#endif
