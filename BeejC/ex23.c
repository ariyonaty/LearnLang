/*
 * Pointers III
 */

#include <stdio.h>
#include <stdlib.h>

struct foo {
    char a;
    int b;
}; 

void print_int(int n)
{
    printf("%d\n", n);
}

int add(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

void print_math(int (*op)(int, int), int x, int y)
{
    int result = op(x, y);
    printf("Result: %d\n", result);
}


int main(void)
{
    int x = 3490;
    int *p = &x; // pointer to int
    int **q = &p; // pointer to pointer to int
    printf("%d\n", *p);
    printf("%d\n", **q);
    /*
     * Variable Stored at Address   Value Stored There
     * x        28350               3490—the value from the code
     * p        29122               28350—the address of x!
     * q        30840               29122—the address of p!
     */

    /*
     * Pointer to anything with & (including pointer)
     * Get the thing a pointer points to with * (including pointer)
     */

    // pointer pointers and const
    // reminder: const -> cant be modified
    int *const cp = &x;
    int *const *const ccq = &cp; // both ccq and what it points to are const

    // multibyte values
    //  sizeof --> how many bytes
    //  address of first byte of object using &
    //  iterating over object should be be done with pointer to unsigned char
    struct foo z = {0x12, 0x12345678};
    unsigned char *ptr = (unsigned char *)&z;
    for (size_t i = 0; i < sizeof(z); i++)
        printf("%02x\n", ptr[i]);

    /*
     * NULL pointer and Zero
     * These can be used interchangibly:
     *  NULL
     *  0
     *  '\0'
     *  (void *)0
     */

    /*
     * Pointers to functions
     */
    float (*func_p)(int, int); // function returns float, takes two ints as arg
    void (*pfunc)(int) = print_int;
    pfunc(1337);
    
    //                      op             x      y
    //              |-----------------|  |---|  |---|
    void print_math(int (*op)(int, int), int x, int y)
    print_math(add, 5, 7);
    print_math(mult, 5, 7);

}
