/*
 * Types III: Conversions
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[10];
    float f = 3.14159;

    // convert 'f' to string, store in 's', writing at most 10 chars, include NUL
    snprintf(s, 10, "%f", f);

    printf("String value: %s\n", s);


    // String to Numeric Value
	// Func		Description
	// atoi		String to int
	// atof		String to float
	// atol		String to long int
	// atoll	String to long long int
	char *pi = "3.14159";
    float fpi;
    fpi = atof(pi);
    printf("%f\n", fpi);

    // Function		Description
	// strtol		String to long int
	// strtoll		String to long long int
	// strtoul		String to unsigned long int
	// strtoull		String to unsigned long long int
	// strtof		String to float
	// strtod		String to double
	// strtold		String to long double
	// ^^^ Allow for better handling and can convert to more types/bases
	char *x = "3490";
    unsigned long int y = strtoul(x, NULL, 10);
    printf("%lu\n", y);

    char *z = "101010";
    y = strtoul(z, NULL, 2); // base-2 conversion
    printf("%lu\n", y);

    char *q = "34x90"; // 'x' is not valid in base-10
    char *badchar;
    y = strtoul(q, &badchar, 10); // invalid char stored in "badchar" 
    printf("%lu\n", y);
    printf("Invalid char: %c\n", *badchar);

    // validity check
    if (*badchar == '\0')
        printf("Success! %lu\n", y);
    else
        printf("Failed with char %c\n", *badchar);

    // Integer Promotions
    // 'm' and 'n' are promoted to integers
    char m = 10;
    char n = 20;
    int i = n + m;
    
    // void* can be converted to/from any pointer type
    {
        int x = 10;
        void *p = &x;
        int *q = p; // p is void*, but stored in int*
    }

    // Explicit Conversions
    // casting
    {
        int x = 10;
        long int y = (long int) x + 12;
    }



    return 0;
}
