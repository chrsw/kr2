/* vim:ts=4:sw=4:et:so=10:
 *
 * flushbuf.c
 *      Write out a file buffer if full.
 *
 * Description:
 *      Partial solution to Exercise 8-3, _flushbuf(), implementation.
 *      
 *      File buffer full or non-existant.
 *
 *      Copy the specified file's buffer to the actual file.
 *   
 *      If there is no buffer, and the file is buffered, allocate a buffer
 *      and write to it.
 *      
 *      If the file is unbuffered, write the specified character to the
 *      file.
 *
 *      For _fillbuf(), the text has this description: "The first call to
 *      getc() for a particular file finds a count of zero, which forces a
 *      call of _fillbuf(). If _fillbuf() finds that the file is not open
 *      for reading, it returns EOF immediately. Otherwise, it tries to
 *      allocate a buffer (if reading is to be buffered)."
 *
 *      So, for _flushbuf(), putc() will try to put a character into the
 *      file buffer. If the buffer is full then _flushbuf() is called. The
 *      buffer is full if the count has reached zero prior to the call of
 *      putc(). When the file is opened by fopen(), fopen() does not
 *      allocate any buffer space. This means that just like _fillbuf(),
 *      the first call to _flushbuf() should allocate the file buffer.
 *
 *      Any call to _flushbuf() means putc() tried to put a character into
 *      the file buffer of fp but the fp.cnt was zero. This means that the
 *      file is being written to for the first time or there is no more
 *      room in the buffer. If the buffer is NULL that means the buffer
 *      has not been allocated yet and this is the first call to _flushbuf().
 *
 * Input:
 *      Character to write and file pointer to write to.
 *
 * Returns:
 *      Character written or EOF for end of file or error.
 *
 * Build:
 *      $ gcc -c flushbuf.c
 *
 */

#include <stdlib.h>
#include "stdio.h"
#include "syscalls.h"


/* _flushbuf:  write out a file buffer if full */ 
int _flushbuf(int c, FILE *fp) {

    int bufsize;
    int written;
    
    /* exit w/ EOF if file is not open for writing or there is an error */
    if ((fp->flag&(_WRITE|_EOF|_ERR)) != _WRITE)
        return EOF;

    /* file is usable, figure out the buffering state */
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (bufsize == 1) {
        fp->cnt = write(fp->fd, &c, bufsize);   /* no buffer, just write one */
        if (fp->cnt == 1)
            return c;                           /* return the chracter */
        else                                    /* written if the write was */
            return EOF;                         /* sucessful */
    }
    else {                                      /* using buffer */
        if (fp->base == NULL)   {               /* have a buffer already? */
            if ((fp->base = (char *)malloc(bufsize)) == NULL)
                return EOF;                     /* can't get buffer */
            fp->ptr = fp->base;
       } else {                                 /* already have full buffer */
            written = bufsize - write(fp->fd, fp->base, bufsize);
            fp->ptr -= written;                 /* reset file buffer ptr */
            return c;
        }
    }
}
