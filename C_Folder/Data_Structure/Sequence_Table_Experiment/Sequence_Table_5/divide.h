#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#define MAXLEN 100
#define ERROR 0

typedef int elemtype;

typedef struct sList
{
	elemtype data[MAXLEN];
	int listLen;
}seqList;

void initialList(seqList* L)
{
	L->listLen = 0;
}

void listDivide(seqList* L, seqList* A, seqList* B)
{
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		if (L->data[i] % 2 == 1)
		{
			A->data[A->listLen] = L->data[i];
			A->listLen++;
		}
		else
		{
			B->data[B->listLen] = L->data[i];
			B->listLen++;
		}
	}
}

void CreatList(seqList* L)
{
	int i, j, n;
	elemtype elem[MAXLEN];
	printf("Please input the length of your data: \n");
	scanf_s("%d", &n);
	printf("Please input your number separated by 'Enter': \n");
	for (j = 0; j < n; j++)
	{
		scanf_s("%d", &elem[j]);
	}
	for (i = 0; i < n; i++)
	{
		L->data[i] = elem[i];
		L->listLen++;
	}
}

void listPre(seqList* L, seqList* A, seqList* B)
{
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
	if (A->listLen == 0)
	{
		printf("No odd num!");
	}
	else
	{
		for (i = 0; i < A->listLen; i++)
		{
			printf("%d ", A->data[i]);
		}
	}
	printf("\n");
	if (B->listLen == 0)
	{
		printf("No even num!");
	}
	else
	{
		for (i = 0; i < B->listLen; i++)
		{
			printf("%d ", B->data[i]);
		}
	}
}
#endif