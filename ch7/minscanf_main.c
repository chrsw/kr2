/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * minscanf_main.c
 *      main() driver for scanf, chapter 7 version.
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
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o minscanf_main minscanf_main.c minscanf.c
 *
 * Run:
 *      $ ./minscanf
 *
 */

#include <stdio.h>
#include "minscanf.h"

int main(int argc, char *argv[])
{

    char *format = "hi there, scanf()";
    char buf[10];
    int status = 0;

    status = ch7_scanf(format, buf);
    if (status) printf("mismatch!\n");
    return 0;
}
