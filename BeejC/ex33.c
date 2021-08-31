/*
 * Arrays Part II
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_2d_array(int array[][2])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
            printf("%d ", array[row][col]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int a[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };
    print_2d_array(a);

    // leaving out some initializers...
    int b[3][2] = {
        {1,2},
        {3},
        {5,6}
    };
    print_2d_array(b);

    int c[3][2] = {
        {1,2},
        // {3,4},
        {5,6}
    };
    print_2d_array(c);

    // Or all zeros
    int d[3][2] = {0};
    print_2d_array(d);

}
