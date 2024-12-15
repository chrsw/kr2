/*
 * ex2-9.c
 *      Rewrite of bitcount() with knowing that 'x &= (x-1)' removes
 *      the rightmost bit in x.
 *
 * Description:
 *      Count 1 bits in x.
 *      Modified excerpt from K&R2 section 2.10.
 *
 * Input:
 *      Unsigned integer to count bits it contains.
 *
 * Build:
 *      gcc -c ex2-9.c
 * 
 *
 */


/* bitcount: count 1 bits in x */
int bitcount(unsigned int x) {

    int b = 0;

    /* shift every bit until all '1' bits are removed */    
    //for (b = 0; x != 0; x >>= 1)
    //    if (x & 01)             /* least significant bit being one adds */ 
    //        b++;                /* to a running count */

    while (x) {
        x &= (x-1);
        b++;
    }
    return b;
}
