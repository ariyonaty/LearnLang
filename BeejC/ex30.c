/*
 * Variable-Length Arrays (VLAs)
 */

#include <stdio.h>
#include <stdlib.h>

// sizeof VLA computed at runtime

int main(void)
{
    int n = 5;
    int v[n];

    int *p = v;
    *(p+2) = 12;
    printf("%d\n", v[2]); // 12
    
    p[3] = 34;
    printf("%d\n", v[3]); // 34
}


