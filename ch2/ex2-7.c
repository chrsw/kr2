/* Exercise 2-7 */

#include <stdio.h>
#include "invert.h"

int main(int argc, char *argv[])
{
    unsigned int x = 0x1111;
    int p = 8;
    int n = 4;
    unsigned int i = invert(x,p,n);
    
    printf("       x = %x\n", x);
    printf("inverted = %x\n", i);

    return 0;
}
