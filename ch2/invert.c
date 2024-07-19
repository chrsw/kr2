/* invert:  invert n bits starting at position p in x */
#include <stdio.h>
#include "invert.h"

unsigned int invert(unsigned x, int p, int n)
{
    unsigned int r = 0;
    unsigned int i = 0;
    unsigned int z = 0;
    unsigned int ones = 0;
    unsigned int zeros = 0;


    /* create a word of inverted bits from the correct posistion */
    i = (x >> (p-n)) & ~(~0 << n); 
    i = ~i;

    /* create n ones */
    ones = ~0;
    ones <<= n;
    ones = ~ones;

    i &= ones;


    /* fill the specified n bits at position p with zeros */
    i <<= p;
    ones <<= p;
    zeros = ~ones;

    /* compute the result */
    r = x & zeros;
    r = r | i;
    return r;
}
