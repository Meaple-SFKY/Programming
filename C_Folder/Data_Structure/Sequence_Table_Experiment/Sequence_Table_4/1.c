#include<stdio.h>
#include<stdlib.h>
#include"insert.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	int i;
	initialList(&L);
	CreatList(&L);
	printf("Please input the num you're inserting: \n");
	scanf_s("%d", &i);
	listInsert(&L, i);
	listPre(&L);
	return 0;
}