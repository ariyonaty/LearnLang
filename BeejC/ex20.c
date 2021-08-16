/*
 * Structs II
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


struct cabin_information {
    int window_count;
    int o2level;
};

struct spaceship {
    char *manufacturer;
    struct cabin_information ci;
};

// Anonymous struct
struct {
    char *name;
    int leg_count;
    int speed;
} a, b, c;

typedef struct {
    char *make;
    int mpg;
} car;

// self-referential structs
struct node {
    int data;
    struct node *next;
};

// padding bytes
// C struct may pad extra bytes
struct foo {
    int a; // 4 bytes
    char b;
};

// Fake OOP
struct parent {
    int a, b;
};

struct child {
    struct parent super; // must be first member
    int c, d;
};

void print_parent(void *p)
{
    struct parent *self = p;
    printf("Parent: %d %d\n", self->a, self->b);
};

void print_child(struct child *self)
{
    printf("Child: %d, %d\n", self->c, self->d);
};

// unions
union bar {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
};


int main(void)
{
    struct spaceship s = {
        .manufacturer="General Products",
        .ci.window_count = 8, // nested initializer
        .ci.o2level = 21
    };
    
    struct spaceship p = {
        .manufacturer="General Products",
        .ci = {
            .window_count = 8,
            .o2level = 21
        }
    };

    printf("%s: %d seats, %d%% oxygen \n",
            s.manufacturer, s.ci.window_count, s.ci.o2level);
    printf("%s: %d seats, %d%% oxygen \n",
            p.manufacturer, p.ci.window_count, p.ci.o2level);

    a.name = "antelope";
    c.leg_count = 4; 

    car toyota, honda;
    toyota.mpg = 23;
    honda.make = "Civic";

    // linked list
    struct node *head;
    // hackish linked list (11)->(22)->(33)
    head = malloc(sizeof(struct node));
    head->data = 11;
    head->next = malloc(sizeof(struct node));
    head->next->data = 22;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->data = 33;
    head->next->next->next = NULL;

    //traverse list
    for (struct node *cur = head; cur != NULL; cur = cur->next)
        printf("%d\n", cur->data);


    // padding bytes
    struct foo f = {1111, 'a'};
    printf("%zu\n", sizeof(f.a) + sizeof(f.b));
    printf("%zu\n", sizeof(struct foo));
    printf("Offset var a -> %zu\n", offsetof(struct foo, a));
    printf("Offset var b -> %zu\n", offsetof(struct foo, b));
    // reason for compiler adding bytes to char-> 4 bytes. Probably faster for CPU.

    // Fake OOP
    struct child c = {.super.a = 1, .super.b = 2, .c = 3, .d = 4};
    print_child(&c);
    print_parent(&c);

    union bar b;
    b.a = 12;
    printf("%d\n", b.a); // OK -> x.a was last thing stored
    b.g = 3.14159;
    printf("%f\n", b.g); // OK -> x.g was last thing stored
    printf("%d\n", b.a); // Unspecified behavior. Union only can work with one field at a time.



}
