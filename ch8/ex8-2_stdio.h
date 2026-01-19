/*
 * ex8-2_stdio.h
 *      Implementation of stdio.h, for Exercise 8-2.
 *      input/output support header.
 *
 * Details:
 *      Uses bit fields instead of int flags for FILE status.
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

struct bflags {
    unsigned int read:1;
    unsigned int write:1;
    unsigned int unbuf:1;
    unsigned int eof:1;
    unsigned int err:1;
} fflags;


typedef struct _iobuf {
    int cnt;                /* characters left */
    char *ptr;              /* next character position */
    char *base;             /* location of buffer */
    int fd;                 /* file descriptor */
    unsigned int read:1;
    unsigned int write:1;
    unsigned int unbuf:1;
    unsigned int eof:1;
    unsigned int err:1;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

/* avoid collisions with existing functions in the standard library */
int _fillbuf(FILE*);
int _flushbuf(int, FILE*);

#define feof(p)         ((p)->eof == 1)
#define ferr(p)         ((p)->err == 1)
#define fileno(p)       ((p)->fd)

#define getc(p)         (--(p)->cnt >= 0 \
                        ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x,p)       (--(p)->cnt >= 0 \
                        ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()       getc(stdin)
#define putchar(x)      putc((x),stdout)

#endif // CH8_STDIO_H
