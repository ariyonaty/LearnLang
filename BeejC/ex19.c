/*
 * The C Preprocessor
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Two categories of header files
 *  system + local
 *  system  -->     use <>
 *  local   -->     use ""
 *
 *  can be used for relative path as well:
 *  #include "mydir/myheader.h"
 *  #include "../someheader.h"
 */

// MACROS
// == placeholder
// gets expanded into other code before compiler sees it 
#define HELLO "Hello, World"
#define PI 3.14159
#define EMPTY_MACRO

/*
 * Conditional Compilation
 *  If defined,             #ifdef
 *  If not defined          #ifndef
 *  Else                    #else
 *  End define              #endif
 */

// Common use-case in header files
#ifndef HEADER_H
#define HEADER_H

// CODE HERE

#endif

#define HAPPY_FACTOR 1
int main(void)
{
#if HAPPY_FACTOR == 0
    printf("I'm not happy!\n");
#elif HAPPY_FACTOR == 1
    printf("I'm just regular!\n");
#else
    printf("I'm extra happy!\n");
#endif

// MACROS can be undefined with #undef


/*
 * Built-in Macros
 */

/*
 * MANDATORY MACROS 
 *
 * __DATE__ The date of compilation—like when you’re compiling this file—in Mmm dd yyyy format
 * __TIME__ The time of compilation in hh:mm:ss format
 * __FILE__ A string containing this file’s name
 * __LINE__ The line number of the file this macro appears on
 * __func__ The name of the function this appears in, as a string107
 * __STDC__ Defined with 1 if this is a standard C compiler
 * __STDC_HOSTED__  This will be 1 if the compiler is a hosted implementation108, otherwise 0
 * __STDC_VERSION__ This version of C, a constant long int in the form yyyymmL, e.g. 201710L
 */

    printf("This function: %s\n", __func__);
    printf("This file: %s\n", __FILE__);
    printf("This line: %d\n", __LINE__);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    printf("C Version: %ld\n", __STDC_VERSION__);

/*
 * Macros with arguments
 */
#define SQRT(x) ((x) * (x))
#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))

//ERROR Directive
#ifndef __STDC_IEC_559__
#error Require IEEE-754 floating point to compile
#endif

/*
 * Pragma directive
 */
// #pragma STDC pragma_name on-off
#pragma STDC FP_CONTRACT OFF
#pragma STDC CX_LIMITED_RANGE ON

    return 0;
}



