/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minscanf_main.c
 *      main() driver for scanf, chapter 7 version.
 *
 * Description:
 *      Use mainscanf() from minscanf.c to test behavior.
 *      Part of Exercise 7-4.
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

int gn;

int main(int argc, char *argv[])
{

    int count = 0;

    count = protoscanf("test%di", &gn);
    printf("protoscanf count = %d\n", count);
   
    printf("value scaned = %d\n", gn); 
    return 0;
}
