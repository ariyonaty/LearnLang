/*
 * Multithreading
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <threads.h>

#ifdef __STDC_NO_THREADS__
#error Threads needed to build program
#endif

/*
 * Function that thread will run. 
 * arg - argument poitner passed to `thrd_create()`
 *
 * parent thread gets return value from `thrd_join()`
 */
int run(void *arg)
{
    int *a = arg; 
    printf("THREAD: Running thread with arg %d\n", *a);
    return 12;
}

int main (void)
{
    thrd_t t; // holds thread id
    int arg = 3490;
    
    printf("Launching a thread..\n"); // 

    thrd_create(&t, run, &arg);

    printf("Doing other things while thread runs.\n");
    printf("Waiting for thread to complete...\n");

    int res;

    thrd_join(t, &res);

    printf("Thread existed with return value %d\n", res);
}
