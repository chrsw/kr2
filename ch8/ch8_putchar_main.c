/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_putchar_main.c
 *      Test custom stdio.h
 *
 * Build:
 *      $ gcc -o ch8_putchar_main ch8_putchar_main.c
 */

#include "ch8_stdio.h"

FILE _iob[OPEN_MAX];
//void ch8_putchar_test(void);

int main(void) {
    
    char c = 0x61;
    putchar(c);
    return 0;
}
