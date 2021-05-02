#include<stdio.h>
#include<math.h>

double fun_fir(double x) {
    return pow(x, 3) - x - 1;
}

double fun_sec(double x) {
    return 3 * pow(x, 2) - 1;
}

void newton(double x_begin, double error_limit, int itMax, int downMax) {
    int temp = 0, i, i_temp;
    double l, x_index, l_temp;

    printf("appRoot\t\tdownFact\tnumIte\tnumDown\n");
    while (temp < itMax) {
        if (fun_sec(x_begin) == 0) {
            printf("Singular sign\n\n");
            return;
        }
        else {
            i = 0;
            l = 1;
            l_temp = l;
            i_temp = i;

            while(1) {
                x_index = x_begin - l * fun_fir(x_begin) / fun_sec(x_begin);
                if (fabs(fun_fir(x_index)) > fabs(fun_fir(x_begin))) {
                    i += 1;
                    l *= 0.5;
                    if (i >= downMax) {
                        printf("Please re-enter the initial value:\n\n");
                        return;
                    }
                    printf("%lf\t%lf\t%d\t%d\n", x_index, l , temp , i);
                    l_temp = l;
                    i_temp = i;
                }
                else {
                    break;
                }
            }

            if (fabs(x_index - x_begin) < error_limit) {
                printf("%lf\n\n", x_index);
                return;
            }
            else {
                if (temp > 0) {
                    printf("%lf\t%lf\t%d\t%d\n", x_index, l_temp, temp, i_temp);
                }
                temp += 1;
                x_begin = x_index;
            }
        }
    }
    printf("Iteration fails.\n\n");
    return;
}

int main(void) {
    double x_begin, error_limit;
    int iteNum, downNum;
    printf("Please enter the initial value, error limit, the maximum number of iterations, the maximum number of downhill:\n");
    scanf("%lf %lf %d %d", &x_begin, &error_limit, &iteNum, &downNum);
    newton(x_begin, error_limit, iteNum, downNum);
    return 0;
}