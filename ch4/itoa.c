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

void itoa(unsigned int i, char *s);

void itoa(unsigned int i, char *s) {

    static int n = 0;
    s[n] = itoa(i/10, n++);
    return cp;
}
