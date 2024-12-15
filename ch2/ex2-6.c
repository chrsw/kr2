/*
 * setbits_test.c
 *      Test driver for the setbits() function.
 *
 *
 */

#include <stdio.h>
#include "setbits.h"

unsigned int x = 0xFFFFFFFF;
//unsigned int x = 0x00000000;
unsigned int y = 0x00004481;

int main(int argc, char *argv[])
{

    printf("main: x = %08X\n", x);
    printf("main: y = %08X\n", y);
    //x = setbits(x,16,8,y);
    //printf("setbits(%08X,16,8,%08X) = %08X\n", x, y, setbits(x,16,8,y));
    printf("setbits(%08X,16,4,%08X) = %08X\n", x, y, setbits(x,16,4,y));

    return 0;
}
