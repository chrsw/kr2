/*
 * minprintf_main.c
 *      main() driver for the minprintf() example from section 7.3.
 *      Also used from Exercise 7-3.
 *
 * Description:
 *      Call minprintf() from the text and exercise solution with a
 *      variety of sample input.
 *
 * Input:
 *      Example strings and arguments to excericse the function.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Returns:
 *      This function returns nothing.
 *      The Standard Library version of this function returns the number of
 *      characters printed.
 *      
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o minprintf_main minprintf_main.c minprintf.c
 *
 * Run:
 *      $ ./minprintf_main
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include "minprintf.h"

int main(int argc, char *argv[])
{
    int n = 10;

    (void)argc;
    (void)argv;
    
    minprintf("this is ten: %d\n", n);

    return 0;
}
