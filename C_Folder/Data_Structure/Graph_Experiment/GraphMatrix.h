#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_

#include<iostream>
#include<cstring>
#include"grpAdjMatrix.h"
#include"createGrpAdjMatrix.h"
#include"Queue.h"
#include<queue>
#include"Tree.h"
#include<stack>

using namespace std;
typedef int elemtype;

bool getGraph(Graph& G)
{
	char filename[15];
	cout << "Please enter the name of your file: ";
	cin >> filename;
	if (CreateGrpFromFile(filename, G))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DFS(Graph G, elemtype v)
{
	elemtype w;
	visit(G, v);
	w = firstAdj(G, v);
	while (w != 0)
	{
		if (visited[w] == false && (G.AdjMatrix[v][w] >= 1) && (G.AdjMatrix[v][w]) < INF)
		{
			DFS(G, w);
		}
		w = nextAdj(G, v, w);
	}
}

void DFSTraverse(Graph& G, int v)
{
	int i;
	for (i = 1; i < MaxVerNum + 1; i++)
	{
		visited[i] = false;
	}
	for (v; v >= 1; v--)
	{
		if (visited[v] == false)
		{
			DFS(G, v);
		}
	}
	v++;
	for (v; v < MaxVerNum + 1; v++)
	{
		if (visited[v] == false)
		{
			DFS(G, v);
		}
	}
}

void BFS(Graph G, elemtype v)
{
	elemtype w;
	CirQueue Q;
	CQinitial(Q);
	visit(G, v);
	enterCQ(Q, v);
	while (!CQempty(Q))
	{
		v = outCQ(Q);
		w = firstAdj(G, v);
		while (w != 0)
		{
			if (!visited[w] && (G.AdjMatrix[v][w] >= 1) && (G.AdjMatrix[v][w]) < INF)
			{
				visit(G, w);
				enterCQ(Q, w);
			}
			w = nextAdj(G, v, w);
		}
	}
}

void BFSTraverse(Graph G, int v)
{
	int i;
	for (i = 1; i < MaxVerNum + 1; i++)
	{
		visited[i] = false;
	}
	for (v; v >= 1; v--)
	{
		if (!visited[v])
		{
			BFS(G, v);
		}
	}
	v++;
	for (v; i < MaxVerNum + 1; v++)
	{
		if (!visited[v])
		{
			BFS(G, v);
		}
	}
}

int getSidesNum(Graph G)
{
	int i = G.ArcNum;
	return i;
}

void DFSTree(Graph G, int v, BT*& T)
{
	int w, first = 1;
	BT* p, * q;
	q = T;
	visited[v] = true;
	w = firstAdj(G, v);
	while (w != 0)
	{
		if (!visited[w] && G.AdjMatrix[v][w] >= 1 && G.AdjMatrix[v][w] < INF)
		{
			p = new BT;
			p->firstChild = NULL;
			p->nextSibling = NULL;
			p->data = G.Data[w];
			if (first)
			{
				T->firstChild = p;
				first = 0;
			}
			else
			{
				q->nextSibling = p;
			}
			q = p;
			DFSTree(G, w, q);
		}
		w = nextAdj(G, v, w);
	}
}

BT* DFSForest(Graph& G, BT*& T, int v)
{
	int i;
	BT* p, * q = NULL;
	T = NULL;
	for (i = 1; i < G.VerNum; i++)
	{
		visited[i] = false;
	}
	for (v; v >= 1; v--)
	{
		if (!visited[v])
		{
			p = new BT;
			p->firstChild = NULL;
			p->nextSibling = NULL;
			p->data = G.Data[v];
			if (!T)
			{
				T = p;
				q = T;
			}
			else
			{
				q->nextSibling = p;
			}
			q = p;
			DFSTree(G, v, p);
		}
	}
	for (v += 1; v <= G.VerNum; v++)
	{
		if (!visited[v])
		{
			p = new BT;
			p->firstChild = NULL;
			p->nextSibling = NULL;
			p->data = G.Data[v];
			if (!T)
			{
				T = p;
				q = T;
			}
			else
			{
				q->nextSibling = p;
			}
			q = p;
			DFSTree(G, v, p);
		}
	}
	return T;
}

void BFSTree(Graph& G, BT*& T, int v)
{
	int w;
	bool first = true;
	BT* p, * q;
	queue<int> Q;
	if (!T)
	{
		T = new BT;
		T->data = G.Data[v];
		visited[v] = true;
		T->firstChild = NULL;
		T->nextSibling = NULL;
	}
	p = T;
	Q.push(v);
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();
		w = firstAdj(G, v);
		first = true;
		while (w != 0)
		{
			if (!visited[w] && G.AdjMatrix[v][w] >= 1 && G.AdjMatrix[v][w] < INF)
			{
				Q.push(w);
				visited[w] = true;
				q = new BT;
				q->data = G.Data[w];
				q->firstChild = NULL;
				q->nextSibling = NULL;
				if (first)
				{
					p->firstChild = q;
					first = false;
				}
				else
				{
					p->nextSibling = q;
				}
				p = q;
			}
			w = nextAdj(G, v, w);
		}
	}
}

