#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct wall {
    double x, z[5];
} w[22];

int n;
double e[101][101];

bool hathes(int a, int b, int w1, int w2) {
    if (b - a < 2) {
        return 1;
    }
    double x1 = w[a].x, x2 = w[b].x, y1 = w[a].z[w1], y2 = w[b].z[w2];
    double k = (y1 - y2) / (x1 - x2), t = y1 - x1 * k;
    for (int i = a + 1;i < b;i++) {
        double y = k * w[i].x + t;
        if (y<w[i].z[1] || (y > w[i].z[2] && y < w[i].z[3]) || y>w[i].z[4]) {
            return 0;
        }
    }
    return 1;
}

void addedge(int a, int b, int w1, int w2) {
    if (!hathes(a, b, w1, w2)) {
        return;
    }
    double x1 = w[a].x, x2 = w[b].x, y1 = w[a].z[w1], y2 = w[b].z[w2];
    e[a * 4 + w1][b * 4 + w2] = e[b * 4 + w2][a * 4 + w1] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//计算两点间距离，建边
}

int main(void) {
    cin >> n;
    memset(e, 127, sizeof(e));
    for (int i = 1; i <= n; i++) {
        cin >> w[i].x;
        for (int j = 1; j < 5; j++) {
            cin >> w[i].z[j];
        }
    }
    w[0].x = 0;
    w[++n].x = 10;
    for (int i = 1; i < 5; i++) {
        w[0].z[i] = w[n].z[i] = 5;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k < 5; k++) {
                for (int l = 1; l < 5; l++) {
                    addedge(i, j, k, l);
                }
            }
        }
    }
    for (int i = 0; i < 101; i++) {
        e[i][i] = 0;
    }
    for (int k = 1; k <= n * 4 + 4; k++) {
        for (int i = 1; i <= n * 4 + 4; i++) {
            for (int j = 1; j <= n * 4 + 4; j++) {
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    cout << e[1][n * 4 + 1] << endl;
    return 0;
}
