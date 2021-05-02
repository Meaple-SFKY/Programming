#include<stdio.h>
#include<stdlib.h>
#include"insert.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	int i, num;
	initialList(&L);
	CreatList(&L);
	printf("Please input the location: \n");
	scanf_s("%d", &i);
	printf("Please input the num you're inserting: \n");
	scanf_s("%d", &num);
	listInsert(&L, num, i);
	listPre(&L);
	return 0;
}