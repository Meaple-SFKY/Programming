//复化梯形算法
#include <stdio.h> 
#include "function.h"

int main(void) {
    int segment;
    double lower, upper, high, temp = 0;
    double sum;

    printf("Please enter the lower limit, upper limit, number of segments: ");
    scanf("%lf %lf %d", &lower, &upper, &segment);

    high = (upper - lower) / segment;

    for (int i = 1; i < segment; i++) {
        temp += funOriginal(lower + i * high);
    }
    sum = high * (funOriginal(lower) + 2 * temp + funOriginal(upper)) / 2.0;
    printf("%lf\n", sum);

    return 0;
}