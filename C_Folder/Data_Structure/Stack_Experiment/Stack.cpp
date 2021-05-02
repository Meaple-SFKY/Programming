#include"Header.h"
#include<stdlib.h>

int main(void)
{
	int i = 0, j;
	int key = -2;
	seqStack S, Q;
	initialStack(S);
	initialStack(Q);

	while (key)
	{
		graph();
		cin >> key;
		switch (key) {
		case 1:
			cout << "Please input the num you are conversing: ";
			cin >> i;
			tranStack(S, i);
			system("pause");
			system("cls");
			continue;
		case 2:
			distingStack(S);
			system("pause");
			system("cls");
			continue;
		case 3:
			cout << "Please input the num you are conversing: ";
			cin >> j;
			transnode(j);
			system("pause");
			system("cls");
			continue;
		case 4:
			distingNode();
			system("pause");
			system("cls");
			continue;
		case 5:
			if (JudgeStack())
			{
				cout << "Okay, it is!" << endl;
			}
			else
			{
				cout << "Oh, no, it isn't!" << endl;
			}
			system("pause");
			system("cls");
			continue;
		case -1: goto L;
		default: 
			cout << "Key ERROR!" << endl;
			system("pause");
			system("cls");
			continue;;
		}
	L: break;
	}
	return 0;
}