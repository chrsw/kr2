/* vim:ts=4:sw=4:et:so=10:
 *
 * ex2-8.c
 *      Main driver for chapter 2, exercise 8, rightrot().
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Build:
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(int argc, char *argv[]) {

    int x = 0x01234567;
    int n = 4;
    unsigned int r = 0;
    
    r = rightrot((unsigned int)x, (unsigned int)n);
    printf("x = %08x\nrotating %d...\nr = %08x\n", x, n, r);

    return 0;
}

