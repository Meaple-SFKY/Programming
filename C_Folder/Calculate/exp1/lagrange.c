#include <stdio.h>

const int N = 1000;

//拉格朗日插值算法
double lagrange(double abscissa[], double ordinate[], int n, double x) {
    double sum = 0.0, lValue[N];

    double temp_fir, temp_sec;

    for (int k = 0; k < n; k++) {
        temp_fir = 1.0;
        temp_sec = 1.0;
        for (int m = 0; m < n; m++) {
            if (m == k)
            {
                continue;
            }
            temp_fir *= (x - abscissa[m]);
            temp_sec *= (abscissa[k] - abscissa[m]);
        }

        lValue[k] = temp_fir / temp_sec;
    }

    for (int i = 0; i < n; i++) {
        sum += ordinate[i] * lValue[i];
    }

    return sum;
}

int main(void) {
    double abscissa[N], ordinate[N];
    double temp_x, answer;
    int num;

    printf("Please enter the number of interpolation nodes (less than %d): ", N);
    scanf("%d", &num);
    printf("Now, Please enter the abscissa and ordinate of these interpolation nodes:\n");

    for (int i = 0; i < num; i++) {
        printf("The abscissa and ordinate of the %d node: ", i + 1);
        scanf("%lf %lf", &abscissa[i], &ordinate[i]);
    }

    printf("Please enter the abscissa of the interpolation node to be solved: \n");
    scanf("%lf", &temp_x);

    answer = lagrange(abscissa, ordinate, num, temp_x);
    printf("Its ordinate is: %lf\n", answer);

    return 0;
}
