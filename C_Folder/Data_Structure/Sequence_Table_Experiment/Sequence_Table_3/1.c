#include<stdio.h>
#include<stdlib.h>
#include"delete.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	int i;
	initialList(&L);
	CreatList(&L);
	printf("Please input the location: \n");
	scanf_s("%d", &i);
	listDelete(&L, i);
	listPre(&L);
	return 0;
}