/*
 * Types Part IV
 * Compound Literals and Generic Selectors
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macro for format specifier
#define FMTSPEC(x) _Generic((x), \
                    int: "%d", \
                    long: "%ld", \
                    float: "%f", \
                    double: "%f", \
                    char *: "%s")

// macro prints variable in form "name = value"
#define PRINT_VAL(x) { \
    char fmt[512]; \
    snprintf(fmt, sizeof(fmt), #x " = %s\n", FMTSPEC(x)); \
    printf(fmt, (x)); \
}

// Compound Literals
// Handy for passing complex args to functions without creating temp var for it
// (int []){1,2,3,4}
int sum(int p[], int count)
{
    int total = 0;
    for (int i = 0; i < count; i++)
        total += p[i];
    return total;
}

struct coord {
    int x, y;
};

void print_coord(struct coord c)
{
    printf("%d, %d\n", c.x, c.y);
}

void print_coord2(struct coord *c)
{
    printf("%d, %d\n", c->x, c->y);
}

int main(void)
{
    // orig way of passing to sum()
    int a[] = {1,2,3,4};
    int s = sum(a, 4);

    int summa = sum((int []){1,2,3,4}, 4);
    printf("Sum: %d\n", summa);

    // unnamed structs 
    print_coord((struct coord){.x=10, .y=20});

    // pointers to unnamed objects 
    print_coord2(&(struct coord){.x=10, .y=20});

    // below are equivalent
    int x = 3490;
    printf("%d\n", x);              // variable
    printf("%d\n", 3490);           // constant 
    printf("%d\n", (int){3490});    // unnamed object

    // Generics
    int i = 10;
    float f = 3.14159;
    char *c = "Hello World!";
    PRINT_VAL(i);
    PRINT_VAL(f);
    PRINT_VAL(c);

    char *g = _Generic(i, 
            int: "var is an int",
            float: "var is a float", 
            default: "var is some type"
            );

    printf("%s\n", g);

}

