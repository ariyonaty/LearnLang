/*
 * Detaching Threads
 */

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
    (void)arg;
    printf("Thread running! %lu\n", thrd_current()); // non-portable
    // printf("Thread running!\n");
    return 0;
}

int main(void)
{
    thrd_t t;

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thrd_create(&t, run, NULL);
        thrd_detach(t); // Detach
    }

    // Sleep for a second to let all threads finish
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);
}
