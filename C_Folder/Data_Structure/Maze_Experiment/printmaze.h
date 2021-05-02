#ifndef _PRINTMAZE_H_
#define _PRINTMAZE_H_

#include<iostream>

using namespace std;

void printmaze(int** p, int hight, int width)
{
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (*(*(p + i) + j) == 1)
            {
                cout << "¨€¨€";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

#endif