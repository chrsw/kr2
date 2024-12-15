/*
 * ch8_stdio.h
 *      Chapter 8 implementation of stdio.h, the standard library
 *      input/output support header.
 *
 * Details:
 *      _iob is not linkable on this version of Unix (Ubuntu 20.04):
 *      chris@xps:~/proj/cpl/ch8$ gcc -o ch8_fopen ch8_fopen.c
 *      /usr/bin/ld: /tmp/ccNuBjjZ.o: in function `main':
 *      ch8_fopen.c:(.text+0x19): undefined reference to `_iob'
 *      /usr/bin/ld: ch8_fopen.c:(.text+0x22): undefined reference to `_iob'
 *
 *      The internal system name for the I/O block on Linux is not "_iob".
 *      
 */

#ifndef CH8_STDIO_H
#define CH8_STDIO_H

#ifndef NULL
#define NULL        0
#endif
#ifndef EOF
#define EOF         (-1)
#endif
#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ      1024
#else
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
    _EOF    =   010,        /* EOF has occurred on this file */
    _ERR    =   020,        /* error occurred on this file */
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

#endif // CH8_STDIO_H
