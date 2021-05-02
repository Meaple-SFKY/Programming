#include"Seek.h"

int main(void)
{
	Graph();
	int key;
	cout << "Please input the key: ";
	cin >> key;
	while (key != 6)
	{
		switch (key)
		{
		case 1: {
			Solution1();
			break;
		}
		case 2: {
			Solution2();
			break;
		}
		case 3: {
			Solution3();
			break;
		}
		case 4: {
			Solution4();
			break;
		}
		case 5: {
			Solution5();
			break;
		}
		default:break;
		}
		cout << "Please input the key: ";
		cin >> key;
	}
	return 0;
}