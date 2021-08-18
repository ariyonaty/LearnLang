/*
 * Bitwise Operations
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // AND, OR, XOR, NOT
    unsigned char a = 0b00001111;
    unsigned char b = 0b11110000;

    unsigned char and = a & b;
    unsigned char or = a | b;
    unsigned char xor = a ^ b;
    unsigned char not = ~b;
    
    //shorthand also works:
    // a &= c --> a = a & c
    printf("AND: %d\n", and);
    printf("OR: %d\n", or);
    printf("XOR: %d\n", xor);
    printf("NOT: %d\n", not);

    // Bitwise Shift
    unsigned char shift = 0b00010000;
    unsigned char left = shift >> 1;
    unsigned char right = shift << 1;
    printf("SHIFT LEFT: %d\n", left);
    printf("SHIFT RIGHT: %d\n", right);

}
