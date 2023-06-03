/* vim:ts=4:sw=4:et:so=10:
 *
 * ex3-4.c
 *      Solution to chapter 3, exercise 4.
 *
 * Description:
 *      The text example for itoa() does not handle the largest negative
 *      number (largest magnitude). Explain why not (explanation below,
 *      in function body). Modify it to print the value correctly, regard-
 *      less of the machine on which it runs.
 * 
 * Build:
 *      $ gcc -o ex3-4 reverse.c ex3-4.c
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    int n = INT_MIN;                
    //int n = -20;              
 
    /* make sure string has enough room to store max size number */
    char s[13];                     /* $ ./int_min | wc -c
                                     * 12
                                     */

    printf("input:  %d\n", n);
    itoa(n,s);
    printf("string: %s\n", s);
	return 0;
}

/* new itoa() for solution to chapter 3, exercise 4
 * handle full range of numerical values for runtime
 */
void itoa(int n, char s[]) {

    int i, sign;

    /* extract sign, handle case where n is smallest limit */
    sign = n == INT_MIN ? -1 : n < 0 ? -1 : 1;      

    printf("sign = %d\n", sign);
    if (n < 0) printf("-1\n");
    i = 0;
    /* generate digits for string in reverse order */ 
    do {    
        /* get next digit.
         * use sign info with each digit so 2's compliment number
         * is handled. this avoids the case where INT_MIN magnitude
         * is too large to handle.
         */
        s[i++] = (sign * (n % 10)) + '0';

    } while (abs(n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
