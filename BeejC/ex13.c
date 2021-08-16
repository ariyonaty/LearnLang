/*
 * Scope
 */

#include <stdio.h>
#include <stdlib.h>

int shared = 10; // file scope var; visible to entire file

void func1(void)
{
    shared += 100;
}

void func2(void)
{
    printf("%d\n", shared);
}

int main(void)
{
    int a = 12; // local to outer block, visible to inner block

    if (a == 12)
    {
        int b = 99; // local to inner block; not to outer block
        printf("%d %d\n", a, b);
    }

    printf("%d\n", a);
    // printf("%d\n", b); // illegal; b not in scope
    
    // Variable Hiding
    int i = 10;
    {
        int i = 20;
        printf("%d\n", i); // 20
    }

    printf("%d\n", i); // 10

    // File Scope == Global Scope
    //  (see "shared" variable)
    func1();
    func2();

    // for-loop scope
    for (int i = 0; i < 10; i++)
        printf("%d\n", i);

    return 0;
}
