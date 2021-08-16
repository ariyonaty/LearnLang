/*
 * Enumerated Types
 */

#include <stdio.h>
#include <stdlib.h>

// `enum` -> refer to constant interger values by name
// differences with #define:
//  enums can only be int types
//  #define can define anything
//  enums shown by symbolic identifier in debugger
//  #define show as raw numbers -> harder to debug

// by default, numbering starts at 0
// can also be manually specified
// mixed as well -> next number continues from last specified value
// trailing commas allowed2

// enums commonly in header files so they have file scope
// common style is UPPER_CASE (with underscores)

enum {
    ONE=1,
    TWO=2
enum {
    SHEEP,  // val = 0
    WHEAT,  // val = 1
    WOOD,   // val = 2
};

enum {
    ONE=1,
    TWO=2
};

printf("%d %d\n", ONE, TWO);


