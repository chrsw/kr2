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
 *      Optional command line arguments for the number to rotate and the
 *      amount to rotate to the right.
 *
 * Output:
 *      Original #, rotation amount and result.
 *
 * Build:
 *      $ gcc -o rightrot rightrot.c ex2-8_main.c
 *
 * Run:
 *      $ ./rightrot <integer> <rotate #>
 *      Integer and rotational amount arguments are optional.
 *      If only one argument is given it will be treated as an integer.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(int argc, char *argv[]) {

    int x = 0;
    int n = 0;

    /* get values from cmd line or use defaults */
    if (argc == 2)
        x = atoi(*++argv);
    else
        x = 0x01234567;
    if (argc == 3)
        n = atoi(*++argv);
    else
        n = 4;

    printf("size of int = %zu\n", sizeof(int));    
    printf("x = 0x%08x\nrotating %d...\nr = 0x%08x\n", x, n, 
            rightrot((unsigned int)x, (unsigned int)n));

    return 0;
}

