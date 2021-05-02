#include"Sort.h"

int main()
{
	Graph();
	int key;
	cout << "Please enter the key and end by '-1': ";
	cin >> key;
	while (key != -1)
	{
		switch (key) {
		case 1: {
			solution1();
			break;
		}
		case 2: {
			solution2();
			break;
		}
		case 3: {
			solution3();
			break;
		}
		case 4: {
			solution4();
			break;
		}
		case 5: {
			solution5();
			break;
		}
		case 6: {
			solution6();
			break;
		}
		case -1:exit(0);
		}
		cout << "Please enter the key and end by '-1': ";
		cin >> key;
	}
	return 0;
}