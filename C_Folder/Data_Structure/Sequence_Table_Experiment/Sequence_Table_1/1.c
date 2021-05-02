#include<stdio.h>
#include<stdlib.h>
#include"getelem.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	int i, num;
	L.listLen = 0;
	CreatList(&L);
	printf("Please input the location: \n");
	scanf_s("%d", &i);
	num = getElem(&L, i);
	printf("It is: ");
	printf("%d", num);
	return 0;
}