#ifndef _HEADER_H_
#define _HEADER_H_

typedef int elemtype;

#define ERROR 0

typedef struct slNode
{
	elemtype data;
	struct slNode* next;
}node;

void listInitial(node*& L)
{
	L = new node;
	L->next = NULL;
}

int TailInsert(node*& L)
{
	elemtype x;
	node* p, * q;
	L = new node;
	p = L;
	cout << "Please input nums separated by 'Enter' and end by '-9999':" << endl;
	cin >> x;
	if (x == -9999)
	{
		return 1;
	}
	else
	{
		while (x != -9999)
		{
			q = new node;
			q->data = x;
			q->next = NULL;
			p->next = q;
			p = q;
			cin >> x;
		}
		return 0;
	}
}

int HeadInsert(node*& L)
{
	elemtype x;
	node* p;
	L = new node;
	L->next = NULL;
	cout << "Please input nums separated by 'Enter' and end by '-9999':" << endl;
	cin >> x;
	if (x == -9999)
	{
		return 1;
	}
	else
	{
		while (x != -9999)
		{
			p = new node;
			p->data = x;
			p->next = L->next;
			L->next = p;
			cin >> x;
		}
		return 0;
	}
}

void listDist(node* L)
{
	node* p = L;
	node* q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	if (p == NULL)
	{
		cout << "Succeed!" << endl;
	}
}

int listLen(node* L)
{
	int len = 0;
	node* p = L;
	while (p->next != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void elemLocate(node* L, int i)
{
	int j;
	node* p = L;
	if (i <= 0)
	{
		cout << "Location Error!" << endl;
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			if (p->next == NULL)
			{
				cout << "Location Error!" << endl;
				exit(ERROR);
			}
			else
			{
				p = p->next;
			}
		}
		cout << "Data located! It's " << p->data << "." << endl;
	}
}

void listInsert(node* L, int i, elemtype x)
{
	int j;
	node* p, * q;
	p = L;
	if (i <= 0)
	{
		cout << "Location Error!" << endl;
		exit(ERROR);
	}
	else
	{
		for (j = 0; j < i - 1; j++)
		{
			if (p->next->next == NULL)
			{
				cout <<"Location Error!" << endl;
				exit(ERROR);
			}
			p = p->next;
		}
		q = new node;
		q->data = x;
		q->next = p->next;
		p->next = q;
	}
}

node* getelem(node* L, elemtype x)
{
	node* p;
	p = L->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	cout <<"Data Failed Located!" << endl;
	return NULL;
}

void listDelete(node* L, int i)
{
	node* p, * q;
	p = L;
	int j;
	if (i <= 0)
	{
		cout << "Location Error!" << endl;
		exit(ERROR);
	}
	for (j = 0; j < i - 1; j++)
	{
		if (p->next->next == NULL)
		{
			cout << "Location Error!" << endl;
			exit(ERROR);
		}
		else
		{
			p = p->next;
		}
	}
	q = p->next;
	p->next = q->next;
	delete q;
}

void ListInsert(node* L, elemtype x)
{
	node* p = L;
	node* q = new node;
	if (q)
	{
		q->data = x;
		while (p->next != NULL && x >= p->next->data)
		{
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
	}
}

void listDivide(node* L, node* L1, node* L2)
{
	node* p = L->next;
	node* q = L1;
	node* r = L2;
	while (p != NULL)
	{
		if (p->data % 2 != 0)
		{
			node* s = new node;
			if (s)
			{
				s->data = p->data;
				s->next = NULL;
				q->next = s;
				q = q->next;
				p = p->next;
			}
		}
		else
		{
			node* t = new node;
			if (t)
			{
				t->data = p->data;
				t->next = NULL;
				r->next = t;
				r = r->next;
				p = p->next;
			}
		}
	}
}

void listMerge(node* L1, node* L2, node* L3)
{
	node* p = L1->next;
	node* q = L2->next;
	node* r = L3;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			p = p->next;
		}
		else if (p->data > q->data)
		{
			q = q->next;
		}
		else
		{
			node* s = new node;
			if (s)
			{
				s->data = p->data;
				r->next = s;
				r = r->next;
				p = p->next;
				q = q->next;
			}
		}
	}
	r->next = NULL;
}

