/*
 * ch8_getchar_main.c
 *      Test chapter 8 stdio.h
 *
 * Build:
 *      $ gcc -o ch8_getchar_main ch8_fillbuf.c ch8_getchar_main.c
 *
 * Notes:
 *      After running this code in a GDB session, the line:
 *      if ((fp-flag&(_READ|_EOF_)) != _READ)
 *      always returns true. getchar() calls getc(stdin) which means
 *      stdin, &_iob[0] is being passed to getc(). _iob[] is defined in
 *      this file, but does it do anything? It's not initialized to 
 *      anything.
 *      The C Standard Library runtime is supposed to set up _iob[]'s so 
 *      they are linked to the actual files, but that isn't happening here.
 *
 * TODO:
 *      The note above might be outdated. Check accuracy and update if
 *      necessary.
 */

#include "ch8_stdio.h"

FILE _iob[OPEN_MAX] = {         /* stdin, stdout, stderr */
    {0, (char *)0, (char *)0, _READ, 0 },
    {0, (char *)0, (char *)0, _WRITE, 1 },
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }
};

char buf[8000];

int main(void) {
    
    int c = 0; 
    int i = 0;
    while ((c = getchar()) != EOF)
        buf[i++] = c;
    return c;
}
