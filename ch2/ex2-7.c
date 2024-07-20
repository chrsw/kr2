/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex2-7.c
 *      Invert n bits in x starting a position p.
 *
 * Description:
 *      Write a function invert(x,p,n) that returns x with the n bits that
 *      begin at position p set to the rightmost n bits of y, leaving the
 *      other bits unchanged.
 *
 * Input:
 *      This file has the example input hard coded.
 *
 * Output:
 *      Prints the input value and output value to standard output.
 *
 * Design:
 *      See invert.c
 *
 * Build:
 *      $ gcc -o ex2-7 ex2-7.c invert.c
 *
 * Run:
 *      $ ./ex2-7
 *
 */


#include <stdio.h>
#include "invert.h"

int main(int argc, char *argv[])
{
    unsigned int x = 0xf0001110;
    int p = 8;
    int n = 4;
    unsigned int i;
    i = invert(x,p,n);
    
    printf("   input = %08x\n", x);
    printf("inverted = %08x\n", i);

    return 0;
}
