//复化辛普森算法
#include <stdio.h> 
#include "function.h"

int main(void) {
    int segment;
    double lower, upper, high, x_index, temp = 0;
    double sum;

    printf("Please enter the lower limit, upper limit, number of segments: ");
    scanf("%lf %lf %d", &lower, &upper, &segment);

    high = (upper - lower) / segment;
    x_index = funOriginal(lower + high / 2.0);

    for (int i = 1; i < segment; i++) {
        x_index += funOriginal(lower + i * high + high / 2.0);
        temp += funOriginal(lower + i * high);
    }
    sum = high * (funOriginal(lower) + 4 * x_index + 2 * temp + funOriginal(upper)) / 6.0;
    printf("%lf\n", sum);

    return 0;
}