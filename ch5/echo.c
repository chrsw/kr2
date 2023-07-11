/* vim:ts=4:sw=4:et:so=10:
 *
 * echo.c
 *      Repeat command line arguments; 1st version.
 *
 * Description:
 *      Excerpt from section 5.10. Demonstrates how to access
 *      command line arguments.
 *
 * Input:
 *      Command line tokens.
 *
 * Build:
 *      $ gcc -o echo echo.c
 *
 * Run:
 *      $ ./echo test input here > echo_test_output.txt
 *
 */

#include <stdio.h>

/* echo command-line arguments */
int main(int argc, char *argv[]) {

    int i;
    
    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf("\n");

    return 0;
}