void listDelrep(node* L)
{
	node* p = L->next;
	node* q;
	if (p == NULL)
	{
		cout << "List NULL!" << endl;
		exit(ERROR);
	}
	while (p->next != NULL)
	{
		if (p->data != p->next->data)
		{
			p = p->next;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
	}
}

void listUnion(node* L1, node* L2)
{
	node* p = L1;
	node* q = L2;
	node* s;
	while (p->next != NULL && q->next != NULL)
	{
		if (p->next->data == q->next->data)
		{
			s = q->next;
			q->next = s->next;
			delete s;
			p = p->next;
		}
		else if (p->next->data > q->next->data)
		{
			q = q->next;
		}
		else
		{
			p = p->next;
		}
	}
	if (p->next != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
	}
	p->next = L2->next;
	delete L2;
}

void listPre1(node* L1)
{
	node* p = L1->next;
	if (p == NULL)
	{
		cout << "List NULL!" << endl;
		exit(ERROR);
	}
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void listPre2(node* L, node* L1, node* L2)
{
	node* p = L->next;
	node* q = L1->next;
	node* r = L2->next;
	cout << "Original list(L), odd list(L1) and even list(L2) are following:" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	if (q == NULL)
	{
		cout << "No ODD num!";
	}
	else
	{
		while (q != NULL)
		{
			cout << q->data << " ";
			q = q->next;
		}
	}
	cout << endl;;
	if (r == NULL)
	{
		cout << "No EVEN num!" << endl;
	}
	else
	{
		while (r != NULL)
		{
			cout << r->data << " ";
			r = r->next;
		}
	}
}

void solution1()
{
	node* L;
	listInitial(L);
	if (TailInsert(L) == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listPre1(L);
	}
}

void solution2()
{
	node* L;
	listInitial(L);
	if (HeadInsert(L) == 1)
	{
		cout << "List Null!" << endl;
	}
	else 
	{
		listPre1(L);
	}
}

void solution3()
{
	node* L;
	listInitial(L);
	if (TailInsert(L) == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listDist(L);
	}
}

void solution4()
{
	node* L;
	int i;
	listInitial(L);
	if (TailInsert(L) == 1)
	{
		cout << "The length is: " << "0" << "." << endl;
	}
	else
	{
		i = listLen(L);
		cout << "The length is: " << i << "." << endl;
	}
}

void solution5()
{
	node* L;
	int i, j;
	listInitial(L);
	j = TailInsert(L);
	cout << "Please input the location:" << endl;
	cin >> i;
	if (j == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		elemLocate(L, i);
	}
}

void solution6()
{
	node* L;
	int i, j;
	elemtype x;
	listInitial(L);
	j = TailInsert(L);
	cout << "Please input the location and the num separated by 'Space':" << endl;
	cin >> i >> x;
	if (j == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listInsert(L, i, x);
		listPre1(L);
	}
}

void solution7()
{
	node* L;
	node* pd;
	int i;
	elemtype x;
	listInitial(L);
	i = TailInsert(L);
	cout << "Please input the num:" << endl;
	cin >> x;
	if (i == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		pd = getelem(L, x);
		if (pd)
		{
			cout << "Success!" << endl;
		}
		else
		{
			cout << "Fail!" << endl;
			exit(ERROR);
		}
	}
}

void solution8()
{
	node* L;
	int i, j;
	listInitial(L);
	j = TailInsert(L);
	cout << "Please input the location:" << endl;
	cin >> i;
	if (j == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listDelete(L, i);
		listPre1(L);
	}
}

void solution9()
{
	node* L;
	elemtype x;
	int i;
	listInitial(L);
	i = TailInsert(L);
	cout << "Please input the num:" << endl;
	cin >> x;
	if (i == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		ListInsert(L, x);
		listPre1(L);
	}
}

void solution10()
{
	node* L, *L1, *L2;
	listInitial(L);
	listInitial(L1);
	listInitial(L2);
	cout << "Creat original list L:" << endl;
	if (TailInsert(L) == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listDivide(L, L1, L2);
		listPre2(L, L1, L2);
	}
}

void solution11()
{
	node* L1, * L2, * L3;
	int i, j;
	listInitial(L1);
	listInitial(L2);
	listInitial(L3);
	cout << "Creat list1 L1:" << endl;
	i = TailInsert(L1);
	cout << "Creat list2 L2:" << endl;
	j = TailInsert(L2);
	if (i == 1 || j == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listMerge(L1, L2, L3);
		listPre1(L3);
	}
}

void solution12()
{
	node* L;
	listInitial(L);
	if (TailInsert(L) == 1)
	{
		cout << "List Null!" << endl;
	}
	else
	{
		listDelrep(L);
		listPre1(L);
	}
}

void solution13()
{
	node* L1, * L2;
	int i, j;
	listInitial(L1);
	listInitial(L2);
	cout << "Creat list1 L1:" << endl;
	i = TailInsert(L1);
	cout << "Creat list2 L2:" << endl;
	j = TailInsert(L2);
	if (i == 0 && j != 0)
	{
		listPre1(L1);
	}
	else if (i != 0 && j == 0)
	{
		node* p = L2->next;
		node* q = L2;
		L1->next = p;
		delete q;
		listPre1(L1);
	}
	else if (i != 0 && j != 0)
	{
		cout << "Each list is null!" << endl;
	}
	else
	{
		listUnion(L1, L2);
		listPre1(L1);
	}
}

#endif