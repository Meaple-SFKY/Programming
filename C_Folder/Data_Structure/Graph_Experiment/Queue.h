#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<iostream>

using namespace std;

#define MaxLen 100

typedef int elemtype;

typedef struct CQueue
{
	elemtype data[MaxLen];
	int front;
	int rear;
}CirQueue;

void CQinitial(CirQueue& Q)
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

char outCQ(CirQueue& Q)
{
	if (CQempty(Q))
	{
		cout << "Circle queue is empty, operation failed!" << endl;
		return NULL;
	}
	else
	{
		elemtype C;
		C = Q.data[Q.front + 1];
		Q.front = (Q.front + 1) % MaxLen;
		return C;
	}
}

#endif