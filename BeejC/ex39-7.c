/*
 * Thread Local Data
 */

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define THREAD_COUNT 5

int run(void *arg)
{
    int n = *(int *)arg; // thread num for humans
    free(arg);
    thread_local static int foo = 10; // non-shared variable

    int x = foo;

    printf("Thread %d: x = %d, foo = %d\n", n, x, foo);

    foo++;

    return 0;
}

int main(void)
{
    /*
     * if thread_local var is block scope -> must be static / (or extern)
     */

    thrd_t t[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        int *n = malloc(sizeof(*n));
        *n =  i;
        thrd_create(t + i, run, n);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thrd_join(t[i], NULL);
    }
}
