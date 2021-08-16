#include <stdio.h>

int main(void)
{
    float f[4];


    f[0] = 3.14159;
    f[1] = 1.41421;
    f[2] = 1.61803;
    f[3] = 2.71828;

    for (int i = 0; i < 4; i++)
    {
        printf("%f\n", f[i]);
    }

    // Getting size of array
    // Note: doesn't work if passing array to function, like:
    // void foo(int x[12]) 
    int arrLength = sizeof(f) / sizeof(float);
    printf("Size of array: %d\n", arrLength);

    return 0;
}


