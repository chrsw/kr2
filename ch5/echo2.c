/*
 * echo2.c
 *      Repeat command line arguments; 2nd version.
 *
 * Description:
 *      Excerpt from section 5.10. Demonstrates how to access
 *      command line arguments.
 *
 * Input:
 *      Command line tokens.
 *
 * Build:
 *      $ gcc -o echo2 echo2.c
 *
 * Run:
 *      $ ./echo2 more test input 2nd version > echo2_test_output.txt
 *
 */

#include <stdio.h>

/* echo command-line arguments */
int main(int argc, char *argv[]) {

    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : ""); 
    printf("\n");

    return 0;
}
