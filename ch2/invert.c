/*
 * invert.c
 *      Invert n bits in x starting a position p.
 *
 * Description:
 *      Write a function invert(x,p,n) that returns x with the n bits that
 *      begin at position p set to the rightmost n bits of y, leaving the
 *      other bits unchanged.
 *
 * Build:
 *      See main driver in ex2-7.c.
 *
 * Run:
 *      $ ./ex2-7
 *
 */



#include <stdio.h>
#include "invert.h"

/* invert:  invert n bits starting at position p in x */
unsigned int invert(unsigned x, int p, int n)
{
    unsigned int result = 0;
    unsigned int inverted = 0;
    unsigned int ones = 0;
    unsigned int zeros = 0;

    /* create the inverted bits in LSBs */
    inverted = (x >> (p-n)) & ~(~0 << n); 
    inverted = ~inverted;
    /* ~((x >> (p-n)) & ~(~0 << n)) */ 

    /* create n ones in LSBs */
    ones = ~0;
    ones <<= n;
    ones = ~ones;
    /* (~(~0 << n)) */

    /* clear all the non-n inverted bits */
    /* leaving only inverted bits in LSBs */
    inverted &= ones;
    inverted <<= p;
    /* (& ones) << p */

    /* fill the specified n bits at position p with zeros */
    ones <<= p;
    zeros = ~ones;

    /* clear the n bits in position p */ 
    result = x & zeros;

    /* compute the result */
    result |= inverted;
    return result ;
}
