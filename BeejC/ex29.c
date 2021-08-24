/*
 * Signal Handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 * Signals are "raised" on variety of external events
 * Functions that are called/handled when external event occurs
 *
 * Signal	Description
 * SIGABRT	Abnormal termination—what happens when abort() is called.
 * SIGFPE	Floating point exception.
 * SIGILL	Illegal instruction.
 * SIGINT	Interrupt—usually the result of CTRL-C being hit.
 * SIGSEGV	“Segmentation Violation”: invalid memory access.
 * SIGTERM	Termination requested. 
 */

/*
 *                  sig          func
 *                |-----|  |---------------|
 *  void (*signal(int sig, void (*func)(int)))(int);
*/

int count = 0;

void sigint_handler(int signum)
{
    signal(SIGINT, sigint_handler);
    (void)signum;
    
    count++;
    printf("Count: %d\n", count);

    if (count == 2)
    {
        printf("Exiting!\n");
        exit(0);
    }
}

int main(void)
{
    char s[1024];
    
    // signal(SIGINT, SIG_IGN); // ignore SIGINT, caused by CTRL-C

    signal(SIGINT, sigint_handler);
    printf("Try hitting ^C ...\n");

    for(;;); // wait forever
    
    fgets(s, sizeof(s), stdin);

    // notes about portability
    //  its not.
    //  use OS's builtin signal handling
}
