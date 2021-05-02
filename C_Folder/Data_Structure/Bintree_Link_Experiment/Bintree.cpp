#include"BiTree.h"

int main()
{
	BiNode* T{};
	int i = 21, j = 0, len = 0;
	elemtype Name[10] = "bt21.btr";
	elemtype strLine[100][3];
	graph();
	int key;
	cout << "Please enter the key:" << endl;
	cin >> key;
	while (key != 19)
	{
		switch (key)
		{
		case 1:{
			ReadFileToArray(Name, strLine, len);
			ArrayToTree(T, strLine, i, j);
			break; 
		}
		case 2:{
			PreOrder(T);
			cout << endl;
			InOrder(T);
			cout << endl;
			PostOrder(T);
			cout << endl;
			break; 
		}
		case 3:{
			InOrderDep(T, 1);
			break; 
		}
		case 4:{
			int depth;
			depth = BTdepth(T);
			cout << depth << endl;
			break; 
		}
		case 5: {
			int nodenum = 0;
			NodeNum(T, nodenum);
			cout << nodenum << endl;
			break;
		}
		case 6: {
			int leavenum = 0;
			LeaveNum(T, leavenum);
			cout << leavenum << endl;
			break;
		}
		case 7: {
			int dounum = 0;
			SearDoubleCh(T, dounum);
			cout << dounum << endl;
			break;
		}
		case 8: {
			elemtype a;
			int f = 0;
			cout << "Please input the data:" << endl;
			cin >> a;
			SearchPar(T, a, f);
			if (f == 0)
			{
				cout << "It has no parent node." << endl;
			}
			break;
		}
		case 9: {
			elemtype b;
			int f1 = 0;
			cout << "Please input the data:" << endl;
			cin >> b;
			SearchBro(T, b, f1);
			if (f1 == 0)
			{
				cout << "It has no brother node." << endl;
			}
			break;
		}
		case 10: {
			elemtype c;
			int f2 = 0;
			cout << "Please input the data:" << endl;
			cin >> c;
			SearChil(T, c, f2);
			if (f2 == 0)
			{
				cout << "It has no child node." << endl;
			}
			break;
		}
		case 11: {
			elemtype d;
			int f3 = 0;
			cout << "Please input the data:" << endl;
			cin >> d;
			LocateDepth(T, d, f3);
			break;
		}
		case 12: {
			BiNode* BT;
			int len, depth, i, j = 0, num = 0;
			elemtype* Arr;
			NodeNum(T, num);
			depth = BTdepth(T);
			len = (int)pow(2, depth);
			Arr = new elemtype[len];
			for (i = 0; i < len; i++)
			{
				*(Arr + i) = NULL;
			}
			TreeToArr(T, Arr, 1, len);
			ArrToTree(BT, Arr, 1, len);
			PreOrder(BT);
			cout << endl;
			break;
		}
		case 13: {
			ExchanCh(T);
			PreOrder(T);
			cout << endl;
			break;
		}
		case 14: {
			BiNode* T1;
			CopyTree(T, T1);
			PreOrder(T1);
			cout << endl;
			break;
		}
		case 15: {
			elemtype* Path;
			int e = 0;
			NodeNum(T, e);
			Path = new elemtype[e];
			SearchPath(T, Path, 0);
			break;
		}
		case 16: {
			TravUpToDown(T);
			break;
		}
		case 17: {
			elemtype g, h, l;
			cout << "Please enter them separated by 'Enter':" << endl;
			cin >> g >> h;
			l = SearchPa(T, g, h);
			cout << "The node is '" << l << "'." << endl;
			break;
		}
		case 18: {
			int s = BTdepth(T);
			elemtype* ARR;
			int z = 0;
			int g = 0;
			ARR = new elemtype[s];
			SearchLong(T, z, s, ARR, g);
			break;
		}
		}
		cout << "Please enter the key:" << endl;
		cin >> key;
	}
	return 0;
}