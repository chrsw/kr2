/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * ch6_strdup.c
 *      Copy the string given by the argument to a "safe" space.
 *
 * Description:
 *      Excertp from chapter 6, section 5.
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

#include <stdlib.h>
#include <string.h>

char *ch6_strdup(char *);

char *ch6_strdup(char *s) 
{
    char *p;

    p = (char *) malloc (strlen(s)+1);      /* +1 for '\0' */
    if (p != NULL)
        strcpy(p,s);
    return p;
}
