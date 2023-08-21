/* vim:ts=4:sw=4:et:so=10:
 *
 * stdio.h
 *      Chapter 8 implementation of stdio.h, the standard library
 *      input/output support header.
 *
 * Details:
 *      Basically a copy of the book excerpt, section 8.5, page 176.
 *
 * TODO:
 *      Look into why using this custom stdio.h file doesn't work at runtime.
 *      
 */

#ifndef STDIO_H
#define STDIO_H

/* These are also defined in syscalls.h */
#ifndef NULL
  #define NULL        0
#endif
#ifndef EOF
  #define EOF         (-1)
#endif
#ifndef BUFSIZ
  #define BUFSIZ      1024
#endif
#ifndef OPEN_MAX
  #define OPEN_MAX    20
#endif

typedef struct _iobuf {
    int cnt;                /* characters left */
    char *ptr;              /* next character position */
    char *base;             /* location of buffer */
    int flag;               /* mode of file access */
    int fd;                 /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

enum _flags {
    _READ   =   01,         /* file open for reading  */
    _WRITE  =   02,         /* file open for writing */
    _UNBUF  =   04,         /* file is unbuffered */
    _EOF    =   010,        /* EOF has onccured on this file */
    _ERR    =   020,        /* error occured on this file */
};


/* avoid collisions with existing functions in the standard library */
int _fillbuf(FILE*);
int _flushbuf(int, FILE*);

#define feof(p)         (((p)->flag & _EOF) != 0)
#define ferror(p)       (((p)->flag & _ERR) != 0)
#define fileno(p)       ((p)->fd)

#define getc(p)         (--(p)->cnt >= 0 \
                        ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x,p)       (--(p)->cnt >= 0 \
                        ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()       getc(stdin)
#define putchar(x)      putc((x),stdout)

#endif // STDIO_H
