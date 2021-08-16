/*
 * Outside Environment
 */

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
       printf("arg %d: %s\n", i, argv[i]);
    }

    int total = 0;
    char buf[20];
    char *ptr;


    for (int i = 1; i < argc; i++)
    {
        int value = (int)strtol(argv[i], NULL, 10);
        total += value;
    }

    printf("Total: %d\n", total);

    // argv[argc] == NULL
    
    // (int argc, char **argv) == (int argc, char *argv[])
    
    // little trick to get rid of compiler warning
    (void) argc;

    total = 0;
    for (char **p = argv; *p != NULL; p++)
    {
        int value = (int)strtol(*p, NULL, 10);
        total += value;
    }
    printf("Total: %d\n", total);

    // EXIT STATUS
    // --> check with: echo $?
    // 0 --> success
    // nonzero --> failure
    if (argc != 3)
    {
        printf("usage: ./mult x y\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
    
    // Environment variables
    // getenv(), setenv(), unsetenv()
    char *envval = getenv("SHELL");

    // check if val exists
    if (envval == NULL)
    {
        printf("Cannot find SHELL environment variable.\n");
        return EXIT_FAILURE;
    }
    printf("SHELL var -> %s\n", envval);

    // see `man environ`
    for (char **p = environ; *p != NULL; p++)
        printf("%s\n", *p);

    for (int i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
        
    // better to use getenv() if (and when) possible. More portable.
    // Use environ when iterating over env vars
    

    return EXIT_SUCCESS;
}
