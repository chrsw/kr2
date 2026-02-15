/*
 * ex3-5.c
 *      Convert integer n to characters in s, using base b.
 *
 * Description:
 *       Write the function itob(n,s,b) that converts the integer n into a
 *      base b character representation in the string s.  In particular,
 *      itob(n,s,16) formats n as a hexadecimal integer in s.
 * 
 * Build:
 *      $ gcc -DEX5_2_MAIN -o itoa2 reverse.c ex5-2.c
 *      $ gcc -c ex5-2.c
 *
 * Notes:
 *      For this exercise, n will be assumed to be in base 10 and the choices
 *      for b as the base will be 10 or 16.
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>

void itoa2(int n, char s[]);
void reverse(char s[]);
void itob(int n, char s[], int b);

#ifdef EX5_2_MAIN
int main(int argc, char *argv[]) {

    int n = 123;                /* simple test case */ 
    char s[65];                 /* worse case number size */
    char s2[65];

    printf("number:  %d\n", n);
    itoa2(n,s);
    printf("string from itoa2:  %s\n", s);
    itob(n,s2,16);
    printf("string from itob:  %s\n", s2);
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
    reverse(s);
}


void itob(int n, char s[], int b) {

    int i = 0;
    int sign = n;

    if ((b != 16) && (b != 8)) b = 10;        /* find the base we're working with */

    n = n < 0 ? -n : n;         /* convert n to positive number */ 

    do {                        /* generate digits in reverse order */
        s[i] = n % b + '0';  /* get next digit */
        if ((b == 16) && (s[i] > '9')) s[i] += 7;
        i++;
    } while ((n /= b) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
