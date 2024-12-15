/*
 * getbits_test.c
 *      Test driver for the getbits() function.
 *
 *
 * Input:
 *      Describe the expected input.
 *
 *
 */

#include <stdio.h>
#include "getbits.h"

unsigned int x = 0x00AA00AA;

int main(int argc, char *argv[])
{

    printf("x = %08X\n", x);
    x = getbits(x,7,23);
    printf("getbits(x,7,23) = %02X\n", x);

    return 0;
}
