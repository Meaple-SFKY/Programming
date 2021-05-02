#include <iostream>
#include <cstdio>

using namespace std;
#define N 1000

typedef struct point {
    double x, y;
} Point;

int n_point;
int cnt = 0;
int is_intersect(int p1, int p2, int t1, int t2);
double get_abs(double t);
double cross_pro(int c, int x, int y);
double val;
Point point[N];

int solve(void);

int main(void) {
   
    while (cin >> n_point) {
        cnt++;
        val = 0;
        if (n_point == 0) {
            break;
        }
        for (int i = 0; i < n_point; i++) {
            cin >> point[i].x >> point[i].y;
        }
        if (cnt - 1) {
            cout << endl;
        }
        if (solve()) {
            val = 0.5 * get_abs(val);
            cout << "Figure" << cnt << " : " <<  val << endl;
        }
        else {
            cout << "Figure" << cnt << " : impossible" << endl;
        }
    }
}

int solve(void) {
    if (n_point < 3) {
        return 0;
    }
    for (int i = 0; i < n_point - 1; i++) {
        val += point[i].x * point[i + 1].y - point[i].y * point[i + 1].x;
        for (int j = 0; j <= i - 2; j++) {
            if (is_intersect(i, i + 1, j, j + 1)) {
                return 0;
            } 
        }
    }
    val += point[n_point - 1].x * point[0].y - point[n_point - 1].y * point[0].x;
    for (int j = 1; j <= n_point - 3; j++) {
        if (is_intersect(n_point - 1, 0, j, j + 1)) {
            return 0;
        }
    }
    return 1;
}


int is_intersect(int p1, int p2, int t1, int t2) {
    double tmp1 = cross_pro(p1, t1, t2);
    double tmp2 = cross_pro(p2, t1, t2);
    double tmp11 = cross_pro(t1, p1, p2);
    double tmp22 = cross_pro(t2, p1, p2);
    if (tmp1 * tmp2 <= 0 && tmp11 * tmp22 <= 0) {
        return 1;
    }
    return 0;
}

double cross_pro(int c, int x, int y) {
    double x1 = point[x].x - point[c].x;
    double x2 = point[y].x - point[c].x;
    double y1 = point[x].y - point[c].y;
    double y2 = point[y].y - point[c].y;
    return x1 * y2 - x2 * y1;
}

double get_abs(double t) {
    if (t < 0) {
        return -t;
    }
    return t;
}
