/* vim:ts=4:sw=4:et:so=10:
 *
 * itoa.c
 *      Convert integer n to characters in s. Revised version.
 *
 * Description:
 *      Excerpt from section 3.6. itoa() takes a signed integer value
 *      and converts each integeter digit in base 10 and converts the
 *      digit to its ascii character. e.e. 0 -> 0x30 (decimal 48),
 *      1 -> 0x31 (decimal 49), etc.
 *      This version is revised from the text version.
 * 
 * Build:
 *      $ gcc -DITOA_MAIN -o itoa2 reverse.c itoa2.c
 *      $ gcc -c itoa2.c
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>

void itoa2(int n, char s[]);
void reverse(char s[]);

#ifdef ITOA_MAIN
int main(int argc, char *argv[])
{
    int n = -23456;
    char s[10];

    printf("input:  %d\n", n);
    itoa2(n,s);
    printf("string: %s\n", s);
	return 0;
}
#endif

void itoa2(int n, char s[]) {

    int i = 0;
    int sign = n;

    n = n < 0 ? -n : n;         /* convert n to positive number */ 

    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    // TODO: Try this without using reverse().
    // e.g. Maybe each time in the do {} while shift the characaters
    // in the array to make room.
    reverse(s);
}
