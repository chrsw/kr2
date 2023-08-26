/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_putchar_main.c
 *      Test custom stdio.h
 *
 * Build:
 *      $ gcc -o ch8_putchar_main flushbuf.c ch8_putchar_main.c
 */

#include "stdio.h"

FILE _iob[OPEN_MAX] = {         /* stdin, stdout, stderr */
    {0, (char *)0, (char *)0, _READ, 0 },
    {0, (char *)0, (char *)0, _WRITE, 1 },
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }
};


int main(void) {
    
    int i = 0;

    for (i = 0x62; i < 0x7B; i++)
        putchar((char)i);
    return 0;
}
