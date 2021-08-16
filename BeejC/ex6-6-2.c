#include <stdio.h>

/*
 * Passing array to functions
 * Most common method: void foo(int *a, int len)
 * Function: double_array() is to illustrate changing arrays in functions
 */

void times2(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i] * 2);
    }
}


void times3(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i] * 3);
    }
}

void double_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] *= 2;
    }
}

void print_array(int *a, int len)
{
    printf("\nArray contains: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}


// same as: print_2D_array(int a[][3])
void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", a[row][col]);
        }
    }
}

int main(void)
{
    int x[5] = {11,22,33,44,55};

    times2(x, 5);
    print_array(x, 5);
    times3(x, 5);
    print_array(x, 5);
    double_array(x, 5);
    print_array(x, 5);

    int y[2][3] = {
        {1,2,3},
        {4,5,6}
    }

    print_2D_array(x);

    return 0;
}

