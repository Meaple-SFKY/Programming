#include<iostream>
#include"GraphMatrix.h"

using namespace std;

int main()
{
	Graph G;
	BT* T;
	int path[MaxVerNum];
	int side[MaxVerNum];
	int Path[MaxVerNum][MaxVerNum];
	int Side[MaxVerNum][MaxVerNum];
	Menu();
	int i1[MaxVerNum];
	int v[MaxVerNum] = { 0 };
	int vlt[MaxVerNum] = { 0 };
	int key;
	cout << "Please enter the key: ";
	cin >> key;
	while (key != 12)
	{
		switch (key)
		{
		case 1: {
			getGraph(G);
			cout << "Finished!" << endl;
			break;
		}
		case 2: {
			cout << "The DFS is:  ";
			DFSTraverse(G, 1);
			cout << endl;
			cout << "The BFS is:  ";
			BFSTraverse(G, 1);
			cout << endl;
			break;
		}
		case 3: {
			cout << "The number of edges is " << getSidesNum(G) << endl;
			break;
		}
		case 4: {
			cout << "Please enter the ver: ";
			int i;
			cin >> i;
			cout << "Level Traverse are following: " << endl;
			cout << "The DFS Tree is: ";
			LevelOrder(DFSForest(G, T, i));
			cout << endl;
			break;
		}
		case 5: {
			cout << "Please enter the ver: ";
			int i;
			cin >> i;
			cout << "Level Traverse are following: " << endl;
			cout << "The BFS Tree is: ";
			LevelOrder(BFSForest(G, T, i));
			cout << endl;
			break;
		}
		case 6: {
			int i;
			cout << "Please enter the starting point: ";
			cin >> i;
			Prim(G, i);
			break;
		}
		case 7: {
			Kruskal(G);
			cout << endl;
			break;
		}
		case 8: {
			int i;
			cout << "Please enter the starting point: ";
			cin >> i;
			Dijkstra(G, path, side, i);
			printDijsktra(G, path, side, i);
			cout << endl;
			break;
		}
		case 9: {
			floyd(G, Side, Path);
			printFloyd(G, Side, Path);
			break;
		}
		case 10: {
			printTopoList(G, i1, v);
			cout << endl;
			break;
		}
		case 11: {
			TopologicalSort(G, i1, v);
			antiTopologicalSort(G, vlt, v);
			printCriticalPath(G, i1, vlt, v);
			cout << endl;
			break;
		}
		case 12: {
			exit(0);
		}
		default:break;
		}
		cout << "Please enter the key: ";
		cin >> key;
	}
	return 0;
}