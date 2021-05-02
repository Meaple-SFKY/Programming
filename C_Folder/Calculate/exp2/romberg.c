#include <stdio.h> 
#include "function.h"

int main(void) {
    int iterator = 1;
    double lower, upper, error_limit, high;
    double temp_fir = 0, temp_sec = 0;
    double temp_thi = 0, temp_fou = 0;
    double temp_fif = 0, temp_six = 0;
    double temp_sev = 0, temp_eig = 1;
    double x_index, sum;

    printf("Please enter the lower limit, upper limit, number of segments: ");
    scanf("%lf %lf %lf", &lower, &upper, &error_limit);
    printf("K\t\tT\t\tS\t\tC\t\tR\n");

    high = upper - lower;
    temp_fir = high * (funOriginal(lower) + funOriginal(upper)) / 2.0;
    printf("0\t%lf\n", temp_fir);

    //龙贝格算法
    while (fabs(temp_eig - temp_sev) >= error_limit) {
        sum = 0;
        x_index = lower + high / 2.0;
        while (x_index < upper) {
            sum += funOriginal(x_index);
            x_index += high;
        }
        temp_sec = temp_fir / 2.0 + high * sum / 2.0;
        temp_fou = temp_sec + (temp_sec - temp_fir) / 3.0;
        if (iterator == 1) {
            iterator += 1;
            high /= 2.0;
            temp_fir = temp_sec;
            temp_thi = temp_fou;
            printf("1\t%lf\t%lf\n", temp_fir, temp_thi);
            continue;
        }
        temp_six = temp_fou + (temp_fou - temp_thi) / 15.0;
        if (iterator == 2) {
            iterator = iterator + 1;
            high = high / 2.0;
            temp_fir = temp_sec;
            temp_thi = temp_fou;
            temp_fif = temp_six;
            printf("2\t%lf\t%lf\t%lf\n", temp_fir, temp_thi, temp_fif);
            continue;
        }
        temp_eig = temp_six + (temp_six - temp_fif) / 63.0;
        iterator += 1;
        high /= 2.0;
        temp_fir = temp_sec;
        temp_thi = temp_fou;
        temp_fif = temp_six;
        temp_sev = temp_eig;
        printf("3\t%lf\t%lf\t%lf\t%lf\n", temp_fir, temp_thi, temp_fif, temp_sev);
    }

    return 0;
}