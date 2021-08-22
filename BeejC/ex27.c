/*
 * Unicode, Wide Characters, Etc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <uchar.h>

int main(void)
{
    char *s = "\u20AC1.23"; // \u for 16 bits
    char *t = "\U0001D4D1"; // \U for 32 bits 
    printf("%s\n", s);
    printf("%s\n", t);

    /* Things to note:
     * strlen() returns # bytes, not characters
     */

    wchar_t *u = L"Hello, world!";
    wchar_t c = L'B';
    printf("%ls %lc\n", u, c);

    char16_t *us = u"Hello, world!";
    char32_t *uus = U"Hello, world!";
    char16_t pi = u"\u03C0";

#if __STDC_UTF_16__
    pi == 0x3C0;
#else
    pi == 0x3C0;
#endif

    printf("%s\n", pi);

}
