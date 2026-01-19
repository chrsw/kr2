/*
 * ex8-2.c
 *      Solution for Exercise 8-2.
 *
 * Description:
 *      Rewrite fopen() and _fillbuf() with fields instead of explicit bit
 *      operations. Compare code size and execution speed.
 *
 * Design:
 *      ch8_fopen() and _fillbuf() use a definition of FILE that has a 
 *      'flags' field where file status is in encoded in an 'int'.
 *      See ch8_stdio.h for how this is done, based on the text.
 *      The exercise needs to implement the FILE definition with bit fields
 *      instead of an enum. In theory, this should be slower than the
 *      enum implementation because of the extra operations needed to
 *      extract values from bit fields.
 *
 * 
 * Build:
 *      $ gcc -c ex8-2.c
 *
 */

#include <fcntl.h>
#include <stdlib.h>
#include "ex8-2_stdio.h"
#include "syscalls.h"



#define PERMS 0666          /* RW for owner, group, others */

/*
 * ch8_open: open a file.
 */
FILE *ch8_fopen(char *name, char *mode) {

    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;                /* invalid mode set */
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->read == 0) || (fp->write == 0))
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
    if (*mode == 'r')
        fp->read = 1;
    else
        fp->write = 1;
    return fp;
}


/*
 * ch8_fillbuf: allocate and fill an input buffer.
 */
int _fillbuf(FILE *fp) {

    int bufsize;

    if ((fp->read == 0) || (fp->eof == 1) || (fp->err == 1))
        return EOF;
    bufsize = fp->unbuf ? 1 : BUFSIZ;
    if (fp->base == NULL)               /* no buffer yet */
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;                 /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->eof = 1;
        else
            fp->err = 1;
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char)*fp->ptr++;
}

