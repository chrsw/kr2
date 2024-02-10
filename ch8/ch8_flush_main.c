/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_flush_main.c
 *      Test fflush() from Exercise 8-3.
 *
 * Build:
 *      $ gcc -o ch8_flush_main fflush.c flushbuf.c ch8_flush_main.c
 */

#include "ch8_stdio.h"

int fflush(FILE *);

FILE _iob[OPEN_MAX] = {       
    {0, (char *)0, (char *)0, _READ, 0 },               /* stdin */
    {0, (char *)0, (char *)0, _WRITE, 1 },              /* stdout */
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }      /* stderr */
};

int main(void) {
    
    int i;
           /* 'a' */  /* 'z' */
    for (i = 0x61; i <= 0x7A; i++)
        putchar((char)i);
    putchar('\n');
    fflush(stdout);
    return 0;
}
