/* vim:ts=4:sw=4:et:
 *
 * setbits.c
 *      Set right-adjusted n bits in x starting at p to the right most
 *      n bits in y.
 *
 * Description:
 *      Exercise 2-6
 *
 * Input:
 *      Number value, bits to set, position, bits value.
 *
 * Returns:
 *      Unsigned number value which is the result of setting n
 *      number of p bits in x to right-most bits in y.
 *     
 *
 */

#include <stdio.h>
#include "setbits.h"

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int m;
    unsigned int mp;
    y = y & ~(~0 << n);
    m = ~0;
    mp = ~0;
    printf("setbits: y = %08X\n", y);
    m = m & (y << p);
    m = m | ~(~0 << n);
    mp = mp << n;
    mp = mp | y;
    mp = mp << p;
    mp = mp | ~(~0 << p);
    printf("setbits: m = %08X\n", m);
    printf("setbits: mp = %08X\n", mp);
    return (x & mp);
}


