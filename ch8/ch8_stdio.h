/* vim:ts=4:sw=4:et:so=10:
 *
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
#ifndef BUFSIZ
  #define BUFSIZ      1024
#endif
#ifndef OPEN_MAX
  #define OPEN_MAX    20
#endif

typedef struct ch8_iobuf {
    int cnt;                /* characters left */
    char *ptr;              /* next character position */
    char *base;             /* location of buffer */
    int flag;               /* mode of file access */
    int fd;                 /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define ch8_stdin   (&_iob[0])
#define ch8_stdout  (&_iob[1])
#define ch8_stderr  (&_iob[2])

enum ch8_flags {
    _READ   =   01,         /* file open for reading  */
    _WRITE  =   02,         /* file open for writing */
    _UNBUF  =   04,         /* file is unbuffered */
    _EOF    =   010,        /* EOF has onccured on this file */
    _ERR    =   020,        /* error occured on this file */
};


/* avoid collisions with existing functions in the standard library */
int ch8_fillbuf(FILE*);
int ch8_flushbuf(int, FILE*);

#define ch8_feof(p)         (((p)->flag & _EOF) != 0)
#define ch8_ferror(p)       (((p)->flag & _ERR) != 0)
#define ch8_fileno(p)       ((p)->fd)

#define ch8_getc(p)         (--(p)->cnt >= 0 \
                        ? (unsigned char)*(p)->ptr++ : ch8_fillbuf(p))
#define ch8_putc(x,p)       (--(p)->cnt >= 0 \
                        ? *(p)->ptr++ = (x) : ch8_flushbuf((x),p))

#define ch8_getchar()       ch8_getc(ch8_stdin)
#define ch8_putchar(x)      ch8_putc((x),ch8_stdout)

#endif // CH8_STDIO_H
