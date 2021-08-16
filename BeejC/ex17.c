/*
 * Multifile projects
 */

#include <stdio.h>
#include <stdlib.h>
#include "ex17-1.h"

int main(void)
{
    printf("%d\n", add(2,3));

    // Dealing with Repeated Includes
    //  -> include in header file a conditional preprocessor definition


    // `static` and `extern`
    // refer to objects in other files with `extern`
    // `static` -> limit to file-scope

    // compiling with object files
    // faster -> more efficient
    // `make` 

    return 0;
}

