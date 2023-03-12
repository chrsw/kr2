/* vim:ts=4:sw=4:et:
 *
 * getbits.c
 *      Get n bits from position p
 *
 * Description:
 *      Excerpt from Chapter 2, Section 9 Bitsiwe Operators
 *
 * Input:
 *      Number value, bits to set, position.
 *
 * Returns:
 *      Unsigned number value which is the result of setting n
 *      number of p bits in x.
 *     
 *
 */

#include "getbits.h"

unsigned int getbits(unsigned int x, int p, int n)
{

    return ( x >> (p+1-n)) & ~(~0 << n);
}


