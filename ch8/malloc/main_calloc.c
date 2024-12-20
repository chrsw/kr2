/*
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
 *      $ gcc -o ch8_calloc main_calloc.c ch8_calloc_2.c
 *      - or -
 *      $ make ch8_calloc
 *      $ make ch8_calloc2 # will use ch8_calloc_2.c
 *      $ make all
 *
 *      Use ch8_calloc.c for calloc() as a wrapper function on malloc().
 *      Use ch8_calloc_2.c for calloc() as a modified malloc().
 *
 * Output:
 *      Prints the allocated and cleared data from calloc().
 *      
 * Run:
 *      $ ./ch8_calloc
 *
 */

#include <stdio.h>
#include <stddef.h>
#include "ch8_calloc.h"

char *gcp;                              /* for accessing the dynamically */
                                        /* allocated memory */

int main(int argc, char *argv[])
{
    (void)argc;                         /* satisfy warnings */ 
    (void)argv;

    int i = 0;
    gcp = (char *)ch8_calloc(10, 1);    /* version of calloc depends on */
                                        /* build command */

    for (i = 0; i < 10; i++)            /* the space allocated by calloc() */
        printf("%d ", gcp[i]);          /* should already be cleard so all */
    printf("\n");                       /* that's necessary is to print */

    ch8_free(gcp);
    
    return 0;
}