BT* BFSForest(Graph& G, BT*& T, int v)
{
	int i;
	BT* p, * q = NULL;
	T = NULL;
	for (i = 1; i <= G.VerNum; i++)
	{
		visited[i] = false;
	}
	for (v; v >= 1; v--)
	{
		if (!visited[v])
		{
			visited[v] = true;
			p = new BT;
			p->firstChild = NULL;
			p->nextSibling = NULL;
			p->data = G.Data[v];
			if (!T)
			{
				T = p;
				q = T;
			}
			else
			{
				q->nextSibling = p;
			}
			q = p;
			BFSTree(G, p, v);
		}
	}
	for (v++; v <= G.VerNum; v++)
	{
		if (!visited[v])
		{
			visited[v] = true;
			p = new BT;
			p->firstChild = NULL;
			p->nextSibling = NULL;
			p->data = G.Data[v];
			if (!T)
			{
				T = p;
				q = T;
			}
			else
			{
				q->nextSibling = p;
			}
			q = p;
			BFSTree(G, p, v);
		}
	}
	return T;
}

typedef struct edge
{
	int v;
	cellType eWeight;
}MinEdgeType;

bool HasEdge(Graph& G, int vBegin, int vEnd, int& eWeight)
{
	int f = false;
	if (G.AdjMatrix[vBegin][vEnd] != INF)
	{
		eWeight = G.AdjMatrix[vBegin][vEnd];
		f = true;
		return f;
	}
	else
	{
		eWeight = G.AdjMatrix[vBegin][vEnd];
		return f;
	}
}

void initialEdge(Graph& G, MinEdgeType TE[], int vID)
{
	int i;
	int eWeight;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (HasEdge(G, vID, i, eWeight))
		{
			TE[i].v = vID;
			TE[i].eWeight = eWeight;
		}
		else
		{
			TE[i].eWeight = INF;
		}
	}
}

int getMinEdge(Graph& G, MinEdgeType TE[])
{
	int eMin = INF;
	int i, j = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false && TE[i].eWeight < eMin)
		{
			j = i;
			eMin = TE[i].eWeight;
		}
	}
	return j;
}

void updateTE(Graph& G, MinEdgeType TE[], int vID)
{
	int i;
	int eWeight;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false)
		{
			if (HasEdge(G, vID, i, eWeight) && eWeight < TE[i].eWeight)
			{
				TE[i].v = vID;
				TE[i].eWeight = eWeight;
			}
		}
	}
}

void PrintEdge(Graph& G, MinEdgeType TE[], int vID)
{
	int i;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (i != vID)
		{
			cout << "(" << G.Data[i] << "," << G.Data[TE[i].v] << ")" << "  ";
		}
	}
	cout << endl;
}

void Prim(Graph& G, int vID)
{
	MinEdgeType TE[MaxVerNum + 1];
	int i;
	int curID;
	for (i = 1; i <= G.VerNum; i++)
	{
		visited[i] = false;
	}
	initialEdge(G, TE, vID);
	visited[vID] = true;
	for (i = 1; i < G.VerNum; i++)
	{
		curID = getMinEdge(G, TE);
		visited[curID] = true;
		updateTE(G, TE, curID);
	}
	PrintEdge(G, TE, vID);
}

typedef struct edgetype
{
	int vBegin;
	int vEnd;
	int eWeight;
}EdgeType;

void getEdge(Graph& G, EdgeType edges[])
{
	int i, v;
	int k = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		v = firstAdj(G, i);
		while (v)
		{
			edges[k].vBegin = i;
			edges[k].vEnd = v;
			edges[k].eWeight = G.AdjMatrix[i][v];
			v = nextAdj(G, i, v);
			k++;
		}
	}
}

