#include <iostream>
#include <string>
#include <vector>

using namespace std;

double poorQuotient(int n, vector<double>& vec_x, vector<double>& vec_y) {
    double sum = 0;
    double temp = 0;
    for (int i = 0; i < n + 1; i++) {
        temp = vec_y[i];
        for (int j = 0; j < n + 1; j++) {
            if (i != j) {
                temp /= (vec_x[i] - vec_x[j]);
            }
        }
        sum += temp;
    }
    return sum;
}

//牛顿插值算法
void Newton(int n1, vector<double>& vec_require, vector<double>& vec_x, vector<double>& vec_y, vector<double>& vec_ans) {
    double temp_exch = 0;
    for (int h = 0; h < n1; h++)
    {
        for (int i = 0; i < vec_x.size(); i++)
        {
            double temp = 1;
            double sum = poorQuotient(i, vec_x, vec_y);
            for (int j = 0; j < i; j++)
            {
                temp = temp * (vec_require[h] - vec_x[j]);
            }
            temp_exch += sum * temp;
        }
        vec_ans[h] = temp_exch;
        temp_exch = 0;
    }
}

int main() {
    char a = 'n';
    do {
        int n, n1;
        cout << "Please enter the number of interpolation nodes (less than 20): ";
        cin >> n;
        vector<double>X_index(n, 0);
        vector<double>Y_index(n, 0);

        cout << "Please enter the abscissa and ordinate of these interpolation nodes:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> X_index[i] >> Y_index[i];
        }
        cout << "Please enter the number of points requested: ";
        cin >> n1;
        vector<double> vec_require(n1, 0);
        vector<double> result(n1, 0);
        cout << "Please enter the abscissa of the interpolation point: ";
        for (int i = 0; i < n1; i++) {
            cin >> vec_require[i];
        }
        Newton(n1, vec_require, X_index, Y_index, result);
        cout << "The ordinates of the calculated interpolation points are respectively:" << endl;
        for (int h = 0; h < n1; h++) {
            cout << result[h] << '\t';
        }
        cout << endl;
        cout << "Continue or not? (y/n): ";
        cin >> a;
    } while (a == 'y');
    return 0;
}

/* 0 0                  
0.52359878 0.5
0.78539816 0.7071
1.04719755 0.8660
1.57079632 1
0.26179938 1.30899693 */