/*
 * Chars and Strings II
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Backslash \ can be used to escape characters
char t = '\'';

/* COMMON ESCAPES
 * \n   Newline character—when printing, continue subsequent output on the next line
 * \'   Single quote—used for a single quote character constant
 * \"   Double quote—used for a double quote in a string literal
 * \\   Backslash—used for a literal \ in a string or character
 */

/* LESS COMMON ESCAPES
 * \a   Alert. This makes the terminal make a sound or flash, or both!
 * \b   Backspace. Moves the cursor back a character. Doesn’t delete the character.
 * \f   Formfeed. This moves to the next “page”, but that doesn’t have much modern meaning. On my system, this behaves like \v.
 * \r   Return. Move to the beginning of the same line.
 * \t   Horizontal tab. Moves to the next horizontal tab stop. 
 * \v   Vertical tab. Moves to the next vertical tab stop. On my machine, this moves to the same column on the next line.
 * \?   Literal question mark. Sometimes you need this to avoid trigraphs, as shown below.
 */

/*
 * \123 Embed the byte with octal value 123, 3 digits exactly.
 * \x4D Embed the byte with hex value 4D, 2 digits.
 * \u2620   Embed the Unicode character at code point with hex value 2620, 4 digits.
 * \U0001243F   Embed the Unicode character at code point with hex value 1243F, 8 digits.
 */

int main(void)
{
    for (int i = 10; i >= 0; i--)
    {
        printf("\rT minus %d second%s... \b", i, i != 1 ? "s" : "");
        fflush(stdout); // Force output to update
        sleep(1);
    }

    printf("\rLiftoff!               \n");

   	printf("\xE2\x80\xA2 Bullet 1\n");
    printf("\xE2\x80\xA2 Bullet 2\n");
    printf("\xE2\x80\xA2 Bullet 3\n"); 
}