EdgeType getMinEdge(Graph& G, EdgeType edges[], bool edgeUsed[], int& n)
{
	EdgeType minEdge;
	cellType wMin = INF;
	int i;
	int M;
	if (G.gKind == UDG || G.gKind == UDN)
	{
		M = G.ArcNum * 2;
	}
	else {
		M = G.ArcNum;
	}
	for (i = 0; i < M; i++)
	{
		if (edgeUsed[i] == false && edges[i].eWeight < wMin)
		{
			wMin = edges[i].eWeight;
			minEdge.eWeight = edges[i].eWeight;
			minEdge.vBegin = edges[i].vBegin;
			minEdge.vEnd = edges[i].vEnd;
			n = i;
		}
	}
	return minEdge;
}

void printTreeEdge(Graph& G, EdgeType treeEdges[])
{
	int i;
	for (i = 0; i < G.VerNum - 1; i++)
	{
		cout << "(" << G.Data[treeEdges[i].vEnd] << "," << G.Data[treeEdges[i].vBegin] << ")" << "  ";
	}
}

void Kruskal(Graph& G)

{
	int conVerID[MaxVerNum];
	EdgeType edges[MaxVerNum * MaxVerNum];
	EdgeType treeEdges[MaxVerNum];
	bool edgeUsed[MaxVerNum * MaxVerNum];
	EdgeType minEdge;
	int i, j;
	int k = 0;
	int conID;
	int n;
	getEdge(G, edges);
	int M;
	if (G.gKind == UDG || G.gKind == UDN)
	{
		M = G.ArcNum * 2;
	}
	else {
		M = G.ArcNum;
	}
	for (i = 0; i < M; i++)
	{
		edgeUsed[i] = false;
	}
	for (i = 1; i <= G.VerNum; i++)
	{
		conVerID[i - 1] = i;
	}
	for (i = 1; i < G.VerNum; i++)
	{
		minEdge = getMinEdge(G, edges, edgeUsed, n);
		while (conVerID[minEdge.vBegin - 1] == conVerID[minEdge.vEnd - 1])
		{
			edgeUsed[n] = 1;
			minEdge = getMinEdge(G, edges, edgeUsed, n);
		}
		treeEdges[i - 1] = minEdge,
			conID = conVerID[minEdge.vEnd - 1];
		for (j = 1; j <= G.VerNum; j++)
		{
			if (conVerID[j - 1] == conID)
			{
				conVerID[j - 1] = conVerID[minEdge.vBegin - 1];
			}
		}
		edgeUsed[n] = true;
	}
	printTreeEdge(G, treeEdges);
}

void Dijkstra(Graph& G, int path[], int dist[], int vID)
{
	int solved[MaxVerNum];
	int i, j, v;
	cellType minDist;
	for (i = 1; i <= G.VerNum; i++)
	{
		solved[i - 1] = 0;
		dist[i - 1] = G.AdjMatrix[vID][i];
		if (dist[i - 1] != INF)
		{
			path[i - 1] = vID;
		}
		else {
			path[i - 1] = -1;
		}
	}
	solved[vID - 1] = 1;
	dist[vID - 1] = 0;
	path[vID - 1] = -1;
	for (i = 1; i <= G.VerNum; i++)
	{
		minDist = INF;
		for (j = 1; j <= G.VerNum; j++)
		{
			if (solved[j - 1] == 0 && dist[j - 1] < minDist)
			{
				v = j;
				minDist = dist[j - 1];
			}
		}
		if (minDist == INF)
		{
			return;
		}
		cout << "Choose ver:" << G.Data[v] << "---distance:" << minDist << endl;
		solved[v - 1] = 1;
		for (j = 1; j <= G.VerNum; j++)
		{
			if (solved[j - 1] == 0 && (minDist + G.AdjMatrix[v][j] < dist[j - 1]))
			{
				dist[j - 1] = minDist + G.AdjMatrix[v][j];
				path[j - 1] = v;
			}
		}
	}
}

void printDijsktra(Graph& G, int path[], int dist[], int vID)
{
	int sPath[MaxVerNum];
	int vPre;
	int top = -1;
	int i, j;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.Data[vID] << " -> " << G.Data[i];
		if (dist[i - 1] == INF)
		{
			cout << "No path." << endl;
		}
		else
		{
			cout << "The shortest distance is: " << dist[i - 1] << endl;
			cout << "The path is: ";
		}
		top++;
		sPath[top] = i;
		vPre = path[i - 1];
		while (vPre != -1)
		{
			top++;
			sPath[top] = vPre;
			vPre = path[vPre - 1];
		}
		if (dist[i - 1] != INF)
		{
			for (j = top; j >= 0; j--)
			{
				cout << G.Data[sPath[j]] << " ";
			}
		}
		top = -1;
		cout << endl;
	}
}

