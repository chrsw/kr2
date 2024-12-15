/*
 * ch8_getcharb.c
 *      Buffered single character input.
 *      Chapter 8 version.
 *
 * Build:
 *      $ gcc -c ch8_getcharb.c
 *
 */

#include "syscalls.h"

/* ch8_getcharb: unbuffered single character input */
int ch8_getcharb(void) {

    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {            /* buffer is empty */
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

