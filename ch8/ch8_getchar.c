/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_getchar.c
 *      Unbuffered single character input.
 *      Chapter 8 version.
 *
 * Build:
 *      $ gcc -c ch8_getchar.c
 *
 */

#include "syscalls.h"

/* getchar: unbuffered single character input */
int getchar(void) {

    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

