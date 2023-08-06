/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_get.c
 *      Read n bytes from position pos.
 *      Excerpt from chapter 8, section 4.
 *
 * Build
 *      $ gcc -c ch8_get.c
 */

#include "syscalls.h"

/* ch8_get:  read n bytes from position pos */
int ch8_get(int fd, long pos, char *buf, int n) {

    if (lseek(fd, pos, 0) >= 0)     /* get to pos */
        return read(fd, buf, n);
    else
        return -1;
}
