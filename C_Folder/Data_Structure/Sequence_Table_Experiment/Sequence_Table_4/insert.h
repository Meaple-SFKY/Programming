#ifndef _INSERT_H_
#define _INSERT_H_

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

void listInsert(seqList* L, elemtype x)
{
	int j;
	if (L->listLen == MAXLEN - 1)
	{
		printf("List Full! \n");
		exit(ERROR);
	}
	else
	{
		for (j = L->listLen - 1; x < L->data[j]; j--)
		{
			L->data[j + 1] = L->data[j];
		}
		j++;
		L->data[j] = x;
		L->listLen++;
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

void listPre(seqList* L)
{
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		printf("%d ", L->data[i]);
	}
}
#endif