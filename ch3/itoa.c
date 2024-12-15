/*
 * itoa.c
 *      Convert integer n to characters in s.
 *
 * Description:
 *      Excerpt from section 3.6. itoa() takes a signed integer value
 *      and converts each integer digit in base 10 and converts the
 *      digit to its ASCII character. e.e. 0 -> 0x30 (decimal 48),
 *      1 -> 0x31 (decimal 49), etc. The sign of the character (-) is
 *      printed too.
 *      reverse() is compiled in too because it's used to switch the
 *      string from left-to-right increasing (how arrays are indexed) to
 *      right-to-left increasing (how numbers are written).
 * 
 * Build:
 *      $ gcc -o itoa reverse.c itoa.c
 *
 */

#include <string.h>
#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    int n = 123456;
    char s[10];

    printf("number:  %d\n", n);
    itoa(n,s);
    printf("string:  %s\n", s);
	return 0;
}


void itoa(int n, char s[]) {

    int i, sign;
    if ((sign = n) < 0)         /* record sign */
        n = -n;                 /* make n positive */
    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
