#include<iostream>
#include"tf.h"

int main()
{
	int key;
	pTree T;
	Graph();
	cout << "Please enter the key: ";
	cin >> key;
	while (key != 9)
	{
		switch (key)
		{
		case 1: {
			initialTree(T);
			char A[11] = "F20.tre";
			CreateTreeFromFile(A, T);
			cout << "Finished!" << endl;
			break;
		}
		case 2: {
			Solution1(T);
			break;
		}
		case 3: {
			Solution2(T);
			break;
		}
		case 4: {
			Solution3(T);
			break;
		}
		case 5: {
			Solution4(T);
			break;
		}
		case 6: {
			Solution5(T);
			break;
		}
		case 7: {
			Solution6(T);
			break;
		}
		case 8: {
			Solution7(T);
			break;
		}
		case 9: {
			exit(0);
		}
		default: {
			cout << "Key Error!" << endl;
			break;
		}
	}
		cout << "Please enter the key: ";
		cin >> key;
	}
	return 0;
}