#include <stdio.h>
#include <stdlib.h>

struct animal {
    char *name;
    int leg_count;
    int speed;
};

typedef struct car {
    char *model;
    int maxSpeed;
} car; // also works. Allows for declaring: `car myCar;`

typedef struct { // anonymous struct; no structure naming
    char *breed;
    int age;
} dog;


int main(void)
{
    typedef struct animal animal;
    
    struct animal x; // typical way of creating struct animal object
    animal z; // alternative result from `typedef`

    struct car toyota; // this works
    car honda; // also works. 'car' is alias

    // struct dog myDog; // doesn't work anymore
    dog myDog = {"husky", 6};
    printf("Breed: %s ; Age: %d \n", myDog.breed, myDog.age);

    /*
     * typedefs can also be used quickly change types:
     * eg:
     *  typedef float app_float; -> typedef long double app_float;
     *  and now all those defs are long doubles
     */


    return 0;
}
