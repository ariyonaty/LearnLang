#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <threads.h>

#ifdef __STDC_NO_THREADS__
#error Need threads to compile
#endif

#define THREAD_COUNT 5

int run(void *arg)
{
    int i = *(int *)arg;
    printf("THREAD: %d: running!\n", i);
    return i;
}

int main(void)
{
    thrd_t t[THREAD_COUNT];

    printf("Launching threads...\n");
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thrd_create(t + i, run, &i);
    }

    printf("Doing other things while thread runs..\n");
    printf("Waiting for thread to complete..\n");

    for (int i = 0; i < THREAD_COUNT; i++) 
    {
        int res; 
        thrd_join(t[i], &res);
        printf("Thread %d complete!\n", res);
    }

    printf("All threads complete!\n");
}
