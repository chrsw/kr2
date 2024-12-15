/*
 * bitcount.c
 *      Count 1 bits in x.
 *
 * Description:
 *      Excerpt from K&R2 section 2.10.
 *
 * Input:
 *      Unsigned integer to count bits it contains.
 *
 * Build:
 *      gcc -c bitcount.c
 * 
 *
 */


/* bitcount: count 1 bits in x */
int bitcount(unsigned int x) {

    int b;

    /* shift every bit until all '1' bits are removed */    
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)             /* least significant bit being one adds */ 
            b++;                /* to a running count */
    return b;
}
