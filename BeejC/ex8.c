#include <stdio.h>
#include <stdlib.h>


// declare struct
struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price);

int main(void)
{
    // declare variable of `struct car`
    struct car saturn;
    saturn.name = "Saturn SL/2";
    saturn.price = 15999.99;
    saturn.speed = 175;

    printf("Name:           %s\n", saturn.name);
    printf("Price (USD):    %f\n", saturn.price);
    printf("Top Speed (km): %d\n", saturn.speed);

    // with initializer!
    struct car benz = {"Mercedenz Benz ML320", 22300.00, 180};
    printf("Name:           %s\n", benz.name);
    printf("Price (USD):    %f\n", benz.price);
    printf("Top Speed (km): %d\n", benz.speed);

    // with initializer! but order independent! uninitialized vars set to 0 / null
    struct car toyota = {.speed=140, .price=18999.54};
    printf("Name:           %s\n", toyota.name);
    printf("Price (USD):    %f\n", toyota.price);
    printf("Top Speed (km): %d\n", toyota.speed);

    // passing structs to functions
    // 1) pass struct
    //      makes copy of struct 
    // 2) pass pointer to struct
    //      good for when fucntion needs to make chances to struct that was passed in
    //      struct can be large to copy, computationally expensive; pointer is cheaper
    printf("Price (USD):    %f\n", saturn.price);
    set_price(&saturn, 800.00); 
    printf("Price (USD):    %f\n", saturn.price);

    // Copy and Returning structs
    struct car honda = toyota;
    printf("Name:           %s\n", honda.name);
    printf("Price (USD):    %f\n", honda.price);
    printf("Top Speed (km): %d\n", honda.speed);

    return 0;
}

void set_price(struct car *c, float new_price)
{
    // (*c).price = new_price;  // this works, but non-idiomatic
    // below is cleaner option
    // known as "Arrow Operator", helps refer to fields in pointers to struct
    //
    // TLDR: 
    //  . operator for struct
    //  -> operator for pointer to struct
    //
    c->price = new_price;
}

