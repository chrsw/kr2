/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * main_calloc.c
 *      Small test driver for ch8_calloc().
 *      Part of solution to Exercise 8-6.
 *
 * Description:
 *
 *
 * Build:
 *      $ gcc -o ch8_calloc main_calloc.c ch8_calloc.c
 *      
 * Run:
 *      $ ./ch8_calloc
 *
 */

#include <stdio.h>
#include "ch8_calloc.h"

char *gcp;                              /* for accessing the dynamically */
                                        /* allocated memory */

int main(int argc, char *argv[])
{
    int i = 0;
    gcp = (char *)ch8_calloc(10, 1);

    for (i = 0; i < 10; i++)
        printf("%d ", gcp[i]);
    printf("\n");

    return 0;
}
