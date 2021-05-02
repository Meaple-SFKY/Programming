#include<iostream>
using namespace std;

#include"Header.h"

int main(void)
{
	int i;
	cout << "Please input the key:" << endl;
	cin >> i;;
	switch (i){
	case 1:solution1(); break;
	case 2:solution2(); break;
	case 3:solution3(); break;
	case 4:solution4(); break;
	case 5:solution5(); break;
	case 6:solution6(); break;
	case 7:solution7(); break;
	case 8:solution8(); break;
	case 9:solution9(); break;
	case 10:solution10(); break;
	case 11:solution11(); break;
	case 12:solution12(); break;
	case 13:solution13(); break;
	default:cout << "Error!" << endl;
	}
	return 0;
}