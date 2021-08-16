/*
 * Manual Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline(FILE *fp)
{
    int offset = 0;
    int bufsize = 4; 
    char *buf;
    int c; // char read

    if ((buf = malloc(bufsize)) == NULL)
        return NULL;

    // main loop -- read until \n or EOF
    while (c = fgetc(fp), c != '\n' && c != EOF)
    {
        // check if we're out of room in buffer
        // for extra byte of NUL terminator
        if (offset == bufsize - 1)
        {
            bufsize *= 2;
            char *new_buf;
            if ((new_buf = realloc(buf, bufsize)) == NULL)
            {
                free(buf);
                return NULL;
            }
            buf = new_buf;
        }
        buf[offset++] = c; // add byte onto buffer
    }

    // hitting newline or EOF
    
    // if EOF and no bytes read
    //  free buff, return NULL to indicate EOF
    if (c == EOF && offset == 0)
    {
        free(buf);
        return NULL;
    }

    // shrink to fit
    if (offset < bufsize - 1) 
    {
        char *new_buf;
        if ((new_buf = realloc(buf, offset + 1)) != NULL) // +1 for NUL terminator ; usage check
            buf = new_buf;
    }

    buf[offset] = '\0';

    return buf;
}


int main(void)
{
    // allocating space for single int
    int *p = malloc(sizeof(int));
    *p = 12; //store value 
    printf("%d\n", *p); 
    free(p); // freeing allocated memory
    // *p = 1234; // ERROR: undefined memory cuz it's been free() 
    
    // Kinda bad example, could just done:
    //  int p = 12;
    
    // more common approach:
    int *p2 = malloc(sizeof( *p2));
    free(p2);

    // Error checking
    int *x;
    if ((x = malloc(sizeof(int) * 10)) == NULL)
    {
        printf("Error allocation 10 ints.\n");
    }
    free(x);

    // Allocating space for array
    int *a = malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
        a[i] = i * 5;

    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);

    free(a);
    
    // alternative: calloc()
    // two args: size of one element ; number of elements
    // clears memory to zero
    int *c = calloc(sizeof(int), 10); 
    free(c);

    int *m = malloc(sizeof(int) * 10);
    memset(m, 0, sizeof(int) * 10); // sets to 0
    free(m);


    // reallocating: realloc()
    float *f = malloc(sizeof(*f) * 20); // allocate space for 20 floats

    for (int i = 0; i < 20; i++)
        f[i] = i / 20.0;

    // reallocate to 40 elements
    float *new_f;
    if ((new_f = realloc(f, sizeof(*f) * 40)) == NULL)
    {
        printf("Error reallocating.\n");
        return 1;
    }
    f = new_f;

    for (int i = 20; i < 40; i++)
        f[i] = 1.0 + (i - 20) / 20.0;

    for (int i = 0; i < 40; i++)
        printf("%f ", f[i]);

    printf("\n");
    free(f); // only need to free from one of pointers because they both point to same memory.

    // reading lines arbitrary length
    FILE *fp = fopen("foo.txt", "r");
    char *line;

    while (( line = readline(fp)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);    

    // Aligned Allocations
    // allocate 256 bytes aligned on a 64-byte boundary
    char *aligned = aligned_alloc(64, 256); //256 == 64*4

    strcpy(aligned, "Hello, World!");
    printf("%s\n", aligned);
    free(aligned);


    return 0;
}
