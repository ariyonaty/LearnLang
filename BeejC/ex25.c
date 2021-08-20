/*
 * Variadic Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void func(int a, ...) // literal 3 dots
{
    printf("a is %d\n", a);
}

int add(int count, ...)
{
    int total = 0;
    va_list va;

    va_start(va, count); // start with args after "count"

    for (int i = 0; i < count; i++)
    {
        int n = va_arg(va, int); // get next int
        total += n;
    }

    va_end(va); // donzo
    return total;
}


int main(void)
{
    func(12);
    printf("Total: %d\n", add(5, 1,2,3,4,5));
    printf("Total: %d\n", add(3, 5, 10, -3));
    
    /*
     * va_start() to initialize your va_list variable
	 * Repeatedly va_arg() to get the values
	 * va_end() to deinitialize your va_list variable
	 */
}

