#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

#define MAXLEN 50
#define ERROR 0

typedef char elemtype;

typedef struct Stack
{
	elemtype data[MAXLEN];
	int top;
}seqStack;

typedef struct slStack
{
	elemtype data;
	struct slStack* next;
}node;

typedef struct slNode
{
	int data;
	struct slNode* next;
}Node;

void initialList(Node*& L)
{
	L->next = NULL;
}

void initialStack(seqStack& S)
{
	S.top = -1;
}

void initialnode(node*& M)
{
	M = new node;
	M->next = NULL;
}

bool stackEmpty(seqStack& S)
{
	if (S.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool nodeEmpty(node*& M)
{
	node* p = M->next;
	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool stackTop(seqStack& S, elemtype x)
{
	if (stackEmpty(S))
	{
		return false;
	}
	else
	{
		x = S.data[S.top];
		return true;
	}
}

bool nodeTop(node*& M, elemtype x)
{
	if (nodeEmpty(M))
	{
		return false;
	}
	else
	{
		x = M->next->data;
		return true;
	}
}

bool stackFull(seqStack& S)
{
	if (S.top == MAXLEN - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool pushStack(seqStack& S, elemtype x)
{
	if (stackFull(S))
	{
		return false;
	}
	else
	{
		S.top++;
		S.data[S.top] = x;
		return true;
	}
}

void pushNode(node*& M, elemtype x)
{
	node* L;
	L = new node;
	L->data = x;
	L->next = M->next;
	M->next = L;
}

bool popStack(seqStack& S, elemtype x)
{
	if (stackEmpty(S))
	{
		return false;
	}
	else
	{
		x = S.data[S.top];
		S.top--;
		cout << x;
		return true;
	}
}

char popNode(node*& M, elemtype x)
{
	node* L;
	if (M->next == NULL)
	{
		exit(0);
	}
	x = M->next->data;
	L = M->next;
	M->next = L->next;
	delete L;
	return x;
}

char popnode(node*& M)
{
	node* L;
	char x;
	if (M->next == NULL)
	{
		exit(0);
	}
	x = M->next->data;
	L = M->next;
	M->next = L->next;
	delete L;
	return x;
}

bool popStackS(seqStack& S, elemtype x)
{
	if (stackEmpty(S))
	{
		return false;
	}
	else
	{
		x = S.data[S.top];
		S.top--;
		return true;
	}
}

void tranStack(seqStack& S, int i)
{
	char c = NULL;
	char ch[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (i)
	{
		if (pushStack(S, ch[i % 16]))
		{
			i /= 16;
		}
	}
	while (popStack(S, c))
	{
		cout << c;
	}
	cout << endl;
}

void transnode(int i)
{
	node* M;
	initialnode(M);
	char c = NULL;
	char ch[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (i)
	{
		pushNode(M, ch[i % 16]);
		i /= 16;
	}
	while (M->next)
	{
		cout << popNode(M, c);
	}
	cout << endl;
}

void distingStack(seqStack& S)
{
	char str[50], c = NULL;
	int i = 0;
	bool flag = false;
	cout << "Please input the expression end by 'Enter': " << endl;
	cin >> str;
	while (str[i] != NULL)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
		{
			pushStack(S, str[i]);
		}
		else if (str[i] == ')' && S.data[S.top] == '(')
		{
			if (!popStackS(S, c))
			{
				cout << "Fail!" << endl;
			}
		}
		else if (str[i] == ']' && S.data[S.top] == '[')
		{
			if (!popStackS(S, c))
			{
				cout << "Fail!" << endl;
			}
		}
		else if (str[i] == '}' && S.data[S.top] == '{')
		{
			if (!popStackS(S, c))
			{
				cout << "Fail!" << endl;
			}
		}
		i++;
	}
	if (stackEmpty(S))
	{
		flag = true;
		cout << "Okay, it is!" << endl;
	}
	else
	{
		cout << "Oh, it isn't!" << endl;
	}
}

int Match(char e, char ch)
{
	if (e == '(' && ch == ')')
	{
		return 0;
	}
	else if (e == '[' && ch == ']')
	{
		return 0;
	}
	else if (e == '{' && ch == '}')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void distingNode()
{
	node* M;
	initialnode(M);
	char str[50], c = NULL;
	int i = 0;
	int flag = 0;
	cout << "Please input the expression end by 'Enter': " << endl;
	cin >> str;
	char* p = str;
	while (*p)
	{
		switch (*p)
		{
		case '(':
		case '[':
		case '{': pushNode(M, *p++);
			break;
		case ')':
			i = Match(popnode(M), ')');
			if (i == 1)
			{
				flag = 1;
			}
			p++;
			break;
		case ']':
			i = Match(popnode(M), ']');
			if (i == 1)
			{
				flag = 1;
			}
			p++;
			break;
		case '}':
			i = Match(popnode(M), '}');
			if (i == 1)
			{
				flag = 1;
			}
			p++;
			break;
		default: p++;
		}
	}
	if (nodeEmpty(M) && flag == 0)
	{
		cout << "Okay, it is!" << endl;
	}
	else
	{
		cout << "Oh, it isn't!" << endl;
	}
}

void CreatARR(int* p, const int n)
{
	int i, j;
	cout << "Please input nums of your queue separated by 'Space': " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		*(p++) = j;
	}
}

bool JudgeStack()
{
	int i, k, n, low = 0;
	cout << "Please input the length of you queue: " << endl;
	cin >> n;
	int* q = new int[n];
	CreatARR(q, n);
	for (i = 0; i < n; i++)
	{
		low = *(q + i);
		for (k = i; k < n; k++)
		{
			if (*(q + k) < *(q + i))
			{
				if (*(q + k) > low)
				{
					return false;
				}
				else
				{
					low = *(q + k);
				}
			}
		}
	}
	return true;
}

void graph(void)
{
	int k;
	for (k = 0; k < 73; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "* 1.ÄãºÃ?;                             * " << endl;
	cout << "* 2.ÄãºÃ*" << endl;
	for (k = 0; k < 73; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "Please input the key in front of you demand and end by '-1': " << endl;
}

#endif