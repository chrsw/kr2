/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fopen.c
 *      Chapter 8 version of fopen() using chapter 8 stdio.h.
 *
 * Description:
 *      This file can't link into an executable because ch8_stdio.h will
 *      break the linker.
 *
 * Build:
 *      $ gcc -c ch8_fopen.c
 *
 * Notes:
 *
 */

#include <fcntl.h>
#include "_stdio.h"
#include "syscalls.h"

#define PERMS 0666          /* RW for owner, group, others */

FILE *ch8_fopen(char *name, char *mode) {

    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;                /* invalid mode set */
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;                  /* found free slots */
    if (fp >= _iob + OPEN_MAX)      /* no free slots */
        return NULL;
    
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)                   /* couldn't access name */
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}
