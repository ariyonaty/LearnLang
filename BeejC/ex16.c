/*
 * Types IV
 * Qualifiers and Specifiers
 */

#include <stdio.h>
#include <stdlib.h>

void foo (const int x)
{
    printf("%d\n", x + 3);
}

void counter(void)
{
    static int count = 1;
    printf("This has been called %d time(s)\n", count);
    count++;
}

int main(void)
{
    const int x = 2;
    // x = 4; // cannot assign value to const

    volatile int *p; // value may change and should be looked up every time
    
    // Static
    // in block-scope, static var is only initialized once.
    // in file-scope, variables persist between function calls ; global, but only in file
    counter();
    counter();
    counter();
    counter();

    // extern
    // extern int a;
    // --> allowing us to refer to variable 'a' from another file

    // register
    // register int a; // makes 'a' as fast to use as possible

    return 0;

}
