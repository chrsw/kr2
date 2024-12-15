/*
 * ch5_itoa.c
 *      Convert integer n to string. Chapter 5 pointer version.
 *
 * Description:
 *      Part of solution to exercise 5-6.
 *
 *      Previous description:
 *      Excerpt from section 3.6. itoa() takes a signed integer value
 *      and converts each integer digit in base 10 and converts the
 *      digit to its ASCII character. e.e. 0 -> 0x30 (decimal 48),
 *      1 -> 0x31 (decimal 49), etc.
 *      This version is revised from the text version.
 * 
 * Build:
 *      $ gcc -DITOA_MAIN -o ch5_itoa ch5_reverse.c ch5_itoa.c
 *      $ gcc -c ch5_itoa.c
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>

void ch5_itoa(int n, char *s);
void reverse(char s[]);

#ifdef ITOA_MAIN
int main(int argc, char *argv[]) {

    int n = -23456;
    char s[10];

    printf("number:  %d\n", n);
    ch5_itoa(n,s);
    printf("string:  %s\n", s);
	return 0;
}
#endif

void ch5_itoa(int n, char *s) {

    int i = 0;
    int sign = n;
    char *s2 = s;
    n = n < 0 ? -n : n;         /* convert n to positive number */ 

    do {                        /* generate digits in reverse order */
        *s++ = n % 10 + '0';    /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    
    reverse(s2);
}
