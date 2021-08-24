/*
 * Exiting a Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define PI 3.14159

/* main() has implicit `return 0` --> doesn't need to be specified */
/* exit() -> exits program ; takes in argument int status; exit(0); */

void on_exit_1(void)
{
    printf("Exit handler 1 called!\n");
}

void on_exit_2(void)
{
    printf("Exit handler 2 called!\n");
}

void on_exit_reg(void)
{
    printf("Exit handler reg\n");
}

void on_quick_exit_1(void)
{
    printf("Quick exit 1\n");
}

void on_quick_exit_2(void)
{
    printf("Quick exit 2\n");
}


int main(void)
{
    // atexit() calls function at process termination
    atexit(on_exit_1);
    atexit(on_exit_2);

    // at_quick_exit() similar to normal exit, but:
    //  open files might not be flushed
    //  temp files might not be removed
    //  atexit() handlers wont be called
    at_quick_exit(on_quick_exit_1);
    at_quick_exit(on_quick_exit_2);
    
    atexit(on_exit_reg); // won't be called

    printf("About to exit...\n");
    
    // quick_exit(0); // remove to handle regular exit() 

    // NUKE -> Buh bye program `_Exit()`
    // _Exit()

    // Exit sometimes: assert()
    assert(PI > 3); // true, so carry on
    assert(PI > 5); // false, so fails
}
