/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * main_malloc.c
 *      Small test driver for ch8_malloc().
 *
 * Description:
 *      Use the malloc() family of functions from Section 8.6 for testing
 *      and demonstration purposes.
 *      Fill a malloc'd array with an integer count from 0 to 9.
 *
 * Build:
 *      $ gcc -o ch8_malloc main_malloc.c ch8_malloc.c
 *      
 * Run:
 *      $ ./ch8_malloc
 *
 */

#include <stdio.h>
#include "ch8_malloc.h"

char *gcp;

int main(int argc, char *argv[])
{
    int i = 0;
    gcp = (char *)ch8_malloc(10);

    for (i = 0; i < 10; i++)
        gcp[i] = i;

    for (i = 0; i < 10; i++)
        printf("%d ", i);
    printf("\n");


    return 0;
}
