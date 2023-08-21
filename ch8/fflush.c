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

    int ret;
    ret = write(1, fp->base, BUFSIZ);
    if (ret < 0)
        return EOF;
    else
        return 0;
}
