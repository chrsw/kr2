/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_putchar_test.c
 *      Test custom stdio.h
 *
 * Build:
 *      $ gcc -c ch8_putchar_test.c
 */

#include "ch8_stdio.h"

void ch8_putchar_test(void);

void ch8_putchar_test(void) {
    
    char c = 0x61;
    putchar(c);
}
