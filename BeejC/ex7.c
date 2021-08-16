#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *s)
{
    int count = 0;
    while (s[count] != '\0')
        count++;

    return count;
}


int main(void)
{
    char *a = "Hello, World!";
    char b[14] = "Hello, World!";
    char c[] = "Hello, World!";
    
    // Accessing by element
    for (int i = 0; i < 13; i++)
    {
        printf("%c\n", a[i]);
        printf("%c\n", b[i]);
    }
    
    // Cannot mutate pointer* to constant string
    // only mutable when declaring array string

    // getting string length <string.h>
    printf("Length string: %zu chars.\n", strlen(a));

    // copying a string 
    char s[] = "Hello, World!";
    char *t;
    t = s; // makes copy of pointer, not copy of string
    t[0] = 'z'; //modifies orig string 's'

    char copy[1000];
    strcpy(copy, s); // makes copy of string
    copy[0] = 'z'; // modifies copy only



    return 0;
}


