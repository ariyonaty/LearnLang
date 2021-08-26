/*
 * goto
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("One\n");
    printf("Two\n");

    goto skip_3;

    printf("Three\n");

skip_3:
    printf("Five!\n");

}


