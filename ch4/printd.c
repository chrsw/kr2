/* vim:ts=4:sw=4:et:so=10:
 *
 * printd.c
 *      Print a decimal integer recursively.
 *
 * Description:
 *      Excerpt from Section 4.10, Recursion
 *
 */

#include <stdio.h>

/* print n in decimal */
void printd(int n) {

    if (n < 0) {
        putchar('-');
        n = -n;
    }
    
    if (n / 10) 
        printd(n/10);
    putchar(n % 10 + '0');     
    
}
