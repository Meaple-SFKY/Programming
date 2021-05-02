#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int M = 4;
const int N = 4;
int MaxSum(int n, int* a);
int MaxSum2(int m, int n, int a[M][N]);

int main(void) {
    int a[][N] = { {0, -2, -7, 0,} ,{ 9 ,2, -6, 2,}, {-4, 1, -4, 1}, { -1, 8, 0, -2} };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "数组a最大连续和为:" << MaxSum2(M, N, a) << endl;

    return 0;
}

int MaxSum2(int m, int n, int a[M][N]) {
    int sum = 0;
    int* b = new int[n];
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n;k++) {
            b[k] = 0;
        }

        for (int j = i;j < m;j++) {
            for (int k = 0; k < n; k++) {
                b[k] += a[j][k];
                int max = MaxSum(n, b);
                if (max > sum) {
                    sum = max;
                }
            }
        }
    }
    return sum;
}

int MaxSum(int n, int* a) {
    int sum1 = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (b > 0) {
            b += a[i];
        }
        else {
            b = a[i];
        }
        if (b > sum1) {
            sum1 = b;
        }
    }
    return sum1;
}

