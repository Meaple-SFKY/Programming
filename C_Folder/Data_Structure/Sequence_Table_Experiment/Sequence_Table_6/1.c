#include<stdio.h>
#include<stdlib.h>
#include"merge.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L1, L2;
	seqList L3;
	initialList(&L3);
	initialList(&L1);
	initialList(&L2);
	printf("Creat Sequence-table L1: \n");
	CreatList(&L1);
	printf("Creat Sequence-table L2: \n");
	CreatList(&L2);
	listMerge(&L1, &L2, &L3);
	listPre(&L1, &L2, &L3);

	return 0;
}