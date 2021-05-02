#ifndef _MERGR_H_
#define _MERGE_H_

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

void listMerge(seqList* L1, seqList* L2, seqList* L3)
{
	int i, j;
	i = 0;
	j = 0;
	while (i != L1->listLen && j != L2->listLen)
	{
		if (L3->listLen >= MAXLEN - 1)
		{
			printf("List Full!");
			exit(ERROR);
		}
		else
		{
			if (L1->data[i] < L2->data[j])
			{
				i++;
			}
			else if (L1->data[i] > L2->data[j])
			{
				j++;
			}
			else
			{
				L3->data[L3->listLen] = L1->data[i];
				i++;
				j++;
				L3->listLen++;
			}
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

void listPre(seqList* A, seqList* B, seqList* L)
{
	int i;
	if (A->listLen == 0 || B->listLen == 0)
	{
		printf("None, because one or both of your table have nothing. \n");
		exit(ERROR);
	}
	else if (L->listLen == 0)
	{
		printf("There is no num meet the criteria. \n");
	}
	else
	{
		printf("Sequence A, B(oringinal) and union-list L are following: \n");
		for (i = 0; i < A->listLen; i++)
		{
			printf("%d ", A->data[i]);
		}
		printf("\n");
		for (i = 0; i < B->listLen; i++)
		{
			printf("%d ", B->data[i]);
		}
		printf("\n");
		for (i = 0; i < L->listLen; i++)
		{
			printf("%d ", L->data[i]);
		}
	}
}
#endif