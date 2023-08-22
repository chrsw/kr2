/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fillbuf.c
 *      Allocate and fill an input buffer.
 *
 * Description:
 *      Taken from K&R2 section 8.5.
 *      Description from the text:
 *      "The first call to getc() for a particular file finds a count of zero,
 *      which forces a call of _fillbuf(). If _fillbuf() finds that the
 *      file is not open for reading, it returns EOF immediately. Otherwise,
 *      it tries to allocate a buffer (if reading is to be buffered)."
 *      
 *      "Once the buffer is established, _fillbuf calls read() to fill it,
 *      sets the count and pointers, and returns the character at the
 *      beginning of the buffer. Subsequent calls to _fillbuf will find a
 *      buffer allocated."
 *
 *      Additional description:
 *      When a file is read, first the data is retrieved from the file's
 *      buffer. If the buffer is empty, that's when this function _fillbuf is
 *      called. This function will allocate space for a new buffer if the
 *      buffer doesn't exist yet.
 *
 *      This function is almost identical to the copy in the text.
 *      
 * Input:
 *      File pointer.
 *
 * Output:
 *      Character at the beginning of the newly allocated buffer.
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
