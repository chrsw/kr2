/* vim:ts=4:sw=4:et:so=10:
 *
 * fflush.c
 *      Flush a stream.
 *
 * Description:
 *      Simple fflush() implementation for part of Exercise 8-3.
 *      
 *      Description from the text:
 *
 * Input:
 *      0 for succession, otherwise EOF. Not implemented errno for this
 *      version.
 *
 * Output:
 *
 * Build:
 *      $ gcc -c fflush.c
 *      $ gcc -o app fflush.c app.c
 *
 *
 */

#include "syscalls.h"
#include "stdio.h"

int fflush(FILE *fp) {

    if (fp == NULL)
        return EOF;
    else
        if (fp->base != NULL)
            if ((write(fp->fd, fp->base, BUFSIZ-(fp->cnt))) < 0) 
                return EOF;
            else
                return 0;

    return EOF;
}
