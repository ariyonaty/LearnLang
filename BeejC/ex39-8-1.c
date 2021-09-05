/*
 * Threads, Mutexes, Condition Variables
 * 
 * Compilation: gcc -Wall -g <filename> -lpthread
 */

/*
 * Condition variables provide way for threads to go to sleep until some even on another thread occurs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define VALUE_COUNT_MAX 5

int value[VALUE_COUNT_MAX]; // shared global
int value_count = 0; // shared global

mtx_t value_mtx; // mutex around value
cnd_t value_cnd; // condition variable on value

int run(void *arg)
{
    (void) arg;

    for (;;)
    {
        mtx_lock(&value_mtx); // grad mutex;

        while (value_count < VALUE_COUNT_MAX) 
        {
            printf("Thread: is waiting..\n");
            cnd_wait(&value_cnd, &value_mtx); // condition wait
        }

        printf("Thread: is awake!\n");

        int t = 0;

        // add everything up
        for (int i = 0; i < VALUE_COUNT_MAX; i++)
            t += value[i];

        printf("Thread: total is %d\n", t);

        // reset input index for main thread
        value_count = 0;

        mtx_unlock(&value_mtx); // unlock mutex
    }

    return 0;
}



int main(void)
{
    thrd_t t;

    // spawn new thread
    thrd_create(&t, run, NULL);
    thrd_detach(t);

    // setu up mutex and condtion variable
    mtx_init(&value_mtx, mtx_plain);
    cnd_init(&value_cnd);

    for (;;)
    {
        int n;

        scanf("%d", &n);

        mtx_lock(&value_mtx);

        value[value_count++] = n;

        if (value_count == VALUE_COUNT_MAX)
        {
            printf("Main: signaling thread\n");
            cnd_signal(&value_cnd); // signal condition
        }

        mtx_unlock(&value_mtx); // unlock mutex
    }

    // cleanup
    mtx_destroy(&value_mtx);
    cnd_destroy(&value_cnd);
}

