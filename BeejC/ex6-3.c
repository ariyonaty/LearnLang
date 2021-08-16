#include <stdio.h>

int main(void)
{
    // array initializing

    int a[5] = {22, 23, 25}; // same as: int a[5] = {22,23,25,0,0}
    int b[10] = {0}; // init to all zeros 
    int c[] = {1,2,3}; // same as int c[3] ...

    // multidimensional
    int x[2][3] = {
        {0, 1, 2},
        {3, 4, 5}
    };



    return 0;
}

