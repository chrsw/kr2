/* vim:ts=4:sw=4:et:so=10:
 *
 * itoa.c
 *      Exercise 4-12. Adapt the ideas of printd to write a recursive version
 *      of itoa(). That is, convert an integer into a string by calling
 *      a recursive routine.
 *
 * Description:
 *      printd() is described in section 4.10 Recursion.
 *      See printd.c for the recursive printd() implementation from the
 *      text.
 *
 * Input:
 *      Integer.
 *
 * Output:
 *      String representation of the integer.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      $ gcc -c itoa.c
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void itoa(unsigned int n, char *s);

void itoa(unsigned int n, char *s) {

    int n_max = 1;
    int int_max = INT_MAX;
    static int i = 0;

    while ((int_max /= 10) > 0 ) n_max++;

    if (n / 10)
        itoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
