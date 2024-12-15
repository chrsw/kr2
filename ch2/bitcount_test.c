/*
 * bitcount_test.c
 *      Test the functionality of the bitcount() function.
 *
 * Description:
 *      Template file for solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      $ gcc -o bitcount_test bitcount.c bitcount_test.c
 *
 */

#include <stdio.h>

int bitcount(unsigned int);

int main(int argc, char *argv[])
{
    unsigned int b = 0xFDB97531;
    printf("b = %8x\tbits set = %d\n", b, bitcount(b));

    b = 0xECA87531;
    printf("b = %8x\tbits set = %d\n", b, bitcount(b));

    return 0;
}
