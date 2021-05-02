#include<stdio.h>
#include<stdlib.h>
#include"divide.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	seqList A, B;
	int i;
	initialList(&L);
	initialList(&A);
	initialList(&B);
	CreatList(&L);
	listDivide(&L, &A, &B);
	printf("Sequence L(oringinal) ,odd-list A and even-list B are following: \n");
	listPre(&L, &A, &B);
	return 0;
}