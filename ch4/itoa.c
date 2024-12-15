/*
 * itoa.c
 *      Exercise 4-12. Adapt the ideas of printd to write a recursive version
 *      of itoa(). That is, convert an integer into a string by calling
 *      a recursive routine.
 *
 * Description:
 *      printd() is described in section 4.10 Recursion.
 *      See printd.c for the recursive printd() implementation from the
 *      text.
 *      itoa() is not an Standard C function so the name doesn't conflict
 *      with the existing host code.
 *      Only one base is supported, base 10.
 *
 * Input:
 *      Integer.
 *
 * Output:
 *      String representation of the integer.
 *
 * Design:
 *      Call itoa() recursively, passing in a smaller integer each time.
 *      The final call writes the first character representation of the
 *      integer to the first location in the string. As the calls return
 *      each adds a successive char representation to the string.
 *
 * Standalone build:
 *      $ gcc -c itoa.c
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
