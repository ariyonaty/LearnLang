/*
 * Types II
 */

#include <stdio.h>
#include <float.h>

int main(void)
{
   int a = 0xDEAD; // hexadecimal
   int b = 0xdead; // case-insensitive

   printf("%x\n", a);

   int c = 0b11111111; // binary
   
   float x = 3.14; // actually a double
   float y = 3.14f; // float
   long double z = 3.14L; 

   printf("%e\n", 123456.0); // Scientific notation

   return 0;
}

