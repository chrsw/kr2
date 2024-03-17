/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * main_calloc.c
 *      Small test driver for ch8_calloc().
 *      Part of solution to Exercise 8-6.
 *
 * Description:
 *      Exercise 8-6 from book as written:
 *      The standar library function calloc(n,size) returns a pointer to
 *      objects of size _size_, with the storage, with the storage initialized
 *      to zero. Write calloc() by calling malloc or by modifying it. 
 *
 * Build:
 *      $ gcc -o ch8_calloc main_calloc.c ch8_calloc.c
 *      - or -
 *      $ gcc -o ch8_calloc main_calloc.c ch8_calloc_2.c
 *
 *      Use ch8_calloc.c for calloc() as a wrapper function on malloc().
 *      Use ch8_calloc_2.c for calloc() as a modified malloc().
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
