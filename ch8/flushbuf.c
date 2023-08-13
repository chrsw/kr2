/* vim:ts=4:sw=4:et:so=10:
 *
 * flushbuf.c
 *      Write out a file buffer if full.
 *
 * Description:
 *      Partial solution to Exercise 8-3, _flushbuf().
 *      If there is no buffer, and the file is buffered, allocate a buffer
 *      and write to it?
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
    
    /* exit if file is not open for writing or there is an error */
    if ((fp->flag&(_WRITE|_EOF|_ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (bufsize == 1) {
        fp->cnt = write(fp->fd, &c, bufsize);   /* no buffer, just write one */
        if (fp->cnt == 1)
            return c;
        else
            return EOF;
    }
    else {                                      /* using buffer */
        if (fp->base == NULL)               
            return EOF;                         /* error, no buffer */
        //fp->cnt = write(fp->fd, fp->base, bufsize);
        written = bufsize - write(fp->fd, fp->ptr, bufsize);
        fp->ptr -= written;                     /* reset file buffer ptr */
        return c;
    }
}
