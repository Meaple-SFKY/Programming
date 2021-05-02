#include <iostream>
#include <string.h>

using namespace std;

int changeNum(char* str1, int m, char* str2, int n) {
	int** p = new int* [m];
	int x;
	for (x = 0; x < m; x++) {
		p[x] = new int[n];
	}
    
	for (x = 0; x < n; x++) {
		p[0][x] = x;
	}
    
	for (x = 0; x < m; x++) {
		p[x][0] = x;
	}

	int i, j;
	for (i = 1; i < m; i++) {
		for (j = 1; j < n; j++) {
			int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
			cost += p[i - 1][j - 1];
			p[i][j] = (cost < (p[i - 1][j] + 1)) ? cost : (p[i - 1][j] + 1);
			p[i][j] = (p[i][j] < (p[i][j - 1] + 1)) ? p[i][j] : (p[i][j - 1]);
		}
	}


	int mm = p[m - 1][n - 1];

	for (x = 0; x < m; x++) {
		delete[](p[x]);
	}
    
	return mm;
}

int main(void) {


	char str1[] = { "abc" };
	char str2[] = { "dabc" };
	int n = changeNum(str1, strlen(str1) + 1, str2, strlen(str2) + 1);

	cout << "num: " << n << endl;
	return 0;
}
