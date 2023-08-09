/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fillbuf.c
 *      Allocate and fill an input buffer.
 *
 * Description:
 *      Taken from K&R2 section 8.5.
 *
 * Input:
 *      File pointer.
 *
 * Output:
 *      Character at the beginning of the buffer.
 *
 * Build:
 *      $ gcc -c ch8_fillbuf.c
 *
 */

#include <stdlib.h>
#include "stdio.h"
#include "syscalls.h"


/* _fillbuf:  allocate and fill input buffer */
int _fillbuf(FILE *fp) {

    int bufsize;

    if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)               /* no buffer yet */
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;                 /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char)*fp->ptr++;
}
