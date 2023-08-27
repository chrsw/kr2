 /* vim:ts=4:sw=4:et:so=10:
 *
 * flushbuf.c
 *      _flushbuf():  write a file buffer to disk. Write a char to file buffer.
 *
 * Description:
 *      Partial solution to Exercise 8-3, _flushbuf(), implementation.
 *      Exercise 8-3 includes two other sections: fflush() and fclose()
 *      which are not implemented in this file. See this chapter's README.
 *
 *      Description of _flushbuf() from the text:
 *      "...we have included the definition of putc() to show that it operates
 *      in much the same way as getc(), calling a function _flushbuf() when
 *      its buffer is full."
 *
 *      How _flushbuf() is called:
 *          #define putc(x,p) (--(p)->cnt >= 0 \
 *                      ? *(p)->ptr++ = (x) : _flushbuf((x),p)
 *
 *      Additional description:      
 *      The text does not formally specify the behavior of _flushbuf and
 *      there doesn't appear to be a corresponding function in the system's
 *      standard C library (Ubunut 20.04 glibc 2.31).
 *
 *      _flushbuf is called when file buffer is full or non-existent.
 *      _flushbuf will copy the specified file's buffer to the actual file.
 *      If there is no buffer, and the file is buffered, allocate a buffer
 *      and write to it.
 *      
 *      If the file is unbuffered, write the specified character to the
 *      file.
 *      
 *      So, for _flushbuf(), putc() will try to put a character into the
 *      file buffer. If the buffer is full then _flushbuf() is called. The
 *      buffer is full if the count has reached zero prior to the call of
 *      putc(). The count is initially set to the size of the allocated 
 *      buffer. After a flush, the count is reset to the same initial size.
 *      When the file is opened by fopen(), fopen() does not
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
 * TODO:
 *      What happens when a file is opened for reading and writing?
 *      the fp.cnt counter will decrease for both reading and writing when
 *      using putc() and getc(), the fp.ptr buffer pointer will advance
 *      on a call to either putc() or getc() but in one case a character is
 *      written and another case a character is read.
 *
 */

#include <stdlib.h>
#include "stdio.h"
#include "syscalls.h"


/* _flushbuf:  write out a file buffer if full */ 
int _flushbuf(int c, FILE *fp) {

    int bufsize;
    
    /* exit w/ EOF if file is not open for writing or there is an error */
    if ((fp->flag&(_WRITE|_EOF|_ERR)) != _WRITE)
        return EOF;

    /* file is usable, determine the buffering mode */
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ+1;
    if (bufsize == 1) {
        if (write(fp->fd, &c, bufsize) == 1) {
            fp->cnt = 0;
            return c;                           /* return the character */
        }
        else                                    /* written if the write was */
            return EOF;                         /* successful */
    } else {                                    /* using buffer */
        if (fp->base == NULL)   {               /* have a buffer already? */
            if ((fp->base = (char *)malloc(bufsize)) == NULL)
                return EOF;                     /* can't get buffer */
            fp->ptr = fp->base;
            *fp->ptr++ = c;
            fp->cnt = bufsize-1;
            return c;
       } else {                                 /* already have full buffer */
            write(fp->fd, fp->base, bufsize);   /* TODO use write() return  */
            fp->ptr = fp->base;                 /* reset file buffer ptr */
            fp->cnt = bufsize-1;
            *fp->ptr++ = c;
            return c;
        }
    }
}
