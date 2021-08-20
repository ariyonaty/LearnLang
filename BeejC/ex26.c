/*
 * Locale and Internationalization
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void)
{
    setlocale(LC_ALL, ""); // use environment's locale
    setlocale(LC_ALL, "C"); // use default C locale
    setlocale(LC_ALL, "en_US.UTF-8"); // non-portable; system-dependent
    
    // Monetary locale settings
    struct lconv *x = localeconv();

}
