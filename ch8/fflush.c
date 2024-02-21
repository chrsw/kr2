/* vim:ts=4:sw=4:et:so=10:
 *
 * fflush.c
 *      Flush a stream's buffer.
 *
 * Description:
 *      Simple fflush() implementation for part of Exercise 8-3.
 *      
 *      Description from the text, Standard Library, Appendix B:
 *      On an output stream, fp, fflush causes any buffered but unwritten
 *      data to be written; on an input stream the affect is undefined. It
 *      returns EOF for a write error, and zero otherwise.
 *      fflush(NULL) flushes all output streams.
 *
 * Input:
 *      0 for success, otherwise EOF. Not implemented: errno for this
 *      version.
 *
 * Build:
 *      $ gcc -c fflush.c
 *      $ gcc -o app fflush.c app.c
 *
 */

#include "syscalls.h"
#include "ch8_stdio.h"

/* fflush:  flush a specified output stream or all output streams */
int fflush(FILE *fp) {

    if (fp == NULL) {
        /* flush standard output and standard error */
        write(stdout->fd, (stdout)->base, BUFSIZ-((stdout)->cnt));
        write(stderr->fd, (stderr)->base, BUFSIZ-((stderr)->cnt));
        return 0;
    }
    else
        if (fp->base != NULL) {
            if ((write(fp->fd, fp->base, BUFSIZ-(fp->cnt))) < 0)
                ;
            else
                return 0;
        }

    return EOF;
}
