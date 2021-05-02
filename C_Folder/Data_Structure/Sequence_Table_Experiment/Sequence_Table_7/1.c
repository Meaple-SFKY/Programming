#include<stdio.h>
#include<stdlib.h>
#include"delrep.h"
#pragma warning(disable:4996)

int main(void)
{
	seqList L;
	initialList(&L);
	CreatList(&L);
	listDelrep(&L);
	listPre(&L);
	return 0;
}