void floyd(Graph& G, cellType dist[MaxVerNum][MaxVerNum], int path[MaxVerNum][MaxVerNum])
{
	int i, j, m;
	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			dist[i - 1][j - 1] = G.AdjMatrix[i][j];
			if (i != j && G.AdjMatrix[i][j] < INF)
			{
				path[i - 1][j - 1] = i;
			}
			else {
				path[i - 1][j - 1] = -1;
			}
		}
	}
	for (m = 1; m <= G.VerNum; m++)
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			for (j = 1; j <= G.VerNum; j++)
			{
				if (i != j && dist[i - 1][m - 1] + dist[m - 1][j - 1] < dist[i - 1][j - 1])
				{
					dist[i - 1][j - 1] = dist[i - 1][m - 1] + dist[m - 1][j - 1];
					path[i - 1][j - 1] = path[m - 1][j - 1];
				}
			}
		}
	}
}

void printFloyd(Graph& G, cellType dist[MaxVerNum][MaxVerNum], int path[MaxVerNum][MaxVerNum])
{
	int i, j, k;
	int Path[MaxVerNum];
	int vPre;
	int top = -1;
	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			if (i != j)
			{
				cout << G.Data[i] << " --> " << G.Data[j] << endl;
				if (dist[i - 1][j - 1] == INF)
				{
					cout << "No path." << endl;
				}
				else {
					cout << "The shortest distance is: " << dist[i - 1][j - 1] << endl;
					cout << "The path is: ";
				}
				if (dist[i - 1][j - 1] != INF)
				{
					top++;
					Path[top] = j;
					vPre = path[i - 1][j - 1];
					while (i != vPre && vPre != -1)
					{
						top++;
						Path[top] = vPre;
						vPre = path[i - 1][vPre - 1];
					}
					top++;
					Path[top] = vPre;
					for (k = top; k >= 0; k--)
					{
						cout << G.Data[Path[k]] << " ";
					}
					cout << endl;
				}
				top = -1;
			}
		}
		top = -1;
		cout << endl;
	}
}

void getIndegree(Graph& G, int Indegree[])
{
	int i, j;
	for (i = 1; i <= G.VerNum; i++)
	{
		int k = 0;
		for (j = 1; j <= G.VerNum; j++)
		{
			if (G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF)
			{
				k++;
			}
		}
		Indegree[i] = k;
	}
}

void TopSort(Graph& G)
{
	int inDegree[MaxVerNum];
	int Num = G.VerNum;
	getIndegree(G, inDegree);
	for (int p = 0; p <= Num; p++)
	{
		for (int i = 1; i <= Num; i++)
		{
			if (inDegree[i] == 0 && G.AdjMatrix[i][i] != INF)
			{
				cout << G.Data[i] << "\t";
				G.AdjMatrix[i][i] = INF;
				for (int j = 1; j <= Num; j++)
				{
					G.AdjMatrix[i][j] = INF;
					G.AdjMatrix[j][i] = INF;
				}
			}
			getIndegree(G, inDegree);
		}
	}
}

void getInDegree(Graph& G, int inds[])
{
	int i, j;
	int k = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			if (G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF)
			{
				k++;
			}
		}
		inds[i] = k;
		k = 0;
	}
}

int TopologicalSort(Graph& G, int topoList[], int vet[])
{
	int inds[MaxVerNum];
	stack<int> S;
	int i;
	int v;
	int vCount = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		vet[i] = 0;
		inds[i] = 0;
		topoList[i - 1] = -1;
	}
	getInDegree(G, inds);
	for (i = 1; i <= G.VerNum; i++)
	{
		if (inds[i] == 0)
		{
			S.push(i);
		}
	}
	while (!S.empty())
	{
		v = S.top();
		S.pop();
		topoList[vCount] = v;
		vCount++;
		for (i = 1; i <= G.VerNum; i++)
		{
			if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF)
			{
				if (!(--inds[i]))
				{
					S.push(i);
				}
				if (vet[v] + G.AdjMatrix[v][i] > vet[i])
				{
					vet[i] = vet[v] + G.AdjMatrix[v][i];
				}
			}
		}
	}
	if (vCount == G.VerNum)
		return 1;
	else
		return 0;
}

