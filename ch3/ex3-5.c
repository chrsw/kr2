/*
 * ex3-5.c
 *      Convert integer n to characters in s, using base b.
 *
 * Description:
 *      Write the function itob(n,s,b) that converts the integer n into a
 *      base b character representation in the string s.  In particular,
 *      itob(n,s,16) formats n as a hexadecimal integer in s.
 * 
 * Build:
 *      Build a main driver or a standalone function object:
 *      $ gcc -DEX3_5_MAIN -o ex5-2 reverse.c ex3-5.c
 *      $ gcc -c ex3-5.c
 *
 * Notes:
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

#ifdef EX3_5_MAIN
int main(int argc, char *argv[]) {

    int n = 123;                /* simple test case */ 
    char s[65];                 /* worse case number size */

    printf("decimal number:  %d\n", n);
    itob(n,s,16);
    printf("hex number in string:  %s\n", s);
	return 0;
}
#endif


void itob(int n, char s[], int b) {

    int i = 0;
    int sign = n;

    /* find the base we're working with */
    if ((b != 16) && (b != 8)) b = 10;        

    n = n < 0 ? -n : n;         /* convert n to positive number */ 

    do {                        /* generate digits in reverse order */
        s[i] = n % b + '0';     /* get next digit */
        if ((b == 16) && (s[i] > '9')) s[i] += 7;
        i++;
    } while ((n /= b) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
