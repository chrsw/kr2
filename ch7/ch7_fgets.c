/*
 * ch7_fgets.c
 *      Get at most n chars from file.
 *
 * Description:
 *      Excerpt from text.
 *      Part of solution to exercise 7-8.
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include "ch7_fgets.h"

char * ch7_fgets(char *s, int n, FILE *iop) 
{
    register int c;
    register char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) != '\n')
            break;
    }
    *cs = '\0';

    return (c == EOF && cs == s) ? NULL : s;
}