void printTopoList(Graph& G, int topoList[], int vet[])
{
	int i;
	if (TopologicalSort(G, topoList, vet))
	{
		cout << "Topological sequence:";
		for (i = 0; i < G.VerNum; i++)
		{
			cout << G.Data[topoList[i]] << " ";
		}
		for (i = 0; i < G.VerNum; i++)
		{
			cout << endl;
			cout << "Numbering:  " << G.Data[topoList[i]] << "  Latest time:  " << vet[topoList[i]];
		}
	}
	else {
		cout << "Failed, because there is a ring." << endl;
	}
}

void getOutDegree(Graph& G, int outds[])
{
	int i, j;
	int k = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF)
			{
				k++;
			}
		}
		outds[i] = k;
		k = 0;
	}
}

int antiTopologicalSort(Graph& G, int vlt[], int vet[])
{
	int outds[MaxVerNum];
	stack<int> S;
	int i;
	int v;
	int vCount = 0;
	int max = 0;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (max < vet[i])
		{
			max = vet[i];
		}
	}
	for (i = 1; i <= G.VerNum; i++)
	{
		vlt[i] = max;
	}
	for (i = 1; i <= G.VerNum; i++)
	{
		outds[i] = 0;
	}
	getOutDegree(G, outds);
	for (i = 1; i <= G.VerNum; i++)
	{
		if (outds[i] == 0)
		{
			S.push(i);
		}
	}
	while (!S.empty())
	{
		v = S.top();
		S.pop();
		vCount++;
		for (i = 1; i <= G.VerNum; i++)
		{
			if (G.AdjMatrix[i][v] >= 1 && G.AdjMatrix[i][v] < INF)
			{
				if (!(--outds[i]))
				{
					S.push(i);
				}
				if (vlt[v] - G.AdjMatrix[i][v] < vlt[i])
				{
					vlt[i] = vlt[v] - G.AdjMatrix[i][v];
				}
			}
		}
	}
	if (vCount == G.VerNum)
		return 1;
	else
		return 0;
}

void printAntiTopoList(Graph& G, int topoList[], int vlt[], int vet[])
{
	int i;
	if (antiTopologicalSort(G, vlt, vet))
	{
		cout << "Topological sequence:";
		for (i = 0; i < G.VerNum; i++)
		{
			cout << G.Data[topoList[i]] << " ";
		}
		for (i = 0; i < G.VerNum; i++)
		{
			cout << endl;
			cout << "Numbering:  " << G.Data[topoList[i]] << "  Latest time:  " << vlt[topoList[i]];
		}
	}
	else {
		cout << "Failed, because there is a ring." << endl;
	}
}

void printCriticalPath(Graph& G, int topoList[], int vlt[], int vet[])
{
	int i = 0, j = 0, k = 0, v = 0;
	int vPre = 0;
	if (!TopologicalSort(G, topoList, vet))
	{
		cout << "No topological sequence!" << endl;
		return;
	}
	cout << "The critical path is: ";
	i = G.VerNum;
	k = topoList[v];
	while (k != vPre && k <= G.VerNum)
	{
		if (vet[k] == vlt[k])
		{
			if (k != vPre)
			{
				cout << G.Data[k] << " ";
			}
			vPre = k;
			for (j = 1; j <= G.VerNum; j++)
			{
				if (G.AdjMatrix[k][j] >= 1 && G.AdjMatrix[k][j] < INF)
				{
					if (vet[j] == vlt[j])
					{
						break;
					}
				}
			}
		}
		k = j;
	}
}

void Menu()
{
	cout << "********************************************************************************" << endl;
	cout << "* 1. 数据文件创建图                                                            *" << endl;
	cout << "* 2. 打印出图（网）的两种遍历序                                                *" << endl;
	cout << "* 3. 求给定图中的边（或弧）的数目                                              *" << endl;
	cout << "* 4. 对给定的图G及出发点v0，深度优先遍历图G，并构造出相应的生成树或生成森林    *" << endl;
	cout << "* 5. 对给定的图G及出发点v0，广度优先遍历图G，并构造出相应的生成树或生成森林    *" << endl;
	cout << "* 6. 实现Prim算法，求图G的最小生成树                                           *" << endl;
	cout << "* 7. 实现Kruskal算法，求图G的最小生成树                                        *" << endl;
	cout << "* 8. 实现Dijkstra算法，求图G指定顶点到其余顶点之间的最短路径                   *" << endl;
	cout << "* 9. 实现Floyd算法，求图G各顶点之间的最短路径                                  *" << endl;
	cout << "* 10. 求解图G的拓扑序列                                                        *" << endl;
	cout << "* 11. 求解AOE网的关键路径                                                      *" << endl;
	cout << "* 12. 退出                                                                     *" << endl;
	cout << "*********************************************************************************" << endl;
}

#endif