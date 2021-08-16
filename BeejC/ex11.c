/*
 * Pointer Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;

    return p - s;
}

void *my_memcpy(void *dest, void *src, int byte_count)
{
    char *s = src;
    char *d = dest;

    while (byte_count--) 
    {
        *d++ = *s++;
    }

    return dest;
}

struct animal {
    char *name;
    int leg_count;
};

int compar(const void *elem1, const void *elem2)
{
    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    return animal1->leg_count - animal2->leg_count;
}



int main(void)
{
    int a[5] = {11,22,33,44,55};
    int *p = a; // pointer to first element in array

    printf("%d\n", *p); // prints a[0]
    printf("%d\n", *(p + 1)); // prints a[1]
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));
    }

    int b[] = {11,22,33,44,55,999};
    int *pb = b;

    while (*pb != 999)
    {
        printf("%d\n", *pb);
        pb++;
    }
    
    printf("Strlen: %d\n", my_strlen("Hello world!"));

    // a[b] == *(a + b)
    // this is TRUE
    
    char s[] = "Antelopes";
    char *t = "Wombats";

    printf("%d\n", my_strlen(s));
    printf("%d\n", my_strlen(t)); // both work

    // `void` pointers
    // byte-by-byte operations
    // when we don't know type
    char x[] = "Goats!";
    char y[100];
    memcpy(y, x, 7); // copy 7 bytes, including NUL terminator
    printf("%s\n", t);

    int aaa[] = {11,22,33};
    int bbb[3];
    memcpy(bbb, aaa, 3 * sizeof(int));
    printf("%d\n", b[1]);

    // TLDR: memcpy allows us to just specify pointer of ANY type as long as
    //  number of bytes is specified
    // Limitiations of void*
    // 1. cannot do pointer arithmetic
    // 2. cannot dereference 
    // 3. cannot do arrow operator
    // 4. cannot use array notation
    // Trick is to convert void* to another type before using it
    char ch = 'X';
    void *ptr = &ch;
    char *q = ptr;

    printf("%c\n", *p); // error -> cannot dereference void*
    printf("%c\n", *q); // print 'X'

    struct animal f[4] = {
        {.name="Dog", .leg_count=4},
        {.name="Monkey", .leg_count=2},
        {.name="Antelope", .leg_count=4},
        {.name="Snake", .leg_count=0}
    };

	qsort(f, 4, sizeof(struct animal), compar);

	for (int i = 0; i < 4; i++) 
    {
        printf("%d: %s\n", f[i].leg_count, f[i].name);
    }

    return 0;
}

