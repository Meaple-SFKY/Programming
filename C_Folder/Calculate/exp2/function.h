#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <math.h>

double funOriginal(double x) {
    if(x==0) {
        return 1;
    }
    else {
        return sin(x)/x;
    }
}

#endif