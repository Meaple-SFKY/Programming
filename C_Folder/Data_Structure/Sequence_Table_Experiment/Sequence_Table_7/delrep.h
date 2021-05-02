#ifndef _DELREP_H_
#define _DELREP_H_

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

void listDelrep(seqList* L)
{
	int i, j, k, l;
	j = 0;
	l = 0;
	for (i = 0; i < L->listLen - 1; i++)
	{
		if (L->data[i] == L->data[i + 1])
		{
			j++;
		}
	}
	i = 0;
	while (i < L->listLen - j - 1)
	{
		if (L->data[i] < L->data[i + 1])
		{
			i++;
		}
		else
		{
			k = i;
			while (L->data[i] >= L->data[k])
			{
				k++;
			}
			L->data[i + 1] = L->data[k];
			l++;
		}
	}
	L->listLen -= j;
	printf("Already move %d times.\n", l);
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