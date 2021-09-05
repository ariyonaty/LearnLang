/*
 * Mutexes
 */

#include <stdio.h>
#include <threads.h>

#define THREAD_COUNT 10

mtx_t serial_mtx; // mutex variable

int run(void *arg)
{
    (void) arg;
    static int serial = 0;

    mtx_lock(&serial_mtx); // aquire mutex
    printf("Thread running! %d\n", serial);

    serial++;

    mtx_unlock(&serial_mtx);

    return 0;
}

int main(void)
{
    thrd_t t[THREAD_COUNT];

    mtx_init(&serial_mtx, mtx_plain); // create mutex

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thrd_create(t+i, run, NULL);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thrd_join(t[i], NULL);
    }

    mtx_destroy(&serial_mtx); // destory mutex
}

/*
 * mtx_plain                Regular ol’ mutex
 * mtx_timed                Mutex that supports timeouts
 * mtx_plain|mtx_recursive  Recursive mutex
 * mtx_timed|mtx_recursive  Recursive mutex that supports timeouts
 */
