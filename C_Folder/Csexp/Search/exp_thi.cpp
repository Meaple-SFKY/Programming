#include<iostream>

using namespace std;
 
int chessboard[8][8];
 
bool FindPath(int startI,int startJ) {
	int queueNumber;
	chessboard[startI][startJ] = 1;
	const int posI[8] = {1, 1, 2, 2, -1, -1, -2, -2};
	const int posJ[8] = {2, -2, 1, -1, 2, -2, 1, -1};
	int posCount = 0;
	int minPosCount;
	int posCountTemp;
	int nexI[8] = {0}, nexJ[8] = {0};
	int nowI = startI, nowJ = startJ;
	int nextI, nextJ;
	int nextnextI, nextnextJ;

	for (queueNumber = 2; queueNumber <= 64; queueNumber++) {
		posCount = 0;
		for (int k = 0; k < 8; k++) {
			nextI = nowI + posI[k];
			nextJ = nowJ + posJ[k];
			if (nextI >= 8 || nextI < 0 || nextJ >= 8 || nextJ < 0) {
				continue;
			}
			if (chessboard[nextI][nextJ] == 0) {
				nexI[posCount] = nextI;
				nexJ[posCount] = nextJ;
				posCount++;
			}
		}
		if (posCount == 0 && queueNumber < 63) {
			return false;
		}
		minPosCount = 8;
		for (int posNum = 0; posNum < posCount; posNum++) {
			posCountTemp = 0;
			for (int k = 0; k < 8; k++) {
				nextnextI = nexI[posNum] + posI[k];
				nextnextJ = nexJ[posNum] + posJ[k];
                if (nextnextI >= 8 || nextnextI < 0 || nextnextJ >= 8 || nextnextJ < 0) {
					continue;
				}
				if (chessboard[nextnextI][nextnextJ] == 0) {
					posCountTemp++;
				}
			}
			if (minPosCount > posCountTemp) {
				minPosCount = posCountTemp;
				nowI = nexI[posNum];
				nowJ = nexJ[posNum];
			}
		}
		chessboard[nowI][nowJ] = queueNumber;
	}
	return true;
}
 
 
int main(void) {
	int startI, startJ;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessboard[i][j] = 0;
		}
	}
	cout << "请输入开始节点的坐标，如(0 0): ";
	cin >> startI >> startJ;
	if (FindPath(startI,startJ)) {
		cout << "路径如下: " << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << chessboard[i][j] << '\t';
			}
			cout << endl;
		}
	}
	else {
		cout << "未找到路径" << endl;
    }
    
    return 0;
}