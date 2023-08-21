/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_putchar_main.c
 *      Test custom stdio.h
 *
 * Build:
 *      $ gcc -o ch8_putchar_main ch8_putchar_main.c
 */

#include "stdio.h"

FILE _iob[OPEN_MAX];

int main(void) {
    
    char c = 0x61;
    putchar(c);
    return 0;
}
