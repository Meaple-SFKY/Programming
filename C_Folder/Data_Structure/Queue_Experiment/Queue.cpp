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
	cout << "*  1.ѭ������  *" << endl << "*  2.������    *" << endl;
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
		cout << "*  1.��ʼ��һ������                                             *" << endl;
		cout << "*  2.����һ������                                               *" << endl;
		cout << "*  3.�ж��Ƿ�ӿ�                                               *" << endl;
		cout << "*  4.�ж��Ƿ����                                               *" << endl;
		cout << "*  5.���                                                       *" << endl;
		cout << "*  6.����                                                       *" << endl;
		cout << "*  7.ȡ��ͷԪ��                                                 *" << endl;
		cout << "*  8.��ǰ������Ԫ�صĸ���                                     *" << endl;
		cout << "*  9.��д�㷨ʵ�ֶ��������ֵĲ������������ӣ�ż�����ӣ�0������  *" << endl;
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
				cout << "* 1.�ֶ����� n ��Ԫ�� *" << endl;
				cout << "* 2.1~99ѭ�����      *" << endl;
				cout << "* 3.�����ַ�����      *" << endl;
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
				cout << "* 1.���ֶ������      *" << endl;
				cout << "* 2.�ַ��������      *" << endl;
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
		cout << "*  1.��ʼ��һ������                                             *" << endl;
		cout << "*  2.����һ������                                               *" << endl;
		cout << "*  3.�ж��Ƿ�ӿ�                                               *" << endl;
		cout << "*  4.�ж��Ƿ����                                               *" << endl;
		cout << "*  5.���                                                       *" << endl;
		cout << "*  6.����                                                       *" << endl;
		cout << "*  7.ȡ��ͷԪ��                                                 *" << endl;
		cout << "*  8.��ǰ������Ԫ�صĸ���                                     *" << endl;
		cout << "*  9.��д�㷨ʵ�ֶ��������ֵĲ������������ӣ�ż�����ӣ�0������  *" << endl;
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
				cout << "* 1.�ֶ����� n ��Ԫ�� *" << endl;
				cout << "* 2.1~99ѭ�����      *" << endl;
				cout << "* 3.�����ַ�����      *" << endl;
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
				cout << "* 1.���ֶ������      *" << endl;
				cout << "* 2.�ַ��������      *" << endl;
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