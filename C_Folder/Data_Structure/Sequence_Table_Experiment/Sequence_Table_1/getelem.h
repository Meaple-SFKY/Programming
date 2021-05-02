#ifndef _GETELEM_H_
#define _GETELEM_H_

#define MAXLEN 100
#define ERROR 0

typedef int elemtype;

typedef struct sList
{
	elemtype data[MAXLEN];
	int listLen;
}seqList;

int getElem(seqList* L, int i)
{
	int x = 0;
	if (L->listLen == 0)
	{
		printf("Table Null! \n");
		exit(ERROR);
	}
	if (i < 1 || i > L->listLen)
	{
		printf("ERROR!");
		exit(ERROR);
	}
	x = L->data[i - 1];
	return x;
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
#endif