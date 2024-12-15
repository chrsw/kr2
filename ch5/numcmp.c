/*
 * numcmp.c
 *      Compare two numeric values.
 *
 * Description:
 *      numcmp() from section 5.11.
 *
 * Input:
 *      Two character strings s1 and s2.
 *
 * Output:
 *      Less than zero if s1 is less than s2.
 *      Greater than 0 if s1 is greater than s2.
 *      Zero if s1 is equal to s2.
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

int numcmp(char *s1, char *s2);

/* numcmp: cmpare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {

    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2 )
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

