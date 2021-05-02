#include"Header.h"

int main()
{
	int i, key;
	elemtype j = 0;
	for (i = 0; i < 16; i++)
	{
		cout << '*';
	}
	cout << endl;
	cout << "*  1.循环队列  *" << endl << "*  2.链队列    *" << endl;
	for (i = 0; i < 16; i++)
	{
		cout << '*';
	}
	cout << endl;
	cout << "Please input the key in front of the topic:" << endl;
	cin >> key;
	if (key == 1)
	{
		CirQueue Q;
		CirCQueue P;
		system("cls");
		for (i = 0; i < 65; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "*  1.初始化一个队列                                             *" << endl;
		cout << "*  2.创建一个队列                                               *" << endl;
		cout << "*  3.判断是否队空                                               *" << endl;
		cout << "*  4.判断是否队满                                               *" << endl;
		cout << "*  5.入队                                                       *" << endl;
		cout << "*  6.出队                                                       *" << endl;
		cout << "*  7.取队头元素                                                 *" << endl;
		cout << "*  8.求当前队列中元素的个数                                     *" << endl;
		cout << "*  9.编写算法实现对输入数字的操作（奇数出队，偶数出队，0结束）  *" << endl;
		for (i = 0; i < 65; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Please input the key in front of the topic and exit with '-1':" << endl;
		cin >> key;
		while (key != -1)
		{
			switch (key) {
			case 1:
				CQinitial(Q);
				CQCinitial(P);
				cout << "Queue initialed!" << endl;
				break;
			case 2:
				cout << "***********************" << endl;
				cout << "* 1.手动输入 n 个元素 *" << endl;
				cout << "* 2.1~99循环入队      *" << endl;
				cout << "* 3.创建字符队列      *" << endl;
				cout << "***********************" << endl;
				cout << "Please input the key:" << endl;
				cin >> key;
				if (key == 1)
				{
					CQcrea(Q);
				}
				else if (key == 2)
				{
					Cirent(Q);
				}
				else if (key == 3)
				{
					CQenCH(P);
				}
				else
				{
					break;
				}
				break;
			case 3:
				if (CQempty(Q))
				{
					cout << "Yes, it is empty!" << endl;
				}
				else
				{
					cout << "No, it isn't empty!" << endl;
				}
				break;
			case 4:
				if (CQfull(Q))
				{
					cout << "Yes, it is full!" << endl;
				}
				else
				{
					cout << "No, it isn't full!" << endl;
				}
				break;
			case 5:
				cout << "***********************" << endl;
				cout << "* 1.数字队列入队      *" << endl;
				cout << "* 2.字符队列入队      *" << endl;
				cout << "***********************" << endl;
				cout << "Please input the key:" << endl;
				cin >> key;
				if (key == 1)
				{
					CQcrea(Q);
					CQprint(Q);
				}
				else if (key == 2)
				{
					CQenCH(P);
					CQCprint(P);
				}
				else
				{
					break;
				}
				break;
			case 6:
				outCQ(Q);
				CQprint(Q);
				break;
			case 7:
				j = CQFget(Q, j);
				cout << j << endl;
				break;
			case 8:
				j = CQlen(Q);
				cout << "It's length is " << j << "." << endl;
				break;
			case 9:
				CQopera(Q);
				break;
			default:exit(0);
			}
			cout << "Please input the key in front of the topic and exit with '-1':" << endl;
			cin >> key;
		}
	}
	else if (key == 2)
	{
		system("cls");
		linkQueue Q;
		linkCQueue P;
		for (i = 0; i < 65; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "*  1.初始化一个队列                                             *" << endl;
		cout << "*  2.创建一个队列                                               *" << endl;
		cout << "*  3.判断是否队空                                               *" << endl;
		cout << "*  4.判断是否队满                                               *" << endl;
		cout << "*  5.入队                                                       *" << endl;
		cout << "*  6.出队                                                       *" << endl;
		cout << "*  7.取队头元素                                                 *" << endl;
		cout << "*  8.求当前队列中元素的个数                                     *" << endl;
		cout << "*  9.编写算法实现对输入数字的操作（奇数出队，偶数出队，0结束）  *" << endl;
		for (i = 0; i < 65; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Please input the key in front of the topic and exit with '-1':" << endl;
		cin >> key;
		while (key != -1)
		{
			switch (key) {
			case 1:
				LQinitial(Q);
				LCQinitial(P);
				cout << "Queue initialed!" << endl;
				break;
			case 2:
				cout << "***********************" << endl;
				cout << "* 1.手动输入 n 个元素 *" << endl;
				cout << "* 2.1~99循环入队      *" << endl;
				cout << "* 3.创建字符队列      *" << endl;
				cout << "***********************" << endl;
				cout << "Please input the key:" << endl;
				cin >> key;
				if (key == 1)
				{
					LQcrea(Q);
				}
				else if (key == 2)
				{
					cirLQcrea(Q);
				}
				else if (key == 3)
				{
					LCQcrea(P);
				}
				{
					break;
				}
				break;
			case 3:
				if (LQempty(Q))
				{
					cout << "Yes, it is empty!" << endl;
				}
				else
				{
					cout << "No, it isn't empty!" << endl;
				}
				break;
			case 4:
				if (LQfull(Q))
				{
					cout << "Yes, it is full!" << endl;
				}
				else
				{
					cout << "No, it isn't full!" << endl;
				}
				break;
			case 5:
				cout << "***********************" << endl;
				cout << "* 1.数字队列入队      *" << endl;
				cout << "* 2.字符队列入队      *" << endl;
				cout << "***********************" << endl;
				cout << "Please input the key:" << endl;
				cin >> key;
				if (key == 1)
				{
					LQcrea(Q);
					LQprint(Q);
				}
				else if (key == 2)
				{
					LCQcrea(P);
					LCQprint(P);
				}
				break;
			case 6:
				outLQ(Q);
				LQprint(Q);
				break;
			case 7:
				LQFget(Q, j);
				cout << j << endl;
				break;
			case 8:
				j = LQlen(Q);
				cout << "It's length is " << j << "." << endl;
				break;
			case 9:
				LQopera(Q);
				break;
			default:exit(0);
			}
			cout << "Please input the key in front of the topic and exit with '-1':" << endl;
			cin >> key;
		}
	}
	else
	{
		cout << "Exited!" << endl;
	}
	return 0;
}