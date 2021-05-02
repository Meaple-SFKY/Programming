#ifndef _ARRAYTIME_H_
#define _ARRAYTIME_H_

#include<iostream>
#include<time.h>

using namespace std;

int* getnum(void)
{
    int* point = new int;

    int num = (rand() + 5) % 2;
    *point = num;
    return point;
}


int** getarray(int hight, int width)
{
    int** p = new int*[hight];
    for (int i = 0; i < hight; i++)
    {
        p[i] = new int[width];
    }
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            p[i][j] = *getnum();
        }
    }
    return p;
}

#endif