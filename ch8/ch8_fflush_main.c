/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fflush_main.c
 *      Test fflush() from Exercise 8-3.
 *
 * Build:
 *      $ gcc -o flush_main ch8_fflush.c flushbuf.c ch8_flush_main.c
 */

#include "ch8_stdio.h"

int ch8_fflush(FILE *);

FILE _iob[OPEN_MAX] = {       
    {0, (char *)0, (char *)0, _READ, 0 },               /* stdin */
    {0, (char *)0, (char *)0, _WRITE, 1 },              /* stdout */
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }      /* stderr */
};

int main(void) {
    
    int i;

    /* this does not fill the BUFSIZ, output will have to be flushed */
            /* 'a' */    /* 'z' */
    for (i = 0x61;   i <= 0x7A;    i++)
        putchar(i);

    putchar('\n');
    ch8_fflush(stdout);
    return 0;
}
