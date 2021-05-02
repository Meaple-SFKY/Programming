#ifndef _DELETE_H_
#define _DELETE_H_

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

void listDelete(seqList* L, int i)
{
	int j;
	if (L->listLen == 0)
	{
		printf("Location Null! \n");
		exit(ERROR);
	}
	else if (i > L->listLen || i <= 0)
	{
		printf("Location Error! \n");
		exit(ERROR);
	}
	else
	{
		for (j = i - 1; j < L->listLen; j++)
		{
			L->data[j] = L->data[j + 1];
		}
		L->listLen--;
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