/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_putchar_main.c
 *      Test putchar(), putc() and _fillbuf() in custom stdio.h
 *
 * Build:
 *      $ gcc -o ch8_putchar_main flushbuf.c ch8_putchar_main.c
 */

#include "stdio.h"

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
    return 0;
}
